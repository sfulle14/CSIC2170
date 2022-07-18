#include <iostream>
#include <string>
using namespace std;

int main() {
  //variable declaration
  string text;
  int frequency[26];

  //getting the user input
  cout<< "Enter text: ";
  getline(cin, text);
  cout << endl;

  //initialize all values to 0
  for (int i=0; i< 26; i++){
    frequency[i]=0;
  }

  //finding the frequency of each letter
  for(int i=0; i<text.length(); i++){
    text[i] = tolower(text[i]);
    frequency[text[i]-'a']++;
  }
  //displaying the letters and their frequency
  for(int i=0; i<26; i++){
    cout <<char('a'+i) << " : "<< frequency[i]<<endl;
  }

  return 0;
}