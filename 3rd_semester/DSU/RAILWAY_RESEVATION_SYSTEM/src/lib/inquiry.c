void inqury()
{
    printf("Select Arrival and Destination Place\n");

    printf("From: ");
    char arrival[20];
    scanf(" %s", arrival);

    printf("To: ");
    char destination[20];
    scanf(" %s", destination);

    printf("\n");

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

    printf("Departure Date (DD/MM/YYYY): ");
    char departure_date[10];
    scanf(" %s", departure_date);

    printf("Search Trains [Y] : ");
    getchar();
}