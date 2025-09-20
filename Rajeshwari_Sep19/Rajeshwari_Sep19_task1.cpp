#include<iostream>
class ServiceRecord
{
private:
    std::string date_;
    int mileage_ ; 
    std::string description_ ;
public:
    ServiceRecord()
    :
    date_(),
    mileage_(0),
    description_(){}

    ServiceRecord(const std::string& date,int mileage,const std::string& description)
        : 
        date_(date),
        mileage_(mileage),
        description_(description)
        {
            if(mileage_<0){
            throw std::invalid_argument("mileage must be >=0");
        }
        }
    
    ServiceRecord(const ServiceRecord& other)
    :
    date_(other.date_),
    mileage_(other.mileage_),
    description_(other.description_)
    {}
    ServiceRecord& operator=(const ServiceRecord& other) {
        if (this != &other) {
            date_ = other.date_;
            mileage_ = other.mileage_;
            description_ = other.description_;
        }
        return *this;
    }

    //Getters
    const std::string& getDate() const{ return date_;}
    int getMileage() const{return mileage_;}
    const std::string& getDescription() const{return description_;}

    void print() const{
        std::cout<<"\nDisplaying record\n";
        std::cout<<"Date : "<<date_<<'\n';
        std::cout<<"Mileage : "<<mileage_<<'\n';
        std::cout<<"Description : "<<description_<<'\n';
    }

};
class Car
{
private:
    std::string vin_;
    std::string make_;
    std::string model_;
    double price_;
    ServiceRecord* serviceHistory_ ;
    size_t serviceCount_ ;
    size_t serviceCap_ ;
    int* damageCodes_ ;
    size_t damageCount_ ;
    size_t damageCap_ ;
    static size_t totalCars_;
    void reserveService(size_t newCap) {
        if (newCap <= serviceCap_) return;
        ServiceRecord* newArr = new ServiceRecord[newCap];
        for (size_t i = 0; i < serviceCount_; i++) {
            newArr[i] = serviceHistory_[i]; 
        }
        delete[] serviceHistory_;
        serviceHistory_ = newArr;
        serviceCap_ = newCap;
    }
     void reserveDamage(size_t newCap) {
        if (newCap <= damageCap_) return;
        int* newArr = new int[newCap];
        for (size_t i = 0; i < damageCount_; i++) {
            newArr[i] = damageCodes_[i];
        }
        delete[] damageCodes_;
        damageCodes_ = newArr;
        damageCap_ = newCap;
    }
public:
    Car()
        :
        vin_(),
        make_(),
        model_(),
        price_(0),
        serviceHistory_(nullptr),
        serviceCount_(0),
        serviceCap_(0),
        damageCodes_(nullptr),
        damageCount_(0),
        damageCap_(0)
        {
            totalCars_++;
        }
    
