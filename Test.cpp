#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <string>
using namespace ariel;
using namespace std;

ifstream units_file("units.txt");

TEST_CASE("regular + & -")
{
    NumberWithUnits::read_units(units_file);

    CHECK_EQ(NumberWithUnits(10, "km") + NumberWithUnits(1, "km"), NumberWithUnits(11, "km"));
    CHECK_EQ(NumberWithUnits(5, "km") + NumberWithUnits(4, "m"), NumberWithUnits(5.004, "km"));
    CHECK_EQ(NumberWithUnits(5, "m") + NumberWithUnits(50, "cm"), NumberWithUnits(5.50, "m"));
    CHECK_EQ(NumberWithUnits(8, "cm") + NumberWithUnits(2, "cm"), NumberWithUnits(10, "cm"));
    CHECK_EQ(NumberWithUnits(105, "cm") + NumberWithUnits(3, "m"), NumberWithUnits(405, "cm"));
    CHECK_EQ(NumberWithUnits(6, "m") + NumberWithUnits(201, "cm"), NumberWithUnits(8.01, "m"));
    CHECK_EQ(NumberWithUnits(7, "kg") + NumberWithUnits(500, "g"), NumberWithUnits(7.5, "kg"));
    CHECK_EQ(NumberWithUnits(400, "g") + NumberWithUnits(1, "kg"), NumberWithUnits(1400, "g"));
    CHECK_EQ(NumberWithUnits(10, "ton") + NumberWithUnits(600, "kg"), NumberWithUnits(10.600, "ton"));
    CHECK_EQ(NumberWithUnits(3, "ton") + NumberWithUnits(500, "kg"), NumberWithUnits(3.500, "ton"));
    CHECK_EQ(NumberWithUnits(1, "kg") + NumberWithUnits(2, "ton"), NumberWithUnits(2001, "kg"));
    CHECK_EQ(NumberWithUnits(6, "hour") + NumberWithUnits(30, "min"), NumberWithUnits(6.5, "hour"));
    CHECK_EQ(NumberWithUnits(2, "hour") + NumberWithUnits(1, "hour"), NumberWithUnits(3, "hour"));
    CHECK_EQ(NumberWithUnits(9, "min") + NumberWithUnits(60, "sec"), NumberWithUnits(10, "min"));

    CHECK_EQ(NumberWithUnits(12, "km") - NumberWithUnits(2, "km"), NumberWithUnits(10, "km"));
    CHECK_EQ(NumberWithUnits(5, "km") - NumberWithUnits(500, "m"), NumberWithUnits(4.500, "km"));
    CHECK_EQ(NumberWithUnits(5, "m") - NumberWithUnits(62, "cm"), NumberWithUnits(4.38, "m"));
    CHECK_EQ(NumberWithUnits(9, "m") - NumberWithUnits(3, "m"), NumberWithUnits(6, "m"));
    CHECK_EQ(NumberWithUnits(3, "m") - NumberWithUnits(99, "cm"), NumberWithUnits(2.01, "m"));
    CHECK_EQ(NumberWithUnits(15, "kg") - NumberWithUnits(2, "kg"), NumberWithUnits(13, "kg"));
    CHECK_EQ(NumberWithUnits(6, "kg") - NumberWithUnits(234, "g"), NumberWithUnits(5.776, "kg"));
    CHECK_EQ(NumberWithUnits(4, "ton") - NumberWithUnits(2, "ton"), NumberWithUnits(2, "ton"));
    CHECK_EQ(NumberWithUnits(10, "ton") - NumberWithUnits(350, "kg"), NumberWithUnits(9.650, "ton"));
    CHECK_EQ(NumberWithUnits(12, "hour") - NumberWithUnits(5, "hour"), NumberWithUnits(7, "hour"));
    CHECK_EQ(NumberWithUnits(7, "hour") - NumberWithUnits(15, "min"), NumberWithUnits(6.75, "hour"));
    CHECK_EQ(NumberWithUnits(54, "min") - NumberWithUnits(4, "min"), NumberWithUnits(50, "min"));
}

