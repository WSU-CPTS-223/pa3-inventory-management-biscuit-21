#pragma once

#include <string>
#include <vector>

using namespace std;

class Data {
    public:
    Data() = default;

    //setters
    void setUniqID(const string& newUniqID) { UniqID = newUniqID; }
    void setProductName(const string& newProductName) { ProductName = newProductName; }
    void setBrandName(const string& newBrandName) { BrandName = newBrandName; }
    void setAsin(const string& newAsin) { Asin = newAsin; }
    void setCategories(const vector<string>& newCategories) { Categories = newCategories; }
    void setUpcEanCode(const string& newUpcEanCode) { UpcEanCode = newUpcEanCode; }
    void setListPrice(const string& newListPrice) { ListPrice = newListPrice; }
    void setSellingPrice(const string& newSellingPrice) { SellingPrice = newSellingPrice; }
    void setQuantity(const string& newQuantity) { Quantity = newQuantity; }
    void setModelNumber(const string& newModelNumber) { ModelNumber = newModelNumber; }
    void setAboutProduct(const string& newAboutProduct) { AboutProduct = newAboutProduct; }
    void setProductSpecification(const string& newProductSpecification) { ProductSpecification = newProductSpecification; }
    void setTechnicalDetails(const string& newTechnicalDetail) { TechnicalDetails = newTechnicalDetail; }
    void setShippingWeight(const string& newShippingWeight) { ShippingWeight = newShippingWeight; }
    void setProductDimensions(const string& newProductDimensions) { ProductDimensions = newProductDimensions; }
    void setImage(const string& newImage) { Image = newImage; }
    void setVariants(const string& newVariants) { Variants = newVariants; }
    void setSku(const string& newSku) { Sku = newSku; }
    void setProductUrl(const string& newProductUrl) { ProductUrl = newProductUrl; }
    void setStock(const string& newStock) { Stock = newStock; }
    void setProductDetails(const string& newProductDetails) { ProductDetails = newProductDetails; }
    void setDimensions(const string& newDimensions) { Dimensions = newDimensions; }
    void setColor(const string& newColor) { Color = newColor; }
    void setIngredients(const string& newIngredients) { Ingredients = newIngredients; }
    void setDirectionToUse(const string& newDirectionToUse) { DirectionToUse = newDirectionToUse; }
    void setIsAmazonSeller(const string& newIsAmazonSeller) { IsAmazonSeller = newIsAmazonSeller; }
    void setSizeQuantityVariant(const string& newSizeQuantityVariant) { SizeQuantityVariant = newSizeQuantityVariant; }
    void setProductDescription(const string& newProductDescription) { ProductDescription = newProductDescription; }

    //getters
    const string& getUniqID() const { return UniqID; }
    const string& getProductName() const { return ProductName; }
    const string& getBrandName() const { return BrandName; }
    const string& getAsin() const { return Asin; }
    const vector<string>& getCategories() const { return Categories; }
    const string& getUpcEanCode() const { return UpcEanCode; }
    const string& getListPrice() const { return ListPrice; }
    const string& getSellingPrice() const { return SellingPrice; }
    const string& getQuantity() const { return Quantity; }
    const string& getModelNumber() const { return ModelNumber; }
    const string& getAboutProduct() const { return AboutProduct; }
    const string& getProductSpecification() const { return ProductSpecification; }
    const string& getTechnicalDetails() const { return TechnicalDetails; }
    const string& getShippingWeight() const { return ShippingWeight; }
    const string& getProductDimensions() const { return ProductDimensions; }
    const string& getImage() const { return Image; }
    const string& getVariants() const { return Variants; }
    const string& getSku() const { return Sku; }
    const string& getProductUrl() const { return ProductUrl; }
    const string& getStock() const { return Stock; }
    const string& getProductDetails() const { return ProductDetails; }
    const string& getDimensions() const { return Dimensions; }
    const string& getColor() const { return Color; }
    const string& getIngredients() const { return Ingredients; }
    const string& getDirectionToUse() const { return DirectionToUse; }
    const string& getIsAmazonSeller() const { return IsAmazonSeller; }
    const string& getSizeQuantityVariant() const { return SizeQuantityVariant; }
    const string& getProductDescription() const { return ProductDescription; }

    private:
    string UniqID;
    string ProductName;
    string BrandName;
    string Asin;
    vector<string> Categories;
    string UpcEanCode;
    string ListPrice;
    string SellingPrice;
    string Quantity;
    string ModelNumber;
    string AboutProduct;
    string ProductSpecification;
    string TechnicalDetails;
    string ShippingWeight;
    string ProductDimensions;
    string Image;
    string Variants;
    string Sku;
    string ProductUrl;
    string Stock;
    string ProductDetails;
    string Dimensions;
    string Color;
    string Ingredients;
    string DirectionToUse;
    string IsAmazonSeller;
    string SizeQuantityVariant;
    string ProductDescription;
};