    Car(const std::string& vin, const std::string& make, const std::string& model, double price)
    :
    vin_(vin),
    make_(make),
    model_(model),
    price_(price),
    serviceHistory_(nullptr), 
    serviceCount_(0), 
    serviceCap_(0),
    damageCodes_(nullptr), 
    damageCount_(0), 
    damageCap_(0)
    {
        if(price_<0){
            throw std::invalid_argument("price must be >=0");
        }
        totalCars_++;
    }
    Car(const Car& other)
    :
        vin_(other.vin_), 
        make_(other.make_), 
        model_(other.model_), 
        price_(other.price_),
        serviceHistory_(nullptr), 
        serviceCount_(other.serviceCount_), 
        serviceCap_(other.serviceCap_),
        damageCodes_(nullptr), 
        damageCount_(other.damageCount_), 
        damageCap_(other.damageCap_)
    {
        if (serviceCap_ > 0) {
            serviceHistory_ = new ServiceRecord[serviceCap_];
            for (size_t i = 0; i < serviceCount_; i++)
                serviceHistory_[i] = other.serviceHistory_[i];
        }
        if (damageCap_ > 0) {
            damageCodes_ = new int[damageCap_];
            for (size_t i = 0; i < damageCount_; i++)
                damageCodes_[i] = other.damageCodes_[i];
        }
        totalCars_++;
    }
    ~Car()
    {
        delete[] serviceHistory_;
        delete[] damageCodes_;
        serviceHistory_=nullptr;
        damageCodes_=nullptr;
        if (totalCars_ > 0) --totalCars_;

    }
     Car& operator=(Car other) {
        swap(*this, other);
        return *this;
    }
     friend void swap(Car& lhs, Car& rhs) noexcept {
        using std::swap;
        swap(lhs.vin_, rhs.vin_);
        swap(lhs.make_, rhs.make_);
        swap(lhs.model_, rhs.model_);
        swap(lhs.price_, rhs.price_);
        swap(lhs.serviceHistory_, rhs.serviceHistory_);
        swap(lhs.serviceCount_, rhs.serviceCount_);
        swap(lhs.serviceCap_, rhs.serviceCap_);
        swap(lhs.damageCodes_, rhs.damageCodes_);
        swap(lhs.damageCount_, rhs.damageCount_);
        swap(lhs.damageCap_, rhs.damageCap_);
        
    }
    static size_t getTotalCars() { return totalCars_; }
    //setters
    void setVIN(const std::string& vin){ vin_=vin;}
    void setMake(const std::string& make){make_=make;}
    void setModel(const std::string& model){model_=model;}
    void setPrice(double price){
        if(price>=0){
            price_=price;
        }
        else{
            throw std::invalid_argument("price must be >= 0");
        }
        
    }
    //Getters
    const std::string& getVIN()const{return vin_;}
    const std::string& getMake()const{return make_;}
    const std::string& getModel()const{return model_;}
    double getPrice()const{return price_;}
    size_t getServiceCount()const{return serviceCount_;}
    size_t getDamageCount()const{return damageCount_;}
    const ServiceRecord* getServiceHistory()const{return serviceHistory_;}
    const int* getDamageCodes()const{return damageCodes_;}

    void addService(const ServiceRecord& rec) {
        if (serviceCount_ == serviceCap_) {
            size_t newCap = (serviceCap_ == 0) ? 2 : serviceCap_ * 2;
            reserveService(newCap);
        }
        serviceHistory_[serviceCount_++] = rec;
    }

    void addDamageCode(int code) {
        if (damageCount_ == damageCap_) {
            size_t newCap = (damageCap_ == 0) ? 4 : damageCap_ * 2;
            reserveDamage(newCap);
        }
        damageCodes_[damageCount_++] = code;
    }
    void printInfo() const{
        std::cout<<"Display info\n";
        std::cout<<"VIN : "<<vin_<<'\n';
        std::cout<<"make : "<<make_<<'\n';
        std::cout<<"model : "<<model_<<'\n';
        std::cout<<"price : "<<price_<<'\n';
        std::cout << "Damage Codes (" << damageCount_ << "): ";
        for (size_t i = 0; i < damageCount_; ++i) std::cout << damageCodes_[i] << ' ';
        std::cout << '\n';
        std::cout << "Service Records (" << serviceCount_ << "):\n";
        for (size_t i = 0; i < serviceCount_; ++i) serviceHistory_[i].print();
    }
    
};
size_t Car::totalCars_ = 0;

