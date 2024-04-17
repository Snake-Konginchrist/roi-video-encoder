#include "../include/Encoder.h"
#include "../include/ROIManager.h"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input file> <output file>\n";
        return 1;
    }

    std::string inputVideo = argv[1];
    std::string outputVideo = argv[2];

    Encoder enc;
    ROIManager roiManager;

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