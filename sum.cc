#include <fstream>
#include <numeric>
#include "sum.h"

Sum::Sum(const std::string& filename)
  :filename(filename) {}

void Sum::notify(int current_step, double current_time, const Data& data) {
  double total = std::accumulate(std::begin(data.values), std::end(data.values), 0);
  step.push_back(current_step);
  time.push_back(current_time);
  sum.push_back(total);
}

void Sum::finalize() {
  std::ofstream ofs(filename);
  ofs << "# step time sum\n";
  for (int i = 0; i < time.size(); ++i) {
    ofs << step[i] << " " << time[i] << " " << sum[i] << "\n";
  }
}
