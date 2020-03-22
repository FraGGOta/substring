#include "file.h"
#include "rabin_karp.h"
#include "boyermoore.h"
#include "knuthmorrispratt.h"

char *sample;

int main(int argc, char *argv[])
{
	int choice;
	clock_t start, end;
	sample = argv[1];

	if (argc == 3) 
	{
		FILE *file = fopen(argv[2], "r");
		if (file == NULL) {
			cout << endl << "File not found\nSearch failed" << endl; 
			return -1;
		}
		
		cout << endl << "1.Rabin–Karp algorithm\n2.Boyer–Moore algorithm\n3.Knuth–Morris–Pratt algorithm" << endl;
		cin >> choice;

		if (choice == 1) {
			char *text = file_to_string(file);
			start = clock();
    		vector<unsigned int> *result = RK_search(text, sample);
    		end = clock();
			file_print(text, result);
    		free(text);
   			delete result;
			fclose(file);
		}
		else if (choice == 2) {
			char *text = file_to_string(file);
			start = clock();
    		vector<unsigned int> *result = BM_search(text, sample);
    		end = clock();
			file_print(text, result);
    		free(text);
   			delete result;
			fclose(file);
		}
		else if (choice == 3) {
			char *text = file_to_string(file);
			start = clock();
    		vector<unsigned int> *result = KMP_search(text, sample);
    		end = clock();
			file_print(text, result);
    		free(text);
   			delete result;
			fclose(file);
		}
		else {
			cout << endl << "Error\nEnter a value from 1 to 3\nSearch failed" << endl;
			return -1;
		}
	}
	else {
		cout << endl << "Invalid arguments number!\n<source><search word><file>\nSearch failed" << endl;
		return -1;
	}
	
	double timer = (double)(end - start) / CLOCKS_PER_SEC;
	cout << endl << "Time: " << timer << " sec." << endl << endl;
	
	return 0;
}
