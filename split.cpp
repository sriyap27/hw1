/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */
void addNode(Node*& l, int val);


void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  if (in == nullptr) {
    return;
  }
  if (in->value % 2 == 1) {
    if (odds == nullptr) {
      Node* odd = new Node(in->value, nullptr);
      odds = odd;
    }
    else {
      addNode(odds, in->value);
    }
  }
  else {
    if (evens == nullptr) {
      Node* even = new Node(in->value, nullptr);
      evens = even;
    }
    else {
      addNode(evens, in->value);
    }
  }
  Node* temp = in;
  in = in->next;
  delete temp;
  split(in, odds, evens);
}

/* If you needed a helper function, write it here */
void addNode(Node*& l, int val) {
  if (l == nullptr) {
    l = new Node(val, nullptr);
  }
  else {
    addNode(l->next, val);
  }
}
