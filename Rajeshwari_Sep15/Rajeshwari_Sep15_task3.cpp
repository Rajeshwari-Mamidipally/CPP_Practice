#include <iostream>
#include <iomanip>
using namespace std;

// Enum for Component Type
enum ComponentType
{
    COMPONENT_TYPE_ENGINE = 0,
    COMPONENT_TYPE_AVIONICS,
    COMPONENT_TYPE_LANDING_GEAR,
    COMPONENT_TYPE_FUEL_SYSTEM
};

// Enum for Component Status
enum ComponentStatus
{
    COMPONENT_STATUS_OPERATIONAL = 0,
    COMPONENT_STATUS_MAINTENANCE_REQUIRED,
    COMPONENT_STATUS_FAILED
};

class AerospaceComponent
{
private:
    int componentIdentifier;
    double componentEfficiency;
    string componentManufacturer;
    ComponentType componentType;
    ComponentStatus componentStatus;

public:
    // Default Constructor
    AerospaceComponent()
        : componentIdentifier(0),
          componentEfficiency(100.0),
          componentManufacturer("Unknown"),
          componentType(COMPONENT_TYPE_ENGINE),
          componentStatus(COMPONENT_STATUS_OPERATIONAL)
    {
    }

    // Parameterized Constructor
    AerospaceComponent(int id, double efficiency, const string &manufacturer,
                       ComponentType type, ComponentStatus status)
        : componentIdentifier(id),
          componentEfficiency(efficiency),
          componentManufacturer(manufacturer),
          componentType(type),
          componentStatus(status)
    {
    }

    // Destructor
    ~AerospaceComponent()
    {
        cout << "Component " << componentIdentifier << " destroyed." << endl;
    }

    // Getters
    int GetComponentIdentifier() const { return componentIdentifier; }
    double GetComponentEfficiency() const { return componentEfficiency; }
    string GetComponentManufacturer() const { return componentManufacturer; }
    ComponentType GetComponentType() const { return componentType; }
    ComponentStatus GetComponentStatus() const { return componentStatus; }

    // Setters
    void SetComponentIdentifier(int id) { componentIdentifier = id; }
    void SetComponentEfficiency(double efficiency) { componentEfficiency = efficiency; }
    void SetComponentManufacturer(const string &manufacturer) { componentManufacturer = manufacturer; }
    void SetComponentType(ComponentType type) { componentType = type; }
    void SetComponentStatus(ComponentStatus status) { componentStatus = status; }

    // Function to update status based on efficiency
    void UpdateStatus()
    {
        if (componentEfficiency < 50.0)
        {
            componentStatus = COMPONENT_STATUS_FAILED;
        }
        else if (componentEfficiency < 80.0)
        {
            componentStatus = COMPONENT_STATUS_MAINTENANCE_REQUIRED;
        }
        else
        {
            componentStatus = COMPONENT_STATUS_OPERATIONAL;
        }
    }

    // Simulate usage
    void SimulateUsage(int usageHours)
    {
        for (int i = 0; i < usageHours; ++i)
        {
            componentEfficiency -= componentEfficiency * 0.005; // 0.5% reduction per hour
            if (componentEfficiency < 0.0)
            {
                componentEfficiency = 0.0;
                break;
            }
        }
        UpdateStatus();
    }

    // Perform maintenance check
    void PerformMaintenanceCheck() const
    {
        switch (componentStatus)
        {
        case COMPONENT_STATUS_OPERATIONAL:
            cout << "Component is fully operational.\n";
            break;
        case COMPONENT_STATUS_MAINTENANCE_REQUIRED:
            cout << "Component requires maintenance soon.\n";
            break;
        case COMPONENT_STATUS_FAILED:
            cout << "Component has failed and must be replaced!\n";
            break;
        default:
            cout << "Unknown status.\n";
            break;
        }
    }

    // Boost efficiency
    void BoostEfficiency()
    {
        while (componentEfficiency < 100.0)
        {
            componentEfficiency += 1.0;
        }
        if (componentEfficiency > 100.0)
        {
            componentEfficiency = 100.0;
        }
        UpdateStatus();
    }

