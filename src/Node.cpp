#include "Node.hpp"

// parametresine sadece person alan constructor
Node::Node(Person person){
    this->person = person;
    this->Left = NULL;
    this->Right = NULL;
    this->Height = 0; //Eklenen her yeni düğüm ilk önce yaprak olarak eklenir bu yüzden 0 verdik
    this->Depth = 0;
}