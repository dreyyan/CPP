#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string type;
    string name;
    string manufacturer;
    int year;

public:
    Vehicle(string type = "?", string name = "?", string manufacturer = "?", int year = 0)
        : type(type), name(name), manufacturer(manufacturer), year(year) {}

    virtual void displayInfo() = 0;

    void setInfo() {
        setType();
        setName();
        setManufacturer();
        setYear();
    }

    void setType() {
        cout << "Change Type: ";
        getline(cin, type);
    }
    void setName() {
        cout << "Change Name: ";
        getline(cin, name);
    }
    void setManufacturer() {
        cout << "Change Manufacturer: ";
        getline(cin, manufacturer);
    }
    void setYear() {
        cout << "Change Year: ";
        cin >> year;
    }
};

class Car : public Vehicle {
private:
    int numberOfDoors;

public:
    Car(string type = "Car", string name = "?", string manufacturer = "?", int year = 0, int numberOfDoors = 4)
        : Vehicle(type, name, manufacturer, year), numberOfDoors(numberOfDoors) {}

    void displayInfo() override {
        setNumberOfDoors();
        cout << "Type: " << type;
        cout << "\nName: " << name;
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nYear: " << year;
        cout << "\n# of Doors: " << numberOfDoors << "\n";
    }

    void setNumberOfDoors() {
        cout << "Set # of Doors: ";
        cin >> numberOfDoors;
    }
};

class Motorcycle : public Vehicle {
public:
    Motorcycle(string type = "Motorcycle", string name = "?", string manufacturer = "?", int year = 0)
        : Vehicle(type, name, manufacturer, year) {}

    void displayInfo() override {
        cout << "Type: " << type;
        cout << "\nName: " << name;
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nYear: " << year << "\n";
    }

};

class Truck : public Vehicle {
private:
    float payloadCapacity;

public:
    Truck(string type = "Truck", string name = "?", string manufacturer = "?", int year = 0, float payloadCapacity = 0.00)
        : Vehicle(type, name, manufacturer, year), payloadCapacity(payloadCapacity) {}

    void displayInfo() override {
        setPayloadCapacity();
        cout << "Type: " << type;
        cout << "\nName: " << name;
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nYear: " << year;
        cout << "\nPayload Capacity(kg): " << payloadCapacity << "\n";
    }

    void setPayloadCapacity() {
        cout << "Set Payload Capacity(kg): ";
        cin >> payloadCapacity;
    }
};

void showVehicleInfo() {
    Truck *vehiclePointer = new Truck("N/A", "N/A", "N/A", 0, 0.00);
    vehiclePointer->setInfo();
    vehiclePointer->displayInfo();
    delete vehiclePointer;
}

int main() {
    showVehicleInfo();
    return 0;
}

