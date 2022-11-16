#include "image.h"
#include <fstream>
#include <iostream>
#include <string>

Image::Image(int name, int image, std::string file_name){
  this->setname(name);
  this->setimage(image);
  find_dims(file_name);
}

void Image::find_dims(std::string file_name) {
  int rows = 0;
  int columns = 0;
  std::string file = file_name;
  
  std::fstream myFile;
  myFile.open(file, std::ios::in); // read //data2.dat
  if (myFile.is_open()) {
    std::string line;
    std::getline(myFile, line);
    columns = line.length();
    rows++;  
    while (std::getline(myFile, line)) {
      if (line.length() != columns) {
        std::cout<<"\n\n\nOh no!!"
          << ' ' << rows
          << ' ' << columns
          << ' ' << line.length() << '\n';
      }
      rows++;
    }
    myFile.close();
}
  std::cout << rows << ' ' << columns << '\n';
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
