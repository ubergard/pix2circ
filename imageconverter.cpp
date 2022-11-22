
#include <iostream>
#include <vector>

#include "imageconverter.h"


void ImageConverter::create_circles(int wanted_circles)
{
    n_circles = wanted_circles;
    /*
    for(int i = 0; i < wanted_circles; i++)
    {
        circle_list_2.push_back();
    }
    */
}

void ImageConverter::print_circles()
{
    for(int i = 0; i < n_circles; i++)
    {
        std::cout << "x, y, radius: " 
                  << circle_list->get_x_pos() << ","
                  << circle_list->get_y_pos() << ", "
                  << circle_list->get_radius()
                  << '\n';
    }
}

ImageConverter::Circle::Circle(int x, int y, int r)
{
    this->set_x_pos(x);
    this->set_y_pos(y);
    this->set_radius(r);
}

bool ImageConverter::Circle::check_circle()
{
    int x = this->get_x_pos();
    int y = this->get_y_pos();
    int r = this->get_radius();

    int x0 = x - r;

    while (x0 <= x+r && radius > 0)
    {
        int y0 = y - r;
        while (y0 <= y+r)
        {
            double p = (x0-x)*(x0-x)+(y0-y)*(y0-y) - r*r;
            if(p <= 0)
            {
                this->size++;
            }
            y0++;
        }
        x0++;
    }

    return false;
}
