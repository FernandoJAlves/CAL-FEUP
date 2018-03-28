all:
	g++ *.cpp -Wall -I cute_lib -std=c++11 -o run

prof:
	g++ -Wall -O3 -I cute_lib -std=c++11 -no-pie -pg *.cpp -o run

debug:
	g++ -g *.cpp -Wall -I cute_lib -std=c++11 -o run

clean:
	rm run
