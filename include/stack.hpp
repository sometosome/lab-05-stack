// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_STACK_HPP_
#define INCLUDE_STACK_HPP_
#include <stdexcept>
#include <utility>

template <typename T>
struct Item {
  T value;
  Item* link;
};

template <typename T>
class Stack {
 private:
  Item<T>* last;
  Item<T>* start;
  bool check;

 public:
  Stack() {
    start = new Item<T>;
    last = start;
    check = true;
  }

  Stack<T>& operator=(const Stack<T>& right) = delete;

  Stack<T>& operator=(Stack<T>&& right) {
    if ((start != right.start) || (last != right.last))
    {
      ~Stack();
      start = std::move(right.start);
      last = std::move(right.last);
      check = true;
    }
    return *this;
  }

  explicit Stack(T&& valueStart) noexcept {
    check = true;
    start = new Item<T>;
    start->value = std::move(valueStart);
    start->link = nullptr;
    last = start;
  }

  Stack(Stack&& value)
  {
    start = std::move(value.start);
    last = std::move(value.last);
  }

  explicit Stack(const T& value) = delete;

  ~Stack() {
    Item<T>* temp;
    if (check)
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
      check = false;
    }
  }

  void push(T&& value) {
    if (!start->value) {
      start->value = std::move(value);
      start->link = nullptr;
      last = start;
      return;
    }
    Item<T>* temp = new Item<T>;
    last->link = temp;
    temp->value = std::move(value);
    temp->link =  nullptr;
    last = temp;
  }

  void push(const T& value) {
    if (!start->value) {
      last->value = value;
      last->link = nullptr;
      start = last;
      return;
    }
    Item<T>* temp = new Item<T>;
    last->link = temp;
    temp->value = value;
    temp->link = nullptr;
    last = temp;
  }

  void pop() {
    if (!start->link)
    {
      return;
    } else {
      Item<T>* temp = start;
      while (temp->link != last) {
        temp = temp->link;
      }
      if (last) {
        delete (last);
        temp->link = nullptr;
      }
      last = temp;
      return;
    }
  }

  const T& head() const { return last->value; }
};

auto example() -> void;

#endif  // INCLUDE_STACK_HPP_
