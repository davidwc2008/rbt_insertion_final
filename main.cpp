/*
David Chen
C++ 2018
Red Black Tree - Insertion Program
With help from Vikram Kashyap
Implemented from algorithm on https://www.geeksforgeeks.org/red-black-tree-set-2-insert/
*/

//libraries
#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h> //for atoi
#include "rbtree.h"

using namespace std;

int main() {
  RBTree tree;
  char method;

  char fileName[30];
  ifstream inFile;
  //create the tree from file input, comma separated list
  cout << "Welcome to the Red Black Tree Program; we will balance your tree!  Enter the name of your file: " << endl;
  cin >> fileName;
  inFile.open(fileName);
  if(!inFile) {
      cout << "Error: No such file." << endl;
      return 0;
  }
  string token;
  while(getline(inFile, token, ',')) { //getline reads until the specified character (in this case it is a comma)
    int num = atoi(token.c_str()); //c_str coverts to character array; atoi is for converting to integer
    tree.add(num);
  }
  
  while (method != 'Q') {
    cout << "Available commands: Add (A), Print (P), Quit (Q).  Enter your command: " << endl;
    cin >> method;
    
    if (method == 'A') {
      int val;
      cout << "Enter value: " << endl;
      cin >> val;
      tree.add(val);
    } else if (method == 'P') {
      tree.print();
    }
  }

  return 0;
}
