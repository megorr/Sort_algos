#include <iostream>
#include "Sorts.h"
#include <chrono>
#include <thread>
#include <cctype>
#include <fstream>

#define TIMING
#define SIZE 50000

#ifdef TIMING //Макрос для измерения времени выполнения участка программы
#define INIT_TIMER auto start = std::chrono::steady_clock::now();
#define START_TIMER  start = std::chrono::steady_clock::now();
#define STOP_TIMER(name, time)  time = std::chrono::duration_cast<std::chrono::nanoseconds>\
								(std::chrono::steady_clock::now()-start).count();\
								std::cout << "RUNTIME of " << name << ": " << \
								time << " ns " << "or " << time/1000000 << "ms" <<std::endl;\
		
#else
#define INIT_TIMER
#define START_TIMER
#define STOP_TIMER(name)
#endif

template<typename X>
void fill_rand(X *arr, X &size);//Прототип функции заполнения массива рандомными числами

template<typename X>//Прототип функции измерения веремени работы программы сортировки
float measure_sort_time(X &arr_size, const int &sort_type);

int main()
{
	enum {Bubble = 1, Selection, Insertion, Quick};
	float time = 0;
	char sw;
	int sort_type = 1, arr_size = 0;

	//////////////////////////////////////////////////////////////////Меню с выбором сортировки//////////////////////////////////////////////////////////////////
	
	do
	{
		
		std::cout << "Choose the number of the sorting algo:\n";
		std::cout << "1. Bubble sort\n" << "2. Selection sort\n" << "3. Insertion sort\n" << "4. Quick sort\n" << "Enter q to exit\n";
		std::cin >> sw;

		if (std::toupper(sw) == 'Q') break;
		sort_type = atoi(&sw);
		system("clear");

		std::cout << "Enter the size of the array\n";
		std::cin >> arr_size;
		system("clear");

		std::cout << "Sorting array of " << arr_size << " elements\n";
		measure_sort_time(arr_size, sort_type);
		std::cout << "\n";
		system("pause");
		system("clear");

	} while (true);

	//////////////////////////////////////////////////////////////////Примеры испльзования функций сортировки////////////////////////////////////////////////////

	//int arr[10] = { 5, 6, 3, 4, 1, 2, 0, 9, 7, 8 };//Массив из 10 чисел
	//insertion_sort(arr, &arr[10]);//Сортировка вставкой
	//selection_sort(arr, &arr[10]);//Сортировка выборкой
	//bubble_sort(arr, &arr[10]);//Сортировка пузырьком
	//quick_sort(arr, &arr[10]);//Быстрая сортировка, разбиение Ломуто
	//print_arr(arr, &arr[10]);//Вывод массива в консоль

	//////////////////////////////////////////////////////////////////Запись значений времени сортировки////////////////////////////////////////////////////////
/* 
	std::ofstream measurements;
	measurements.open("measurements.csv");
	measurements << "Array size;Bubble sorting time;Selection sorting time;Insertion sorting time;Quick sorting time\n";

	for (int i = 2; i <= 100000;)
	{
		std::cout << i << "\n";
		measurements << i << ";" << measure_sort_time(i, static_cast<int>(Bubble))/1000000 <<
							 ";" << measure_sort_time(i, static_cast<int>(Selection))/1000000 <<
							 ";" << measure_sort_time(i, static_cast<int>(Insertion))/1000000 << 
							 ";" << measure_sort_time(i, static_cast<int>(Quick))/1000000 << "\n";
		if (i >= 10000) i += 5000;
		if (i >= 1000 && i < 10000) i += 250;
		if (i >= 100 && i < 1000) i += 10;
		if (i >= 10 && i < 100) i += 5;
		if (i < 10) ++i;
	};
	measurements.close(); */
};

template<typename X>
void fill_rand(X *arr, X &size)//Заполнение массива рандомными числами
{
	register X i = 0;
	for (; i < size; ++i)
	{
		*arr++ = rand();
	};
	return;
};

template<typename X>
float measure_sort_time(X &arr_size, const int &sort_type)//Измерение времени работы определенного алгоритма сортировки
{
	INIT_TIMER;
	float time = 0;
	int *numbers = new int[arr_size];

	fill_rand(numbers, arr_size);

	switch (sort_type)
	{
	case 1://Сортировка пузырьком
		START_TIMER;
		bubble_sort(numbers, &numbers[arr_size]);
		STOP_TIMER("Bubble sort", time);
		break;

	case 2:
		START_TIMER;//Сортировка выбором
		selection_sort(numbers, &numbers[arr_size]);
		STOP_TIMER("Selection sort", time);
		break;

	case 3:
		START_TIMER;//Сортировка вставками
		insertion_sort(numbers, &numbers[arr_size]);
		STOP_TIMER("Insertion sort", time);
		break;

	case 4:
		START_TIMER;//Быстрая сортировка
		quick_sort(numbers, &numbers[arr_size]);
		STOP_TIMER("Quick sort", time);
		break;

	default:
		std::cout << "You've done smthng wrong, try again!\n";
		return -1;
	};

	return time;
};
