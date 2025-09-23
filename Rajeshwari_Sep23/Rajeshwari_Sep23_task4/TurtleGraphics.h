#include <vector>
#include <utility>
#include <string>

// Board size: 20x20
const int SIZE = 20;

// Directions: 0 = UP, 1 = RIGHT, 2 = DOWN, 3 = LEFT
enum Direction { UP, RIGHT, DOWN, LEFT };

class TurtleGraphics {
private:
    bool floor[SIZE][SIZE]; // sketchpad
    int x, y;               // current position of turtle
    bool penDown;           // pen status
    Direction dir;          // current direction

public:
    TurtleGraphics();

    // Command functions
    void penUp();            // Command 1
    void penDownCommand();   // Command 2
    void turnRight();        // Command 3
    void turnLeft();         // Command 4
    void moveForward(int steps); // Command 5
    void printFloor() const; // Command 6

    // Process a list of commands
    void processCommands(const std::vector<std::pair<int, int>>& commands);
};