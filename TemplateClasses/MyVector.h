#pragma once
#include <initializer_list>
#include <cstdlib>

template<class T>
class MyVector
{
public:
	T * data;
	size_t size;
	MyVector()
	{
		data = nullptr;
		size = 0;
	}

	MyVector(std::initializer_list<T> elements)
	{
		for (T element : elements) 
		{
			this->push_back(element);
		}
	}

	size_t count() const
	{
		return size;
	}

	void push_back(const T & element)
	{
		if (nullptr == data)
		{
			data = new T[++size];
			data[0] = element;
		}
		else
		{
			data = (T*)realloc(data, ++size * sizeof(T));
			data[size - 1] = element;
		}
	}

	void pop_back()
	{
		if (nullptr != data)
		{
			data = (T*)realloc(data, --size * sizeof(T));
		}
	}
	//Pass the index of removing element
	void erase(const int index)
	{
		T * data_temple = new T[size-1];
		for (int i = 0, j = 0; i < size; i++)
		{
			if (i != index)
			{
				data_temple[j] = data[i];
				j++;
			}
		}
		size--;
		data = data_temple;
	}

	T & operator [](const int & pos)
	{
		return data[pos];
	}

	void operator += (const T & element)
	{
		push_back(element);
	}

	void operator += (MyVector & OtherVector)
	{
		for (int i = 0; i < OtherVector.count(); i++)
		{
			push_back(OtherVector[i]);
		}
	}

	void operator = (MyVector & OtherVector)
	{
		size = OtherVector.count();
		data = new T[size];
		for (int i = 0; i < OtherVector.count(); i++)
		{
			data[i] = OtherVector[i];
		}
	}

	void clear()
	{
		delete[] data;
	}

	~MyVector()
	{
		clear();
	}
};

