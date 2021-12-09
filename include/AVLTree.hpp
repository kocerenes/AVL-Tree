#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include "Node.hpp"

class AVLTree{
	private:
		Node *root;
		Node* temproot; //sonradan yükseklikleri güncelleyebilmek için başta rootu tutacak bi node olusturdum
		Node *AraveEkle(Node*,const Person&);
		Node *LeftCocukIleDegistir(Node*); // Sağa dönüş
		Node *RightCocukIleDegistir(Node*); // Left dönüş
		void SeviyeyiYazdir(Node*, int) const;
		void PushToHeightStack(Node*) const; //yuksekligi guncelleyip yigita attigim metod
		int Height(Node*) const;
		bool DugumSil(Node*&);

	public:
		AVLTree(); //constructor
		bool isEmpty() const;
		void Add(const Person&);
		void Levelorder() const;
		void Clear();
		int Height() const;
		int Depth(Node*) const; //verdigim dugumun derinligini donduren metod
		~AVLTree(); //Destructor
};

#endif