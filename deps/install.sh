### Build

mkdir obj
mkdir lib

gcc -O2 -s -Wall -o obj/glad.o -c glad.c
ar r lib/libGlad.a obj/glad.o
ranlib lib/libGlad.a

#### Install

cp -a KHR /usr/local/include/KHR
cp linmath.h /usr/local/include/linmath.h
cp -a glad /usr/local/include/glad

cp lib/libGlad.a /usr/local/lib/libGlad.a

