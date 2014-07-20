client: main_client.o class_client.o
	g++ main_client.o class_client.o -o client
main_client.o: main_client.cpp class_client.h
	g++ -c main_client.cpp
class_client.o: class_client.cpp class_client.h
	g++ -c class_client.cpp
