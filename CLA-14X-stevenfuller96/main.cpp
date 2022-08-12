#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

//declare struct
typedef string ItemType;
struct NodeType;
typedef NodeType* NodePtr;
struct NodeType {
   ItemType data;
   NodePtr next;
};


// Declare the function "Insert" here
void Insert(NodePtr& head, ItemType item);
// Declare the function "Delete" here
void Delete(NodePtr& head, ItemType item);
// Declare the function "ReleaseList" here
void ReleaseList(NodePtr & head);

bool IsPresent(NodePtr head, ItemType data);
void DisplayList(NodePtr head);
void BuildList(ifstream & myIn, NodePtr & head);

int main()
{
  //variable declaration
    ifstream myIn;
    ItemType item;
    NodePtr  head=NULL;  // the pointer points to the beginning of the list
    
    myIn.open("grocery.dat");
    assert(myIn);

    BuildList(myIn, head);
    DisplayList(head);

  //ask user for item to remove
    cout << "Enter an item to be deleted from the list:";
    cin >> item;

    // call the function "IsPresent" to determine if the item is in the list
    // If the item is in the list, 
    //              call the function "Delete" to delete the item from the list
    //              call the function "DisplayList" to display the list after the deletion
    // else
    //     display a message "The item is not found in the list
    if (IsPresent(head, item))
    {
         Delete(head, item);
         cout << item << " deleted from the list." << endl;
         DisplayList(head);
    }
    else
         cout << "Item is not in the list." << endl;

    myIn.close();

  //release the memory space
    ReleaseList(head);

    return 0;
}

// Define the function "Insert" here. This function inserts a value into a list such that
// the list is always in sorted order, i.e., sorted in alphabetically ascending order
void Insert(NodePtr& head, ItemType item){
  NodePtr cur, prev;
  NodePtr newPtr;

  //create a new node
  newPtr = new NodeType;
  newPtr -> data = item;
  newPtr -> next = NULL;

  if (head == NULL || (head!= NULL && (item < head->data))){
    newPtr -> next = head;
    head = newPtr;
  }
  else{
    cur = head;
    prev = NULL;

    while((cur != NULL) && (cur->data < item)){
      prev = cur;
      cur = cur->next;
    }

    newPtr->next = cur;
    prev->next = newPtr;
  }
}

// Define the function "Delete" here. This function deletes a value from  the list 
// If the list is empty, show an appropriate message indicating that fact;
// The item to be deleted may be the first item in the list,
// Or it may occur in the middle or at the end of the list.
// If the item is not found in the list, show an appropriate message indicating that;
void Delete(NodePtr& head, ItemType item){
  NodePtr cur, prev;

  if(head != NULL && head->data == item){
    cur = head;
    head = head->next;
  }
  else {
    cur = head;
    prev = NULL;

    while(cur != NULL && cur->data != item){
      prev = cur;
      cur = cur->next;
    }
    prev->next = cur->next;
  }
}




// Define the function "ReleaseList" here. This function releases the memory of all the nodes in the list
void ReleaseList(NodePtr & head) {
  NodePtr cur = head;
  while (cur != NULL) {
    head = head->next;

    cur->next = NULL;
    delete cur;

    cur = head;
  }
}

// function "BuildList" reads the values one by one from the datafile and calls
// the "Insert" function to insert each value into the linked list
void BuildList(ifstream & myIn, NodePtr & head)
{
    string item;

    while (myIn >> item)
    {
         Insert(head, item);
    }
}

// function "DisplayList" prints all the items in the list one by one
void DisplayList(NodePtr head)
{
    NodePtr cur = head;

    cout << "The list of items are: " << endl;
    while (cur != NULL) 
    {
        cout << cur->data << endl;
        cur = cur->next;
    }
}

// Function "IsPresent" returns true if the item to search for is 
// in the list, otherwise it returns false
bool IsPresent(NodePtr head, ItemType item)
{
    NodePtr cur=head;
    while (cur != NULL)
    {
       if (cur->data == item)
       {
           return true;
       }
       cur = cur->next;
    }
    return false;
}
