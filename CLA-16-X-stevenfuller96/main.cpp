#include "dateclass.h"
#include <iostream> 
using namespace std;

int main() {
  //create objects
  DateClass firstDate;
  DateClass secondDate(3, 15, 2019);

  //change the values of the first date
  firstDate.setMonth(7);
  firstDate.setDay(17);
  firstDate.setYear(2019);

  cout << "first date: " << firstDate;

  if(firstDate == secondDate){
    cout << "Same date\n";
  }
  else{
    cout << "Two different dates.\n";
  }
  
  //copy constructor is called here
  DateClass thirdDate = firstDate;

  firstDate.getMonth() >> firstDate.getDay() >> firstDate.getYear();

  if(secondDate < thirdDate){
    cout << "Second date is prior to the third date\n";
  }
  else{
    cout << "Second date is not prior to the third date\n";
  }

  return 0;
}