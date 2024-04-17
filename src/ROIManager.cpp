//
// Created by IOT on 2024/4/17.
//
#include "../include/ROIManager.h"
#include <iostream>

ROIManager::ROIManager() {}

bool ROIManager::setROI(const std::string& videoPath, int width, int height) {
    // 设置ROI掩码，实际中这可能会更复杂，包括读取视频帧，分析ROI等
    roiMask.resize(width * height, 10); // 默认QP
    // 假设右下角区域是高清区域
    for (int i = height / 2; i < height; ++i) {
        for (int j = width / 2; j < width; ++j) {
            roiMask[i * width + j] = 40; // 高清区域使用较低的QP
        }
    }
    return true;
}

std::vector<int> ROIManager::getROIMask() const {
    return roiMask;
}