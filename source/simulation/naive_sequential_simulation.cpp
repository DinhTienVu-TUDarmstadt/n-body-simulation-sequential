#include "simulation/naive_sequential_simulation.h"
#include "simulation/constants.h"
#include "physics/gravitation.h"
#include "physics/mechanics.h"
#include <vector>
#include "plotting/plotter.h"
#include <iostream>
#include <cmath>

void NaiveSequentialSimulation::calculate_forces(Universe& universe) {
    std::size_t num_bodies = universe.num_bodies;
    universe.forces.clear();
    for (size_t i = 0; i < num_bodies; i++) {
        universe.forces.emplace_back(0, 0);
    }
    for (size_t i = 0; i < num_bodies; i++) {
        for (size_t j = 0; j < num_bodies; j++) {
            Vector2d<double> direction = universe.positions[j] - universe.positions[i];
            double distance = sqrt(pow(direction[0], 2) + pow(direction[1], 2));
            if (distance == 0) {
            }else {
                direction = direction / distance;
                double force_magnitude = gravitational_force(universe.weights[i], universe.weights[j], distance);
                Vector2d<double> force = direction * force_magnitude;
                universe.forces[i] = universe.forces[i] + force;
            }
        }
    }
}

void NaiveSequentialSimulation::calculate_velocities(Universe& universe) {
    for (std::size_t i = 0; i < universe.num_bodies; i++) {
        Vector2d<double> force = universe.forces[i];
        double mass = universe.weights[i];
        Vector2d<double> acceleration = calculate_acceleration(force, mass);

        Vector2d<double> initial_velocity = universe.velocities[i];
        Vector2d<double> new_velocity = calculate_velocity(initial_velocity, acceleration,epoch_in_seconds);

        universe.velocities[i] = new_velocity;
    }
}

void NaiveSequentialSimulation::calculate_positions(Universe& universe) {
    for (std::size_t i = 0; i < universe.num_bodies; ++i) {
        Vector2d<double> velocity = universe.velocities[i];

        Vector2d<double> movement = velocity * epoch_in_seconds;

        Vector2d<double> initial_position = universe.positions[i];
        Vector2d<double> new_position = initial_position + movement;

        universe.positions[i]= new_position;
    }
}

void NaiveSequentialSimulation::simulate_epoch(Plotter& plotter, Universe& universe, bool create_intermediate_plots, std::uint32_t plot_intermediate_epochs) {
    calculate_forces(universe);

    calculate_velocities(universe);

    calculate_positions(universe);

    universe.current_simulation_epoch++;

    if (create_intermediate_plots && (universe.current_simulation_epoch % plot_intermediate_epochs == 0)) {
        plotter.add_bodies_to_image(universe);
        plotter.write_and_clear();
    }
}

void NaiveSequentialSimulation::simulate_epochs(Plotter& plotter, Universe& universe, std::uint32_t num_epochs, bool create_intermediate_plots, std::uint32_t plot_intermediate_epochs) {
    for (std::uint32_t epoch = 0; epoch < num_epochs; ++epoch) {
        simulate_epoch(plotter, universe, create_intermediate_plots, plot_intermediate_epochs);
    }
}



