#include "ARR.h"

using namespace std;



int          ARR::_counter = 0; 
int          ARR::_max_id  = 0;

void         ARR::_fill_from(ARR& other) {

    _length = other._length;
    _ar = new int[_length];
    for (size_t i = 0; i < _length; i++)
        _ar[i] = other._ar[i];

    _id = ++_max_id;
    _counter++;

}
void         ARR::_fill_zero() {

    _length = 1;
    _ar = new int[_length];
    for (size_t i = 0; i < _length; ++i) _ar[i] = 0;

    _id = ++_max_id;
    _counter++;

}
void         ARR::_fill_random(unsigned int length) {

            //  srand(time(NULL));
    auto now = std::chrono::high_resolution_clock::now();
    std::mt19937 random_generator(now.time_since_epoch().count());

    _length = length;

    vector <int> base;
    for (size_t i = 1; i <= _length; i++) base.push_back(i);

            //if (_ar != nullptr) delete[] _ar;
    _ar = new int[_length];
    int r = 0;
    for (size_t i = 0; i < _length; i++) {
            //r = rand() % base.size();
        r = random_generator() % base.size();
        _ar[i] = base[r];
        base.erase(base.begin() + r);
    }

    _id = ++_max_id;
    _counter++;

}

void         ARR::destruct() {

    if (_ar != nullptr)
        delete[] _ar;
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
unsigned int ARR::get_counter() {

    return ARR::_counter;

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
bool         ARR::get_from_file(std::string filename) {

    ifstream file(filename);

    if (!file.is_open()) return false;

    string str;
    vector <string> next;
    
    int i = 0;
    
    while (getline(file, str)) {
        next.push_back("");
    
        while (i < str.length()) {
            if (str[i] != ' ') next.back() += str[i];
            else               next.push_back("");

            i++;
        }
    }
    
    if (str.length() == 0) return false;
    if (next.size() < 0)   return false;

    _length = next.size();
    
    if (_ar != nullptr) delete[] _ar; _ar = new int[_length];
    for (size_t i = 0; i < _length; ++i) _ar[i] = atoi(next[i].c_str());            

    

    file.close();

    return true;

}

ARR&         ARR::operator =  (ARR& other) {

    if (_ar != nullptr) delete[] _ar;

    _length = other._length;
    _ar = new int[_length];
    for (size_t i = 0; i < _length; i++)
        _ar[i] = other._ar[i];

    _id = ++_max_id;
    _counter++;

    return *this;

}
void         ARR::operator += (int next) {

    int* tmp = new int[_length];
    for (size_t i = 0; i < _length; i++) tmp[i] = _ar[i];
    
    delete[] _ar;
    _ar = new int[++_length];

    for (size_t i = 0; i < _length - 1; i++)
        _ar[i] = tmp[i];
    _ar[_length - 1] = next;

    delete[] tmp;
}
ARR          ARR::operator +  (ARR& other) {

    int L = _length, l = _length;
    int* A = _ar; int* a = _ar;

    L = (_length > other._length) ? _length : other._length;
    l = (_length > other._length) ? other._length : _length;
    A = (_length > other._length) ? _ar : other._ar;
    a = (_length > other._length) ? other._ar : _ar;

    ARR copy(L);
    for (size_t i = 0; i < l; i++) copy._ar[i] = A[i] + a[i];
    for (size_t i = l; i < L; i++) copy._ar[i] = A[i];

    A = nullptr; a = nullptr;
    delete[]  A; delete[]  a;

    return copy;

}
void         ARR::operator -  (int del) {

    vector <int> tmp;

    int l = _length;
    for (int i = 0; i < _length; ++i) {
        if (_ar[i] != del) tmp.push_back(_ar[i]);
        else               l--;
    }
    
    if (_ar != nullptr) delete[] _ar;
    _length = l;
    _ar = new int[_length];

    for (int i = 0; i < _length; ++i) _ar[i] = tmp[i];

}
bool         ARR::operator == (ARR& other) {

    for (size_t i = 0; i < _length; i++)
        if (_ar[i] != other._ar[i]) return 0;
    
    return 1;

}
int          ARR::operator [] (int index) {

    return _ar[index];

}


void         Matrix::_fill_random(unsigned int m, unsigned int n) {

    _matrix = new ARR[_m]{ NULL };
    for (size_t i = 0; i < _m; i++)
        _matrix[i]._fill_random(_n);

}
void         Matrix::destruct() {

    if (_matrix != nullptr) delete[] _matrix;

}
void         Matrix::print() {

    for (size_t i = 0; i < _m; i++) {
        _matrix[i].print();
        wl(); wl();
    }

}
bool         Matrix::get_from_file(std::string filename) {

    ifstream file(filename);

    
    



    file.close();

    return true;

}