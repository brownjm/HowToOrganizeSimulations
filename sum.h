#ifndef SUM_H_
#define SUM_H_

#include <fstream>
#include "observer.h"
#include "simulation.h"

// This is an example of an observer that computes the sum of the
// simulation values
class Sum : public Observer {

public:
  // write data to specified filename
  Sum(const std::string& filename);

  // override notify, compute the sum
  void notify(int current_step, double current_time, const Data& data) override;

  // override finalize, write data to filename
  void finalize() override;

private:
  // Store any additional data needed to perform a computation
  std::string filename;
  std::vector<int> step;
  std::vector<double> time;
  std::vector<double> sum;

};


#endif // SUM_H_
