#include <iostream>

////////////////////////////////////////////////////////////////Вспомогательные алгоритмы////////////////////////////////////////////////////////////

template<typename X>
void print_arr(X *begin, X *end)//Вывод массива на экран
{
	while(begin < end) std::cout << *begin++ << " ";
	std::cout << std::endl;
	return;
}

template<typename X>
void swap(X *a, X *b)//Обмен двух значений
{
	X tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

template<typename X>
X *partition(X *begin, X *end)//Разбиение Ломуто для быстрой сортировки
{
	X *i = begin;

	for (X *j = begin; j < end - 1; ++j)
	{
		if (*j <= *(end - 1))
		{	
			swap(i++, j);
		}
	}
	swap(i, end - 1);
	return i;
}


template<typename X>
void merge(X *l, X *m, X *r)//Слияние двух сортированных массивов
{
	size_t size = r - l;
	X temp_arr[size];
	X *temp_ptr = temp_arr;
	X *l_ptr = l, *m_ptr = m;

	while(l_ptr < m && m_ptr < r)
	{
		if(*l_ptr < *m_ptr) *temp_ptr++ = *l_ptr++;
		else *temp_ptr++ = *m_ptr++;
	}

	while(l_ptr < m) *temp_ptr++ = *l_ptr++;
	while(m_ptr < r) *temp_ptr++ = *m_ptr++;

	temp_ptr = temp_arr;
	while(l < r) *l++ = *temp_ptr++;

	return;

}

////////////////////////////////////////////////////////////////Алгоритмы сортировки////////////////////////////////////////////////////////////////

template<typename X>
void insertion_sort(X *begin, X *end)//Сортировка вставками
{
	X *edge = begin + 1;
	for (; edge < end; ++edge)
	{
		X tmp = *edge;
		X *insert_pos = edge;
		while (insert_pos > begin && tmp < *(insert_pos - 1))
		{
			*insert_pos = *(insert_pos - 1);
			--insert_pos;
		}
		*insert_pos = tmp;
	}
	return;
}

template<typename X>
void selection_sort(X *begin, X *end)//Сортировка выбором
{
	X *min, *curr_elem;

	for (; begin < end; ++begin)
	{
		curr_elem = begin;
		min = curr_elem++;
		for (; curr_elem < end; ++curr_elem)
		{
			if (*min > *curr_elem) min = curr_elem;
		}
		swap(min, begin);
	}
	return;
}

template<typename X>
void bubble_sort(X *begin, X *end)//Сортировка пузырьком
{
	X *sorted_end = end - 1;
	for (X *j = begin; j < end; ++j)
	{
		for (X *i = begin; i< sorted_end; ++i)
		{
			if (*i > *(i + 1)) swap(i, i + 1);
		}
		--sorted_end;
	}
	return;
}

template<typename X>
void quick_sort(X *begin, X *end)//Быстрая сортировка, разбиение Ломуто
{
	if (begin < end)
	{
		X *part_index = partition(begin, end);
		quick_sort(begin, part_index);
		quick_sort(part_index + 1, end);
	}
	return;
}

template<typename X>
void merge_sort(X *begin, X*end)//Сортировка слиянием
{
	if(begin + 1< end)
	{
		size_t middle = (end - begin) / 2;
		merge_sort(begin, begin + middle);
		merge_sort(begin + middle, end);
		merge(begin, begin + middle, end);
	}
	return;	
}


