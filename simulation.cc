#include "simulation.h"

Simulation::Simulation(int N, double dx)
  :N(N), dx(dx), values(N) {}

void Simulation::update(double dt) {
  double coef = dt / dx;
  for (int i = 1; i < N-1; ++i) {
    values[i] = coef * (values[i-1] + values[i+1] - 2*values[i]);
  }
}

Data Simulation::get_data() {
  Data data = {dx, values};
  return data;
}
