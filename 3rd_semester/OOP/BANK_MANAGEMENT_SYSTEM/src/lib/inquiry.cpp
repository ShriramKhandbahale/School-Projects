#include "../include/inquiry.h"

void check_balance()
{
    int input_account_number = login_prompt();

    std::string s_account_number = std::to_string(input_account_number);
    std::string path = "data/accounts/" + s_account_number + "/account_balance.txt";
    std::ifstream file_r(path);
    char account_record;

    double current_balance;
    file_r >> current_balance;
    file_r.close();

    std::fstream record("data/register/registered_accounts.txt");
    GotoLine(record, input_account_number - 999);
    // record.close();

    clear();

    std::cout << "Account No: " << input_account_number << std::endl;
    std::cout << "\nAccount Holder Name:\n";
    while (true)
    {
        record >> account_record;
        if (account_record == '|')
        {
            break;
        }
        std::cout << account_record;
    }
    std::cout << "\n\nCurrent Balance: " << current_balance << std::endl;
    hold();
}