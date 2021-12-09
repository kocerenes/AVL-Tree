#include "Stack.hpp"

//Constructor
Stack::Stack(){
    this->head = NULL;
    this->lengthOfStack=0; //stack uzunlugumu basta 0 olarak verdim
}

bool Stack::IsEmpty() const
{
    return head == NULL;
}

//ekleme metodum
void Stack::Push(const int &obj)
{
    head = new sNode(obj, head);
    lengthOfStack++; //stack uzunlugumu 1 arttırdım
}

//yıgıta son eklenen elemanı silen metod
void Stack::Pop()
{
    if (IsEmpty())
        return;
    sNode *tmp = head;
    head = head->next;
    delete tmp;
}

//yıgıtı yazdıran metodum
void Stack::Print(){
    sNode* tmp = head; //tmp düğümüme headi verdim

    //eklenen eleman sayısı kadar dönen döngüm
    for (int i = 0; i < lengthOfStack; i++){
        cout<<tmp->data;
        tmp = tmp->next;

        //virgülleri doğru şekilde koymak için döngü açtım 
        //(bu çözümü bulmasaydım parantez içine yazılan son sayıdan sonra sayı gelmemesine rağmen virgül koyuyordu)
        while (tmp!=NULL){
            cout<<",";
            break;
        }
    }
    cout<<")";
}

//yıgıtımın içini bosaltan metod
void Stack::Clear(){
    while (!IsEmpty())
        Pop();
}

//Destructor
Stack::~Stack(){
    Clear();
}
