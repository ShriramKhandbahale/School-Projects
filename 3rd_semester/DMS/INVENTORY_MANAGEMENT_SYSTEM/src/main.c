#include <stdlib.h>
#include <stdio.h>

// MYSQL API
#include <mysql/mysql.h> // apt install libmysqlclient-dev

// connection details
static char *host = "127.0.0.1";
static char *user = "root";
static char *password = "";
static char *dbname = "demo";
unsigned int port = 3306;
static char *unix_socket = NULL; // connection type
unsigned int flag = 0;

int main()
{
    MYSQL *connection;
    MYSQL_RES *result;
    MYSQL_ROW column;
    connection = mysql_init(NULL);

    if (!mysql_real_connect(connection, host, user, password, dbname, port, unix_socket, flag))
    {
        fprintf(stderr, "\nError: %s [%d]\n", mysql_error(connection), mysql_errno(connection));
        exit(1);
    }

    printf("connected\n");

    // mysql_query(connection, "SELECT * FROM users");
    // result = mysql_store_result(connection); // if the query returns a value store it inside a result pointer
    // while (column = mysql_fetch_row(result))
    // {
    //     printf("%s\t\t%s\t\t%s\t\t%s\n", column[0], column[1], column[2], column[3]);
    // }
    // mysql_free_result(result);

    // if (mysql_query(connection, "insert into users values (%d, 'HELLO WORLD', 'HELLO WORLD' , 'IN');"))
    // {
    //     fprintf(stderr, "\nError: %s [%d]\n", mysql_error(connection), mysql_errno(connection));
    // }

    // mysql_close(connection);
    // return EXIT_SUCCESS;
}