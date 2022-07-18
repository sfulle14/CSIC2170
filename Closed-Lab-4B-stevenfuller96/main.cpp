#include <iostream>
#include <cstdlib>  // for rand()
using namespace std;

int main() {

  //variable declaration
  int counter = 0;
  int flip;
  int coin;

  //loop that will run until the counter reaches 3
  while (counter< 3){
    //funcion to get a random number
    flip = rand();
    //this line will compute if the random number is even or odd
    coin = flip%2;
    //if the number is even it will add to the counter if it is odd it will reset the counter
    if(coin == 0){
      cout << "Head"<<endl;
      counter++;
    }
    else{
      cout << "Tail"<<endl;
      counter=0;
    }
  }

  return 0;
}