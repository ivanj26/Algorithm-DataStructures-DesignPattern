// Bad way / violates the OCP
class BMICalculator {
    public:
        int calculate() {
            // Someone already wrote the code here!
            // Assume: There is a code here!

            // If there is a request to add a new logic on the bmi calculation
            // We need to modify this method, It violates the OC Principle
            return 0;
        }
};

// Good way, separate the calculation of female and male by extending the method from base class.

//
// Male BMI Calculator
class MaleBMICalculator: public BMICalculator {
    public:
        int calculate() override {
            // Formula for male bmi calculation
        }
};

// Female BMI Calculator
class FemaleBMICalculator: public BMICalculator {
    public:
        int calculate() override {
            // Formula for female bmi calculation
        }
};

int main() {
    return 0;
}