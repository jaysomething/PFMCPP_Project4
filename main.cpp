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

#include <iostream>
#include <cmath>

// Forward declaration
struct FloatType;
struct DoubleType;
struct IntType;

struct Point
{
    Point(float val_x, float val_y);
    Point(const FloatType& val_x, const FloatType& val_y);
    Point(const DoubleType& val_x, const DoubleType& val_y);
    Point(const IntType& val_x, const IntType& val_y);
    Point(const FloatType& ft);
    Point(const DoubleType& dt);
    Point(const IntType& it);
    
    Point& multiply(float m);
    Point& multiply(const FloatType& m);
    Point& multiply(const DoubleType& m);
    Point& multiply(const IntType& m);
    
    Point& toString()
    {
        std::cout << "x = " << x << ", y = " << y << '\n';
        return *this;
    }
    
private:
    float x{0}, y{0};
};

struct FloatType
{
    FloatType(float val = 0.0f) : value(new float(val)) {}
    ~FloatType()
    {
        delete value;
    }

    operator float() const { return *value; }

    FloatType& add(float v);
    FloatType& subtract(float v);
    FloatType& multiply(float v);
    FloatType& divide(float v);

    FloatType& pow(const IntType& v);
    FloatType& pow(const FloatType& v);
    FloatType& pow(const DoubleType& v);
    FloatType& pow(float);

    FloatType& powInternal(float v);
    
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

    operator double() const { return *value; }

    DoubleType& add(double v);
    DoubleType& subtract(double v);
    DoubleType& multiply(double v);
    DoubleType& divide(double v);

    DoubleType& pow(const IntType& v);
    DoubleType& pow(const FloatType& v);
    DoubleType& pow(const DoubleType& v);
    DoubleType& pow(double);

    DoubleType& powInternal(double v);
    
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

    operator int() const { return *value; }

    IntType& add(int v);
    IntType& subtract(int v);
    IntType& multiply(int v);
    IntType& divide(int v);

    IntType& pow(const IntType& v);
    IntType& pow(const FloatType& v);
    IntType& pow(const DoubleType& v);
    IntType& pow(int);

    IntType& powInternal(int v);

private:
    int* value { nullptr };
};

// Point class
Point::Point(float val_x, float val_y) : x(val_x), y(val_y) {}
Point::Point(const FloatType& val_x, const FloatType& val_y) : x(val_x), y(val_y) {}
Point::Point(const DoubleType& val_x, const DoubleType& val_y) : x(static_cast<float>(val_x)), y(static_cast<float>(val_y)) {}
Point::Point(const IntType& val_x, const IntType& val_y) : x(static_cast<float>(val_x)), y(static_cast<float>(val_y)) {}
Point::Point(const FloatType& ft) : x(ft), y(ft) {}
Point::Point(const DoubleType& dt) : x(static_cast<float>(dt)), y(static_cast<float>(dt)) {}
Point::Point(const IntType& it) : x(static_cast<float>(it)), y(static_cast<float>(it)) {}

Point& Point::multiply(float m)
{
    x *= m;
    y *= m;
    return *this;
}

Point& Point::multiply(const FloatType& m)
{
    return multiply(static_cast<float>(m));
}

Point& Point::multiply(const DoubleType& m)
{
    return multiply(static_cast<float>(m));
}

Point& Point::multiply(const IntType& m)
{
    return multiply(static_cast<float>(m));
}

// FloatType member functions implementation
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

FloatType& FloatType::pow(const IntType& v)
{
    return FloatType::powInternal(v);
}

FloatType& FloatType::pow(const FloatType& v)
{
    return FloatType::powInternal(v);
}

FloatType& FloatType::pow(const DoubleType& v)
{
    return FloatType::powInternal(static_cast<float>(v));
}

FloatType& FloatType::pow(float v)
{
    return FloatType::powInternal(v);
}

FloatType& FloatType::powInternal(float v)
{
    *value = std::pow( *value, v);
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

DoubleType& DoubleType::pow(const IntType& v)
{
    return DoubleType::powInternal(v); 
}

DoubleType& DoubleType::pow(const FloatType& v)
{
    return DoubleType::powInternal(static_cast<double>(v)); 
}

DoubleType& DoubleType::pow(const DoubleType& v)
{
    return DoubleType::powInternal(v); 
} 

DoubleType& DoubleType::pow(double v)
{
    return DoubleType::powInternal(v); 
}

DoubleType& DoubleType::powInternal(double v)
{
    *value = std::pow(*value, v);
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

IntType& IntType::pow(const IntType& v)
{
    return IntType::powInternal(v); 
}

IntType& IntType::pow(const FloatType& v)
{
    return IntType::powInternal(static_cast<int>(v)); 
}

IntType& IntType::pow(const DoubleType& v)
{
    return IntType::powInternal(static_cast<int>(v)); 
}

IntType& IntType::pow(int v)
{
    return IntType::powInternal(v); 
}

IntType& IntType::powInternal(int v)
{
    *value = static_cast<int>(std::pow(*value, v));
    return *this;
}

int main()
{
    FloatType ft(2.0f);
    DoubleType dt(3.0);
    IntType it(4);

    ft.pow(dt);
    std::cout << ft << '\n';

    dt.pow(it);
    std::cout << dt << '\n';

    it.pow(ft);
    std::cout << it << '\n';

    Point p1(dt, dt);
    p1.toString();
    p1.multiply(ft).toString().multiply(dt).toString().multiply(it).toString();

    Point p2(ft, it);
    p2.toString();
    p2.multiply(ft).toString().multiply(dt).toString().multiply(it).toString();

    Point p3(it);
    p3.toString();

    std::cout << "good to go!" << std::endl;
}
