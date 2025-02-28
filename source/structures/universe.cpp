#include "structures/universe.h"
#include <limits>

Universe::Universe()
    : num_bodies(0),
      current_simulation_epoch(0),
      weights(),
      forces(),
      velocities(),
      positions() {}

BoundingBox Universe::get_bounding_box() const {
    if (positions.empty()) {
        return BoundingBox(0.0, 0.0, 0.0, 0.0);
    }

    double x_min = std::numeric_limits<double>::max();
    double x_max = std::numeric_limits<double>::lowest();
    double y_min = std::numeric_limits<double>::max();
    double y_max = std::numeric_limits<double>::lowest();

    for (const auto& pos : positions) {
        x_min = std::min(x_min, pos[0]);
        x_max = std::max(x_max, pos[0]);
        y_min = std::min(y_min, pos[1]);
        y_max = std::max(y_max, pos[1]);
    }

    return BoundingBox(x_min, x_max, y_min, y_max);
}

