\\This project is prepared by 23CS085, 23CS089 & 23CS106
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class RadixConverter {
private:
    string number;
    int frombase;
    int tobase;

public:
    RadixConverter(string num, int from, int to): number(num) , frombase(from), tobase(to)
     {}
    int todecimal()
    {
        int decimal = 0;
        int power = 0;
        for (int i = number.size() - 1; i >= 0; i--) {
            int digit_value;
            if (isdigit(number[i])) {
                digit_value = number[i] - '0';
            } else {
                digit_value = number[i] - 'A' + 10;
            }  
