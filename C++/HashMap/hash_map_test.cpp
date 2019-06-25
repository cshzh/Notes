//
// Created by hui on 19-6-24.
//


#include "gtest/gtest.h"
#include "hash_map.h"

TEST(hash_map_test, put) {
    hash_map map;

    map.put(1, 1);
    EXPECT_EQ(1, map.size());
    map.put(1, 2);
    EXPECT_EQ(1, map.size());
    map.put(2, 2);
    EXPECT_EQ(2, map.size());
    map.put(3, 2);
    EXPECT_EQ(3, map.size());
    map.put(3, 3);
    EXPECT_EQ(3, map.size());
}

TEST(hash_map_test, get) {
    hash_map map;

    map.put(10, 10);
    EXPECT_EQ(10, map.get(10));
    map.put(8, 8);
    EXPECT_EQ(8, map.get(8));
    map.put(6, 6);
    EXPECT_EQ(6, map.get(6));
    map.put(4, 4);
    EXPECT_EQ(4, map.get(4));
    map.put(2, 2);
    EXPECT_EQ(2, map.get(2));
    map.put(0, 0);
    EXPECT_EQ(0, map.get(0));
}

TEST(hash_map_test, erase) {
    hash_map map;
    map.put(1, 1);
    map.put(2, 2);
    map.erase(1);
    EXPECT_EQ(1, map.size());
    map.put(3, 3);
    map.erase(2);
    EXPECT_EQ(1, map.size());
    map.put(4, 4);
    map.erase(3);
    EXPECT_EQ(1, map.size());
    map.put(5, 5);
    map.put(6, 6);
    map.put(7, 7);
    map.erase(5);
    EXPECT_EQ(3, map.size());
    map.erase(4);
    map.erase(6);
    map.erase(7);
    EXPECT_EQ(0, map.size());
}

TEST(hash_map_test, integration) {
    hash_map map;

    for (int i = 1; i < 1000; i += 2) {
        if (i == 17 ) {
            map;
        }
        map.put(i, i + 1);
        EXPECT_EQ(i + 1, map.get(i));
        EXPECT_EQ((i + 1) / 2, map.size());
    }

    EXPECT_EQ(500, map.size());

    EXPECT_EQ(2, map.get(1));
    EXPECT_EQ(8, map.get(7));
    EXPECT_EQ(1000, map.get(999));

    for (int i = 999; i > 0; i -= 2) {
        EXPECT_EQ(i + 1, map.get(i));
        EXPECT_EQ((i + 1) / 2, map.size());
        map.erase(i);
    }
}

