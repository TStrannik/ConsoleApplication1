#pragma region HEAD

#include <iostream>
#include <thread>
#include <vector>
#include <deque>

#include "SimpleTimer.h"

using namespace std;



template <typename T> void w (T s) { std::cout << s;              }
template <typename T> void wl(T s) { std::cout << s << std::endl; }
                      void wl()    { std::cout <<      std::endl; }

inline void ttsleep(float t) { this_thread::sleep_for(chrono::milliseconds((int)(t * 1000))); }

#pragma endregion 



#pragma region int
int main() {
    setlocale(LC_ALL, "RU_ru");
    system("color 70\n cls\n");
    SimpleTimer STimer;
#pragma endregion main()
    
    deque <int> dq;
    dq.push_back(5);
    dq.push_front(8);
    dq.push_back(1);
    dq.push_front(4);

    for (auto _ : dq) { w(_); w(" "); } wl();

    int max = 0;
    for (auto i = 0; i < dq.size() - 1; ++i) {
        if (dq[i] > max) {
            max = dq[i];
            std::swap(dq[i], dq[dq.size() - 1]);
            i = 0;
        }
    }

    for (auto _ : dq) { w(_); w(" "); } wl();
    
#pragma region }
    std::cout << std::endl << std::endl;
    return 0;
}
#pragma endregion