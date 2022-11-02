
// Calculating area of circle based on txt file
#include <iostream>
//#include<cmath>

#define PI 3.1415

int main () {
    int radius;

    std::cin >> radius;  // input number of spheres
    std::cout << radius << '\n';

    //int area = PI*pow(radius,2);
    int area = PI*radius*radius;
    std::cout << area << '\n';

    return 0;
}