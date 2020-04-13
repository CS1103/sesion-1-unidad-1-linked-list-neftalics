//
//  main.cpp
//  LinkendList
//
//  Created by neftali calixto on 4/11/20.
//  Copyright © 2020 neftali calixto. All rights reserved.
//

#include <iostream>
using namespace std;

//add
//push back, push front, insert
//delete
//pop back, pop front, erase
//travese
//item(index) item(1)=10->escritura    lvalue
//            cout<< item(i)->lectura  Rvalue



#include <iostream>
#include "LinkedList.hpp"
#include <cassert>
#include <string>


using namespace std;

int main() {

    utec::LinkedList ll;

    // Probar el metodo push_front;
    for(int i = 0; i < 10; ++i) {
        ll.push_front(i);
    }

    // Verifico el tamano
    assert(ll.size() == 10);

    string result;
    for (int i = 0; i < 10; ++i) {
        result += to_string(ll.item(i)) + " ";
    }
    assert(result == "9 8 7 6 5 4 3 2 1 0 ");

    
//    for(int i = 0; i < 10; ++i) {
//        ll.erase(i);
//    }
//    // Verifico el tamano
//    assert(ll.size() == 0);
 
    // pop_front
    // Probar el metodo push_front;
    for(int i = 0; i < 5; ++i) {
        ll.pop_front();
    }
    // Verifico el tamano
    assert(ll.size() == 5);
    

    
    
    // Probar el metodo push_front;
    for(int i = 0; i < 5; ++i) {
        ll.pop_back();
    }
    // Verifico el tamano
    assert(ll.size() == 0);
    
    ll.insert(0, 3);
    assert(ll.size() == 1);
    string result2;
    for (int i = 0; i < 1; ++i) {
        result2 += to_string(ll.item(i)) + " ";
    }
    assert(result2 == "3 ");
    

    
    utec::LinkedList l1;

    // Probar el metodo push_front;
    for(int i = 0; i < 10; ++i) {
        l1.push_back(i);
    }

    // Verifico el tamano
    assert(l1.size() == 10);

    string result1;
    for (int i = 0; i < 10; ++i) {
        result1 += to_string(l1.item(i)) + " ";
    }
    assert(result1 == "0 1 2 3 4 5 6 7 8 9 ");




    std::cout << "Ejecucion exitosa!!" << std::endl;
    return 0;
}

