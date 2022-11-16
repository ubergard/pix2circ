#include "image.h"
#include <fstream>
#include <iostream>

Image::Image(int name, int image){
  this->setname(name);
  this->setimage(image);
  this->set_modefiable_image(image);
}

void Image::print_stuff(){
  std::cout<<"Hello fokes" << " " << this->name << "\n";
}

//void Image::print_image() {
 // Print image
//for (int i = 0; i < len; i++) {
//  for (int j = 0; j < wid; j++) {
//    std::cout << image[j][i];
//  }
//  std::cout << '\n';
//}
