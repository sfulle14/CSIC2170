#include <iostream>
#include <cstring>  // this library file needs to be included when using string type data
using namespace std;

int main() {
  //declare variables
  int counter=0;
  string text;
  int i=0;

  //get user input
  cout << "Please enter a line of text: ";
  getline(cin, text);

  //loop through the user input and count the ' '
  do
  {
    if(text[i] == ' '){
      counter++;
    }
    i++;
  } while(i < text.length());
  cout << "There are " << counter + 1 << " words in this sentence.";

  return 0;
}