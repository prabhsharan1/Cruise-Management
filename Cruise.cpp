#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <ctime>

using namespace std;

// Define global constants and data types
const int MAX_PEOPLE = 20; // Max number of people per booking

// A structure to store passenger information
struct Person {
    string name;
    int age;
    string sex;
    string passportNumber;
};

// Class to manage personal details
class PersonDetails {
private:
    int travelCode;
    string familyName;
    string address;
    string phoneNumber;
    vector<Person> members;

public:
    PersonDetails(int code) : travelCode(code) {}

    void inputPersonalDetails();
    void displayPersonalDetails() const;
    int getTravelCode() const { return travelCode; }
    void addMember(const Person& person) { members.push_back(person); }
    const vector<Person>& getMembers() const { return members; }
};

// Method to input personal details
void PersonDetails::inputPersonalDetails() {
    cout << "\nEnter Family Name: ";
    cin >> familyName;
    cout << "\nEnter Address: ";
    cin.ignore();
    getline(cin, address);
    cout << "\nEnter Phone Number (10 digits): ";
    cin >> phoneNumber;

    int numPeople;
    cout << "\nEnter the number of people traveling: ";
    cin >> numPeople;

    for (int i = 0; i < numPeople; ++i) {
        Person person;
        cout << "\nEnter details for member " << i + 1 << endl;
        cout << "Name: ";
        cin >> person.name;
        cout << "Age: ";
        cin >> person.age;
        cout << "Sex (M/F): ";
        cin >> person.sex;
        cout << "Passport Number: ";
        cin >> person.passportNumber;

        addMember(person);
    }
}

// Method to display personal details
void PersonDetails::displayPersonalDetails() const {
    cout << "\nFamily Name: " << familyName << endl;
    cout << "Address: " << address << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Members: " << endl;

    for (const auto& member : members) {
        cout << "Name: " << member.name << ", Age: " << member.age << ", Sex: " << member.sex
             << ", Passport Number: " << member.passportNumber << endl;
    }
}

// Class to manage travel details
class TravelDetails {
private:
    int travelCode;
    string boardingPoint;
    string destination;
    string departureDate;
    int deckChoice;
    int cabinChoice;
    vector<string> facilities;

public:
    TravelDetails(int code) : travelCode(code) {}

    void inputTravelDetails();
    void displayTravelDetails() const;
    int getTravelCode() const { return travelCode; }
    void addFacility(const string& facility) { facilities.push_back(facility); }
};

// Method to input travel details
void TravelDetails::inputTravelDetails() {
    cout << "\nEnter Boarding Point: ";
    cin >> boardingPoint;
    cout << "\nEnter Destination: ";
    cin >> destination;
    cout << "\nEnter Date of Departure (DD/MM/YYYY): ";
    cin >> departureDate;

    cout << "\nChoose Deck (1-Top, 2-Middle, 3-Bottom): ";
    cin >> deckChoice;
    cout << "\nChoose Cabin (1-AC, 2-Non-AC): ";
    cin >> cabinChoice;

    int choice;
    cout << "\nSelect Facilities (enter 0 to stop):" << endl;
    cout << "1. Swimming Pool, 2. Gym, 3. Sports, 4. Spa, 5. Salon, 6. Theatre" << endl;
    while (true) {
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 0) break;

        switch (choice) {
        case 1: addFacility("Swimming Pool"); break;
        case 2: addFacility("Gym"); break;
        case 3: addFacility("Sports"); break;
        case 4: addFacility("Spa"); break;
        case 5: addFacility("Salon"); break;
        case 6: addFacility("Theatre"); break;
        default: cout << "Invalid choice." << endl; continue;
        }
    }
}

// Method to display travel details
void TravelDetails::displayTravelDetails() const {
    cout << "\nBoarding Point: " << boardingPoint << endl;
    cout << "Destination: " << destination << endl;
    cout << "Date of Departure: " << departureDate << endl;
    cout << "Deck: " << (deckChoice == 1 ? "Top Deck" : deckChoice == 2 ? "Middle Deck" : "Bottom Deck") << endl;
    cout << "Cabin: " << (cabinChoice == 1 ? "AC" : "Non-AC") << endl;

    cout << "Facilities: ";
    for (const auto& facility : facilities) {
        cout << facility << " ";
    }
    cout << endl;
}

// Main program for user interaction
int main() {
    int travelCode;
    cout << "Enter Travel Code: ";
    cin >> travelCode;

    PersonDetails personDetails(travelCode);
    personDetails.inputPersonalDetails();

    TravelDetails travelDetails(travelCode);
    travelDetails.inputTravelDetails();

    personDetails.displayPersonalDetails();
    travelDetails.displayTravelDetails();

    return 0;
}
