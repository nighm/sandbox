#pragma once

#include <vector>
#include <memory>
#include "core/Types.hpp"
#include "core/Constants.hpp"

namespace PlanetSim {

class GravitySystem {
public:
    GravitySystem();
    ~GravitySystem();

    // 初始化系统
    void initialize();

    // 更新所有天体的引力作用
    void update(std::vector<CelestialBody>& bodies, double deltaTime);

    // 计算两个天体之间的引力
    Vector3 calculateGravitationalForce(const CelestialBody& body1, const CelestialBody& body2) const;

    // 更新轨道参数
    void updateOrbits(std::vector<CelestialBody>& bodies, double deltaTime);

    // 检测和处理碰撞
    void handleCollisions(std::vector<CelestialBody>& bodies);

    // 设置模拟精度
    void setSimulationAccuracy(double accuracy) { m_accuracy = accuracy; }

private:
    // Barnes-Hut八叉树节点
    struct OctreeNode {
        Vector3 centerOfMass;
        double totalMass;
        Vector3 bounds[2];  // min和max边界点
        std::vector<CelestialBody*> bodies;
        std::unique_ptr<OctreeNode> children[8];
    };

    // 构建八叉树
    void buildOctree(const std::vector<CelestialBody>& bodies);
    
    // 使用Barnes-Hut算法计算引力
    Vector3 calculateForceBarnesHut(const CelestialBody& body, const OctreeNode& node) const;

    // 检查两个天体是否碰撞
    bool checkCollision(const CelestialBody& body1, const CelestialBody& body2) const;

    // 合并两个碰撞的天体
    CelestialBody mergeBodies(const CelestialBody& body1, const CelestialBody& body2) const;

private:
    double m_accuracy;  // Barnes-Hut算法的精度参数
    std::unique_ptr<OctreeNode> m_root;  // 八叉树根节点
    double m_collisionThreshold;  // 碰撞检测阈值
};

} // namespace PlanetSim 