#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) 
{ 
    (void)src; 
}
ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
    (void)rhs;
    return *this;
}

int ScalarConverter::isChar(const std::string& input)
{
    return (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]));
}

int ScalarConverter::isInt(const std::string& input)
{
    size_t i = 0;
    if (input.empty())
        return 0;
    if ((input[0] == '+' || input[0] == '-') && input.length() > 1)
        i = 1;
    else if (input[0] == '+' || input[0] == '-')
        return 0;
    for (; i < input.length(); i++)
    {
        if (!std::isdigit(input[i]))
            return 0;
    }
    return 1;
}

int ScalarConverter::isFloat(const std::string& input)
{
    size_t i = 0;
    int dot = 0;
    int digit = 0;

    if (input.empty() || input[input.length() - 1] != 'f')
        return 0;
    if ((input[0] == '+' || input[0] == '-') && input.length() > 2)
        i = 1;
    for (;i < input.length() - 1; i++)
    {
        if (input[i] == '.')
        {
            dot++;
            if (dot > 1)
                return 0;
        }
        else if (std::isdigit(input[i]))
            digit = 1;
        else
            return 0;
    }
    return (dot == 1 && digit);
}

int ScalarConverter::isDouble(const std::string& input)
{
    size_t i = 0;
    int dot = 0;
    int digit = 0;

    if (input.empty())
        return 0;
    if ((input[0] == '+' || input[0] == '-') && input.length() > 1)
        i = 1;
    else if (input[0] == '+' || input[0] == '-')
        return 0;
    for (; i < input.length(); i++)
    {
        if (input[i] == '.')
        {
            dot++;
            if (dot > 1)
                return 0;
        }
        else if (std::isdigit(input[i]))
            digit = 1;
        else
            return 0;
    }
    return (dot == 1 && digit);
}

int ScalarConverter::isPseudoLiteral(const std::string& input)
{
    return (input == "inf" || input == "inff" || input == "nan" || input == "+inf" || input == "-inf" || input == "nanf" || input == "+inff" || input == "-inff");
}

void ScalarConverter::printImpossibleAll()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::printChar(double value)
{
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value)
{
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || value > INT_MAX || value < INT_MIN)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value)
{
    std::cout << "float: ";
    if (std::isnan(value))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(value))
    {
        if (value < 0)
            std::cout << "-inff" << std::endl;
        else
            std::cout << "+inff" << std::endl;
    }
    else
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
}

void ScalarConverter::printDouble(double value)
{
    std::cout << "double: ";
    if (std::isnan(value))
        std::cout << "nan" << std::endl;
    else if (std::isinf(value))
    {
        if (value < 0)
            std::cout << "-inf" << std::endl;
        else
            std::cout << "+inf" << std::endl;
    }
    else
        std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
    double value;

    if (isChar(input))
        value = static_cast<double>(input[0]);
    else if (isInt(input))
        value = static_cast<double>(std::atol(input.c_str()));
    else if (isFloat(input) || isDouble(input))
        value = std::atof(input.c_str());
    else if (isPseudoLiteral(input))
    {
        if (input == "nan" || input == "nanf")
            value = std::numeric_limits<double>::quiet_NaN();
        else if (input == "+inf" || input == "+inff")
            value = std::numeric_limits<double>::infinity();
        else
            value = -std::numeric_limits<double>::infinity();
    }
    else
    {
        printImpossibleAll();
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}