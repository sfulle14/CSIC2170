/*
PROGRAMMER: Steven Fuller
Assignment: OLA 3A
Class: CSIC 2170: Summer 2022
Course Instructor: Dr. Cen Li
Due Date: Wednesday, 7/13/22
Description: This program takes one change value (between 1 and 99) and prints out what coins can be used to make that change. Use coin denominations of 25 cents (quarters), 10 cents (dimes), and 1 cent (pennies). Do not use nickels and half-dollar coins.
The input is from a .dat file
The output should be in the console and a list of how many of each coin will make the amount listed.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <string>
using namespace std;

// declare all the user defined functions here
void ComputeCoin(int coinValue, int& number, int& amountLeft);

int main() {
  //variable declaration
  int quarters = 25;
  int dimes = 10;
  int pennies = 1;
  int coinValue;
  string fileName;
  int number=0;
  int amountLeft;

  //asking user for file name to open
  cout << "Enter the data file name: ";
  cin >> fileName;
  
  //load data from file
  ifstream myIn(fileName.c_str());
  assert(myIn);

  //print out the number of coins needed to make the amount
  while (myIn >> amountLeft){
    cout << amountLeft << " cents can be changed using: "<< endl;
    ComputeCoin(quarters, number, amountLeft);
    cout << number << " quarter(s)" << endl;
    ComputeCoin(dimes, number, amountLeft);
    cout << number << " dime(s)"<< endl;
    ComputeCoin(pennies, number, amountLeft);
    cout << number << " cent(s)"<< endl;
  }

  return 0;
}

// define all the user defined functions below
void ComputeCoin(int coinValue, int& number, int& amountLeft){
  //find number of coins needed and update amountLeft
  if ( 0 < coinValue && coinValue < 100 && 0 <= amountLeft && amountLeft < 100){
    number = amountLeft / coinValue;
    amountLeft = amountLeft - (coinValue * number);
  }
}