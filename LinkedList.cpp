    //
    //  LinkedList.cpp
    //  LinkendList
    //
    //  Created by neftali calixto on 4/11/20.
    //  Copyright © 2020 neftali calixto. All rights reserved.
    //

#include "LinkedList.hpp"


utec::first::LinkedList::LinkedList(size_t value):size_(value){}
utec::first::LinkedList::LinkedList(const utec::LinkedList& other):head_(other.head_),tail_(other.tail_),size_(other.size_){}
utec::LinkedList &utec::first::LinkedList::operator =(const utec::LinkedList& other){
    
    size_=other.size_;
    head_=other.head_;
    tail_=other.tail_;
    
    return *this;
    
}
utec::first::LinkedList::LinkedList(LinkedList&& other){}
utec::LinkedList &utec::first::LinkedList::operator =(LinkedList&& other){return * this;}

utec::first::LinkedList::~LinkedList(){
    for(size_t i=0 ; i<size_ ; ++i){
        pop_front();
    }
}
//add
void utec::first::LinkedList::push_front(int value){
    
    head_=new node{value, head_};
    if (tail_==nullptr) tail_=head_;
    size_++;
    
}

void utec::first::LinkedList::push_back(int value){

    if (size_==0)
    {
        tail_=new node{value, nullptr};
        head_=tail_;
    }
    else
    {
        auto temp=tail_;
        
        tail_=new node{value, nullptr};
        
        temp->next_=tail_;
    }
    size_++;

}

void utec::first::LinkedList::insert(size_t index , int value){
    if (size_==0) {
        tail_=new node{value, nullptr};
        head_=tail_;
    }
//    if(index==size_)
//        push_back(value);
    
    else{
        node* temp=head_;
        while(temp->next_ != nullptr){
            temp=temp->next_;
        }
    
        node* m_nodo = new node{value , temp->next_};
        temp->next_ = m_nodo;
    }
    size_++;
}

//remove
    
void utec::first::LinkedList::pop_front(){
    if (head_==tail_){
        delete head_;
        head_=tail_=nullptr;
        size_=0;
    }
    else {
        auto next = head_->next_;
        delete head_;
        head_=next;
        size_--;
    }
}
    
void utec::first::LinkedList::pop_back(){
    if (size_==1){
        delete tail_;
        tail_=head_=NULL;
        size_=0;
    }
    else{
        //recorro hasta 2 antes
        auto temp = head_;
        while (temp->next_->next_ != nullptr) {
            temp = temp->next_;
        }
        
        tail_ = temp;
        delete tail_->next_;
        tail_->next_ = nullptr;
        --size_;
    }
    
}
void utec::first::LinkedList::erase(size_t index){
    if (tail_==head_){
        delete tail_;
        tail_=head_=nullptr;
    }
    if (index==0){
        pop_front();
    }
    if (index==size_--) {
        pop_back();
    }
    else{
        auto temp = head_;
        while (index-2) {
            temp = temp->next_;
        }
        
        auto tempL = head_;
        while (index--) {
            tempL=tempL->next_;
        }
        
        auto tempR = head_;
        while (index++) {
            tempR=tempR->next_;
        }
        
        //borro tail-
        delete temp;
        tempL->next_=tempR;
    }
        size_--;
}
//traversal operations
int& utec::first::LinkedList::item(size_t index){

    auto actual = head_;
    while (index--){
        actual = actual->next_;
    }
    return actual->value_;
    
}
const int& utec::first::LinkedList::item(size_t index) const{
    auto actual = head_;
    while (index--)
        actual = actual->next_;
    return actual->value_;
}
//get size of list
size_t utec::first::LinkedList::size() const{return size_;}
