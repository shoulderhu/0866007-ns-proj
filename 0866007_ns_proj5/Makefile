CXX = g++
CFLAG = -g -Wall -std=c++11

all: px

%.o: %.cpp
	$(CXX) -c $< $(CFLAG)

px: px.o
	$(CXX) -o $@ $^ -lcurl
	sudo cp $@ /usr/local/bin/

py: py.o
	$(CXX) -o $@ $^
	sudo cp $@ /var/Y/

clean:
	rm -rf px px.o py py.o

.PHONY: all clean