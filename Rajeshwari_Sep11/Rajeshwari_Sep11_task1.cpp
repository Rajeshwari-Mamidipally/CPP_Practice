#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;
void delay_ms(int ms) {
    clock_t start = clock();
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < ms);
}
class Sensor {
public:
    Sensor(int id_, float value_, float threshold_, const string& status_ = "OK")
        : id(id_), value(value_), threshold(threshold_), status(status_) {}
    virtual ~Sensor() {}
    virtual void simulateFault() = 0; 
    bool isFaulty() const { return value > threshold; }
    int getId() const { return id; }
    float getValue() const { return value; }
    float getThreshold() const { return threshold; }
    const string& getStatus() const { return status; }
    void setThreshold(float newT) { threshold = newT; }
    void setStatus(const string& s) { status = s; }
protected:
    int id;
    float value;
    float threshold;
    string status;
};
class TemperatureSensor : public Sensor {
public:
    TemperatureSensor(int id_, float value_, float threshold_)
        : Sensor(id_, value_, threshold_) {}
    void simulateFault() {
        static std::mt19937 rng((unsigned)time(0));
        std::uniform_real_distribution<float> faultType(0.0f, 1.0f);
        float choice = faultType(rng);
        if (choice < 0.5f) {
            value += 40.0f + (faultType(rng) * 10.0f);
            status = "STUCK_HOT";
        } else {
            value += 10.0f + (faultType(rng) * 5.0f);
            status = "OFFSET_HIGH";
        }
    }
};
class PressureSensor : public Sensor {
public:
    PressureSensor(int id_, float value_, float threshold_)
        : Sensor(id_, value_, threshold_) {}
    void simulateFault() {
        static std::mt19937 rng((unsigned)time(0) + 123);
        std::uniform_real_distribution<float> faultType(0.0f, 1.0f);
        float choice = faultType(rng);
        if (choice < 0.5f) {
            value -= 30.0f + (faultType(rng) * 20.0f);
            status = "DROP";
        } else {
            value += 30.0f + (faultType(rng) * 20.0f);
            status = "SPIKE";
        }
    }
};
class Actuator {
public:
    Actuator(int id_, const string& state_, int responseTimeMs_)
        : id(id_), state(state_), responseTime(responseTimeMs_), delayed(false) {}
    ~Actuator() {}
    void triggerAction() {
        if (!delayed) {
            state = "Active";
        } else {
            state = "Delayed";
        }
    }
    int getId() const { return id; }
    const string& getState() const { return state; }
    int getResponseTime() const { return responseTime; }
    bool isDelayed() const { return delayed; }
    void injectDelay(int extraMs) {
        responseTime += extraMs;
        delayed = true;
    }
    void clearDelay() {
        delayed = false;
    }
private:
    int id;
    string state;
    int responseTime;
    bool delayed;
};
class FaultInjector {
public:
    FaultInjector() {}
    void attachSensor(Sensor* s) {
        if (s) sensors.push_back(s);
    }
    void attachActuator(Actuator* a) {
        if (a) actuators.push_back(a);
    }
    void injectSensorFault(Sensor* s) {
        if (s) s->simulateFault();
    }
    void injectActuatorDelay(Actuator& a) {
        a.injectDelay(150);
    }
    void injectAllFaults() {
        for (size_t i = 0; i < sensors.size(); ++i) {
            if (i % 2 == 0) injectSensorFault(sensors[i]);
        }
        for (size_t j = 0; j < actuators.size(); ++j) {
            injectActuatorDelay(*actuators[j]);
        }
    }
    void reportStatus() const {
        cout << "--- FaultInjector Report ---\n";
        cout << "Sensors attached: " << sensors.size() << "\n";
        for (size_t i = 0; i < sensors.size(); ++i) {
            Sensor* s = sensors[i];
            cout << "  Sensor ID " << s->getId()
                 << " value=" << s->getValue()
                 << " threshold=" << s->getThreshold()
                 << " status=" << s->getStatus()
                 << (s->isFaulty() ? " [FAULTY]" : " [OK]") << "\n";
        }
        cout << "Actuators attached: " << actuators.size() << "\n";
        for (size_t i = 0; i < actuators.size(); ++i) {
            Actuator* a = actuators[i];
            cout << "  Actuator ID " << a->getId()
                 << " state=" << a->getState()
                 << " RT=" << a->getResponseTime()
                 << (a->isDelayed() ? " [DELAYED]" : "") << "\n";
        }
    }
    const vector<Sensor*>& getSensors() const { return sensors; }
    const vector<Actuator*>& getActuators() const { return actuators; }
private:
    vector<Sensor*> sensors;
    vector<Actuator*> actuators;
};
class ConfigManager {
public:
    void updateThreshold(Sensor& s, float newThreshold) {
        s.setThreshold(newThreshold);
    }
};
class FaultLogger {
public:
    FaultLogger(const string& filename) : ofs(filename.c_str(), ios::out) {
        if (!ofs) {
            throw runtime_error("Unable to open log file");
        }
        ofs << "timestamp,sensor_id,value,threshold,status\n";
    }
    ~FaultLogger() {
        ofs.flush();
        ofs.close();
    }
    void log(Sensor& s) {
        ofs << currentTimestamp() << "," << s.getId() << ","
            << fixed << setprecision(2) << s.getValue() << ","
            << s.getThreshold() << ","
            << s.getStatus() << "\n";
        ofs.flush();
    }
private:
    ofstream ofs;
    string currentTimestamp() {
        time_t now = time(0);
        char buf[64];
        strftime(buf, sizeof(buf), "%Y-%m-%dT%H:%M:%SZ", gmtime(&now));
        return string(buf);
    }
};
void logFault(Sensor* s) {
    if (!s) return;
    cout << "[GLOBAL_LOG] Sensor* id=" << s->getId()
         << " value=" << s->getValue()
         << " threshold=" << s->getThreshold()
         << " status=" << s->getStatus() << "\n";
}
void analyzeSystem(FaultInjector* fi) {
    if (!fi) return;
    cout << "[GLOBAL_ANALYZE] System analysis summary:\n";
    size_t faultCount = 0;
    for (size_t i = 0; i < fi->getSensors().size(); ++i) {
        if (fi->getSensors()[i]->isFaulty()) faultCount++;
    }
    cout << "  Total sensors: " << fi->getSensors().size()
         << " Faulty sensors: " << faultCount << "\n";
    cout << "  Total actuators: " << fi->getActuators().size() << "\n";
}
class SimulationEngine {
public:
    SimulationEngine(ConfigManager& cfg, FaultLogger* loggerPtr)
        : config(cfg), logger(loggerPtr) {
        injector = new FaultInjector();
    }
    ~SimulationEngine() {
        delete injector;
        injector = NULL;
        cleanup();
    }
    void setupDemoComponents() {
        Sensor* t1 = new TemperatureSensor(101, 85.0f, 90.0f);
        Sensor* t2 = new TemperatureSensor(102, 70.0f, 90.0f);
        Sensor* p1 = new PressureSensor(103, 45.0f, 50.0f);
        sensors.push_back(t1);
        sensors.push_back(t2);
        sensors.push_back(p1);
        Actuator* a1 = new Actuator(201, "Idle", 120);
        Actuator* a2 = new Actuator(202, "Idle", 200);
        actuators.push_back(a1);
        actuators.push_back(a2);
        for (size_t i = 0; i < sensors.size(); ++i) injector->attachSensor(sensors[i]);
        for (size_t j = 0; j < actuators.size(); ++j) injector->attachActuator(actuators[j]);
    }
    void run(int cycles = 6) {
        if (!logger) {
            cout << "[SimulationEngine] No logger provided; aborting run.\n";
            return;
        }
        cout << "[SimulationEngine] Starting simulation for " << cycles << " cycles\n";

        cout << "[SimulationEngine] Adjusting threshold for sensor ID " 
             << sensors[0]->getId() << " via ConfigManager\n";
        config.updateThreshold(*sensors[0], 80.0f);

        for (int tick = 0; tick < cycles; ++tick) {
            cout << "\n[Tick " << tick << "]\n";
            if (tick == 1) {
                cout << "[Tick] injecting all faults via FaultInjector\n";
                injector->injectAllFaults();
            }
            if (tick == 3) {
                cout << "[Tick] triggering actuator actions\n";
                for (size_t i = 0; i < actuators.size(); ++i)
                    actuators[i]->triggerAction();
            }

            for (size_t i = 0; i < sensors.size(); ++i) {
                Sensor* s = sensors[i];
                if (s->isFaulty()) {
                    logger->log(*s);
                    logFault(s);
                } else {
                    cout << " Sensor ID " << s->getId() 
                         << " OK (value=" << s->getValue()
                         << " threshold=" << s->getThreshold() << ")\n";
                }
            }
            for (size_t i = 0; i < actuators.size(); ++i) {
                Actuator* a = actuators[i];
                cout << " Actuator ID " << a->getId()
                     << " state=" << a->getState()
                     << " rt=" << a->getResponseTime()
                     << (a->isDelayed() ? " [DELAYED]" : "") << "\n";
            }
            delay_ms(200); 
        }
        injector->reportStatus();
        analyzeSystem(injector);
        generateSystemReport();
        cleanup();
    }
private:
    ConfigManager& config;
    FaultLogger* logger;
    FaultInjector* injector;
    vector<Sensor*> sensors;
    vector<Actuator*> actuators;
    void generateSystemReport() {
        cout << "\n=== SYSTEM REPORT ===\n";
        size_t faultCount = 0;
        for (size_t i = 0; i < sensors.size(); ++i) {
            Sensor* s = sensors[i];
            if (s->isFaulty()) faultCount++;
            cout << "Sensor " << s->getId() << " value=" << s->getValue()
                 << " threshold=" << s->getThreshold()
                 << " status=" << s->getStatus() << "\n";
        }
        cout << "Total sensors: " << sensors.size() << " Faulty: " << faultCount << "\n";
        for (size_t j = 0; j < actuators.size(); ++j) {
            Actuator* a = actuators[j];
            cout << "Actuator " << a->getId() << " state=" << a->getState()
                 << " rt=" << a->getResponseTime()
                 << (a->isDelayed() ? " [DELAYED]" : "") << "\n";
        }
    }
    void cleanup() {
        for (size_t i = 0; i < sensors.size(); ++i)
            delete sensors[i];
        sensors.clear();

        for (size_t i = 0; i < actuators.size(); ++i)
            delete actuators[i];
        actuators.clear();
    }
};
int main() {
    try {
        ConfigManager cfg;
        FaultLogger* logger = new FaultLogger("fault_log.csv");
        SimulationEngine engine(cfg, logger);
        engine.setupDemoComponents();
        engine.run(6);
        delete logger;
        logger = NULL;
        cout << "\nDemo finished. Fault log written to 'fault_log.csv'\n";
    } catch (const std::exception& ex) {
        cerr << "Exception: " << ex.what() << "\n";
        return 1;
    }
    return 0;
}