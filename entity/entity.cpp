#include "entity.h"

Entity::Entity(Point _pos)
{
    pos = _pos;
    fd = 0.001;
    vel = {0, 0, 0};
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
    pos.x = pos.x + vel.x * fd + (acc.x * fd * fd) / 2;
    vel.x = vel.x + acc.x * fd;
}