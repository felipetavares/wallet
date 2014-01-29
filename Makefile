STD=c++11

all: hook.o wallet.o hook.deposit.single.o hook.deposit.daily.o
	g++ -std=$(STD) build/*.o -o money
hook.o: hook.cpp hook.h
	g++ -std=$(STD) hook.cpp -o build/hook.o -c
wallet.o: wallet.cpp wallet.h
	g++ -std=$(STD) wallet.cpp -o build/wallet.o -c
hook.deposit.single.o: hook/deposit.single.cpp hook/deposit.single.h
	g++ -std=$(STD) hook/deposit.single.cpp -o build/deposit.single.o -c
hook.deposit.daily.o: hook/deposit.daily.cpp hook/deposit.daily.h
	g++ -std=$(STD) hook/deposit.daily.cpp -o build/deposit.daily.o -c
