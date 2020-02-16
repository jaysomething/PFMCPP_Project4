/*
 Project 4 - Part 1 / 9
 video: Chapter 2 Part 7
 Returning Values tasks 

 Create a branch named Part1
 
 1) write 3 UDTs named FloatType, DoubleType, IntType.
 
 2) give each UDT the following member functions:
        add( lhs, rhs );
        subtract( lhs, rhs );
        multiply( lhs, rhs );
        divide( lhs, rhs );
 
 3) make them return the correct primitive type. e.g. if you're implementing the FloatType::add function, your implementation would start like this:
        float FloatType::add( float lhs, float rhs )
 
 4) declare a few instances of each class in main() and call the member functions with the appropriate arguments.
        FloatType ft;
        auto result = ft.add(3.2f, 23.f );
 
 5) print out those results using std::cout:
        std::cout "result of ft.add(): " << result << std::endl;
 
 6) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */
#include <iostream>

struct FloatType
{
    float add(float lhs, float rhs);
    float subtract(float lhs, float rhs);
    float multiply(float lhs, float rhs);
    float divide(float lhs, float rhs);
};

float FloatType::add(float lhs, float rhs)
{
    return lhs + rhs;
}

float FloatType::subtract(float lhs, float rhs)
{
    return lhs - rhs;
}

float FloatType::multiply(float lhs, float rhs)
{
    return lhs * rhs;
}

float FloatType::divide(float lhs, float rhs)
{
    if (rhs == 0.0f)
    {
        std::cout << "Error: cannot divide by 0! Returning 0 instead\n";
        return 0;
    }
    else
        return lhs / rhs;
}

struct DoubleType
{
    double add(double lhs, double rhs);
    double subtract(double lhs, double rhs);
    double multiply(double lhs, double rhs);
    double divide(double lhs, double rhs);
};

double DoubleType::add(double lhs, double rhs)
{
    return lhs + rhs;
}

double DoubleType::subtract(double lhs, double rhs)
{
    return lhs - rhs;
}

double DoubleType::multiply(double lhs, double rhs)
{
    return lhs * rhs;
}

double DoubleType::divide(double lhs, double rhs)
{
    if (rhs == 0.0)
    {
        std::cout << "Error: cannot divide by 0! Returning 0 instead\n";
        return 0;
    }
    else
        return lhs / rhs;
}

struct IntType
{
    int add(int lhs, int rhs);
    int subtract(int lhs, int rhs);
    int multiply(int lhs, int rhs);
    int divide(int lhs, int rhs);
};

int IntType::add(int lhs, int rhs)
{
    return lhs + rhs;
}

int IntType::subtract(int lhs, int rhs)
{
    return lhs - rhs;
}

int IntType::multiply(int lhs, int rhs)
{
    return lhs * rhs;
}

int IntType::divide(int lhs, int rhs)
{
    if (rhs == 0)
    {
        std::cout << "Error: cannot divide by 0! Returning 0 instead\n";
        return 0;
    }
    else
        return lhs / rhs;
}

int main()
{
    FloatType ft;
    DoubleType dt;
    IntType it;

    auto ftAdd = ft.add(3.2f, 23.0f);
    std::cout << "result of ft.add: " << ftAdd << '\n';
    auto dtAdd = dt.add(3.2, 23.0);
    std::cout << "result of dt.add: " << dtAdd << '\n';
    auto itAdd = it.add(3, 2);
    std::cout << "result of it.add: " << itAdd << '\n';

    auto ftSub = ft.subtract(3.2f, 23.0f);
    std::cout << "result of ft.subtract: " << ftSub << '\n';
    auto dtSub = dt.subtract(3.2, 23.0);
    std::cout << "result of dt.subtract: " << dtSub << '\n';
    auto itSub = it.subtract(3, 2);
    std::cout << "result of it.subtract: " << itSub << '\n';

    auto ftMult = ft.multiply(3.2f, 23.0f);
    std::cout << "result of ft.multiply: " << ftMult << '\n';
    auto dtMult = dt.multiply(3.2, 23.0);
    std::cout << "result of dt.multiply: " << dtMult << '\n';
    auto itMult = it.multiply(3, 2);
    std::cout << "result of it.multiply: " << itMult << '\n';
    
    auto ftDiv = ft.divide(3.2f, 23.0f);
    std::cout << "result of ft.divide: " << ftDiv << '\n';
    auto dtDiv = dt.divide(3.2, 23.0);
    std::cout << "result of dt.divide: " << dtDiv << '\n';
    auto itDiv = it.divide(3, 2);
    std::cout << "result of it.divide: " << itDiv << '\n';
    itDiv = it.divide(3, 0);
    std::cout << "result of it.divide: " << itDiv << '\n';

    std::cout << "good to go!" << std::endl;
}
