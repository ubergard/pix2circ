#include <cassert>

#include "disk-vector.h"

using namespace diskgraphics;

void DiskVector::in(std::istream* source)
{
   int x, y;
   *source >> x >> y;  // read figure size in px
   this->set_size(x, y);
   
   unsigned bg_num;
   *source >> bg_num;  // read background colour
   this->set_background(bg_num);
   
   int N;  // read number of disks
   *source >> N;
   
   for(int i = 0; i < N; i++)
   {
      Disk d;
      *source >> d;  // read disk parameters
      this->add_disk(d);
   }
}
std::istream& operator>>(std::istream& is, DiskVector& v)
{
   v.in(&is);
   return is;
}
std::istream& operator>>(std::istream& is, Disk& d)
{
   is >> d.x >> d.y >> d.r;
   unsigned clr;
   is >> clr;
   d.colour = clr;
   return is;
}

void DiskVector::out(std::ostream* target) const
{
   *target << this->px_size_x << " " << this->px_size_y << "\n"
           << (unsigned)this->background << "\n\n" << this->disks.size() << "\n";

   for(auto i = this->disks.begin(); i != this->disks.end(); i++) *target << *i << "\n";
}
std::ostream& operator<<(std::ostream& os, const DiskVector& v)
{
   v.out(&os);
   return os;
}
std::ostream& operator<<(std::ostream& os, const Disk& d)
{
   os << d.x << "\t" << d.y << "\t" << d.r << "\t" << (unsigned)d.colour;
   return os;
}

unsigned char DiskVector::get_pixel(int x, int y) const
{
   assert(x >= 0);
   assert(y >= 0);
   assert(x < this->px_size_x);
   assert(y < this->px_size_y);

   char colour = this->background;
   for(auto i = this->disks.begin(); i != this->disks.end(); i++)
   {
      float dd = (x - i->x)*(x - i->x) + (y - i->y)*(y - i->y);
      if(i->r * i->r >= dd) colour = i->colour;
   }
   return colour;
}
