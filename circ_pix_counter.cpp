
// Calculating area of circle based on txt file
#include <iostream>
#include <string>
// #include<cmath>

#include "circle.h"
#include "image.h"

#define PI 3.1415

int main() {
  // Make one circle
  Circle test(0, 0, 1);
  int radius = test.get_radius();

  // Check circle and size
  bool blocked = test.check_circle();
  std::cout << test.size << '\n';

  // Importing image
  int len = 0;
  int wid = 0;
  std::cin >> wid >> len; // input size of image
  std::cout << wid << ' ' << len << '\n';

  int image[wid][len];
  for (int y = 0; y < len; y++) {
    for (int x = 0; x < wid; x++) {
      std::cin >> image[x][y];
    }
  }

  // Print image
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < wid; j++) {
      std::cout << image[j][i];
    }
    std::cout << '\n';
  }

  // Check pixel
  // std::cout << image[25][12] << '\n';i

  // Make image instance 
  std::string file_directory = "data.txt";

  Image image2(file_directory);
  //image2.print_stuff();
  image2.print_dims();
  return 0;
}
