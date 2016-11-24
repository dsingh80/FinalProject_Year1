CC = g++ -std=c++11
CFLAGS = -g -c

BankRunner: main.cpp Account.o User.o Date.o Address.o
	$(CC) -g main.cpp Account.o User.o Date.o Address.o -o BankRunner
Account.o: Account.cpp Account.h User.o
	$(CC) $(CFLAGS) Account.cpp Account.h
User.o: User.cpp User.h Date.o Address.o
	$(CC) $(CFLAGS) User.cpp User.h
Date.o: Date.cpp Date.h
	$(CC) $(CFLAGS) Date.cpp Date.h
Address.o: Address.cpp Address.h
	$(CC) $(CFLAGS) Address.cpp Address.h
run: BankRunner
	./BankRunner
clean:
	rm *.gch
	rm *.o
	rm BankRunner
