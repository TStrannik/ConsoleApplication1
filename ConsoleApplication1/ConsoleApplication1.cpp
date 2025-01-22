#pragma region HEAD

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <semaphore>
#include <functional>

#include "SimpleTimer.h"

using namespace std;



template <typename T> void w (T s) { std::cout << s;              }
template <typename T> void wl(T s) { std::cout << s << std::endl; }
                      void wl()    { std::cout <<      std::endl; }

inline void ttsleep(float t) { this_thread::sleep_for(chrono::milliseconds((int)(t * 1000))); }

#pragma endregion 


template <typename T>
class IndirectValue {
    T* ptr;
public:

    explicit IndirectValue(T* ptr) : ptr(ptr) {}
    ~IndirectValue() noexcept { if (ptr) delete ptr; }

    IndirectValue(IndirectValue const& other) : ptr(other.ptr ? new T(*other.ptr) : nullptr) {}

    IndirectValue& operator=(IndirectValue const& other) {
        IndirectValue temp(other);
        std::swap(ptr, temp.ptr);
        return *this;
    }
    


    IndirectValue(IndirectValue&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }
    IndirectValue& operator=(IndirectValue&& other) noexcept {
        IndirectValue temp(std::move(other));
        std::swap(ptr, temp.ptr);
        return *this;
    }

};




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