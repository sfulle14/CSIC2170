#ifndef dateclass_h
#define dateclass_h

class DateClass
{
  private:
    int month;
    int day;
    int year;

  public:
    DateClass(); // default constructor
    
    DateClass(int initialMonth, int initialDay, int initialYear); // value constructor


    //mutator methods
    void setYear(int newYear); //set the year value
    void setMonth(int newMonth); // set the month value
    void setDay(int newDay); // set the day value

    //Accessor methods
    int getYear() const; //returns the year
    int getMonth() const; //returns the month
    int getDay() const; //returns the day

    //Other methods
    void DisplayStandard() const; // displays the date as "Date: month/day/year"
    void DisplayFull() const; // displays the date as "Date: month day year"
    bool SameDate(DateClass d) const; // checks to see if 2 dates are the same
    bool PriorTo(DateClass d) const; //check if the "self" date is prior to the 2nd date

//~DateClass(); //destructor
//throws an error when isnt commented out
};


#endif