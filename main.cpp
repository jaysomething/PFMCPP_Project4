/*
 Project 4 - Part 2 / 9
 Video: Chapter 3 Part 6

 Create a branch named Part2

New/This/Pointers/References conclusion

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 0) in the blank space below, declare/define an empty struct named 'A' on a single Line. 
     on the lines below it, write a struct named 'HeapA' that correctly shows how to own an instance of 'A' 
         on the heap without leaking, without using smart pointers. 
 */

struct A {};

struct HeapA 
{
    ~HeapA() { delete a; }

    A* a {new A};
};

 /*
 1) Edit your 3 structs so that they own a heap-allocated primitive type without using smart pointers  
         IntType should own a heap-allocated int, for example.
 
 2) give it a constructor that takes the appropriate primitive
    this argument will initialize the owned primitive's value.
         i.e. if you're owning an int on the heap, your ctor argument will initialize that heap-allocated int's value.
 
 3) modify those add/subtract/divide/multiply member functions from chapter 2 on it
         a) make them modify the owned numeric type
         b) set them up so they can be chained together.
             i.e.
             DoubleType dt(3.5);
             dt.add(3.0).multiply(-2.5).divide(7.2); //an example of chaining
 
 4) write add/subtract/divide/multiply member functions for each type that take your 3 UDTs
        These are in addition to your member functions that take primitives
        for example, IntType::divide(const DoubleType& dt);
 
 5) print out the results with some creative couts 
    i.e.
         FloatType ft(0.1f);
         IntType it(3);
         std::cout << "adding 3 and subtracting 'it' from 'ft' results in the following value: " << *ft.add(2.f).subtract( it ).value << std::endl;  //note the dereference of the `value` member of `ft`
 
 6) Don't let your heap-allocated owned type leak!
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */



#include <iostream>

struct DoubleType;
struct IntType;

struct FloatType
{
    FloatType(float val) : value(new float(val)) {}
    ~FloatType() { delete value; }

    float* value;

    // primitives
    FloatType& add(float v);
    FloatType& subtract(float v);
    FloatType& multiply(float v);
    FloatType& divide(float v);
    // FloatType args
    FloatType& add(const FloatType& ft);
    FloatType& subtract(const FloatType& ft);
    FloatType& multiply(const FloatType& ft);
    FloatType& divide(const FloatType& ft);
    // DoubleType args
    FloatType& add(const DoubleType& dt);
    FloatType& subtract(const DoubleType& dt);
    FloatType& multiply(const DoubleType& dt);
    FloatType& divide(const DoubleType& dt);
    // IntType args
    FloatType& add(const IntType& it);
    FloatType& subtract(const IntType& it);
    FloatType& multiply(const IntType& it);
    FloatType& divide(const IntType& it);
};

struct DoubleType
{
    DoubleType() {}
    DoubleType(double val) : value(new double(val)) {}
    ~DoubleType() { delete value; }

    double* value;

    // primitives
    DoubleType& add(double v);
    DoubleType& subtract(double v);
    DoubleType& multiply(double v);
    DoubleType& divide(double v);
    // FloatType args
    DoubleType& add(const FloatType& ft);
    DoubleType& subtract(const FloatType& ft);
    DoubleType& multiply(const FloatType& ft);
    DoubleType& divide(const FloatType& ft);
    // DoubleType args
    DoubleType& add(const DoubleType& dt);
    DoubleType& subtract(const DoubleType& dt);
    DoubleType& multiply(const DoubleType& dt);
    DoubleType& divide(const DoubleType& dt);
    // IntType args
    DoubleType& add(const IntType& it);
    DoubleType& subtract(const IntType& it);
    DoubleType& multiply(const IntType& it);
    DoubleType& divide(const IntType& it);
};

struct IntType
{
    IntType() {}
    IntType(int val) : value(new int(val)) {}
    ~IntType() { delete value; }

    int* value;

    // primitives
    IntType& add(int v);
    IntType& subtract(int v);
    IntType& multiply(int v);
    IntType& divide(int v);
    // FloatType args
    IntType& add(const FloatType& ft);
    IntType& subtract(const FloatType& ft);
    IntType& multiply(const FloatType& ft);
    IntType& divide(const FloatType& ft);
    // DoubleType args
    IntType& add(const DoubleType& dt);
    IntType& subtract(const DoubleType& dt);
    IntType& multiply(const DoubleType& dt);
    IntType& divide(const DoubleType& dt);
    // IntType args
    IntType& add(const IntType& it);
    IntType& subtract(const IntType& it);
    IntType& multiply(const IntType& it);
    IntType& divide(const IntType& it);
};

