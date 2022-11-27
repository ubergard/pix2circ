
# Running C++ 11
CXX=g++-11 -std=c++2a
run: pix_2_circ
	./pix_2_circ 20

pix_2_circ: pix_2_circ.o image.o imageconverter.o 
	$(CXX) -O2 -o pix_2_circ *.o

clean:
	rm -f *.o pix_2_circ
