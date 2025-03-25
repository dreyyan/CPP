#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include <ctime>
#include <vector>
using namespace std;

// TO IMPROVE:
// customizeFeatures();
// travel();
// loopMenu();

// Vehicle > TwoWheels > Motorcycle/Bicycle/EBike
// Vehicle > ThreeWheels > Tricycle
// Vehicle > FourWheels > Car/Truck/Bus/Van/SUV/ATV/Jeep

// Base Class: Vehicle
class Vehicle {
protected:
    // Base Features
    string manufacturer, model, licensePlate, wheelType;
    int wheelsAmount;

    // Physical Features
    string color, headlights, taillights, dimensions, bumperType;
    double lengthDimension, widthDimension, heightDimension;
    bool hasBody = false, hasEngine = false, hasBattery = false;

    int bodyCondition = 100, engineCondition = 100, batteryCondition = 100, frontLeftTireCondition = 0, frontRightTireCondition = 0, backLeftTireCondition = 0, backRightTireCondition = 0, frontTireCondition = 0, backTireCondition = 0;
    bool hasFrontLeftTire = false, hasFrontRightTire = false, hasBackLeftTire = false, hasBackRightTire = false, hasFrontTire = false, hasBackTire = false;
public:
    Vehicle(string vehicleManufacturer, string vehicleModel, string vehicleLicensePlate, int vehicleWheelsAmount)
        : manufacturer(vehicleManufacturer), model(vehicleModel), licensePlate(vehicleLicensePlate), wheelsAmount(vehicleWheelsAmount) {}

    void repairBody() {
        cout << "\n>> repairing Body...";
        bodyCondition = 100;
    }

    void repairEngine() {
        cout << "\n>> repairing Engine...";
        engineCondition = 100;
    }

    void replaceBattery() {
        cout << "\n>> replacing Battery...";
        batteryCondition = 100;
    }

    void replaceTires() {
        cout << "\n>> replacing Tires...";

        if (frontTireCondition < 100 && hasFrontTire) {
            frontTireCondition = 100;
            cout << "\n> replaced Front Tire";
        }
        else if (frontTireCondition == 100 && hasFrontTire) {
            cout << "\nFront Tire is already in perfect condition.";
        }

        if (backTireCondition < 100 && hasBackTire) {
            backTireCondition = 100;
            cout << "\n> replaced Back Tire";
        }
        else if (backTireCondition == 100 && hasBackTire) {
            cout << "\nBack Tire is already in perfect condition.";
        }

        if (frontLeftTireCondition < 100 && hasFrontLeftTire) {
            frontLeftTireCondition = 100;
            cout << "\n> replaced Front-Left Tire";
        }
        else if (frontLeftTireCondition == 100 && hasFrontLeftTire) {
            cout << "\nFront-Left Tire is already in perfect condition.";
        }

        if (frontRightTireCondition < 100 && hasFrontRightTire) {
            frontRightTireCondition = 100;
            cout << "\n> replaced Front-Right Tire";
        }
        else if (frontRightTireCondition == 100 && hasFrontRightTire) {
            cout << "\nFront-Right Tire is already in perfect condition.";
        }

        if (backLeftTireCondition < 100 && hasBackLeftTire) {
            backLeftTireCondition = 100;
            cout << "\n> replaced Back-Left Tire";
        }
        else if (backLeftTireCondition == 100 && hasBackLeftTire) {
            cout << "\nBack-Left Tire is already in perfect condition.";
        }

        if (backRightTireCondition < 100 && hasBackRightTire) {
            backRightTireCondition = 100;
            cout << "\n> replaced Back-Right Tire";
        }
        else if (backRightTireCondition == 100 && hasBackRightTire) {
            cout << "\nBack-Right Tire is already in perfect condition.";
        }
    }

    void displayFeatures() {
        cout << "\n| FEATURES |";
        cout << "\n---------------------------";
        cout << "\nColor: " << color;
        cout << "\nDimensions(L/W/H): " << lengthDimension << " mm / " << widthDimension << " mm / " << heightDimension << " mm";
        cout << "\n# of Headlights: " << headlights;
        cout << "\n# of Taillights: " << taillights;
        cout << "\nWheel Type: " << wheelType;
        cout << "\nBumper Type: " << bumperType;
        cout << "\n---------------------------";
    }

    void customizeFeatures() {
        cout << "\ncustomizing features...";
        cout << "\nColor: ";
        getline(cin, color);

        while (true) {
            cout << "\nDimensions(mm): ";
            getline(cin, dimensions);

            stringstream ss(dimensions);
            if (ss >> lengthDimension >> widthDimension >> heightDimension) {
                if (ss.eof()) {
                    break;
                }
            }
            cout << "Invalid input. Enter dimensions(LL/WW/HH) in mm separately using spaces.";
        }

        cout << "\n# of Headlights: ";
        cin >> headlights;
        cout << "\n# of Taillights: ";
        cin >> taillights;
        cin.ignore();
        cout << "\nWheel Type( steel | alloy | cast | spoked ): ";
        getline(cin, wheelType);
        if (wheelType != "steel" && wheelType != "alloy" && wheelType != "cast" && wheelType != "spoked") {
            cout << "\nInvalid input. Please enter a valid wheel type.";
            getline(cin, wheelType);
        }
        cout << "\nBumper Type( standard | reinforced | off-road ): ";
        getline(cin, bumperType);
        if (bumperType != "standard" && bumperType != "reinforced" && bumperType != "off-road") {
            cout << "\nInvalid input. Please enter a valid bumper type.";
            getline(cin, bumperType);
        }
        displayFeatures();
    }

