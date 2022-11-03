run: circ_pix_counter data.dat
	cat data.dat | ./circ_pix_counter

circ_pix_counter: circ_pix_counter.o circle.o
	g++ -o circ_pix_counter *.o

clean:
	rm -f *.o circ_pix_counter