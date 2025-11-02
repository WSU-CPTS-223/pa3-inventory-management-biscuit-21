#include "DataMaps.hpp"
#include "TestSuite.hpp"

#include <iostream>
#include <string>

using namespace std;

void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'." << endl;
    cout << " 3. test - makes sure program is working properly\n"
         << endl;
    cout << " Use :quit to quit the REPL" << endl;
}

bool validCommand(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0) ||
           (line.rfind("test") == 0);
}

void evalCommand(string line, UnorderedMap<std::string, Data>& idMap, UnorderedMap<std::string, std::vector<std::string>>& catMap)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        // Look up the appropriate datastructure to find if the inventory exist
        size_t pos = line.find(" ");
        if (pos != string::npos) {
            string userInput = line.substr(pos + 1); //gets only the user-specified category from the command

            if (idMap.find(userInput) == nullptr) {
                cout << "\nInventory/Product not found!\n";
            }
            else {
                auto* item = idMap.find(userInput);
                cout << "\n-> " << item->getUniqID() << "\n-> "
                    << item->getProductName() << "\n-> "
                    << item->getBrandName() << "\n-> "
                    << item->getAsin() << "\n-> ";

                    //special logic for printing all categories
                    const vector<string>& catVector = item->getCategories();
                    cout << catVector[0];
                    for (size_t i = 1; i < catVector.size(); i++) {
                        cout << " | " << catVector[i];
                    }

                cout << item->getUpcEanCode() << "\n-> "
                    << item->getListPrice() << "\n-> "
                    << item->getSellingPrice() << "\n-> "
                    << item->getQuantity() << "\n-> "
                    << item->getModelNumber() << "\n-> "
                    << item->getAboutProduct() << "\n-> "
                    << item->getProductSpecification() << "\n-> "
                    << item->getTechnicalDetails() << "\n-> "
                    << item->getShippingWeight() << "\n-> "
                    << item->getProductDimensions() << "\n-> "
                    << item->getImage() << "\n-> "
                    << item->getVariants() << "\n-> "
                    << item->getSku() << "\n-> "
                    << item->getProductUrl() << "\n-> "
                    << item->getStock() << "\n-> "
                    << item->getProductDetails() << "\n-> "
                    << item->getDimensions() << "\n-> "
                    << item->getColor() << "\n-> "
                    << item->getIngredients() << "\n-> "
                    << item->getDirectionToUse() << "\n-> "
                    << item->getIsAmazonSeller() << "\n-> "
                    << item->getSizeQuantityVariant() << "\n-> "
                    << item->getProductDescription() << "\n" << endl;
            }
        }
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        // Look up the appropriate datastructure to find all inventory belonging to a specific category
        size_t pos = line.find(" ");
        if (pos != string::npos) {
            string userInput = line.substr(pos + 1); //gets only the user-specified category from the command

            if (catMap.find(userInput) == nullptr) {
                cout << "\nInvalid Category!\n";
            }
            else {
                for (const string& idString : *catMap.find(userInput)) {
                    auto* item = idMap.find(idString);
                    cout << "\n" << item->getUniqID() << "\n"
                        << item->getProductName() << "\n";
                }
            }
        }
    }
    else if (line.rfind("test") == 0)
    {
        TestSuite tests;
        tests.testAll();
    }
}

DataMaps bootStrap()
{
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";
    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices
    DataMaps ADMs; //Amazon Data Maps
    ADMs.loadMaps();
    return ADMs;
}

int main(int argc, char const *argv[])
{
    string line;
    auto ADMs = bootStrap();
    auto& idMap = ADMs.getIDMap();
    auto& catMap = ADMs.getCategoryMap();

    while (getline(cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(line, idMap, catMap);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }
    return 0;
}
