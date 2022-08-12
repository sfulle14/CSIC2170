#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// declare struct
struct Items {
  string description;
  int amount;
};

// function declaration
void AddParts(Items parts[], string part, int num);
void RemoveParts(Items parts[], string part, int num);
void Display(Items parts[]);

// declare global variables
const int BINS = 10;

int main() {

  // declare valriables
  Items parts[BINS];
  fstream myIn;
  fstream myParts;
  string operation;
  string part;
  int num;

  // open files
  myIn.open("inventory.dat");
  assert(myIn);
  myParts.open("operations.dat");
  assert(myParts);

  // add the items and their amounts to the parts array
  int i = 0;
  while (i < BINS) {
    getline(myIn, parts[i].description);
    myIn >> parts[i].amount;
    myIn.ignore();
    // cout << parts[i].description << setw(20) << right << parts[i].amount <<
    // endl;
    i++;
  }

  //print out the results before the operations.dat file is read
  cout << "Warehouse inventory before the operations" << endl << endl;
  Display(parts);

  //check the operations file to see if you should add or remove and do the proper operation
  while (myParts >> operation) {
    if (operation == "Add") {
      myParts.ignore();
      getline(myParts, part);
      myParts >> num;
      myParts.ignore();
      AddParts(parts, part, num);
    } else if (operation == "Remove") {
      myParts.ignore();
      getline(myParts, part);
      myParts >> num;
      myParts.ignore();
      RemoveParts(parts, part, num);
    }
  }

  //print out the results after the operations.dat file is read
  //the example says valve should = 15 but the only value in operations.dat adds 15 to valves
  cout << "\n\nWarehouse inventory after the operations" << endl << endl;
  Display(parts);

  // close the file
  myIn.close();
  myParts.close();
  return 0;
}

// function to increase an items count
void AddParts(Items parts[], string part, int num) {
  // declare local variables
  int index = 0;
  int position = 0;
  bool found = false;

  // add items to array
  while (index < BINS && !found) {
    if (parts[index].description == part) {
      parts[index].amount += num;
      break;
    }
    index++;
  }
}

// function to decrease an items count
void RemoveParts(Items parts[], string part, int num) {
  // declare local variables
  int index = 0;
  int position = 0;
  bool found = false;

  // add items to array
  while (index < BINS && !found) {
    if (parts[index].description == part) {
      parts[index].amount -= num;
      break;
    }
    index++;
  }
}

// function to display results
void Display(Items parts[]) {
  cout << "Part" << setw(20) << right << "Quantity" << left << setw(20) << endl
       << endl;
  //loops throught the parts struct to print out all parts and their quantities
  for (int index = 0; index < BINS; index++) {
    cout << parts[index].description << parts[index].amount << left << setw(20)
         << endl;
  }
}
