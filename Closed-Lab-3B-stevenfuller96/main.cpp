#include <iostream>
using namespace std;

int main() {
  //variable declaration
  int value1, value2, value3;
  int temp;

  //user input
  cout << "Please enter three integer values:";
  cin >> value1 >> value2 >> value3;

  if (value1 > value2){
    temp = value2;
    value2 = value1;
    value1 = temp;
    }

  if (value1 > value3){
    temp = value3;
    value3 = value1;
    value1 = temp;
    }
  
  if (value2 > value3){
    temp = value3;
    value3 = value2;
    value2 = temp; 
    }
  
  cout << endl;
  cout << "The three values in ascending order are: "<< value1 << ' '<< value2 << ' '<< value3;
  
  return 0;
}