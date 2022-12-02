Improvements & Ideas
======================

**Implementation of parameters** |br|
1. stride of pixel for evaluation |br| 
When we evaluate each circle we do *not* need to evaluate every pixel. This can also be dependent on the
current status of the progress. When we initialize an algorithm we can assume that it is not neccessary  to
check every pixel to achieve a placement of increasing score. An alternative to the current solution could therefore
be changed to evaluate a portion of the selected circe then gradually increasing this portion. By some experimenation this 
could yield results much like what was already achieved. |br| 

2. number of no-improvements |br| 
The number of interations of no improvement will wary with the content of the image and the shape. It would be interesting
to give the user the ability to change this as a parameter. By some experimentation we could also define a standard analsys 
of the image to find some parameters to ensure that the algorithm running smoothly. |br|

3. increments of radius |br| 
Most of the same ideas from above apply to radius as well. Instad of the numbers you could implement different functions
for reducing the length. |br| 

**Imageconverter** |br| 
4. Backwards evaluation of circle relevance  |br| 
We can assume that the models already made will place circles that over time will be over written by other circles. 
This can be solved by simply iterate over the circles backwards. The strategy can be summed up to: 
Define an emtpy image of 0. Place the circles one by one as the same colors. Every time this places an circle and none 
of the pixels change any value in the image, we can remove this circle.  |br| 

5. Improve evaluation method |br|
The current implementation of the evaluation method reproduces the approximation of the image based on every circle
in the list every time.
Over the course of the iterations, this will result in performance of :math:`O`  ( **number of circles**  :math:`*` **number of placement attempts** ). 
This can be rewritten to *deep copy* the last approximation and placing only one circle. |br| 

6. Algorithms |br|
Based on the strcture we can freely add other Algorithms: |br|
One idea we had is to make an algorithm based on dividing the image into subimages,
this enables us to implement other algorithms like: |br| 

a: at a chosen condition split the image based on the longest axis into two sub images. This will result in :math:`2^k` subimages for *k* numbers of splitting. |br|
b: implement a procedure of placing circles, for example placing *n* numbers of circles filling the majority of the sub image |br| 
c: repeat a and b until we run out of circles to place or a specified size of subimage. |br|


.. |br| raw:: html

   <br />
