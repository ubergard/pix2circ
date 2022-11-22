#ifndef IMAGE_H
#define IMAGE_H

#include <string>

class Image
{
public:
  // Features
  void import_image(std::string file_name);
  void print_dims(); 
  void print_image();
  void find_dims(std::string file_name);
  void image_make(std::string file_name);
  int check_pixel(int x, int y){return img_array[y-1][x-1];}

protected:
  std::string image_name;
  int dims[2] = {0, 0};
  int img_array[1024][1024];
};

#endif

