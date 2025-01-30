/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  Node* list = new Node(1, nullptr);
  list->next = new Node(2, nullptr);
  list->next->next = new Node(3, nullptr);
  Node* even = nullptr;
  Node* odd = nullptr;
  // while (list != nullptr) {
  //   cout << list->value << endl;
  //   list = list->next;
  // }
  split(list, odd, even);
  while (even != nullptr) {
    cout << even->value << endl;
    even = even->next;
  }
  while (odd != nullptr) {
    cout << odd->value << endl;
    odd = odd->next;
  }
}
