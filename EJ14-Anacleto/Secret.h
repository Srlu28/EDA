#ifndef Secret_h
#define Secret_h

#include <iostream>
using namespace std;
#include "Dequeue.h"
#include "Stack_eda.h"

const char Vowels[10] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

template <class T>

class _0069 : public deque<T>{
	using Nodo = typename deque<T>::Nodo;
public:
	_0069 reorder(string s) {
		_0069 ret;

		for (long unsigned int i = 0; i < s.size(); i += 2)
			ret.push_back(s.at(i));
		for (long int i = s.size() - 1 - (s.size() % 2); i > 0; i -= 2)
			ret.push_back(s.at(i));

		_0069<char> ret1;
		stack<char> c_Stack;
		int n = ret.nelems;
		char c;
		for (int i = 0; i < n; ++i) {
			c = ret.front();
			ret.pop_front();

			if (isVowel(c)) {
				while (!c_Stack.empty()) {
					ret1.push_back(c_Stack.top());
					c_Stack.pop();
				}
				ret1.push_back(c);
			}
			else c_Stack.push(c);
		}
		while (!c_Stack.empty()) {
			ret1.push_back(c_Stack.top());
			c_Stack.pop();
		}
		ret.copia(ret1);
		return ret;
	}

	void print(ostream& output = cout) const {
		Nodo* aux = this->fantasma->sig;
		while (aux != this->fantasma) {
			output << aux->elem;
			aux = aux->sig;
		}
		output << '\n';
	}
private:
	bool isVowel(char c)
	{
		for (int i = 0; i < 10; i++)
		{
			if (c == Vowels[i])return true;
		}
		return false;
	}
};

template <class T>
inline ostream& operator<<(ostream& out, _0069<T> const l) {
	l.print(out);
	return out;
}

#endif