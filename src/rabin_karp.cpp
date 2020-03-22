#include "file.h"
#include "rabin_karp.h"

unsigned long long int ring_hash(char* substr, unsigned int sample_length, unsigned long long int prev_hash)
{
    if (!prev_hash) { //Если хеш считается впервые (т.е. нет предыдущего)
    unsigned long long int hash = 0;

        for (unsigned int i = 0; i < sample_length; ++i) { //Переводим HASH_H-ю систему счисления посимвольно
            hash += substr[i] * (unsigned long long int)pow(HASH_H, sample_length - i - 1);
        }

        return hash;
    } else {
        prev_hash -= substr[-1] * (unsigned long long int)pow(HASH_H, sample_length - 1);  //Иначе, вычетаем вклад первого (нулевого) символа из предыдущего хэша (выбывшего)
        prev_hash *= HASH_H;  //Сдвигаем на один HASH_H-й разряд влево
        prev_hash += substr[sample_length - 1] * (unsigned long long int)pow(HASH_H, 0);  //Прибавляем вклад последнего (нового) символа
        return prev_hash;
    }
}

vector<unsigned int> *RK_search(char* text, char* sample)
{
    vector<unsigned int> *result = new vector<unsigned int>;

    unsigned int text_length = strlen(text);
    unsigned int sample_length = strlen(sample);
 
    if (sample_length > text_length) {
        return result;
    }

 	int interrapt = 0;
	
    //Находим хеш для образца и для подстроки
    unsigned long long int sample_hash = ring_hash(sample, sample_length, 0);
    unsigned long long int text_hash = ring_hash(text, sample_length, 0);

    //В случае несовпадения подстроки с образцом, выполняем сдвиг на один символ (находя в конце цикла хеш следующей подстроки)
    for (unsigned int i = 0; i <= (text_length - sample_length); ++i) 
    {
        if (sample_hash == text_hash)  //Если хеши совпадают
        {
            for (unsigned int j = 0; j < sample_length; ++j)  //Выполняем сравнение посимвольно
            {
                if (sample[j] != text[i + j])  //Если символы не совпадают, прерываем цикл
                {
                    interrapt = 1;
                    break;
                }
            }

            if (!interrapt) { //Если совпадение найдено
				result->push_back(i); //Добавляем индекс начала подстроки
            } else {
                interrapt = 0;  //Иначе сбрасываем счетчик прерываний
            }
        }
        text_hash = ring_hash(text + i + 1, sample_length, text_hash); //Находим хеш следующей подстроки
    }
    return result;
}
