#include<iostream>
#include<Windows.h>
using namespace std;
void game()
{
	//drawing board
	char board[3][3];int  row, column;
	bool player1 = true;
	bool player2 = false,boolean=false;
	char inputchar;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			 board[i][j]='*';
			 
		}
	
	}
	while (1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN);
		cout << "\t\t\t\t TIC TAC TOE GAME\n";
		cout << "\t\t\t\t PLAY AND ENJOY\n\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		if (player1)
		{
			inputchar = 'o';
			cout << "Its player 1 turn! Input character will \'o\'" << endl;;
		}
		else if (player2)
		{
			inputchar = 'x';
			cout << "Its player 2 turn! Input character will \'x\'"<<endl;
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << board[i][j];
			}
			cout << endl;
		}
		cout << "Enter your row number =";
		cin >> row;
		cout << "Enter your column number =";
		cin >> column;
		//logic
		if (board[row][column] == 'o' || board[row][column] == 'x' || row < 0 || row > 2 || column < 0 || column > 2) goto end;
		board[row][column] = inputchar;
		if (board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'o')
		{
			cout << "Player 1 has won!" << '\a' << endl;
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					cout << board[a][b];
				}
				cout << endl;
			}
			break;
		}
		else if (board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == 'x')
		{
			cout << "Player 2 has won!" << '\a' << endl;
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					cout << board[a][b];
				}
				cout << endl;
			}
			break;
		}
		
		else if (board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'o')
		{
			cout << "Player 1 has won!" << '\a' << endl;
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					cout << board[a][b];
				}
				cout << endl;
			}
			break;
		}
		else if (board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == 'x')
		{
			cout << "Player 2 has won!" << '\a' << endl;
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					cout << board[a][b];
				}
				cout << endl;
			}
			break;
		}
		else if (board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'o')
		{
			cout << "Player 1 has won!" << '\a' << endl;
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					cout << board[a][b];
				}
				cout << endl;
			}
			break;
		}
		else if (board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == 'x')
		{
			cout << "Player 2 has won!" << endl << '\a';
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					cout << board[a][b];
				}
				cout << endl;
			}
			break;

		}
		else if (board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == 'o')
		{
			cout << "Player 1 has won!" << endl << '\a';
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					cout << board[a][b];
				}
				cout << endl;
			}
			break;
		}
		else if (board[0][1] == 'x' && board[1][1] == 'x' && board[2][1] == 'x')
		{

			cout << "Player 2 has won!" << '\a' << endl;
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					cout << board[a][b];
				}
				cout << endl;
			}
			break;
		}
		else if (board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o')
		{
		cout << "Player 1 has won!" << endl << '\a';
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					cout << board[a][b];
				}
				cout << endl;
			}
			break;
		}
		else if (board[0][0] == 'x' && board[1][0] == 'x' && board[2][0] == 'x')
		{
		cout << "Player 2 has won!" << endl << '\a';
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					cout << board[a][b];
				}
				cout << endl;
			}
			break;
		}
		else if (board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == 'o')
		{
		cout << "Player 1 has won!" << endl << '\a';
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					cout << board[a][b];
				}
				cout << endl;
			}
			break;
		}
		else if (board[0][2] == 'x' && board[1][2] == 'x' && board[2][2] == 'x')
		{
		cout << "Player 2 has won!" << '\a' << endl;
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					cout << board[a][b];
				}
				cout << endl;
			}
			break;
		}
		else if (board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o')
		{
		cout << "Player 1 has won!" << endl << '\a';
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					cout << board[a][b];
				}
				cout << endl;
			}
			break;
		}
		else if (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x')
		{
		cout << "Player 2 has won!" << endl << '\a';
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
				{
					cout << board[a][b];
				}
				cout << endl;
			}
			break;
		}
		else
		{
			for (int p = 0; p < 3; p++)
			{
				for (int k = 0; k < 3; k++)
				{
					if (board[p][k] == '*')
					{
						boolean = true;
						break;
					}
					else
					{
						boolean = false;
					}
				}
			}
			if (boolean == false)
			{
				cout << "Game has drawn!" << '\a' << endl;
				for (int a = 0; a < 3; a++)
				{
					for (int b = 0; b < 3; b++)
					{
						cout << board[a][b] ;
					}
					cout << endl;
				}
				return;

			}
		}
		player1=!player1; player2=!player2;
		end:
		system("cls");
	}
}
void main()
{
	game();
}