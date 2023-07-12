#include "Stack.h"
using namespace MyStack;
Stack::Stack(unsigned int maxSize)
{
	this->maxSize = maxSize;
	str = new char[maxSize + 1];
	size = -1;
}

Stack::~Stack()
{
	delete[] str;
}

void Stack::push(char symb)
{
	if (size == maxSize - 1) {
		throw exception("Stack overflow");
	}
	str[++size] = symb;
}

void Stack::pop()
{
	if (size < 0) {
		throw exception("Stack empty");
	}
	--size;
}

char& Stack::top()
{
	if (size < 0) {
		throw exception("Stack empty");
	}
	return str[size];
}

bool Stack::empty() const
{
	return size < 0;
}

int Stack::current_s()
{
	return size + 1;
}
