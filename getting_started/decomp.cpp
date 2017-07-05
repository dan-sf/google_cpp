#include <iostream>
using namespace std;

void GetInput(int WeeklySales) {
}

float CalcMethod1() {
    return 600.0;
}

float CalcMethod2(float WeeklySales) {
    float result = 40.0*7.0 + WeeklySales*0.10;
    return result;
}

float CalcMethod3(float WeeklySales) {
    float result = WeeklySales*0.20 + 20.0 * (float) ( (int) (WeeklySales / 225.0) );
    return result;
}

int main() {
    float WeeklySales;
    for (int i = 10; i < 15; i++) {
        WeeklySales = ((float) i) * 225.0;
        printf("Weekly Sales: %f\n\tCalcMethod1: %f, CalcMethod2: %f, CalcMethod3: %f\n", WeeklySales, CalcMethod1(), CalcMethod2(WeeklySales), CalcMethod3(WeeklySales));
    }
}

