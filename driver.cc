#include "driver.h"
#include "simulation.h"
#include "observer.h"

Driver::Driver(Simulation& sim)
  :current_step(0), current_time(0), simulation(sim) {}

void Driver::add_observer(std::unique_ptr<Observer> obs) {
  observers.push_back(std::move(obs));
}

void Driver::run(double end_time, int steps) {
  // gives the observers the initial data
  notify_observers();

  // advance the simulation forward
  double dt = (end_time - current_time) / steps;
  for (int i = 0; i < steps; ++i) {
    simulation.update(dt);
    current_step += 1;
    current_time += dt;
    notify_observers();
  }


  finalize();
}

void Driver::notify_observers() {
  auto data = simulation.get_data();
  for (auto& obs: observers) {
    obs->notify(current_step, current_time, data);
  }
}

void Driver::finalize() {
  for (auto& obs: observers) {
    obs->finalize();
  }
}
