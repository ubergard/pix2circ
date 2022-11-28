TARGET = pix_2_circ

SRCS  = $(shell find ./src     -type f -name *.cpp)
HEADS = $(shell find ./include -type f -name *.h)
OBJS = $(SRCS:.cpp=.o)
DEPS = Makefile.depend

# Magick++
MAGICK_CXX = `Magick++-config --cppflags`
MAGICK_LIB = `Magick++-config --libs`


CXX = g++-11
INCLUDES = -I./include
CXXFLAGS = -std=c++2a -O2 -Wall $(INCLUDES) $(MAGICK_CXX)
LDFLAGS= -lm


all: $(TARGET)

$(TARGET): $(OBJS) $(HEADS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(MAGICK_LIB) 

run: all # 20 is added, since there must be circles provided
	@./$(TARGET) 20

.PHONY: depend clean
depend:
	$(CXX) $(INCLUDES) -MM $(SRCS) > $(DEPS)
	@sed -i -E "s/^(.+?).o: ([^ ]+?)\1/\2\1.o: \2\1/g" $(DEPS)

clean:
	$(RM) $(OBJS) $(TARGET)

-include $(DEPS)