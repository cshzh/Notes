#include <iostream>
#include <cstring>
#include "Singleton.h"


// undefined behaviour
// delete a pointer more than once
void deleteLearn();

int main() {
    deleteLearn();

//    Singleton &singleton = Singleton::GetInstance();
//
//    singleton.Show();
//
//    printf("%p\n", &singleton);
//
//    char arr[8];
//
//    Singleton *singleton2 = static_cast<Singleton *>(memcpy(arr, &singleton, 8));
//
//    singleton2->Show();
//
//    singleton2->SetData(24);
//    printf("******after******\n");
//
//    singleton.Show();
//    singleton2->Show();
//
////    delete singleton;
//    delete singleton2;

    return 0;
}

// undefined behaviour
// delete a pointer more than once
void deleteLearn() {
    int *a, *b;
//    a = new int[256];
    a = new int[512];
    b = a;
    printf("*a={%d}\n", *a);
    printf("*b={%d}\n", *b);
    printf("a={%p}\n", a);
    printf("b={%p}\n", b);
    delete[] a;
//    delete[] a;
    delete[] b;
}