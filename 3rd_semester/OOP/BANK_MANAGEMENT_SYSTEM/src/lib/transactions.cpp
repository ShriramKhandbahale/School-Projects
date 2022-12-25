#include "../include/transactions.h"
#include "../include/globals.h"
#include <iostream>
#include <limits>
#include <fstream>

void deposit_amount()
{
    double deposit_amount;
    int input_account_number = login_prompt();

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

    // updating passbook
    path = "data/accounts/" + s_account_number + "/untracked/deposit.txt";
    std::ofstream untracked_d(path, std::ios::app);
    std::string white_spaces1;
    std::string white_spaces2;
    std::string s_deposit_amount = std::to_string(deposit_amount);
    for (int i = 0; i < 26; i++)
    {
        white_spaces1 += " ";
    }
    for (int i = 0; i < 24 - s_deposit_amount.length(); i++)
    {
        white_spaces2 += " ";
    }
    untracked_d << get_time() << white_spaces1 << deposit_amount << white_spaces2 << current_balance + deposit_amount << std::endl;
    untracked_d.close();
}

void withdrawal_amount()
{
    int input_account_number = login_prompt();
    double withdrawal_amount;

    clear();

    std::cout << "Enter Amount to Withdrawal: ";
    std::cin >> withdrawal_amount;

    std::string s_account_number = std::to_string(input_account_number);
    std::string path = "data/accounts/" + s_account_number + "/account_balance.txt";
    std::ifstream withdrawal_file_r(path);

    double current_balance;
    withdrawal_file_r >> current_balance;
    withdrawal_file_r.close();

    std::ofstream withdrawal_file_w(path);
    withdrawal_file_w << current_balance - withdrawal_amount;

    clear();

    std::cout << "Transaction Successful\n\n";
    std::cout << "Account Number: " << input_account_number << "\n\n";
    std::cout << current_balance << " - " << withdrawal_amount << std::endl;
    std::cout << "Current balance: " << current_balance - withdrawal_amount << std::endl;

    // updating passbook
    path = "data/accounts/" + s_account_number + "/untracked/withdrawal.txt";
    std::ofstream untracked_w(path, std::ios::app);
    std::string white_spaces;
    std::string s_withdrawal_amount = std::to_string(withdrawal_amount);
    for (int i = 0; i < 44 - s_withdrawal_amount.length(); i++)
    {
        white_spaces += " ";
    }
    untracked_w << get_time() << "      " << withdrawal_amount << white_spaces << current_balance - withdrawal_amount << std::endl;
    untracked_w.close();
}

void transfer_amount()
{
    int input_account_number = login_prompt();
    double transfer_amount;
    int receiving_account_number;

    clear();

    std::cout << "Enter the Receiver's Account No: ";
    std::cin >> receiving_account_number;

    clear();

    std::cout << "Enter Amount to Transfer: ";
    std::cin >> transfer_amount;

    // deduct form senders account
    std::string s_account_number = std::to_string(input_account_number);
    std::string path = "data/accounts/" + s_account_number + "/account_balance.txt";
    std::ifstream sender_file_r(path);

    double current_balance;
    sender_file_r >> current_balance;
    sender_file_r.close();

    std::ofstream sender_file_w(path);
    sender_file_w << current_balance - transfer_amount;
    sender_file_w.close();

    clear();

    std::cout << "Transaction Successful\n\n";
    std::cout << "Amount " << transfer_amount << " Successfully Deposited to " << receiving_account_number << std::endl;
    std::cout << "\nAccount Number: " << input_account_number << "\n\n";
    std::cout << current_balance << " - " << transfer_amount << std::endl;
    std::cout << "Current balance: " << current_balance - transfer_amount << std::endl;

    // add to receivers account
    s_account_number = std::to_string(receiving_account_number);
    path = "data/accounts/" + s_account_number + "/account_balance.txt";
    std::ifstream receiver_file_r(path);
    receiver_file_r >> current_balance;
    receiver_file_r.close();

    std::ofstream receiver_file_w(path);
    receiver_file_w << current_balance + transfer_amount;
    receiver_file_w.close();

    // updating passbook of sender
    s_account_number = std::to_string(input_account_number);
    path = "data/accounts/" + s_account_number + "/untracked/withdrawal.txt";
    std::ofstream untracked_w(path, std::ios::app);
    std::string white_spaces;
    std::string s_transfer_amount = std::to_string(transfer_amount);
    for (int i = 0; i < 44 - s_transfer_amount.length(); i++)
    {
        white_spaces += " ";
    }
    untracked_w << get_time() << "      " << transfer_amount << white_spaces << current_balance - transfer_amount << std::endl;
    untracked_w.close();

    // updating passbook of receiver
    s_account_number = std::to_string(receiving_account_number);
    path = "data/accounts/" + s_account_number + "/untracked/deposit.txt";
    std::ofstream untracked_d(path, std::ios::app);
    std::string white_spaces1;
    std::string white_spaces2;
    for (int i = 0; i < 26; i++)
    {
        white_spaces1 += " ";
    }
    for (int i = 0; i < 24 - s_transfer_amount.length(); i++)
    {
        white_spaces2 += " ";
    }
    untracked_d << get_time() << white_spaces1 << transfer_amount << white_spaces2 << current_balance + transfer_amount << std::endl;
    untracked_d.close();
}