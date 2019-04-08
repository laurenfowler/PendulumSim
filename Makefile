CC = g++
CFLAGS = -g
GLUT = -lGL -lGLU -lglut -lGLEW -lm libSOIL.a
OBJS = display.o physics.o call_step.o draw_objects.o keyboard.o tex.o camera.o lighting.o
HEADERS = includes.h globals.h prototypes.h SOIL.h
FLAGS = -DTEXTURE

run: main.o $(OBJS) $(HEADERS)
	$(CC) $(CLFAGS) main.o $(OBJS) $(GLUT) 

main.o : main.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c main.cpp

display.o: display.cpp 	$(HEADERS)
	$(CC) $(CFLAGS) -c display.cpp

physics.o: physics.c $(HEADERS)
	$(CC) $(CFLAGS) -c physics.c 

call_step.o: call_step.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c call_step.cpp

draw_objects.o: draw_objects.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c draw_objects.cpp $(FLAGS)

keyboard.o: keyboard.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c keyboard.cpp

tex.o: tex.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c tex.cpp

camera.o : camera.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c camera.cpp

lighting.o: lighting.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c lighting.cpp
clean:
	rm *.o
	rm a.out
