// Your name: 

#include <cstdlib>
#include <iostream>
using namespace std;

//global variable declaration
const int SIZE=3;

// declare all the functions here
void InitializeBoard(char gameBoard [][SIZE]);
void Display(char gameBoard[][SIZE]);
bool BoardIsFull(char gameBoard[][SIZE]);
bool Assign(char gameBoard[][SIZE], int x, int y, char p);
char CheckWon(char gameBoard[][SIZE]);

int main()
{
   char turn;
   int x, y;
   char gameBoard[SIZE][SIZE];

   // Call the function InitializeBoard to Initialize the game board pieces to blanks
   InitializeBoard(gameBoard);

   // Randomly determine who is to start the game
   int t=rand()%2;
   if (t == 1)
        turn='X';
   else
        turn='O';
   cout << "Game Starts!" << endl;

   // Display the initial game board on screen
   Display(gameBoard);

   // The game is played between two players until one of two cases occurs:
   // (1) the board is completely filled with pieces from the player, and no winner is determined. 
   // (2) one player wins the game
   while (!BoardIsFull(gameBoard)&& (CheckWon(gameBoard)=='n'))
   {
   	// Prompt the player to enter the position to play the next move
	// The move is validated in the inner loop. 
	// Only if a move is valid, it will be assigned to the gameboard
       do
       {
          do {
          cout << "Player " << turn << " makes the next move."<<endl;
          cout << "Enter the x, y location, 0<=x<3, 0<=y<3:";
          cin >> x >> y;
          } while (x>2 || x<0 || y>2 || y<0);
       }
       while (!Assign(gameBoard, x, y, turn));
       // The Assign function will attempt to assign a move from a player to the gameboard. IF there is already a piece at that location, Assign function will not put the piece at that location and it returns false. Otherwise, it will put the piece at that location and return true. 

	// Show the updated game board
       Display(gameBoard);

	// determines the player for the next move
       if (turn == 'X')
           turn = 'O';
       else
           turn = 'X';
   }

   // Display the result of the game
   if (CheckWon(gameBoard) == 'X')
      cout << "Player X wins!" << endl;
   else if (CheckWon(gameBoard) == 'O')
      cout << "Player O wins!" << endl;
   else
      cout << "This is a Draw game!" << endl;

    return 0;
}

// This function initializes all the elements of the game board to blank characters ' '
void InitializeBoard(char gameBoard [][SIZE])
{
  for(int x = 0; x < SIZE; x++){
    for (int y = 0; y < SIZE; y++){
      gameBoard[x][y] = ' ';
    }
  }
}

// This function displays the game board as a 3 by 3 board
void Display(char gameBoard[][SIZE])
{
  cout << "Current game board:" << endl;
  for(int x=0; x < SIZE; x++){
    for(int y=0; y < SIZE; y++){
      cout << gameBoard[x][y];
      cout << " |";
    }
    if(x<2){
      cout << "\n-----------\n";
    }
    else{
      cout << endl;
    }
  }
}

// This function checks to see if all the elements of the game board have been filled
bool BoardIsFull(char gameBoard[][SIZE])
{
  if(gameBoard[0][0]!= ' ' && gameBoard[0][1]!= ' ' && gameBoard[0][2]!= ' ' && gameBoard[1][0]!= ' ' && gameBoard[1][1]!= ' ' && gameBoard[1][2]!= ' ' && gameBoard[2][0]!= ' ' && gameBoard[2][1]!= ' ' && gameBoard[2][2]!= ' '){
    return true;
  }
  return false;
}

// This function assigns character p to location (x, y) on the game board
// p is either 'X' or 'O'
// If the location (x, y) already has a piece/character there, do not assign p to that location, returns the boolean value false
// If the location (x, y) does not have any piece/character, assign p to that location and return true
bool Assign(char gameBoard[][SIZE], int x, int y, char p)
{
  if(gameBoard[x][y] == ' '){
    gameBoard[x][y] = p;
    return true;
  }
  else{
    return false;
  }
}

// check to see if the game is over by checking
// if any row, column or diagonal has the same character
// if 'X' is on all elements of a row, column, or diagonal, 'X' is returned
// if 'O' is ............................................., 'O' is returned
// otherwise, 'n' is returned.
char CheckWon(char gameBoard[][SIZE])
{
  char won = 'n';

  // write multiway if statement to check whether a win condition is met
  // Case 1: the 3 elements on the i-th row of the array are the same, assign the array element value to variable "won" 
  for(int i =0; i < SIZE; i++){
  if(gameBoard[i][0] == 'X' && gameBoard[i][1]== 'X' && gameBoard[i][2] == 'X'){
    won = 'X';
  }
  else if(gameBoard[i][0] == 'O' && gameBoard[i][1]== 'O' && gameBoard[i][2] == 'O'){
    won = 'O';
  }
}
  // Case 2: the 3 elements on the j-th column of the array are the same, assign value to variable "won" 
  for(int j =0; j < SIZE; j++){
  if(gameBoard[0][j]=='X' && gameBoard[1][j]=='X' && gameBoard[2][j]=='X' ){
    won = 'X';
  }
  else if(gameBoard[0][j]=='O' && gameBoard[1][j]=='O' && gameBoard[2][j]=='O' ){
    won = 'O';
  }
}
  // Case 3: the 3 elements on the diagonal of the array are the same, assign value to variable "won"
  if(gameBoard[0][0]=='X' && gameBoard[1][1]=='X' && gameBoard[2][2]=='X'){
    won = 'X';
  }
  else if(gameBoard[0][0]=='O' && gameBoard[1][1]=='O' && gameBoard[2][2]=='O'){
    won = 'O';
  }
  
  // Case 4: the 3 elements of the second diagonal of the array are the same, assign value to variable "won"
  if(gameBoard[2][0]=='X' && gameBoard[1][1]=='X' && gameBoard[2][0]=='X'){
    won = 'X';
  }
  else if(gameBoard[2][0]=='O' && gameBoard[1][1]=='O' && gameBoard[2][0]=='O'){
    won = 'O';
  }

    return won;
}
