#include "file.h"
#include "knuthmorrispratt.h"

vector<unsigned int> *KMP_search(char *text, char *sample)
{
	vector<unsigned int> *result = new vector<unsigned int>; 
	int text_length = strlen(text);
	int sample_length = strlen(sample);   
	
	if (sample_length > text_length) {
        return result;
    }

	int *prefix = (int*)malloc(sample_length * sizeof(int));	
	  
	//Вычисление префикс функции
	prefix[0] = 0;
    for(int i = 1, j = 0; i < sample_length; i++)
    {
        while((j > 0) && (sample[j] != sample[i]))
            j = prefix[j - 1];
        
		if(sample[j] == sample[i])
            j++;
            
		prefix[i] = j;
    }
	
	//Поиск
	int position = 0;
	while (position != -1) 
	{ 
		for(int i = position, j = 0; i < text_length; i++)
		{
			while((j > 0) && (sample[j] != text[i]))
				j = prefix[j - 1];
        
			if(sample[j] == text[i])
				j++;
        
			if(j == sample_length)
			{
				position = i - j + 1; //Продолжаем поиск следующих вхождений
				result->push_back(position);
			}
		}
		position = -1;
		break;
	}
	free(prefix);
	return result;
}
