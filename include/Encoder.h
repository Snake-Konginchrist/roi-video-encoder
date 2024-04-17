#ifndef ROI_VIDEO_ENCODER_ENCODER_H
#define ROI_VIDEO_ENCODER_ENCODER_H

#include <string>
#include <vector>
#include <cstdint>

extern "C" {
    #include <x264.h>
}

class Encoder {
public:
    Encoder();
    ~Encoder();
    bool initialize(int w, int h, const std::vector<int>& mask);
    bool encode(const std::string& inputPath, const std::string& outputPath);
    std::vector<char> processBuffer(const uint8_t* data, size_t size);

private:
    int width;
    int height;
    std::vector<int> roiMask;
    x264_t* encoder;
    x264_param_t param;
    x264_picture_t pic_in, pic_out;
};

#endif //ROI_VIDEO_ENCODER_ENCODER_H
