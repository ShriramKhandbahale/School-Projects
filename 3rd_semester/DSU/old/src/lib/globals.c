#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "../include/globals.h"

int clear()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    return 0;
}

void print_format_line()
{
    printf("------------------------------");
}

void processing_animation()
{

    clear();

    printf("\e[?25l");

    printf("processing\n");
    usleep(250000);
    clear();

    printf("processing..\n");
    usleep(250000);
    clear();

    printf("processing...\n");
    usleep(250000);
    clear();

    printf("processing\n");
    usleep(250000);
    clear();

    printf("processing.\n");
    usleep(250000);
    clear();

    printf("processing..\n");
    usleep(250000);
    clear();

    printf("processing...\n\n");
    usleep(250000);

    printf("\e[?25h");
    clear();
}