#include <iostream>
#include <random>
const int width = 50;
const int height = 25;

const char wall = '#';
const char food = '*';
const char body = 'O';
const char space = ' ';
//function declaratons
void draw_board(char board[height][width]); //this function is to draw the gameboard.
void generate_food(char board[height][width]); //this function will take the gameboard array as input and return the gameboard array with food.
int main() {
	
	//create 2d array for the game board
	char gameBoard[height][width];

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

	//infinite loop for drawing game board, processing input, updating game logic
	while (true) {
		// draw the game board
		draw_board(gameBoard);

		//reading input
		//readInput();

		//update game logic

		//delay

		//exit loop when game ends
		break;
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
	std::uniform_int_distribution<> height_dis(1, height-1);
	std::uniform_int_distribution<> width_dis(1, width-1);

	//for loop to update board
	for (int i = 1; i <= food_amt; i++) {
		int x = height_dis(gen);
		int y = width_dis(gen);
		board[x][y] = food;
	}
}

