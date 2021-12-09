#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
using namespace std;

class Person{
	private:
		string Name;
        int Age;
	    int BodyHeight;
	public:
        Person(); //boş constructor
        Person(string,int,int); //parametreli constructor

        /*Yazdirma islemlerimde kullanmak için Get metodlarım*/
        string GetName();
        int GetAge();
        int GetBodyHeight();
        friend class AVLTree; //Kisinin özelliklerine erisebilmek için AVLTree sınıfımı friend tanımladım
};

#endif