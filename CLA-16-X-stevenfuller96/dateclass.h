#ifndef dateclass_h
#define dateclass_h

#include <iostream>
using namespace std;

class DateClass; //Forward declaration

//function prototypes for overload
ostream &operator << (ostream &, const DateClass &);
istream &operator >> (istream &, DateClass &);

class DateClass
{
  private:
    int month;
    int day;
    int year;

  public:
    DateClass(); // default constructor
    
    DateClass(int initialMonth, int initialDay, int initialYear); // value constructor

    //copy constructor
    DateClass(const DateClass& d){
      month = d.month;
      day = d.day;
      year = d.year;
    };

    //mutator methods
    void setYear(int newYear); //set the year value
    void setMonth(int newMonth); // set the month value
    void setDay(int newDay); // set the day value

    //Accessor methods
    int getYear() const; //returns the year
    int getMonth() const; //returns the month
    int getDay() const; //returns the day


//~DateClass(); //destructor
//throws an error when isnt commented out

    bool operator == (const DateClass &);
    bool operator < (const DateClass &);
    
    friend ostream &operator << (ostream &, const DateClass &);
    friend istream &operator >> (istream &, DateClass &);
};


#endif