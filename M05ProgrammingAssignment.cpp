#include <iostream>
#include <string>

class Beverage {
protected:
    std::string name;
    std::string description;
    std::string servingSize;
    int calories;
    double price;

public:
    Beverage(std::string name, std::string description, std::string servingSize, int calories, double price)
        : name(name), description(description), servingSize(servingSize), calories(calories), price(price) {}

    virtual ~Beverage() {}

    // Getter methods
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    std::string getServingSize() const { return servingSize; }
    int getCalories() const { return calories; }
    double getPrice() const { return price; }

    // Setter methods
    void setName(std::string newName) { name = newName; }
    void setDescription(std::string newDescription) { description = newDescription; }
    void setServingSize(std::string newServingSize) { servingSize = newServingSize; }
    void setCalories(int newCalories) { calories = newCalories; }
    void setPrice(double newPrice) { price = newPrice; }

    // toString method
    virtual std::string toString() const {
        return "Name: " + name + "\nDescription: " + description + "\nServing Size: " + servingSize +
               "\nCalories: " + std::to_string(calories) + "\nPrice: $" + std::to_string(price);
    }
};

class Coffee : public Beverage {
private:
    std::string roastType;
    bool isHot;
    bool isCaffeinated;
    int strength;
    bool hasCreamer;
    bool hasSweetener;

public:
    Coffee(std::string name, std::string description, std::string servingSize, int calories, double price,
           std::string roastType, bool isHot, bool isCaffeinated, int strength, bool hasCreamer, bool hasSweetener)
        : Beverage(name, description, servingSize, calories, price),
          roastType(roastType), isHot(isHot), isCaffeinated(isCaffeinated), strength(strength),
          hasCreamer(hasCreamer), hasSweetener(hasSweetener) {}

    // Additional getter/setter methods specific to Coffee
    std::string getRoastType() const { return roastType; }
    bool getIsHot() const { return isHot; }
    bool getIsCaffeinated() const { return isCaffeinated; }
    int getStrength() const { return strength; }
    bool getHasCreamer() const { return hasCreamer; }
    bool getHasSweetener() const { return hasSweetener; }

    void setRoastType(std::string newRoastType) { roastType = newRoastType; }
    void setIsHot(bool newIsHot) { isHot = newIsHot; }
    void setIsCaffeinated(bool newIsCaffeinated) { isCaffeinated = newIsCaffeinated; }
    void setStrength(int newStrength) { strength = newStrength; }
    void setHasCreamer(bool newHasCreamer) { hasCreamer = newHasCreamer; }
    void setHasSweetener(bool newHasSweetener) { hasSweetener = newHasSweetener; }

    // Override toString method
    std::string toString() const override {
        std::string hotOrCold = isHot ? "Hot" : "Cold";
        std::string caffeinated = isCaffeinated ? "Caffeinated" : "Decaffeinated";
        return Beverage::toString() + "\nRoast Type: " + roastType + "\nHot/Cold: " + hotOrCold +
               "\nCaffeinated/Decaffeinated: " + caffeinated + "\nStrength: " + std::to_string(strength) +
               "\nCreamer: " + (hasCreamer ? "Yes" : "No") + "\nSweetener: " + (hasSweetener ? "Yes" : "No");
    }
};

class Tea : public Beverage {
private:
    std::string type;
    bool isHot;
    bool hasCreamer;
    bool hasSweetener;
    bool hasLemon;

public:
    Tea(std::string name, std::string description, std::string servingSize, int calories, double price,
        std::string type, bool isHot, bool hasCreamer, bool hasSweetener, bool hasLemon)
        : Beverage(name, description, servingSize, calories, price),
          type(type), isHot(isHot), hasCreamer(hasCreamer), hasSweetener(hasSweetener), hasLemon(hasLemon) {}

    // Additional getter/setter methods specific to Tea
    std::string getType() const { return type; }
    bool getIsHot() const { return isHot; }
    bool getHasCreamer() const { return hasCreamer; }
    bool getHasSweetener() const { return hasSweetener; }
    bool getHasLemon() const { return hasLemon; }

    void setType(std::string newType) { type = newType; }
    void setIsHot(bool newIsHot) { isHot = newIsHot; }
    void setHasCreamer(bool newHasCreamer) { hasCreamer = newHasCreamer; }
    void setHasSweetener(bool newHasSweetener) { hasSweetener = newHasSweetener; }
    void setHasLemon(bool newHasLemon) { hasLemon = newHasLemon; }

    // Override toString method
    std::string toString() const override {
        std::string hotOrCold = isHot ? "Hot" : "Cold";
        return Beverage::toString() + "\nType: " + type + "\nHot/Cold: " + hotOrCold +
               "\nCreamer: " + (hasCreamer ? "Yes" : "No") + "\nSweetener: " + (hasSweetener ? "Yes" : "No") +
               "\nLemon: " + (hasLemon ? "Yes" : "No");
    }
};

class Soda : public Beverage {
private:
    std::string brand;
    std::string sodaType;
    bool isDiet;

public:
    Soda(std::string name, std::string description, std::string servingSize, int calories, double price,
         std::string brand, std::string sodaType, bool isDiet)
        : Beverage(name, description, servingSize, calories, price),
          brand(brand), sodaType(sodaType), isDiet(isDiet) {}

    // Additional getter/setter methods specific to Soda
    std::string getBrand() const { return brand; }  // Removed semicolon
    std::string getSodaType() const { return sodaType; }  // Removed semicolon
};

int main() {
    // Create instances of beverages
    Coffee coffee("Black Coffee", "Classic black coffee", "Medium", 5, 2.5, "Dark", true, true, 3, false, false);
    Tea tea("Green Tea", "Healthy green tea", "Large", 0, 1.8, "Green", true, true, true, false);
    Soda soda("Coca-Cola", "Classic cola", "Can", 150, 1.0, "Coca-Cola", "Cola", false);

    // Display information about beverages
    std::cout << "Coffee:\n" << coffee.toString() << "\n\n";
    std::cout << "Tea:\n" << tea.toString() << "\n\n";
    std::cout << "Soda:\n" << soda.toString() << "\n\n";

    return 0;
}
