main: main.o menus.o globals.o account.o transactions.o inquiry.o passbook.o
	g++ build/object_files/main.o build/object_files/globals.o build/object_files/menus.o build/object_files/account.o build/object_files/transactions.o build/object_files/inquiry.o build/object_files/passbook.o -o build/main

main.o: 
	g++ -c src/main.cpp -o build/object_files/main.o

globals.o:
	g++ -c src/lib/globals.cpp -o build/object_files/globals.o

menus.o:
	g++ -c src/lib/menus.cpp -o build/object_files/menus.o

account.o:
	g++ -c src/lib/account.cpp -o build/object_files/account.o

transactions.o:
	g++ -c src/lib/transactions.cpp -o build/object_files/transactions.o

inquiry.o:
	g++ -c src/lib/inquiry.cpp -o build/object_files/inquiry.o

passbook.o:
	g++ -c src/lib/passbook.cpp -o build/object_files/passbook.o

clean:
	rm build/object_files/*; rm -rf build/data/accounts/*; echo 1000 > build/data/stats/user_count.txt;