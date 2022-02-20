#ifndef INCLUDE_STACK_HPP_
#define INCLUDE_STACK_HPP_
#include <stdexcept>

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
    this->start = new Item<T>;
    this->last = this->start;
    this->check = true;
  };

  explicit Stack(T&& valueStart) {
    this->check = true;
    this->start = new Item<T>;
    start->value = valueStart;
    start->link = nullptr;
    this->last = this->start;
  }

  Stack(T& value) = delete;

  ~Stack() {
    Item<T>* temp;
    if (this->check)
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
      this->check = false;
    }
  }

  void push(T&& value) {
    if (!this->start->value) {
      start->value = std::move(value);
      start->link = nullptr;
      this->last = this->start;
      return;
    }
    Item<T>* temp = new Item<T>;
    last->link = temp;
    temp->value = std::move(value);
    temp->link =  nullptr;
    this->last = temp;
  };

  void push(const T& value) {
    if (!this->start->value) {
      last->value = value;
      last->link = nullptr;
      this->start = this->last;
      return;
    }
    Item<T>* temp = new Item<T>;
    last->link = temp;
    temp->value = value;
    temp->link = nullptr;
    this->last = temp;
  };

  void pop() {
    if (!this->start->link)
    {
      return;
    } else {
      Item<T>* temp = this->start;
      while (temp->link != this->last) {
        temp = temp->link;
      }
      if (last) {
        delete (last);
        temp->link = nullptr;
      }
      this->last = temp;
      return;
    }
  };

  const T& head() const { return this->last->value; };

  Stack<T>& operator=(const Stack<T>& right) = delete;

  Stack<T>& operator=(Stack<T>&& right) {
    if ((this->start != right.start) || (this->last != right.last))
    {
      this->~Stack();
      this->start = std::move(right.start);
      this->last = std::move(right.last);
      check = true;
    }
    return *this;
  }
};

auto example() -> void;

#endif  // INCLUDE_STACK_HPP_