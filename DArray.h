#ifndef DARRAY_H
#define DARRAY_H
#include <iostream>


class DArray {
private:
	std::string *arr;
	int capacity;
	int numOfElements;
public:
	DArray();
	DArray(int newCapacity);
	~DArray();
	
	void addElement(const std::string &newElement);
	int getNumOfElements() const;
	int getCapacity() const;
	
	void replaceElementAt(const std::string &newElement,int idx);
	bool compareArrays(const DArray &otherArray) const;
	bool isSorted() const;
	int findElement(const std::string &key) const;
	bool removeElement(const std::string &key);
	
    // The Big Three
	DArray(const DArray &otherArray);
	DArray& operator=(const DArray &rightside); // OVERLOAD ASSIGNMENT
	DArray& operator+=(const DArray &right);
	
	friend std::ostream& operator << (std::ostream &out,const DArray &myArray);
	
	
};
#endif //const
