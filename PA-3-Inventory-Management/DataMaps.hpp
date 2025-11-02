#pragma once

#include "UnorderedMap.hpp"
#include "DataMaps.hpp"

#include <string>
#include <vector>
#include <sstream> 

class DataMaps {
    public:
        DataMaps() = default;
        
        void setIDMap(const UnorderedMap<std::string, Data>& newIDMap) { IDMap = newIDMap; }
        void setCategoryMap(const UnorderedMap<std::string, std::vector<std::string>>& newCategoryMap) { categoryMap = newCategoryMap; }

        UnorderedMap<std::string, Data>& getIDMap() { return IDMap; }
        UnorderedMap<std::string, std::vector<std::string>>& getCategoryMap() { return categoryMap; }

        bool quoteLineParser(std::stringstream& ss, std::string& out);
        void loadMaps();
    private:
        UnorderedMap<std::string, Data> IDMap;
        UnorderedMap<std::string, std::vector<std::string>> categoryMap;
};