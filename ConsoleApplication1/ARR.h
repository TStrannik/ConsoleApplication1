#include "sugar.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include <vector>



struct ARR
{

    ARR()           { _fill_zero();         }
    ARR(int length) { _fill_random(length); }
    ARR(ARR& othr)  { _fill_from(othr);     }
    ~ARR() noexcept { destruct();           }  

    ARR& operator =  (ARR& othr);
    void operator += (int next);
    ARR  operator +  (ARR& othr);
    void operator -  (int del);
    bool operator == (ARR& other);
    int  operator [] (int index);

    void         destruct();
    void         reset();
    void         print();
    void         info();
    unsigned int get_size();
    unsigned int get_counter();
    int          search_pos(int);
    void         search_set(int);
    bool         get_from_file(std::string filename);

private:
    int*         _ar;
    unsigned int _id = 0;
    static int   _max_id;
    static int   _counter;
    std::string  _name = "Array";
    unsigned int _length;

    void         _fill_zero();
    void         _fill_from(ARR&);

//protected:
public:
    void         _fill_random(unsigned int);

};



struct Matrix
    : public ARR
{

    Matrix()                               : _m(1), _n(1) { _fill_random(_m, _n); }
    Matrix(unsigned int m, unsigned int n) : _m(m), _n(n) { _fill_random(_m, _n); }
    ~Matrix()                                             { destruct();           }

    void destruct();
    void print();
    virtual bool get_from_file(std::string filename);

private:
    ARR*         _matrix;
    unsigned int _m = 0;
    unsigned int _n = 0;

    void _fill_random(unsigned int, unsigned int);

};