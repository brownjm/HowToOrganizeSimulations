#ifndef DRIVER_H_
#define DRIVER_H_

#include <vector>
#include <memory>


class Observer;
class Simulation;


class Driver {
public:
  Driver(Simulation& sim);
  void add_observer(std::unique_ptr<Observer> obs);
  void run(double end_time, int steps);

private:
  int current_step;
  double current_time;
  
  Simulation& simulation;

  std::vector<std::unique_ptr<Observer>> observers;
  void notify_observers();
  void finalize(); // signals the observers to perform a final computation
};

#endif // DRIVER_H_
