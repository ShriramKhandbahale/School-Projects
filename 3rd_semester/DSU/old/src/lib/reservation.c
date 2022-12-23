#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "../include/globals.h"
#include "../include/reservation.h"

typedef struct
{
    char passenger_name[20];
    char passenger_gender[6];
    int passenger_age;
    struct node *next;
} node;

void book_ticket()
{

    printf("Select Source and Destination Place\n");

    printf("From: ");
    char arrival[20];
    scanf(" %s", arrival);

    printf("To: ");
    char destination[20];
    scanf(" %s", destination);

    printf("Departure Date (DD/MM/YYYY): ");
    char departure_date[10];
    scanf(" %s", departure_date);

    printf("Enter number of passengers/members: ");
    int passenger_no;
    scanf("%d", passenger_no);

    print_format_line();
    printf("Trains from %s to %s on %s: \n\n", arrival, destination, departure_date);
    // todo print dashbaord
    print_format_line();

    printf("Enter Train No: ");
    int train_number;
    scanf("%d", &train_number);

    clear();
    switch (train_number)
    {
    case 11058:
        printf("train----");
        break;

    default:
        printf("No %d not available", train_number);
        break;
    }

    print_format_line();
    printf("\n[1] All Classes\n");
    printf("[2] Anubhuti Class\n");
    printf("[3] AC First Class (1A)\n");
    printf("[4] AC 2 Tier (2A)\n");
    printf("[5] AC 3 Tier (3A)\n");
    printf("[6] AC Chair car (CC)\n");
    printf("[7] Sleeper (SL)\n");
    printf("[8] First Class (FC)\n");
    print_format_line();

    printf("Select Classes (1-8): ");
    int class_choice;
    scanf("%d", &class_choice);

    printf("\n");

    print_format_line();
    printf("\n[1] General\n");
    printf("[2] Ladies\n");
    printf("[3] Tatkal\n");
    printf("[4] Lower Berth/Sr.Citizen\n");
    printf("[5] Premium Tatkal\n");
    printf("[6] Divyaang\n");
    // printf("[7] Sleeper (SL)\n");
    // printf("[8] First Class (FC)\n");
    print_format_line();

    printf("Select Classes (1-8): ");
    int quota_choice;
    scanf("%d", &quota_choice);

    void processing_animation();

    printf("Confirm Reservation [Y/n] :");
    char confirm_choice;
    scanf(" %c", confirm_choice);
    confirm_choice = toupper(confirm_choice);

    if (!confirm_choice == 'Y')
    {
        return 0;
    }

    passenger_details(passenger_no);

    void processing_animation();

    printf("Ticket Confirmed\n\n");
    printf("your ticket no is: %d", get_ticket_no());

    printf("Allocated Seats: ");
}

void passenger_details(int passenger_no)
{
    char passenger_name[20];
    char passenger_gender[6];
    int passenger_age;

    for (int i = 1; i <= passenger_no; i++)
    {
        clear();
        printf("Passenger %d Details:\n", i);

        printf("Name: ");
        scanf(" %s", passenger_name);

        printf("Gender: ");
        scanf(" %s", passenger_gender);

        printf("Age: ");
        scanf("%s", passenger_age);

        add_to_list(passenger_name, passenger_gender, passenger_age);
    }
}

void add_to_list(char passenger_name[20], char passenger_gender[6], int passenger_age)
{
    node *temp = NULL, *ptr;

    temp = (node *)malloc(sizeof(node));

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
        printf("Passenger %d Details: ", i);

        printf("\tName: ");
        puts(ptr->passenger_name);

        printf("\tGender: ");
        puts(ptr->passenger_gender);

        printf("\tAge: %d", ptr->passenger_age);

        ptr = ptr->next;
    }
}