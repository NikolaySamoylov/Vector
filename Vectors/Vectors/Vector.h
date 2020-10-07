#pragma once

template <class T>

class Vector
{
private:
	T* data;
	size_t vsize;
	size_t vcopacity;
public:
	// конструктор по умолчанию
	Vector()
	{
		data = nullptr;
		size = 0;
		copacity = 0;
	}
	// конструктор с параметром
	Vector(size_t n)
	{
		data = new T[n];
		vsize = n;
		vcopacity = n;
		for (int i = 0; i < n; i++)
			data[i] = 0;
	}
	// конструктор копирования
	Vector(const Vector& v)
	{
		if (data != nullptr)
			delete[] data;
		data = new T[v.vsize];
		size = v.vsize;
		copacity = v.vcopacity;
		for (int i = 0; i < size; i++)
			data[i] = v.data[i];
	}
	// деструктор
	~Vector()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}
	// количество элеметов в векторе
	size_t size()
	{
		return vsize;
	}
	//  количество элементов, которое может содержать вектор до того, как ему потребуется выделить больше места
	size_t copacity()
	{
		return vcopacity;
	}
	// вставка элемента в конец вектора
	void push_back(T Elem)
	{
		if (vsize >= vcopacity)
		{
			vcopacity = 1.3 * vsize;
			T* b = new T[vcopacity];
			for (int i = 0; i < vsize; i++)
				b[i] = data[i];
			if (data != nullptr)
				delete[] data;
			data = b;
		}
		data[vsize + 1] = Elem;
	}
	// удалить последний элемент вектора
	void pop_back()
	{
		vsize--;
	}
	// вставка элемента в начало вектора
	void push_front(const T& Elem)
	{
		T* b = new T[vsize + 1];
		for (int i = 1; i < size + 1; i++)
			b[i] = data[i];
		b[0] = Elem;
		if (data != nullptr)
			delete[] data;
		data = b;
	}
	// изменение размера вектора на заданную величину
	void resize(size_t n)
	{
		T* b = new T[n];
		unsigned int i;
		if (n > vsize)
		{
			for (i = 0; i < vsize; i++)
				b[i] = data[i];
			for (i = vsize; i < n; i++)
				b[i] = 0;
		}
		else
			for (i = 0; i < n; i++)
				b[i] = data[i];
		if (data != nullptr)
			delete[] data;
		data = b;
	}
	// вставка элемента в вектор
	void insert(T Elem, unsigned int index)
	{
		T* b = new T[vsize + 1];
		unsigned int i;
		for (int i = 0; i < index; i++)
			b[i] = data[i];
		b[index] = Elem;
		for (i = index; i < vsize; i++)
			b[i + 1] = data[i];
		if (data != nullptr)
			delete[] data;
		data = b;
	}
	// удаление элемента вектора
	void erase(int index)
	{
		T* b = new T[vsize - 1];
		unsigned int i;
		for (i = 0; i < index; i++)
			b[i] = data[i];
		for (i = index + 1; i < vsize; i++)
			b[i - 1] = data[i];
		if (data != nullptr)
			delete[] data;
		data = b;
	}
	// доступ к элементу вектора
	T operator[](int index)
	{
		return data[index];
	}
//	T& operator[](int index) {}
};

