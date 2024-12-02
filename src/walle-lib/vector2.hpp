#pragma once 

#include <cmath>

template <typename T=double>
class Vector2 {
public:
    Vector2() : _x(0.), _y(0.) {}
    Vector2(T x, T y) : _x(x), _y(y) {}

    T norm1() const { return std::abs(_x) + std::abs(_y); }
    T norm2() const { return std::sqrt(_x*_x+_y*_y); }
    void normalize() { _x/=norm2(); _y/=norm2(); }
    Vector2 normalized() const { Vector2 out=*this; out.normalize(); return out; }

    Vector2 operator-(const Vector2& other) const { return {_x-other._x, _y-other._y}; }
    Vector2 operator+(const Vector2& other) const { return {_x+other._x, _y+other._y}; }
    Vector2 operator*(T f) const { return {_x*f, _y*f}; }

    bool operator==(const Vector2& other) const { return std::abs(_x-other._x) < 1e-5 && std::abs(_y-other._y)<1e-5; }
    bool operator!=(const Vector2& other) const { return !(*this == other); }

    T x() const { return _x;}
    T y() const { return _y;}

    T dot(const Vector2& other) const { return _x*other._x + _y*other._y; }
    T cross(const Vector2& other) const { return _x*other._y - _y*other._x; }
    T angle(const Vector2& m) const { return std::atan2(cross(m), dot(m)); }
    T angle() const { return std::atan2(_y, _x); }
private:
    T _x, _y;
};
