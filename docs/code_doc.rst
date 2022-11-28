Code documentation
=====================


Image
-------

Header file: ``image.h``   

.. py:function:: Image::Image(std::string file_name)
.. py:function:: void import_image(std::string file_name)

    Import image

        :brief: Imports the image based on the filename. It will use the "find dims()"
                to find and check the dimensions of the image, and then "image_make()" to set the pixels value to
                the img_array. |br| |br|

        :parameter file_name: A string, contains the file name


.. py:function:: void print_dims()
    
    Print dimensions

        :brief: Print the dimensions, if the dimension are not set, it will display an error
                message and return it.


.. py:function:: void print_image()

    Print image

        :brief: Prints the image and if the dimension are not set, it willl display an error message
                and return from it.



.. py:function:: int get_image_rows(){return dims[0]} 

    Get image rows

        :brief: Returns the images row (height) 


.. py:function:: int get_image_columns(){return dims[1]} 

    Get image columns

        :brief: Returns the image columns (width)


.. py:function:: void set_dims(int rows, int columns)
   
    Set dimensions

        :brief: Sets the dimensions manually. To be used for custom size of image and/or buypass
                the control check of consistency. |br| |br|

        :parameter rows: Holds the number of rows
        :parameter columns: Holds the number of columns


.. py:function:: void find dims(std::String file_name)

    Find dimensions

        :brief: Will find the first columns-length and ensure all other columns have the same length.
                Will abort if one column is inconsistent.
                Stores the dimensions if all checks out. |br| |br|

        :parameter file_name: A string


.. py:function:: void image_make(std::String file_name)

    Make image

        :brief: Imports the image based on the filename. It will check if the dimensions are set
                and if not, run "find_dims()" and then run through all the pixels in the image and
                store the values on a 2D array. This function and "set_dims()" can be used for custom
                size of an image. |br| |br|

        :parameter file_name: A string


.. py:function:: int check_pixel(int x, int y){return img_array[y-1][x-1]}

    Check pixels

        :brief: Returns the pixel/color value of a given position(input). |br| |br|

        :parameter x: Holds the column position of the pixel.
        :parameter y: Holds the row position of the pixel. |br| |br|

        :return: int, the colour value. 


.. py:function:: bool is_image_imported()

    Image imported (should be expanded!)

        :brief: Checks if all the required values are set for operations for an image. 
                Checks dimensions nad if atleast one pixel is given. |br| |br|

        :return: bool, values are set. 

Source code: :ref:`Related to Image`  


ImageConverter
----------------
Header file: ``imageconverter.h`` 

.. py:function:: ImageConverter::ImageConverter()
.. py:function:: void print_circles()

    Print circles (might get changed to return or save values to file!)

    :brief: Will iterate through the circle_list[vector] and print the values of the circles in
            the terminal.


.. py:function:: int get_amount_circles(){return circle_list.size()}

    Get amount of circles

    :brief: Returns the number of circles in the circle list.


.. py:function:: int get_circle_x_pos(int i){return circle_list[i].get_x_pos()}
    
    Get x position

    :brief: Returns the x positions from the circle list.


.. py:function:: int get_circle_y_pos(int i){return circle_list[i].get_y_pos()}

    Get y position

    :brief: Returns the y positions from the circle list.


.. py:function:: int get_circle_radius(int i){return circle_list[i].get_radius()}

    Get circle radius

    :brief: Returns the circle radius from the circle list.


.. py:function:: int get_circle_color(int i){return circle_list[i].get_color()}

    Get circle color 

    :brief: Returns the circle color from the circle list. 


.. py:function:: void bogo_algorithm(int wnated_circles)

    Bogo algorithm

        :brief: Bogo algorithm tries to make the worst case scenario for placing circles, 
                by randomly placing them, with a random size, only limited by the image diagonal. |br| |br|

        :parameter wanted_circles: Value which specifies the number of circles to be placed by algorithm.

Source code: :ref:`Related to Image`

Circle
--------

 Header file: ``imageconverter.h``
 
.. py:function:: Circle::Circle(int x, int y, int r, int c)
.. py:function:: int get_x_pos() const { return this->get_x_pos}
    
    Get x position

    :brief: An implenetation for returning the x-value of a circle.  |br| |br|

    :return: x position [int]


.. py:function:: int get_y_position() const { return this->get_y_pos}

    Get y position

    :brief: An implementation for returning the y-value of a circle. |br| |br|

    :return: y position[int]


.. py:function:: int get_radius() const{ return this ->radius}

    Get radius:

    :brief: An implementation for returning the radius of a circle. |br| |br|

    :return: radius [int]


.. py:function:: get_color() const {return this->color} 

    Get color

    :brief: An implementation for returning the color-value of a circle. |br| |br|

    :return: color[int]


.. py:function:: void set_x_pos(int x) { this->x_pos = x}

    Set x position

    :brief: An implementation for setting the x-value of a circle. |br| |br|

    :parameter x: Int, contains the x-position


.. py:function:: void set_y_pos{int y) { this->y_pos = y}

    Set y position

    :brief: An implementation for setting the y-value of a circle. |br| |br|

    :parameter y: Int, contains the y-position


.. py:function:: void set_radius(int r) {assert(r>=0) this->radius = r}

    Set radius

    :brief: An implementation for setting the radius of a circle. |br| |br|

    :parameter r: Int, contains the radius


.. py:function:: void set_color(int c) {this->color = c}

    Set color

    :brief: An implementation for setting the color of a circle. |br| |br|

    :parameter c: Int, contains the color. 

.. py:function:: bool check_circle() 

    Check circle (not finished)

    :brief: Function for checking the area, which the  circle is placed. 
            Will store relevant data. |br| |br|

    :return bool: Tells if the circle is placed on a black pixel.
    
 Source code: :ref:`Related to Circle`

.. note:: ``Circle`` is a nested class within imageconverter 



.. |br| raw:: html

   <br />