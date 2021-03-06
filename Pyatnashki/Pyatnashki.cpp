// Pyatnashki.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

#define SIZE 4

int Field[SIZE][SIZE];
int WinPosition[SIZE][SIZE];
int EmptyX, EmptyY, NumberOfPossibleMoves;

void CountNumberOfPossibleMoves()
{
	NumberOfPossibleMoves = 2;
	if (EmptyX > 0 && EmptyX < SIZE - 1) NumberOfPossibleMoves++;
	if (EmptyY > 0 && EmptyY < SIZE - 1) NumberOfPossibleMoves++;
}

void InitField()
{
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			Field[x][y] = y * SIZE + x + 1;
			WinPosition[x][y] = Field[x][y];
		}
	}
	EmptyX = EmptyY = SIZE - 1;
	Field[EmptyX][EmptyY] = 0;
	WinPosition[EmptyX][EmptyY] = 0;
	CountNumberOfPossibleMoves();
}

void ShowField()
{
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			if (Field[x][y] == 0)
			{
				cout << setfill(' ') << setw(2) << " " << " ";
			}
			else
			{
				cout << setfill(' ') << setw(2) << Field[x][y] << " ";
			}
			
		}
		cout << "\n";
	}
}

bool DoMove(char c)
{
	switch (c)
	{
		case 'w':
			if (EmptyY == 0) return false;
			Field[EmptyX][EmptyY] = Field[EmptyX][EmptyY - 1];
			EmptyY--;
			break;
		case 'd':
			if (EmptyY == SIZE - 1) return false;
			Field[EmptyX][EmptyY] = Field[EmptyX][EmptyY + 1];
			EmptyY++;
			break;
		case 's':
			if (EmptyX == 0) return false;
			Field[EmptyX][EmptyY] = Field[EmptyX - 1][EmptyY];
			EmptyX--;
			break;
		case 'f':
			if (EmptyX == SIZE - 1) return false;
			Field[EmptyX][EmptyY] = Field[EmptyX + 1][EmptyY];
			EmptyX++;
			break;
		default: 
			return false;
	}
	Field[EmptyX][EmptyY] = 0;
	return true;
}

void Play()
{
	int c;
	do
	{
		c = getchar();
		if (DoMove(c)) ShowField();
	} while (c != 'q');
}

int main()
{
	cout << "Hello!\n";
	system("stty raw");
	InitField();
	ShowField();
	Play();
	//cin.ignore();
    return 0;	
}

