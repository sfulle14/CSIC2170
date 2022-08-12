#include "dateclass.h"
#include <iostream> 
using namespace std;


int main() {
  //create 2 objects
  DateClass firstDate; //month=1, day=1, year=1970
  DateClass secondDate(3, 15, 2017);

  //change the values of the first date
  firstDate.setMonth(4);
  firstDate.setDay(17);
  firstDate.setYear(2018);

  //display the first date
  firstDate.DisplayStandard();

  //display the month of second date
  cout <<"2nd date month: " << secondDate.getMonth() << endl;

  //update the year and month of the second date
  secondDate.setYear(2019);
  secondDate.setMonth(7);

  //display the second date
  secondDate.DisplayStandard();
  secondDate.DisplayFull();

  //check to see if the dates are the same
  if(firstDate.SameDate(secondDate)){
    cout << "Same date\n";
  }
  else{
    cout << "Different dates\n";
  }

  //check to see if the first date it prior to the second date
  if(firstDate.PriorTo(secondDate)){
    cout << "First date is prior to the second date\n";
  }
  else{
    cout <<"First date is not prior to the second date\n";
  }

  return 0;
}