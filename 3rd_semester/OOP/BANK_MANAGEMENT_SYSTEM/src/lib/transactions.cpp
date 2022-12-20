#include "../include/transactions.h"
#include "../include/globals.h"
#include <iostream>
#include <limits>
#include <fstream>

void deposit_amount()
{
    int input_account_number;
    double deposit_amount;
    std::cout << "Enter Account Number: ";
    std::cin >> input_account_number;

    clear();

    std::cout << "Enter Amount to deposit: ";
    std::cin >> deposit_amount;

    std::string s_account_number = std::to_string(input_account_number);
    std::string path = "data/accounts/" + s_account_number + "/account_balance.txt";
    std::ifstream deposit_file_r(path);

    double current_balance;
    deposit_file_r >> current_balance;
    deposit_file_r.close();

    std::ofstream deposit_file_w(path);
    deposit_file_w << current_balance + deposit_amount;

    clear();

    std::cout << "Transaction Successful\n\n";
    std::cout << "Account Number: " << input_account_number << "\n\n";
    std::cout << current_balance << " + " << deposit_amount << std::endl;
    std::cout << "Current balance: " << current_balance + deposit_amount << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getchar();
}

void withdrawal_amount()
{
    //todo working on

    int input_account_number;
    double withdrawal_amount;

    std::cout << "Enter Account Number: ";
    std::cin >> input_account_number;

    clear();

    std::cout << "Enter Amount to deposit: ";
    std::cin >> deposit_amount;  
}