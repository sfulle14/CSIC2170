/*
PROGRAMMER: Steven Fuller
Assignment: OLA 1
Class: CSIC 2170: Summer 2022
Course Instructor: Dr. Cen Li
Due Date: Thursday, 7/7/22
Description: A C++ program that, given a person’s birth date, computes and displays the day of the week the person was born. 
The input is from a .dat file
The output should be in the console and a list of dates with their day of the week.
*/

#include <iostream>  // for cin, cout, endl, etc
#include <fstream> // for ifstream
#include <cassert>  // for assert
#include <cmath>
using namespace std;

int main()
{
  int day; // a person's day of birth from user input.
  int month; // a person's month of birth from user input.
  int year; // a person's year of birth from user input.
  
  // declare other variables here
  int d;
  int m;
  int D;
  int C;
  int f;
  int modifiedYear;
  bool valid;

  ifstream myIn("birthday.dat");
  assert(myIn);

  // This loop will read one birthday at a time til the end
  // of the data file is reached
  // For each birthday read:
  // (1) check whether the birthday is valid
  //     if it is not valid, display the message
  // (2) if it is valid compute and display the day of the week
  while (myIn >> month >> day >> year)
  {   
    valid = true;
    // Check for birthday validity
    //checks for leap year
    if(month == 2){
      if((year%4 == 0 && year%100 != 0) || year%400 == 0){
        if(day > 29){
          valid = false;
        }
      }
      else if(day > 28){
        valid = false;
      }
    }
    //September, April, June, and November
    else if(month == 4 || month == 6 || month == 9 || month == 11){
      if (day > 30){
        valid = false;
      }
    }
      //months with 31 days
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
      if (day > 31){
        valid = false;
      }
    }
     
    // if the birthday is valid, compute and display its corresponding weekday
    if(month == 1){
      m=11;
      modifiedYear = year - 1;
      d = day;
      D = modifiedYear%100;
      C = modifiedYear/100;     
    }
    else if(month == 2){
      m=12;
      modifiedYear = year - 1;
      d = day;
      D = modifiedYear%100;
      C = modifiedYear/100;     
    }
    else if(month == 3){
      m=1;
      modifiedYear = year;
      d = day;
      D = modifiedYear%100;
      C = modifiedYear/100;     
    }
    else if(month == 4){
      m=2;
      modifiedYear = year;
      d = day;
      D = modifiedYear%100;
      C = modifiedYear/100;     
    }
    else if(month == 5){
      m=3;
      modifiedYear = year;
      d = day;
      D = modifiedYear%100;
      C = modifiedYear/100;     
    }
    else if(month == 6){
      m=4;
      modifiedYear = year;
      d = day;
      D = modifiedYear%100;
      C = modifiedYear/100;     
    }
    else if(month == 7){
      m=5;
      modifiedYear = year;
      d = day;
      D = modifiedYear%100;
      C = modifiedYear/100;     
    }
    else if(month == 8){
      m=6;
      modifiedYear = year;
      d = day;
      D = modifiedYear%100;
      C = modifiedYear/100;     
    }
    else if(month == 9){
      m=7;
      modifiedYear = year;
      d = day;
      D = modifiedYear%100;
      C = modifiedYear/100;     
    }
    else if(month == 10){
      m=8;
      modifiedYear = year;
      d = day;
      D = modifiedYear%100;
      C = modifiedYear/100;     
    }
    else if(month == 11){
      m=9;
      modifiedYear = year;
      d = day;
      D = modifiedYear%100;
      C = modifiedYear/100;     
    }
    else if(month == 12){
      m=10;
      modifiedYear = year;
      d = day;
      D = modifiedYear%100;
      C = modifiedYear/100;     
    }
    //output of data
    if(!valid){
      cout << month << " " <<  day << " " << year << " => " << "Incorrect Data" << endl;
    }
    if(valid){
      f = d + floor((13*m -1)/5) + D + floor(D/4) + floor(C/4) - 2*C;
      if(f%7 == 0){
        cout << month << " " <<  day << " " << year << " => " << "Sunday" << endl;
      }
      if(f%7 == 1){
        cout << month << " " <<  day << " " << year << " => " << "Monday" << endl;
      }
      if(f%7 == 2){
        cout << month << " " <<  day << " " << year << " => " << "Tuesday" << endl;
      }
      if(f%7 == 3){
        cout << month << " " <<  day << " " << year << " => " << "Wednesday" << endl;
      }
      if(f%7 == 4){
        cout << month << " " <<  day << " " << year << " => " << "Thursday" << endl;
      }
      if(f%7 == 5){
        cout << month << " " <<  day << " " << year << " => " << "Friday" << endl;
      }
      if(f%7 == 6){
        cout << month << " " <<  day << " " << year << " => " << "Saturday" << endl;
      }
    }
        
    }// end while
                
  myIn.close();
  return 0;
}
