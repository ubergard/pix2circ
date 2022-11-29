Results
=======

To test the algorithms, a binary image of the KFC logo was converted to 1's and 0's. |br|

.. image:: images/kfc_converter.png


**Bogo place** |br|
As this algorithm is a random -worst case algorithm, the test results was as expected, totally random in the range from
all white to all black. As shown, run with both 20 circles and 1000, the results makes no sense in comparison with the original picture.
In turn, this makes alot of sense as this is an *all* random algorithm. 

.. image:: images/kfc_test_bogo_group.png


**Modified bogo place - Circle version** |br| 
Even though the results shown is not subpar, the performance is. 
If this version is run with for example 1500 circles, it might not even finish running, as bogo place is still 
randomly placed. As shown in the examples, the runtime of 1000 circles is still under 1 second, but 1500 circles was aborted
after 3 minutes and 25 seconds. 

.. image:: images/kfc_test_modbogo_group.png



**Modified bogo place - Accuracy version** |br|
The second version of the modded bogo place. This algorithm place circles at random until the desired accuracy is hit. 
100 accuracy is probably achieveable, but as it is a random placing algorithm, it might have to run for
a long period of time to achieve this. 

.. image:: images/kfc_test_mod_acc_group.png


*Placeholder name* gjorde det sånn her bra |br|
resultat resultat |br|












.. |br| raw:: html

   <br />