#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include <ctime>
#include <vector>
using namespace std;

// TO IMPROVE:
// customizeFeatures();
// displayVehicleList(), drive(), destroyVehicle();
// use enum classes

// Vehicle > TwoWheels > Motorcycle/Bicycle/EBike
// Vehicle > ThreeWheels > Tricycle
// Vehicle > FourWheels > Car/Truck/Bus/Van/SUV/ATV/Jeep

// Base Class: Vehicle
class Vehicle {
protected:
    // Base Features
    string manufacturer, model, wheelType;

    // Physical Features
    string color, headlights, taillights, dimensions, bumperType;
    double lengthDimension, widthDimension, heightDimension;
public:
    Vehicle(string vehicleManufacturer, string vehicleModel, string vehicleLicensePlate, int vehicleNumWheels)
        : manufacturer(vehicleManufacturer), model(vehicleModel), licensePlate(vehicleLicensePlate), numWheels(vehicleNumWheels) {}

    int numWheels;
    string licensePlate;
    string returnLicensePlate(auto& vehicle) {
        return vehicle->licensePlate;
    }

    void displayVehicleInfo() {
        cout << "\n~ displaying vehicle info...";
        cout  << "\n>>>> [" << getType(); "] Chassis Created ";
        cout << "\nVehicle Details |";
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nLicense Plate: " << licensePlate;
        cout << "\n# of Wheels: " << numWheels;
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
    virtual string getType() = 0;
    // virtual void displayFeatures() = 0;
    // virtual void customizeFeatures() = 0;
};

vector<Vehicle> vehicleList;

// Derived Class: Vehicle > TwoWheels
class TwoWheels : public Vehicle {
private:

public:
    TwoWheels(string twoWheelsManufacturer, string twoWheelsVehicleModel, string twoWheelsLicensePlate, int twoWheelsNumWheels = 2)
        : Vehicle(twoWheelsManufacturer, twoWheelsVehicleModel, twoWheelsLicensePlate, twoWheelsNumWheels) {}

};

// Derived Class: Vehicle > ThreeWheels
class ThreeWheels : public Vehicle {
private:
    string bumperType;
public:
    ThreeWheels(string threeWheelsManufacturer, string threeWheelsVehicleModel, string threeWheelsLicensePlate, int threeWheelsNumWheels = 3)
        : Vehicle(threeWheelsManufacturer, threeWheelsVehicleModel, threeWheelsLicensePlate, threeWheelsNumWheels) {}

};

// Derived Class: Vehicle > FourWheels
class FourWheels : public Vehicle {
private:
    string bumperType;
public:
    FourWheels(string fourWheelsManufacturer, string fourWheelsVehicleModel, string fourWheelsLicensePlate, int fourWheelsNumWheels = 4)
    : Vehicle(fourWheelsManufacturer, fourWheelsVehicleModel, fourWheelsLicensePlate, fourWheelsNumWheels) {}

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
        cout << "\n# of Wheels: " << numWheels;
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
        cout << "\n# of Wheels: " << numWheels;
    }

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
        cout << "\n# of Wheels: " << numWheels;
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
        cout << "\n# of Wheels: " << numWheels;
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
        cout << "\n# of Wheels: " << numWheels;
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
        cout << "\n# of Wheels: " << numWheels;
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
        cout << "\n# of Wheels: " << numWheels;
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
        cout << "\n# of Wheels: " << numWheels;
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
        cout << "\n# of Wheels: " << numWheels;
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
        cout << "\n# of Wheels: " << numWheels;
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
        cout << "\n# of Wheels: " << numWheels;
    }

    string getType() override {
        return "Jeep";
    }
};

class Garage {
public:
    // Vectors
    vector<unique_ptr<Vehicle>> vehicleList;
    vector<unique_ptr<Vehicle>> travellingVehicles;
    vector<unique_ptr<Vehicle>> destroyedVehicles;
    // Main Components
    bool hasBody = false, hasEngine = false, hasBattery = false, hasTransmission = false;
    // Secondary Components
    bool hasBrakeSystem = false, hasSteeringSystem = false, hasFuelSystem = false, hasExhaustSystem = false, hasCoolingSystem = false;
    // Tire Components
    bool hasFrontLeftTire = false, hasFrontRightTire = false, hasBackLeftTire = false, hasBackRightTire = false, hasFrontTire = false, hasBackTire = false;
    // Parts Conditions
    int bodyCondition = 100, engineCondition = 100, batteryCondition = 100, frontLeftTireCondition = 0, frontRightTireCondition = 0, backLeftTireCondition = 0, backRightTireCondition = 0, frontTireCondition = 0, backTireCondition = 0;