    // Pure Virtual Functions
    virtual void makeBody() = 0;
    virtual void makeEngine() = 0;
    virtual void makeTransmission() = 0;
    virtual void makeWheels() = 0;
    virtual void addTires() = 0;
    virtual void installBattery() = 0;
    virtual void installBrakeSystem() = 0;
    virtual void installSteeringSystem() = 0;
    virtual void installFuelSystem() = 0;
    virtual void installExhaustSystem() = 0;
    virtual void installCoolingSystem() = 0;
    virtual void displayVehicleCondition() = 0;
    virtual string getType() = 0;
    // virtual void displayFeatures() = 0;
    // virtual void customizeFeatures() = 0;
};

vector<Vehicle> vehicleList;

// Derived Class: Vehicle > TwoWheels
class TwoWheels : public Vehicle {
private:

public:
    TwoWheels(string twoWheelsManufacturer, string twoWheelsVehicleModel, string twoWheelsLicensePlate, int twoWheelsWheelsAmount = 2)
        : Vehicle(twoWheelsManufacturer, twoWheelsVehicleModel, twoWheelsLicensePlate, twoWheelsWheelsAmount) {}

        void displayVehicleCondition() override {
        cout << "\n>> displaying Vehicle Condition...";
        cout << "\n| VEHICLE CONDITION |";
        cout << "\n-------------------------------";
        if (hasBody == false || hasEngine == false || hasFrontTire == false || hasBackTire == false) {
            cout << "Error displaying information. Check for missing parts.";
            return;
        }

        // Display Evaluation
        cout << "\nVehicle Health: ";
        if (bodyCondition < 20 || engineCondition < 20 || batteryCondition < 20 || frontTireCondition < 20 || backTireCondition < 20) {
            cout << "Needs Repair";
        }
        else if ((bodyCondition >= 20 && bodyCondition < 50) || (engineCondition >= 20 && engineCondition < 50) || (batteryCondition >= 20 && batteryCondition < 50) || (frontTireCondition >= 20 && frontTireCondition < 50) || (backTireCondition >= 20 && backTireCondition < 50)) {
            cout << "Moderate Condition";
        }
        else if ((bodyCondition >= 50 && bodyCondition < 100) || (engineCondition >= 50 && engineCondition < 100) || (batteryCondition >= 50 && batteryCondition < 100) || (frontTireCondition >= 50 && frontTireCondition << 100) || (backTireCondition >= 50 && backTireCondition < 100)) {
            cout << "Healthy Condition";
        }
        else {
            cout << "Perfect Condition";
        }

        cout << "\nBody: " << bodyCondition << "%";
        cout << "\nEngine: " << engineCondition << "%";
        cout << "\nBattery: " << batteryCondition << "%";
        cout << "\nTire(F): " << frontTireCondition << "%";
        cout << "\nTire(B): " << backTireCondition << "%";

        // Display Repair Suggestions
        cout << "\nRecommended Repair/s: ";
        if (bodyCondition < 20) {
            cout << "\n-> Body";
        }
        if (engineCondition < 20) {
            cout << "\n-> Engine";
        }
        if (batteryCondition < 20) {
            cout << "\n-> Battery";
        }
        if (frontTireCondition < 20) {
            cout << "\n-> Tire(F)";
        }
        if (backTireCondition < 20) {
            cout << "\n-> Tire(B)";
        }
        cout << "\n-------------------------------";
    }
};

// Derived Class: Vehicle > ThreeWheels
class ThreeWheels : public Vehicle {
private:
    string bumperType;
public:
    ThreeWheels(string threeWheelsManufacturer, string threeWheelsVehicleModel, string threeWheelsLicensePlate, int threeWheelsWheelsAmount = 3)
        : Vehicle(threeWheelsManufacturer, threeWheelsVehicleModel, threeWheelsLicensePlate, threeWheelsWheelsAmount) {}

