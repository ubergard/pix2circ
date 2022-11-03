
#include "circle.h"

Circle::Circle(int x, int y, int r)
{
    this->set_x_pos(x);
    this->set_y_pos(y);
    this->set_radius(r);
}

bool Circle::check_circle()
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