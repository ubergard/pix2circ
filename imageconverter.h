
#ifndef IMAGECONVERTER_H
#define IMAGECONVERTER_H

#include <cassert>
#include <vector>

#include "image.h"

class ImageConverter: public Image
{
public:
    // Features
    void print_circles();

    // Algorithms
    void bogo_algorithm(int wanted_circles);

    class Circle
    {
    public:
        Circle() {}
        Circle(int x, int y, int r, int c);


        int get_x_pos() const { return this->x_pos; }
        int get_y_pos() const { return this->y_pos; }
        int get_radius() const { return this->radius; }
        int get_color() const { return this->color; }

        void set_x_pos(int x) { this->x_pos = x; }
        void set_y_pos(int y) { this->y_pos = y; }
        void set_radius(int r) { assert(r >= 0); this->radius = r; }
        void set_color(int c) { this->color = c; }

        bool check_circle();

    private:
        int x_pos;
        int y_pos;
        int radius;
        int color;

        int size = 0;

    };


private:
    int n_circles = 100;
    int c_circles = 0;
    int run_counter = 0;

    std::vector<Circle> circle_list;
};


#endif