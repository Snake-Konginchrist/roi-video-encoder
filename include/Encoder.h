#ifndef ROI_VIDEO_ENCODER_ENCODER_H
#define ROI_VIDEO_ENCODER_ENCODER_H

#include <string>
#include <vector>

class Encoder {
public:
    Encoder();
    bool initialize(int width, int height, const std::vector<int>& roiMask);
    bool encode(const std::string& inputPath, const std::string& outputPath);
    std::vector<char> processBuffer(const char* data, size_t size);
private:
    int width;
    int height;
    std::vector<int> roiMask;
};

#endif //ROI_VIDEO_ENCODER_ENCODER_H
