
#ifndef IMAGECONVERTER_H
#define IMAGECONVERTER_H

#include <cassert>
#include <vector>

#include "image.h"

class ImageConverter: public Image
{
public:
    void create_circles(int wanted_circles);
    void print_circles();

    class Circle
    {
    public:
        Circle() {}
        Circle(int x, int y, int r);


        int get_x_pos() const { return this->x_pos; }
        int get_y_pos() const { return this->y_pos; }
        int get_radius() const { return this->radius; }

        void set_x_pos(int x) { this->x_pos = x; }
        void set_y_pos(int y) { this->y_pos = y; }
        void set_radius(int r) { assert(r >= 0); this->radius = r; }

        bool check_circle();

    private:
        int x_pos;
        int y_pos;
        int radius;
        int size = 0;

    };


private:
    int n_circles = 100;
    int c_circles = 0;
    Circle circle_list[100]; 

    std::vector<Circle> circle_list_2;
};


#endif