//Global functions
double averagePrice(const Car* arr, size_t n){
    if (arr == nullptr || n == 0) return 0.0;
    double sum = 0.0;
    for (size_t i = 0; i < n; ++i) {
        sum += arr[i].getPrice();
    }
    return sum / n;
}
bool compareByPriceAsc(const Car& a, const Car& b){
    return a.getPrice()<b.getPrice();

}
bool compareByPriceDesc(const Car& a, const Car& b){
    return a.getPrice()>b.getPrice();
} 
bool areCarsEqual(const Car& a, const Car& b){
    return a.getVIN()==b.getVIN();

}
const Car* maxPriceCar(const Car* arr,size_t n){
    if(n==0||arr==nullptr){
        return nullptr;
    }
    const Car* max=&arr[0];
    for(size_t i=1;i<n;i++){
        if(arr[i].getPrice()>max->getPrice()){
            max=&arr[i];
        }

    }
    return max;
}
const Car* findCarByVIN(const Car* arr, size_t n,const std::string& vin){
    if(arr==nullptr)return nullptr;
    for(size_t i=0;i<n;i++){
        if(arr[i].getVIN()==vin)return &arr[i];
    }
    return nullptr;
}
size_t countCarsWithDamage(const Car* arr, size_t n, int code){
    if(arr==nullptr)return 0;
    size_t count=0;
    for(size_t i=0;i<n;i++){
        const int* codes=arr[i].getDamageCodes();
        size_t damageCount=arr[i].getDamageCount();
        for(size_t j=0;j<damageCount;j++){
            if(codes[j]==code){
                count++;
                break;
            }
        }
    }
    return count;
}
void swapCars(Car& a, Car& b){
    swap(a,b);

}
int main(){
    std::cout << "Initial totalCars: " << Car::getTotalCars() << "\n";

    //Default construct
    Car cDefault;
    std::cout << "\nAfter default construction:\n";
    cDefault.printInfo();
    std::cout << "totalCars: " << Car::getTotalCars() << "\n";

    //Parameterized construct
    Car cParam("1HGCM", "Honda", "Accord", 19999.99);
    std::cout << "\nAfter parameterized construction:\n";
    cParam.printInfo();

    //Add damage codes
    cParam.addDamageCode(101);
    cParam.addDamageCode(205);
    cParam.addDamageCode(307);
    std::cout << "\nAfter adding damage codes:\n";
    cParam.printInfo();

    //Add service records
    ServiceRecord sr1("2022-03-15", 15000, "Oil change");
    ServiceRecord sr2("2023-01-10", 25000, "Brake pads replacement");
    cParam.addService(sr1);
    cParam.addService(sr2);
    std::cout << "\nAfter adding service records:\n";
    cParam.printInfo();

    //Copy constructor
    Car cCopy(cParam);
    std::cout << "\nCopy-constructed car:\n";
    cCopy.printInfo();

    //Modify copy's damage code to check deep copy
    cCopy.addDamageCode(999);
    std::cout << "\nAfter modifying copy's damage codes:\n";
    std::cout << "Original:\n"; cParam.printInfo();
    std::cout << "Copy:\n"; cCopy.printInfo();

    //Service count check
    std::cout << "\nOriginal services: " << cParam.getServiceCount()
         << ", Copy services: " << cCopy.getServiceCount() << "\n";

    //Assignment operator
    Car cAssign;
    cAssign = cParam;
    std::cout << "\nAfter assignment:\n";
    cAssign.printInfo();

    //Dynamic array of cars
    size_t N = 3;
    Car* garage = new Car[N];
    garage[0] = Car("JH4KA", "Acura", "TLX", 27999.49);
    garage[1] = Car("5YJ3E", "Tesla", "Model 3", 39999.00);
    garage[2] = Car("WBA4", "BMW", "3 Series", 34999.99);

    //Add damage codes and services using lambda
    auto setupCar = [](Car& car, const int* codes, size_t codeCount,const ServiceRecord* services, size_t serviceCount) {
        for (size_t i = 0; i < codeCount; i++) car.addDamageCode(codes[i]);
        for (size_t i = 0; i < serviceCount; i++) car.addService(services[i]);
    };

    int damageTesla[] = {150, 250};
    int damageBMW[] = {175, 285, 395, 505, 615};
    ServiceRecord sr3("2023-06-20", 30000, "Tire rotation");
    ServiceRecord sr4("2024-02-05", 35000, "Annual inspection");
    setupCar(garage[0], damageTesla, 2, &sr3, 1);
    setupCar(garage[1], damageBMW, 5, &sr4, 1);
    std::cout << "\nGarage cars:\n";
    for (size_t i = 0; i < N; ++i)
        garage[i].printInfo();

    //Average price
    std::cout << "\nAverage price of garage: " << averagePrice(garage, N) << "\n";

    //Global utilities
    const Car* maxCar = maxPriceCar(garage, N);
    if (maxCar) std::cout << "Most expensive VIN: " << maxCar->getVIN() << "\n";

    const Car* found = findCarByVIN(garage, N, "WBA4");
    if (found) std::cout << "Found car price: " << found->getPrice() << "\n";

    std::cout << "Cars with damage code 150: " << countCarsWithDamage(garage, N, 150) << "\n";
    std::cout << "Are first two cars equal? " << (areCarsEqual(garage[0], garage[1]) ? "Yes" : "No") << "\n";

    //Delete heap array
    delete[] garage;
    std::cout << "\nAfter deleting garage, totalCars: " << Car::getTotalCars() << "\n";
    std::cout << "Final totalCars before exit: " << Car::getTotalCars() << "\n";
    return 0;
    
}

