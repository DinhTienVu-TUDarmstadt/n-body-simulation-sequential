#include "plotting/plotter.h"

void Plotter::add_bodies_to_image(Universe& universe) {
    for (std::uint32_t i = 0; i < universe.num_bodies; ++i) {
        if (universe.positions[i][0] < plot_bounding_box.x_min || universe.positions[i][0] > plot_bounding_box.x_max ||
            universe.positions[i][1] < plot_bounding_box.y_min || universe.positions[i][1] > plot_bounding_box.y_max) {
            continue;
            }

        double normalized_x = (universe.positions[i][0] - plot_bounding_box.x_min) / (plot_bounding_box.x_max - plot_bounding_box.x_min);
        double normalized_y = (universe.positions[i][1] - plot_bounding_box.y_min) / (plot_bounding_box.y_max - plot_bounding_box.y_min);

        std::uint32_t pixel_x = static_cast<std::uint32_t>(normalized_x * plot_width);
        std::uint32_t pixel_y = static_cast<std::uint32_t>(normalized_y * plot_height);

        mark_pixel(pixel_x, pixel_y, 255, 255, 255);
    }
}