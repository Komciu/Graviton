#pragma once

#include "common.h"

class Entity
{
public:
    Entity(Vector3D _pos = {0, 0, 0});
    Vector3D getPos();
    void setVelocity(Vector3D _vel);
    Vector3D getVelocity();
    void setAcceleration(Vector3D _acc);
    Vector3D getAcceleration();
    void setFrameDuration(double _time);
    void update();
    double getDistanceTo(const Entity &other);
    double getMass();
    Vector3D getVectorTowardsTarget(const Entity &other);

private:
    Vector3D pos;
    Vector3D vel;
    Vector3D acc;
    double fd;
    double mass;

    void calcNew(double &p, double &v, double &a);
};
