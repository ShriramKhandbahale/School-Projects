#include "../include/globals.h"

void print_format_line()
{
    std::cout << "------------------------------";
}

int clear()
{
#ifdef _win32
    system("cls");
#else
    system("clear");
#endif
    return 0;
}

int open_file(int input_account_number)
{
    char buf[32];

#ifdef _win32
    sprintf(buf, "start data/accounts/%d/info.txt", input_account_number);
#else
    sprintf(buf, "nano data/accounts/%d/info.txt", input_account_number);
#endif
    system(buf);
    return 0;
}

int delete_file(int input_account_number)
{
    char buf[32];

#ifdef _win32
    sprintf(buf, "rmdir /Q /S data/accounts/%d/", input_account_number);
#else
    sprintf(buf, "rm -rf data/accounts/%d/", input_account_number);
#endif
    system(buf);
    return 0;
}

void processing_animation()
{

    clear();

    std::cout << "\e[?25l";

    std::cout << "processing\n";
    usleep(250000);
    clear();
    ;

    printf("processing..\n");
    usleep(250000);
    clear();
    ;

    printf("processing...\n");
    usleep(250000);
    clear();
    ;

    printf("processing\n");
    usleep(250000);
    clear();
    ;

    printf("processing.\n");
    usleep(250000);
    clear();
    ;

    printf("processing..\n");
    usleep(250000);
    clear();
    ;

    printf("processing...\n\n");
    usleep(250000);

    printf("\e[?25h");
    clear();
}

int login_prompt()
{
    int input_account_number;
    double deposit_amount;
    std::cout << "Enter Account Number: ";
    std::cin >> input_account_number;

    return input_account_number;
}

void hold()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getchar();
}

std::fstream &GotoLine(std::fstream &file, unsigned int num)
{
    file.seekg(std::ios::beg);
    for (int i = 0; i < num - 1; ++i)
    {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return file;
}

std::string get_time()
{
    time_t now = time(0);
    char *date_time = ctime(&now);
    std::string time(date_time);
    time.erase(std::remove(time.begin(), time.end(), '\n'), time.cend());
    return time;
}

bool is_empty(std::ifstream &pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}