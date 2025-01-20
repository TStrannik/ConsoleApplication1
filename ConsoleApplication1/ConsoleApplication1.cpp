#pragma region in your 

#include <iostream>
#include <thread>
#include "SimpleTimer.h"

using namespace std;



template <typename T> void w (T s) { std::cout << s;              }
template <typename T> void wl(T s) { std::cout << s << std::endl; }
                      void wl()    { std::cout <<      std::endl; }

inline void ttsleep(float t) { this_thread::sleep_for(chrono::milliseconds((int)(t * 1000))); }

#pragma endregion HEAD


#pragma region int
int main() {
    setlocale(LC_ALL, "RU_ru");
    system("color 70\n cls\n");
    SimpleTimer STimer;
#pragma endregion main()

   

    

#pragma region }
    std::cout << std::endl << std::endl;
    return 0;
}
#pragma endregion