
# Running C++ 11
CXX=g++-11 -std=c++2a
run: circ_2_pix
	./circ_2_pix 20

circ_2_pix: circ_2_pix.o image.o imageconverter.o 
	$(CXX) -O2 -o circ_2_pix *.o

clean:
	rm -f *.o circ_2_pix
