#include <stdio.h>

#include "../include/globals.h"

void print_home_menu()
{
    print_format_line();
    printf("[1] View Dashboard\n");
    printf("[2] Reservation\n");
    printf("[3] Inquiry\n");
    printf("[0] Exit\n");
    print_format_line();
}

void open_dashboard()
{
    //todo dashboard
}

void print_reservation_menu()
{
    print_format_line();
    printf("\n[1] Book Ticket\n");
    printf("[2] Cancel Reservation\n");
    print_format_line();
}
