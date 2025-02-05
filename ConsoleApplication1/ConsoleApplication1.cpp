#include "SimpleTimer.h"
#include "ARR.h"
#include <array>



#pragma region int

int main() {
     setlocale(LC_ALL, "RU_ru");
     system("color 70\n cls\n");
     SimpleTimer STimer;

#pragma endregion main() {

     /*Matrix hoyda(5, 5);
     hoyda.get_from_file("matrix.in");
     hoyda.print();*/
    
     

     ARR JoJo;

     JoJo.get_from_file("arr.in");
     JoJo.info();



#pragma region }
    //system("pause");
    return 0;
}
#pragma endregion