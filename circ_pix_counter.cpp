
// Calculating area of circle based on txt file
#include <iostream>
#include <string>
// #include<cmath>

#include "circle.h"
#include "image.h"

int main() {
  // Make image instance 
  std::string file_name = "data.txt";

  Image batman(file_name);
  batman.print_image();
  batman.print_dims();

  // Check pixel
  //std::cout << batman.check_pixel(26, 13) << '\n';

  return 0;
}
