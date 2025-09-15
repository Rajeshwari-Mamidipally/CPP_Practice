#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Sensor {
public:
    int id;
    float value;
    int priority;
    string status;
    Sensor(int i, float v, int p) : id(i), value(v), priority(p), status("OK") {}
    void updateValue(float v) {
        value = v;
        if (value > 100) {
            status = "ALERT";
        } else {
            status = "OK";
        }
    }
};
void rebindCriticalSensor(Sensor*& ref, Sensor* list[], int size) {
    if (size == 0) return;
    Sensor* highestPriority = list[0];
    for (int i = 1; i < size; i++) {
        if (list[i]->priority > highestPriority->priority) {
            highestPriority = list[i];
        }
    }
    ref = highestPriority;
}
void printSensorMap(Sensor* list[], int size) {
    cout << "\n--- Sensor Map ---\n";
    cout << left << setw(8) << "ID" << setw(10) << "Value" << setw(10) 
         << "Priority" << setw(10) << "Status" << "\n";
    for (int i = 0; i < size; i++) {
        cout << left << setw(8) << list[i]->id
             << setw(10) << list[i]->value
             << setw(10) << list[i]->priority
             << setw(10) << list[i]->status << "\n";
    }
}
class SensorDiagnostics {
public:
    string checkHealth(Sensor& s) {
        if (s.value > 100) {
            return "Faulty";
        } else if (s.value < 0) {
            return "Disconnected";
        }
        return "Healthy";
    }
};
class Controller {
public:
    Sensor* sensorList[10];      
    Sensor& criticalSensor;     
    int sensorCount;
    Controller(Sensor& cs) : criticalSensor(cs), sensorCount(0) {}
    void bindCriticalSensor() {
        if (sensorCount == 0) return;
        Sensor* ref = &criticalSensor; 
        rebindCriticalSensor(ref, sensorList, sensorCount);
        cout << "Critical sensor bound to ID: " << ref->id << "\n";
    }
    void updateCriticalSensor() {
        cout << "Updating critical sensor (ID " << criticalSensor.id << ")...\n";
        criticalSensor.updateValue(criticalSensor.value + 10);
    }
    void printStatus() {
        printSensorMap(sensorList, sensorCount);
    }
};
int main() {
    Controller* controller = nullptr;
    Sensor* sensors[10];
    cout << "Creating 10 sensors with random priorities...\n";
    for (int i = 0; i < 10; i++) {
        int priority = (i % 5) + 1; 
        sensors[i] = new Sensor(100 + i, 50.0 + i * 5, priority);
    }
    controller = new Controller(*sensors[0]);
    for (int i = 0; i < 10; i++) {
        controller->sensorList[i] = sensors[i];
        controller->sensorCount++;
    }
    controller->bindCriticalSensor();
    controller->printStatus();
    controller->updateCriticalSensor();
    SensorDiagnostics diag;
    string healthStatus = diag.checkHealth(controller->criticalSensor);
    cout << "Health status of critical sensor: " << healthStatus << "\n";
    cout << "\nRebinding critical sensor after priority change...\n";
    sensors[7]->priority = 10; 
    Sensor* tempPtr = &controller->criticalSensor;
    rebindCriticalSensor(tempPtr, controller->sensorList, controller->sensorCount);
    cout << "Now critical sensor should be ID: " << tempPtr->id << "\n";
    controller->printStatus();
    for (int i = 0; i < 10; i++) {
        delete sensors[i];
    }
    delete controller;
    cout << "\nMemory cleanup completed successfully!\n";
    return 0;
}