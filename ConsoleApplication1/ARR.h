#include "sugar.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>



struct ARR {
    ARR()           { fill_zero();         }
    ARR(int length) { fill_random(length); }
    ARR(ARR& othr)  { fill_from(othr);     }
    ~ARR() noexcept { destruct();          }

    ARR& operator = (ARR& othr);
    void operator += (int next);

    void         destruct();
    void         fill_zero();
    void         fill_random(unsigned int);
    void         fill_from(ARR&);
    void         reset();
    void         print();
    void         info();
    unsigned int get_size();
    int          search_pos(int);
    void         search_set(int);

private:
    int*         _ar;
    unsigned int _id = 0;
    static int   _max_id;
    static int   _counter;
    std::string  _name = "Array";
    unsigned int _length;
};