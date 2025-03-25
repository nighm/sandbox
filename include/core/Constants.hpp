#pragma once

namespace PlanetSim {
namespace Constants {

// 物理常量
constexpr double G = 6.67430e-11;        // 引力常数 (m^3 kg^-1 s^-2)
constexpr double LIGHT_SPEED = 2.99792458e8;  // 光速 (m/s)
constexpr double BOLTZMANN = 1.380649e-23;    // 玻尔兹曼常数 (J/K)
constexpr double PLANCK = 6.62607015e-34;     // 普朗克常数 (J⋅s)

// 天文常量
constexpr double SOLAR_MASS = 1.989e30;       // 太阳质量 (kg)
constexpr double EARTH_MASS = 5.972e24;       // 地球质量 (kg)
constexpr double EARTH_RADIUS = 6.371e6;      // 地球半径 (m)
constexpr double AU = 1.495978707e11;         // 天文单位 (m)

// 模拟参数
constexpr double MIN_PARTICLE_MASS = 1e10;    // 最小粒子质量 (kg)
constexpr double MAX_PARTICLE_MASS = 1e25;    // 最大粒子质量 (kg)
constexpr double MIN_TEMPERATURE = 3;         // 最低温度 (K)
constexpr double MAX_TEMPERATURE = 1e8;       // 最高温度 (K)

// 时间尺度
constexpr double YEAR_IN_SECONDS = 31557600;  // 年in秒
constexpr double DAY_IN_SECONDS = 86400;      // 天in秒
constexpr double HOUR_IN_SECONDS = 3600;      // 小时in秒

} // namespace Constants
} // namespace PlanetSim 