    void displayVehicleCondition() override {
        cout << "\n>> displaying Vehicle Condition...";
        cout << "\n| VEHICLE CONDITION |";
        cout << "\n-------------------------------";
        if (hasBody == false || hasEngine == false || hasFrontLeftTire == false || hasBackLeftTire == false || hasBackRightTire == false) {
            cout << "Error displaying information. Check for missing parts.";
            return;
        }

        // Display Evaluation
        cout << "\nVehicle Health: ";
        if (bodyCondition < 20 || engineCondition < 20 || batteryCondition < 20 || frontLeftTireCondition < 20 || backLeftTireCondition < 20 || backRightTireCondition < 20) {
            cout << "Needs Repair";
        }
        else if ((bodyCondition >= 20 && bodyCondition < 50) || (engineCondition >= 20 && engineCondition < 50) || (batteryCondition >= 20 && batteryCondition < 50) || (frontLeftTireCondition >= 20 && frontLeftTireCondition < 50) || (backLeftTireCondition >= 20 && backLeftTireCondition < 50) || (backRightTireCondition >= 20 && backRightTireCondition < 50)) {
            cout << "Moderate Condition";
        }
        else if ((bodyCondition >= 50 && bodyCondition < 100) || (engineCondition >= 50 && engineCondition < 100) || (batteryCondition >= 50 && batteryCondition < 100) || (frontLeftTireCondition >= 50 && frontLeftTireCondition < 100) || (backLeftTireCondition >= 50 && backLeftTireCondition < 100) || (backRightTireCondition >= 50 && backRightTireCondition < 100)) {
            cout << "Healthy Condition";
        }
        else {
            cout << "Perfect Condition";
        }

        cout << "\nBody: " << bodyCondition << "%";
        cout << "\nEngine: " << engineCondition << "%";
        cout << "\nBattery: " << batteryCondition << "%";
        cout << "\nTire(FL): " << frontLeftTireCondition << "%";
        cout << "\nTire(BL): " << backLeftTireCondition << "%";
        cout << "\nTire(BR): " << backRightTireCondition << "%";

        // Display Repair Suggestions
        cout << "\nRecommended Repair/s: ";
        if (bodyCondition < 20) {
            cout << "\n-> Body";
        }
        if (engineCondition < 20) {
            cout << "\n-> Engine";
        }
        if (batteryCondition < 20) {
            cout << "\n-> Battery";
        }
        if (frontLeftTireCondition < 20) {
            cout << "\n-> Tire(FL)";
        }
        if (backLeftTireCondition < 20) {
            cout << "\n-> Tire(BL)";
        }
        if (backRightTireCondition < 20) {
            cout << "\n-> Tire(BR)";
        }
        cout << "\n-------------------------------";
    }
};

// Derived Class: Vehicle > FourWheels
class FourWheels : public Vehicle {
private:
    string bumperType;
public:
    FourWheels(string fourWheelsManufacturer, string fourWheelsVehicleModel, string fourWheelsLicensePlate, int fourWheelsWheelsAmount = 4)
    : Vehicle(fourWheelsManufacturer, fourWheelsVehicleModel, fourWheelsLicensePlate, fourWheelsWheelsAmount) {}

        void displayVehicleCondition() override {
        cout << "\n>> displaying Vehicle Condition...";
        cout << "\n| VEHICLE CONDITION |";
        cout << "\n-------------------------------";
        if (hasBody == false || hasEngine == false || hasFrontLeftTire == false || hasFrontRightTire == false || hasBackLeftTire == false || hasBackRightTire == false) {
            cout << "Error displaying information. Check for missing parts.";
            return;
        }

        cout << "\nVehicle Type: " << getType();
        // Display Evaluation
        cout << "\nVehicle Health: ";
        if (bodyCondition < 20 || engineCondition < 20 || batteryCondition < 20 || frontLeftTireCondition < 20 || frontRightTireCondition < 20 || backLeftTireCondition < 20 || backRightTireCondition < 20) {
            cout << "Needs Repair";
        }
        else if ((bodyCondition >= 20 && bodyCondition < 50) || (engineCondition >= 20 && engineCondition < 50) || (batteryCondition >= 20 && batteryCondition < 50) || (frontLeftTireCondition >= 20 && frontLeftTireCondition < 50) || (frontRightTireCondition >= 20 && frontRightTireCondition < 50) || (backLeftTireCondition >= 20 && backLeftTireCondition < 50) || (backRightTireCondition >= 20 && backRightTireCondition < 50)) {
            cout << "Moderate Condition";
        }
        else if ((bodyCondition >= 50 && bodyCondition < 100) || (engineCondition >= 50 && engineCondition < 100) || (batteryCondition >= 50 && batteryCondition < 100) || (frontLeftTireCondition >= 20 && frontLeftTireCondition < 50) || (frontRightTireCondition >= 20 && frontRightTireCondition < 50) || (backLeftTireCondition >= 20 && backLeftTireCondition < 50) || (backRightTireCondition >= 20 && backRightTireCondition < 50)) {
            cout << "Healthy Condition";
        }
        else {
            cout << "Perfect Condition";
        }

        cout << "\n\n                 Engine: " << engineCondition << "%    Battery: " << batteryCondition << "%\n";
        cout << "                 __________________________\n";
        cout << "                |               |          |\n";
        cout << "                |               |          |\n";
        cout << "                |_______________|__________|\n";
        cout << "               | |                        | |\n";
        cout << "         Tire(FL): " << frontLeftTireCondition << "%              Tire(FR): " << frontRightTireCondition << "%\n";
        cout << "               | |                        | |\n";
        cout << "                |                          | \n";
        cout << "                |                          |\n";
        cout << "                |                          |\n";
        cout << "                         Body: " << bodyCondition << "%\n";
        cout << "                |                          |\n";
        cout << "                |                          |\n";
        cout << "                |                          |\n";
        cout << "               | |                        | |\n";
        cout << "         Tire(BL): " << backLeftTireCondition << "%              Tire(BR): " << backRightTireCondition << "%\n";
        cout << "               | |                        | |\n";
        cout << "                |--------------------------|\n";
        cout << "                 |________________________|\n";

        // Display Repair Suggestions
        cout << "\nRecommended Repair/s: ";
        if (bodyCondition < 20) {
            cout << "\n-> Body";
        }
        if (engineCondition < 20) {
            cout << "\n-> Engine";
        }
        if (batteryCondition < 20) {
            cout << "\n-> Battery";
        }
        if (frontLeftTireCondition < 20) {
            cout << "\n-> Tire(FL)";
        }
        if (frontRightTireCondition < 20) {
            cout << "\n-> Tire(FR)";
        }
        if (backLeftTireCondition < 20) {
            cout << "\n-> Tire(BL)";
        }
        if (backRightTireCondition < 20) {
            cout << "\n-> Tire(BR)";
        }
        cout << "\n-------------------------------";
    }
};

