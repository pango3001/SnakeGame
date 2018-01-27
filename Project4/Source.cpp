#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;
bool letsplay = true;
bool gameOver = false;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Startscreen() {
	system("cls");
	for (int i = 0; i <= height / 2; i++) {
		if (i < height / 2)
			cout << endl;
		else if (i == height / 2) {
			cout << "Welcome to the game\n";
			cout << "where the O eats the F\n";
			cout << "Try to eat all the F's you can!!!\n";
			cout << "Press any key then \"Enter\" to start!\n";
			string start;
			cin >> start; // NEED TO FINISH STARTING THE GAME

		}
	}
}
void Setup() {
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
void Draw() {
	system("cls");						// clears the screen to prepare to make a play area
	for (int i = 0; i < width + 2; i++)
		cout << "#";					// This creates the top border
	cout << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0)
				cout << "#";			// This creates the left border
			if (i == y && j == x)
				cout << "O";			// This is the head of the snake
			else if (i == fruitY && j == fruitX)
				cout << "F";
			else
				cout << " ";			// this creates the play space between the left and right borders

			if (j == width - 1)
				cout << "#";			// This creates the right border
		}
		cout << endl;
	}
	for (int i = 0; i < width + 2; i++)
		cout << "#";					// This creates the bottom border
	cout << endl << endl;
	cout << "Score: " << score;			// Displays the users current
}
void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}
void Logic() {
	switch (dir) {
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;

	}
	if (x > width || x < 0 || y > height || y < 0)
		gameOver = true;
	if (x == fruitX && y == fruitY) {
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
}
void Endgame() {
	system("cls");
	for (int i = 0; i <= height / 2; i++) {
		if (i < height / 2)
			cout << endl;
		else if (i == height / 2) {
			cout << "           You Lose!!!" << endl;
			cout << "       Your score was: " << score << endl;
			cout << "Would you like to play again? (y/n)";
		}
	}
	string playagain;
	cin >> playagain;
	if (playagain != "y")
		letsplay = false;    //THIS RESTARTS THE GAME

}

int main()
{
	while (letsplay) {
		Startscreen();
		Setup();
		while (!gameOver) {
			Draw();
			Input();
			Logic();
			Sleep(10);
		}
		Endgame();
	}
	return 0;
}