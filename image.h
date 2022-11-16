#ifndef IMAGE_H
#define IMAGE_H

#include <string>
class Image
{
public:
    Image();
    Image(int name, int image);
    
    void print_stuff(); 
    void print_image();

    int setname(int name) const {return this -> name;}
    int setimage(int image) const {return this -> image;}
    int set_modefiable_image(int image) {return this -> image_modefiable;}

private:
  int name = 10;
  int image;
  int image_modefiable;
};

#endif

