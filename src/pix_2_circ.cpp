
#include <iostream>
#include <memory>
#include <fstream>
#include <iostream>

#include <Magick++.h>

// Can use image class with other features from imageconverter
//#include "image.h"
#include "imageconverter.h"
#include "charmap.h"

#define terminal_input


int main(int argc, char *argv[]) 
{
  // Start software
  std::cout << "\n"
          << "Starting 'Image 2 circle' converter" << "\n\n";


  int user_input = 1;
#if defined(terminal_input)
  user_input = std::stoi(argv[2]);
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
  std::string filename(argv[1]);

  std::string file_name_2 = filename;
  std::unique_ptr<imagecircles::ImageConverter> kfc(new imagecircles::ImageConverter);
  kfc->import_image(filename);
  kfc->print_image();
  kfc->print_dims();

  kfc->bogo_algorithm(user_input);
  kfc->print_circles();


  //std::cout<< '\n' << kfc->accuracy() << '\n';
  //kfc->approxinate_image(); 




  // ----------------- Output code (provided) -----------------
  // Code provided from assignment
  // Generate image output
  diskgraphics::DiskVector dv;
  dv.set_size(kfc->get_image_rows(), kfc->get_image_columns());
  dv.set_background(255);

  int amount_circles = kfc->get_amount_circles();
  for(int i = 0; i < amount_circles; i++)
  {
    diskgraphics::Disk dsk;
    kfc->get_circle_x_pos(i);

    dsk.x = kfc->get_circle_x_pos(i);
    dsk.y = kfc->get_circle_y_pos(i);
    dsk.r = kfc->get_circle_radius(i);
    dsk.colour = kfc->get_circle_color(i) * 255;
    dv.add_disk(dsk);

  }
  

  // Vector output
  std::ofstream vctostrm("fileoutput.vct");
  if(!vctostrm) return EXIT_FAILURE;
  vctostrm << dv;
  vctostrm.close();
  
  // Pixel conversion and output
  diskgraphics::Charmap cm(dv);
  //if(32 >= kfc->get_image_rows() || 32 >= kfc->get_image_columns() ) cm.out(&std::cout, true);  // if a small figure, also show on cout
  std::ofstream pixostrm("fileoutput.pxl");
  if(!pixostrm) return EXIT_FAILURE;
  pixostrm << cm;
  pixostrm.close();

  std::ifstream pixistrm("fileoutput.pxl");
  if(!pixistrm) return EXIT_FAILURE;
  diskgraphics::Charmap cn;
  pixistrm >> cn;
  if(32 >= cn.get_sizex()) cn.out(&std::cout, true);
  pixistrm.close();
  

  // Fixed filenames
  std::string infilename = "fileoutput.pxl";
  std::string outfilename = "fileoutput.png";
  if(argc > 1) infilename = argv[1];
  if(argc > 2) outfilename = argv[2];

  Magick::InitializeMagick(*argv);
  Magick::Image img(Magick::Geometry(cn.get_sizex(), cn.get_sizey()), "white"); 
  img.magick("PNG");
  img.monochrome();
  img.type(Magick::BilevelType);
  
  for(int x = 0; x < cn.get_sizex(); x++)
  {
    for(int y = 0; y < cn.get_sizey(); y++)
    {
      img.pixelColor(x, y, Magick::Color(cn.get_pixel(x, y) == 0? "black": "white"));
    }
  }
  img.quantize(2);
  img.write("fileoutput.png");
  


  return 0;
}
