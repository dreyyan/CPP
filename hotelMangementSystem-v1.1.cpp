#include <iostream>
#include <string>
#include <ctime>
#include <memory>
#include <vector>
#include <iomanip>
using namespace std;

// TO IMPROVE:
// people staying in hotel
// listRooms() will also print its availability

struct Amenities {
    bool hasFan, hasAircon, hasWifi;
};

struct Restrictions {
    bool isSmokingAllowed, isPetFriendly;
};

struct Availability {
    bool isCleaned, maintenanceRequired, isOccupied, isAvailable;
};

class Hotel {
protected:
    unique_ptr<string> location;
    float rating;
    double rate;
    int rooms;

public:
    unique_ptr<string> name;
    vector<int> roomList;

    Hotel(const string& hotelName, const string& hotelLocation, float hotelRating, double hotelRate, int hotelRooms)
        : name(make_unique<string>(hotelName)), location(make_unique<string>(hotelLocation)), rating(hotelRating), rate(hotelRate), rooms(hotelRooms) {
        cout << "\n>>>> Hotel established -> " << hotelName;
    }

    void displayInfo() {
        cout << "\n[-------------------------------]";
        cout << "\n| Hotel Details |";
        cout << "\nHotel Name: " << *name;
        cout << "\nLocation: " << *location;
        cout << "\nRating: " << rating << " / 5 stars";
        cout << fixed << setprecision(2) << "\nHotel Rate: $" << rate;
        cout << "\n# of Rooms: " << rooms;
        cout << "\n[-------------------------------]";
    }

    void listRooms() {
        cout << "\nRoom List:";
        for (int i = 0; i < roomList.size(); i++) {
            cout << "\n* Room " << roomList[i];
        }
    }
};

class HotelRoom {
protected:
    double size;
    int roomNumber, numOfBeds, numOfBathrooms, roomSize;
    Amenities amenities;
    Restrictions restrictions;
    Availability availability;

public:
    HotelRoom(Hotel& hotel, int roomRoomNumber = 0, double roomSize = 0, int roomNumOfBeds = 0, int roomNumOfBathrooms = 0, bool roomHasFan = false, bool roomHasAircon = false, bool roomHasWifi = false, bool roomSmokingAllowed = false, bool roomPetFriendly = false, bool roomIsCleaned = false, bool roomMaintenanceRequired = false, bool roomIsOccupied = false, bool roomIsAvailable = false)
        : roomNumber(roomRoomNumber), size(roomSize), numOfBeds(roomNumOfBeds), numOfBathrooms(roomNumOfBathrooms),
    amenities{roomHasFan, roomHasAircon, roomHasWifi},
    restrictions{roomSmokingAllowed, roomPetFriendly},
    availability{roomIsCleaned, roomMaintenanceRequired, roomIsOccupied, roomIsAvailable} {
        cout << "\n>>> Hotel Room No. " << roomNumber << " Built [" << *hotel.name << "]";
        hotel.roomList.push_back(roomNumber);
    }

    void displayInfo() {
        cout << "\n[------------------------]";
        cout << "\n| Room Details |";
        cout << "\nRoom Number: " << roomNumber;
        cout << "\nSize: " << size << " sqm";
        cout << "\nBeds: " << numOfBeds;
        cout << "\nBathrooms: " << numOfBathrooms;
        cout << "\n| Amenities |";
        cout << "\nFan: " << (amenities.hasFan ? "Yes" : "No");
        cout << "\nAircon: " << (amenities.hasAircon ? "Yes" : "No");
        cout << "\nWi-Fi: " << (amenities.hasWifi ? "Yes" : "No");
        cout << "\n| Restrictions |";
        cout << "\nSmoking: " << (restrictions.isSmokingAllowed ? "Yes" : "No");
        cout << "\nPets: " << (restrictions.isPetFriendly ? "Yes" : "No");
        cout << "\n\nAvailable: " << (availability.isAvailable ? "Yes" : "No");
        cout << "\n[--------------]";
    }
};


// Room No., Size, Beds, Bathrooms | Fan, Aircon, WiFi, Smoking, Pet | isClean, needsMaintenance, Occupied, Available
int main() {
    unique_ptr<Hotel> hotel1 = make_unique<Hotel>("Lafayette Park Square", "Megaworld, Iloilo City", 4.8, 40, 20);
    unique_ptr<HotelRoom> room1 = make_unique<HotelRoom>(*hotel1, 1, 25.5, 1, false, true, true, false, true, false, false, true);
    unique_ptr<HotelRoom> room2 = make_unique<HotelRoom>(*hotel1, 2, 35, 3, 2, true, true, true, true, true, false, false, true);

    hotel1->displayInfo();
    room1->displayInfo();
    room2->displayInfo();
    hotel1->listRooms();
    return 0;
}