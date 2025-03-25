#pragma once

#include <cstdio>

namespace planet {

// 版本信息
constexpr int VERSION_MAJOR = 0;
constexpr int VERSION_MINOR = 1;
constexpr int VERSION_PATCH = 0;

// 版本字符串
constexpr const char* VERSION_STRING = "0.1.0";

// 构建时间
constexpr const char* BUILD_DATE = __DATE__;
constexpr const char* BUILD_TIME = __TIME__;

// 版本描述
constexpr const char* VERSION_DESCRIPTION = "初始版本 - 基础物理引擎实现 (2025-03-25)";

// 获取完整版本信息
inline const char* getFullVersion() {
    static char version[256];
    snprintf(version, sizeof(version), "%s (%s %s)", 
             VERSION_STRING, BUILD_DATE, BUILD_TIME);
    return version;
}

} // namespace planet 