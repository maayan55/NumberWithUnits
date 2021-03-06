#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel{
        class NumberWithUnits{
        
             double number; //private method by default
             string type;
        
        
        public:
            NumberWithUnits(double num,string unit)
            {
                number=num;
                type=unit;
            }
            ~NumberWithUnits(){};

            static void read_units(ifstream& units_file);

            // +, +=, +, -, -=, -
            friend NumberWithUnits& operator+(const NumberWithUnits& num1, const NumberWithUnits& num2);
            friend NumberWithUnits& operator+=(NumberWithUnits& num1, const NumberWithUnits& num2);
            friend NumberWithUnits& operator+(const NumberWithUnits& num1);
            friend NumberWithUnits& operator-(const NumberWithUnits& num1, const NumberWithUnits& num2);
            friend NumberWithUnits& operator-=(NumberWithUnits& num1, const NumberWithUnits& num2);
            friend NumberWithUnits& operator-(const NumberWithUnits& num1);
            // >, >=, <, <=, ==, !=
            friend bool operator>(const NumberWithUnits& num1, const NumberWithUnits& num2);
            friend bool operator>=(const NumberWithUnits& num1, const NumberWithUnits& num2);
            friend bool operator<(const NumberWithUnits& num1, const NumberWithUnits& num2);
            friend bool operator<=(const NumberWithUnits& num1, const NumberWithUnits& num2);
            friend bool operator==(const NumberWithUnits& num1, const NumberWithUnits& num2);
            friend bool operator!=(const NumberWithUnits& num1, const NumberWithUnits& num2);
            // ++ after, ++ before, -- after, -- before
            friend NumberWithUnits& operator++( NumberWithUnits& num1);     
            friend NumberWithUnits& operator++( NumberWithUnits& num1, int);  
            friend NumberWithUnits& operator--( NumberWithUnits& num1);             
            friend NumberWithUnits& operator--( NumberWithUnits& num1, int);     
            // *, *, *=, *=
            friend NumberWithUnits& operator*(double num1,  NumberWithUnits& num2);
            friend NumberWithUnits& operator*(  NumberWithUnits& num2,double num1);
            friend NumberWithUnits& operator*=( double num1,NumberWithUnits  &num2);     
            friend NumberWithUnits& operator*=(  NumberWithUnits& num2, double num1);
            // >> cin input, <<c out output
            friend std::istream& operator>> (std::istream& input , NumberWithUnits& n);
            friend std::ostream& operator<< (std::ostream& output, const NumberWithUnits& n);
        


    };    
    
}