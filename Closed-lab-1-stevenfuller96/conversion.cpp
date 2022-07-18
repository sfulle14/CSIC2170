#include <iomanip>
#include <iostream>
using namespace std;

// function declaration
float conversion();

int main() {
  conversion();
  return 0;
}

float conversion() {
  
  // variable declaration
  float amount = 0.00;
  float convertedAmount = 0.00;

    // prompt for user input
    cout << "Enter amount of US Dollar you want to convert : ";
    cin >> amount;
    cout << fixed << setprecision(2);
    cout << "You entered $" << amount << endl << endl;

    // conversion
    convertedAmount = 0.87 * amount;

    //display results
    cout << "$1 US dollar = 0.87 EUR" << endl << endl;
    cout << fixed << setprecision(2);
    cout << "$" << amount << " in US Dollars is equivalent to "
         << convertedAmount << " EUR" << endl;
    cout << endl;

  return convertedAmount;
}