#include "common.h"

class Entity
{
public:
    Entity(Point _pos = {0, 0, 0});
    Point getPos();
    void setVelocity(Point _vel);
    Point getVelocity();
    void setAcceleration(Point _acc);
    Point getAcceleration();
    void setFrameDuration(double _time);
    void update();

private:
    Point pos;
    Point vel;
    Point acc;
    double fd;

    void calcNew(double &p, double &v, double &a);
};
