// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_STACK2_HPP_
#define INCLUDE_STACK2_HPP_
#include <stdexcept>
#include <utility>

#include "stack.hpp"

template <typename T>
class Stack2 {
 private:
  Item<T>* last;
  Item<T>* start;
  bool checkDestructor = true;

 public:
  Stack2() {
    this->start = new Item<T>;
    this->last = this->start;
  }

  explicit Stack2(T&& valueStart) {
    this->start = new Item<T>;
    start->value = valueStart;
    start->link = nullptr;
    this->last = this->start;
  }

  explicit Stack2(const T& valueStart) = delete;

  ~Stack2() {
    Item<T>* temp;
    if (this->checkDestructor)
    {
      while (this->start->link) {
        temp = this->start;
        while (temp->link != this->last) {
          temp = temp->link;
        }
        if (last) {
          delete(last);
          temp->link = nullptr;
        }
        this->last = temp;
      }
      if (last)
      {
        delete(last);
      }
      this->checkDestructor = false;
    }
  }

  template <typename... Args>
  void push_emplace(Args&&... args) {
    if (!this->start->value) {
      last->value = { std::forward<Args>(args)... };
      last->link = nullptr;
      return;
    }
    Item<T>* temp = new Item<T>;
    last->link = temp;
    temp->value =  { std::forward<Args>(args)... };
    temp->link = nullptr;
    this->last = temp;
  }

  void push(T&& value) {
    if (!this->start->value) {
      last->value = std::move(value);
      last->link = nullptr;
      return;
    }
    Item<T>* temp = new Item<T>;
    temp->value = std::move(value);
    temp->link = nullptr;
    this->last = temp;
  }

  const T& head() const { return this->last->value; }

  T pop() {
    if (!this->start->link)
    {
      T value = last->value;
      return value;
    } else {
      Item<T>* temp = this->start;
      while (temp->link != this->last) {
        temp = temp->link;
      }
      T value = last->value;
      if (last) {
        delete (last);
        temp->link = nullptr;
      }
      this->last = temp;
      return value;
    }
  }

  Stack<T>& operator=(const Stack<T>& right) = delete;

  Stack<T>& operator=(Stack<T>&& right) {
    if ((this->start != right.start) || (this->last != right.last))
    {
      this->~Stack();
      this->start = std::move(right.start);
      this->last = std::move(right.last);
      checkDestructor = true;
    }
    return *this;
  }
};

#endif  // INCLUDE_STACK2_HPP_
