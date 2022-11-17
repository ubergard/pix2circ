#ifndef IMAGE_H
#define IMAGE_H

#include <string>
class Image
{
public:
    Image();
    Image(int image, std::string file_name);
    
    void print_dims(); 
    void print_image();
    void find_dims(std::string file_name);
    void image_make(std::string file_name);

    void setimage(int image_val) {
      this->image = image_val;
      this->image_modefiable = image_val;}
    //void set_modefiable_image(int image_mod_val) { this->image_modefiable = image_mod_val; }

    int getimage() const {return this->image;}
    int get_modefiable_image() {return this->image_modefiable;}

private:
  int image;
  int image_modefiable;
  int dims[2] = {0, 0} ;
  int* img_pointer;
};

#endif

