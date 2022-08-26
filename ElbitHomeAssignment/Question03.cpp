//	without using STL containers implement the following:
//	A class for a dynamic int array, let's call it "CVectorInt" that -
//  1. doubles its size automatically when its full (allocates twice the size and moves the data),
//	2. halves its size when it is half empty (allocates half of the size and moves the data)
//  3. can be told the initial capacity (num of ints) in a constructor
//  4. have a method called "reserve" - that Requests that the vector capacity be at least enough to contain n elements.
//     If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n
//  5. have a method called "capacity" - that returns the number of int elements allocated
//  6. have a method called "size" - that returns the number of elements actually inserted
//  7. have a method called "empty" - that returns true/false according to amount of actual elements in the data
//  8. have a method called "clear" - that frees all the data and resets the size
//  9. have a method called "push_back" - that adds an int elements at the end
// 10. have a method called "pop_back" - that removes an int elements at the end and return it
// 11. have a method called "remove"  - that removes an int elements at specific index
// 12. have an interface to access the data at a specific index using subscript "[]"
//
// make sure to handle edge cases such as memory issues, size issues etc.


#include <iostream>
#include <stdexcept>
#include <vector>



class CVectorInt
{
protected:

	// TODO: your code here
private:
	int vector_capacity, vector_size;
	int* array;
public:
	CVectorInt()
	{
		vector_size = 0;
		vector_capacity = 1;
		array = new int[1];
	}

	CVectorInt(int capacity)
	{
		this->vector_capacity = capacity;
		array = new int[1];
		vector_size = 0;
	}

	int& operator[](int index)
	{
		return array[index];
	}

	void setCapacity(int new_capacity)
	{
		vector_capacity = new_capacity;
	}

	int size_array()
	{
		return sizeof(*array) / sizeof(array[0]);
	}

	int* getArrray()
	{
		return array;
	}

	int capacity()
	{
		return this->vector_capacity;
	}

	int size()
	{
		return vector_size;
	}

	void push_back(int element) {
		if (vector_capacity == vector_size)
			doubleVector();
		int result= sizeof(*array) / sizeof(*array);
		array[vector_size] = element;
		result = sizeof(*array) / sizeof(array[0]);
		++vector_size;
	}
	void doubleVector()
	{
		std::vector<int> temp(vector_size * 2);
		for (int i = 0; i < vector_size; i++) {
			temp[i] = array[i];
		}

		for (int i = 0; i < vector_size; i++)
			array[i] = temp[i];

		vector_capacity = vector_capacity * 2;
	}
	bool empty()
	{
		if (vector_size == 0)
			return true;
		return false;
	}
	CVectorInt pop_back()
	{
		if (empty())
			std::cout << "the array is empty: " << std::endl;
		else
		{
			array[vector_size - 1] = INT_MIN;
			vector_size -= 1;
			if (vector_size == vector_capacity / 2)
				half_size();
		}
		return *array;
	}
	void half_size()
	{
		if (vector_size == vector_capacity / 2)
		{
			std::vector<int> temp(vector_capacity / 2);
			for (int i = 0; i < vector_size; ++i)
			{
				temp[i] = array[i];
			}
			vector_capacity /= 2;
			for (int i = 0; i < vector_size; i++)
				array[i] = temp[i];
		}
	}
	void reserve(int new_capacity)
	{
		if (new_capacity > vector_capacity)
			vector_capacity = new_capacity;
	}
	void clear()
	{
		while (vector_size != 0)
		{
			pop_back();
		}
	}

	~CVectorInt()
	{
		delete[]array;

	}
};

int main(int argc, char* argv[])
{
	// some code to use the class
	try
	{
		CVectorInt v(5);

		for (int i = 0; i < 5; i++)
		{
			v.push_back(i);
		}
		std::cout << "the size is: " << v.size() << std::endl;
		std::cout << "the capacity is: " << v.capacity() << std::endl;
		v.push_back(1);
		std::cout << "the size is: " << v.size() << std::endl;
		std::cout << "the capacity is: " << v.capacity() << std::endl;
		while (!v.empty())
		{
			v.pop_back();
		}
		std::cout << "the size is: " << v.size() << std::endl;
		std::cout << "the capacity is: " << v.capacity() << std::endl;
		v.reserve(15);
		std::cout << "the size is: " << v.size() << std::endl;
		std::cout << "the capacity is: " << v.capacity() << std::endl;
		for (int i = 0; i < 15; i++)
		{
			v.push_back(i);
		}
		v[5] = 3;
		for (int i = 0; i < v.size(); i++)
		{
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
		v.clear();
		std::cout << "the size is: " << v.size() << std::endl;
		std::cout << "the capacity is: " << v.capacity() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}