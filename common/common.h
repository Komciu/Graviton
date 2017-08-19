#pragma once

struct Vector3D
{
    double x;
    double y;
    double z;

    Vector3D():x(0), y(0), z(0){}
    Vector3D(double _x, double _y, double _z):x(_x), y(_y), z(_z){}
    bool operator==(const Vector3D &other)
    {
      return (x == other.x && y == other.y && z == other.z);
    }
    Vector3D operator/(double val)
    {
      Vector3D result;
      result.x = x / val;
      result.y = y / val;
      result.z = z / val;
      return result;
    }
};
