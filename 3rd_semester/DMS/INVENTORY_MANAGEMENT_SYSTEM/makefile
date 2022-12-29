mysql_config_cflags = -I/usr/include/mysql
mysql_config_libs=-L/usr/lib/x86_64-linux-gnu -lmysqlclient -lzstd -lssl -lcrypto -lresolv -lm

CC=gcc
CFLAGS=$(mysql_config_cflags) $(mysql_config_libs)

main: src/main.c
	$(CC) src/main.c $(CFLAGS) -o dist/main
