#include <stdio.h>

#include "../include/getters.h"

int get_ticket_no()
{
    int ticket_no;

    FILE *ptrR = fopen("data/tickets/ticket_count.txt", "r");
    fscanf(ptrR, "%d", &ticket_no);
    fclose(ptrR);

    ticket_no++;

    FILE *ptrW = fopen("data/tickets/ticket_count.txt", "w");
    fprintf(ptrW, "%d", ticket_no);
    fclose(ptrW);

    return ticket_no;
}

void get_seat_count(int *array, int size)
{
    int seat_count;
    FILE *ptrR = fopen("data/tickets/seatno_count.txt", "r");

    fscanf(ptrR, "%d", &seat_count);

    for (int i = 0; i < size; i++)
    {
        array[i] = seat_count + i;
    }
    fclose(ptrR);

    FILE *ptrW = fopen("data/tickets/seatno_count.txt", "w");
    fprintf(ptrW, "%d", seat_count + size);
    fclose(ptrW);
}