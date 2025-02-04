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
    void         _fill_random(unsigned int);
    void         _fill_from(ARR&);

};



struct Matrix 
    : public ARR
{

    Matrix()  { _matrix = new ARR[10]{ 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 }; }      //?
    ~Matrix() { delete[] _matrix; }

    void print() {
        for (size_t i = 0; i < 10; i++) {
            _matrix[i].print();
            wl(); wl();
        }
    }

    //bool get_form_file(std::string filename);

private:
    ARR* _matrix;

};