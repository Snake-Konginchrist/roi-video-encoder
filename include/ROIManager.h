//
// Created by IOT on 2024/4/17.
//

#ifndef ROI_VIDEO_ENCODER_ROIMANAGER_H
#define ROI_VIDEO_ENCODER_ROIMANAGER_H

#include <vector>
#include <string>

class ROIManager {
public:
    ROIManager();
    bool setROI(const std::string& videoPath, int width, int height);
    std::vector<int> getROIMask() const;

private:
    std::vector<int> roiMask;
};

#endif //ROI_VIDEO_ENCODER_ROIMANAGER_H
