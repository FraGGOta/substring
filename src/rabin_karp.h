#pragma once

#define HASH_H 31

unsigned long long int ring_hash(char* sample, unsigned int sample_length, unsigned long long int prev_hash);
vector<unsigned int> *RK_search(char* text, char* sample);
