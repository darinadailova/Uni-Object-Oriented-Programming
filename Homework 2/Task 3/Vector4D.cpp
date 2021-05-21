#include "Vector4D.hpp"

Vector4D::Vector4D() {
    numbers[0] = 0;
    numbers[1] = 0;
    numbers[2] = 0;
    numbers[3] = 0;
}

Vector4D::Vector4D(double num1, double num2, double num3, double num4) {
    numbers[0] = num1;
    numbers[1] = num2;
    numbers[2] = num3;
    numbers[3] = num4;
}

Vector4D::Vector4D(const Vector4D& rhs) {
    for (int i = 0; i < this->SIZE_OF_NUMBERS; i++) {
        this->numbers[i] = rhs.numbers[i];
    }
}

Vector4D& Vector4D::operator=(const Vector4D& rhs) {
    if (this != &rhs) {
        for (int i = 0; i < this->SIZE_OF_NUMBERS; i++) {
            this->numbers[i] = rhs.numbers[i];
        }
    }

    return *this;
}

void Vector4D::setNumbers(double newNums[]) {
    for (int i = 0; i < SIZE_OF_NUMBERS; i++) {
        numbers[i] = newNums[i];
    }
}

double& Vector4D::operator[](unsigned const int& index) { return numbers[index]; }

bool Vector4D::operator==(const Vector4D rhs) const {
    for (int i = 0; i < SIZE_OF_NUMBERS; i++) {
        if (numbers[i] != rhs.numbers[i]) {
            return false;
        }
    }

    return true;
}

Vector4D  Vector4D::operator+(const Vector4D& rhs)const {
    return Vector4D(numbers[0] + rhs.numbers[0], numbers[1] + rhs.numbers[1], numbers[2] + rhs.numbers[2], numbers[3] + rhs.numbers[3]);
}

Vector4D& Vector4D::operator+=(const Vector4D& rhs) {
    for (int i = 0; i < SIZE_OF_NUMBERS; i++) {
        numbers[i] += rhs.numbers[i];
    }

    return *this;
}

Vector4D Vector4D::operator-(const Vector4D& rhs) const {
    return Vector4D(numbers[0] - rhs.numbers[0], numbers[1] - rhs.numbers[1], numbers[2] - rhs.numbers[2], numbers[3] - rhs.numbers[3]);
}

Vector4D& Vector4D::operator-=(const Vector4D& rhs) {
    for (int i = 0; i < SIZE_OF_NUMBERS; i++) {
        numbers[i] -= rhs.numbers[i];
    }

    return *this;
}

Vector4D Vector4D::operator*(const Vector4D& rhs) const {
    return Vector4D(numbers[0] * rhs.numbers[0], numbers[1] * rhs.numbers[1], numbers[2] * rhs.numbers[2], numbers[3] * rhs.numbers[3]);
}

Vector4D& Vector4D::operator*=(const Vector4D& rhs) {
    for (int i = 0; i < SIZE_OF_NUMBERS; i++) {
        numbers[i] *= rhs.numbers[i];
    }

    return *this;
}

Vector4D& Vector4D::operator*=(const double& x) {
    for (int i = 0; i < SIZE_OF_NUMBERS; i++) {
        numbers[i] *= x;
    }

    return *this;
}

Vector4D Vector4D::operator*(const double& x) const {
    return Vector4D(x * numbers[0], x * numbers[1], x * numbers[2], x * numbers[3]);
}

Vector4D Vector4D::operator/(const Vector4D& rhs) const {
    return Vector4D(numbers[0] / rhs.numbers[0], numbers[1] / rhs.numbers[1], numbers[2] / rhs.numbers[2], numbers[3] / rhs.numbers[3]);
}

Vector4D& Vector4D::operator/=(const Vector4D& rhs) {
    for (int i = 0; i < SIZE_OF_NUMBERS; i++) {
        numbers[i] /= rhs.numbers[i];
    }

    return *this;
}

bool Vector4D::operator<(const Vector4D& rhs) const {
    if (numbers[0] == rhs.numbers[0] && numbers[1] == rhs.numbers[1] && numbers[2] == rhs.numbers[2] && numbers[3] == rhs.numbers[3]) {
        return false;
    }

    for (int i = 0; i < SIZE_OF_NUMBERS; i++) {
        if (numbers[i] > rhs.numbers[i]) {
            return false;
        }
    }

    return true;
}

bool Vector4D::operator>(const Vector4D& rhs) const {
    if (numbers[0] == rhs.numbers[0] && numbers[1] == rhs.numbers[1] && numbers[2] == rhs.numbers[2] && numbers[3] == rhs.numbers[3]) {
        return false;
    }

    if (operator<(rhs)) return false;
    return true;
}

bool Vector4D::operator<=(const Vector4D& rhs) const {
    for (int i = 0; i < SIZE_OF_NUMBERS; i++) {
        if (numbers[i] > rhs.numbers[i]) {
            return false;
        }
    }

    return true;
}

bool Vector4D::operator>=(const Vector4D& rhs) const {
    for (int i = 0; i < SIZE_OF_NUMBERS; i++) {
        if (numbers[i] < rhs.numbers[i]) {
            return false;
        }
    }

    return true;
}

bool Vector4D::operator!=(const Vector4D& rhs) const {
    if (operator==(rhs)) return false;
    return true;
}

bool Vector4D::operator!() const {
    for (int i = 0; i < SIZE_OF_NUMBERS; i++) {
        if (numbers[i] != 0) {
            return false;
        }
    }

    return true;
}

Vector4D Vector4D::operator-() const {
    return Vector4D(-numbers[0], -numbers[1], -numbers[2], -numbers[3]);
}