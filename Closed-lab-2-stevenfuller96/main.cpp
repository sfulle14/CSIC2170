#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float InvestmentCalculator();

int main() {
  InvestmentCalculator();
}

float InvestmentCalculator(){
  //variables
  float amount = 0.00;
  float principal;
  float interestRate;
  int timesCompounded;
  int years;

  cout << "Welcome to investment helper!" << endl;
  
  //user input
  cout << "Enter principle amount of your investment:";
  cin >> principal;
  cout << "Enter the interest rate:" ;
  cin >> interestRate;
  cout << "Enter the number of times interest is compounded per year:";
  cin >> timesCompounded;
  cout << "Enter the number of years of this investment:" ;
  cin >> years;
  cout << endl;


  //calculations
interestRate = interestRate / 100;
  
  amount = (principal * pow((1 + (interestRate / timesCompounded)),(timesCompounded * years)));

  //data output
  cout << fixed << setprecision(2);
  cout << "Your investment of $" << principal << " will grow into $" << amount << " at the end of " << years << " years." << endl;

  return amount;
}

/*
Here is an example run of the program:

Welcome to the investment helper!

Enter principle amount of your investment : $ 2500 Enter the interest rate: 6.5 Enter the number of times interest is compounded per year: 12 Enter the number of years of this investment: 10

Your investment of $2500 will grow into $4780.44 at the end of 10 years.
*/