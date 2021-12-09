#include "Processes.hpp"

//Dosyadan verileri okuyup AVL agacıma eklediğim ve ekleme işlemlerimden sonra level order biçimde yazdırdığım metodum
void Processes::AddToTreeAndWrite()
{
    ifstream file;

    AVLTree* avlTree = new AVLTree(); //Ağaç nesnesi olusturdum

	// Dosyayi actim
	file.open("doc/Kisiler.txt");

	// Girdi almak icin kullandigim degiskenler
	string name;
	int age;
    int height;
    char character;

    while (!file.eof())
    {
        //karakteri aldım
        file >> character;
        // # işaretini görene kadar okutup name değişkenime attım
        while ( character != '#' )
        {
            name = name + character;
            file>>character;
        }

        // iki # arasındaki yaşı değişkenime attıgım döngü
        while ( character != '#' )
        {
            age = age + character;
            file>>character;
        }

        // yas okudum
        file >> age;

        // karakter okudum
        file >> character;
        
        //boy değişkenime boyu attıgım döngü
        while (character != '#')
        {
            height = height + character;
            file >> character;
        }

        // boyu okudum
        file >> height;

        Person person(name,age,height); //Kisi nesnesi olusturdum
        
        avlTree->Add(person); //Avl agacıma person ekledim

        name = ""; //isimleri üst üste yazmasın diye değişkeni boşalttım
    }
    file.close(); //dosyayı kapattım
    avlTree->Levelorder(); //ağacımı levelorder şeklinde yazdırdım
    delete(avlTree); //Ağacımı bellekten sildim
}
