// Open Lab 8
// BY Steven Fuller, CSCI 2170-sec, Due: 08/04/2022
// PROGRAM ID: OLA 8
// AUTHOR: Steven Fuller
// Description:  This program is to maintain a list of top hit songs, their
// artists, and billboard year.
// It can lookup, add, delete, and print out songs, their artists, and billboard
// year.
//
#include "slist.h"
#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
  // declare variables
  ifstream myIn;
  SongType aSong;
  SortedList myList;
  int selection;
  SongType item;

  // open data file
  myIn.open("topsongs.dat");
  assert(myIn);

  while (myIn >> aSong.rank) {
    myIn.ignore(100, '\n');
    getline(myIn, aSong.artist);
    getline(myIn, aSong.song);
    myIn >> aSong.billboardYear;

    myList.Insert(aSong);

    myIn.ignore(100, '\n');
  }

  do {
    cout << "Billboard Top Song Management\n\n";
    cout << "Please select from the following menu choices:\n\n";
    cout << "1. Look up an artist\n";
    cout << "2. Add a song\n";
    cout << "3. Delete a song\n";
    cout << "4. Print\n";
    cout << "5. Exit\n";
    cin >> selection;
    cin.ignore(100, '\n');

    if (selection == 1) {
      cout << "Enter an artist name:";
      getline(cin, item.artist);
      cout << endl;

      myList.Reset();
      cout << "Here are the songs by " << item.artist << endl << endl;
      cout << left << setw(30) << "Title"
           << "Rank" << right << setw(8) << "Year" << endl;
      for (int i = 0; i < myList.GetLength(); i++) {
        if (aSong.artist != item.artist && myList.HasNext()) {
          aSong = myList.GetNextItem();
        } else {
          cout << left << setw(30) << aSong.song << aSong.rank << right
               << setw(10) << aSong.billboardYear << endl;
          if (myList.HasNext()) {
            aSong = myList.GetNextItem();
          }
        }
      }
      cout << endl;
    } else if (selection == 2) {
      cout << "Enter the song title:";
      getline(cin, item.song);
      cout << "Enter the artist name:";
      getline(cin, item.artist);
      cout << "Enter the rank:";
      cin >> item.rank;
      cout << "Enter the billboard year:";
      cin >> item.billboardYear;

      myList.Insert(item);
    } else if (selection == 3) {
      cout << "Enter the song to delete:";
      getline(cin, item.song);

      myList.Reset();
      for (int i = 0; i < myList.GetLength(); i++) {
        if (aSong.song == item.song) {
          myList.Delete(item);
        } else if (myList.HasNext()) {
          aSong = myList.GetNextItem();
        }
      }

    } else if (selection == 4) {
      cout << "Enter a year:";
      cin >> item.billboardYear;

      cout << left << setw(30) << "Artist"
           << "Song" << right << setw(10) << "Rank" << endl;
      for (int i = 0; i < myList.GetLength(); i++) {
        if (aSong.billboardYear == item.billboardYear) {
          cout << left << setw(30) << aSong.artist << aSong.song << right
               << setw(10) << aSong.rank << endl;
          if (myList.HasNext()) {
            aSong = myList.GetNextItem();
          }
        } else if (myList.HasNext()) {
          aSong = myList.GetNextItem();
        }
      }

    } else if (selection == 5) {
      exit(0); // terminates the program
    } else {
      cout << "Invalid choice!\n";
      continue;
    }

  } while (selection != 5);

  // close data file
  myIn.close();
  return 0;
}