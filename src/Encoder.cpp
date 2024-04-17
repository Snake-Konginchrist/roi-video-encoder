//
// Created by IOT on 2024/4/17.
//
#include "../include/Encoder.h"
#include <iostream>

Encoder::Encoder() : width(0), height(0) {}

bool Encoder::initialize(int w, int h, const std::vector<int>& mask) {
    width = w;
    height = h;
    roiMask = mask;
    // 实际的初始化代码，如打开编码器，配置参数等
    return true;
}

bool Encoder::encode(const std::string& inputPath, const std::string& outputPath) {
    // 这里应当是编码处理的具体实现，包括打开输入文件，读取数据，应用ROI，编码，写输出文件等
    std::cout << "Encoding video..." << std::endl;
    // 示例代码，应用ROI掩码和调用FFmpeg的编码逻辑
    return true;
}