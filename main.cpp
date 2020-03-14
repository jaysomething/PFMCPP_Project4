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

struct FloatType
{
    FloatType(float val = 0.0f) : m_value(new float(val)) {}
    ~FloatType()
	{
		delete m_value;
		m_value = nullptr;
	}

	operator float() { return *m_value; }

    FloatType& add(float v);
    FloatType& subtract(float v);
    FloatType& multiply(float v);
    FloatType& divide(float v);
	
private:
	float* m_value { nullptr };
};

struct DoubleType
{
    DoubleType(double val = 0.0) : m_value(new double(val)) {}
    ~DoubleType()
	{
		delete m_value;
		m_value = nullptr;
	}

	operator double() { return *m_value; }

    DoubleType& add(double v);
    DoubleType& subtract(double v);
    DoubleType& multiply(double v);
    DoubleType& divide(double v);
	
private:
	double* m_value { nullptr };
};

struct IntType
{
    IntType(int val = 0) : m_value(new int(val)) {}
    ~IntType()
	{
		delete m_value;
		m_value = nullptr;
	}

	operator int() { return *m_value; }
	
    IntType& add(int v);
    IntType& subtract(int v);
    IntType& multiply(int v);
    IntType& divide(int v);

private:
	int* m_value { nullptr };
};

FloatType& FloatType::add(float v)
{
	std::cout << "(ft) " << *m_value << " + " << v << " = " << *m_value + v << '\n';
	*m_value += v;
    return *this;
}

FloatType& FloatType::subtract(float v)
{
	std::cout << "(ft) " << *m_value << " - " << v << " = " << *m_value - v << '\n';
    *m_value -= v;
    return *this;
}

FloatType& FloatType::multiply(float v)
{
	std::cout << "(ft) " << *m_value << " * " << v << " = " << *m_value * v << '\n';
    *m_value *= v;
    return *this;
}

FloatType& FloatType::divide(float v)
{
	std::cout << "(ft) " << *m_value << " / " << v << " = " << *m_value / v << '\n';
	*m_value /= v;
    return *this;
}

// DoubleType member functions implementation
DoubleType& DoubleType::add(double v)
{
	std::cout << "(dt) " << *m_value << " + " << v << " = " << *m_value + v << '\n';
	*m_value += v;
    return *this;
}

DoubleType& DoubleType::subtract(double v)
{
	std::cout << "(dt) " << *m_value << " - " << v << " = " << *m_value - v << '\n';
    *m_value -= v;
    return *this;
}

DoubleType& DoubleType::multiply(double v)
{
	std::cout << "(dt) " << *m_value << " * " << v << " = " << *m_value * v << '\n';
    *m_value *= v;
    return *this;
}

DoubleType& DoubleType::divide(double v)
{
	std::cout << "(dt) " << *m_value << " / " << v << " = " << *m_value / v << '\n';
	*m_value /= v;
    return *this;
}

// IntType member functions implementation
IntType& IntType::add(int v)
{
	std::cout << "(it) " << *m_value << " + " << v << " = " << *m_value + v << '\n';
	*m_value += v;
    return *this;
}

IntType& IntType::subtract(int v)
{
	std::cout << "(it) " << *m_value << " - " << v << " = " << *m_value - v << '\n';
    *m_value -= v;
    return *this;
}

IntType& IntType::multiply(int v)
{
	std::cout << "(it) " << *m_value << " * " << v << " = " << *m_value * v << '\n';
    *m_value *= v;
    return *this;
}

IntType& IntType::divide(int v)
{
    if (v == 0)
    {
        std::cout << "Error: Int division by zero. Calculation skipped. ";
        std::cout << "(it) " << *m_value << '\n';
    }
    else
    {
        std::cout << "(it) " << *m_value << " / " << v << " = " << *m_value / v << '\n';
        *m_value /= v;
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
    ft.add(it).multiply(ft).subtract(static_cast<float>(dt)).divide(it);
    std::cout << '\n';

    std::cout << "- ";
    std::cout << "DoubleType UDT calculations:\n";
    dt.add(it).multiply(static_cast<double>(ft)).subtract(static_cast<double>(ft)).divide(it);
    std::cout << '\n';

    std::cout << "- ";
    std::cout << "IntType UDT calculations:\n";
    it.add(it).multiply(static_cast<int>(ft)).subtract(static_cast<int>(ft)).divide(static_cast<int>(dt));
    std::cout << '\n';

    std::cout << "- ";
    std::cout << "Division by zero (primitive):\n";
    ft.divide(0.0f);
    dt.divide(0.0);
    it.divide(0);
    std::cout << '\n';

    std::cout << "good to go!" << std::endl;
}
