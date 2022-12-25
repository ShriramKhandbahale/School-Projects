#include "../include/passbook.h"

void update_passbook()
{
    int account_number = login_prompt();

    std::string s_account_number = std::to_string(account_number);

    std::string path_w = "data/accounts/" + s_account_number + "/untracked/withdrawal.txt";
    std::ifstream withdrawal_file(path_w);

    std::string passbook_path = "data/accounts/" + s_account_number + "/passbook.txt";
    std::ofstream passbook(passbook_path, std::ios::app);

    std::string path_d = "data/accounts/" + s_account_number + "/untracked/deposit.txt";
    std::ifstream deposit_file(path_d);

    std::string line;

    if (!is_empty(withdrawal_file) || !is_empty(deposit_file))
    {
        if (!is_empty(withdrawal_file))
        {
            while (!withdrawal_file.eof())
            {
                getline(withdrawal_file, line);
                passbook << line << "\n";
            }
            std::ofstream withdrawal(path_w, std::ofstream::out | std::ofstream::trunc);
            withdrawal.close();
        }

        if (!is_empty(deposit_file))
        {
            while (!deposit_file.eof())
            {
                getline(deposit_file, line);
                passbook << line << std::endl;
            }
            std::ofstream deposit(path_d, std::ofstream::out | std::ofstream::trunc);
            deposit.close();
        }

        std::cout << "Passbook Updated\n\n";
        view_passbook(account_number);
    }
    else
    {
        clear();
        std::cout << "No Transactions found\n";
    }
}

void view_passbook(int account_number)
{
    std::string s_account_number = std::to_string(account_number);
    std::string passbook_path = "data/accounts/" + s_account_number + "/passbook.txt";
    std::ifstream passbook(passbook_path);

    std::string line;
    while (!passbook.eof())
    {
        getline(passbook, line);
        std::cout << line << "\n";
    }
    for (int i = 0; i < 75; i++)
    {
        std::cout << "-";
        if (i == 74)
        {
            std::cout << std::endl;
        }
    }
}