#include "TurtleGraphics.h"
#include <vector>
#include <utility>
using namespace std;

int main() {
    TurtleGraphics turtle;
    //drawing a 12x12 square according to question
    vector<pair<int, int>> commands = {
        {2, 0},    // Pen down
        {5, 12},   // Move forward 12
        {3, 0},    // Turn right
        {5, 12},   // Move forward 12
        {3, 0},    // Turn right
        {5, 12},   // Move forward 12
        {3, 0},    // Turn right
        {5, 12},   // Move forward 12
        {1, 0},    // Pen up
        {6, 0},    // Print floor
        {9, 0}     // End of data
    };

    turtle.processCommands(commands);

    return 0;
}