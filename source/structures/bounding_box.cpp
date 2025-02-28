#include "structures/bounding_box.h"
#include <math.h>
#include <stdexcept>

BoundingBox::BoundingBox(double x_min, double x_max, double y_min, double y_max)
    : x_min(x_min), x_max(x_max), y_min(y_min), y_max(y_max) {}

std::string BoundingBox::get_string(){
    std::string res = "" + std::to_string(x_min) + " " + std::to_string(x_max) + "  -  " + std::to_string(y_min) + " " + std::to_string(y_max);
    return res;
}

double BoundingBox::get_diagonal(){
    // NOTE: berechnungsformel auf grund von max(1.0 , ..) vorgeben
    return std::max(1.0, sqrt(pow((x_max-x_min), 2) + pow((y_max-y_min), 2)));
}

void BoundingBox::plotting_sanity_check(){
    // if one direction has a size of 0, convert to a square
    double x_size = x_max - x_min;
    x_size = x_size < 0 ? -x_size : x_size;
    double y_size = y_max - y_min;
    y_size = y_size < 0 ? -y_size : y_size;

    if(x_size < 1e-10 && y_size > 1e-10){
        // fix x size
        //std::cout << "BoundingBox.sanity_check: inflating bounding box in x direction." << std::endl;
        x_min = x_min - (y_size / 2);
        x_max = x_max + (y_size / 2);
        // update x_size
        x_size = x_max - x_min;
        x_size = x_size < 0 ? -x_size : x_size;
    }
    if(y_size < 1e-10 && x_size > 1e-10){
        // fix y size
        //std::cout << "BoundingBox.sanity_check: inflating bounding box in y direction." << std::endl;
        y_min = y_min - (x_size / 2);
        y_max = y_max + (x_size / 2);
    }
    if(x_size < 1e-10 && y_size < 1e-10){
        throw std::invalid_argument("x and y size of bounding box are 0, thus can not be fixed by the sanity check.");
    }
}

BoundingBox BoundingBox::get_scaled(std::uint32_t scaling_factor){
    // calculate edge lenghts and multiply by scaling factor
    double x_middle = (x_min + x_max) / 2;
    double y_middle = (y_min + y_max) / 2;

    double x_size = x_max - x_min;
    double y_size = y_max - y_min;

    return BoundingBox(x_middle - x_size*scaling_factor, x_middle + x_size*scaling_factor, y_middle - y_size*scaling_factor, y_middle + y_size*scaling_factor);
}

// Method: contains
bool BoundingBox::contains(const Vector2d<double>& position) const {
    return (position[0] >= x_min && position[0] <= x_max &&
            position[1] >= y_min && position[1] <= y_max);
}

// Method: get_quadrant
BoundingBox BoundingBox::get_quadrant(std::uint8_t quadrant_index) const {
    double x_mid = (x_min + x_max) / 2.0;
    double y_mid = (y_min + y_max) / 2.0;

    switch (quadrant_index) {
        case 2: // Quadrant 2: Bottom-left
            return {x_min, x_mid, y_min, y_mid};
        case 3: // Quadrant 3: Bottom-right
            return {x_mid, x_max, y_min, y_mid};
        case 0: // Quadrant 0: Top-left
            return {x_min, y_mid, x_mid, y_max};
        case 1: // Quadrant 1: Top-right
            return {x_mid, x_max, y_mid, y_max};
        default:
            throw std::exception();
    }
}