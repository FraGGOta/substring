#include "file.h"
#include "rabin_karp.h"
#include "boyermoore.h"
#include "knuthmorrispratt.h"

extern char *sample;

char *file_to_string(FILE *file)
{
    unsigned int i;
    char *string = (char*)malloc(1 * sizeof(char));

    for (i = 0; fscanf(file, "%c", &string[i]) != EOF; ++i) {
        string = (char*)realloc(string, (i + 2) * sizeof(char));
    }
    string[i] = '\0';

    return string;
}

void file_print(char *text, vector<unsigned int> *result)
{   
    if (!result->size()) {
        cout << "No match found";
    } else {
        unsigned int text_length = strlen(text);
        unsigned int str_num = 1;
        unsigned int char_num = 0;
        unsigned int result_index = 0;
		cout << "Search done!" << endl << endl;
        for (unsigned int i = 0; i < text_length; ++i) 
		{
            ++char_num;
            if (text[i] == '\n') 
			{
                ++str_num;
                char_num = 0;
            }
			if (result_index == result->size()) 
				return;
            else if (i == result->at(result_index)) 
			{
				cout << "Line: " << str_num << " Position: " << char_num << endl;
                ++result_index;
            }
        }
    }
	cout << endl;
}
