#ifndef OBSERVER_H_
#define OBSERVER_H_

class Data;

class Observer {
public:
  // all observers will receive these parameters at intervals
  virtual void notify(int current_step, double current_time, const Data& data) = 0;

  // signals to the observers to perform a final computation,
  // such as write their results to a file
  virtual void finalize() = 0;
};

#endif // OBSERVER_H_
