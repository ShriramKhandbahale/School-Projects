#include <stdio.h>
#include <stdlib.h>

#include "include/globals.h"
#include "include/menus.h"
#include "include/reservation.h"

int main()
{
HOME:
    clear();
    print_home_menu();
    printf("Enter your choice (0-3): ");
    char choice;
    scanf(" %c", &choice);

    switch (choice)
    {
    case '1':
        open_dashboard();
        break;
    case '2':
        print_reservation_menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case '1':
            book_ticket();
            break;
        case '2':
            //todo cancel
            break;
        default:
            break;
        }
        break;
    case '3':
        //todo inquiry
        break;
    case '0':
        exit(1);
        break;

    default:
        break;
    }
}