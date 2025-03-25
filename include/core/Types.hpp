#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <memory>
#include <string>

namespace PlanetSim {

// 基础类型别名
using Vector3 = glm::dvec3;  // 使用双精度向量
using Matrix3 = glm::dmat3;
using Matrix4 = glm::dmat4;

// 演化阶段
enum class EvolutionStage {
    NEBULA,             // 星云阶段
    PROTOPLANETARY,     // 原行星盘阶段
    ACCRETION,          // 吸积阶段
    DIFFERENTIATION,    // 分异阶段
    GEOLOGICAL,         // 地质阶段
    ATMOSPHERIC         // 大气层形成阶段
};

// 物质状态
enum class MatterState {
    GAS,
    LIQUID,
    SOLID,
    PLASMA
};

// 物理属性
struct PhysicalProperties {
    double temperature;     // 温度 (K)
    double pressure;        // 压力 (Pa)
    double density;         // 密度 (kg/m^3)
    double volume;         // 体积 (m^3)
    MatterState state;     // 物质状态
};

// 化学成分
struct ChemicalComposition {
    std::vector<std::pair<std::string, double>> elements;  // 元素及其质量分数
    double metallicity;    // 金属度
    double volatility;     // 挥发性
};

// 地质特征
struct GeologicalFeatures {
    bool hasCrust;        // 是否有地壳
    bool hasCore;         // 是否有核心
    bool hasMantle;       // 是否有地幔
    double crustThickness;  // 地壳厚度 (m)
    double magneticField;   // 磁场强度 (T)
};

// 大气层属性
struct AtmosphericProperties {
    std::vector<std::pair<std::string, double>> composition;  // 大气成分及比例
    double pressure;       // 大气压 (Pa)
    double temperature;    // 平均温度 (K)
    double escapeVelocity; // 逃逸速度 (m/s)
};

// 天体对象
struct CelestialBody {
    // 基本属性
    std::string name;
    double mass;          // 质量 (kg)
    double radius;        // 半径 (m)
    Vector3 position;     // 位置 (m)
    Vector3 velocity;     // 速度 (m/s)
    Vector3 acceleration; // 加速度 (m/s^2)
    Vector3 angularVelocity; // 角速度 (rad/s)
    
    // 详细属性
    PhysicalProperties physics;
    ChemicalComposition chemistry;
    GeologicalFeatures geology;
    AtmosphericProperties atmosphere;
    
    // 演化状态
    EvolutionStage stage;
    double age;          // 年龄 (s)
};

} // namespace PlanetSim 