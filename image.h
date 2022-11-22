#ifndef IMAGE_H
#define IMAGE_H

#include <string>

class Image
{
public:
  // ------ Features ------
  /**
  * Import image
  *
  * @brief Imports the image based on the filename. It will use the "find_dims()"
  *        to find and check the dimensions of the image, and then "image_make()" to set the pixels value to
  *        the img_array. 
  */
  void import_image(std::string file_name);

  /**
  * Print dimensions
  *
  * @brief Prints the dimensions
  */
  void print_dims(); 
  void print_image();
  void set_dims(int rows, int columns);
  void find_dims(std::string file_name);
  void image_make(std::string file_name);
  int check_pixel(int x, int y){return img_array[y-1][x-1];}
  bool is_image_imported();

protected:
  std::string image_name;
  int dims[2] = {0, 0};
  int img_array[1024][1024];
};

#endif

