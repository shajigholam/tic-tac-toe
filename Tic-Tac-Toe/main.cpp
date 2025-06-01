//
//  main.cpp
//  Tic-Tac-Toe
//
//  Created by Samaneh Hajigholam on 2025-05-29.
//

#include <iostream>

using namespace std;

char board[9] = {'1','2','3','4','5','6','7','8','9'};
int winPositions[8][3] = {
    {0,1,2},{3,4,5},{6,7,8},
    {0,3,6},{1,4,7},{2,5,8},
    {0,4,8},{2,4,6}
};
void createBoard()
{
    for (int i = 0; i < 9; i++) {
        cout << i + 1 << " | ";
        if ((i + 1) % 3 == 0) {
            cout << "\n";
        }
    }
}

bool isWin(char currPly)
{
    for (auto& winPosition : winPositions) {
        if ((board[winPosition[0]] == currPly) && (board[winPosition[1]] == currPly) && (board[winPosition[2]] == currPly)) {
            return true;
        }
    }
    return false;
}

bool isDraw()
{
    for (int i = 0; i < 9; i++) {
        if (board[i+1] != 'X' && board[i+1] != 'O') {
            return false;
        }
    }
    return true;
}

void playGame()
{
    char currentPlayer = 'X';
    int move;
    do {
        cout << "Enter a number(1 - 9): ";
        cin >> move;
        
        if (move < 1 || move > 9 || board[move - 1] == 'X' || board[move-1] == 'O') {
            cout << "Invalid Input\n";
            continue;
        }
        board[move - 1] = currentPlayer;
        if (isWin(currentPlayer)) {
            cout << "you won!";
            break;
        }
        currentPlayer = currentPlayer == 'X' ? 'O' : 'X';
    } while (!isDraw());
    
}
int main(int argc, const char * argv[]) {
    
    createBoard();
    playGame();
    
    return 0;
}
