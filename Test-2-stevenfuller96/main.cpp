#include <iostream>
#include <string>
#include <cassert>
#include <fstream>
using namespace std;

struct Items {
  string item;
};

typedef Items ItemType;
struct Node;
typedef Node* NodePtr;
struct Node{
  ItemType data;
  NodePtr next;
};

int main() {

  Items fruits;
  fstream myIn;
  int location;
  NodePtr head=NULL; 
  NodePtr cur, prev;
  NodePtr newPtr = new Node;
  newPtr->next = NULL;
  int i = 0;


  myIn.open("location.dat");
  assert(myIn);

  while(getline(myIn, fruits.item)){
    myIn >> location;
    NodePtr newPtr = new Node;
    newPtr->next = NULL;

    if(head==NULL){
      newPtr->data.item = fruits.item;
      newPtr->next = NULL;
      head = newPtr;
    }
    else if(location == 1){
      cur->next = head->next;
      newPtr ->data.item = fruits.item;
      newPtr->next = cur;
      head = newPtr;
    }
    else{
      if(cur != NULL && i == location){
      prev->next = newPtr;
      newPtr->data.item = fruits.item;
      newPtr->next = cur->next;
      }
      else{
      prev = cur;
      prev->next = cur->next;
      cur = cur->next;
      i++;
      }
    } 
    myIn.ignore();
  }

  cout << "The list of items are:\n\n";
  cur = head;
  while(cur!= NULL){
    cout << cur->data.item << endl;
    cur = cur->next;
  }

  return 0;
}