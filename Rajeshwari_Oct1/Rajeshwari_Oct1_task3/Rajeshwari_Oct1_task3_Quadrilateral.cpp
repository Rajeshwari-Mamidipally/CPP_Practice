#include "Rajeshwari_Oct1_task3_Quadrilateral.h"
#include<iostream>
#include<cmath>

// ---------------- Quadrilateral ----------------
Quadrilateral::Quadrilateral(const float s[4], const float a[4]) {
    sides = new float[4];
    angles = new float[4];
    for (int i = 0; i < 4; i++) {
        sides[i] = s[i];
        angles[i] = a[i];
    }
}

Quadrilateral::Quadrilateral(const Quadrilateral& other) {
    sides = new float[4];
    angles = new float[4];
    for (int i = 0; i < 4; i++) {
        sides[i] = other.sides[i];
        angles[i] = other.angles[i];
    }
}

Quadrilateral& Quadrilateral::operator=(const Quadrilateral& other) {
    if (this != &other) {
        delete[] sides;
        delete[] angles;
        sides = new float[4];
        angles = new float[4];
        for (int i = 0; i < 4; i++) {
            sides[i] = other.sides[i];
            angles[i] = other.angles[i];
        }
    }
    return *this;
}

Quadrilateral::~Quadrilateral() {
    delete[] sides;
    delete[] angles;
}

bool Quadrilateral::isValid() const {
    float sum = 0;
    for (int i = 0; i < 4; i++) sum += angles[i];
    return std::abs(sum - 360.0f) < 1e-3;
}

float Quadrilateral::area() const { return 0.0f; }

bool Quadrilateral::operator==(const Quadrilateral& other) const {
    return std::abs(area() - other.area()) < 1e-3;
}

float Quadrilateral::operator()() const {
    return sides[0] + sides[1] + sides[2] + sides[3];
}

Quadrilateral::operator float() const {
    return area();
}

std::string Quadrilateral::type() const { return "Quadrilateral"; }

std::ostream& operator<<(std::ostream& os, const Quadrilateral& q) {
    os << q.type() << " | Sides: ";
    for (int i = 0; i < 4; i++) os << q.sides[i] << " ";
    os << "| Angles: ";
    for (int i = 0; i < 4; i++) os << q.angles[i] << " ";
    os << "| Area: " << q.area() << " | Perimeter: " << q();
    return os;
}

// ---------------- Trapezoid ----------------
Trapezoid::Trapezoid(const float s[4], const float a[4]) : Quadrilateral(s, a) {}

bool Trapezoid::isValid() const {
    if (!Quadrilateral::isValid()) return false;
    return (std::abs(angles[0] + angles[2] - 180) < 1e-3) || (std::abs(angles[1] + angles[3] - 180) < 1e-3);
}

float Trapezoid::area() const {
    float a = sides[0], b = sides[2];
    float h = std::sqrt(sides[1] * sides[1] - std::pow(((a - b) + (sides[1]*sides[1] - sides[3]*sides[3])/(a-b))/2, 2));
    return (a + b) / 2 * h;
}

std::string Trapezoid::type() const { return "Trapezoid"; }

// ---------------- Parallelogram ----------------
Parallelogram::Parallelogram(const float s[4], const float a[4]) : Trapezoid(s, a) {}

bool Parallelogram::isValid() const {
    if (!Quadrilateral::isValid()) return false;
    return (sides[0] == sides[2] && sides[1] == sides[3]);
}

float Parallelogram::area() const {
    float base = sides[0];
    float height = sides[1] * std::sin(angles[0] * M_PI / 180.0);
    return base * height;
}

std::string Parallelogram::type() const { return "Parallelogram"; }

// ---------------- Rectangle ----------------
Rectangle::Rectangle(const float s[4], const float a[4]) : Parallelogram(s, a) {}

bool Rectangle::isValid() const {
    if (!Parallelogram::isValid()) return false;
    return (std::abs(angles[0] - 90) < 1e-3 && std::abs(angles[1] - 90) < 1e-3 && std::abs(angles[2] - 90) < 1e-3 && std::abs(angles[3] - 90) < 1e-3);
}

float Rectangle::area() const {
    return sides[0] * sides[1];
}

std::string Rectangle::type() const { return "Rectangle"; }

// ---------------- Square ----------------
Square::Square(const float s[4], const float a[4]) : Rectangle(s, a) {}

bool Square::isValid() const {
    if (!Rectangle::isValid()) return false;
    return (sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3]);
}

float Square::area() const {
    return sides[0] * sides[0];
}

std::string Square::type() const { return "Square"; }