// FloatType member functions implementation
// Primitives
FloatType& FloatType::add(float v)
{
    std::cout << "(ft) " << *value << " + " << v << " = ";
    *value += v;
    std::cout << *value << '\n';
    return *this;
}

FloatType& FloatType::subtract(float v)
{
    std::cout << "(ft) " << *value << " - " << v << " = ";
    *value -= v;
    std::cout << *value << '\n';
    return *this;
}

FloatType& FloatType::multiply(float v)
{
    std::cout << "(ft) " << *value << " * " << v << " = ";
    *value *= v;
    std::cout << *value << '\n';
    return *this;
}

FloatType& FloatType::divide(float v)
{
    std::cout << "(ft) " << *value << " / " << v << " = ";
    *value /= v;
    std::cout << *value << '\n';
    return *this;
}

// FloatType member functions implementation
// FloatType argument
FloatType& FloatType::add(const FloatType& ft)
{
    std::cout << "(ft) " << *value << " + (ft) " << *ft.value << " = ";
    *value = *value + *ft.value;
    std::cout << *value << '\n';
    return *this;
}

FloatType& FloatType::subtract(const FloatType& ft)
{
    std::cout << "(ft) " << *value << " - (ft) " << *ft.value << " = ";
    *value = *value - *ft.value;
    std::cout << *value << '\n';
    return *this;
}

FloatType& FloatType::multiply(const FloatType& ft)
{
    std::cout << "(ft) " << *value << " * (ft) " << *ft.value << " = ";
    *value = *value * *ft.value;
    std::cout << *value << '\n';
    return *this;
}

FloatType& FloatType::divide(const FloatType& ft)
{
    std::cout << "(ft) " << *value << " / (ft) " << *ft.value << " = ";
    *value = *value / *ft.value;
    std::cout << *value << '\n';
    return *this;
}

// FloatType member functions implementation
// DoubleType argument
FloatType& FloatType::add(const DoubleType& dt)
{
    std::cout << "(ft) " << *value << " + (dt) " << *dt.value << " = ";
    *value = *value + *dt.value;
    std::cout << *value << '\n';
    return *this;
}

FloatType& FloatType::subtract(const DoubleType& dt)
{
    std::cout << "(ft) " << *value << " - (dt) " << *dt.value << " = ";
    *value = *value - *dt.value;
    std::cout << *value << '\n';
    return *this;
}

FloatType& FloatType::multiply(const DoubleType& dt)
{
    std::cout << "(ft) " << *value << " * (dt) " << *dt.value << " = ";
    *value = *value * *dt.value;
    std::cout << *value << '\n';
    return *this;
}

FloatType& FloatType::divide(const DoubleType& dt)
{
    std::cout << "(ft) " << *value << " / (dt) " << *dt.value << " = ";
    *value = *value / *dt.value;
    std::cout << *value << '\n';
    return *this;
}

// IntType argument
FloatType& FloatType::add(const IntType& it)
{
    std::cout << "(ft) " << *value << " + (it) " << *it.value << " = ";
    *value = *value + *it.value;
    std::cout << *value << '\n';
    return *this;
}

FloatType& FloatType::subtract(const IntType& it)
{
    std::cout << "(ft) " << *value << " - (it) " << *it.value << " = ";
    *value = *value - *it.value;
    std::cout << *value << '\n';
    return *this;
}

FloatType& FloatType::multiply(const IntType& it)
{
    std::cout << "(ft) " << *value << " * (it) " << *it.value << " = ";
    *value = *value * *it.value;
    std::cout << *value << '\n';
    return *this;
}

FloatType& FloatType::divide(const IntType& it)
{
    std::cout << "(ft) " << *value << " / (it) " << *it.value << " = ";
    *value = *value / *it.value;
    std::cout << *value << '\n';
    return *this;
}

// DoubleType member functions implementation
// Primitives
DoubleType& DoubleType::add(double v)
{
    std::cout << "(dt) " << *value << " + " << v << " = ";
    *value += v;
    std::cout << *value << '\n';
    return *this;
}

DoubleType& DoubleType::subtract(double v)
{
    std::cout << "(dt) " << *value << " - " << v << " = ";
    *value -= v;
    std::cout << *value << '\n';
    return *this;
}

DoubleType& DoubleType::multiply(double v)
{
    std::cout << "(dt) " << *value << " * " << v << " = ";
    *value *= v;
    std::cout << *value << '\n';
    return *this;
}

DoubleType& DoubleType::divide(double v)
{
    std::cout << "(dt) " << *value << " / " << v << " = ";
    *value /= v;
    std::cout << *value << '\n';
    return *this;
}

