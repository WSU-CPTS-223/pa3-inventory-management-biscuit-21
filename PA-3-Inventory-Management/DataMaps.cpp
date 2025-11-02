#include "DataMaps.hpp"

#include <fstream>
#include <iostream>

using namespace std;

//helper for loadMaps
bool DataMaps::quoteLineParser(std::stringstream& ss, std::string& detailsString) {
    detailsString.clear(); //clears the old string
    char c;
    bool inQuotes = false;

    while (ss.get(c)) {
        if (c == '"') { //toggle quote state
            inQuotes = !inQuotes;
        } 
        else if (c == ',' && !inQuotes) { //breaks if end of field
            break;
        } 
        else {
            detailsString += c;
        }
    }

    //trim quotes at both ends if present
    if (!detailsString.empty() && detailsString.front() == '"' && detailsString.back() == '"') {
        detailsString = detailsString.substr(1, detailsString.size() - 2);
    }

    return true;
}

void DataMaps::loadMaps() {
    ifstream infile;
    infile.open("marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data-1.csv");
    if (!infile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    int count = 0;
    while (getline(infile,line)) {
        //skips first line
        if (count == 0) {
            count++;
            continue;
        }

        //skips empty lines
        if (line.empty()) {
            continue;
        }

        Data item;
        stringstream ss(line);
        string field;

        if (!getline(ss, field, ',') || field.empty()) { //cannot read UniqID or field is empty
            cout << "No UniqID, line " << count << "skipped\n";
            continue;
        }
        else {
            item.setUniqID(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setProductName("NA");
        }
        else {
            item.setProductName(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setBrandName("NA");
        }
        else {
            item.setBrandName(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setAsin("NA");
        }
        else {
            item.setAsin(field);
        }

        //special case for '|' seperated categories
        quoteLineParser(ss, field);
        if (field.empty()) {
            vector<string> cats;
            cats.push_back("NA");
            item.setCategories(cats);
        }
        else {
            vector<string> cats;
            string singleCat;
            stringstream cs(field);
            while (getline(cs, singleCat, '|')) {
                if (!singleCat.empty()) {
                    singleCat.erase(0, singleCat.find_first_not_of(" ")); //trims leading space
                    singleCat.erase(singleCat.find_last_not_of(" ") + 1); //trims trailing space
                    cats.push_back(singleCat);
                }
            }
            item.setCategories(cats);
        }
        
        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setUpcEanCode("NA");
        }
        else {
            item.setUpcEanCode(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setListPrice("NA");
        }
        else {
            item.setListPrice(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setSellingPrice("NA");
        }
        else {
            item.setSellingPrice(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setQuantity("NA");
        }
        else {
            item.setQuantity(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setModelNumber("NA");
        }
        else {
            item.setModelNumber(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setAboutProduct("NA");
        }
        else {
            item.setAboutProduct(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setProductSpecification("NA");
        }
        else {
            item.setProductSpecification(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setTechnicalDetails("NA");
        }
        else {
            item.setTechnicalDetails(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setShippingWeight("NA");
        }
        else {
            item.setShippingWeight(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setProductDimensions("NA");
        }
        else {
            item.setProductDimensions(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setImage("NA");
        }
        else {
            item.setImage(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setVariants("NA");
        }
        else {
            item.setVariants(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setSku("NA");
        }
        else {
            item.setSku(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setProductUrl("NA");
        }
        else {
            item.setProductUrl(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setStock("NA");
        }
        else {
            item.setStock(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setProductDetails("NA");
        }
        else {
            item.setProductDetails(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setDimensions("NA");
        }
        else {
            item.setDimensions(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setColor("NA");
        }
        else {
            item.setColor(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setIngredients("NA");
        }
        else {
            item.setIngredients(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setDirectionToUse("NA");
        }
        else {
            item.setDirectionToUse(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setIsAmazonSeller("NA");
        }
        else {
            item.setIsAmazonSeller(field);
        }

        quoteLineParser(ss, field);
        if (field.empty()) {
            item.setSizeQuantityVariant("NA");
        }
        else {
            item.setSizeQuantityVariant(field);
        }

        getline(ss, field);
        if (field.empty()) {
            item.setProductDescription("NA");
        }
        else {
            item.setProductDescription(field);
        }

        count++;

        //inserts Data item into IDMap indexes based on UniqID
        const string id = item.getUniqID();
        IDMap.insert(id, item);

        //inserts UniqID into categoryMap for ever category it's a part of
        for (const string& oneCat : item.getCategories()) {
            if (!oneCat.empty()) {
                if (auto* stringVector = categoryMap.find(oneCat)) {
                    stringVector->push_back(id);
                }
                else {
                    categoryMap.insert(oneCat, vector<string>{id});
                }
            }
        }
    }

    infile.close();
}