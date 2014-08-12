server: main_server.o class_server.o class_person.o
	g++ main_server.o class_server.o class_person.o -o server
main_server.o: main_server.cpp class_server.h class_person.h
	g++ -c main_server.cpp
class_server.o: class_server.cpp class_server.h
	g++ -c class_server.cpp
class_person.o: class_person.cpp class_person.h
	g++ -c class_person.cpp
