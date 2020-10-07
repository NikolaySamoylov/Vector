// Vectors.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Vector.h"

int main()
{
	Vector<int> v(3);
	v.insert(54, 2);
	std::cout << v.size() << std::endl;
	std::cout << v[2];
	return 0;
}