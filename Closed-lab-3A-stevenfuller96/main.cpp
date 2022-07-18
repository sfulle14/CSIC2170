#include <iostream>
using namespace std;

int main() {

  //variable declaration
  int credits;
  //user input
  cout << "Please enter your total credit hours earned:";
  cin >> credits;
  cout << endl;

  //output based on answer
  if (credits <= 15 && credits > 0)
    cout << "You are a Freshman.";
  else if (credits <= 45 && credits > 0)
    cout << "You are a Sophomore.";
  else if (credits <= 75 && credits > 0)
    cout << "You are a Junior.";
  else if (credits > 75)
    cout << "You are a Senior.";
  else 
    cout << "Invalid input.";

  return 0;
}