    // Display component details
    void DisplayDetails() const
    {
        cout << "\n--- Component Details ---\n";
        cout << "ID: " << componentIdentifier << '\n';
        cout << "Efficiency: " << componentEfficiency << "%\n";
        cout << "Manufacturer: " << componentManufacturer << '\n';
        cout << "Type: ";
        switch (componentType)
        {
        case COMPONENT_TYPE_ENGINE: cout << "Engine\n"; break;
        case COMPONENT_TYPE_AVIONICS: cout << "Avionics\n"; break;
        case COMPONENT_TYPE_LANDING_GEAR: cout << "Landing Gear\n"; break;
        case COMPONENT_TYPE_FUEL_SYSTEM: cout << "Fuel System\n"; break;
        default: cout << "Unknown\n"; break;
        }

        cout << "Status: ";
        switch (componentStatus)
        {
        case COMPONENT_STATUS_OPERATIONAL: cout << "Operational\n"; break;
        case COMPONENT_STATUS_MAINTENANCE_REQUIRED: cout << "Maintenance Required\n"; break;
        case COMPONENT_STATUS_FAILED: cout << "Failed\n"; break;
        default: cout << "Unknown\n"; break;
        }
    }
};

// ----------- Global Functions -----------

void AssignManufacturer(AerospaceComponent &component, const string &manufacturerName)
{
    component.SetComponentManufacturer(manufacturerName);
    cout << "Manufacturer assigned successfully.\n";
}

bool IsEfficient(const AerospaceComponent &component)
{
    return component.GetComponentEfficiency() > 85.0;
}

bool IsSameType(const AerospaceComponent &componentA, const AerospaceComponent &componentB)
{
    return componentA.GetComponentType() == componentB.GetComponentType();
}

bool IsSameStatus(const AerospaceComponent &componentA, const AerospaceComponent &componentB)
{
    return componentA.GetComponentStatus() == componentB.GetComponentStatus();
}

void PrintFormattedComponentList(const AerospaceComponent componentList[], const int listSize)
{
    cout << "\nID   | Manufacturer    | Efficiency | Type          | Status\n";
    cout << "---------------------------------------------------------------\n";
    for (int i = 0; i < listSize; ++i)
    {
        cout << setw(4) << componentList[i].GetComponentIdentifier() << " | "
             << setw(15) << componentList[i].GetComponentManufacturer() << " | "
             << setw(9) << componentList[i].GetComponentEfficiency() << " | ";

        switch (componentList[i].GetComponentType())
        {
        case COMPONENT_TYPE_ENGINE: cout << setw(12) << "Engine"; break;
        case COMPONENT_TYPE_AVIONICS: cout << setw(12) << "Avionics"; break;
        case COMPONENT_TYPE_LANDING_GEAR: cout << setw(12) << "Landing Gear"; break;
        case COMPONENT_TYPE_FUEL_SYSTEM: cout << setw(12) << "Fuel System"; break;
        }

        cout << " | ";
        switch (componentList[i].GetComponentStatus())
        {
        case COMPONENT_STATUS_OPERATIONAL: cout << "Operational"; break;
        case COMPONENT_STATUS_MAINTENANCE_REQUIRED: cout << "Maintenance"; break;
        case COMPONENT_STATUS_FAILED: cout << "Failed"; break;
        }
        cout << '\n';
    }
    cout << endl;
}


int SearchComponentByIdentifier(const AerospaceComponent componentList[], const int listSize, const int searchIdentifier)
{
    for (int i = 0; i < listSize; ++i)
    {
        if (componentList[i].GetComponentIdentifier() == searchIdentifier)
        {
            return i;
        }
    }
    return -1;
}

// ----------- Main Function -----------

