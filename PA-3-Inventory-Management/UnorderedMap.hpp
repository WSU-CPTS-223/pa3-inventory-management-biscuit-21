#pragma once

#include "List.hpp"

#include <string>
#include <utility>           //std::pair
#include <functional>        //std::hash
#include <cstddef>           //size_t
#include <vector>
#include <iostream>

template <typename K, typename V>
class UnorderedMap {
    public:
        UnorderedMap() : tableSize(165), numElements(0), buckets(165) {}

        const std::vector<List<std::pair<K,V>>>& getBuckets() const { return buckets; }

        void insert(const K& key, const V& newData);
        V* find(const K& key);
        void erase(K& key);
        void rehash();
    private:
        size_t tableSize;
        size_t numElements;
        std::vector<List<std::pair<K,V>>> buckets;
        size_t hash(const K& key) const;
};

//helper function for insert(), find()
template <typename K, typename V>
size_t UnorderedMap<K,V>::hash(const K& key) const {
    return std::hash<K>{}(key);
}

//helper function for insert()
template <typename K, typename V>
void UnorderedMap<K,V>::rehash() {
    size_t newTableSize = tableSize * 2;
    tableSize = newTableSize;
    numElements = 0;

    auto oldBuckets = std::move(this->buckets);
    this->buckets.assign(newTableSize, {});

    for (size_t i = 0; i < oldBuckets.size(); i++) {
        Node<std::pair<K,V>>* pCur = oldBuckets[i].getPHead();
        while (pCur != nullptr) {
            std::pair<K,V>* item = pCur->getPT();
            insert(item->first, item->second);
            pCur = pCur->getPNext();
        }
    }
}

template <typename K, typename V>
void UnorderedMap<K,V>::insert(const K& key, const V& newData) {
    const size_t index = hash(key) % tableSize;
    auto& bucket = buckets[index];
    std::pair<K,V>* pNodeData = new std::pair<K,V>(key, newData);
    bucket.enqueue(pNodeData);
    numElements++;

    //checks load factor
    if ((double)numElements / (double)tableSize > 0.5) {
        rehash();
    }
}

template <typename K, typename V>
void UnorderedMap<K,V>::erase(K& key) {
    const size_t index = hash(key) % tableSize;
    auto& bucket = buckets[index];

    Node<std::pair<K,V>>* pCur = bucket.getPHead();
    Node<std::pair<K,V>>* pPrev = nullptr;

    while (pCur != nullptr) {
        std::pair<K,V>* item = pCur->getPT();
        if (item->first == key) {
            Node<std::pair<K,V>>* pNext = pCur->getPNext();

            //unlinks current node
            if (pPrev == nullptr) { //if unlinking first element
                bucket.setPHead(pNext);
            }
            else { //if not unlinking first element
                pPrev->setPNext(pNext);
            }

            if (pNext == nullptr) { //if unlinking last element
                bucket.setPTail(pPrev);
            }

            delete pCur;

            std::cout << "\nElement deleted!\n";
            numElements--;
            return;
        }
        pPrev = pCur;
        pCur = pCur->getPNext();
    }
    std::cout << "\nElement not found!\n";
}

template <typename K, typename V>
V* UnorderedMap<K,V>::find(const K& key) {
    const size_t index = hash(key) % tableSize;
    auto& bucket = buckets[index];

    Node<std::pair<K,V>>* pCur = bucket.getPHead();
    while (pCur != nullptr) { //for each Node in List...
        std::pair<K,V>* item = pCur->getPT();
        if (item->first == key) { //compares key values
            return &item->second;
        }
        pCur = pCur->getPNext();
    }
    return nullptr;
}