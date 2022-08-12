#include <iostream>
#include <cmath>
using namespace std;

float Power(float x, float y);

int main() {
  float x, y;
  float result;

  cout << "Please enter the base and exponent values: ";
  cin >> x >> y;
  cout << endl;

  result = Power(x, y);

  cout << x << " raises to the power of " << y << " equals to " << result;
  
  return 0;
}

float Power(float x, float y){
  if(y == 0){
    return 1;
  }
  else if (y == 1){
    return x;
  }
  else if(y > 1){
   return x * Power(x,y-1);
  }
  else {
    return 1/ Power(x, -y);
  }
}