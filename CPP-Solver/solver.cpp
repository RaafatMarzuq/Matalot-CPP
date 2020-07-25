#include "solver.hpp"
using namespace std;
namespace solver
{

//Operator(+)

const RealVariable RealVariable::operator+(const RealVariable &other) const
{
    return RealVariable(this->_a() + other._a(), this->_b() + other._b(), this->_c() + other._c());
}

const RealVariable RealVariable::operator+(const double &other) const
{
    return RealVariable(this->_a(), this->_b(), this->_c() + other);
}

const RealVariable operator+(const double &d, const RealVariable &r)
{
    return RealVariable(r._a(), r._b(), r._c() + d);
}

//Operator(-)

const RealVariable RealVariable::operator-(const RealVariable &other) const
{
    return RealVariable(this->a - other.a, this->b - other.b, this->c - other.c);
}

const RealVariable RealVariable::operator-(const double &other) const
{
    return RealVariable(this->a, this->b, this->c - other);
}

const RealVariable operator-(const double &d, const RealVariable &r)
{
    return RealVariable(r._a(), r._b(), r._c() - d);
}

//Operator(*)

const RealVariable RealVariable::operator*(const RealVariable &other) const
{
    return RealVariable(this->a * other._a(), this->b * other._b(), this->_c() * other._c());
}
const RealVariable RealVariable::operator*(const double &other) const
{
    return RealVariable(this->_a() * other, this->_b() * other, this->_c() * other);
}

const RealVariable operator*(const double &d, const RealVariable &r)
{
    return RealVariable(r._a() * d, r._b() * d, r._c() * d);
}

//Operator(/)

const RealVariable RealVariable::operator/(const double &other) const
{
    if (other == 0)
        throw runtime_error("can't divide by 0, \n Ya Melon");

    return RealVariable(this->_a() / other, this->_b() / other, this->c / other);
}

//operator(^)
const RealVariable RealVariable::operator^(const double &other) const
{
    if(other < 0.0)
    {
             throw runtime_error("Al mi ata ba");

    }
    if (other > 2.0)
        throw runtime_error("Al mi ata ba");

    if (other == 1)
        return *this;

    if (other == 0)
    {
        return RealVariable(0, 0, 1);
    }

    return RealVariable(1, 0, 0);
}
//Operator(==)

const RealVariable RealVariable::operator==(const RealVariable &other) const
{
    return RealVariable(this->a - other.a, this->b - other.b, this->c - other.c);
}

const RealVariable RealVariable::operator==(const double &other) const
{
    return RealVariable(this->a, this->b, this->c - other);
}

const RealVariable operator==(const double &d, const RealVariable &r)
{
    return RealVariable(r._a(), r._b(), r._c() - d);
}

complex<double> solve(const ComplexVariable &bi)
{
   if (bi._a().real() != 0)
    {
        complex<double> Desc = (bi._b() * bi._b()) - (4.0 * (bi._a()) * (bi._c()));
        
       
        complex<double> result = ((-bi._b()) + sqrt(Desc)) / (2.0 * bi._a());
        return result;
    }
    else if (bi._b() != std::complex<double>(0.0,0.0) )
    {
        return -(bi._c()) / bi._b();
    }
    else
    { // 1==0
        {
            throw runtime_error("No solution");
        }
    }
}
double solve(const RealVariable &x)
{

    if (x._a() != 0)
    {
        double Desc = (x._b() * x._b()) - (4 * (x._a()) * (x._c()));
        if (Desc < 0)
        {
            throw runtime_error("The answer is not a Real number ");
        }
        else{
        double result = ((-x._b()) + sqrt(Desc)) / (2 * x._a());
        return result;
    }
    }
    else if (x._b() != 0)
    {
        return -(x._c()) / x._b();
    }
    else
    { // 1==0
        {
            throw runtime_error("No solution");
        }
    }
}

///---------------------complex----------------------------

//Operator(+)

const ComplexVariable ComplexVariable::operator+(const ComplexVariable &other) const
{
    return ComplexVariable(this->_a() + other._a(), this->_b() + other._b(), this->_c() + other._c());
}

const ComplexVariable ComplexVariable::operator+(const complex<double> &other) const
{
    return ComplexVariable(this->_a(), this->_b(), this->_c() + other);
}

const ComplexVariable operator+(const complex<double> &d, const ComplexVariable &r)
{
    return ComplexVariable(r._a(), r._b(), r._c() + d);
}

//Operator(-)

const ComplexVariable ComplexVariable::operator-(const ComplexVariable &other) const
{
    return ComplexVariable(this->a - other.a, this->b - other.b, this->c - other.c);
}

const ComplexVariable ComplexVariable::operator-(const complex<double> &other) const
{
    return ComplexVariable(this->a, this->b, this->c - other);
}

const ComplexVariable operator-(const complex<double> &d, const ComplexVariable &r)
{
    return ComplexVariable(r._a(), r._b(), r._c() - d);
}

//Operator(*)

const ComplexVariable ComplexVariable::operator*(const ComplexVariable &other) const
{
    return ComplexVariable(this->a * other._a(), this->b * other._b(), this->_c() * other._c());
}
const ComplexVariable ComplexVariable::operator*(const complex<double> &other) const
{
    return ComplexVariable(this->_a() * other, this->_b() * other, this->_c() * other);
}

const ComplexVariable operator*(const complex<double> &d, const ComplexVariable &r)
{
    return ComplexVariable(r._a() * d, r._b() * d, r._c() * d);
}

//Operator(/)

const ComplexVariable ComplexVariable::operator/(const complex<double> &other) const
{
    if (other.real() == 0)
        throw runtime_error("can't divide by 0, \n Ya Melon");

    return ComplexVariable(this->_a() / other, this->_b() / other, this->c / other);
}

//operator(^)
const ComplexVariable ComplexVariable::operator^(const complex<double> &other) const
{
    if (other.real() < 0)
    throw runtime_error("Al mi ata ba");
    
    if (other.real() > 2)
        throw runtime_error("Al mi ata ba");

    if (other.real() == 1)
        return *this;

    if (other.real() == 0)
    {
        return ComplexVariable(0, 0, 1);
    }

    return ComplexVariable(1, 0, 0);
}
//Operator(==)

const ComplexVariable ComplexVariable::operator==(const ComplexVariable &other) const
{
    return ComplexVariable(this->a - other.a, this->b - other.b, this->c - other.c);
}

const ComplexVariable ComplexVariable::operator==(const complex<double> &other) const
{
    return ComplexVariable(this->a, this->b, this->c - other);
}

const ComplexVariable operator==(const complex<double> &d, const ComplexVariable &r)
{
    return ComplexVariable(r._a(), r._b(), r._c() - d);
}
} // namespace solver