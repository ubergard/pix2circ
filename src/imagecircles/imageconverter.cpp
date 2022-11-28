
#include <iostream>
#include <cmath>

#include "image.h"
#include "imageconverter.h"

using namespace imagecircles;
void ImageConverter::bogo_algorithm(int wanted_circles)
{
  n_circles = wanted_circles;
  run_counter++;

  int rows = dims[0];
  int columns = dims[1];
  int radius_limit = sqrt(rows*rows+columns*columns);
  
  // Added run counter to make a different seed within same second
  srand(time(NULL)+run_counter);

  // Empty vector, if it is already used
  if(!circle_list.empty())
  {
    circle_list.clear();
    circle_list.shrink_to_fit();
  }

  circle_list.push_back(ImageConverter::Circle(0,0,radius_limit, 1));

  for(int i = 1; i < wanted_circles; i++)
  {
    // Set all values till random values
    int x = rand() % columns + 1;
    int y = rand() % rows + 1;
    int r = (rand() % radius_limit + 1)/(i+1) + 1;
    int c = rand() % 2;

    c_circles++;
    circle_list.push_back(ImageConverter::Circle(x,y,r,c));
  }
}

void ImageConverter::bogo_modded(int wanted_circles)
{
  n_circles = wanted_circles;
  run_counter++;

  int rows = dims[0];
  int columns = dims[1];
  int radius_limit = sqrt(rows*rows+columns*columns);
  
  // Added run counter to make a different seed within same second
  srand(time(NULL)+run_counter);

  // Empty vector, if it is already used
  if(!circle_list.empty())
  {
    circle_list.clear();
    circle_list.shrink_to_fit();

    approx_image.clear();
    approx_image.shrink_to_fit();
  }

  circle_list.push_back(ImageConverter::Circle(0,0,radius_limit, 0));

  double accuracy_prev = 0;

  c_circles = 0;
  for(int i = 1; i < wanted_circles;)
  {
    // Set all values till random values
    int x = rand() % columns + 1;
    int y = rand() % rows + 1;
    int r = (rand() % radius_limit + 1)/(i+1) + 1;
    int c = rand() % 2;

    if (c_circles < n_circles-1) 
    {
      circle_list.push_back(ImageConverter::Circle(x,y,r,c));
    }
    else
    {
      circle_list[i].set_x_pos(x);
      circle_list[i].set_y_pos(y);
      circle_list[i].set_radius(r);
      circle_list[i].set_color(c);
    }

    double accuracy_new = accuracy();
    if(accuracy_new >= accuracy_prev)
    {
      i++;
      c_circles++;
      accuracy_prev = accuracy_new;
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
  std::cout << "\n";
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

void ImageConverter::print_approx_image(){
  if(approx_image.empty())
  {
    std::cout << "Could not print image!" << '\n';
    return;
  }

 for (int m = 0; m < dims[0]; m++) 
  {
    for (int n = 0; n < dims[1]; n++) 
    {
      std::cout << approx_image[m][n];
    }
    std::cout << '\n';
  }
}

void ImageConverter::approximate_image(){
  if(approx_image.empty())
  {
    for (int m = 0; m < dims[0]; m++) 
    {
      approx_image.push_back(std::vector<int>());
      for (int n = 0; n < dims[1]; n++)
      {
        approx_image[m].push_back(0);
      }
    }
  }


  for(int i = 0; i < c_circles; i++)
  {
  
    int x = circle_list[i].get_x_pos();
    int y = circle_list[i].get_y_pos();
    int r = circle_list[i].get_radius();
    int c = circle_list[i].get_color();

    int x0 = x - r;
    int x_max = x+r;
    if(x0 < 0)
    {
      x0 = 0;
    }
    if(x0 >= dims[0])
    {
      x0 = dims[0] - 1;
    }
    if(x_max >= dims[0])
    {
      x_max = dims[0] - 1;
    }

    while (x0 <= x_max)
    {
      int y0 = y - r;
      int y_max = y + r;
      if(y0 < 0)
      {
        y0 = 0;
      }
      if(y0 >= dims[1])
      {
        y0 = dims[1] - 1;
      }
      if(y_max >= dims[1])
      {
        y_max = dims[1] - 1;
      }

      while (y0 <= y_max)
      {
        double p = (x0-x)*(x0-x)+(y0-y)*(y0-y) - r*r;
        if(p <= 0)
        {
          approx_image[x0][y0]= c;
        }
        y0++;
      }
      x0++;
    }
  }
}

double ImageConverter::accuracy()
{
  int tp = 0;
  int tn = 0;
  int fp = 0;
  int fn = 0;
  evaluation_of_pixels(tp, tn, fp, fn);
  return (tp + tn)/(tp + fp + fn + tn);
}
  
double ImageConverter::precision()
{
  int tp = 0;
  int tn = 0;
  int fp = 0;
  int fn = 0;
  evaluation_of_pixels(tp, tn, fp, fn);
  return tp/(tp+fp);
}

double ImageConverter::recall()
{
  int tp = 0;
  int tn = 0;
  int fp = 0;
  int fn = 0;
  evaluation_of_pixels(tp, tn, fp, fn);
  return tp/(tp+fp);
}

double ImageConverter::f1_score()
{
  int tp = 0;
  int tn = 0;
  int fp = 0;
  int fn = 0;
  evaluation_of_pixels(tp, tn, fp, fn);
  return (2 * tp)/(2*tp + fp +fn);
}
  
double ImageConverter::matthews_correlation_coefficient()
{
  int tp = 0;
  int tn = 0;
  int fp = 0;
  int fn = 0;
  evaluation_of_pixels(tp, tn, fp, fn);
  return (tp*tn - fp*fn)/(sqrt((tp + fp) * (tp + fn)* (tn + fp)*(tn + fn) ));
}

void ImageConverter::evaluation_of_pixels(int &tp, int &tn, int &fp, int &fn)
{
// we asume that black is is forgraound and call it posetive
// the opesit goes for white, backgorund is white and therfor negative 
  int m = dims[0];
  int n = dims[1];
  tp = 0;
  tn = 0;
  fp = 0;
  fn = 0;

  approximate_image();

  for (int y = 0; y < m; y++) 
  {
    for (int x = 0; x < n; x++)
    {
      if (img_vector[y][x] == 1) 
        {
          if(img_vector[y][x] == approx_image[y][x]) // change img_vector to approx_image
          {
            tp++;
          } 
          else 
          {
            fn++;
          }
        } 
      else 
      {
        if(img_vector[y][x] == approx_image[y][x])
        {
          tn++;
        } 
        else 
        {
          fp ++;
        }
      }
    }
  }
}