// Derived Class: Vehicle > TwoWheels > Motorcycle
class Motorcycle : public TwoWheels {
public:
    Motorcycle(string motorcycleManufacturer, string motorcycleVehicleModel, string motorcycleLicensePlate)
: TwoWheels(motorcycleManufacturer, motorcycleVehicleModel, motorcycleLicensePlate, 2) {
        cout  << "\n>>>> [Motorcycle] Chassis Created";
        cout << "\nVehicle Details |";
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nLicense Plate No.: " << licensePlate;
        cout << "\n# of Wheels: " << wheelsAmount;
    }

    // Functions
    void makeBody() override {
        cout << "\n>> making Body...";
        hasBody = true;
    }
    void makeEngine() override {
        cout << "\n>> making Engine...";
        hasEngine = true;
    }
    void makeTransmission() override {
        cout << "\n>> making Transmission...";
    }
    void makeWheels() override {
        cout << "\n>> making Wheels...";
    }
    void addTires() override {
        cout << "\n>> adding Tires...";
        hasFrontTire = true;
        hasBackTire = true;
    }
    void installBattery() override {
        cout << "\n>> installing Battery...";
        hasBattery = true;
    }
    void installBrakeSystem() override {
        cout << "\n>> installing Brake System...";
    }
    void installSteeringSystem() override {
        cout << "\n>> installing Steering System...";
    }
    void installFuelSystem() override {
        cout << "\n>> installing Fuel System...";
    }
    void installExhaustSystem() override {
        cout << "\n>> installing Exhaust System...";
    }
    void installCoolingSystem() override {
        cout << "\n>> installing Cooling System...";
    }

    string getType() override {
        return "Motorcycle";
    }
};

// Derived Class: Vehicle > TwoWheels > Bicycle
class Bicycle : public TwoWheels {
public:
    Bicycle(string bicycleManufacturer, string bicycleVehicleModel, string bicycleLicensePlate)
: TwoWheels(bicycleManufacturer, bicycleVehicleModel, bicycleLicensePlate, 2) {
        cout  << "\n>>>> [Bicycle] Chassis Created ";
        cout << "\nVehicle Details |";
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nLicense Plate No.: " << licensePlate;
        cout << "\n# of Wheels: " << wheelsAmount;
    }

    // Functions
    void makeBody() override {
        cout << "\n>> making Body...";
        hasBody = true;
    }
    void makeWheels() override {
        cout << "\n>> making Wheels...";
    }
    void addTires() override {
        cout << "\n>> adding Tires...";
        hasFrontTire = true;
        hasBackTire = true;
    }
    void installBrakeSystem() override {
        cout << "\n>> installing Brake System...";
    }
    void installSteeringSystem() override {
        cout << "\n>> installing Steering System...";
    }
    void installBattery() override {}
    void makeEngine() override {}
    void makeTransmission() override {}
    void installFuelSystem() override {}
    void installExhaustSystem() override {}
    void installCoolingSystem() override {}

    string getType() override {
        return "Bicycle";
    }
};

// Derived Class: Vehicle > TwoWheels > EBike
class EBike : public TwoWheels {
private:
    int progressBar = 0;
public:
    EBike(string ebikeManufacturer, string ebikeVehicleModel, string ebikeLicensePlate)
: TwoWheels(ebikeManufacturer, ebikeVehicleModel, ebikeLicensePlate, 2) {
        cout  << "\n>>>> [E-Bike] Chassis Created";
        cout << "\nVehicle Details |";
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nLicense Plate No.: " << licensePlate;
        cout << "\n# of Wheels: " << wheelsAmount;
    }

    // Functions
    void makeBody() override {
        cout << "\n>> making Body...";
        hasBody = true;
    }
    void makeEngine() override {
        cout << "\n>> making Engine...";
        hasEngine = true;
    }
    void makeWheels() override {
        cout << "\n>> making Wheels...";
    }
    void addTires() override {
        cout << "\n>> adding Tires...";
        hasFrontTire = true;
        hasBackTire = true;
    }
    void installBattery() override {
        cout << "\n>> installing Battery...";
        hasBattery = true;
    }
    void installBrakeSystem() override {
        cout << "\n>> installing Brake System...";
    }
    void installSteeringSystem() override {
        cout << "\n>> installing Steering System...";
    }
    void makeTransmission() override {}
    void installExhaustSystem() override {}
    void installCoolingSystem() override {}
    void installFuelSystem() override {}

