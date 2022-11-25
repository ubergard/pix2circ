#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>

class Image
{
public:

  /**
  * Image destructor
  *
  * @brief Clears the 2D vector and frees up the memory.
  */
  ~Image();

  // ------ Features ------
  /**
  * Import image
  *
  * @brief Imports the image based on the filename. It will use the "find_dims()"
  *        to find and check the dimensions of the image, and then "image_make()" to set the pixels value to
  *        the img_array.
  *
  * @param file_name A string, containes the file name.
  */
  void import_image(std::string file_name);

  /**
  * Print dimensions
  *
  * @brief Prints the dimensions, if the dimension are not set, it will display an error 
  *        message and return from it.
  */
  void print_dims();

  /**
  * Print image
  *
  * @brief Prints the image and if the dimension are not set, it will display an error 
  *        message and return from it.
  */ 
  void print_image();

  /**
  * Set dimensions
  *
  * @brief Sets the dimensions manually.
  *        Too be used for custom size of image and/or bypass the controll check of consictency.
  *
  * @param rows Holds the number of rows.
  * @param columns Holds the number of columns.
  */
  void set_dims(int rows, int columns);

  /**
  * Find dimensions
  *
  * @brief Will find the first columns-length and ensure all other columns have the same length.
  *        Will abort if one columns is inconsitent.
  *        Stores the dimensions if all checks out.
  *
  * @param file_name A string, containes the file name.
  */
  void find_dims(std::string file_name);

  /**
  * Make image
  *
  * @brief Imports the image based on the filename. It will check if the dimensions are set and if not, run 
  *        "find_dims()" and the run through all the pixels in the image and store the values on a 2D array.
  *        This function and "set_dims()" can be used for custom size of an image.
  *
  * @param file_name A string, containes the file name.
  */
  void image_make(std::string file_name);

  /**
  * Check pixel
  *
  * @brief Returns the pixel/color value of a given position(input).
  *
  * @param x Holds the column posistion of the pixel.
  * @param y Holds the row posistion of the pixel.
  *
  * @return int, the color value.
  */
  int check_pixel(int x, int y){return img_vector[y-1][x-1];}

  /**
  * Image imported (Should be expanded!)
  *
  * @brief Checks if all the requierd values are set for operations for an image.
  *        Checks dimensions and if atleast one pixel is given.
  *
  * @return bool, values are set.
  */

  bool is_image_imported();


protected:
  std::string image_name;
  int dims[2] = {0, 0};

  std::vector<std::vector<int>> img_vector;
};

#endif

