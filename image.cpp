
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>

#include "image.h"


void Image::import_image(std::string file_name)
{
  find_dims(file_name);
  image_make(file_name);
}

void Image::find_dims(std::string file_name) 
{
  int rows = 0;
  int columns = 0;
  
  std::fstream myFile;
  myFile.open(file_name, std::ios::in);
  if (myFile.is_open()) 
  {
    std::string line;
    std::getline(myFile, line);
    columns = line.length();
    rows++;  
    while (std::getline(myFile, line))
    {
      rows++;
      if (line.length() != columns) 
      {
        std::cout << "\n\n" 
          << "AT LEAST ONE ROW HAVE LESS ENTRIES THAN OTHER LINES" << '\n'
          << "Row: " << rows << " is missing entries\n"
          << "The difference is: " << columns - line.length()<< "\n\n\n";
        abort();
      }
    }
    myFile.close();
}
  dims[0] = rows;
  dims[1] = columns;
}

void Image::image_make(std::string file_name)
{
  if(!dims[1] || !dims[0])
  {
    find_dims(file_name);
  }

  std::cout << '\n' << "Importing file: " << file_name << '\n';
  image_name = file_name;
  std::fstream image_file;
  image_file.open(file_name, std::ios::in);
  std::string line;
  if (!image_file.is_open()) {abort();}

  for (int m = 0; m < dims[0]; m++) 
  {
    std::getline(image_file, line);
    for (int n = 0; n < dims[1]; n++) 
    {
      if(line[n] < 48)
      {
        std::cout << "\n"
          << "Illegal character: '" << line[n] << "'" << "\n"
          << "Position " << n << "," << m << "\n\n";
        abort();
      }
      else
      {
        img_array[m][n] = line[n] - 48;
      }
    }
  }
}

void Image::set_dims(int rows, int columns)
{
  dims[0] = rows;
  dims[1] = columns;
}

void Image::print_dims(){
  if(!dims[1] || !dims[0])
  {
    std::cout << "Could not print dimensions!" << '\n';
    return;
  }

  std::cout<<"\nThe size of the image is (x,y): "
    << '('<<dims[1]<<','<<dims[0]<<')'
    << "\n\n";
}

void Image::print_image(){
  if(!is_image_imported())
  {
    std::cout << "Could not print image!" << '\n';
    return;
  }


  int m = dims[0];
  int n = dims[1];

  for (int m = 0; m < dims[0]; m++) 
  {
    for (int n = 0; n < dims[1]; n++) 
    {
      std::cout << img_array[m][n];
    }
      std::cout << '\n';
  }
}


bool Image::is_image_imported()
{
  if(!dims[1] || !dims[0] || !img_array[0][0])
  {
    std::cout << "Please import the image first!!!" << '\n';
    return false;
  }
  else{
    return true;
  }
}

double Image::accuracy(){
  int tp = 0;
  int tn = 0;
  int fp = 0;
  int fn = 0;
  evaluation_of_pixels(tp, tn, fp, fn);

}

void Image::evaluation_of_pixels(int &tp, int &tn, int &fp, int &fn)
{
// We asume that black is is forgraound and call it posetive
// The opesit goes for white, backgorund is white and therfor negative 
int m = dims[0];
int n = dims[1];
tp = 0;
tn = 0;
fp = 0;
fn = 0;

for (int y = 0; y < m; y++) {
    for (int x = 0; x < n; x++)
      if (img_array[y][x] == 1) {
        if(img_array[y][x] == img_array[y][x]) // change img_array to img_pred
        {
          tp++;
        } else {
          fn++;
        }
      } else {
       if(img_array[y][x] == img_array[y][x]){
          tn++;
        } else {
          fp ++;
        }
      }
  }
}


