
#include <iostream>
#include <string>

#include "image.h"
#include "imageconverter.h"

#define terminal_input

int main(int argc, char *argv[]) {
  // Make image instance 
  std::string file_name = "data.txt";
  std::string file_name_2 = "test.txt";

  std::cout << "\n"
          << "Starting 'Image 2 circle' converter" << "\n"
          << "File: " << file_name << "\n\n";


  #if defined(terminal_input)
  int user_input = std::stoi(argv[1]);
  if(user_input < 1)
  {
    std::cout << "PLEASE PROVIDE A VALID NUMBER!!!" << '\n'
              << "Number provided: " << user_input << "\n";
    abort();
  }
  std::cout << "Circles wanted: " << user_input << '\n';
  #endif

  ImageConverter *batman1 = new ImageConverter;
  batman1->import_image(file_name);
  batman1->print_image();
  batman1->print_dims();

  // Check pixel
  //std::cout << batman1->check_pixel(26, 13) << '\n';

  ImageConverter *batman2 = new ImageConverter;
  batman2->import_image(file_name_2);
  batman2->print_image();
  batman2->print_dims();


  return 0;
}
