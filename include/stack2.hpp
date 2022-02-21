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
    start = new Item<T>;
    last = start;
  }

  explicit Stack2(T&& valueStart) {
    start = new Item<T>;
    start->value = std::move(valueStart);
    start->link = nullptr;
    last = start;
  }

  Stack2(Stack2&& value)
  {
    start = std::move(value.start);
    last = std::move(value.last);
  }

  explicit Stack2(const T& valueStart) = delete;

  ~Stack2() {
    Item<T>* temp;
    if (checkDestructor)
    {
      while (start->link) {
        temp = start;
        while (temp->link != last) {
          temp = temp->link;
        }
        if (last) {
          delete(last);
          temp->link = nullptr;
        }
        last = temp;
      }
      if (last)
      {
        delete(last);
      }
      checkDestructor = false;
    }
  }

  template <typename... Args>
  void push_emplace(Args&&... args) {
    if (!start->value) {
      last->value = { std::forward<Args>(args)... };
      last->link = nullptr;
      return;
    }
    Item<T>* temp = new Item<T>;
    last->link = temp;
    temp->value =  { std::forward<Args>(args)... };
    temp->link = nullptr;
    last = temp;
  }

  void push(T&& value) {
    if (!start->value) {
      last->value = std::move(value);
      last->link = nullptr;
      return;
    }
    Item<T>* temp = new Item<T>;
    temp->value = std::move(value);
    temp->link = nullptr;
    last = temp;
  }

  const T& head() const { return last->value; }

  T pop() {
    if (!start->link)
    {
      T value = last->value;
      return value;
    } else {
      Item<T>* temp = start;
      while (temp->link != last) {
        temp = temp->link;
      }
      T value = last->value;
      if (last) {
        delete (last);
        temp->link = nullptr;
      }
      last = temp;
      return value;
    }
  }

  Stack2<T>& operator=(const Stack2<T>& right) = delete;

  Stack2<T>& operator=(Stack2<T>&& right) {
    if ((start != right.start) || (last != right.last))
    {
      ~Stack2();
      start = std::move(right.start);
      last = std::move(right.last);
      checkDestructor = true;
    }
    return *this;
  }
};

#endif  // INCLUDE_STACK2_HPP_
