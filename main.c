#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <Windows.h>
#include <wchar.h>
#define N 100
char process_line(char buffer[], char c)
	{
		printf("-------------------------------------------------------------------------------\n");
		char* ptr;
		ptr = buffer; //указатель на стпроку элентты массива
		char word[N]; //буфферный массив для слова
		char* ptr_word = word;
		*ptr_word = '\0';
		while (*ptr != '\0')
		{
			if (*ptr == c) //найден раз
			{
				*ptr_word = '\0';
				printf("|| %s\t", word);
				ptr_word = word; //ставлю указатель на начало
				*ptr_word = '\0'; //и обнуляю его
				ptr++;
			}
			else
			{
				*ptr_word++ = *ptr++; //я в массив ворм записываю слово
			}

		}

		if (word[0] != '\0')
		{
			*ptr_word = '\0';
			printf("|| %s\t", word);
		}
		printf("\n");
	}
int main(int argc, char* argv[]) //параметр будет выведен с консоли, массив тех параме
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

	FILE* file;
	char line[N];
	char c = *argv[1];
	if (c == NULL)
	{
		printf_s("error");
		return -1;
	}
	errno_t fp;
	int nlines1 = 0, nl;
	fp = fopen_s(&file, "C:\\rename.txt", "rt");

	/*элементы argv[1]...argv[argc - 1] содержат указатели на параметры командной строки.*/
	while (!feof(file)) //печатаю
	{
		fgets(line, N, file); //заполняю массив
		process_line(line, c);
	}
	system("pause");
}