#include "entity.h"
#include <cmath>

Entity::Entity(Point _pos)
{
    pos = _pos;
    fd = 0.001;
    vel = {0, 0, 0};
}

double Entity::getDistanceTo(const Entity &other)
{
  return sqrt( (other.pos.x - pos.x) * (other.pos.x - pos.x) +
               (other.pos.y - pos.y) * (other.pos.y - pos.y) +
               (other.pos.z - pos.z) * (other.pos.z - pos.z));
}

Point Entity::getPos()
{
    return pos;
}

void Entity::setVelocity(Point _vel)
{
    vel = _vel;
}

Point Entity::getVelocity()
{
    return vel;
}

void Entity::setAcceleration(Point _acc)
{
    acc = _acc;
}

Point Entity::getAcceleration()
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
