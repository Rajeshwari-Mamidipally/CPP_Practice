#include<iostream>
#include <string>
#include <iomanip>
void printClassification(const std::string& label) {
    std::cout << "Classification: " << label << std::endl;
}
class ParcelAnalyzer
{
public:
     std::string classifyWeight(int grams) {
        std::cout << "Input: " << grams << " grams" << std::endl;
        if (grams < 500)
            return "Light";
        else if (grams <= 2000)
            return "Medium";
        else
            return "Heavy";
    }
    std::string classifyWeight(float kilograms) {
        std::cout << "Input: " << std::fixed << std::setprecision(2) << kilograms << " kg" << std::endl;
        if (kilograms < 0.5f)
            return "Light";
        else if (kilograms <= 2.0f)
            return "Medium";
        else
            return "Heavy";
    }

    std::string classifyWeight(double pounds) {
        std::cout << "Input: " << std::fixed << std::setprecision(2) << pounds << " lb" << std::endl;
        if (pounds < 1.1)
            return "Light";
        else if (pounds <= 4.4)
            return "Medium";
        else
            return "Heavy";
    }
};

int main() {
    ParcelAnalyzer analyzer;
    printClassification(analyzer.classifyWeight(450));   
    printClassification(analyzer.classifyWeight(1500));  
    printClassification(analyzer.classifyWeight(2500));  
    std::cout << "\n";
    printClassification(analyzer.classifyWeight(0.3f)); 
    printClassification(analyzer.classifyWeight(1.5f));  
    printClassification(analyzer.classifyWeight(3.0f));  
    std::cout << "\n";
    printClassification(analyzer.classifyWeight(0.9));   
    printClassification(analyzer.classifyWeight(2.5));   
    printClassification(analyzer.classifyWeight(5.0));   
    return 0;
}

