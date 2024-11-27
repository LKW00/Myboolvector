#include "MyBoolVector.h"
#include <algorithm>
#include <cassert>
#include <stdlib.h>

using namespace std;

MyBoolVector::~MyBoolVector() {
	delete[] data;
}
MyBoolVector::MyBoolVector(const MyBoolVector& v) {
	data = new bool[v.capacity];
	capacity = v.capacity;
	used = v.used;
	copy(v.data, v.data + used, data);
}
MyBoolVector& MyBoolVector::operator =(const MyBoolVector& v) {
	if (this == &v)
		return *this;
	if (capacity != v.capacity)
	{
		delete[] data;
		data = new bool[v.capacity];
		capacity = v.capacity;
	}
	used = v.used;
	copy(v.data, v.data + used, data);
	return *this;
}
void MyBoolVector::operator +=(const MyBoolVector& addend)
{
	if (used + addend.used > capacity)
		reserve(used + addend.used);
	copy(addend.data, addend.data + addend.used, data + used);
	used += addend.used;
}
bool MyBoolVector::operator[](size_t index) const
{
	if (index < 0 || index >= size())
		perror("Index out of range"); exit(1);

	return data[index];
}
size_t MyBoolVector::size() const
{
	return used;
}
size_t MyBoolVector::capa() const
{
	return capacity;
}
MyBoolVector& MyBoolVector:: operator-(const MyBoolVector& v) {
	MyBoolVector v1;
	for (int i = 0;i < v.size();i++) {
		v1.push_back(~v.data[i]); //비트바꾸기(1의보수)
	}
	return v1;
}
MyBoolVector& operator +(const MyBoolVector& v1, const MyBoolVector& v2)
{
	assert(v1.used == v2.used);

	MyBoolVector m;
	for (int i = 0;i < v1.size();i++) {
		m.push_back(v1.data[i] ^ v2.data[i]);
	}
	return m;
}
bool operator ==(const MyBoolVector& v, const MyBoolVector& v1)
{
	assert(v.size() == v1.size());
	for (int i = 0;i < v.size();i++) {
		if (v.data[i] != v1.data[i])
			return false;
	}
	return true;
}
void MyBoolVector::push_back(bool d)
{
	if (used == 0)
		reserve(8);
	else if (used == capacity)
		reserve(2 * used);

	data[used] = d;
	++used;
}
void MyBoolVector::reserve(size_t n)
{
	bool* larger_array;
	if (n == capacity)
		return;
	if (n < used)
		n = used;
	larger_array = new bool[n];
	copy(data, data + used, larger_array);
	delete[] data;
	data = larger_array;
	capacity = n;

}
bool MyBoolVector::is_empty() const {
	if (used == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
void MyBoolVector::clear() {
	for (int i = 0; i < used;i++) {
		data[i] = NULL;
	}
	used = 0;
}
void MyBoolVector::pop_back() {
	delete& data[used - 1];
	--used;
	--capacity;
}