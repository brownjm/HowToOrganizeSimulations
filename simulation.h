#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <vector>


// main simulation data to be shared with observers
struct Data {
  const double dx;
  const std::vector<double>& values;
};



class Simulation {
public:
  Simulation(int N, double dx);
  void update(double dt); // advance the simulation
  Data get_data();
  
private:
  int N;
  double dx;
  std::vector<double> values;
};

#endif // SIMULATION_H_
