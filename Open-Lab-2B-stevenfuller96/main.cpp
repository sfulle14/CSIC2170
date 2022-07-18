/*
PROGRAMMER: Steven Fuller
Assignment: OLA 2B
Class: CSIC 2170: Summer 2022
Course Instructor: Dr. Cen Li
Due Date: Monday, 7/9/22
Description: Your program generates and displays the acronyms for each of the strings in a data file named “acronym.dat”.
There is no input data comes from the acronym.dat file.
The output is the string and its acryonym in the console.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <cctype>
using namespace std;

int main() {
  //declare variables
  ifstream file;
  string lines;
  int location;
  int size=0;
  
  //read file and make sure it is valid
  file.open("acronym.dat");
  assert(file);

  //loop to read all the lines in the file
  while(getline(file, lines)){
    //convert all of the letters to uppercase
    for(int i=0; i < lines.length(); i++){
      lines[i] = toupper(lines[i]);
    }
    //finding the location of the first letter of       
    //each word and outputting the lines and their      
    //acronyms
    cout << lines<< " => ";
    cout << lines[0];
    location = lines.find(' ');
    while(location != string::npos){
      cout << lines[location+1];
      size++;
      location = lines.find(' ', location+1);
    }
    cout <<endl;
  }

  return 0;
}