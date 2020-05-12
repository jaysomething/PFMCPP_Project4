
#include <iostream>
/*
Project 4: Part 5 / 9
 video: Chapter 5 Part 2
 Operator Overloading.

Do not delete your previous main. 

 Create a branch named Part5

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 1) replace the add/subtract/multiply/etc functions with overloaded math operators 
        e.g. add() would become operator+=() because it modifies the internal heap-allocated object.
 
 2) Your overloaded operators should only take primitives, passed by value.
 
 3) don't delete your conversion functions.
         if you removed them in Chapter 4 Part 7, put them back in.
         uncomment them if you commented them in Chapter 4 Part 7
 
 4) your main() function should be the same as Chapter 4 Part 7.  
     
 5) if your Chapter4 Part7 task didn't use any [+ - * or /], 
         add some in and fix the build errors that might result via the techniques you have learned in the previous weeks (hint: casting)
         i.e.
 */
#if false
namespace Example
{
    int main()
    {
        FloatType floatNum(4.3f);
        IntType intNum(2);
        IntType intNum2(6);

        /* 
        if you previously had a line like this demonstrating chaining:
            
            intNum.add(3).add(4.5f).divide(floatNum); 

        it should become:
        */
        intNum += 3;
        intNum += 4.5f;
        intNum /= floatNum;
        std::cout << "intNum: " << intNum << std::endl;
        
        return 0;
    }
}
#endif
 /*
 6) compile/link/run to make sure you don't have any errors

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
    return powInternal(v);
}

FloatType& FloatType::pow(const FloatType& v)
{
    return powInternal(v);
}

FloatType& FloatType::pow(const DoubleType& v)
{
    return powInternal(static_cast<float>(v));
}

FloatType& FloatType::pow(float v)
{
    return powInternal(v);
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
    return powInternal(v);
}

DoubleType& DoubleType::pow(const FloatType& v)
{
    return powInternal(static_cast<double>(v));
}

DoubleType& DoubleType::pow(const DoubleType& v)
{
    return powInternal(v);
} 

DoubleType& DoubleType::pow(double v)
{
    return powInternal(v);
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
    return powInternal(v);
}

IntType& IntType::pow(const FloatType& v)
{
    return powInternal(static_cast<int>(v));
}

IntType& IntType::pow(const DoubleType& v)
{
    return powInternal(static_cast<int>(v));
}

IntType& IntType::pow(int v)
{
    return powInternal(v);
}

IntType& IntType::powInternal(int v)
{
    *value = static_cast<int>(std::pow(*value, v));
    return *this;
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

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
