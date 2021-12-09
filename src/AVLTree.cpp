#include "AVLTree.hpp"

//PRIVATE//
Node* AVLTree::AraveEkle(Node *alt_Dugum,const Person& newPerson)
{
	// alt_Dugum = z, alt_Dugum->Left = y, yeni = x,w
	if (alt_Dugum == NULL)
	{
		alt_Dugum = new Node(newPerson);
	}
	else if (newPerson.BodyHeight < alt_Dugum->person.BodyHeight) // y, z'nin Left çocuğu ise
	{
		alt_Dugum->Left = AraveEkle(alt_Dugum->Left, newPerson);

		if (Height(alt_Dugum->Left) - Height(alt_Dugum->Right) == 2)
		{
			// Left Left Durumu
			if (newPerson.BodyHeight < alt_Dugum->Left->person.BodyHeight) // x, y'nin Left çocuğu ise
				alt_Dugum = LeftCocukIleDegistir(alt_Dugum); //sağa dönüş z
			else											// Left Sağ Durumu
			{
				alt_Dugum->Left = RightCocukIleDegistir(alt_Dugum->Left); // Lefta dönüş y
				alt_Dugum = LeftCocukIleDegistir(alt_Dugum); // sağa dönüş z
			}
		}
	}
	else if (newPerson.BodyHeight > alt_Dugum->person.BodyHeight)
	{
		alt_Dugum->Right = AraveEkle(alt_Dugum->Right, newPerson);

		if (Height(alt_Dugum->Right) - Height(alt_Dugum->Left) == 2)
		{
			// Sağ Sağ Durumu
			if (newPerson.BodyHeight > alt_Dugum->Right->person.BodyHeight)
				alt_Dugum = RightCocukIleDegistir(alt_Dugum);
			else
			{ // Sağ Left Durumu
				alt_Dugum->Right = LeftCocukIleDegistir(alt_Dugum->Right);
				alt_Dugum = RightCocukIleDegistir(alt_Dugum);
			}
		}
	}
	// boy uzunlugu aynıysa şartı
	else if(newPerson.BodyHeight == alt_Dugum->person.BodyHeight){  
		alt_Dugum->Left = AraveEkle(alt_Dugum->Left,newPerson);
		if (Height(alt_Dugum->Left) - Height(alt_Dugum->Right) == 2)
		{
			// Left Left Durumu
			if (newPerson.BodyHeight == alt_Dugum->Left->person.BodyHeight) // x, y'nin Left çocuğu ise
				alt_Dugum = LeftCocukIleDegistir(alt_Dugum); //sağa dönüş z
			else											// Left Sağ Durumu
			{
				alt_Dugum->Left = RightCocukIleDegistir(alt_Dugum->Left); // Lefta dönüş y
				alt_Dugum = LeftCocukIleDegistir(alt_Dugum);			  // sağa dönüş z
			}
		}
	}
	else
		;
	
	return alt_Dugum;
}


Node* AVLTree::LeftCocukIleDegistir(Node *alt_Dugum) // Sağa dönüş
{
	//swap
	Node *tmp = alt_Dugum->Left;
	alt_Dugum->Left = tmp->Right;
	tmp->Right = alt_Dugum;

	// Yükseklikleri Güncelle
	alt_Dugum->Height = Height(alt_Dugum);
	tmp->Height = max(Height(tmp->Left), alt_Dugum->Height) + 1; // Bir düğümün yüksekliği en yüksek çocuğunun bir fazlasıdır

	return tmp;
}


Node* AVLTree::RightCocukIleDegistir(Node *alt_Dugum) // Sola dönüş
{
	//swap
	Node *tmp = alt_Dugum->Right;
	alt_Dugum->Right = tmp->Left;
	tmp->Left = alt_Dugum;

	// Yükseklikleri Güncelle
	alt_Dugum->Height = Height(alt_Dugum);
	tmp->Height = max(Height(tmp->Right), alt_Dugum->Height) + 1;

	return tmp;
}

// ağacı postorder yöntemiyle gezerek yükseklikleri güncelleyip yığıta attıgım metodum
void AVLTree::PushToHeightStack(Node *alt_Dugum) const
{
	//parametre olarak verdiğim dugum NULL değilse şartı
	if (alt_Dugum != NULL)
	{
		PushToHeightStack(alt_Dugum->Left); //parametre olarak verdigim dugumun sol cocugunu tekrar metoda parametre olarak verdim
		PushToHeightStack(alt_Dugum->Right); //parametre olarak verdigim dugumun sag cocugunu tekrar metoda parametre olarak verdim

		alt_Dugum->Height = Height(alt_Dugum); //Yüksekliği güncelledim
		alt_Dugum->HeightOfNode.Push(alt_Dugum->Height); //Yüksekliği yığıta ekledim

		alt_Dugum->Depth = Depth(alt_Dugum); //derinliği güncelledim
		alt_Dugum->DepthOfNode.Push(alt_Dugum->Depth); //Derinliği yığıta ekledim
	}
}

