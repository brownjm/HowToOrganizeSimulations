# How to Organize Simulations

The goal of this example project is to demonstrate how to cleanly
organize the common tasks of a scientific simulation.

## The concepts

Let's begin with an example in physics: a calculation of the time
dynamics of a wavefunction subject to a particular potential. This
simulation contains a main loop where a method of updating the
wavefunction in time is applied in a step-wise manner using the
time-dependent Schroedinger equation. From the evolving wavefunction,
a large variety of results can be calculated: expectation values
(position, momentum, energy), the projection of the wavefunction onto
the ground state, etc.


The main tasks in this simulation include:

 * Updating the wavefunction at each step in the simulation
 * Controlling how small of time steps should be taken
 * Calculating some results at various intervals

Each one of these tasks could change significantly during the research
process: explicit vs. implicit integration scheme, finite-difference
vs. spectral methods, adding new observables, etc. Therefore, it's a
good idea to structure our code such that we separate these tasks and
provide a nice interface between. This will ensure that changes in one
part of the code minimially affect the others.


## The code

We make a class that is responsible for each task. The Simulation
class is responsible for performing a single step to update the main
values of the simulation. The Observer class is a base class for
objects that will be responsible for computing a result from the
simulation data. A concrete example of an Observer is the Sum
class. Finally, the Driver class controls how many steps to take in
the simulation and orchestrates the passing of data to a list of
observers.

