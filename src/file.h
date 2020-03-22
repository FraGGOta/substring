#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <string.h>
#include <time.h>

using namespace std;

char *file_to_string(FILE *file);
void file_print(char *text, vector<unsigned int> *result);
