#include "entity.h"
#include <cmath>

Entity::Entity(Vector3D _pos)
{
    pos = _pos;
    fd = 0.001;
    mass = 1;
    vel = {0, 0, 0};
}

double Entity::getDistanceTo(const Entity &other)
{
  return sqrt( (other.pos.x - pos.x) * (other.pos.x - pos.x) +
               (other.pos.y - pos.y) * (other.pos.y - pos.y) +
               (other.pos.z - pos.z) * (other.pos.z - pos.z));
}

Vector3D Entity::getPos()
{
    return pos;
}

void Entity::setVelocity(Vector3D _vel)
{
    vel = _vel;
}

Vector3D Entity::getVelocity()
{
    return vel;
}

void Entity::setAcceleration(Vector3D _acc)
{
    acc = _acc;
}

Vector3D Entity::getAcceleration()
{
    return acc;
}

void Entity::setFrameDuration(double _time)
{
    fd = _time;
}

void Entity::update()
{
    calcNew(pos.x, vel.x, acc.x);
    calcNew(pos.y, vel.y, acc.y);
    calcNew(pos.z, vel.z, acc.z);
}

void Entity::calcNew(double &p, double &v, double &a)
{
    p = p + v * fd + (a * fd * fd) / 2;
    v = v + a * fd;
}

double Entity::getMass()
{
  return mass;
}

Vector3D Entity::getVectorTowardsTarget(const Entity &other)
{
  Vector3D direction;
  direction.x = other.pos.x - pos.x;
  direction.y = other.pos.y - pos.y;
  direction.z = other.pos.z - pos.z;
  return direction;
}
