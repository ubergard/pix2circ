
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


  ImageConverter batman; // = new ImageConverter;
  batman.import_image(file_name);
  batman.print_image();
  batman.print_dims();

  batman.bogo_algorithm(user_input);
  batman.print_circles();


  // Check pixel
  //std::cout << batman.check_pixel(26, 13) << '\n';

  
  /* Can run multiple files... or algorithms,
     but needs allocated memory */
  
  std::string file_name_2 = "kfc.txt";
  ImageConverter *kfc = new ImageConverter;
  kfc->import_image(file_name_2);
  kfc->print_image();
  kfc->print_dims();

  kfc->bogo_algorithm(user_input);
  kfc->print_circles();
  std::cout<< '\n' << kfc->accuracy() << '\n';
  kfc->approxinate_image(); 
  
  // Delete object after use
  delete kfc;

  return 0;
}
