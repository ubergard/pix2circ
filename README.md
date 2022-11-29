# Pix2Circ - Tutorial for dummies 
It will create an approximation of a picture/file by a set of superimposed or imposed circles. <br />
There are multiple algorithms implemented and some benchmark tools.<br />


**Steps to run our code:** <br />

Change directory to our pix2circ directory and build it by using *make*:

```
cd pix2circ/
make 
``` 
We have 3 working algorithms you can choose from. We have assigned numbers to chose which algorithm you want to use. We have prepared two binary images, the batman logo and the kfc logo, converted them into 0's and 1's and exported them to a .txt file. Namely batman.txt and kfc.txt, the batman logo is a bit small, the results are shown better with the kfc image. <br />

Bogo place            :1 <br />
Directed random place :2 <br />
Bogo feedback         :3 <br />

The different algorithms work in different ways, for Bogo place and the *placeholder* name algorithms, you have to assign how many circles you want to run with. For the modified bogo place, you assign the accuracy that you want it to run with, with a number between 1-99, the higher the number, the better accuracy you will get. After you have run the program, it will generate a .png image in the pix2circ folder.  <br />

**Example for running Bogo place:** <br />

```
./pix2circ 1 kfc.txt 500
```
This will run the *bogo place* algorithm, on the kfc image, with 500 circles. <br />

**Example for running Directed random place:** <br />

```
./pix2circ 2 batman.txt 1000
```
This will run the *directed random place* algorithm, on the batman logo, with 1000 circles. <br />

**Example for running Bogo feedback:** 

```
./pix2circ 3 kfc.txt 99
```
This will run the *bogo feedback* algorithm, on the kfc image, with 99% accuracy. <br />

**Documentation** 
To view the documentation regarding our work, change directory to the *docs* directory and make the documentation,
followed by changing directory to *html* via the *_build* directory and open the index.html file. 

```
cd docs/ 
make html
cd _build/html
``` 


