#include <iostream>
#include <cstring>
#include "LongestSubstring.h"

int main() {
    std::string s1 = "1A2C3D4B56";
    std::string s2 = "B1D23CA45B6A";

    LongestSubstring longestSubstring;
    auto ans = longestSubstring.findLCS(s1, s1.length(), s2, s2.length());
    printf("%d\n", ans);

    return 0;
}