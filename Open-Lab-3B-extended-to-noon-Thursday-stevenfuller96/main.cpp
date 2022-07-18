/*
PROGRAMMER: Steven Fuller
Assignment: OLA 3B
Class: CSIC 2170: Summer 2022
Course Instructor: Dr. Cen Li
Due Date: Thursday, 7/14/22
Description: This program reads an ISBN from a data file and tests to see if the ISBN is a valid ISBN.
The input is from a .dat file
The output should be in the console and will list the ISBN and if it is valid or invalid.
*/

#include <iostream> 
#include <string> 
#include <fstream> 
#include <cassert> 
using namespace std;

// Function Prototypes
//Provide function prototypes for CheckDigit and IsValidISBN
int CheckDigit(string);
bool IsValidISBN(string);

int main( ) {
  //variable declaration
  string isbn; //ISBN number to be processed
  bool   isValid; //indicates if the isbn is valid
  ifstream  myIn;

  //loading the file 
  myIn.open("isbn.dat"); 
  assert(myIn);

  //loops through all the ISBNs in the data file
  while ( myIn >> isbn) //read a ISBN number from data file
  {
    //calls IsValidISBN to get result
    isValid = IsValidISBN(isbn);
    //prints out output based on if the ISBN is valid or not
    if ( isValid )
      cout << isbn << " is a valid ISBN number" << endl;
    else
      cout << isbn << " is not a valid ISBN number" << endl;
  }

  //closes the data file
  myIn.close();
  return 0; 
}

// Define the IsValidISBN function here. The IsValidISBN function will call function "CheckDigit" to compute the check digit
bool IsValidISBN(string isbn){
  bool isValid = false;
  int checkDigit=0;

  //call to the CheckDigit function
  checkDigit = CheckDigit(isbn);

  //checks to see if the CheckDigit function returned a number equal to the last digit of the ISBN
  if(checkDigit == (isbn[12]-'0')){
    isValid = true;
  }

  return isValid;
}

// Define CheckDigit function here.
int CheckDigit(string isbn){
  int checkDigit=0;

  //calculates the digit to check against the last digit of the ISBN for vality testing
  for(int i = 1; i<13; i++){
    if(i%2==0){
      checkDigit = checkDigit + ((isbn[i-1]-'0')*3);
    }
    else if(i%2 != 0){
      checkDigit += (isbn[i-1]-'0')*1;
    }
  }
  checkDigit %= 10;
  checkDigit = 10 - checkDigit;

  //modifies a result of 10 to a 0
  if(checkDigit == 10){
    checkDigit = 0;
  }
  
  return checkDigit;
}