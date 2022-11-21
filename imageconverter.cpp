
#include <iostream>
#include "imageconverter.h"

void ImageConverter::print_circles()
{
    for(int i = 0; i < n_circles; i++)
    {
        std::cout << "x, y, radius: " 
                  << test->get_x_pos() << ","
                  << test->get_y_pos() << ", "
                  << test->get_radius()
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
