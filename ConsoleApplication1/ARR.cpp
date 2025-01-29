#include "ARR.h"

using namespace std;



int          ARR::_counter = 0; 
int          ARR::_max_id  = 0;

ARR&         ARR::operator = (ARR& other) {

    _length = other._length;
    _ar = new int[_length];
    for (size_t i = 0; i < _length; i++)
        _ar[i] = other._ar[i];

    _id = ++_max_id;
    _counter++;

    return *this;

}

void         ARR::fill_from(ARR& other) {

    _length = other._length;
    _ar = new int[_length];
    for (size_t i = 0; i < _length; i++)
        _ar[i] = other._ar[i];

    _id = ++_max_id;
    _counter++;

}
void         ARR::fill_zero() {

    _length = 5;
    _ar = new int[_length];
    for (size_t i = 0; i < _length; ++i) _ar[i] = 0;

    _id = ++_max_id;
    _counter++;

}
void         ARR::fill_random(unsigned int length) {

    srand(time(NULL));
    _length = length;

    vector <int> base;
    for (size_t i = 1; i <= _length; i++) base.push_back(i);

    _ar = new int[_length];
    int r = 0;
    for (size_t i = 0; i < _length; i++) {
        r = rand() % base.size();
        _ar[i] = base[r];
        base.erase(base.begin() + r);
    }

    _id = ++_max_id;
    _counter++;

}

void         ARR::destruct() {

    if (_ar != nullptr) delete[] _ar;
    _counter--;

}

void         ARR::print() {

    for (size_t i = 0; i < _length; i++) { w(_ar[i]); w("\t"); } wl();

}
void         ARR::info() {
                      
    w("array "); w(_name); w(" "); w(_id); w(":\n\t");
    for (size_t i = 0; i < _length; i++) { w(_ar[i]); w("\t"); } wl(); wl();

}
void         ARR::reset() {

    w("new length: "); int l; cin >> l;
    if (l < 0) return;
    _length = l;

    if (_ar != nullptr) delete[] _ar;
    _ar = new int[_length];

    for (size_t i = 0; i < _length; ++i) cin >> _ar[i];

}

unsigned int ARR::get_size() {

    return _length;

}
int          ARR::search_pos(int value) {

    for (size_t i = 0; i < _length; i++)
        if (_ar[i] == value) return i;
    return -1;

}
void         ARR::search_set(int value) {

    w("array "); w(_name); w(" "); w(_id); w(":\n\t");
    for (size_t i = 0; i < _length; i++) { w(_ar[i]); w("\t"); } w("\n\t");
    for (size_t i = 0; i < _length; i++)
        if (_ar[i] == value)
            w("^\t");
        else
            w(" \t");
    wl();

}

void         ARR::operator += (int next) {

    int* tmp = new int[_length];
    for (size_t i = 0; i < _length; i++) tmp[i] = _ar[i];
    
    delete[] _ar;
    _ar = new int[++_length];

    for (size_t i = 0; i < _length - 1; i++) _ar[i] = tmp[i];
    _ar[_length - 1] = next;

    delete[] tmp;
}