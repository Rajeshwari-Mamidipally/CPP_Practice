#ifndef TICTACTOE_H
#define TICTACTOE_H
class TicTacToe{
    public:
    TicTacToe();//constructor
    void playGame();//start game
    private:
    int currentPlayer;//1 or 2
    int board[3][3];
    void displayBoard() const; //display the board
    bool checkWin() const; //check if currentPlayer wins
    bool checkDraw() const;//check for a draw
    bool makeMove(int,int);//place current players move
    void switchPlayer();//switch between player 1 and 2
};
#endif