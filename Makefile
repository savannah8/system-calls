
output:forks.o sum_intergers.o
	g++ forks.o -o a1q1
	g++ sum_intergers.o -o a1q3 -pthread

forks.o:forks.cpp
	g++ -c forks.cpp

sum_intergers.o:sum_intergers.cpp
	g++ -c sum_intergers.cpp

clean:
	rm *.o