    void chargeBattery() {
        if (hasBattery) {
            cout << "\n>> charging Battery...\n";
            while (progressBar <= 100) {
                cout << "\rBattery: " << progressBar << "%" << flush;

                // Time Delay
                time_t startTime = time(nullptr); // Current Time
                while (time(nullptr) - startTime < 1); // Interval (Current Time - Time Started < 1sec)
                progressBar += 10; // Increment
            }
            cout << "\nCharging Complete!";
        }
    }

    string getType() override {
        return "E-Bike";
    }
};

// Derived Class: Vehicle > ThreeWheels > Tricycle
class Tricycle : public ThreeWheels {
public:
    Tricycle(string tricycleManufacturer, string tricycleVehicleModel, string tricycleLicensePlate)
: ThreeWheels(tricycleManufacturer, tricycleVehicleModel, tricycleLicensePlate, 3) {
        cout  << "\n>>>> [Tricycle] Chassis Created";
        cout << "\nVehicle Details |";
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nLicense Plate No.: " << licensePlate;
        cout << "\n# of Wheels: " << wheelsAmount;
    }

    // Functions
    void makeBody() override {
        cout << "\n>> making Body...";
        hasBody = true;
    }
    void makeEngine() override {
        cout << "\n>> making Engine...";
        hasEngine = true;
    }
    void makeTransmission() override {
        cout << "\n>> making Transmission...";
    }
    void makeWheels() override {
        cout << "\n>> making Wheels...";
    }
    void addTires() override {
        cout << "\n>> adding Tires...";
        hasFrontLeftTire = true;
        hasBackLeftTire = true;
        hasBackRightTire = true;
    }
    void installBattery() override {
        cout << "\n>> installing Battery...";
        hasBattery = true;
    }
    void installBrakeSystem() override {
        cout << "\n>> installing Brake System...";
    }
    void installSteeringSystem() override {
        cout << "\n>> installing Steering System...";
    }
    void installFuelSystem() override {
        cout << "\n>> installing Fuel System...";
    }
    void installExhaustSystem() override {
        cout << "\n>> installing Exhaust System...";
    }
    void installCoolingSystem() override {
        cout << "\n>> installing Cooling System...";
    }
    string getType() override {
        return "Tricycle";
    }
};

// Derived Class: Vehicle > FourWheels > Car
class Car : public FourWheels {
public:
    Car(string carManufacturer, string carVehicleModel, string carLicensePlate)
    : FourWheels(carManufacturer, carVehicleModel, carLicensePlate, 4) {
        cout  << "\n>>>> [Car] Chassis Created";
        cout << "\nVehicle Details |";
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nLicense Plate No.: " << licensePlate;
        cout << "\n# of Wheels: " << wheelsAmount;
    }

    // Functions
    void makeBody() override {
        cout << "\n>> making Body...";
        hasBody = true;
    }
    void makeEngine() override {
        cout << "\n>> making Engine...";
        hasEngine = true;
    }
    void makeTransmission() override {
        cout << "\n>> making Transmission...";
    }
    void makeWheels() override {
        cout << "\n>> making Wheels...";
    }
    void addTires() override {
        cout << "\n>> adding Tires...";
        hasFrontLeftTire = true;
        hasFrontRightTire = true;
        hasBackLeftTire = true;
        hasBackRightTire = true;
    }
    void installBattery() override {
        cout << "\n>> installing Battery...";
        hasBattery = true;
    }
    void installBrakeSystem() override {
        cout << "\n>> installing Brake System...";
    }
    void installSteeringSystem() override {
        cout << "\n>> installing Steering System...";
    }
    void installFuelSystem() override {
        cout << "\n>> installing Fuel System...";
    }
    void installExhaustSystem() override {
        cout << "\n>> installing Exhaust System...";
    }
    void installCoolingSystem() override {
        cout << "\n>> installing Cooling System...";
    }

    string getType() override {
        return "Car";
    }
};

// Derived Class: Vehicle > FourWheels > Truck
class Truck : public FourWheels {
public:
    Truck(string truckManufacturer, string truckVehicleModel, string truckLicensePlate)
: FourWheels(truckManufacturer, truckVehicleModel, truckLicensePlate, 4) {
        cout  << "\n>>>> [Truck] Chassis Created";
        cout << "\nVehicle Details |";
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nLicense Plate No.: " << licensePlate;
        cout << "\n# of Wheels: " << wheelsAmount;
    }

