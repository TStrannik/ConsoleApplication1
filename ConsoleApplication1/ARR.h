#include "sugar.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>



struct ARR {

    ARR()           { _fill_zero();         }
    ARR(int length) { _fill_random(length); }
    ARR(ARR& othr)  { _fill_from(othr);     }
    ~ARR() noexcept { destruct();           }  

    ARR& operator =  (ARR& othr);
    void operator += (int next);
    ARR  operator +  (ARR& othr);
    void operator -  (int del);
    bool operator == (ARR& other);

    void         destruct();
    void         reset();
    void         print();
    void         info();
    unsigned int get_size();
    unsigned int get_counter();
    int          search_pos(int);
    void         search_set(int);

private:
    int*         _ar;
    unsigned int _id = 0;
    static int   _max_id;
    static int   _counter;
    std::string  _name = "Array";
    unsigned int _length;

    void         _fill_zero();
    void         _fill_random(unsigned int);
    void         _fill_from(ARR&);

};