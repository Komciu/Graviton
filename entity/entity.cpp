#include "entity.h"

Entity::Entity(Point _pos)
{
    pos = _pos;
}

Point Entity::getPos()
{
    return pos;
}