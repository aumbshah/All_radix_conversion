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
decimal = decimal + (digit_value * pow(frombase, power));
            power++;
        }
        return decimal;
    }


    string fromdecimal(int decimal)
     {
        string result;
        while (decimal > 0) {
            int remainder = decimal % tobase;
            char digit;
            if (remainder < 10) {
                digit = '0' + remainder;
            } else {
                digit = 'A' + remainder - 10;
            }
            result = digit + result;
            decimal = (decimal / tobase);
        }
        return result;
    }


    string convert()
{
        int decimal = todecimal();
        return fromdecimal(decimal);
    }
};

int main() {
    string number;
    int frombase, tobase;
    cout<<"*****************************"<<'\n';
    cout<<"----ALL RADIX CONVERSION-----"<<'\n';
    cout<<"*****************************"<<'\n';
    cout<<"Enter the number to convert: ";
    cin>>number;
    cout<<"Enter the base of the number: ";
    cin>>frombase;
    cout<<"Enter the base to convert to: ";
    cin>>tobase;

    RadixConverter converter(number, frombase, tobase);
    string converted_number = converter.convert();

    cout << "Converted number: " << converted_number << endl;

    return 0;
}
        
