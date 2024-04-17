#include "../include/Encoder.h"
#include <iostream>
#include <fstream>
#include <cstring>

Encoder::Encoder() : width(0), height(0), encoder(nullptr) {
    memset(&pic_in, 0, sizeof(pic_in));
    memset(&pic_out, 0, sizeof(pic_out));
}

Encoder::~Encoder() {
    if (encoder) {
        x264_encoder_close(encoder);
        encoder = nullptr;
    }
    x264_picture_clean(&pic_in);
}

bool Encoder::initialize(int w, int h, const std::vector<int>& mask) {
    width = w;
    height = h;
    roiMask = mask;

    x264_param_default_preset(&param, "veryfast", "zerolatency");
    param.i_threads = 1;
    param.i_width = width;
    param.i_height = height;
    param.i_fps_num = 25;
    param.i_fps_den = 1;
    param.b_vfr_input = 0;
    param.i_keyint_max = 25;
    param.b_repeat_headers = 1;
    param.b_annexb = 1;
    param.rc.i_rc_method = X264_RC_CRF;
    param.rc.f_rf_constant = 25;
    param.i_csp = X264_CSP_I420;

    if (x264_param_apply_profile(&param, "high") < 0) {
        std::cerr << "Failed to set profile." << std::endl;
        return false;
    }

    encoder = x264_encoder_open(&param);
    if (!encoder) {
        std::cerr << "Failed to open encoder!" << std::endl;
        return false;
    }

    x264_picture_alloc(&pic_in, param.i_csp, param.i_width, param.i_height);
    return true;
}

bool Encoder::encode(const std::string& inputPath, const std::string& outputPath) {
    std::ifstream inFile(inputPath, std::ios::binary);
    std::ofstream outFile(outputPath, std::ios::binary);
    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        return false;
    }

    std::vector<uint8_t> buffer(width * height * 3 / 2);
    x264_nal_t* nals;
    int i_nals;
    int frame_size;

    while (!inFile.eof()) {
        inFile.read(reinterpret_cast<char*>(buffer.data()), buffer.size());
        size_t bytes = inFile.gcount();
        if (bytes == 0) break;

        // Assuming YUV420p input
        memcpy(pic_in.img.plane[0], buffer.data(), width * height);
        memcpy(pic_in.img.plane[1], buffer.data() + width * height, width * height / 4);
        memcpy(pic_in.img.plane[2], buffer.data() + width * height + width * height / 4, width * height / 4);

        frame_size = x264_encoder_encode(encoder, &nals, &i_nals, &pic_in, &pic_out);
        if (frame_size < 0) {
            std::cerr << "Failed to encode frame" << std::endl;
            return false;
        } else if (frame_size) {
            outFile.write(reinterpret_cast<char*>(nals[0].p_payload), frame_size);
        }
    }

    inFile.close();
    outFile.close();

    return true;
}