#pragma once

#include <iostream>

namespace Engine
{
	template <typename T>
	class List {

	public:
		List<T>() //Default constructor which initializes the list with a size of 0
		{
			m_array = new T[0];
			m_count = 0;
			m_size = 0;
		}

		List<T>(int size) //Constructor with size parameter which initializes list with internal array size of 'size'
		{
			m_array = new T[size]; //Allocated on heap (dynamically allocated array) 
			m_size = size;
			m_count = 0;
		}

		~List<T>()
		{
			delete[] m_array; //'delete[]' instead of 'delete' since this is a dynamically allocated array on the heap
		}

	public:
		//Add function: either adds new element to first empty slot in internal array or, 
		//makes a new internal array, sizeof(T) bigger in size to make room for the new element
		void Add(T& item)
		{
			if (m_count == m_size)
			{
				T* temp = m_array;
				m_size++;
				m_array = new T[m_size];
				std::copy(temp, temp + m_count, m_array);

				m_array[m_count] = item;
				m_count++;
				delete temp;
			}
			else
			{
				m_array[m_count] = item;
				m_count++;
			}
		}

		//Remove Function: Finds the index of referenced item and removes it from the internal array,
		//shrinking the internal array in the process by making it a new array sizeof(T) less in size
		void Remove(T& item)
		{
			int index = FindIndexOfReferencedItem(item);

			if (index == -1)
			{
				std::cout << "Couldn't find referenced item in list" << std::endl;
				return;
			}

			T* temp = m_array;
			m_size--;
			m_array = new T[m_size];

			int j = 0;
			for (size_t i = 0; i < m_count; i++)
			{
				if (i == index)
				{
					j++;
					continue;
				}

				m_array[i - j] = temp[i];
			}

			m_count--;
			delete temp;
		}

		void RemoveAt(int index)
		{
			if (index < 0 || index > m_count)
			{
				std::cout << "Index out of bounds" << std::endl;
				return;
			}

			T* temp = m_array;
			m_size--;
			m_array = new T[m_size];

			int j = 0;
			for (size_t i = 0; i < m_count; i++)
			{
				if (i == index)
				{
					j++;
					continue;
				}

				if (i - j < m_count)
					m_array[i - j] = temp[i];
			}

			m_count--;
			delete temp;
		}

		int Size()
		{
			return m_size;
		}

		int Count()
		{
			return m_count;
		}

	private:

		int FindIndexOfReferencedItem(T& item) //Looks for the referenced item in the internal array and returns the index of said item if it finds it
		{
			for (int i = 0; i < m_count; i++)
			{
				if (m_array[i] == item)
				{
					return i;
					break;
				}
			}

			return -1;
		}

	public:

		T& operator[](int i) //Overload of [] operator which let's us write 'Listname[n]' to access elements of the internal array
		{
			if (i < 0 || i > m_count)
			{
				std::cout << "Index out of bounds" << std::endl;
				return m_array[0];
			}


			return m_array[i];
		}

	private:

		T* m_array;
		int m_count;
		int m_size;

	};
}

