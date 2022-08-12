#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//declare struct
struct CardType
{
  string suit;
  int value;
  int points;
};

//function declaration
void FormCards(CardType deck[]);
void DisplayCards(CardType deck[]);

//declaring global variable
const int NUMCARDS = 52;

int main() {
  //creating deck array of type CardType
  CardType deck[NUMCARDS];

  //user function calls
  FormCards(deck);
  DisplayCards(deck);
  
  return 0;
}
//function to create the deck of cards
void FormCards(CardType deck[]){
  for(int i = 0; i < NUMCARDS; i++){
    if(i < 13){
      deck[i].suit = "Diamond";
      deck[i].value = i+1;
      deck[i].points = 0;
      if(i==10){
        deck[i].points = -100;
      }
    }
    else if(i < 26){
      deck[i].suit = "Club";
      deck[i].value = (i)%13+1;
      deck[i].points = 0;
    }
    else if(i < 39){
      deck[i].suit = "Heart";
      deck[i].value = (i)%13+1;
      deck[i].points = 5;
      if(i > 34){
        deck[i].points = 10;
      }
    }
    else{
      deck[i].suit = "Spade";
      deck[i].value = (i)%13+1;
      deck[i].points = 0;
      if(i==50){
        deck[i].points = 100;
      }
    }
  }
}

//function to print results
void DisplayCards(CardType deck[]){
  cout << "Here is the deck of cards: "<< endl<< endl;
  cout <<  "SUIT" << setw(15) << right <<  "VALUE" << setw(15) << "POINTS" << endl;
  for(int i = 0; i < NUMCARDS; i++){
    if(i%13 == 0){
      cout << left<< setw(10) << deck[i].suit << right << setw(10) << "A" << right << setw(15) << deck[i].points << endl;
    }
    else if(i%13 == 10){
      cout << left<< setw(10) <<  deck[i].suit << setw(10) <<  right << setw(10) << "J" << setw(15) << deck[i].points << endl;
    }
    else if(i%13 == 11){
      cout << left<< setw(10) <<  deck[i].suit << setw(10) <<  right << setw(10) << "Q" << setw(15) << deck[i].points << endl;
    }
    else if(i%13 == 12){
      cout << left<< setw(10) <<  deck[i].suit << setw(10) <<  right << setw(10) << "K" << setw(15) << deck[i].points << endl;
    }
    else{
      cout << left<< setw(10) <<  deck[i].suit << setw(10) <<  right << setw(10) << deck[i].value << setw(15) << deck[i].points << endl;
    }
  }
}