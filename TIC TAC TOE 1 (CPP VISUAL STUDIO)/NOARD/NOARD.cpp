// NOARD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>

#define length 20
#define width 20
int playerRow = -1;
int playerColumn = -1;
bool isPlayer1 = true;
bool isPlayer2 = false;
char boardArray[3][3];
bool gameOver = false;
std::string gameOverMessage = "";

using namespace std;

void initialize();
void draw();
void input();
void logic();

int main(){
    initialize();
    while (!gameOver) {
        draw();
        input();
        logic();
        system("cls");
    }
    cout << gameOverMessage;
}
void initialize() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            boardArray[i][j] = '*';
}
void draw() {
    if (isPlayer1) cout << "Player 1 turn";
    else cout << "Player 2 turn";
    cout << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << boardArray[i][j];
        cout << endl;
    }
}
void input() {
    cout << "Please enter row : ";
    cin >> playerRow;
    cout << "Please enter column : ";
    cin >> playerColumn;
    if (playerRow < 0 || playerRow>2 || playerColumn < 0 || playerColumn>2) (playerRow = playerColumn = -1);
}
void logic() {
    if (playerRow == playerColumn == -1) return;
    else if (boardArray[playerRow][playerColumn] == '0' || boardArray[playerRow][playerColumn] == 'X') return;
    char playerChar = '*';
    if (isPlayer1) playerChar = '0';
    else if (isPlayer2)playerChar = 'X';
    boardArray[playerRow][playerColumn] = playerChar;
            if ((boardArray[0][0] == '0'&& boardArray[0][1] == '0'&& boardArray[0][2] == '0') || (boardArray[0][0] == 'X' && boardArray[0][1] == 'X' && boardArray[0][2] == 'X')) {
                if (boardArray[0][0] == '0') gameOverMessage = "Player 1 wins!";
                else gameOverMessage = "Player 2 wins!";
                gameOver = true;
                return;
            }
            else if ((boardArray[0][0] == '0' && '0' == boardArray[1][1] && boardArray[2][2] == '0') || (boardArray[0][0] == 'X' && boardArray[1][1] == 'X' && boardArray[2][2] == 'X')) {
                if (boardArray[0][0] == '0') gameOverMessage = "Player 1 wins!";
                else gameOverMessage = "Player 2 wins!";
                gameOver = true;
                return;
            }
            else if ((boardArray[0][0] == '0' && boardArray[1][0] == '0' && boardArray[2][0] == '0') || (boardArray[0][0] == 'X' && boardArray[1][0] == 'X' && boardArray[2][0] == 'X')) {
                if (boardArray[0][0] == '0') gameOverMessage = "Player 1 wins!";
                else gameOverMessage = "Player 2 wins!";
                gameOver = true;
                return;
            }
            else if ((boardArray[0][1] == '0' && boardArray[1][1] == '0' && boardArray[2][1] == '0') || (boardArray[0][1] == 'X' && boardArray[1][1] == 'X' && boardArray[2][1] == 'X')) {
                if (boardArray[0][1] == '0') gameOverMessage = "Player 1 wins!";
                else gameOverMessage = "Player 2 wins!";
                gameOver = true;
                return;
            }
            else if ((boardArray[0][2] == '0' && boardArray[1][2] == '0' && boardArray[2][3] == '0') || (boardArray[0][2] == 'X' && boardArray[1][2] == 'X' && boardArray[2][3] == 'X')) {
                if (boardArray[0][2] == '0') gameOverMessage = "Player 1 wins!";
                else gameOverMessage = "Player 2 wins!";
                gameOver = true;
                return;
            }
            else if ((boardArray[1][0] == '0' && boardArray[1][1] == '0' && boardArray[1][2] == '0') || (boardArray[1][0] == 'X' && boardArray[1][1] == 'X' && boardArray[1][2] == 'X')) {
                if (boardArray[0][1] == '0') gameOverMessage = "Player 1 wins!";
                else gameOverMessage = "Player 2 wins!";
                gameOver = true;
                return;
            }
            else if ((boardArray[2][0] == '0' && boardArray[2][2] == '0' && boardArray[2][3] == '0') || (boardArray[2][0] == 'X' && boardArray[2][2] == 'X' && boardArray[2][3] == 'X')) {
                if (boardArray[2][0] == '0') gameOverMessage = "Player 1 wins!";
                else gameOverMessage = "Player 2 wins!";
                gameOver = true;
                return;
            }
            else if ((boardArray[2][0] == '0' && boardArray[2][1] == '0' && boardArray[2][2] == '0') || (boardArray[2][0] == 'X' && boardArray[2][1] == 'X' && boardArray[2][2] == 'X')) {
                if (boardArray[2][0] == '0') gameOverMessage = "Player 1 wins!";
                else gameOverMessage = "Player 2 wins!";
                gameOver = true;
                return;
            }
    bool isEstaric = false;
    for (int i = 0; i < 3 && !isEstaric ; i++)
        for (int j = 0; j < 3; j++) {
            if (boardArray[i][j] == '*') {
                isEstaric = true;
                break;
            }
        }
    if (!isEstaric) {
        gameOverMessage = "Draw!";
        gameOver = true;
    }

    isPlayer1 = !isPlayer1;
    isPlayer2 = !isPlayer2;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
