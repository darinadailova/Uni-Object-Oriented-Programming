#pragma once

class Vector4D {
    double numbers[4];
    const int SIZE_OF_NUMBERS = 4;
public:
    Vector4D();
    Vector4D(double, double, double, double);
    Vector4D(const Vector4D& rhs);
    Vector4D& operator=(const Vector4D& rhs);

    void setNumbers(double[]);

    bool operator==(Vector4D rhs) const;
    double& operator[](unsigned const int& index);
    Vector4D operator+(const Vector4D& rhs) const;
    Vector4D& operator+=(const Vector4D& rhs);
    Vector4D operator-(const Vector4D& rhs) const;
    Vector4D& operator-=(const Vector4D& rhs);
    Vector4D operator*(const Vector4D& rhs)const;
    Vector4D operator*(const double& x)const;
    Vector4D& operator*=(const Vector4D& rhs);
    Vector4D& operator*=(const double& x);
    Vector4D operator/(const Vector4D& rhs) const;
    Vector4D& operator/=(const Vector4D& rhs);
    bool operator<(const Vector4D& rhs) const;
    bool operator>(const Vector4D& rhs) const;
    bool operator<=(const Vector4D& rhs) const;
    bool operator>=(const Vector4D& rhs) const;
    bool operator!=(const Vector4D& rhs) const;
    bool operator!() const;
    Vector4D operator-() const;
};