#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include "NodeOfStack.hpp"
using namespace std;

class Stack{
	private:
		sNode* head;
		int lengthOfStack; //yıgıt boyutu
	public:
		Stack();
		bool IsEmpty() const;
		void Push(const int &obj); //ekleme
		void Pop();
		void Print(); //yazdirma
		void Clear();
		~Stack(); //Destructor
};
#endif