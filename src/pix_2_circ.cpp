
#include <iostream>
#include <memory>

// Can use image class with other features from imageconverter
//#include "image.h"
#include "imageconverter.h"

#define terminal_input


int main(int argc, char *argv[]) 
{
  // Start software
  std::cout << "\n"
          << "Starting 'Image 2 circle' converter" << "\n\n";


  int user_input = 1;
#if defined(terminal_input)
  user_input = std::stoi(argv[1]);
  if(user_input < 1)
  {
    std::cout << "PLEASE PROVIDE A VALID NUMBER!!!" << '\n'
              << "Number provided: " << user_input << "\n";
    abort();
  }
#else
  user_input = 10;
#endif
  std::cout << "Circles wanted: " << user_input << '\n';

  std::string file_name = "batman.txt";
  std::unique_ptr<imagecircles::ImageConverter> batman(new imagecircles::ImageConverter);
  batman->import_image(file_name);
  batman->print_image();
  batman->print_dims();

  batman->bogo_algorithm(user_input);
  batman->print_circles();


  // Check pixel
  std::cout << batman->check_pixel(26, 13) << '\n';


  std::string file_name_2 = "kfc.txt";
  std::unique_ptr<imagecircles::ImageConverter> kfc(new imagecircles::ImageConverter);
  kfc->import_image(file_name_2);
  kfc->print_image();
  kfc->print_dims();

  kfc->bogo_algorithm(user_input);
  kfc->print_circles();
  std::cout<< '\n' << kfc->accuracy() << '\n';
  kfc->approxinate_image(); 


  return 0;
}
