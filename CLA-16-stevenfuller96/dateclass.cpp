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


void DateClass::DisplayStandard() const{
  cout << "Date: " << getMonth() << "/" << getDay() << "/" << getYear() << endl;
}

void DateClass::DisplayFull() const{
  if(getMonth() == 1){
    cout << "Date: " << "January" << " " << getDay() << "th, " << getYear() << endl;
  }
  else if(getMonth() == 2){
    cout << "Date: " << "February" << " " << getDay() << "th, " << getYear() << endl;
  }
  else if(getMonth() == 3){
    cout << "Date: " << "March" << " " << getDay() << "th, " << getYear() << endl;
  }
  else if(getMonth() == 4){
    cout << "Date: " << "April" << " " << getDay() << "th, " << getYear() << endl;
  }
  else if(getMonth() == 5){
    cout << "Date: " << "May" << " " << getDay() << "th, " << getYear() << endl;
  }
  else if(getMonth() == 6){
    cout << "Date: " << "June" << " " << getDay() << "th, " << getYear() << endl;
  }
  else if(getMonth() == 7){
    cout << "Date: " << "July" << " " << getDay() << "th, " << getYear() << endl;
  }
  else if(getMonth() == 8){
    cout << "Date: " << "August" << " " << getDay() << "th, " << getYear() << endl;
  }
  else if(getMonth() == 9){
    cout << "Date: " << "September" << " " << getDay() << "th, " << getYear() << endl;
  }
  else if(getMonth() == 10){
    cout << "Date: " << "October" << " " << getDay() << "th, " << getYear() << endl;
  }
  else if(getMonth() == 11){
    cout << "Date: " << "November" << " " << getDay() << "th, " << getYear() << endl;
  }
  else {
    cout << "Date: " << "December" << " " << getDay() << "th, " << getYear() << endl;
  }
}

bool DateClass::SameDate(DateClass d) const{
  if(day == d.day && month == d.month && year == d.year){
    return true;
  }
  return false;
} 

bool DateClass::PriorTo(DateClass d) const{
  if(day < d.day || month < d.month || year < d.year){
    return true;
  }
  return false;
}