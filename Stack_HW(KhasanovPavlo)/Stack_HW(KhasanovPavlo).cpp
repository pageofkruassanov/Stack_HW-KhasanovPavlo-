#include "Stack.h"

enum Symbols {
	brace_o = '{',
	squareBracket_o = '[',
	parenthesis_o = '(',
	brace_c = '}',
	squareBracket_c = ']',
	parenthesis_c = ')',
	semicolon = ';'
};

int main()
{
	int brace = 0;
	int squareBracket = 0;
	int parenthesis = 0;
	int lastIndex = 0;

	/*Stack st1(50);*/
	Stack st2(30);
	/*Stack st3(30);
	char str1[50] = "{(3 + 22) * ((11 - 8) + (1001 - 9)) / [10 - 10]};";*/
	char str2[17] = "[99} + (88 - 4);";
	/*char str3[12] = "99 + 88))};";*/
	/*for (int i = 0; i < 49; i++) {
		st1.push(str1[i]);
	}*/
	for (int i = 0; i < 16; i++) {
		st2.push(str2[i]);
	}
	/*for (int i = 0; i < 11; i++) {
		st3.push(str3[i]);
	}*/

	if (st2.top() != ';')
		cout << "expected a ';', row " << st2.current_s() + 1 << endl;
	else {
		bool isBad = false;
		while (!st2.empty()) {
			switch (st2.top()) {
			case '{': {
				--brace;
				lastIndex = st2.current_s();
				break;
			}
			case '[': {
				--squareBracket;
				lastIndex = st2.current_s();
				break;
			}
			case '(': {
				--parenthesis;
				lastIndex = st2.current_s();
				break;
			}
			case '}': {
				++brace;
				lastIndex = st2.current_s();
				break;
			}
			case ']': {
				++squareBracket;
				lastIndex = st2.current_s();
				break;
			}
			case ')': {
				++parenthesis;
				lastIndex = st2.current_s();
				break;
			}
			}
			if (parenthesis < 0)
			{
				cout << "expected a ')', row " << lastIndex << endl;
				isBad = true;
				break;
			}
			if (squareBracket < 0) {
				cout << "expected a ']', row " << lastIndex << endl;
				isBad = true;
				break;
			}
			if (brace < 0) {
				cout << "expected a '}', row " << lastIndex << endl;
				isBad = true;
				break;
			}
			st2.pop();
		}
		if (parenthesis > 0 && !isBad)
		{
			cout << "expected a '(', row " << lastIndex << endl;
			
		}
		if (squareBracket > 0 && !isBad) {
			cout << "expected a '[', row " << lastIndex << endl;
		}
		if (brace > 0 && !isBad) {
			cout << "expected a '{', row " << lastIndex << endl;
		}
	}
	
	
}
