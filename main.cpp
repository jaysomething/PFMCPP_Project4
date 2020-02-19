/*
 Project 4 - Part 3 / 9
 Video: Chapter 4 Part 3 
 Casting

 Create a branch named Part3
 
    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.

 1) remove your functions that accepted a User-Defined Type
 
 2) remove any getValue() functions if you added them
 
 3) move all of your add/subtract/multiply/divide implementations out of the class.
  
 4) add user-defined conversion functions that convert to the numeric type your object holds.
        i.e. if your type holds an int, you'll need an operator int() function.
 
 5) make your member variable private.
         this conversion function should be the ONLY WAY to access the held value.
 
 6) clean up any forward declaration that you might have.
 
 7) make sure it compiles & runs without errors.
 
 8) use your knowledge of casting to remove any conversion warnings. 
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

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
