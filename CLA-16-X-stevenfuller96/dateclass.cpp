#include "dateclass.h"
#include <iostream> 
using namespace std;

DateClass::DateClass(){
  month = 1;
  day = 1;
  year = 1970;
}

DateClass::DateClass(int initialMonth, int initialDay, int initialYear){
  if(initialYear > 0){
    year = initialYear;
  }
  if(initialMonth >=1 && initialMonth <=12){
    month = initialMonth;
  }
  if(initialDay >= 0 && initialDay <=31){
    day = initialDay;
  }
}

void DateClass::setYear(int newYear){
  if(newYear > 0){
    year = newYear;
  }
}

void DateClass::setMonth(int newMonth){
  if(newMonth >=1 && newMonth <=12){
    month = newMonth;
  }
}

void DateClass::setDay(int newDay){
  if(newDay >= 0 && newDay <=31){
    day = newDay;
  }
}


int DateClass::getYear() const{
  return year;
}

int DateClass::getMonth() const{
  return month;
}

int DateClass::getDay() const{
  return day;
}
  
bool DateClass::operator == (const DateClass &right){
  bool result;

  if(day == right.day && month == right.month && year == right.year){
    result = true;
  }
  else {
    result = false;
  }
  return result;
}
  
bool DateClass::operator < (const DateClass &right){
  bool result;

  if(day < right.day || month < right.month || year < right.year){
    result = true;
  }
  else{
    result = false;
  }
  return result;
}

ostream &operator << (ostream &strm, const DateClass &obj){
  strm << obj.month <<"/" << obj.day << "/" << obj.year << endl;
  return strm;
}
  
istream &operator >> (istream &strm, DateClass &obj){

  cout << "Enter a month:";
  strm >> obj.month;
  cout << "Enter a day:";
  strm >> obj.day;
  cout << "Enter a year:";
  strm >> obj.year;
  
  return strm;
}