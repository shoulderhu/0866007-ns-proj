CXX = g++
CFLAG = -g -Wall

all: px

%.o: %.cpp
	$(CXX) -c $<

px: px.o
	$(CXX) -o $@ $^ -lcurl

py: py.o
	$(CXX) -o $@ $^ -lcurl

clean:
	rm -rf px px.o py py.o