#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <unistd.h>

#include "include/globals.h"
#include "include/transactions.h"
#include "include/menus.h"
#include "include/account.h"
#include "include/inquiry.h"
#include "include/passbook.h"

int main()
{
    User user;
    bool select_failure = false;
    char choice;
    int input_account_number;
    std::string var_string;

    do
    {
    start:
        clear();
        print_main_menu();
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            select_failure = false;
            do
            {
                clear();
                print_transaction_menu();
                std::cin >> choice;

                switch (choice)
                {
                case '1':
                    clear();
                    deposit_amount();
                    hold();
                    goto start;
                    break;
                case '2':
                    clear();
                    withdrawal_amount();
                    hold();
                    goto start;
                    break;
                case '3':
                    clear();
                    transfer_amount();
                    hold();
                    goto start;
                    break;
                case '0':
                    goto start;
                    break;
                default:
                    std::cout << "Error: Invalid Input\n";
                    sleep(1);
                    select_failure = true;
                    break;
                }
            } while (select_failure);
            break;
        case '2':
            select_failure = false;
            do
            {
                clear();
                print_inquiry_menu();
                std::cin >> choice;

                switch (choice)
                {
                case '1':
                    clear();
                    check_balance();
                    goto start;
                    break;
                case '2':
                    clear();
                    view_passbook(login_prompt());
                    hold();
                    goto start;
                    break;
                case '0':
                    goto start;
                    break;
                default:
                    std::cout << "Error: Invalid Input\n";
                    sleep(1);
                    select_failure = true;
                    break;
                }
            } while (select_failure);
            break;
        case '3':
            clear();
            update_passbook();
            hold();
            goto start;
            break;
        case '4':
            select_failure = false;
            do
            {
                clear();
                print_account_menu();
                std::cin >> choice;

                switch (choice)
                {
                case '1':
                    user.create_account();
                    goto start;
                    break;
                case '2':
                    clear();
                    update_account();
                    goto start;
                    break;
                case '3':
                    clear();
                    delete_account();
                    hold();
                    goto start;
                    break;
                case '4':
                    clear();
                    display_registered_accounts();
                    goto start;
                    break;
                case '0':
                    goto start;
                    break;
                default:
                    std::cout << "Error: Invalid Input\n";
                    sleep(1);
                    select_failure = true;
                    break;
                }
            } while (select_failure);
            break;
        case '0':
            exit(1);
            break;

        default:
            std::cout << "Error: Invalid Input\n";
            sleep(1);
            select_failure = true;
            break;
        }
    } while (select_failure);
}