TEST_CASE("+=, -=, unary + & -")
{
    NumberWithUnits::read_units(units_file);

    NumberWithUnits test_num1(8, "km");
    NumberWithUnits test_num2(400, "m");
    NumberWithUnits test_num3(8,"km");

    CHECK(test_num3 == test_num1);
    CHECK((test_num1 += test_num2) == NumberWithUnits(8.4, "km"));
    CHECK(test_num1 == NumberWithUnits(8.4, "km"));
    CHECK((test_num2 += test_num1) == NumberWithUnits(8800, "m"));
    CHECK(test_num2 == NumberWithUnits(8800, "m"));
    CHECK((test_num1 -= test_num2) == NumberWithUnits(-0.4, "km"));
    CHECK(test_num1 == NumberWithUnits(-0.4, "km"));
    CHECK((test_num2 -= test_num1) == NumberWithUnits(9200, "m"));
    CHECK(test_num2 == NumberWithUnits(9200, "m"));

    NumberWithUnits test_num4(4, "kg");
    NumberWithUnits test_num5(-13, "m");

    CHECK((+test_num4) == NumberWithUnits(4, "kg"));
    CHECK((-test_num4) == NumberWithUnits(-4, "kg"));
    CHECK((+test_num5) == NumberWithUnits(-13, "m"));
    CHECK((-test_num5) == NumberWithUnits(13, "m"));
}

TEST_CASE(">, >=, <, <=, ==, !=")
{
    NumberWithUnits::read_units(units_file);

    CHECK_GT(NumberWithUnits(12, "min"), NumberWithUnits(8, "min"));
    CHECK_GT(NumberWithUnits(2, "km"), NumberWithUnits(900, "m"));
    CHECK_GE(NumberWithUnits(5, "min"), NumberWithUnits(300, "sec"));
    CHECK_GE(NumberWithUnits(2, "kg"), NumberWithUnits(2000, "g"));
    CHECK_LT(NumberWithUnits(5, "km"), NumberWithUnits(8, "km"));
    CHECK_LT(NumberWithUnits(3, "min"), NumberWithUnits(200, "sec"));
    CHECK_LE(NumberWithUnits(2, "m"), NumberWithUnits(2, "m"));
    CHECK_LE(NumberWithUnits(1, "m"), NumberWithUnits(100, "cm"));
    CHECK_EQ(NumberWithUnits(1, "hour"), NumberWithUnits(60, "min"));
    CHECK_EQ(NumberWithUnits(3, "USD"), NumberWithUnits(9, "ILS"));
    CHECK_NE(NumberWithUnits(30, "min"), NumberWithUnits(30, "sec"));
    CHECK_NE(NumberWithUnits(4, "kg"), NumberWithUnits(2000, "g"));
}

TEST_CASE("before and after ++ & --")
{
    NumberWithUnits::read_units(units_file);

    NumberWithUnits test_num1(8, "km");

    CHECK(test_num1== NumberWithUnits(8, "km"));
    CHECK(++test_num1 == NumberWithUnits(9, "km"));
    CHECK(test_num1 == NumberWithUnits(9, "km"));
    CHECK(test_num1++ == NumberWithUnits(9, "km"));
    CHECK(test_num1 == NumberWithUnits(10, "km"));
    CHECK(test_num1-- == NumberWithUnits(10, "km"));
    CHECK(test_num1 == NumberWithUnits(9, "km"));
    CHECK(--test_num1 == NumberWithUnits(8, "km"));
    CHECK(test_num1 == NumberWithUnits(8, "km"));
}

TEST_CASE("before and after *, *=")
{
    NumberWithUnits::read_units(units_file);

    NumberWithUnits test_num1(4, "USD");
    NumberWithUnits test_num2(10, "m");

    CHECK((test_num1 * 1) == NumberWithUnits(4, "USD"));
    CHECK((test_num1 * 3.5) == NumberWithUnits(14, "USD"));
    CHECK((0.5 * test_num1) == NumberWithUnits(2, "USD"));
    CHECK((10 * test_num1) == NumberWithUnits(40, "USD"));
    
    CHECK((test_num2 *= 1) == NumberWithUnits(10, "m"));
    CHECK((test_num2 *= 2.5) == NumberWithUnits(25, "m"));
    CHECK((test_num2 *= 4) == NumberWithUnits(100, "m"));
    CHECK((test_num2 *= 4) == NumberWithUnits(400, "m"));
    CHECK((test_num2 *= 0.4) == NumberWithUnits(160, "m"));
  
}
