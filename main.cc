#include "driver.h"
#include "simulation.h"
#include "sum.h"

int main() {
  // parameters
  double spacing = 0.1;
  int num_points = 11;
  int steps = 10;
  double end_time = 10;
  
  // initialize simulation
  Simulation sim(num_points, spacing);

  // gives control of the simulation to the driver
  Driver driver(sim);
  
  // add an observer to calculate some results
  driver.add_observer(std::make_unique<Sum>("sum.dat"));

  // launch the simulation
  driver.run(end_time, steps);
}
