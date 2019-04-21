#include <iostream>
#include <cstring>

int main() {
    char *c_ptr;
    c_ptr = new char[1024];

    strcpy(c_ptr, "this is a string");

    delete[] c_ptr;
    delete[] c_ptr;

    return 0;
}