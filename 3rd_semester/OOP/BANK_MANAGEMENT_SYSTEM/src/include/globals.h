#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>

#include <stdlib.h>

#include <string>

void print_format_line();

int clear();

void processing_animation();

int open_file(int);

#include <fstream>
#include <limits>

int delete_file(int);

int login_prompt();

#include <cstdlib>
#include <unistd.h>

void hold();

std::fstream &GotoLine(std::fstream &, unsigned int);

#include <ctime>
std::string get_time();

#include <algorithm>

bool is_empty(std::ifstream &);

#endif