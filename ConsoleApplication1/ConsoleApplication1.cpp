#include "SimpleTimer.h"
#include "ARR.h"



#pragma region int

int main() {
     setlocale(LC_ALL, "RU_ru");
     system("color 70\n cls\n");
     SimpleTimer STimer;

#pragma endregion main() {
    
    ARR ar1(10);
    ARR ar2(20);
    ar1.info();
    ar2.info();

    wl(ar1[2]);
    wl(ar2[9]);
    
#pragma region }
    //system("pause");
    return 0;
}
#pragma endregion