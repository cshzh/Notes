#include <iostream>
#include <cstring>
#include "LongestSubstring.h"
#include "AscentSequence.h"
#include "Mixture.h"

void testFindLongest();

int main() {
    std::string A = "bcbccabccacccbcac";
    int n = A.size();
    std::string B = "abbbacaabccbccaaaabbcbcbaaacccbaaba";
    int m = B.size();
    std::string C = "babbbacaabccbccaaaabbcbcbaaacccbaabacbccabccacccbcac";
    int v = C.size();

    std::cout << Mixture().chkMixture(A, n, B, m, C, v) << std::endl;


//    testFindLongest();

    return 0;
}

void testFindLongest() {
    vector<int> A = {88181, 66402, 35219, 85574, 54640, 5931, 39028, 9026, 84648, 15938, 30692, 58418, 71423,
                     21622, 93420, 17292, 34854, 10751, 38335, 82886, 36348, 28400, 2471, 60448, 49691, 20036,
                     82783, 24841, 20614, 63445, 1709, 43315, 54001, 73624, 86913, 40591, 74500, 73284, 44309,
                     45064, 15469, 63863, 92843, 94895, 60988, 17444, 75657, 84275, 22532, 88581, 20936, 77568,
                     37370, 27136, 89450, 5035, 23390, 22702, 18417, 33972, 79610, 20653, 2679, 28819, 16866,
                     36550, 63695, 22140, 80453, 43587, 8584, 8481, 15002, 76905, 31585, 75489, 95860, 10199,
                     87114, 9618, 83500, 44904, 66773, 95702, 41138, 64183, 67206, 71609, 42960, 48730, 40095,
                     91372, 19423, 60258, 63186, 91824, 8348, 54415, 88171, 67031, 2624, 23345, 5942, 22272, 5199,
                     63880, 6056, 52909, 96552, 96609, 5982, 40628, 77770, 23115, 47054, 76024, 94235, 15450,
                     27757, 43006, 40548, 45956, 44692, 40516, 55014, 89813, 85578, 53908, 19730, 19101, 40903,
                     8424, 95014, 83119, 62573, 20915, 32664, 54241, 66608, 50222, 14763, 85709, 64582, 29100,
                     28508, 59687, 48399, 6135, 87663, 41090, 78091, 9557, 90518, 46090, 80111, 71045, 49494,
                     15616, 76865, 83986, 89947, 88453, 23572, 47326, 51668, 2139, 59913, 10686, 62417, 19958,
                     39883, 83363, 56714, 1013, 80694, 52664, 31553, 80014, 61391, 47993, 74636, 7615, 33191,
                     53650, 49487, 59263, 88850, 1395, 37726, 8065, 11606, 41280, 20268, 41677, 23021, 41232,
                     43455, 78177, 83498, 20933, 22404, 16485, 5413, 64775, 57113, 79907, 88067, 11865, 59772,
                     65471, 3547, 42411, 31588, 54300, 12270, 14793, 77373, 60847, 70908, 39358, 32083, 65209,
                     15846, 53520, 47948, 63691, 95868, 17972, 48689, 8841, 79841, 53634, 40624, 11061, 11218,
                     13291, 91543, 28739, 33361, 127, 87135};
    int n = A.size();

    printf("%d\n", AscentSequence().findLongest(A, n));
}