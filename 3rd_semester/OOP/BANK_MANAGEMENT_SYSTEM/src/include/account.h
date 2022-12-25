#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "../include/account.h"
#include "../include/globals.h"
#include "../include/menus.h"

#include <string>

class Account
{
    int account_number;
    char account_type;
    double balance = 0.00;

public:
    void set_account_number(int);
    void set_account_type();
    void set_account_balance(double);

    char get_account_type();
    int get_account_number();
    double get_account_balance();
};

class User : public Account
{
    static int user_count;
    std::string first_name;
    std::string last_name;
    std::string address;
    long unsigned int contact_no;
    long unsigned int aadhaar_card_no;
    long unsigned int pan_no;
    int age;

public:
    void create_account();
    void write_account(int);
    void get_account_info();
    void print_success_message();
};

#include <fstream>
#include <limits>
#include <cctype>
#include <unistd.h>

void delete_record(const char *file_name, int n);

#include <string>
#include <iostream>
#include <sys/stat.h>

int generate_account_number();
void display_registered_accounts();
void delete_account();
void update_account();

#endif