// DoubleType member functions implementation
// FloatType argument
DoubleType& DoubleType::add(const FloatType& ft)
{
    std::cout << "(dt) " << *value << " + (ft) " << *ft.value << " = ";
    *value = *value + *ft.value;
    std::cout << *value << '\n';
    return *this;
}

DoubleType& DoubleType::subtract(const FloatType& ft)
{
    std::cout << "(dt) " << *value << " - (ft) " << *ft.value << " = ";
    *value = *value - *ft.value;
    std::cout << *value << '\n';
    return *this;
}

DoubleType& DoubleType::multiply(const FloatType& ft)
{
    std::cout << "(dt) " << *value << " * (ft) " << *ft.value << " = ";
    *value = *value * *ft.value;
    std::cout << *value << '\n';
    return *this;
}

DoubleType& DoubleType::divide(const FloatType& ft)
{
    std::cout << "(dt) " << *value << " / (ft) " << *ft.value << " = ";
    *value = *value / *ft.value;
    std::cout << *value << '\n';
    return *this;
}

// DoubleType member functions implementation
// DoubleType argument
DoubleType& DoubleType::add(const DoubleType& dt)
{
    std::cout << "(dt) " << *value << " + (dt) " << *dt.value << " = ";
    *value = *value + *dt.value;
    std::cout << *value << '\n';
    return *this;
}

DoubleType& DoubleType::subtract(const DoubleType& dt)
{
    std::cout << "(dt) " << *value << " - (dt) " << *dt.value << " = ";
    *value = *value - *dt.value;
    std::cout << *value << '\n';
    return *this;
}

DoubleType& DoubleType::multiply(const DoubleType& dt)
{
    std::cout << "(dt) " << *value << " * (dt) " << *dt.value << " = ";
    *value = *value * *dt.value;
    std::cout << *value << '\n';
    return *this;
}

DoubleType& DoubleType::divide(const DoubleType& dt)
{
    std::cout << "(dt) " << *value << " / (dt) " << *dt.value << " = ";
    *value = *value / *dt.value;
    std::cout << *value << '\n';
    return *this;
}

// DoubleType member functions implementation
// IntType argument
DoubleType& DoubleType::add(const IntType& it)
{
    std::cout << "(dt) " << *value << " + (it) " << *it.value << " = ";
    *value = *value + *it.value;
    std::cout << *value << '\n';
    return *this;
}

DoubleType& DoubleType::subtract(const IntType& it)
{
    std::cout << "(dt) " << *value << " - (it) " << *it.value << " = ";
    *value = *value - *it.value;
    std::cout << *value << '\n';
    return *this;
}

DoubleType& DoubleType::multiply(const IntType& it)
{
    std::cout << "(dt) " << *value << " * (it) " << *it.value << " = ";
    *value = *value * *it.value;
    std::cout << *value << '\n';
    return *this;
}

DoubleType& DoubleType::divide(const IntType& it)
{
    std::cout << "(dt) " << *value << " / (it) " << *it.value << " = ";
    *value = *value / *it.value;
    std::cout << *value << '\n';
    return *this;
}

// IntType member functions implementation
// Primitives
IntType& IntType::add(int v)
{
    std::cout << "(it) " << *value << " + " << v << " = ";
    *value += v;
    std::cout << *value << '\n';
    return *this;
}

IntType& IntType::subtract(int v)
{
    std::cout << "(it) " << *value << " - " << v << " = ";
    *value -= v;
    std::cout << *value << '\n';
    return *this;
}

IntType& IntType::multiply(int v)
{
    std::cout << "(it) " << *value << " * " << v << " = ";
    *value *= v;
    std::cout << *value << '\n';
    return *this;
}

IntType& IntType::divide(int v)
{
    if (v == 0)
    {
        std::cout << "Error: Int division by zero. Calculation skipped. ";
        std::cout << "(it) " << *value << '\n';
    }
    else
    {
        std::cout << "(it) " << *value << " / " << v << " = ";
        *value /= v;
        std::cout << *value << '\n';
    }
    return *this;
}

// IntType member functions implementation
// FloatType argument
IntType& IntType::add(const FloatType& ft)
{
    std::cout << "(it) " << *value << " + (ft) " << *ft.value << " = ";
    *value = *value + *ft.value;
    std::cout << *value << '\n';
    return *this;
}

IntType& IntType::subtract(const FloatType& ft)
{
    std::cout << "(it) " << *value << " - (ft) " << *ft.value << " = ";
    *value = *value - *ft.value;
    std::cout << *value << '\n';
    return *this;
}