int main()
{
    AerospaceComponent componentList[3];

    int choice;
    do
    {
        cout << "\n=== Aerospace Component Monitoring Menu ===\n";
        cout << "1. Add component details\n";
        cout << "2. Assign manufacturer\n";
        cout << "3. Simulate usage\n";
        cout << "4. Boost efficiency\n";
        cout << "5. Check maintenance status\n";
        cout << "6. Compare two components\n";
        cout << "7. Search component by ID\n";
        cout << "8. Display all components\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int slot;
            cout << "Enter slot number (0-2): ";
            cin >> slot;
            if (slot < 0 || slot > 2)
            {
                cout << "Invalid slot!\n";
                continue;
            }

            int id, typeInput, statusInput;
            double efficiency;
            string manufacturer;

            cout << "Enter Component ID: ";
            cin >> id;

            cout << "Enter Efficiency (0.0 - 100.0): ";
            cin >> efficiency;
            while (efficiency < 0.0 || efficiency > 100.0)
            {
                cout << "Invalid efficiency! Enter again: ";
                cin >> efficiency;
            }

            cin.ignore();
            cout << "Enter Manufacturer Name: ";
            getline(cin, manufacturer);
            while (manufacturer.empty())
            {
                cout << "Manufacturer cannot be empty. Enter again: ";
                getline(cin, manufacturer);
            }

            cout << "Select Type [0-Engine, 1-Avionics, 2-Landing Gear, 3-Fuel System]: ";
            cin >> typeInput;
            while (typeInput < 0 || typeInput > 3)
            {
                cout << "Invalid type! Enter again: ";
                cin >> typeInput;
            }

            cout << "Select Status [0-Operational, 1-Maintenance Required, 2-Failed]: ";
            cin >> statusInput;
            while (statusInput < 0 || statusInput > 2)
            {
                cout << "Invalid status! Enter again: ";
                cin >> statusInput;
            }

            componentList[slot] = AerospaceComponent(id, efficiency, manufacturer,
                                                     static_cast<ComponentType>(typeInput),
                                                     static_cast<ComponentStatus>(statusInput));
            cout << "Component added successfully!\n";
        }
        else if (choice == 2)
        {
            int slot;
            cout << "Enter slot number (0-2): ";
            cin >> slot;
            cin.ignore();
            string manufacturer;
            cout << "Enter Manufacturer Name: ";
            getline(cin, manufacturer);
            AssignManufacturer(componentList[slot], manufacturer);
        }
        else if (choice == 3)
        {
            int slot, hours;
            cout << "Enter slot number (0-2): ";
            cin >> slot;
            cout << "Enter usage hours: ";
            cin >> hours;
            componentList[slot].SimulateUsage(hours);
            cout << "Usage simulated successfully!\n";
        }
        else if (choice == 4)
        {
            int slot;
            cout << "Enter slot number (0-2): ";
            cin >> slot;
            componentList[slot].BoostEfficiency();
            cout << "Efficiency boosted to 100%.\n";
        }
        else if (choice == 5)
        {
            int slot;
            cout << "Enter slot number (0-2): ";
            cin >> slot;
            componentList[slot].PerformMaintenanceCheck();
        }
        else if (choice == 6)
        {
            int slotA, slotB;
            cout << "Enter first slot (0-2): ";
            cin >> slotA;
            cout << "Enter second slot (0-2): ";
            cin >> slotB;

            if (IsSameType(componentList[slotA], componentList[slotB]))
                cout << "Components are of the SAME type.\n";
            else
                cout << "Components are of DIFFERENT types.\n";

            if (IsSameStatus(componentList[slotA], componentList[slotB]))
                cout << "Components have the SAME status.\n";
            else
                cout << "Components have DIFFERENT statuses.\n";
        }
        else if (choice == 7)
        {
            int searchID;
            cout << "Enter Component ID to search: ";
            cin >> searchID;
            int index = SearchComponentByIdentifier(componentList, 3, searchID);
            if (index != -1)
            {
                cout << "Component found at slot " << index << ".\n";
                componentList[index].DisplayDetails();
            }
            else
            {
                cout << "Component not found.\n";
            }
        }
        else if (choice == 8)
        {
            PrintFormattedComponentList(componentList, 3);
        }
        else if (choice == 9)
        {
            cout << "Exiting program. Goodbye!\n";
        }
        else
        {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 9);

    
}