    // Blueprint
    void makeBody()  {
        cout << "\n>> making Body...";
        hasBody = true;
    }
    void makeEngine() {
        cout << "\n>> making Engine...";
        hasEngine = true;
    }
    void installBattery() {
        cout << "\n>> installing Battery...";
        hasBattery = true;
    }
    void makeTransmission() {
        cout << "\n>> making Transmission...";
        hasTransmission = true;
    }
    void makeWheels(Vehicle& vehicle) {
        cout << "\n>> making Wheels...";
        if (vehicle.numWheels == 2) {
            hasFrontTire = true;
            hasBackTire = true;
        }

        else if (vehicle.numWheels == 3) {
            hasFrontTire = true;
            hasBackLeftTire = true;
            hasBackRightTire = true;
        }

        else if (vehicle.numWheels == 4) {
            hasFrontLeftTire = true;
            hasFrontRightTire = true;
            hasBackLeftTire = true;
            hasBackRightTire = true;
        }
    }
    void addTires() {
        cout << "\n>> adding Tires...";
        hasFrontTire = true;
        hasBackTire = true;
    }
    void installBrakeSystem()  {
        cout << "\n>> installing Brake System...";
    }
    void installSteeringSystem() {
        cout << "\n>> installing Steering System...";
    }
    void installFuelSystem() {
        cout << "\n>> installing Fuel System...";
    }
    void installExhaustSystem() {
        cout << "\n>> installing Exhaust System...";
    }
    void installCoolingSystem() {
        cout << "\n>> installing Cooling System...";
    }

    // Maintenance
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

