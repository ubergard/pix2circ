Code documentation
=====================

Circle
--------

 Header file: ``circle.h``

 Source code: :ref:`Related to Circle`
 
.. py:function:: Circle::Circle(int x, int y, int r)

    :brief:  |br| |br|

    :parameters: 

Image
-------

Header file: ``image.h`` 

Source code: :ref:`Related to Image`    

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


ImageConverter
----------------
Header file: ``imageconverter.h`` 

Source code: :ref:`Related to Image`

.. py:function:: ImageConverter::ImageConverter()
.. py:function:: void print_circles()

    Print circles (might get changed to return or save values to file!)

    :brief: Will iterate through the circle_list[vector] and print the values of the circles in
            the terminal.


.. py:function:: void bogo_algorithm(int wnated_circles)

    Bogo algorithm

        :brief: Bogo algorithm tries to make the worst case scenari






.. note:: evt noe her 





.. |br| raw:: html

   <br />