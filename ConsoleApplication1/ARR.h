#include "sugar.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>



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
    bool         get_form_file(std::string filename);

private:
    int*         _ar;
    unsigned int _id = 0;
    static int   _max_id;
    static int   _counter;
    std::string  _name = "Array";
    unsigned int _length;

    void         _fill_zero();
    void         _fill_from(ARR&);

public:
    void         _fill_random(unsigned int);

};



struct Matrix
    : public ARR
{

    // { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 }; 
    Matrix() : _m(5), _n(5) { _matrix = new ARR[_m]{ (int)_n }; }


    //void _fill_random(unsigned int);

    Matrix(unsigned int m, unsigned int n) : _m(m), _n(n) {
        _matrix = new ARR[_m]{ NULL };
        for (size_t i = 0; i < _m; i++) {
            _matrix[i]._fill_random(_n);
            
        }
    }



    ~Matrix() { delete[] _matrix; }

    void print() {
        for (size_t i = 0; i < _m; i++) {
            _matrix[i].print();
            wl(); wl();
        }
    }





    //bool get_form_file(std::string filename);

private:
    ARR*         _matrix;
    unsigned int _m = 0;
    unsigned int _n = 0;

};