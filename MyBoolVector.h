#pragma once
#pragma once
#include <stdio.h>
#include <algorithm>
#include <cassert>

class MyBoolVector {
public:
	MyBoolVector() :data(nullptr), capacity(0), used(0) {};

	MyBoolVector(const MyBoolVector& v);
	~MyBoolVector();
	MyBoolVector& operator =(const MyBoolVector& v);

	void operator +=(const MyBoolVector& addend);
	bool operator[](size_t index) const;
	friend MyBoolVector& operator +(const MyBoolVector& v1, const MyBoolVector& v2);
	MyBoolVector& operator-(const MyBoolVector& v);
	friend bool operator==(const MyBoolVector& v1, const MyBoolVector& v2);

	size_t size() const;
	size_t capa() const;

	void pop_back();
	void push_back(bool x);

	void reserve(size_t n);
	bool is_empty() const;
	void clear();

private:
	bool* data;
	int used;
	int capacity;
};

