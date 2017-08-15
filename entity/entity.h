#include "common.h"

class Entity
{
public:
    Entity(Point _pos = {0, 0, 0});
    Point getPos();

private:
    Point pos;
};
