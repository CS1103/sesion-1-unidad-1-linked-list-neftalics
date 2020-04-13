//
//  LinkedList.hpp
//  LinkendList
//
//  Created by neftali calixto on 4/11/20.
//  Copyright © 2020 neftali calixto. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
namespace utec{
    struct node
    {
        int value_=0;
        node* next_=nullptr;
    };
    inline namespace first{
        class LinkedList{
        private:
            node* head_=nullptr;
            node* tail_=nullptr;
            size_t size_=0;
        public:
            LinkedList() = default;
            LinkedList(size_t value);
            LinkedList(const LinkedList& other);
            LinkedList &operator =(const LinkedList& other);
            LinkedList(LinkedList&& other);
            LinkedList &operator =(LinkedList&& other);
            
            //destruct
            ~LinkedList();
            
            //add
            void push_front(int value);
            void push_back(int value);
            void insert(size_t index , int value);
            //remove
            void pop_front();
            void pop_back();
            void erase(size_t index);
            //traversal operations
            int& item(size_t index);
            const int& item(size_t index) const;
            //get size of list
            size_t size() const;
        };
    }
}
#endif /* LinkedList_hpp */
