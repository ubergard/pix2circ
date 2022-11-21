
# Running C++ 11
CXX=g++-11 -std=c++2a
run: circ_pix_counter
	./circ_pix_counter 20

circ_pix_counter: circ_pix_counter.o image.o imageconverter.o 
	$(CXX) -O2 -o circ_pix_counter *.o

clean:
	rm -f *.o circ_pix_counter
