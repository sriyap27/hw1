#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val) {
  if (tail_ == NULL || tail_->last == ARRSIZE) {
    Item* temp = new Item;
    temp->val[0] = val;
    temp->first = 0;
    temp->last = 1;
    if (tail_ == NULL) {
      tail_ = temp;
      head_ = temp;
    }
    else {
      tail_->next = temp;
      temp->prev = tail_;
      tail_ = temp;
    }
  }
  else {
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  size_++;
}

void ULListStr::push_front(const std::string& val) {
  if (head_ == NULL || head_->first == 0) {
    Item* temp = new Item;
    temp->first = ARRSIZE - 1;
    temp->last = ARRSIZE;
    temp->val[temp->first] = val;
    if (head_ == NULL) {
      tail_ = temp;
      head_ = temp;
    }
    else {
      head_->prev = temp;
      temp->next = head_;
      head_ = temp;
    }
  }
  else {
    head_->first--;
    head_->val[head_->first] = val;
  }
  size_++;
}

void ULListStr::pop_back() {
  if (size_ != 0) {
    if (tail_->last == 1) {
      Item* temp = tail_;
      tail_ = tail_->prev;
      if (tail_ != NULL) {
        tail_->next = NULL;
      }
      if (tail_ == NULL) {
        head_ = NULL;
      }
      delete temp;
    }
    else {
      tail_->last--;
    }
    size_--;
  }
}

void ULListStr::pop_front() {
  if (size_ != 0) {
    if (head_->first == ARRSIZE - 1) {
      Item* temp = head_;
      head_ = head_->next;
      if (head_ != NULL) {
        head_->prev = NULL;
      }
      if (head_ == NULL) {
        tail_ = NULL;
      }
      delete temp;
    }
    else {
      head_->first++;
    }
    size_--;
  }
}

std::string const & ULListStr::back() const {
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const {
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if(loc > size_) {
    return NULL;
  }
  Item* temp = head_;
  int ind = head_->first;
  for(size_t i = 0; i < loc; i++) {
    if(ind == ARRSIZE - 1) {
      temp = temp->next;
      ind = 0;
    }
    else {
      ind++;
    }
  }
  return &(temp->val[ind]);
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
