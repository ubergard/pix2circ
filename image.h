#ifndef IMAGE_H
#define IMAGE_H

#include <string>
class Image
{
public:
    Image();
    Image(int name, int image, std::string file_name);
    
    void print_stuff(); 
    void print_image();
    void find_dims(std::string file_name);

    void setname(int name_val) { this->name = name_val; }
    void setimage(int image_val) {
      this->image = image_val;
      this->image_modefiable = image_val;}
    //void set_modefiable_image(int image_mod_val) { this->image_modefiable = image_mod_val; }

    int getname() const {return this->name;}
    int getimage() const {return this->image;}
    int get_modefiable_image() {return this->image_modefiable;}

private:
  int name;
  int image;
  int image_modefiable;
  int dims[2] = {0, 0} ;
};

#endif

