#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class String
{
	char* buffer = nullptr;
	size_t _size = 0;
	static int _count;

	static size_t strLen(const char* str) {
		size_t len = 0;
		while (str[len] != '\0') len++;
		return len;
	}

	static void strCopy(char* dest, const char* src, size_t len) {
		for (size_t i = 0; i < len; i++)
			dest[i] = src[i];
		dest[len] = '\0';
	}

public:
	String()
		: _size{ 80 }
	{
		buffer = new char[_size + 1];
		buffer[0] = '\0';
		_count++;
	}

	String(size_t size)
		: _size{ size }
	{
		buffer = new char[_size + 1];
		buffer[0] = '\0';
		_count++;
	}

	String(const char* str)
		: _size{ strLen(str) }
	{
		buffer = new char[_size + 1];
		strCopy(buffer, str, _size);
		_count++;
	}

	String(const String& other)
		: _size{ other._size }
	{
		buffer = new char[_size + 1];
		strCopy(buffer, other.buffer, _size);
		_count++;
	}

	~String() {
		delete[] buffer;
		_count--;
	}

	String& operator=(const String& other) {
		if (this == &other) return *this;
		delete[] buffer;
		_size = other._size;
		buffer = new char[_size + 1];
		strCopy(buffer, other.buffer, _size);
		return *this;
	}

	String& operator=(const char* str) {
		delete[] buffer;
		_size = strLen(str);
		buffer = new char[_size + 1];
		strCopy(buffer, str, _size);
		return *this;
	}

	size_t size() const { return _size; }
	static int count() { return _count; }

	void input() {
		char temp[4096];
		cin.getline(temp, 4096);
		size_t len = strLen(temp);
		if (len > _size) {
			delete[] buffer;
			_size = len;
			buffer = new char[_size + 1];
		}
		strCopy(buffer, temp, len);
	}

	void print() const {
		cout << buffer << endl;
	}

	String concat(const String& obj) const {
		size_t lenA = strLen(buffer);
		size_t lenB = strLen(obj.buffer);
		String result(lenA + lenB);
		strCopy(result.buffer, buffer, lenA);
		for (size_t i = 0; i <= lenB; i++)
			result.buffer[lenA + i] = obj.buffer[i];
		return result;
	}

	String intersect(const String& obj) const {
		size_t lenA = strLen(buffer);
		size_t lenB = strLen(obj.buffer);
		char* temp = new char[lenA + 1];
		size_t k = 0;
		for (size_t i = 0; i < lenA; i++) {
			for (size_t j = 0; j < lenB; j++) {
				if (buffer[i] == obj.buffer[j]) {
					bool already = false;
					for (size_t m = 0; m < k; m++)
						if (temp[m] == buffer[i]) { already = true; break; }
					if (!already) temp[k++] = buffer[i];
					break;
				}
			}
		}
		temp[k] = '\0';
		String result(temp);
		delete[] temp;
		return result;
	}

	static int compare(const String& a, const String& b) {
		size_t i = 0;
		while (a.buffer[i] != '\0' && b.buffer[i] != '\0') {
			if (a.buffer[i] < b.buffer[i]) return -1;
			if (a.buffer[i] > b.buffer[i]) return 1;
			i++;
		}
		if (a.buffer[i] == '\0' && b.buffer[i] == '\0') return 0;
		return a.buffer[i] == '\0' ? -1 : 1;
	}

	static void sort(String* arr, size_t n) {
		for (size_t i = 0; i < n - 1; i++)
			for (size_t j = 0; j < n - i - 1; j++)
				if (compare(arr[j], arr[j + 1]) > 0) {
					char* tempBuf = arr[j].buffer;
					size_t tempSize = arr[j]._size;
					arr[j].buffer = arr[j + 1].buffer;
					arr[j]._size = arr[j + 1]._size;
					arr[j + 1].buffer = tempBuf;
					arr[j + 1]._size = tempSize;
				}
	}

	String operator*(const String& other) const {
		return intersect(other);
	}

	String operator/(const String& other) const {
		size_t lenA = strLen(buffer);
		size_t lenB = strLen(other.buffer);
		char* temp = new char[lenA + 1];
		size_t k = 0;
		for (size_t i = 0; i < lenA; i++) {
			bool found = false;
			for (size_t j = 0; j < lenB; j++)
				if (buffer[i] == other.buffer[j]) { found = true; break; }
			if (!found) temp[k++] = buffer[i];
		}
		temp[k] = '\0';
		String result(temp);
		delete[] temp;
		return result;
	}

	String operator+(const String& other) const {
		return concat(other);
	}

	String operator+(const char* str) const {
		String temp(str);
		return concat(temp);
	}

	friend String operator+(const char* str, const String& obj) {
		String temp(str);
		return temp.concat(obj);
	}

	String& operator++() {
		size_t len = strLen(buffer);
		for (size_t i = 0; i < len; i++)
			buffer[i]++;
		return *this;
	}

	String operator++(int) {
		String temp = *this;
		size_t len = strLen(buffer);
		for (size_t i = 0; i < len; i++)
			buffer[i]++;
		return temp;
	}

	String operator!() const {
		size_t len = strLen(buffer);
		String result(len);
		for (size_t i = 0; i < len; i++)
			result.buffer[i] = buffer[len - 1 - i];
		result.buffer[len] = '\0';
		return result;
	}

	bool operator==(const String& other) const { return compare(*this, other) == 0; }
	bool operator!=(const String& other) const { return compare(*this, other) != 0; }
	bool operator< (const String& other) const { return compare(*this, other) < 0; }
	bool operator> (const String& other) const { return compare(*this, other) > 0; }
	bool operator<=(const String& other) const { return compare(*this, other) <= 0; }
	bool operator>=(const String& other) const { return compare(*this, other) >= 0; }
};

int String::_count = 0;