    // Special Functions
    void chargeBattery() {
        int progressBar;
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

    // Getters
    string getVehicleManufacturer() {
        string manufacturer;
        cout << "\nManufacturer: ";
        getline(cin, manufacturer);
        while (manufacturer.empty()) {
            cout << "\nInvalid manufacturer. Please try again.";
            cout << "\nManufacturer: ";
            getline(cin, manufacturer);
        }
        return manufacturer;
    }

    string getVehicleModel() {
        string model;
        cout << "\nModel: ";
        getline(cin, model);
        while (model.empty()) {
            cout << "\nInvalid model. Please try again.";
            cout << "\nModel: ";
            getline(cin, model);
        }
        return model;
    }

    string getVehicleLicensePlate() {
        string licensePlate;
        bool validLicensePlate = false;
        cout << "\nLicense Plate(AAA1111): ";
        getline(cin, licensePlate);

        // Check License Plate Format
        if (licensePlate.length() == 7) {
            if (isalpha(licensePlate[0]) && isalpha(licensePlate[1]) && isalpha(licensePlate[2]) && isdigit(licensePlate[3]) && isdigit(licensePlate[4]) && isdigit(licensePlate[5]) && isdigit(licensePlate[6])) {
                validLicensePlate = true;
            }
        }

        while (licensePlate.empty() || !validLicensePlate) {
            cout << "\nInvalid License Plate. Please enter valid license plate.";
            cout << "\nLicense Plate: ";
            getline(cin, licensePlate);
        }
        return licensePlate;
    }

    string lowercaseConversion(const string& vehicleChoice) {
        string lowercaseVehicleChoice;
        for (char c : vehicleChoice) {
            lowercaseVehicleChoice += tolower(c);
        }
        return lowercaseVehicleChoice;
    }

    // Create Vehicle
    void createVehicle() {
        int wheelsChoice;
        string vehicleChoice;
        cout << "\n~ creating vehicle...";

        cin.ignore();
        cout << "\n| Vehicle Information |";
        string manufacturer = getVehicleManufacturer();
        string model = getVehicleModel();
        string licensePlate = getVehicleLicensePlate();

        // Vehicle Type
        cout <<"\n[ 2 / 3 / 4 ] Wheels: ";
        cin >> wheelsChoice;
        cin.ignore();
        while (wheelsChoice < 2 || wheelsChoice > 4) {
            cout << "\nInvalid Input. Enter a valid number.";
            cout <<"\n[ 2 / 3 / 4 ] Wheels: ";
            cin >> wheelsChoice;
            cin.ignore();
        }

        cout << (wheelsChoice == 2 ? "\n| 2-Wheel Vehicles |" : wheelsChoice == 3 ? "\n| 3-Wheel Vehicles |" : "\n| 4-Wheel Vehicles |");

        if (wheelsChoice == 2) {
            cout << "\n[ Motorcycle / Bicycle / EBike ]";
        }
        else if (wheelsChoice == 3) {
            cout << "\n[ Tricycle ]";
        }
        else {
            cout << "\n[ Car / Truck / Bus / Van / SUV / ATV / Jeep ]";
        }

        cout << "\nVehicle Type: ";
        getline(cin, vehicleChoice);
        string lowercaseVehicleChoice = lowercaseConversion(vehicleChoice);

        while (lowercaseVehicleChoice.empty() || (lowercaseVehicleChoice != "motorcycle" && lowercaseVehicleChoice != "bicycle" && lowercaseVehicleChoice != "ebike" && lowercaseVehicleChoice != "tricycle" && lowercaseVehicleChoice != "car" && lowercaseVehicleChoice != "truck" && lowercaseVehicleChoice != "bus" && lowercaseVehicleChoice != "van" && lowercaseVehicleChoice != "suv" && lowercaseVehicleChoice != "atv" && lowercaseVehicleChoice != "jeep")) {
            cout << "\nInvalid Vehicle Type.";
            cout << "\nVehicle Type: ";
            getline(cin, vehicleChoice);

            lowercaseVehicleChoice = lowercaseConversion(vehicleChoice);
        }

        if (wheelsChoice == 2) {
            if (lowercaseVehicleChoice == "motorcycle") {
                vehicleList.push_back(make_unique<Motorcycle>(manufacturer, model, licensePlate));
            }

            if (lowercaseVehicleChoice == "bicycle") {
                vehicleList.push_back(make_unique<Bicycle>(manufacturer, model, licensePlate));
            }

            if (lowercaseVehicleChoice == "ebike") {
                vehicleList.push_back(make_unique<EBike>(manufacturer, model, licensePlate));
            }
        }

        else if (wheelsChoice == 3) {
            if (lowercaseVehicleChoice == "tricycle") {
                vehicleList.push_back(make_unique<Tricycle>(manufacturer, model, licensePlate));
            }
        }

        else if (wheelsChoice == 4) {
            if (lowercaseVehicleChoice == "car") {
                vehicleList.push_back(make_unique<Car>(manufacturer, model, licensePlate));
            }

            if (lowercaseVehicleChoice == "truck") {
                vehicleList.push_back(make_unique<Truck>(manufacturer, model, licensePlate));
            }

            if (lowercaseVehicleChoice == "bus") {
                vehicleList.push_back(make_unique<Bus>(manufacturer, model, licensePlate));
            }

            if (lowercaseVehicleChoice == "van") {
                vehicleList.push_back(make_unique<Van>(manufacturer, model, licensePlate));
            }

            if (lowercaseVehicleChoice == "suv") {
                vehicleList.push_back(make_unique<SUV>(manufacturer, model, licensePlate));
            }

            if (lowercaseVehicleChoice == "atv") {
                vehicleList.push_back(make_unique<ATV>(manufacturer, model, licensePlate));
            }

            if (lowercaseVehicleChoice == "jeep") {
                vehicleList.push_back(make_unique<Jeep>(manufacturer, model, licensePlate));
            }
        }
    }

    // Display
        void displayVehicleCondition(Vehicle& vehicle) {
        cout << "\n>> displaying Vehicle Condition...";
        cout << "\n| VEHICLE CONDITION |";
        cout << "\n-------------------------------";
        /*cout << "\nVehicle Type: " << getType();*/

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

        // Display Condition Percentage
        cout << "\nBody: " << bodyCondition << "%";
        cout << "\nEngine: " << engineCondition << "%";
        cout << "\nBattery: " << batteryCondition << "%";
        if (vehicle.numWheels == 2) {
            cout << "\nTire(F): " << frontTireCondition << "%";
            cout << "\nTire(B): " << backTireCondition << "%";
        }
        else if (vehicle.numWheels == 3) {
            cout << "\nTire(FL): " << frontLeftTireCondition << "%";
            cout << "\nTire(FR): " << frontRightTireCondition << "%";
            cout << "\nTire(BL): " << backLeftTireCondition << "%";
            cout << "\nTire(BR): " << backRightTireCondition << "%";
        }
        else if (vehicle.numWheels == 4) {
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
        }
        else {
            cout << "\nError Displaying Vehicle Condition.";
        }

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
        if (vehicle.numWheels == 2) {
            if (frontTireCondition < 20) {
                cout << "\n-> Tire(F)";
            }
            if (backTireCondition < 20) {
                cout << "\n-> Tire(B)";
            }
        }
        else if (vehicle.numWheels == 3) {
            if (frontTireCondition < 20) {
                cout << "\n-> Tire(F)";
            }
            if (backLeftTireCondition < 20) {
                cout << "\n-> Tire(BL)";
            }
            if (backRightTireCondition < 20) {
                cout << "\n-> Tire(BR)";
            }
        }
        else if (vehicle.numWheels == 4) {
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
        }
        cout << "\n-------------------------------";
    }

    void displayVehicleList() {
        for (const auto& vehicle : vehicleList) {
            cout << "\n* " << vehicle->getType();
            cout << "[" << vehicle->returnLicensePlate(vehicle) << "]";
        }
    }

    void displayBlueprint() {
        cout << "\n~ displaying blueprint...";
        cout << "\n | Main Components |";
        cout << "\n-------------------------------";
        cout << "\nBody: " << (hasBody ? "Complete" : "Incomplete");
        cout << "\nEngine: " << (hasEngine ? "Complete" : "Incomplete");
        cout << "\nBattery: " << (hasBattery ? "Complete" : "Incomplete");
        cout << "\nTransmission: " << (hasTransmission ? "Complete" : "Incomplete");
        cout << "\nWheels: ";
        cout << "\nTires: ";
        cout << "\n-------------------------------";
        cout << "\n| Vehicle Systems |";
        cout << "\n-------------------------------";
        cout << "\nBrake System: " << (hasBrakeSystem ? "Complete" : "Incomplete");
        cout << "\nSteering System: " << (hasSteeringSystem ? "Complete" : "Incomplete");
        cout << "\nFuel System: " << (hasFuelSystem ? "Complete" : "Incomplete");
        cout << "\nExhaust System: " << (hasExhaustSystem ? "Complete" : "Incomplete");
        cout << "\nCooling System: " << (hasCoolingSystem ? "Complete" : "Incomplete");
        cout << "\n-------------------------------";
    }

    void buildParts() {
        string licensePlate;
        bool vehicleFound;
        cout << "\n~ building parts for vehicle...";
        displayVehicleList();
        cout << "\nEnter Vehicle License Plate: ";
        cin.ignore();
        getline(cin, licensePlate);

        if (licensePlate.empty()) {
            cout << "\nInvalid License Plate.";
            return;
        }
        cout  << "\nsearching for vehicle...";
        for (const auto& vehicle : vehicleList) {
            if (licensePlate == vehicle->returnLicensePlate(vehicle)) {
                vehicleFound = true;
                cout << "\nVehicle Found!";
                displayBlueprint();
                break;
            }
        }
    }

    void displayMenu() {
        int choice;

        do {
            cout << "\n| VEHICLE MANAGEMENT SYSTEM |";
            cout << "\n[1] | Create Vehicle";
            cout << "\n[2] | Build Parts";
            cout << "\n[3] | Display Vehicle Condition";
            cout << "\n[4] | Display Vehicle List";
            cout << "\n[5] | Drive";
            cout << "\n[6] | Destroy Vehicle";
            cout << "\n[7] | Exit";
            cout << "\n-> ";
            cin >> choice;

            switch(choice) {
                case 1:
                    createVehicle();
                    backToMenu();
                break;
                case 2:
                    buildParts();
                    backToMenu();
                break;
                case 3:
                    // displayVehicleCondition();
                    backToMenu();
                break;
                case 4:
                    cout << "\n~ displaying vehicle list...";
                    displayVehicleList();
                    backToMenu();
                break;
                case 5:
                    //Drive();
                    backToMenu();
                break;
                case 6:
                    //destroyVehicle();
                    backToMenu();
                break;
                case 7:
                    cout << "\nProgram Exited.";
                return;
                default:
                    cout << "\nInvalid Input. Please try again.";
                break;
            }
        } while(true);
    }
    
    void backToMenu() {
        char choice;
        cout << "\nReturn to menu[y/n]?: ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            return;
        }

        else if (choice == 'n' || choice == 'N') {
            cout << "\nProgram Exited.";
            exit(0);
        }
        else {
            cout << "\nInvalid Input.\n";
            cin >> choice;
        }
    }
};

int main() {
    unique_ptr<Garage> startProgram = make_unique<Garage>();
    startProgram->displayMenu();
    return 0;
}