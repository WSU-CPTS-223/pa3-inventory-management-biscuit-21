#include "TestSuite.hpp"

#include <sstream>
#include <string>
#include <functional> //std::hash

using namespace std;

void TestSuite::testQuoteLineParser() {
    DataMaps map;
    stringstream ssQuotes("\"Item1\",Name1");
    stringstream ssNoQuotes("Item2,Name2");
    stringstream ssNA(",Name3");
    string result;

    //testign correct output with quotes
    map.quoteLineParser(ssQuotes, result);
    assert(result == "Item1");
    map.quoteLineParser(ssQuotes, result);
    assert(result == "Name1");

    //testing correct output without quotes
    map.quoteLineParser(ssNoQuotes, result);
    assert(result == "Item2");
    map.quoteLineParser(ssNoQuotes, result);
    assert(result == "Name2");

    //testing if empty fields get set to "NA" correctly
    map.quoteLineParser(ssNA, result);
    assert(result.empty());
    map.quoteLineParser(ssNA, result);
    assert(result == "Name3");
}

//precondition: test find()
void TestSuite::testLoadMaps() {
    DataMaps map;

    //testing DataMaps objects load data correctly
    map.loadMaps();
    UnorderedMap<string, Data> idMap = map.getIDMap();
    Data* data = idMap.find("66fb5ba1fa6603986d00368940ffc4dd");
    assert(data != nullptr);
}

//precondition: test find()
void TestSuite::testInsert() {
    DataMaps map;
    UnorderedMap<string, Data> idMap = map.getIDMap();
    Data value;

    //checks that inserting works and puts items in the keyed place
    idMap.insert("0", value);
    assert(idMap.find("0") != nullptr);

    //insert at same index again to make sure seperate chaining works
    idMap.insert("0", value);
    vector<List<pair<string,Data>>> mapVector(165);
    mapVector = idMap.getBuckets();
    Node<pair<string,Data>>* pCur = mapVector[hash<string>{}("0") % mapVector.size()].getPHead();
    assert(pCur->getPNext() != nullptr);
}

void TestSuite::testFind() {
    DataMaps map;
    UnorderedMap<string, Data> idMap = map.getIDMap();
    Data idData;

    //checks that find returns expected values
    idMap.insert("0", idData);
    Data* pData = idMap.find("0");
    Data* pEmpty = idMap.find("1");
    assert(pData->getUniqID() == idData.getUniqID());
    assert(pEmpty == nullptr);

    //insert at same index to make sure seperate chaining works
    UnorderedMap<string, vector<string>> catMap = map.getCategoryMap();
    vector<string> catData(165);
    catMap.insert("Games", catData);
    catMap.insert("Games", catData);
    vector<List<pair<string,vector<string>>>> catMapVector = catMap.getBuckets();
    Node<pair<string,vector<string>>>* pCur = catMapVector[hash<string>{}("Games") % catData.size()].getPHead();
    assert(pCur->getPNext() != nullptr);
}

//implement a test for erase() if it is actually used in the future
void TestSuite::testErase() {

}

//precondition: test insert()
void TestSuite::testRehash() {
    DataMaps map;
    UnorderedMap<string, Data> idMap = map.getIDMap();
    Data idData;

    //inserts a number of elements larger than tableSize(currently 165) and then sees if they are still there after rehashing
    for (int i = 0; i < 200; ++i)
        idMap.insert(to_string(i), idData);

    for (int i = 0; i < 200; ++i) {
        Data* pData = idMap.find(to_string(i));
        assert(pData != nullptr);
    }
}

void TestSuite::testAll() {
    testQuoteLineParser();
    testFind();
    testLoadMaps();
    testInsert();
    testErase();
    testRehash();

    cout << "All tests passed\n"
        << "> ";
}