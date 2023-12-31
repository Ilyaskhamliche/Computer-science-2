
#include <iostream>
#include <string>
#include <stdexcept>

class StereoReceiver {
private:
    std::string manufacturer;
    std::string model;
    std::string serialNum;
    int wattage;
    int channels;
    std::string band;
    double frequency;
    int volume;
    bool power;
    std::string customAttribute1;
    std::string customAttribute2;

public:
    StereoReceiver(std::string mfr, std::string mdl, std::string serial, int watt, int ch) {
        if (mfr.empty() || mdl.empty() || serial.empty()) {
            throw std::invalid_argument("Invalid Value - Manufacturer, Model, or Serial Number not provided.");
        }

        if (watt < 100 || ch > 10) {
            throw std::invalid_argument("Invalid Value - Inappropriate values for Wattage or Number of Channels.");
        }

        manufacturer = mfr;
        model = mdl;
        serialNum = serial;
        wattage = watt;
        channels = ch;
        band = "AM";
        frequency = 0.0;
        volume = 5;
        power = false;
        customAttribute1 = "";
        customAttribute2 = "";
    }

};

int main() {
    std::string manufacturer, model, serialNum;
    int wattage, channels;

    try {
        // Prompt the user for receiver information
        std::cout << "Enter the Manufacturer: ";
        std::cin >> manufacturer;

        std::cout << "Enter the Model: ";
        std::cin >> model;

        std::cout << "Enter the Serial Number: ";
        std::cin >> serialNum;
        
        if (manufacturer.empty() || model.empty() || serialNum.empty()) {
            throw std::invalid_argument("Invalid Value - Manufacturer, Model, or Serial Number not provided.");
        }
   
        std::cout << "Enter the Wattage: ";
        std::cin >> wattage;

        std::cout << "Enter the Number of Channels: ";
        std::cin >> channels;

        if (wattage < 100 || channels > 10) {
            throw std::invalid_argument("Invalid Value - Inappropriate values for Wattage or Number of Channels.");
        }

        // Create a StereoReceiver object
        StereoReceiver receiver(manufacturer, model, serialNum, wattage, channels);

    } catch (std::invalid_argument &ex) {
        std::cerr << ex.what() << std::endl;
    }
}
class StereoReceiver2 {
private:
    // ... (previous code remains the same)

public:
    StereoReceiver2 (std::string mfr, std::string mdl, std::string serial, int watt, int ch, std::string bnd = "AM", double freq = 0.0, int vol = 5) {
        if (mfr.empty() || mdl.empty() || serial.empty()) {
            throw std::invalid_argument("Invalid Value - Manufacturer, Model, or Serial Number not provided.");
        }

        if (watt < 100 ||ch > 10) {
            throw std::invalid_argument("Invalid Value - Inappropriate values for Wattage or Number of Channels.");
        }

        if (bnd != "AM" && bnd != "FM") {
            throw std::invalid_argument("Invalid Value - Inappropriate Band.");
        }

        if (freq < 0.0 || freq > 200.0) {
            throw std::invalid_argument("Invalid Value - Invalid Frequency.");
        }

        if (vol < 0 || vol > 10) {
            throw std::invalid_argument("Invalid Value - Invalid Volume.");
        }

    }


};

