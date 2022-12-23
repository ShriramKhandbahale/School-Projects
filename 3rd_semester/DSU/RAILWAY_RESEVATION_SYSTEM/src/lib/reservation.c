#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "../include/globals.h"
#include "../include/reservation.h"
#include "../include/getters.h"
#include "../include/menus.h"

typedef struct node
{
    char passenger_name[20];
    char passenger_gender[6];
    int passenger_age;
    struct node *next;
} node;

struct node *start = NULL;

void book_ticket()
{

    printf("Select Source and Destination Place\n");

    printf("From: ");
    char arrival[20];
    scanf(" %s", arrival);

    printf("To: ");
    char destination[20];
    scanf(" %s", destination);

    printf("\nDeparture Date (DD/MM/YYYY): ");
    char departure_date[10];
    scanf(" %s", departure_date);

    printf("\nEnter number of passengers/members: ");
    int passenger_no;
    scanf("%d", &passenger_no);

    printf("\n");
    print_format_line();
    printf("\n\nTrains from %s to %s on %s: \n\n", arrival, destination, departure_date);
    open_dashboard();

    printf("\nEnter Train No: ");
    int train_number;
    scanf("%d", &train_number);

    clear();
    print_train(train_number);
    printf("\n");

    print_format_line();
    printf("\n[1] Anubhuti Class\n");
    printf("[2] AC First Class (1A)\n");
    printf("[3] AC 2 Tier (2A)\n");
    printf("[4] AC 3 Tier (3A)\n");
    printf("[5] AC Chair car (CC)\n");
    printf("[6] Sleeper (SL)\n");
    printf("[7] First Class (FC)\n");
    print_format_line();

    printf("\nSelect Class (1-7): ");
    int class_choice;
    scanf("%d", &class_choice);

    clear();
    print_train(train_number);
    printf("\n");

    print_format_line();
    printf("\n[1] General\n");
    printf("[2] Ladies\n");
    printf("[3] Tatkal\n");
    printf("[4] Lower Berth/Sr.Citizen\n");
    printf("[5] Premium Tatkal\n");
    printf("[6] Divyaang\n");
    print_format_line();

    printf("\nSelect Quota (1-6): ");
    int quota_choice;
    scanf("%d", &quota_choice);

    processing_animation();

    printf("Proceed [Y/n] : ");
    char confirm_choice;
    scanf(" %c", &confirm_choice);
    confirm_choice = toupper(confirm_choice);

    if (confirm_choice != 'Y')
    {
        exit(1);
    }

    passenger_details(passenger_no);

    processing_animation();

    printf("Ticket Confirmed\n\n");

    int ticket_number = get_ticket_no();
    printf("your ticket no is: %d\n", ticket_number);

    printf("\nAllocated Seats: ");
    int seat_numbers[passenger_no];
    get_seat_count(seat_numbers, passenger_no);
    for (int i = 0; i < passenger_no; i++)
    {
        printf("S-%d  ", seat_numbers[i]);
    }
    printf("\n");

    write_ticket(ticket_number, train_number, seat_numbers, passenger_no, arrival, destination, class_choice, quota_choice);
}

void passenger_details(int passenger_no)
{
    char passenger_name[20];
    char passenger_gender[6];
    int passenger_age;

    for (int i = 1; i <= passenger_no; i++)
    {
        clear();
        printf("Passenger %d Details:\n\n", i);

        printf("  Name: ");
        scanf(" %s", passenger_name);

        printf("  Gender: ");
        scanf(" %s", passenger_gender);

        printf("  Age: ");
        scanf("%d", &passenger_age);

        add_to_list(passenger_name, passenger_gender, passenger_age);
    }
}

