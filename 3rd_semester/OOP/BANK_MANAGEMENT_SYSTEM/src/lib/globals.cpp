#include "../include/globals.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdlib.h>
#include <string>

void print_format_line()
{
    std::cout << "------------------------------";
}

int clear()
{
#ifdef _win32
    system("cls");
#else
    system("clear");
#endif
    return 0;
}

int open_file(int input_account_number)
{
    char buf[32];

#ifdef _win32
    sprintf(buf, "start data/accounts/%d/info.txt", input_account_number);
#else
    sprintf(buf, "nano data/accounts/%d/info.txt", input_account_number);
#endif
    system(buf);
    return 0;
}

int delete_file(int input_account_number)
{
    char buf[32];

#ifdef _win32
    sprintf(buf, "rmdir /Q /S data/accounts/%d/info.txt", input_account_number);
#else
    sprintf(buf, "rm -rf data/accounts/%d/info.txt", input_account_number);
#endif
    system(buf);
    return 0;
}

void processing_animation()
{

    clear();

    std::cout << "\e[?25l";

    std::cout << "processing\n";
    usleep(250000);
    clear();
    ;

    printf("processing..\n");
    usleep(250000);
    clear();
    ;

    printf("processing...\n");
    usleep(250000);
    clear();
    ;

    printf("processing\n");
    usleep(250000);
    clear();
    ;

    printf("processing.\n");
    usleep(250000);
    clear();
    ;

    printf("processing..\n");
    usleep(250000);
    clear();
    ;

    printf("processing...\n\n");
    usleep(250000);

    printf("\e[?25h");
    clear();
}