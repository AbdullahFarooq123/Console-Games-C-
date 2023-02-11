#pragma once
#include<iostream>
#include<Windows.h>
#include<time.h>
#include<thread>
#include<chrono>
#include<string>
#include<conio.h>
#include"dynamicArray.h"

using namespace std;

/*
* Structure to store the 2D view of 
* elements of game e.g the snake, it's
* tails and head and fruit.
* The operators '==' and '=' are both 
* overloaded for the struct.
*/
struct Vector{

	int X_Axis;
	int Y_Axis;
	bool operator == (Vector vector) { return (this->X_Axis == vector.X_Axis) && (this->Y_Axis == vector.Y_Axis); }
	void operator =	(Vector vector) {
		this->X_Axis = vector.X_Axis;
		this->Y_Axis = vector.Y_Axis;
	}

};

class Snake{

private :

	//Player's score variable
	int score; 
	//Speed of the game
	int speed;
	//The width and height of board
	int boardWidth;
	int boardHeight;
	//The width and height of screen 
	int screenWidth;
	int screenHeight;
	//The vaiable for making the game over
	bool gameOver;
	//The boolean array to check if a movement key is pressed
	bool keys[4];
	//The display character pointer
	wchar_t* display;
	//Player field pointer
	int* playerField ;
	//Hard or classic variable
	bool isHard;
	//Console variable
	HANDLE console;
	//DWORD variable
	DWORD bytesWritten;
	//Vector variables for head and fruit
	Vector snakeHead;
	Vector fruit;
	//Vector list for tails
	dynamicArray<Vector> tails;
	//Draw function
	void draw();
	//Logic function
	void logic();
	//Input function
	void input();
	//Spawns random fruit on the screen
	void spawnRandomFruit(Vector);
	//Set movement keys to false
	void keysToFalse(int);
	//Increase the tail length
	void increaseTail(Vector);

public :

	//Constructor to initialize variables and game
	Snake(int,int,int,int);
	//Destructor
	~Snake();
	//Runs the game
	void run();

};
//Constructor sets the variables
Snake::Snake(int screenWidth, int screenHeight, int boardWidth, int boardHeight):screenWidth(screenWidth),screenHeight(screenHeight),boardWidth(boardWidth),boardHeight(boardHeight){
	
	srand(time(NULL));
	gameOver = false;
	bytesWritten = score = 0;
	//Tails is zero at start
	tails = dynamicArray<Vector>(0);
	//Sets the head in the center of the board
	snakeHead.X_Axis = boardWidth / 2;
	snakeHead.Y_Axis = boardHeight / 2;
	//Sets the movement keys to false
	for (int i = 0; i < 4; i++) keys[i] = false;
	//Initializes player field and display array
	playerField = new int[boardWidth * boardHeight]; 
	display = new wchar_t[screenWidth * screenHeight];
	//Spawns fruit randomly on the board
	fruit.X_Axis = (rand() % (boardWidth - 2) - 2 + 1) + 2;
	fruit.Y_Axis = (rand() % (boardHeight - 2) - 2 + 1) + 2;
	//Sets display to spaces
	for (int i = 0; i < screenHeight * screenWidth; i++) display[i] = L' ';
	//Sets speed to 1
	speed = 1;
	console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

}
//Destructor to de-allocate the pointers
Snake::~Snake() {
	delete[] playerField;
	delete[] display;
}
//Controls the game or runs the game
void Snake::run() {

	int signalHeight = 5;
	int signalWidth = signalHeight * 2;
	cout << "Please select mode : " << endl;
	cout << "1.CLASSIC" << endl;
	cout << "2.HARD" << endl;
	isHard = (_getch() >= 2 ? true : false);
	SetConsoleActiveScreenBuffer(console);
	wchar_t* signal = new wchar_t[signalWidth * signalHeight];
	for (int i = 0; i < (signalWidth * signalHeight); i++) signal[i] = L' ';
	while (!(0x8000 & GetAsyncKeyState(VK_RETURN))) {
		if (0x8000 & GetAsyncKeyState(VK_RIGHT)) {
			speed = speed++ > 5 ? 5 : speed;
		}
		else if (0x8000 & GetAsyncKeyState(VK_RIGHT)) {
			speed = speed-- < 0 ? 0 : speed;
		}
		for (int x = 0; x < screenWidth; x++)
			for (int y = 0; y < signalHeight; y++)
				display[(y + 2) * screenWidth + (x + 2)] = signal[y * signalWidth + x];
		WriteConsoleOutputCharacter(console, display, screenWidth * screenHeight, { 0,0 }, &bytesWritten);
	}
	//Runs the game till game is not over
	//Draws the assets, takes input and applies logic 
	while (!gameOver) {
	
		draw();
		input();
		logic();
	
	}
	//Stops the game while keep showing the gameover screen
	//till user presses 'ESC' key.
	while (!(0x8000 & GetAsyncKeyState(VK_ESCAPE))) {
	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
		WriteConsoleOutputCharacter(console, display, screenWidth * screenHeight, { 0,0 }, &bytesWritten);
		swprintf_s(&display[0], 16,L"SCORE: %8d", score);
		swprintf_s(&display[boardHeight * screenWidth + boardWidth + 100 ], 11, L"GAME OVER!\n Press ESC to quit!");
	
	}

}
//Draws the assets on the screen
void Snake::draw() {
	
	//Small tick or small pause 
	this_thread::sleep_for(60ms);
	
	//Sets the boundary of the game
	//If it is a boundary, sets it to 4 otherwise to 0,
	//in playerfield array
	for (int x = 0; x < boardWidth; x++)
		for (int y = 0; y < boardHeight; y++)
			playerField[y * boardWidth + x] = ( x == 0 || x == boardWidth - 1 || y == 0 || y == boardHeight - 1 ? 4 : 0);
	
	//Sets the snake fruit,tail and head to 1,2 and 3 respectively 
	//in the playerfield array
	playerField[fruit.Y_Axis * boardWidth + fruit.X_Axis] = 1;
	playerField[snakeHead.Y_Axis * boardWidth + snakeHead.X_Axis] = 3;
	for (Vector tempTail : tails) playerField[tempTail.Y_Axis * boardWidth + tempTail.X_Axis] = 2;
	
	//In the playerfield array, sets the display array
	//to specific characters as space,O and to special characters
	for (int x = 0; x < boardWidth; x++)
		for (int y = 0; y < boardHeight; y++)
			display[(y + 2) * screenWidth + (x + 2)] = L" O■■█"[playerField[y * boardWidth + x]];
	
	WriteConsoleOutputCharacter(console, display, screenWidth * screenHeight, { 0,0 }, &bytesWritten);
	swprintf_s(&display[0], 16, L"SCORE: %8d", score);

}
//Gets input from the user
void Snake::input() {
	
	if (0x8000 & GetAsyncKeyState(VK_UP)) keysToFalse(0); //Up key
	else if (0x8000 & GetAsyncKeyState(VK_DOWN)) keysToFalse(1); //Down Key
	else if (0x8000 & GetAsyncKeyState(VK_RIGHT)) keysToFalse(2); //Right key
	else if (0x8000 & GetAsyncKeyState(VK_LEFT)) keysToFalse(3); //Left key

}