void add_to_list(char passenger_name[20], char passenger_gender[6], int passenger_age)
{
    node *temp = NULL, *ptr;

    temp = (node *)malloc(sizeof(node) + (20 + 6) * sizeof(char));
    if (temp == NULL)
    {
        fprintf(stderr, "Error allocating memory\n");
        exit(EXIT_FAILURE);
    }

    strcpy(temp->passenger_name, passenger_name);
    strcpy(temp->passenger_gender, passenger_gender);
    temp->passenger_age = passenger_age;

    temp->next = NULL;

    if (start == NULL)
        start = temp;
    else
    {
        ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

void print_list(int passenger_no)
{
    node *ptr = start;

    for (int i = 1; i <= passenger_no; i++)
    {
        printf("Passenger %d Details:\n", i);

        printf("  Name: ");
        puts(ptr->passenger_name);

        printf("  Gender: ");
        puts(ptr->passenger_gender);

        printf("  Age: %d", ptr->passenger_age);
        printf("\n\n");
        ptr = ptr->next;
    }
}

void print_train(int train_number)
{
    switch (train_number)
    {
    case 11058:
        printf("\n+--------+----------------+--------+-------------+----------+---------+\n");
        printf("|Train no|  Train Name    |  From  |      To     |   Date   | Arrival |\n");
        printf("+--------+----------------+--------+-------------+----------+---------+\n");
        printf("| 11058  | Amritsar Dadar | Source | Destination | DD/MM/YY |  10:30  |\n");
        printf("|        | Express        |        |             |          |         |\n");
        printf("+--------+----------------+--------+-------------+----------+---------+\n");
        break;
    case 12556:
        printf("\n+--------+----------------+--------+-------------+----------+---------+\n");
        printf("|Train no|  Train Name    |  From  |      To     |   Date   | Arrival |\n");
        printf("+--------+----------------+--------+-------------+----------+---------+\n");
        printf("| 12556  | Gorakhdham     | Source | Destination | DD/MM/YY |  12:45  |\n");
        printf("|        | Express        |        |             |          |         |\n");
        printf("+--------+----------------+--------+-------------+----------+---------+\n");
        break;
    case 11077:
        printf("\n+--------+--------------+--------+-------------+----------+---------+\n");
        printf("|Train no|  Train Name    |  From  |      To     |   Date   | Arrival |\n");
        printf("+--------+----------------+--------+-------------+----------+---------+\n");
        printf("| 11077  | Jhelum Express | Source | Destination | DD/MM/YY |  15:30  |\n");
        printf("+--------+----------------+--------+-------------+----------+---------+\n");
        break;
    case 12137:
        printf("\n+--------+--------------+--------+-------------+----------+---------+\n");
        printf("|Train no|  Train Name    |  From  |      To     |   Date   | Arrival |\n");
        printf("+--------+----------------+--------+-------------+----------+---------+\n");
        printf("| 12137  | Punjab Main    | Source | Destination | DD/MM/YY |  17:00  |\n");
        printf("+--------+----------------+--------+-------------+----------+---------+\n");
        break;
    case 12875:
        printf("\n+--------+----------------+--------+-------------+----------+---------+\n");
        printf("|Train no|  Train Name    |  From  |      To     |   Date   | Arrival |\n");
        printf("+--------+----------------+--------+-------------+----------+---------+\n");
        printf("| 12875  | Udyan Abha     | Source | Destination | DD/MM/YY |  21:45  |\n");
        printf("|        | Toofam Express |        |             |          |         |\n");
        printf("+--------+----------------+--------+-------------+----------+---------+\n");
        break;
    default:
        printf("Train %d not available", train_number);
        break;
    }
}

void write_ticket(int ticket_no, int train_no, int *seat_no, int arr_size, char source[15], char destination[15], int class, int quota)
{
    char base_path[] = "data/tickets/";
    char path[50];

    sprintf(path, "%s%d", base_path, ticket_no);
    mkdir(path, 0700);

    sprintf(path, "%s%d%s", base_path, ticket_no, "/ticket.txt");

    FILE *ptrW = fopen(path, "w");


    fprintf(ptrW, "Ticket No: %d\n\n", ticket_no);
    fprintf(ptrW, "Seats Allocated: ");
    for (int i = 0; i < arr_size; i++)
    {
        fprintf(ptrW, "S-%d ,", seat_no[i]);
    }

    switch (train_no)
    {
    case 11058:
        fprintf(ptrW, "\nTrain: Amritsar Dadar Express\n");
        fprintf(ptrW, "Boarding Time: 10:30\n");
        break;
    case 12556:
        fprintf(ptrW, "Train: Gorakhdham Express\n");
        fprintf(ptrW, "Boarding Time: 12:45\n");
        break;
    case 11077:
        fprintf(ptrW, "Train: Jhelum Express\n");
        fprintf(ptrW, "Boarding Time: 15:30\n");
        break;
    case 12137:
        fprintf(ptrW, "Train: Punjab Mail\n");
        fprintf(ptrW, "Boarding Time: 17:00\n");
        break;
    case 12875:
        fprintf(ptrW, "Train: Udyan Abha Toofan Express\n");
        fprintf(ptrW, "Boarding Time: 21:45\n");
        break;
    default:
        break;
    }

    switch (class)
    {
    case 1:
        fprintf(ptrW, "Class: Anubhuti Class\n");
        break;
    case 2:
        fprintf(ptrW, "Class: AC First Class (1A)\n");
        break;
    case 3:
        fprintf(ptrW, "Class: AC 2 Tier (2A\n");
        break;
    case 4:
        fprintf(ptrW, "Class: AC 3 Tier (3A)\n");
        break;
    case 5:
        fprintf(ptrW, "Class: AC Chair car (CC)\n");
        break;
    case 6:
        fprintf(ptrW, "Class: Sleeper (SL)\n");
        break;
    case 7:
        fprintf(ptrW, "Class: First Class (FC)\n");
        break;

    default:
        break;
    }

    switch (quota)
    {
    case 1:
        fprintf(ptrW, "Quota: General\n");
        break;
    case 2:
        fprintf(ptrW, "Quota: Ladies\n");
        break;
    case 3:
        fprintf(ptrW, "Quota: Tatkal\n");
        break;
    case 4:
        fprintf(ptrW, "Quota: Lower Berth/Sr.Citizen\n");
        break;
    case 5:
        fprintf(ptrW, "Quota: Premium Tatkal\n");
        break;
    case 6:
        fprintf(ptrW, "Quota: Divyaang\n");
        break;
    default:
        break;
    }

    fprintf(ptrW, "\nSource: %s\n", source);
    fprintf(ptrW, "Destination: %s\n\n", destination);

    node *ptr = start;
    for (int i = 1; i <= arr_size; i++)
    {
        fprintf(ptrW, "Passenger %d Details:\n", i);
        fprintf(ptrW, "  Name: %s\n", ptr->passenger_name);
        fprintf(ptrW, "  Gender: %s\n", ptr->passenger_gender);
        fprintf(ptrW, "  Age: %d\n", ptr->passenger_age);
        fprintf(ptrW, "\n");

        ptr = ptr->next;
    }

    fclose(ptrW);
}