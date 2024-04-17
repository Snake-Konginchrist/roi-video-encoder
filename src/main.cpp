#include "../include/Encoder.h"
#include "../include/ROIManager.h"
#include <iostream>

int main() {
    Encoder enc;
    ROIManager roiManager;
    std::string inputVideo = "input.yuv";
    std::string outputVideo = "output.h264";

    if (!roiManager.setROI(inputVideo, 1920, 1080)) {
        std::cerr << "Error setting ROI" << std::endl;
        return -1;
    }

    if (!enc.initialize(1920, 1080, roiManager.getROIMask())) {
        std::cerr << "Error initializing encoder" << std::endl;
        return -1;
    }

    if (!enc.encode(inputVideo, outputVideo)) {
        std::cerr << "Error during encoding" << std::endl;
        return -1;
    }

    std::cout << "Encoding completed successfully." << std::endl;
    return 0;
}