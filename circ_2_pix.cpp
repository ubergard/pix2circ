
#include <iostream>
#include <string>

//#include "image.h"
#include "imageconverter.h"

#define terminal_input

int main(int argc, char *argv[]) {
  // Make image instance 
  std::string file_name = "batman.txt";
  std::cout << "\n"
          << "Starting 'Image 2 circle' converter" << "\n"
          << "File: " << file_name << "\n\n";


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

  ImageConverter batman1; // = new ImageConverter;
  batman1.import_image(file_name);
  batman1.print_image();
  batman1.print_dims();

  batman1.bogo_algorithm(user_input);
  batman1.print_circles();


  // Check pixel
  //std::cout << batman1.check_pixel(26, 13) << '\n';

  
  /* Can run multiple files... or algorithms,
     but needs allocated memory */
  
  std::string file_name_2 = "kfc.txt";
  ImageConverter *batman2 = new ImageConverter;
  batman2->import_image(file_name_2);
  batman2->print_image();
  batman2->print_dims();

  batman2->bogo_algorithm(user_input);
  batman2->print_circles();
  std::cout<< '\n' << batman2->Matthews_correlation_coefficient() << '\n';
  
  
  // Delete object after use
  delete batman2;

  return 0;
}
