CXX = g++
CFLAG = -g -Wall

all: px

%.o: %.cpp
	$(CXX) -c $<

px: px.o
	$(CXX) -o $@ $^ -lcurl
	sudo cp $@ /usr/local/bin/

py: py.o
	$(CXX) -o $@ $^
	sudo cp $@ /usr/local/bin/

clean:
	rm -rf px px.o py py.o