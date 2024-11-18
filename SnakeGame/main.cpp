#include <iostream>
#include <random>
#include <Windows.h>
#include <vector>
#include <conio.h>

//constant variables declarations
const int width = 50;
const int height = 25;
const char wall = '#';
const char food = '*';
const char body = 'O';
const char space = ' ';

//function declaratons
void draw_board(char board[height][width]); //this function is to draw the gameboard.
void generate_food(char board[height][width]); //this function will take the gameboard array as input and return the gameboard array with food.
void render_snake(char board[height][width], std::vector<std::pair<int,int>> snake);

//the snake will be a series of consecutive coordinates,
//we can represent it on the board by vector of pairs
std::vector<std::pair<int, int>> snake;

int main() {
	//create 2d array for the game board
	char gameBoard[height][width];
    snake.push_back(std::make_pair(height / 2, width / 2));
	
	// Nested loop to initialize gameBoard
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			// Condition for the walls
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
				gameBoard[i][j] = wall;
			}
			// need to randomly generate food
			else {
				gameBoard[i][j] = space; // Empty space
			}
		}
	}
	//generate food
	generate_food(gameBoard);
	//render snake
	render_snake(gameBoard, snake);
	int key_pressed_ascii;
	char key_pressed;
	//infinite loop for drawing game board, processing input, 
										//updating game logic

	while (true) {
		// draw the game board
		draw_board(gameBoard);
		//reading input
		if (_kbhit()) {//keyboard has been pressed
			key_pressed_ascii = getch();
			//find which key was pressed
			if (key_pressed_ascii == 0 || key_pressed_ascii == 224) {//Extended key
				key_pressed_ascii = getch();
				
				switch (key_pressed_ascii) {
				case 72:
					//up arrow
					break;
				case 80:
					//down arrow
					break;
				case 75:
					//left arrow
					break;
				case 77:
					//right arrow
					break;
				}
			}
			
			
		}

		//update game logic


		//delay

		//exit loop when game ends
		
		
	}
	return 0;
}

void draw_board(char board[height][width]) {
	//loop to draw the board

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}

}

void generate_food(char board[height][width]) {
	//we need to generate food that is proportionate to the size of the board
	//the size of the board is height * width, let's do (height * width) / 20 
	//to represent the total amount of starting food

	int board_area = height * width;
	int food_amt = (height * width) / 20;

	std::random_device rd;
	std::mt19937 gen(rd());

	//uniform distribution range
	std::uniform_int_distribution<> height_dis(1, height-2);
	std::uniform_int_distribution<> width_dis(1, width-2);

	//for loop to update board
	for (int i = 1; i <= food_amt; i++) {
		int x = height_dis(gen);
		int y = width_dis(gen);
		board[x][y] = food;
	}
}

void render_snake(char board[height][width], std::vector<std::pair<int,int>> snake) {
	for (int i = 0; i < snake.size(); i++) {
		board[snake[i].first][snake[i].second] = body;
	}
}

