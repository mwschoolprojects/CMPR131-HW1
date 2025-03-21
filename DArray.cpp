#include <iostream>
#include "DArray.h"
#include <string>
DArray::DArray() {
	capacity = 50;
	numOfElements = 0;
	arr = new std::string[capacity];
}
DArray::DArray(int newCapacity) {
	capacity = newCapacity;
	numOfElements = 0;
	arr = new std::string[capacity];
}
DArray::~DArray() {
	delete [] arr;
}
void DArray::addElement(const std::string &newElement) {
	if (numOfElements < capacity) {
		arr[numOfElements++] = newElement;
	} else {
		std::cout << "PLAYLIST FULL\n"; 
	}
}
int DArray::getNumOfElements() const {
	return numOfElements;
}
int DArray::getCapacity() const {
	return capacity;
}
void DArray::replaceElementAt(const std::string &newElement, int idx) {
	if (idx>=0 && idx < numOfElements) {
		arr[idx]=newElement;
	}
}

bool DArray::compareArrays(const DArray &otherArray) const {
	if (numOfElements!=otherArray.numOfElements)
		return false;
	for (int i=0;i<numOfElements;i++) {
		if (arr[i]!=otherArray.arr[1])
			return false;
	}
	return true;
}

bool DArray::isSorted() const {
	if (numOfElements<=1) return true;
	bool ascending = true,descending=true;
	for (int i=0;i<numOfElements-1;i++) {
		if (arr[i] > arr[i+1]) ascending = false;
		if (arr[i] < arr[i+1]) descending = false;
	}
	return descending || ascending;
}

int DArray::findElement(const std::string &key) const {
	for (int i = 0; i < numOfElements; i++) {
		if (arr[i] == key) return i;
	}
	return -1;
}

bool DArray::removeElement(const std::string &key) {
	int index = findElement(key);
	if (index != -1) {
		for (int i = index; i < numOfElements-1;i++) {
			arr[i] = arr[i+1];
		}
		numOfElements--;
		return true;
	}
	return false;
}

DArray::DArray(const DArray &otherArray) {
	capacity = otherArray.capacity;
	numOfElements = otherArray.numOfElements;
	arr = new std::string [capacity];
	for (int i = 0; i < numOfElements; i++) {
		arr[i] = otherArray.arr[i];
	}
}

DArray& DArray::operator=(const DArray &rightside) {
	if (this != &rightside) {
		delete[] arr;
		capacity = rightside.capacity;
		numOfElements = rightside.numOfElements;
		arr = new std::string[capacity];
		for (int i = 0; i < numOfElements; i++) {
			arr[i] = rightside.arr[i];
		}
	}
	return *this;
}

DArray& DArray::operator+=(const DArray &right) {
	int newSize = numOfElements + right.numOfElements;
	if (newSize > capacity) {
		std::cout << "NOT ENOUGH SPACE TO MERGE PLAYLIST\n";
		return *this;
	}
	for (int i = 0; i < right.numOfElements; i++) {
		arr[numOfElements++] = right.arr[i];
	}
	return *this;
}

std::ostream& operator<<(std::ostream &out, const DArray &myArray) {
	for (int i = 0; i < myArray.numOfElements; i++) {
		out << i + 1 << ". " << myArray.arr[i] << std::endl;
	}
	return out;
}