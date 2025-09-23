#include "TurtleGraphics.h"
#include <iostream>
#include <algorithm>
using namespace std;

// Constructor initializes the turtle state
TurtleGraphics::TurtleGraphics() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            floor[i][j] = false; // floor is initially empty
        }
    }
    x = 0;            // start position row
    y = 0;            // start position column
    penDown = false;  // pen starts up
    dir = RIGHT;      // initial direction facing right
}

// Command 1: Pen up
void TurtleGraphics::penUp() {
    penDown = false;
}

// Command 2: Pen down
void TurtleGraphics::penDownCommand() {
    penDown = true;
    floor[x][y] = true; // mark current position
}

// Command 3: Turn right
void TurtleGraphics::turnRight() {
    dir = static_cast<Direction>((dir + 1) % 4);
}

// Command 4: Turn left
void TurtleGraphics::turnLeft() {
    dir = static_cast<Direction>((dir + 3) % 4); // equivalent to -1 mod 4
}

// Command 5: Move forward
void TurtleGraphics::moveForward(int steps) {
    for (int step = 0; step < steps; ++step) {
        switch (dir) {
            case UP:
                if (x > 0) x--;
                break;
            case RIGHT:
                if (y < SIZE - 1) y++;
                break;
            case DOWN:
                if (x < SIZE - 1) x++;
                break;
            case LEFT:
                if (y > 0) y--;
                break;
        }
        if (penDown) {
            floor[x][y] = true; // mark current cell
        }
    }
}

// Command 6: Print the floor
void TurtleGraphics::printFloor() const {
    cout << "\nCurrent floor layout:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << (floor[i][j] ? "*" : " ");
        }
        cout << "\n";
    }
    cout << endl;
}

// Process a list of commands
void TurtleGraphics::processCommands(const vector<pair<int, int>>& commands) {
    for (auto& cmd : commands) {
        int command = cmd.first;
        int value = cmd.second;

        switch (command) {
            case 1:
                penUp();
                break;
            case 2:
                penDownCommand();
                break;
            case 3:
                turnRight();
                break;
            case 4:
                turnLeft();
                break;
            case 5:
                moveForward(value);
                break;
            case 6:
                printFloor();
                break;
            case 9:
                cout << "Program terminated.\n";
                return;
            default:
                cout << "Invalid command: " << command << endl;
                break;
        }
    }
}
