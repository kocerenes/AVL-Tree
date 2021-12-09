#include "Person.hpp"

//boş Person nesnesi oluşturdugumuz kurucu metod
Person::Person(){
    this->Name = "";
    this->Age = 0;
    this->BodyHeight = 0;
}

//persona parametre olarak verilerini verdiğimiz kurucu metod
Person::Person(string name,int age,int bodyheight){
    this->Name = name;
    this->Age = age;
    this->BodyHeight = bodyheight;
}

//kişinin ismini döndüren metod
string Person::GetName(){
    return Name;
}

//kişinin yasini döndüren metod
int Person::GetAge(){
    return Age;
}

//kişinin boyunu döndüren metod
int Person::GetBodyHeight(){
    return BodyHeight;
}


