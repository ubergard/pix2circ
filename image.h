#ifndef IMAGE_H
#define IMAGE_H

#include <string>
class Image
{
public:
    Image();
    Image(std::string file_name);
    
    void print_dims(); 
    void print_image();
    void find_dims(std::string file_name);
    void image_make(std::string file_name);

    void setimage(int image_val) {
      this->image = image_val;
      this->image_modefiable = image_val;}
    // make this able to use the printed iamge in getimage

    int getimage() const {return this->image;}
    int get_modefiable_image() {return this->image_modefiable;}

private:
  int image;
  int image_modefiable;
  int dims[2] = {0, 0} ;
  int* img_pointer;
};

#endif