    // Functions
    void makeBody() override {
        cout << "\n>> making Body...";
        hasBody = true;
    }
    void makeEngine() override {
        cout << "\n>> making Engine...";
        hasEngine = true;
    }
    void makeTransmission() override {
        cout << "\n>> making Transmission...";
    }
    void makeWheels() override {
        cout << "\n>> making Wheels...";
    }
    void addTires() override {
        cout << "\n>> adding Tires...";
        hasFrontLeftTire = true;
        hasFrontRightTire = true;
        hasBackLeftTire = true;
        hasBackRightTire = true;
    }
    void installBattery() override {
        cout << "\n>> installing Battery...";
        hasBattery = true;
    }
    void installBrakeSystem() override {
        cout << "\n>> installing Brake System...";
    }
    void installSteeringSystem() override {
        cout << "\n>> installing Steering System...";
    }
    void installFuelSystem() override {
        cout << "\n>> installing Fuel System...";
    }
    void installExhaustSystem() override {
        cout << "\n>> installing Exhaust System...";
    }
    void installCoolingSystem() override {
        cout << "\n>> installing Cooling System...";
    }
    string getType() override {
        return "Truck";
    }
};

// Derived Class: Vehicle > FourWheels > Bus
class Bus : public FourWheels {
public:
    Bus(string busManufacturer, string busVehicleModel, string busLicensePlate)
: FourWheels(busManufacturer, busVehicleModel, busLicensePlate, 4) {
        cout  << "\n>>>> [Bus] Chassis Created";
        cout << "\nVehicle Details |";
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nLicense Plate No.: " << licensePlate;
        cout << "\n# of Wheels: " << wheelsAmount;
    }

    // Functions
    void makeBody() override {
        cout << "\n>> making Body...";
        hasBody = true;
    }
    void makeEngine() override {
        cout << "\n>> making Engine...";
        hasEngine = true;
    }
    void makeTransmission() override {
        cout << "\n>> making Transmission...";
    }
    void makeWheels() override {
        cout << "\n>> making Wheels...";
    }
    void addTires() override {
        cout << "\n>> adding Tires...";
        hasFrontLeftTire = true;
        hasFrontRightTire = true;
        hasBackLeftTire = true;
        hasBackRightTire = true;
    }
    void installBattery() override {
        cout << "\n>> installing Battery...";
        hasBattery = true;
    }
    void installBrakeSystem() override {
        cout << "\n>> installing Brake System...";
    }
    void installSteeringSystem() override {
        cout << "\n>> installing Steering System...";
    }
    void installFuelSystem() override {
        cout << "\n>> installing Fuel System...";
    }
    void installExhaustSystem() override {
        cout << "\n>> installing Exhaust System...";
    }
    void installCoolingSystem() override {
        cout << "\n>> installing Cooling System...";
    }

    string getType() override {
        return "Bus";
    }
};

// Derived Class: Vehicle > FourWheels > Van
class Van : public FourWheels {
public:
    Van(string vanManufacturer, string vanVehicleModel, string vanLicensePlate)
: FourWheels(vanManufacturer, vanVehicleModel, vanLicensePlate, 4) {
        cout  << "\n>>>> [Van] Chassis Created";
        cout << "\nVehicle Details |";
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nLicense Plate No.: " << licensePlate;
        cout << "\n# of Wheels: " << wheelsAmount;
    }

    // Functions
    void makeBody() override {
        cout << "\n>> making Body...";
        hasBody = true;
    }
    void makeEngine() override {
        cout << "\n>> making Engine...";
        hasEngine = true;
    }
    void makeTransmission() override {
        cout << "\n>> making Transmission...";
    }
    void makeWheels() override {
        cout << "\n>> making Wheels...";
    }
    void addTires() override {
        cout << "\n>> adding Tires...";
        hasFrontLeftTire = true;
        hasFrontRightTire = true;
        hasBackLeftTire = true;
        hasBackRightTire = true;
    }
    void installBattery() override {
        cout << "\n>> installing Battery...";
        hasBattery = true;
    }
    void installBrakeSystem() override {
        cout << "\n>> installing Brake System...";
    }
    void installSteeringSystem() override {
        cout << "\n>> installing Steering System...";
    }
    void installFuelSystem() override {
        cout << "\n>> installing Fuel System...";
    }
    void installExhaustSystem() override {
        cout << "\n>> installing Exhaust System...";
    }
    void installCoolingSystem() override {
        cout << "\n>> installing Cooling System...";
    }

    string getType() override {
        return "Van";
    }
};

// Derived Class: Vehicle > FourWheels > SUV
class SUV : public FourWheels {
public:
    SUV(string SUVManufacturer, string SUVVehicleModel, string SUVLicensePlate)
: FourWheels(SUVManufacturer, SUVVehicleModel, SUVLicensePlate, 4) {
        cout  << "\n>>>> [SUV] Chassis Created";
        cout << "\nVehicle Details |";
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nLicense Plate No.: " << licensePlate;
        cout << "\n# of Wheels: " << wheelsAmount;
    }

