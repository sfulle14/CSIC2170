#include <iostream>
using namespace std;

int main() {
  // declare variables
  int year;

  // main structure of the program is a while loop
  while (cin >> year)
    {
      // determine if the year read is leap or not
      if((year%4 ==0 && year%100 !=0) || year%400==0){
        cout <<"yes"<<endl;
      }
      else{
        cout << "no"<<endl;
      }
    }

  return 0;
}