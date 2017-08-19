#pragma once

struct Vector3D
{
    double x;
    double y;
    double z;

    Vector3D():x(0), y(0), z(0){}
    Vector3D(double _x, double _y, double _z):x(_x), y(_y), z(_z){}
    /*bool operator==(const Vector3D &other)
    {
      return (x == other.x && y == other.y && z == other.z);
    }*/
    Vector3D operator/(double val)
    {
      Vector3D result;
      result.x = x / val;
      result.y = y / val;
      result.z = z / val;
      return result;
    }
    Vector3D operator*(double val)
    {
      Vector3D result;
      result.x = x * val;
      result.y = y * val;
      result.z = z * val;
      return result;
    }
    Vector3D operator+(const Vector3D &other)
    {
      Vector3D result;
      result.x = this->x + other.x;
      result.y = this->y + other.y;
      result.z = this->z + other.z;
      return result;
    }
};

inline bool operator==(const Vector3D &left, const Vector3D &right)
{
  return (left.x == right.x && left.y == right.y && left.z == right.z);
}
