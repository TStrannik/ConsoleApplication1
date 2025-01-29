#include "SimpleTimer.h"
#include "ARR.h"



#pragma region int

int main() {
     setlocale(LC_ALL, "RU_ru");
     system("color 70\n cls\n");
     SimpleTimer STimer;

#pragma endregion main() {

    
    ARR ar1(10);
    ar1.info();
   
    ar1 += 111;
    ar1 += 222;
    ar1 += 333;
    ar1.info();

    

#pragma region }
    //system("pause");
    return 0;
}
#pragma endregion