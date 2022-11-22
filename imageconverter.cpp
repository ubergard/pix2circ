
#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h> 

#include "imageconverter.h"

/* Bogo algorithm
* Bogo algorithm tries to make the worst case scenario for placing circles, 
* by randomly placing them, with a random size, only limited by the image diagonal.
*
* Input: Number of circles
*/
void ImageConverter::bogo_algorithm(int wanted_circles)
{
    n_circles = wanted_circles;
    run_counter++;

    int rows = dims[0];
    int columns = dims[1];
    int radius_limit = sqrt(rows*rows+columns*columns);
    
    // Added run counter to make a different seed within same second
    srand(time(NULL)+run_counter);

    // Black background, only create background once
    if(!circle_list.size())
    {
        circle_list.push_back(ImageConverter::Circle(0,0,radius_limit, 1));
    }

    for(int i = 1; i < wanted_circles; i++)
    {
        // Set all values till random values
        int x = rand() % columns + 1;
        int y = rand() % rows + 1;
        int r = rand() % radius_limit + 1;
        int c = rand() % 2;

        if (c_circles < n_circles-1)
        {
            c_circles++;
            circle_list.push_back(ImageConverter::Circle(x,y,r, c));
        }
        else
        {
            circle_list[i].set_x_pos(x);
            circle_list[i].set_y_pos(y);
            circle_list[i].set_radius(r);
            circle_list[i].set_color(c);
        }
    }
}

void ImageConverter::print_circles()
{
    std::cout << "Circles: " << "\n";
    for(int i = 0; i < n_circles; i++)
    {
        std::cout << "x, y, radius, color: " 
                  << circle_list[i].get_x_pos() << ","
                  << circle_list[i].get_y_pos() << ","
                  << circle_list[i].get_radius() << ","
                  << circle_list[i].get_color()
                  << '\n';
    }
}

ImageConverter::Circle::Circle(int x, int y, int r, int c)
{
    this->set_x_pos(x);
    this->set_y_pos(y);
    this->set_radius(r);
    this->set_color(c);
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
