#include "Rajeshwari_Oct1_task3_Quadrilateral.h"

int main() {
    float sqSides[4] = {5,5,5,5}; float sqAngles[4] = {90,90,90,90};
    float rectSides[4] = {6,4,6,4}; float rectAngles[4] = {90,90,90,90};
    float paraSides[4] = {6,4,6,4}; float paraAngles[4] = {110,70,110,70};
    float trapSides[4] = {6,5,4,3}; float trapAngles[4] = {100,80,100,80};
    float quadSides[4] = {3,4,5,6}; float quadAngles[4] = {90,90,90,90};

    Quadrilateral* shapes[5];
    shapes[0] = new Quadrilateral(quadSides, quadAngles);
    shapes[1] = new Trapezoid(trapSides, trapAngles);
    shapes[2] = new Parallelogram(paraSides, paraAngles);
    shapes[3] = new Rectangle(rectSides, rectAngles);
    shapes[4] = new Square(sqSides, sqAngles);

    for (int i = 0; i < 5; i++) {
        std::cout << *shapes[i] << "\n";
        std::cout << "Valid? " << (shapes[i]->isValid() ? "Yes" : "No") << "\n";
        std::cout << "Area: " << shapes[i]->area() << "\n\n";
    }

    std::cout << "Rectangle == Square? "<< ((*shapes[3] == *shapes[4]) ? "Yes" : "No") << "\n";
    std::cout << "Square as float (area): " << float(*shapes[4]) << "\n";
    std::cout << "Square perimeter using (): " << (*shapes[4])() << "\n";

    for (int i = 0; i < 5; i++) delete shapes[i];
    return 0;
}