    // Functions
    void makeBody() override {
        cout << "\n>> making Body...";
        hasBody = true;
    }
    void makeEngine() override {
        cout << "\n>> making Engine...";
        hasEngine = true;
    }
    void makeTransmission() override {
        cout << "\n>> making Transmission...";
    }
    void makeWheels() override {
        cout << "\n>> making Wheels...";
    }
    void addTires() override {
        cout << "\n>> adding Tires...";
        hasFrontLeftTire = true;
        hasFrontRightTire = true;
        hasBackLeftTire = true;
        hasBackRightTire = true;
    }
    void installBattery() override {
        cout << "\n>> installing Battery...";
        hasBattery = true;
    }
    void installBrakeSystem() override {
        cout << "\n>> installing Brake System...";
    }
    void installSteeringSystem() override {
        cout << "\n>> installing Steering System...";
    }
    void installFuelSystem() override {
        cout << "\n>> installing Fuel System...";
    }
    void installExhaustSystem() override {
        cout << "\n>> installing Exhaust System...";
    }
    void installCoolingSystem() override {
        cout << "\n>> installing Cooling System...";
    }

    string getType() override {
        return "SUV";
    }
};

// Derived Class: Vehicle > FourWheels > ATV
class ATV : public FourWheels {
public:
    ATV(string ATVManufacturer, string ATVVehicleModel, string ATVLicensePlate)
: FourWheels(ATVManufacturer, ATVVehicleModel, ATVLicensePlate, 4) {
        cout  << "\n>>>> [ATV] Chassis Created";
        cout << "\nVehicle Details |";
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nLicense Plate No.: " << licensePlate;
        cout << "\n# of Wheels: " << wheelsAmount;
    }

    // Functions
    void makeBody() override {
        cout << "\n>> making Body...";
        hasBody = true;
    }
    void makeEngine() override {
        cout << "\n>> making Engine...";
        hasEngine = true;
    }
    void makeTransmission() override {
        cout << "\n>> making Transmission...";
    }
    void makeWheels() override {
        cout << "\n>> making Wheels...";
    }
    void addTires() override {
        cout << "\n>> adding Tires...";
        hasFrontLeftTire = true;
        hasFrontRightTire = true;
        hasBackLeftTire = true;
        hasBackRightTire = true;
    }
    void installBattery() override {
        cout << "\n>> installing Battery...";
        hasBattery = true;
    }
    void installBrakeSystem() override {
        cout << "\n>> installing Brake System...";
    }
    void installSteeringSystem() override {
        cout << "\n>> installing Steering System...";
    }
    void installFuelSystem() override {
        cout << "\n>> installing Fuel System...";
    }
    void installExhaustSystem() override {
        cout << "\n>> installing Exhaust System...";
    }
    void installCoolingSystem() override {
        cout << "\n>> installing Cooling System...";
    }

    string getType() override {
        return "ATV";
    }
};

// Derived Class: Vehicle > FourWheels > Jeep
class Jeep : public FourWheels {
public:
    Jeep(string jeepManufacturer, string jeepVehicleModel, string jeepLicensePlate)
: FourWheels(jeepManufacturer, jeepVehicleModel, jeepLicensePlate, 4) {
        cout  << "\n>>>> [Jeep] Chassis Created";
        cout << "\nVehicle Details |";
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nLicense Plate No.: " << licensePlate;
        cout << "\n# of Wheels: " << wheelsAmount;
    }

    // Functions
    void makeBody() override {
        cout << "\n>> making Body...";
        hasBody = true;
    }
    void makeEngine() override {
        cout << "\n>> making Engine...";
        hasEngine = true;
    }
    void makeTransmission() override {
        cout << "\n>> making Transmission...";
    }
    void makeWheels() override {
        cout << "\n>> making Wheels...";
    }
    void addTires() override {
        cout << "\n>> adding Tires...";
        hasFrontLeftTire = true;
        hasFrontRightTire = true;
        hasBackLeftTire = true;
        hasBackRightTire = true;
    }
    void installBattery() override {
        cout << "\n>> installing Battery...";
        hasBattery = true;
    }
    void installBrakeSystem() override {
        cout << "\n>> installing Brake System...";
    }
    void installSteeringSystem() override {
        cout << "\n>> installing Steering System...";
    }
    void installFuelSystem() override {
        cout << "\n>> installing Fuel System...";
    }
    void installExhaustSystem() override {
        cout << "\n>> installing Exhaust System...";
    }
    void installCoolingSystem() override {
        cout << "\n>> installing Cooling System...";
    }

    string getType() override {
        return "Jeep";
    }
};

