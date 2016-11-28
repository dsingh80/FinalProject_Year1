CC = g++ -std=c++11
CFLAGS = -g -c

BankRunner: main.cpp Bank.o CheckingAccount.o Account.o User.o Date.o Address.o
	$(CC) -g main.cpp Bank.o CheckingAccount.o Account.o User.o Date.o Address.o -o BankRunner
Bank.o: Bank.cpp Bank.h CheckingAccount.o
	$(CC) $(CFLAGS) Bank.cpp Bank.h
CheckingAccount.o: CheckingAccount.cpp CheckingAccount.h Account.o
	$(CC) $(CFLAGS) CheckingAccount.cpp CheckingAccount.h
Account.o: Account.cpp Account.h User.o
	$(CC) $(CFLAGS) Account.cpp Account.h
User.o: User.cpp User.h Date.o Address.o
	$(CC) $(CFLAGS) User.cpp User.h
Date.o: Date.cpp Date.h
	$(CC) $(CFLAGS) Date.cpp Date.h
Address.o: Address.cpp Address.h
	$(CC) $(CFLAGS) Address.cpp Address.h
valgrind: BankRunner
	valgrind --leak-check=full --track-origins=yes ./BankRunner
run: BankRunner
	./BankRunner
clean:
	rm *.gch
	rm *.o
	rm BankRunner
