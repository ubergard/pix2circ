
#include <iostream>
#include <memory>
#include <fstream>
#include <iostream>

#include <Magick++.h>

// Can use image class without imageconverter and it's features
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
  user_input = std::stoi(argv[3]);
  if(user_input < 1)
  {
    std::cout << "PLEASE PROVIDE A VALID NUMBER!!!" << '\n'
              << "Number provided: " << user_input << "\n";
    abort();
  }
#else
  user_input = 10;
#endif
  std::cout << "Number inputed: " << user_input << '\n';

  std::string filename(argv[1]);
  std::unique_ptr<imagecircles::ImageConverter> infile(new imagecircles::ImageConverter);
  infile->import_image(filename);
  infile->print_image();
  infile->print_dims();

  int user_algo = std::stoi(argv[2]);
  if(user_algo == 1)
  {
    infile->bogo_algorithm(user_input);
  }
  else if(user_algo == 2)
  {
    infile->directed_random_place(user_input);
  }
  else
  {
    infile->bogo_feedback(user_input);
  }
  
  if(infile->get_amount_circles() < 50)
  {
    infile->print_circles();
  }

  std::cout << "Circles generated: " << infile->get_amount_circles() << '\n';

  //std::cout<< '\n' << infile->accuracy() << '\n';
  //infile->approxinate_image(); 


  // ----------------- Output code (provided) -----------------
  // Code provided from assignment to generate image output

  // Remove file prefix (.txt)
  filename.erase(filename.length()-4, filename.length()); 

  diskgraphics::DiskVector dv;
  dv.set_size(infile->get_image_columns(), infile->get_image_rows());
  dv.set_background(255);

  int amount_circles = infile->get_amount_circles();
  for(int i = 0; i < amount_circles; i++)
  {
    diskgraphics::Disk dsk;
    infile->get_circle_x_pos(i);

    dsk.y = infile->get_circle_x_pos(i);
    dsk.x = infile->get_circle_y_pos(i);
    dsk.r = infile->get_circle_radius(i);
    dsk.colour = infile->get_circle_color(i) * 255;
    dv.add_disk(dsk);

  }
  

  // Vector output
  std::string filedata = filename + ".vct";
  std::ofstream vctostrm(filedata);
  if(!vctostrm) return EXIT_FAILURE;
  vctostrm << dv;
  vctostrm.close();
  
  // Pixel conversion and output
  std::string infilename = filename + ".pxl";
  diskgraphics::Charmap cm(dv);
  //if(32 >= infile->get_image_rows() || 32 >= infile->get_image_columns() ) cm.out(&std::cout, true);  // if a small figure, also show on cout
  std::ofstream pixostrm(infilename);
  if(!pixostrm) return EXIT_FAILURE;
  pixostrm << cm;
  pixostrm.close();

  std::ifstream pixistrm(infilename);
  if(!pixistrm) return EXIT_FAILURE;
  diskgraphics::Charmap cn;
  pixistrm >> cn;
  //if(32 >= cn.get_sizex()) cn.out(&std::cout, true);
  pixistrm.close();
  

  std::string outfilename = filename + ".png";
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
  img.write(outfilename);
  


  return 0;
}
