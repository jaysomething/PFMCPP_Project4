/*
Project 4: Part 4 / 9
 Chapter 4 Part 7
 Function/Constructor Overloading

 Create a branch named Part4
 
 Do not delete your previous main. you will be adding to it.

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 1) add pow() functions, and a powInternal() function to each of your UDTs
     a) your pow() functions should call powInternal()
     b) add a pow() whose argument type is the primitive your UDT owns.  the argument should be passed by copy.
     c) for each UDT in the file, your class should have pow() overloads that take that UDT as the function argument.
         the argument should be passed as const ref
         i.e. if you had UDTs named IntType, FloatType, DoubleType
             in your IntType class, you'd have:
                 pow(const IntType&),
                 pow(const FloatType&),
                 pow(const DoubleType&),
                 and pow(int)
     d) be sure to remember the rules about what member functions can be called on const objects.
             (const objects can only call their const member functions)
 
 2) your powInternal() function should do something like this in its body:    *val = std::pow( *val, arg );
         where 'arg' is the passed-in type, converted to whatever type your object is holding.
             if your UDT owns an int, then arg would be an int.
             if your UDT owns a float, then arg would be a float.
         std::pow's documentation is found here: https://en.cppreference.com/w/cpp/numeric/math/pow so be sure to include
             the proper header file listed there.
 
 3) modify the Point class below to have Constructors that accept your UDTs.
     a) make the Constructor's UDT arguments initialize the Point class's two member variables.
     b) overload the multiply() function so it can accept each of your UDTs.  I've added an implementation you can mimick for this function.
     c) add a toString() function to the Point class that prints out the x and y members via std::cout.
 
 4) Add to main()
     a) use your new pow() function in main for all of your types and print out the results.
     b) use the Point class in main and multiply some Point instances with your UDTs
     c) use the Point::toString() function to print out the results.
 
 
 5) make sure it compiles without errors.
 
 You will need to use Forward Declaration and out-of-class definitions to complete this.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

struct Point
{
    Point& multiply(float m)
    {
        x *= m;
        y *= m;
        return *this;
    }
private:
    float x{0}, y{0};
};



#include <iostream>

struct FloatType
{
    FloatType(float val = 0.0f) : value(new float(val)) {}
    ~FloatType()
    {
        delete value;
    }

    operator float() { return *value; }

    FloatType& add(float v);
    FloatType& subtract(float v);
    FloatType& multiply(float v);
    FloatType& divide(float v);
    
private:
    float* value { nullptr };
};

struct DoubleType
{
    DoubleType(double val = 0.0) : value(new double(val)) {}
    ~DoubleType()
    {
        delete value;
    }

    operator double() { return *value; }

    DoubleType& add(double v);
    DoubleType& subtract(double v);
    DoubleType& multiply(double v);
    DoubleType& divide(double v);
    
private:
    double* value { nullptr };
};

struct IntType
{
    IntType(int val = 0) : value(new int(val)) {}
    ~IntType()
    {
        delete value;
    }

    operator int() { return *value; }
    
    IntType& add(int v);
    IntType& subtract(int v);
    IntType& multiply(int v);
    IntType& divide(int v);

private:
    int* value { nullptr };
};

FloatType& FloatType::add(float v)
{
    *value += v;
    return *this;
}

FloatType& FloatType::subtract(float v)
{
    *value -= v;
    return *this;
}

FloatType& FloatType::multiply(float v)
{
    *value *= v;
    return *this;
}

FloatType& FloatType::divide(float v)
{
    *value /= v;
    return *this;
}

// DoubleType member functions implementation
DoubleType& DoubleType::add(double v)
{
    *value += v;
    return *this;
}

DoubleType& DoubleType::subtract(double v)
{
    *value -= v;
    return *this;
}

DoubleType& DoubleType::multiply(double v)
{
    *value *= v;
    return *this;
}

DoubleType& DoubleType::divide(double v)
{
    *value /= v;
    return *this;
}

// IntType member functions implementation
IntType& IntType::add(int v)
{
    *value += v;
    return *this;
}

IntType& IntType::subtract(int v)
{
    *value -= v;
    return *this;
}

IntType& IntType::multiply(int v)
{
    *value *= v;
    return *this;
}

IntType& IntType::divide(int v)
{
    if (v == 0)
    {
        std::cout << "Error: Int division by zero. Calculation skipped. Return original value: ";
    }
    else
    {
        *value /= v;
    }
    return *this;
}

int main()
{
    
    FloatType ft(-1.1f);
    std::cout << "- ";
    std::cout << "FloatType primitive calculations: " << ft.add(8.0f).subtract(7.0f).multiply(6.0f).divide(5.0f) << '\n';

    DoubleType dt(2.2);
    std::cout << "- ";
    std::cout << "DoubleType primitive calculations: " << dt.add(8.0).subtract(7.0).multiply(6.0).divide(5.0) << '\n';

    IntType it(3);
    std::cout << "- ";
    std::cout << "IntType primitive calculations: " << it.add(8).subtract(7).multiply(6).divide(5) << '\n';

    std::cout << "- ";
    std::cout << "FloatType UDT calculations: " << ft.add(it).multiply(ft).subtract(static_cast<float>(dt)).divide(it) << '\n';

    std::cout << "- ";
    std::cout << "DoubleType UDT calculations: " << dt.add(it).multiply(static_cast<double>(ft)).subtract(static_cast<double>(ft)).divide(it) << '\n';

    std::cout << "- ";
    std::cout << "IntType UDT calculations: " << it.add(it).multiply(static_cast<int>(ft)).subtract(static_cast<int>(ft)).divide(static_cast<int>(dt)) << '\n';

    std::cout << "- ";
    std::cout << "Division by zero (primitive): " << '\n';
    std::cout << ft.divide(0.0f) << '\n';
    std::cout << dt.divide(0.0) << '\n';
    std::cout << it.divide(0) << '\n';
    std::cout << '\n';

    std::cout << "good to go!" << std::endl;
}
