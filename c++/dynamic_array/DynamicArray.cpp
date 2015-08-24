#include <iostream>
#include <cstring>
#include <exception>

using namespace std;

class DynamicArray{
private:
	int size;		//size of the real data
	int capacity;	//size of the storage
	int *storage;	//dynamically allocated space to store data
public:
	DynamicArray(){
		capacity = 10;
		size = 0;
		storage = new int[capacity];
	}
	DynamicArray(int capacity){
		this->capacity = capacity;
		size = 0;
		storage = new int[capacity];
	}

	void setCapacity(int newCapacity);
	void ensureCapacity(int minCapacity);
	void pack();
	void trim();	

	void rangeCheck(int index);
	void set(int index, int value);
	int get(int index);
	void removeAt(int index);
	void insertAt(int index, int value);

	~DynamicArray(){
		delete[] storage;
	}
};


void setCapacity(int newCapacity){
	int *newStorage = new int[newCapacity];
	memcpy(newStorage, storage, sizeof(int)*size);
	capacity = newCapacity;
	delete[] storage;
	storage = newStorage;
}

void ensureCapacity(int minCapacity){
	if(minCapacity > capacity){
		int newCapacity = (capacity*3)/2+1;
		if(newCapacity < minCapacity){
			newCapacity = minCapacity;
		}
		setCapacity(newCapacity);
	}
}

void DynamicArray::pack(){
	if(size <= capacity/2){
		int newCapacity = (size*3)/2+1;
		setCapacity(newCapacity);
	}
}

void DynamicArray::trim(){
	int newCapacity = size;
	setCapacity(newCapacity);
}

void DynamicArray::rangeCheck(int index){
	if(index < 0 || index >= size){
		throw "Index out of bounds!";
	}
}

void DynamicArray::set(int index, int value){
	rangeCheck(index);
	storage[index] = value;
}

int DynamicArray::get(int index){
	rangeCheck(index);
	return storage[index];
}

/*
 * Prototype: void *memmove(void *dest, const *src, size_t count)
 * Function: copy count bytes from src to dest
 */
void DynamicArray::removeAt(int index){
	rangeCheck(index);
	int moveCount = size-index-1;
	if(moveCount > 0){
		memmove(storage+index, storage+(index+1), sizeof(int)*moveCount);
	}
	--size;
	pack();
}

void DynamicArray::insertAt(int index, int value){
	if(index < 0 || index >size){
		throw "Index out of bounts";
	}
	ensureCapacity(size+1);
	int moveCount = size-index;
	if(moveCount != 0){
		memmove(storage+index+1, storage+index, sizeof(int)*moveCount);
	}
	storage[index] = value;
	++size;
}




