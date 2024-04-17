//
// Created by IOT on 2024/4/17.
//

#ifndef ROI_VIDEO_ENCODER_ENCODER_H
#define ROI_VIDEO_ENCODER_ENCODER_H

#include <string>
#include <vector>

class Encoder {
public:
    Encoder();
    bool initialize(int width, int height, const std::vector<int>& roiMask);
    bool encode(const std::string& inputPath, const std::string& outputPath);

private:
    int width;
    int height;
    std::vector<int> roiMask;
};

#endif //ROI_VIDEO_ENCODER_ENCODER_H
