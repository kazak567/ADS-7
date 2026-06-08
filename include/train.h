// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
  struct Compartment {
    bool lampOn;
    Compartment* forward;
    Compartment* backward;
  };

  int moveCounter;
  Compartment* startCompartment;

 public:
  Train();
  ~Train();

  void attachWagon(bool initialState);
  int determineSize();
  int getMoveCount();
};

#endif  // INCLUDE_TRAIN_H_
