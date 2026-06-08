// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : moveCounter(0), startCompartment(nullptr) {}

Train::~Train() {
  if (!startCompartment) return;

  Compartment* current = startCompartment;
  do {
    Compartment* nextOne = current->forward;
    delete current;
    current = nextOne;
  } while (current != startCompartment);
}

void Train::attachWagon(bool initialState) {
  Compartment* newWagon = new Compartment{initialState, nullptr, nullptr};

  if (!startCompartment) {
    startCompartment = newWagon;
    startCompartment->forward = startCompartment;
    startCompartment->backward = startCompartment;
  } else {
    Compartment* rear = startCompartment->backward;
    rear->forward = newWagon;
    newWagon->backward = rear;
    newWagon->forward = startCompartment;
    startCompartment->backward = newWagon;
  }
}

int Train::determineSize() {
  if (!startCompartment) return 0;

  moveCounter = 0;
  startCompartment->lampOn = true;

  int estimatedLength = 1;
  Compartment* traveler = startCompartment->forward;
  ++moveCounter;

  while (true) {
    if (traveler->lampOn) {
      traveler->lampOn = false;

      for (int step = 0; step < estimatedLength; ++step) {
        traveler = traveler->backward;
        ++moveCounter;
      }

      if (!traveler->lampOn) {
        // Restore the marker and finish
        traveler->lampOn = true;
        return estimatedLength;
      }

      for (int step = 0; step < estimatedLength; ++step) {
        traveler = traveler->forward;
        ++moveCounter;
      }
    }

    traveler = traveler->forward;
    ++moveCounter;
    ++estimatedLength;
  }
}

int Train::getMoveCount() {
  return moveCounter;
}
