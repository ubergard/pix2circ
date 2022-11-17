#include "image.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>

Image::Image(int image, std::string file_name){
  this->setimage(image);
  image_make(file_name);
}

void Image::find_dims(std::string file_name) {
  int rows = 0;
  int columns = 0;
  //std::string file = file_name;
  
  std::fstream myFile;
  myFile.open(file_name, std::ios::in); // read //data2.dat
  if (myFile.is_open()) {
    std::string line;
    std::getline(myFile, line);
    columns = line.length();
    rows++;  
    while (std::getline(myFile, line)) {
      rows++;
      if (line.length() != columns) {
        std::cout << "\n\n" 
          << "AT LEAST ONE ROW HAVE LESS ENTRIES THAN OTHER LINES" << '\n'
          << "Row: " << rows << " is missing entries\n"
          << "The difference is: " << columns - line.length()
          << "\n\n\n";
        abort();
      }
    }
    myFile.close();
}
  this->dims[0] = rows;
  this->dims[1] = columns;
}

void Image::image_make(std::string file_name){
  std::cout << '\n' << file_name << '\n';
  find_dims(file_name);
  int pixels[this->dims[0]][this->dims[1]];

  std::fstream image_file;
  image_file.open(file_name, std::ios::in);
  std::string line;
  if (!image_file.is_open()) {abort();}

  for (int y = 0; y < this->dims[0]; y++) {
    std::getline(image_file, line);
    for (int x = 0; x < this->dims[1]; x++) {
      int num = 0;
      pixels[x][y] = line[x];
    }
  }
  // Print image
  for (int m = 0; m < this->dims[0]; m++) {
    for (int n = 0; n < this->dims[1]; n++) {
      std::cout << pixels[m][n] - 48;
    }
    std::cout << '\n';
  }
  
}

void Image::print_dims(){
  std::cout<<"\nDimentions of the image is: "
    << '('<<dims[0]<<','<<dims[1]<<')'
    << '\n';
}

//void Image::print_image() {
 // Print image
//for (int i = 0; i < len; i++) {
//  for (int j = 0; j < wid; j++) {
//    std::cout << image[j][i];
//  }
//  std::cout << '\n';
//}
