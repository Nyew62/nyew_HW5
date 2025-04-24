#ifndef NYEW_HW5_Q1_MYLIST_H
#define NYEW_HW5_Q1_MYLIST_H
#include <iostream>
using namespace std;
template <class A>
class MyList;

template <class A>
class Node{
    friend class MyList<A>;
    public:
    Node(const A& theData, Node<A>* theLink = nullptr):
    data(theData), link(theLink){}
private:
    A data;
Node<A>* link;
};

template <class A>
class MyList{
public:
    MyList():head(nullptr){}
    ~MyList();

    void insertHead(const A& theData);
    A deleteHead();
    bool search(const A& target);
    void display();
private:
    Node<A>* head;
};

//destruct
 template <class A>
 MyList<A>::~MyList(){
     while(head !=nullptr){
         Node<A>* temp=head;
         head= head->link;
         delete temp;
     }
 }

 template<class A>
 void MyList<A>::insertHead(const A &theData) {
     head= new Node<A>(theData, head);
 }

 template<class A>
 A MyList<A>::deleteHead() {
     if(head == nullptr)
         A data=head->data;
     Node<A>* temp=head;
     head=head->link;
     delete temp;
     return data;
 }

 template<class A>
 bool MyList<A>::search(const A &target) {
     Node<A>* current=head;
     while(current !=nullptr){
         if(current->data ==target)
             return true;
         current=current->link;
     }
     return false;
 }

 template<class A>
 void MyList<A>::display(){
     Node<A>* current=head;
     while(current !=nullptr){
         cout<< current->data <<endl;
         current=current->link;
     }
 }

#endif //NYEW_HW5_Q1_MYLIST_H
