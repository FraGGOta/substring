#include "file.h"
#include "file.h"
#include "boyermoore.h"

vector<unsigned int> *BM_search(char *text, char *sample)
{
	vector<unsigned int> *result = new vector<unsigned int>;
    int text_length = strlen(text);
    int sample_length = strlen(sample);

	if (sample_length > text_length) {
        return result;
    }
	
    int shift = 0; //Размер сдвига
	int i, j;
    
	while (shift <= text_length - sample_length) 
    {
        for (i = sample_length - 2; i >= 0; --i) 
        {
            if (text[i + shift] != sample[i]) 
            {
                for (j = i; j >= 0; --j) 
                {
                    if (text[i + shift] == sample[j]) // Совпадение стоп символа в образце
                    {
                        shift += i - j;
                        break;
                    }
                }

                if (j == -1) 
                {
                    shift += sample_length - 1;
                }
                break;
            }
        }

        if (i == -1) //Обнаружение слова
        { 
			result->push_back(shift);
            shift += sample_length - 1;
        }
    }
    return result;

}
