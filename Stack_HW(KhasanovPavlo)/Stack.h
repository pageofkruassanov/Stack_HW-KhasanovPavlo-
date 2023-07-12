#pragma once
#include <iostream>
#include <string>
using namespace std;
namespace MyStack {
	class Stack
	{
		char* str;
		unsigned int maxSize;
		int size;
	public:
		Stack() = delete;
		Stack(unsigned int maxSize);
		~Stack();
		void push(char symb);
		void pop();
		char& top();
		bool empty() const;
		int current_s();

	};
}

