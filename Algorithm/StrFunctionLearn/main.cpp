#include <iostream>
#include <cstring>
#include <vector>

//char *strcpy(char *des, const char *src);
//
//int strlen(const char *str);
//
//char *strcat(char *des, const char *src);
//
//int strcmp(const char *s1, const char *s2);

int main() {

    const char *a = "hua ng";
    int length = std::strlen(a);
    for (int i = 0; i <= 10; ++i) {
        std::cout << int(a[i]) << " ";
    }
    std::cout << std::endl;
    std::cout << length << std::endl;
    return 0;
}