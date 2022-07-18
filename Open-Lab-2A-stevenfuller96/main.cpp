/*
PROGRAMMER: Steven Fuller
Assignment: OLA 2A
Class: CSIC 2170: Summer 2022
Course Instructor: Dr. Cen Li
Due Date: Monday 7/9/22
Description: Write a C++ program that displays all the perfect numbers that is between 0
and 10000 exclusive.
There is no input data it is all from loops.
The output is the perfect numbers printed to the console.
*/

#include <iostream>
using namespace std;

int main() {
  //variable declartion
  int num=1;
  int i=1;
  int sum = 0;

  //this loop is used to calculate the perfect numbers
  while(num<=10000){
    while(i<=10000){
      if(i < num){
        if(num%i == 0){
          sum += i;
        }        
      }
      i++;
    }
    //output the number if it is a perfect number
    if(sum == num){
      cout<<num<<endl;
    }
    //reset the variables to restart the calculations
    num++;
    i=1;
    sum=0;
  }
  return 0;
}
