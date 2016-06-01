CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++11

OBJS = Asteroids/Game.o	Asteroids/main.o

LIBS = -lGL -lGLEW -lSDL2 -lm

TARGET =	Asteroids/main

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
