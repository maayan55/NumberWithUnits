#include <iostream>
#include <fstream>
#include <map>
#include "NumberWithUnits.hpp"
using namespace std;

namespace ariel{

            std::map<string,std::map<string,double>> units;
            NumberWithUnits nu(0,"0");
            
             void  NumberWithUnits::read_units(ifstream& units_file)
             {

             }
            // +,+=,+,-,-=,-
             NumberWithUnits& operator+(const NumberWithUnits& num1, const NumberWithUnits& num2){
                 return nu;
             }
            NumberWithUnits& operator+=(NumberWithUnits& num1, const NumberWithUnits& num2){
                 return nu;
             }
             NumberWithUnits& operator+(const NumberWithUnits& num1){
                 return nu;
             }
             NumberWithUnits& operator-(const NumberWithUnits& num1, const NumberWithUnits& num2){
                 return nu;
             }
             NumberWithUnits& operator-=(NumberWithUnits& num1, const NumberWithUnits& num2){
                 return nu;
             }
             NumberWithUnits& operator-(const NumberWithUnits& num1){
                 return nu;
             }
            // >, >=, <, <=, ==, !=
             bool operator>(const NumberWithUnits& num1, const NumberWithUnits& num2){
                 return true;
             }
            bool operator>=(const NumberWithUnits& num1, const NumberWithUnits& num2){
                 return true;
             }
             bool operator<(const NumberWithUnits& num1, const NumberWithUnits& num2){
                 return true;
             }
             bool operator<=(const NumberWithUnits& num1, const NumberWithUnits& num2){
                 return true;
             }
             bool operator==(const NumberWithUnits& num1, const NumberWithUnits& num2){
                 return true;
             }
             bool operator!=(const NumberWithUnits& num1, const NumberWithUnits& num2){
                 return true;
             }
            // ++ after, ++ before, -- after, -- before
             NumberWithUnits& operator++( NumberWithUnits& num1){
                 return nu;
             }
             NumberWithUnits& operator++( NumberWithUnits& num1, int){
                 return nu;
             }             
             NumberWithUnits& operator--( NumberWithUnits& num1){
                 return nu;
             }    
             NumberWithUnits& operator--( NumberWithUnits& num1, int)
             {
                 return nu;
             }    
            // *, *, *=, *=
             NumberWithUnits& operator*( NumberWithUnits& num2 ,double num1){
                 return nu;
             }
             NumberWithUnits& operator*(double num1,  NumberWithUnits& num2){
                 return nu;
             }
             NumberWithUnits& operator*=( double num1,NumberWithUnits& num2){
                 return nu;
             }  
              NumberWithUnits& operator*=( NumberWithUnits& num2, double num1){
                 return nu;
             }  
            // >> cin input, << cout output
             std::istream& operator>> (std::istream& input , NumberWithUnits& n){
                 return input;
             }
             std::ostream& operator<< (std::ostream& output, const NumberWithUnits& n){
                 return output;
             }
            

}