#ifndef RAJESHWARI_OCT1_TASK3_QUADRILATERAL_H
#define RAJESHWARI_OCT1_TASK3_QUADRILATERAL_H
#include<iostream>
#include<string>
#include<cmath>
class Quadrilateral{
    protected:
    float* sides;
    float* angles;
    public:
    Quadrilateral(const float s[4], const float a[4]);
    Quadrilateral(const Quadrilateral& other);
    Quadrilateral& operator=(const Quadrilateral& other);
    virtual ~Quadrilateral();

    // Methods
    virtual bool isValid() const;
    virtual float area() const;

    // Operators
    bool operator==(const Quadrilateral& other) const;
    float operator()() const;        
    operator float() const;           
    virtual std::string type() const;

    friend std::ostream& operator<<(std::ostream& os, const Quadrilateral& q); 

};
class  Trapezoid : public Quadrilateral{
    public:
    Trapezoid(const float s[4],const float a[4]);
    bool isValid()const;
    float area()const;
    std::string type() const override;


};
class Parallelogram : public Trapezoid{
    public:
    Parallelogram(const float s[4], const float a[4]);
    bool isValid() const;
    float area() const;
    std::string type() const override;

};
class Rectangle : public Parallelogram{
    public:
    Rectangle(const float s[4],const float a[4]);
    bool isValid() const;
    float area() const;
    std::string type() const override;

};
class Square : public Rectangle{
    public:
    Square(const float s[4],const float a[4]);
    bool isValid() const;
    float area() const;
    std::string type() const override;

};
#endif