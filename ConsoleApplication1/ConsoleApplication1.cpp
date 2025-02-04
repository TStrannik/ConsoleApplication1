#include "SimpleTimer.h"
#include "ARR.h"
#include <array>



#pragma region int

int main() {
     setlocale(LC_ALL, "RU_ru");
     system("color 70\n cls\n");
     SimpleTimer STimer;

#pragma endregion main() {

    //Matrix hoyda;
    //hoyda.print(); 
    
    
     ARR JoJo;

     JoJo.get_form_file("arr.in");
     JoJo.info();


#pragma region }
    //system("pause");
    return 0;
}
#pragma endregion