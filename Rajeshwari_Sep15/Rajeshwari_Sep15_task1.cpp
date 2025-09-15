#include <iostream>
#include <string>
using namespace std;

class FleetVehicle {
private:
    int m_vehicleID;
    float m_fuelLevel;
    double m_distanceTravelled;
    char m_status;       
    bool m_isAvailable;
    string m_driverName;

public:
    // Default Constructor
    FleetVehicle()
        : m_vehicleID(0),
          m_fuelLevel(50.0),
          m_distanceTravelled(0.0),
          m_status('A'),
          m_isAvailable(true),
          m_driverName("Unassigned") {}

    // Parameterized Constructor
    FleetVehicle(int vehicleID, float fuelLevel, double distanceTravelled,
                 char status, bool isAvailable, const string& driverName)
        : m_vehicleID(vehicleID),
          m_fuelLevel(fuelLevel),
          m_distanceTravelled(distanceTravelled),
          m_status(status),
          m_isAvailable(isAvailable),
          m_driverName(driverName) {}

    // Destructor
    ~FleetVehicle() {
        cout << "Destructor called for vehicle ID: " << m_vehicleID << ";" << endl;
    }

    // ======= Getters =======
    int GetVehicleID() const { return m_vehicleID; }
    float GetFuelLevel() const { return m_fuelLevel; }
    double GetDistanceTravelled() const { return m_distanceTravelled; }
    char GetStatus() const { return m_status; }
    bool GetIsAvailable() const { return m_isAvailable; }
    string GetDriverName() const { return m_driverName; }

    // ======= Setters =======
    void SetVehicleID(int id) { m_vehicleID = id; }
    void SetFuelLevel(float fuel) {
        if (fuel >= 0.0)
            m_fuelLevel = fuel;
    }
    void SetDistanceTravelled(double distance) {
        if (distance >= 0.0)
            m_distanceTravelled = distance;
    }
    void SetStatus(char status) { m_status = status; }
    void SetIsAvailable(bool available) { m_isAvailable = available; }
    void SetDriverName(const string& name) { m_driverName = name; }

    // Update status
    void updateStatus() {
        if (m_fuelLevel < 10.0 || !m_isAvailable) {
            m_status = 'I'; // Inactive
        } else {
            m_status = 'A'; // Active
        }
    }

    // Display vehicle information
    void displayInfo() const {
        cout << "\n--- Vehicle Info ---\n";
        cout << "Vehicle ID        : " << m_vehicleID << '\n';
        cout << "Fuel Level        : " << m_fuelLevel << " liters\n";
        cout << "Distance Travelled: " << m_distanceTravelled << " km\n";
        cout << "Status            : " << (m_status == 'A' ? "Active" : "Inactive") << '\n';
        cout << "Availability      : " << (m_isAvailable ? "Available" : "Not Available") << '\n';
        cout << "Driver Name       : " << m_driverName << '\n';
        cout << "----------------------\n";
    }
};

// ======= Global Functions =======

// Assign a driver to a vehicle
void assignDriver(FleetVehicle &vehicle, const string& name) {
    vehicle.SetDriverName(name);
    cout << "Driver " << vehicle.GetDriverName()
         << " has been assigned to Vehicle ID " << vehicle.GetVehicleID() << ".\n";
}

// Refuel a vehicle
void refuelVehicle(FleetVehicle &vehicle, float fuelAmount) {
    if (fuelAmount <= 0) {
        throw invalid_argument("Fuel amount must be greater than 0!");
    }
    float newFuelLevel = vehicle.GetFuelLevel() + fuelAmount;
    vehicle.SetFuelLevel(newFuelLevel);
    cout << "Vehicle ID " << vehicle.GetVehicleID()
         << " refueled. New Fuel Level: " << vehicle.GetFuelLevel() << " liters\n";
}


int main() {
    const int SIZE = 3;               
    FleetVehicle fleet[SIZE];         

    int choice;

    do {
        cout << "\n===== FLEET MANAGEMENT MENU =====\n";
        cout << "1. Add vehicle details\n";
        cout << "2. Assign a driver\n";
        cout << "3. Refuel a vehicle\n";
        cout << "4. Update status\n";
        cout << "5. Display vehicle info\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: { // Add vehicle details using parameterized constructor
            int index;
            cout << "Enter vehicle index (0-" << SIZE - 1 << "): ";
            cin >> index;

            if (index < 0 || index >= SIZE) {
                cout << "Invalid index! Please try again.\n";
                break;
            }

            int id;
            float fuel;
            double distance;
            char status;
            bool available;
            string driver;

            cout << "Enter Vehicle ID: ";
            cin >> id;
            cout << "Enter Fuel Level: ";
            cin >> fuel;
            cout << "Enter Distance Travelled: ";
            cin >> distance;
            cout << "Enter Status (A/I): ";
            cin >> status;
            cout << "Is Available? (1 for Yes, 0 for No): ";
            cin >> available;
            cin.ignore(); 
            cout << "Enter Driver Name: ";
            getline(cin, driver);

            
            fleet[index] = FleetVehicle(id, fuel, distance, status, available, driver);
            cout << "Vehicle details added successfully!\n";
            break;
        }

        case 2: { // Assign a driver
            int index;
            cout << "Enter vehicle index (0-" << SIZE - 1 << ") to assign driver: ";
            cin >> index;

            if (index < 0 || index >= SIZE) {
                cout << "Invalid index! Please try again.\n";
                break;
            }

            cin.ignore();
            string driverName;
            cout << "Enter Driver Name: ";
            getline(cin, driverName);

            assignDriver(fleet[index], driverName);
            break;
        }

        case 3: { // Refuel a vehicle
            int index;
            float fuelAmount;
            cout << "Enter vehicle index (0-" << SIZE - 1 << ") to refuel: ";
            cin >> index;

            if (index < 0 || index >= SIZE) {
                cout << "Invalid index! Please try again.\n";
                break;
            }

            cout << "Enter fuel amount to add: ";
            cin >> fuelAmount;

            try {
                refuelVehicle(fleet[index], fuelAmount);
            } catch (const invalid_argument &e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }

        case 4: { // Update status
            int index;
            cout << "Enter vehicle index (0-" << SIZE - 1 << ") to update status: ";
            cin >> index;

            if (index < 0 || index >= SIZE) {
                cout << "Invalid index! Please try again.\n";
                break;
            }

            fleet[index].updateStatus();
            cout << "Status updated for Vehicle ID " << fleet[index].GetVehicleID() << ".\n";
            break;
        }

        case 5: { // Display all vehicles
            cout << "\n--- Displaying Vehicle Information ---\n";
            for (int i = 0; i < SIZE; i++) {
                cout << "\nVehicle Slot [" << i << "]:\n";
                fleet[i].displayInfo();
            }
            break;
        }

        case 6:
            cout << "Exiting program... Thank you!\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);
   

}
