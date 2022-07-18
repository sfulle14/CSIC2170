#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
using namespace std;

//function declaration
void DisplayTableHeading();
void DisplayOneLine(string title, string author, float rating, float price, int year);

int main() 
{
  //variable declaration
	int year;
	string title;
	string author;
	float rating;
	float price;
  int  count=0;

  //loading data from a file
	ifstream myIn("library.dat"); 
	assert(myIn);

 	// Display the heading of the table
	DisplayTableHeading();

	// Write a while loop here to read information for one book at a time
  while(!myIn.eof()){
    getline(myIn, title);
    getline(myIn, author); 
    myIn >> rating;
    myIn.ignore(5, '\n');
    myIn.ignore(100, ' ');
    myIn.ignore(100, ' ');
    myIn >> year;
    myIn >> price;
    myIn.ignore(100,'\n');
    cout << endl;

    //counts the number of times through the loop
    count++;
    
    // Once a record is read, it calls function "DisplayOneLine" to display the information in the required format
    DisplayOneLine(title, author,rating, price, year);  
  }

  //prints out the number of books
  cout << endl;
  cout << "There are a totel of " << count << " books." << endl;
  
  //closes the opened file
	myIn.close();

	return 0;
}

// Description: This function prints the heading of the output table of information
void DisplayTableHeading()
{
	cout << left;
	cout << fixed << showpoint << setprecision(2);
	cout << setw(25) << "TITLE" << setw(25) << "AUTHOR" << setw(10) << "RATING" << setw(10) << "PRICE" << setw(5) << "YEAR"<< endl << endl; 
	return;
}

// Description: This function prints one line of information for one book
void DisplayOneLine(string title, string author, float rating, float price, int year)
{
	cout << setw(25) << title << setw(25) << author << setw(10) << rating << setw(10) << price << setw(5) << year << endl;
	return;
}