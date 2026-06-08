// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
  if (first == nullptr) return;

  Car *cursor = first;
  do {
    Car *follower = cursor->next;
    delete cursor;
    cursor = follower;
  } while (cursor != first);
}

void Train::addCar(bool light) {
  Car *wagon = new Car{light, nullptr, nullptr};

  if (first == nullptr) {
    first = wagon;
    first->next = first;
    first->prev = first;
  } else {
    Car *tail = first->prev;
    tail->next = wagon;
    wagon->prev = tail;
    wagon->next = first;
    first->prev = wagon;
  }
}

int Train::getLength() {
  if (first == nullptr) return 0;

  countOp = 0;
  first->light = true;

  int probe = 1;
  Car *walker = first->next;
  ++countOp;

  while (true) {
    if (walker->light) {
      walker->light = false;

      for (int step = 0; step < probe; ++step) {
        walker = walker->prev;
        ++countOp;
      }

      if (!walker->light) {
        walker->light = true;
        return probe;
      }

      for (int step = 0; step < probe; ++step) {
        walker = walker->next;
        ++countOp;
      }
    }

    walker = walker->next;
    ++countOp;
    ++probe;
  }
}

int Train::getOpCount() {
  return countOp;
}
