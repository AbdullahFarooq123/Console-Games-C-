#pragma once
#include<Windows.h>
class tetris{
private:
	int Width = 22;
	int Height = 22;
	int fieldWidth = 18;
	int fieldHeight = 18;
	unsigned char* pField = nullptr;
	void game();
public:
	void run();
};
void tetris::game() {
	wchar_t* screen = new wchar_t[Width * Height];
	for (int i = 0; i < Width * Height; i++) screen[i] = L' ';
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;
	while (1) {
		pField = new unsigned char[fieldWidth * fieldHeight]; // Create play field buffer
		for (int x = 0; x < fieldWidth; x++) // Board Boundary
			for (int y = 0; y < fieldHeight; y++)
				pField[y * fieldWidth + x] = (x == 0 || x == fieldWidth - 1 || y == fieldHeight - 1) ? 9 : 0;
		for (int x = 0; x < fieldWidth; x++)
			for (int y = 0; y < fieldHeight; y++)
				screen[(y + 2) * Width + (x + 2)] = L" ABCDEFG=#"[pField[y * fieldWidth + x]];
	
		WriteConsoleOutputCharacter(hConsole, screen, Width * Height, { 0,0 }, &dwBytesWritten);
	}
}
void tetris::run() {
	game();
}

