# Pix2Circ - Tutorial for dummies 
It will create an approximation of a picture/file by a set of superimposed or imposed circles.
There are multiple algorithms implemented and some benchmark tools.


**Steps to run our code:**

Change directory to our pix2circ directory and build it by using *make*:

```
cd pix2circ/
make 
``` 
We have 3 working algorithms you can choose from. We have assigned numbers to chose which algorithm you want to use. 
We have prepared two binary images, the batman logo and the kfc logo, converted them into 0's and 1's and exported them 
to a .txt file. Namely batman.txt and kfc.txt, the batman logo is a bit small, the results are shown better with the 
kfc image. 

Bogo place            :1 
Directed random place :2
Bogo feedback         :3 

The different algorithms work in different ways, for Bogo place and the *placeholder* name algorithms, 
you have to assign how many circles you want to run with. For the modified bogo place, 
you assign the accuracy that you want it to run with, with a number between 1-99, the higher the number, 
the better accuracy you will get. After you have run the program, it will generate a .png image in the pix2circ folder.  


**Example for running Bogo place:**

```
./pix2circ kfc.txt 1 500
```
This will run the *bogo place* algorithm, on the kfc image, with 500 circles. 


**Example for running Directed random place:**

```
./pix2circ batman.txt 2 1000
```
This will run the *directed random place* algorithm, on the batman logo, with 1000 circles.


**Example for running Bogo feedback:** 

```
./pix2circ kfc.txt 3 99
```
This will run the *bogo feedback* algorithm, on the kfc image, with 99% accuracy. 


**Documentation** 
The work we have done is documented using Sphinx, change directory to the *docs* directory and make the documentation,
followed by changing directory to *html* via the *_build* directory and open the index.html file. 

```
cd docs/ 
make html
cd _build/html
``` 
