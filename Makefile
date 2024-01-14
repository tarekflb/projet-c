all: build run

build:
	gcc main.c -o main -I raylib/include -L raylib/lib -lraylib  -lopengl32 -lgdi32 -lwinmm

run:
	./main.exe