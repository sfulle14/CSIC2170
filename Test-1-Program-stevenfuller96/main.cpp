#include <iostream>
#include <fstream>
using namespace std;

// declare user defined functions here
void ComputeStatistics(int scores[], int len, int& highestScore, int& lowestScore, float& averageScore);
int Above80(int scores[], int len);


// declare constants here
int const SIZE = 50;

int main() {
  // declare variables
  fstream myIn;
  int scores[SIZE];
  int len = 0;
  int highestScore = 0;
  int lowestScore;
  float averageScore = 0.0;
  int numScores;

  
  // read data from the data file, store data in the array
  myIn.open("scores.dat");

  //load the data into the array and find the length
  while(len < SIZE && myIn >> scores[len]){
    len+=1;
  }


  // Call function to compute statistics
  ComputeStatistics(scores, len, highestScore, lowestScore, averageScore);

  //print out the results from ComputeStatistics
  cout << "Number of Scores read: " << len << endl;
  cout << "Highest score: " << highestScore << endl;
  cout << "Lowest score: " << lowestScore << endl;
  cout << "Average score: " << averageScore << endl;
  
  // call function to count the number of scores above 80
  numScores = Above80(scores, len);
  cout << "Number of scores above 80: "<< numScores << endl;

  //close the file
  myIn.close();
  return 0;
}

// define user defined functions here
void ComputeStatistics(int scores[], int len, int& highestScore, int& lowestScore, float& averageScore){
  int test = 0;
  int temp=0;
  int sum = scores[0];
  lowestScore = scores[0];

  //loop through the data to find the largest and smallest score
  for(int i = 1; i < len; i++){
    sum += scores[i];
    test = scores[i];
    
    if(lowestScore > test){
      temp = lowestScore;
      lowestScore = test;
      if(temp > highestScore){
        highestScore = temp;
      }
    }
    else if (test > highestScore){
      highestScore = test;
    }
  }
  averageScore = static_cast<float>(sum) / len;

  return ;
}

//finds all the scores >= 80
int Above80(int scores[], int len){
  int count = 0;
  
  for (int i = 0; i < len; i++){
    if (scores[i] >= 80){
      count++;
    }
  }
  
  return count;
}
