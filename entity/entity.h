#include "common.h"

class Entity
{
public:
    Entity(Point _pos = {0, 0, 0})
    {
        pos = _pos;
    }

    Point getPos()
    {
        return pos;
    }

private:
    Point pos;
};
