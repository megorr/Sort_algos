#include <iostream>
#include "Sorts.h"
#include <chrono>
#include <thread>
#include <cctype>
#include <fstream>

using namespace std;

#define TIMING
#define SIZE 50000

#ifdef TIMING //Макрос для измерения времени выполнения участка программы
#define INIT_TIMER auto start = chrono::steady_clock::now();
#define START_TIMER  start = chrono::steady_clock::now();
#define STOP_TIMER(name, time)  time = chrono::duration_cast<chrono::nanoseconds>\
								(chrono::steady_clock::now()-start).count();\
								cout << "RUNTIME of " << name << ": " << \
								time << " ns " << "or " << time/1000000 << "ms" <<endl;\
		
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
	enum {Bubble = 1, Selection, Insertion, Quick, Merge};
	float time = 0;
	char sw;
	int sort_type = 1, arr_size = 0;

	//////////////////////////////////////////////////////////////////Меню с выбором сортировки//////////////////////////////////////////////////////////////////
	
	// do
	// {
		
	// 	cout << "Choose the number of the sorting algo" << endl;
	// 	cout << "1. Bubble sort\n" << "2. Selection sort\n" << "3. Insertion sort\n" << "4. Quick sort\n" << "5. Merge sort\n" <<  "Enter q to exit" << endl;
	// 	cin >> sw;

	// 	if (toupper(sw) == 'Q') break;
	// 	sort_type = atoi(&sw);
	// 	system("clear");

	// 	cout << "Enter the size of the array" << endl;
	// 	cin >> arr_size;
	// 	system("clear");

	// 	cout << "Sorting array of " << arr_size << " elements" << endl;
	// 	measure_sort_time(arr_size, sort_type);
	// 	cout << endl;
	// 	system("pause"); 
	// 	//system("clear");

	// } while (true);

	//////////////////////////////////////////////////////////////////Примеры испльзования функций сортировки////////////////////////////////////////////////////

	//int arr[10] = { 5, 6, 3, 4, 1, 2, 0, 9, 7, 8 };//Массив из 10 чисел
	// insertion_sort(arr, &arr[10]);//Сортировка вставкой
	// selection_sort(arr, &arr[10]);//Сортировка выборкой
	// bubble_sort(arr, &arr[10]);//Сортировка пузырьком
	// quick_sort(arr, &arr[10]);//Быстрая сортировка, разбиение Ломуто
	//merge_sort(arr, &arr[10]);
	//print_arr(arr, &arr[10]);//Вывод массива в консоль

	//////////////////////////////////////////////////////////////////Запись значений времени сортировки////////////////////////////////////////////////////////
 
	ofstream measurements;
	measurements.open("measurements.csv");
	measurements << "Array size;Bubble sorting time;Selection sorting time;Insertion sorting time;Quick sorting time;Merge sorting time" << endl;

	for (int i = 2; i <= 100000;)
	{
		cout << i << endl;
		measurements << i << ";" << measure_sort_time(i, static_cast<int>(Bubble))/1000000 <<
							 ";" << measure_sort_time(i, static_cast<int>(Selection))/1000000 <<
							 ";" << measure_sort_time(i, static_cast<int>(Insertion))/1000000 << 
							 ";" << measure_sort_time(i, static_cast<int>(Quick))/1000000 <<
							 ";" << measure_sort_time(i, static_cast<int>(Merge))/1000000 << "\n";
		if (i >= 10000) i += 5000;
		if (i >= 1000 && i < 10000) i += 250;
		if (i >= 100 && i < 1000) i += 10;
		if (i >= 10 && i < 100) i += 5;
		if (i < 10) ++i;
	}
	measurements.close();
}

template<typename X>
void fill_rand(X *arr, X &size)//Заполнение массива рандомными числами
{
	register X i = 0;
	for (; i < size; ++i)
	{
		*arr++ = rand();
	}
	return;
}

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
	
	case 5: 
		START_TIMER;//Сортировка слиянием
		merge_sort(numbers, &numbers[arr_size]);
		STOP_TIMER("Merge sort", time);
		break;

	default:
		cout << "You've done smthng wrong, try again!" << endl;
		return -1;
	}

	return time;
}
