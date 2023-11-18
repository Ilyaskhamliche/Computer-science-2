#include <iostream>
#include <vector>
#include <stdexcept>

class NerfGun {
private:
    std::string model;
    int range;
    int capacity;
    int dartCount;
    std::string gun;  // This line seems unnecessary and is causing a syntax error

public:
    NerfGun(const std::string& model, int range, int capacity)
        : model(model), range(range), capacity(capacity), dartCount(capacity) {
        if (capacity > 144) {
            throw std::overflow_error("Capacity exceeds the maximum limit of 144.");
        }
    }

    std::string getModel() const {
        return model;
    }

    int getCapacity() const {
        return capacity;
    }

    int getDartCount() const {
        return dartCount;
    }

    void fire() {
        if (dartCount <= 0) {
            throw std::underflow_error("Out of ammunition.");
        }
        --dartCount;
    }

    void reload(int quantity) {
        if (dartCount + quantity > capacity) {
            throw std::overflow_error("Reloading exceeds the gun's capacity.");
        }
        dartCount += quantity;
    }

    // Overloaded operators
    bool operator==(const NerfGun& other) const {
        return dartCount == other.dartCount;
    }

    bool operator<(const NerfGun& other) const {
        return dartCount < other.dartCount;
    }

    NerfGun& operator--() {
        fire();
        return *this;
    }

    NerfGun operator--(int) {
        NerfGun temp = *this;
        fire();
        return temp;
    }

    NerfGun& operator+=(int quantity) {
        reload(quantity);
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const NerfGun& gun) {
        os << "Model: " << gun.model << "\nRange: " << gun.range << "\nCapacity: " << gun.capacity
           << "\nDart Count: " << gun.dartCount << std::endl;
        return os;
    }
};

int main() {
    std::vector<NerfGun> guns;

    // Create 4 to 7 different guns
    guns.push_back(NerfGun("Blaster1", 140, 144));
    guns.push_back(NerfGun("Blaster2", 86, 32));
    guns.push_back(NerfGun("Blaster3", 100, 20));
    guns.push_back(NerfGun("Blaster4", 88, 99));

    for(const auto& gun : guns) {
        
        std::cout << gun << std::endl;
    }

    NerfGun maxAmmoGun = guns[0];
    for (const auto& gun : guns) {
        if (gun < maxAmmoGun) {
            maxAmmoGun = gun;
        }
    }
    std::cout << "Gun with the most ammunition:\n" << maxAmmoGun << std::endl;

    
    try {
        guns[0]--;
        guns[1] += 10;
        guns[2]--;
        guns[3] += 30;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Display updated gun information
    for (const auto& gun : guns) {
        std::cout << gun << std::endl;
    }

    return 0;
}
