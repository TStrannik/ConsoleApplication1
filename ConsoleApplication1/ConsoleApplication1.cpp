#pragma region in your 

#include <iostream>
#include <thread>
#include <vector>

#include "SimpleTimer.h"

using namespace std;



template <typename T> void w (T s) { std::cout << s;              }
template <typename T> void wl(T s) { std::cout << s << std::endl; }
                      void wl()    { std::cout <<      std::endl; }

inline void ttsleep(float t) { this_thread::sleep_for(chrono::milliseconds((int)(t * 1000))); }

#pragma endregion HEAD


struct Gavka {
    Gavka()                          { wl("+G"); }
    Gavka(string name) : _name(name) { wl("+G"); call(); }
    ~Gavka()                         { wl("-G"); }

    void call() { w("Howdy, "); w(_name); wl("!"); }

private:
    string _name;

};




#pragma region int
int main() {
    setlocale(LC_ALL, "RU_ru");
    system("color 70\n cls\n");
    SimpleTimer STimer;
#pragma endregion main()
    
    vector <Gavka*> Psy;
    Psy.push_back(new Gavka("Aleksandr"));
    Psy.push_back(new Gavka("Aleksey"));
    Psy.push_back(new Gavka("Alesha"));
    Psy.push_back(new Gavka("Anatoliy"));
    
    wl();    
    for (auto _ : Psy) _->call();
    wl();

    Psy.pop_back();
    for (auto _ : Psy) _->call();
    wl();

    Psy.erase(Psy.cbegin() + 1);
    for (auto _ : Psy) _->call();
    wl();



    Psy.clear();

#pragma region }
    std::cout << std::endl << std::endl;
    return 0;
}
#pragma endregion