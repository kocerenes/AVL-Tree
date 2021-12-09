#include "NodeOfStack.hpp"

//parametre olarak yıgıta eklemek için int deger ve next dugumu alan Constructor
sNode::sNode(const int &data, sNode *next){
    this->data = data;
    this->next = next;
}