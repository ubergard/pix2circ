
#ifndef IMAGECONVERTER_H
#define IMAGECONVERTER_H

#include <cassert>

#include "image.h"

namespace imagecircles
{
    class ImageConverter: public Image
    {
    public:
        // ------ Features ------
        /** 
        * Print circles (Might get changed to return or save values to file!)
        *
        * @brief Will iterate through the circle_list[vector] and print the values of the circles in
        *        the terminal.
        */
        void print_circles();

        /**
        * Get amount of circles
        *
        * @brief Returns the number of circles in the circle list.
        */ 
        int get_amount_circles(){return c_circles;}

        /**
        * Get the x-position of a chosen circle
        *
        * @brief Returns the x-position of one circle from the list.
        *
        * @return x posistion[int]
        */ 
        int get_circle_x_pos(int i){return circle_list[i].get_x_pos();}

        /**
        * Get the y-position of a chosen circle
        *
        * @brief Returns the y-position of one circle from the list.
        *
        * @return y posistion[int]
        */ 
        int get_circle_y_pos(int i){return circle_list[i].get_y_pos();}

        /**
        * Get the radius of a chosen circle
        *
        * @brief Returns the radius of one circle from the list.
        *
        * @return r radius[int]
        */
        int get_circle_radius(int i){return circle_list[i].get_radius();}

        /**
        * Gets the color of a chosen circle
        *
        * @brief Returns the color of one circle from the list.
        *
        * @return c color[int]
        */ 
        int get_circle_color(int i){return circle_list[i].get_color();}

        /**
        * Print approximate image
        *
        * @brief Prints the approximated image and if image is empty, it will display an error 
        *        message and return from it.
        */ 
        void print_approx_image();


        void approximate_image();

        double accuracy();
        double precision();
        double recall();
        double f1_score();
        double matthews_correlation_coefficient();

        void evaluation_of_pixels(int &tp, int &tn, int &fp, int &fn);


        // ------ Algorithms ------
        /** 
        * Bogo algorithm
        *
        * @brief Bogo algorithm tries to make the worst case scenario for placing circles, 
        *        by randomly placing them, with a random size, only limited by the image diagonal.
        *
        * @param wanted_circles Value which speciefies the number of circles to be placed by algorithm
        */
        void bogo_algorithm(int wanted_circles);

        /** 
        * Bogo algorithm modded
        *
        * @brief This algorithm is based on bogo algorithm, but checks if accuracy increases, and if it does, 
        *        it will keep the circle. It many circles is needed, it will scale the circles down.        
        *
        * @param accuracy_wanted Value which speciefies the accuracy threshold
        */
        void bogo_feedback(int accuracy_wanted);

        void directed_random_place(int wanted_circles);
    

        class Circle
        {
        public:
            Circle() {}
            Circle(int x, int y, int r, int c);


            // ------ Circles, fetch values ------
            /** 
            * Get x position
            *
            * @brief An impletation for returning the x-value of a circle.
            * 
            * @return x posistion[int]
            */
            int get_x_pos() const { return this->x_pos; }

            /**
            * Get y position
            *
            * @brief An impletation for returning the y-value of a circle.
            * 
            * @return y posistion[int]
            */
            int get_y_pos() const { return this->y_pos; }

            /**
            * Get radius
            *
            * @brief An impletation for returning the radius of a circle.
            * 
            * @return radius[int]
            */
            int get_radius() const { return this->radius; }

            /** 
            * Get color
            *
            * @brief An impletation for returning the color-value of a circle.
            * 
            * @return color[int]
            */
            int get_color() const { return this->color; }


            // ------ Circles, set values ------
            /** 
            * Set x position
            *
            * @brief An impletation for setting the x-value of a circle.
            * 
            * @param x Int, contains the x-postion
            */
            void set_x_pos(int x) { this->x_pos = x; }

            /** 
            * Set y position
            *
            * @brief An impletation for setting the y-value of a circle.
            * 
            * @param y Int, contains the y-postion
            */
            void set_y_pos(int y) { this->y_pos = y; }

            /** 
            * Set radius
            *
            * @brief An impletation for setting the radius of a circle.
            * 
            * @param r Int, contains the radius
            */
            void set_radius(int r) { assert(r >= 0); this->radius = r; }

            /** 
            * Set color
            *
            * @brief An impletation for setting the color of a circle.
            * 
            * @param c Int, contains the color
            */
            void set_color(int c) { this->color = c; }

            /**
            * Check circle (NOT COMPLETE)
            *
            * @brief Function too check the area, which the circle is placed.
            *        Will store relevant data.
            * 
            * @return bool Tells if the circle is placed on a black pixel.
            */
            bool check_circle();

        private:
            int x_pos;
            int y_pos;
            int radius;
            int color;

            int size = 0;

        };


    private:
        int n_circles = 100;
        int c_circles = 0;
        int run_counter = 0;

        std::vector<std::vector<int>> approx_image;
        std::vector<Circle> circle_list;
    };
}

#endif
