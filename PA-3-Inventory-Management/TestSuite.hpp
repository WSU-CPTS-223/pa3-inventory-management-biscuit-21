#pragma once

#include "DataMaps.hpp"
#include "UnorderedMap.hpp"

#include <cassert>

//TODO: implement test functions
class TestSuite {
    public:
        //check if all tests passed
        void testAll();
    private:
        //DataMaps functions
        void testQuoteLineParser();
        void testLoadMaps();

        //UnorderedMap function
        void testInsert();
        void testFind();
        void testErase();
        void testRehash();
};