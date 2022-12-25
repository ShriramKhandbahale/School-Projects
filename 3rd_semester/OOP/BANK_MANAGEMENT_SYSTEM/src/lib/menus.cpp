#include "../include/menus.h"

void print_main_menu()
{
    print_format_line();
    std::cout << "\n[1] Transaction\n";
    std::cout << "[2] Inquiry\n";
    std::cout << "[3] Update Passbook\n";
    std::cout << "[4] Account\n";
    std::cout << "[0] Exit\n";
    print_format_line();

    std::cout << "\nEnter your choice (0-4): ";
}

void print_transaction_menu()
{
    print_format_line();
    std::cout << "\n[1] Deposit Amount\n";
    std::cout << "[2] Withdrawal Amount\n";
    std::cout << "[3] Transfer Amount\n";
    std::cout << "[0] <--\n";
    print_format_line();

    std::cout << "\nEnter your choice (0-3): ";
}

void print_inquiry_menu()
{
    print_format_line();
    std::cout << "\n[1] Check Balance\n";
    std::cout << "[2] View Passbook\n";
    std::cout << "[0] <--\n";

    print_format_line();

    std::cout << "\nEnter your choice (0-2): ";
}

void print_account_menu()
{
    print_format_line();
    std::cout << "\n[1] Open New Account\n";
    std::cout << "[2] Update/Modify Account\n";
    std::cout << "[3] Close an Account\n";
    std::cout << "[4] Display all Accounts\n";
    std::cout << "[0] <--\n";
    print_format_line();

    std::cout << "\nEnter your choice (0-4): ";
}