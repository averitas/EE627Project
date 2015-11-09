mainuserdata.exe: main.o userdata.o
	g++ main.o userdata.o -o mainuserdata.exe

main.o: main.cc
	g++ -c main.cc

userdata.o: userdata.cc
	g++ -c userdata.cc

userdata.cc: userdata.h
	touch userdata.cc

main.cc: userdata.h
	touch main.cc