void Snake::logic() {

	//Passes the coordinates of head to
	//tails
	Vector tempHeadVector = snakeHead;
	for (Vector &tempTails : tails) {
		Vector tempVector = tempTails;
		tempTails = tempHeadVector;
		tempHeadVector = tempVector;
	}

	//Continues to decrease or increase
	//coordinates according to key pressed
	if (keys[0]) snakeHead.Y_Axis--;
	else if (keys[1]) snakeHead.Y_Axis++;
	else if (keys[2]) snakeHead.X_Axis++;
	else if (keys[3]) snakeHead.X_Axis--;
	
	//If snake reaches the boundary,
	//resets the head or the game is
	//over. However if head touches
	//tail, the game is also over
	if (snakeHead.X_Axis == 0)	snakeHead.X_Axis = boardWidth - 2;
	else if (snakeHead.X_Axis == boardWidth - 1) snakeHead.X_Axis = 1;
	else if (snakeHead.Y_Axis == 0)	snakeHead.Y_Axis = boardHeight - 2;
	else if (snakeHead.Y_Axis == boardHeight - 1) snakeHead.Y_Axis = 1;
	else for (Vector tempTail : tails) if (tempTail == snakeHead) gameOver = true;
	
	//If snake eats the fruit,
	//spawns the fruit randomly
	if (snakeHead == fruit) spawnRandomFruit(tempHeadVector);
	
	//If snake is moving vectically,
	//decreses the speed
	if (keys[0] || keys[1]) this_thread::sleep_for(20ms);

}
//Spawns fruit randomly
//and increases the tail length
//and the score
void Snake::spawnRandomFruit(Vector headVector) {

	score++;
	fruit.X_Axis = (rand() % (boardWidth - 2) - 2 + 1) + 2;
	fruit.Y_Axis = (rand() % (boardHeight - 2) - 2 + 1) + 2;
	increaseTail(headVector);

}
//Sets the cooresponding key to true
//and the other keys to false
void Snake::keysToFalse(int indexToTrue) {

	for (int i = 0; i < 4; i++) 
		keys[i] = (i == indexToTrue ? true : false);

}

//Adds a new tail in the 
//array
void Snake::increaseTail(Vector headVector) { tails.add(headVector, tails.length()); }
