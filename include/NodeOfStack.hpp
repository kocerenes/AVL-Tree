#ifndef NODEOFSTACK_HPP
#define NODEOFSTACK_HPP

class sNode{
    private:
        int data;
        sNode *next;
    public:
        sNode(const int&, sNode*); //Constructor
        friend class Stack; //private alanları Stack sınıfımda kullanabilmek için friend tanımladım
};

#endif