void AVLTree::SeviyeyiYazdir(Node *alt_Dugum, int seviye) const
{
	if (alt_Dugum == NULL)
		return;
	if (seviye == 0){
		cout << alt_Dugum->person.GetName() << " "<< alt_Dugum->person.GetAge()<<" "<<alt_Dugum->person.GetBodyHeight();
		cout<<" Y(";
		alt_Dugum->HeightOfNode.Print(); //stackteki yukseklik değerlerimi yazdırdım
		
		cout<<", D(";
		alt_Dugum->DepthOfNode.Print(); //derinligi tutan yıgıtımdaki degerleri yazdırdım
		cout<<"  ";
	}
	else
	{
		SeviyeyiYazdir(alt_Dugum->Left, seviye - 1);
		SeviyeyiYazdir(alt_Dugum->Right, seviye - 1);
	}
}


int AVLTree::Height(Node *childNode) const
{
	if (childNode == NULL)
		return -1; // Ortada düğüm yoksa yükseklik anlamsızdır. Kodun çalışması adına -1 intlmektedir.
	return 1 + max(Height(childNode->Left), Height(childNode->Right));
}

//parametre olarak verilen dugumu silen metod
bool AVLTree::DugumSil(Node *&alt_Dugum)
{
	Node *silinecekDugum = alt_Dugum;

	if (alt_Dugum->Right == NULL)
		alt_Dugum = alt_Dugum->Left;
	else if (alt_Dugum->Left == NULL)
		alt_Dugum = alt_Dugum->Right;
	else
	{
		silinecekDugum = alt_Dugum->Left;
		Node *ebeveynDugum = alt_Dugum;
		while (silinecekDugum->Right != NULL)
		{
			ebeveynDugum = silinecekDugum;
			silinecekDugum = silinecekDugum->Right;
		}
		alt_Dugum->person.BodyHeight = silinecekDugum->person.BodyHeight;
		if (ebeveynDugum == alt_Dugum)
			alt_Dugum->Left = silinecekDugum->Left;
		else
			ebeveynDugum->Right = silinecekDugum->Left;
	}

	delete silinecekDugum; //dugumu sildim
	return true; //true dondurdum
}

//PUBLİC//
//constructor
AVLTree::AVLTree()
{
	this->root = NULL; //baslangicta NULL verdim
	this->temproot = NULL; //baslangicta NULL verdim
}

bool AVLTree::isEmpty() const
{
	return root == NULL;
}

void AVLTree::Add(const Person& yeni)
{
	root = AraveEkle(root, yeni); //AraveEkle metodumdan donen Nodeu roota attım ve agaca yeni Node ekledim
	temproot = root; //temproota eklenmiş ve dengelenmiş olan dugumu verdim
	PushToHeightStack(temproot); //parametre olarak verdigim dugumun yuksekligini guncelleyip yıgıta eklemesi için metod
}

//agacı Level order olarak yazdıran metod
void AVLTree::Levelorder() const
{
	int h = Height();
	cout<<"Level Order: "<<endl;
	for (int level = 0; level <= h; level++){
		SeviyeyiYazdir(root, level);	
	}
}

//düğümleri sildigim metod
void AVLTree::Clear()
{
	//ağaç boş değilse döngüye girdi
	while (!isEmpty()){
		DugumSil(root);
	}
}

//Yüksekliği döndüren public erişim belirteçli metodum
int AVLTree::Height() const
{
	return Height(root);
}

// parametre olarak aldıgı düğümün derinliğini döndüren metod
int AVLTree::Depth(Node* node)const{
	//düğüm boşsa
	if (node == NULL)
        return 0;
    else
    {
        // recursive yapıda alt ağaçların derinliğini hesapladım
        int leftDepth = Depth(node->Left);
        int rightDepth = Depth(node->Right);
     
        //derinlik karşılaştırması
        if (leftDepth > rightDepth)
            return(leftDepth +1);
        else return(rightDepth+1);
    }
}

//Destructor metod
AVLTree::~AVLTree()
{
	root->HeightOfNode.Clear(); //yüksekliklerin tutuldugu yığıtımı bellekten temizledim 
	root->DepthOfNode.Clear(); //derinliklerin tutuldugu yığıtımı bellekten temizledim
	Clear();
}
