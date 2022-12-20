#include "../include/account.h"
#include "../include/globals.h"
#include "../include/menus.h"
#include <fstream>
#include <limits>
#include <cctype>
#include <unistd.h>
#include <string>
#include <iostream>
#include <sys/stat.h>
#include "../include/account.h"

void Account::set_account_number(int user_count)
{
    account_number = user_count;
}

void Account::set_account_type()
{
    std::cout << "\nEnter Account Type (C/S): ";
    std::cin >> account_type;
    account_type = toupper(account_type);

    if (account_type == 'C' || account_type == 'S')
    {
        this->account_number = account_number;
    }
    else
    {
        std::cout << "\nInvalid account type\n";
        exit(1);
    }
}

void Account::set_account_balance(double acc_balance)
{
    balance = acc_balance;
}

double Account::get_account_balance()
{
    return balance;
}

char Account::get_account_type()
{
    return account_type;
}

int Account::get_account_number()
{
    return account_number;
}

void User::print_success_message()
{
    processing_animation();

    std::cout << "Account created Successfully\n";
    std::cout << "Your Account number is : " << get_account_number() << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getchar();
}

void User::create_account()
{
    clear();
    std::cout << "Enter First Name: ";
    std::cin >> first_name;

    std::cout << "\nEnter Last Name: ";
    std::cin >> last_name;

    std::cout << "\nEnter age: ";
    std::cin >> age;

    std::cout << "\nEnter Contact Number: ";
    std::cin >> contact_no;

    std::cout << "\nEnter Aadhaar Chard Number: ";
    std::cin >> aadhaar_card_no;

    std::cout << "\nEnter PAN Number: ";
    std::cin >> pan_no;

    set_account_type();

    std::cout << "\nEnter Address: ";
    std::cin >> address;

    set_account_number(generate_account_number());
    write_account(get_account_number());
}

void User::get_account_info()
{
    std::cout << "\nFirst Name: " << first_name;
    std::cout << "\nLast Name: " << last_name;
    std::cout << "\nAadhar: " << aadhaar_card_no;
    std::cout << "\naacout type: " << get_account_type();
    std::cout << "\nacc no" << get_account_number();
}

int generate_account_number()
{
    std::ifstream file_count("data/stats/user_count.txt");
    int user_count;
    file_count >> user_count;
    ++user_count;
    file_count.close();
    std::ofstream file_count_add("data/stats/user_count.txt");
    file_count_add << user_count;
    file_count_add.close();

    return user_count;
}

void User::write_account(int account_number)
{
    std::string acc_file_name;
    acc_file_name = std::to_string(account_number);

    std::string folder_name = "data/accounts/" + acc_file_name;
    mkdir(folder_name.c_str(), 0777);

    acc_file_name = "data/accounts/" + acc_file_name + "/info.txt";
    std::ofstream write_account(acc_file_name);

    write_account << "First Name: " << first_name << std::endl
                  << "Last Name: " << last_name << std::endl
                  << "Account Number: " << get_account_number() << std::endl
                  << "Account Type: " << get_account_type() << std::endl
                  << "PAN Number: " << pan_no << std::endl
                  << "Aadhaar Number: " << aadhaar_card_no << std::endl
                  << "Contact Number: " << contact_no << std::endl
                  << "Age: " << age << std::endl
                  << "Address: " << address;
    write_account.close();

    // writing balance 0.00 to file
    std::string acc_balance_file = folder_name + "/account_balance.txt";
    std::ofstream write_account_balance(acc_balance_file);
    write_account_balance << get_account_balance();
    write_account_balance.close();

    // adding record to register
    std::ofstream add_account_to_register("data/register/registered_accounts.txt", std::ios::app);
    add_account_to_register << first_name << " " << last_name
                            << "\t\t\t\t|\t" << get_account_number()
                            << "\t|\t" << get_account_type() << std::endl;
    add_account_to_register.close();
    print_success_message();
}

void delete_account()
{
    int input_account_number;
    std::cout << "Enter Account Number: ";
    std::cin >> input_account_number;
    if (delete_file(input_account_number) == 0)
    {
        clear();
        std::cout << "Account deleted\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getchar();
    }
}

void update_account()
{
    int input_account_number;
    std::cout << "Enter Account Number: ";
    std::cin >> input_account_number;
    if (open_file(input_account_number) == 0)
    {
        clear();
        std::cout << "Record Updated\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getchar();
    }
}

void display_registered_accounts()
{
    std::string var_string;
    std::ifstream registered_accounts_file("data/register/registered_accounts.txt");
    while (getline(registered_accounts_file, var_string))
    {
        std::cout << var_string << std::endl;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getchar();
}