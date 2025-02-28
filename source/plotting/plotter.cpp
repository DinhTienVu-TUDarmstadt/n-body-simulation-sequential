#include "plotting/plotter.h"
#include "io/image_parser.h"
#include "structures/vector2d.h"
#include <exception>

void Plotter::write_and_clear(){
    // create plot serial number string
    std::string serial_number_string = std::to_string(image_serial_number);
    while(serial_number_string.length() < 9){
        serial_number_string = "0" + serial_number_string;
    }

    std::string file_name = filename_prefix + "_" + serial_number_string + ".bmp";
    ImageParser::write_bitmap(output_folder_path / file_name, image);
    clear_image();
    image_serial_number += 1;
}

BitmapImage::BitmapPixel Plotter::get_pixel(std::uint32_t x, std::uint32_t y){
    return image.get_pixel(y, x);
}

void Plotter::mark_pixel(std::uint32_t x, std::uint32_t y, std::uint8_t red, std::uint8_t green, std::uint8_t blue) {
    if (x >= plot_width  || y >= plot_height) {
        throw std::exception();
    }

    image.set_pixel(y, x, BitmapImage::BitmapPixel(red, green, blue));
}

void Plotter::mark_position(Vector2d<double> position, std::uint8_t red, std::uint8_t green, std::uint8_t blue) {
    if (position[0] < plot_bounding_box.x_min || position[0] > plot_bounding_box.x_max ||
        position[1] < plot_bounding_box.y_min || position[1] > plot_bounding_box.y_max) {
        return;
        }

    double normalized_x = (position[0] - plot_bounding_box.x_min) / (plot_bounding_box.x_max - plot_bounding_box.x_min);
    double normalized_y = (position[1] - plot_bounding_box.y_min) / (plot_bounding_box.y_max - plot_bounding_box.y_min);

    std::uint32_t pixel_x = static_cast<std::uint32_t>(normalized_x * plot_width);
    std::uint32_t pixel_y = static_cast<std::uint32_t>(normalized_y * plot_height);

    if (pixel_x != 0) {
        pixel_x--;
    }
    if (pixel_y != 0) {
        pixel_y--;
    }
    mark_pixel(pixel_x, pixel_y, red, green, blue);
}

void Plotter::highlight_position(Vector2d<double> position, std::uint8_t red, std::uint8_t green, std::uint8_t blue) {
    if (position[0] < plot_bounding_box.x_min || position[0] > plot_bounding_box.x_max ||
        position[1] < plot_bounding_box.y_min || position[1] > plot_bounding_box.y_max) {
        return;
        }

    double normalized_x = (position[0] - plot_bounding_box.x_min) / (plot_bounding_box.x_max - plot_bounding_box.x_min);
    double normalized_y = (position[1] - plot_bounding_box.y_min) / (plot_bounding_box.y_max - plot_bounding_box.y_min);

    std::uint32_t pixel_x = static_cast<std::uint32_t>(normalized_x * plot_width);
    std::uint32_t pixel_y = static_cast<std::uint32_t>(normalized_y * plot_height);

    if (pixel_x != 0) {
        pixel_x--;
    }
    if (pixel_y != 0) {
        pixel_y--;
    }

    for (std::uint32_t x = 0; x < plot_width; ++x) {
        mark_pixel(x, pixel_y, red, green, blue);
    }

    for (std::uint32_t y = 0; y < plot_height; ++y) {
        mark_pixel(pixel_x, y, red, green, blue);
    }
}
