#pragma once

#include <fstream>
#include <iomanip>
#include <filesystem>
#include "structures/universe.h"

static void save_universe(std::filesystem::path save_universe_path, const Universe& universe) {
    std::ofstream universe_file(save_universe_path);

    if (!universe_file.is_open()) {
        throw std::invalid_argument("Could not save universe to the given file!");
    }
    //To format a number to 6 decimal places
    universe_file << std::fixed << std::setprecision(6);

    // Save the number of bodies
    universe_file << "### Bodies\n";
    universe_file << universe.num_bodies << "\n";

    // Save positions
    universe_file << "### Positions\n";
    for (const auto& position : universe.positions) {
        universe_file << position[0] << " " << position[1] << "\n";
    }

    // Save weights
    universe_file << "### Weights\n";
    for (const auto& weight : universe.weights) {
        universe_file << weight << "\n";
    }

    // Save velocities
    universe_file << "### Velocities\n";
    for (const auto& velocity : universe.velocities) {
        universe_file << velocity[0] << " " << velocity[1] << "\n";
    }

    // Save forces
    universe_file << "### Forces\n";
    for (const auto& force : universe.forces) {
        universe_file << force[0] << " " << force[1] << "\n";
    }

    universe_file.close();
}