IntType& IntType::multiply(const FloatType& ft)
{
    std::cout << "(it) " << *value << " * (ft) " << *ft.value << " = ";
    *value = *value * *ft.value;
    std::cout << *value << '\n';
    return *this;
}

IntType& IntType::divide(const FloatType& ft)
{
    if (*ft.value == 0.0f)
    {
        std::cout << "Error: Int division by zero. Calculation skipped. ";
        std::cout << "(it) " << *value << '\n';
    }
    else
    {
        std::cout << "(it) " << *value << " / (ft) " << *ft.value << " = ";
        *value = *value / *ft.value;
        std::cout << *value << '\n';
    }
    return *this;
}

// IntType member functions implementation
// DoubleType argument
IntType& IntType::add(const DoubleType& dt)
{
    std::cout << "(it) " << *value << " + (dt) " << *dt.value << " = ";
    *value = *value + *dt.value;
    std::cout << *value << '\n';
    return *this;
}

IntType& IntType::subtract(const DoubleType& dt)
{
    std::cout << "(it) " << *value << " - (dt) " << *dt.value << " = ";
    *value = *value - *dt.value;
    std::cout << *value << '\n';
    return *this;
}

IntType& IntType::multiply(const DoubleType& dt)
{
    std::cout << "(it) " << *value << " * (dt) " << *dt.value << " = ";
    *value = *value * *dt.value;
    std::cout << *value << '\n';
    return *this;
}

IntType& IntType::divide(const DoubleType& dt)
{
    if (*dt.value == 0.0)
    {
        std::cout << "Error: Int division by zero. Calculation skipped. ";
        std::cout << "(it) " << *value << '\n';
    }
    else
    {
        std::cout << "(it) " << *value << " / (dt) " << *dt.value << " = ";
        *value = *value / *dt.value;
        std::cout << *value << '\n';
    }
    return *this;
}

// IntType member functions implementation
// IntType argument
IntType& IntType::add(const IntType& it)
{
    std::cout << "(it) " << *value << " + (it) " << *it.value << " = ";
    *value = *value + *it.value;
    std::cout << *value << '\n';
    return *this;
}

IntType& IntType::subtract(const IntType& it)
{
    std::cout << "(it) " << *value << " - (it) " << *it.value << " = ";
    *value = *value - *it.value;
    std::cout << *value << '\n';
    return *this;
}

IntType& IntType::multiply(const IntType& it)
{
    std::cout << "(it) " << *value << " * (it) " << *it.value << " = ";
    *value = *value * *it.value;
    std::cout << *value << '\n';
    return *this;
}

IntType& IntType::divide(const IntType& it)
{
    if (*it.value == 0)
    {
        std::cout << "Error: Int division by zero. Calculation skipped. ";
        std::cout << "(it) " << *value << '\n';
    }
    else
    {
        std::cout << "(it) " << *value << " / (it) " << *it.value << " = ";
        *value = *value / *it.value;
        std::cout << *value << '\n';
    }
    return *this;
}

int main()
{
    std::cout << "- ";
    std::cout << "FloatType primitive calculations:\n";
    FloatType ft(-1.1f);
    ft.add(8.0f).subtract(7.0f).multiply(6.0f).divide(5.0f);
    std::cout << '\n';

    std::cout << "- ";
    std::cout << "DoubleType primitive calculations:\n";
    DoubleType dt(2.2);
    dt.add(8.0).subtract(7.0).multiply(6.0).divide(5.0);
    std::cout << '\n';

    std::cout << "- ";
    std::cout << "IntType primitive calculations:\n";
    IntType it(3);
    it.add(8).subtract(7).multiply(6).divide(5);
    std::cout << '\n';

    std::cout << "- ";
    std::cout << "FloatType UDT calculations:\n";
    ft.add(it).multiply(ft).subtract(dt).divide(it);
    std::cout << '\n';

    std::cout << "- ";
    std::cout << "DoubleType UDT calculations:\n";
    dt.add(it).multiply(ft).subtract(ft).divide(it);
    std::cout << '\n';

    std::cout << "- ";
    std::cout << "IntType UDT calculations:\n";
    it.add(it).multiply(ft).subtract(ft).divide(dt);
    std::cout << '\n';

    *ft.value = 1.0f;
    *dt.value = 1.0;
    *it.value = 1;
    std::cout << "- ";
    std::cout << "Object values set to 1.\n";
    std::cout << '\n';

    std::cout << "- ";
    std::cout << "Division by zero (primitive):\n";
    ft.divide(0.0f);
    dt.divide(0.0);
    it.divide(0);
    std::cout << '\n';

    std::cout << "good to go!" << std::endl;
}
