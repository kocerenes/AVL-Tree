#ifndef NODE_HPP
#define NODE_HPP

#include "Person.hpp"
#include "Stack.hpp"

class Node{
	private:
		Person person; //dugumumde person bulunmalı
		Node* Left;
		Node* Right;
		int Height;
		int Depth;
		Stack HeightOfNode; // yüksekliği tutucağımız stack
		Stack DepthOfNode; //Derinliği tutucağımız stack

	public:
		Node(Person); //parametresine sadece person alan constructor
		friend class AVLTree; //Node classımdaki private alanları kullanabilmek için friend tanımladım
};

#endif