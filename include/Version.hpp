#pragma once

#include <cstdio>

namespace planet {

// 版本信息
constexpr int VERSION_MAJOR = 0;
constexpr int VERSION_MINOR = 2;
constexpr int VERSION_PATCH = 0;

// 版本字符串
constexpr const char* VERSION_STRING = "0.2.0";

// 构建时间
constexpr const char* BUILD_DATE = __DATE__;
constexpr const char* BUILD_TIME = __TIME__;

// 版本描述
constexpr const char* VERSION_DESCRIPTION = "文档结构优化 - 完善项目文档体系 (2025-03-25)";

// 获取完整版本信息
inline const char* getFullVersion() {
    static char version[256];
    snprintf(version, sizeof(version), "%s (%s %s)", 
             VERSION_STRING, BUILD_DATE, BUILD_TIME);
    return version;
}

} // namespace planet 