void loopMenu() {
    int choice;

        cout << "\n| VEHICLE MANAGEMENT SYSTEM |";
        cout << "\n[1] | Create Vehicle";
        cout << "\n[2] | Build Parts";
        cout << "\n[3] | Display Vehicle Condition";
        cout << "\n[4] | Drive";
        cout << "\n[5] | Destroy Vehicle";
        cout << "\n[6] | Exit";
        cout << "\nEnter Number: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: {
                string vehicleChoice;
                shared_ptr<Vehicle> vehicle;

                cout << "\n[1] Create Vehicle";
                cout << "\n--------------------";
                cout << "\n2 Wheels -> [Motorcycle/Bicycle/EBike]";
                cout << "\n3 Wheels -> [Tricycle]";
                cout << "\n4 Wheels -> [Car/Truck/Bus/Van/SUV/ATV/Jeep]";
                cout << "\nEnter Vehicle Type: ";
                getline(cin, vehicleChoice);

                if(vehicleChoice == "motorcycle") {
                    string manufacturer, model, licensePlate;
                    cout << "\nManufacturer: ";
                    getline(cin, manufacturer);
                    cout << "Model: ";
                    getline(cin, model);
                    cout << "License Plate: ";
                    getline(cin, licensePlate);
                    vehicle = make_shared<Motorcycle>(manufacturer, model, licensePlate);
                    cout << "\nMotorcycle created successfully!\n";
                }
                else if (vehicleChoice == "bicycle") {
                    string manufacturer, model, licensePlate;
                    cout << "\nManufacturer: ";
                    getline(cin, manufacturer);
                    cout << "Model: ";
                    getline(cin, model);
                    cout << "License Plate: ";
                    getline(cin, licensePlate);
                    vehicle = make_shared<Bicycle>(manufacturer, model, licensePlate);
                    cout << "\nBicycle created successfully!\n";
                }
                else if (vehicleChoice == "ebike") {
                    string manufacturer, model, licensePlate;
                    cout << "\nManufacturer: ";
                    getline(cin, manufacturer);
                    cout << "Model: ";
                    getline(cin, model);
                    cout << "License Plate: ";
                    getline(cin, licensePlate);
                    vehicle = make_shared<EBike>(manufacturer, model, licensePlate);
                    cout << "\nE-Bike created successfully!\n";
                }
                else if (vehicleChoice == "tricycle") {
                    string manufacturer, model, licensePlate;
                    cout << "\nManufacturer: ";
                    getline(cin, manufacturer);
                    cout << "Model: ";
                    getline(cin, model);
                    cout << "License Plate: ";
                    getline(cin, licensePlate);
                    vehicle = make_shared<Tricycle>(manufacturer, model, licensePlate);
                    cout << "\nTricycle created successfully!\n";
                }
                else if (vehicleChoice == "car") {
                    string manufacturer, model, licensePlate;
                    cout << "\nManufacturer: ";
                    getline(cin, manufacturer);
                    cout << "Model: ";
                    getline(cin, model);
                    cout << "License Plate: ";
                    getline(cin, licensePlate);
                    vehicle = make_shared<Car>(manufacturer, model, licensePlate);
                    cout << "\nCar created successfully!\n";
                }
                else if (vehicleChoice == "truck") {
                    string manufacturer, model, licensePlate;
                    cout << "\nManufacturer: ";
                    getline(cin, manufacturer);
                    cout << "Model: ";
                    getline(cin, model);
                    cout << "License Plate: ";
                    getline(cin, licensePlate);
                    vehicle = make_shared<Truck>(manufacturer, model, licensePlate);
                    cout << "\nTruck created successfully!\n";
                }
                else if (vehicleChoice == "bus") {
                    string manufacturer, model, licensePlate;
                    cout << "\nManufacturer: ";
                    getline(cin, manufacturer);
                    cout << "Model: ";
                    getline(cin, model);
                    cout << "License Plate: ";
                    getline(cin, licensePlate);
                    vehicle = make_shared<Bus>(manufacturer, model, licensePlate);
                    cout << "\nBus created successfully!\n";
                }
                else if (vehicleChoice == "van") {
                    string manufacturer, model, licensePlate;
                    cout << "\nManufacturer: ";
                    getline(cin, manufacturer);
                    cout << "Model: ";
                    getline(cin, model);
                    cout << "License Plate: ";
                    getline(cin, licensePlate);
                    Van van(manufacturer, model, licensePlate);
                    cout << "\nVan created successfully!\n";
                }
                else if (vehicleChoice == "suv") {
                    string manufacturer, model, licensePlate;
                    cout << "\nManufacturer: ";
                    getline(cin, manufacturer);
                    cout << "Model: ";
                    getline(cin, model);
                    cout << "License Plate: ";
                    getline(cin, licensePlate);
                    vehicle = make_shared<SUV>(manufacturer, model, licensePlate);
                    cout << "\nSUV created successfully!\n";
                }
                else if (vehicleChoice == "atv") {
                    string manufacturer, model, licensePlate;
                    cout << "\nManufacturer: ";
                    getline(cin, manufacturer);
                    cout << "Model: ";
                    getline(cin, model);
                    cout << "License Plate: ";
                    getline(cin, licensePlate);
                    vehicle = make_shared<ATV>(manufacturer, model, licensePlate);
                    cout << "\nATV created successfully!\n";
                }
                else if (vehicleChoice == "jeep") {
                    string manufacturer, model, licensePlate;
                    cout << "\nManufacturer: ";
                    getline(cin, manufacturer);
                    cout << "Model: ";
                    getline(cin, model);
                    cout << "License Plate: ";
                    getline(cin, licensePlate);
                    vehicle = make_shared<Jeep>(manufacturer, model, licensePlate);
                    cout << "\nJeep created successfully!\n";
                }
                else {
                    cout << "\nInvalid Vehicle Type. Please try again.";
                }
                break;
            }

            case 6:
                cout << "\nProgram exited successfully.";
                return;
            break;
        }
    loopMenu();
    }
int main() {
    loopMenu();
    return 0;
}
