#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <limits>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cmath>


class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& src);
    ~ScalarConverter();
    ScalarConverter& operator=(const ScalarConverter& rhs);

    static int isChar(const std::string& input);
    static int isInt(const std::string& input);
    static int isFloat(const std::string& input);
    static int isDouble(const std::string& input);
    static int isPseudoLiteral(const std::string& input);

    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);
    static void printImpossibleAll();

public:
    static void convert(const std::string& input);
};

#endif