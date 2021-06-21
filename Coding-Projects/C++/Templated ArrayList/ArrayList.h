#pragma once

template <class T>
class ArrayList
{
private:
	// Attributes
	const static int DEFAULT_SIZE = 5;
	T* list;
	int count;
	int capacity;

public:
	// Constructors
	ArrayList(void)
	{
		this->list = new T[DEFAULT_SIZE];
		this->capacity = DEFAULT_SIZE;
		this->count = 0;
	}

	ArrayList(int initialCapacity)
	{
		this->list = new T[initialCapacity];
		this->capacity = initialCapacity;
		this->count = 0;
	}

	// Destructor
	~ArrayList(void)
	{
		// Delete Array Pointer
		if (this->list != nullptr)
		{
			delete[] this->list;
			this->list = nullptr;
		}
	}

	// Behaviors
	bool isEmpty(void)
	{
		return count == 0;
	}

	T get(int position)
	{
		if (position < count)
			return list[position];
		else
			return NULL;
	}

	void add(T data)
	{
		// If array is full double size
		if (count == capacity)
		{
			capacity = 2 * capacity;
			T* temp = new T[capacity];

			// Copy items from current array to bigger array
			for (int i = 0; i < count; i++)
			{
				temp[i] = list[i];
			}

			// Delete the Current array
			delete[] list;

			// Rename the bigger Array to List
			list = temp;
		}

		// Add the data item to the array
		list[count] = data;

		// Increment count
		count++;
	}

	/// Remove item at the given position
	void removeAt(int position)
	{
		for (int i = 0; i < position; i++)
		{
			list[i] = list[i + 1];
		}

		// Decrease the Count
		count--;
	}

	/// Get the count of item in ArrayList
	int getCount(void)
	{
		return count;
	}

	/// Get the ArrayList current capacity
	int getCapacity()
	{
		return capacity;
	}
};