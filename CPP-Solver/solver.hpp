#include <complex>
#include <cmath>

using namespace std;

namespace solver
{

class RealVariable
{
    double a;
    double b;
    double c;

public:
    RealVariable(const double &_a = 0.0, const double &_b = 1.0, const double &_c = 0.0) : a(_a), b(_b), c(_c){};

    // getters
    double _a() const
    {
        return a;
    }

    double _b() const
    {
        return b;
    }
    double _c() const
    {
        return c;
    }

    //Operator(+)
    const RealVariable operator+(const RealVariable &other) const;
    const RealVariable operator+(const double &other) const;
    friend const RealVariable operator+(const double &d, const RealVariable &r);
    //Operator(-)
    const RealVariable operator-(const RealVariable &other) const;
    const RealVariable operator-(const double &other) const;
    friend const RealVariable operator-(const double &d, const RealVariable &r);

    //Operator(*)
    const RealVariable operator*(const RealVariable &other) const;
    const RealVariable operator*(const double &other) const;
    friend const RealVariable operator*(const double &d, const RealVariable &r);

    //Operator(/)
    const RealVariable operator/(const double &other) const;

    //Operator(^)
    const RealVariable operator^(const double &other) const;

    //Operator(==)
    const RealVariable operator==(const RealVariable &other) const;
    const RealVariable operator==(const double &other) const;
    friend const RealVariable operator==(const double &d, const RealVariable &r);
};

class ComplexVariable
{

complex<double> a;
complex<double> b;
complex<double> c;
public:
    ComplexVariable(const complex<double> &_a = 0.0, const complex<double> &_b = 1.0, const complex<double> &_c = 0.0) : a(_a), b(_b), c(_c){};

    // getters
    complex<double> _a() const
    {
        return a;
    }

    complex<double> _b() const
    {
        return b;
    }
    complex<double> _c() const
    {
        return c;
    }

    //Operator(+)
    const ComplexVariable operator+(const ComplexVariable &other) const;
    const ComplexVariable operator+(const complex<double> &other) const;
    friend const ComplexVariable operator+(const complex<double> &d, const ComplexVariable &r);
    //Operator(-)
    const ComplexVariable operator-(const ComplexVariable &other) const;
    const ComplexVariable operator-(const complex<double> &other) const;
    friend const ComplexVariable operator-(const complex<double> &d, const ComplexVariable &r);

    //Operator(*)
    const ComplexVariable operator*(const ComplexVariable &other) const;
    const ComplexVariable operator*(const complex<double> &other) const;
    friend const ComplexVariable operator*(const complex<double> &d, const ComplexVariable &r);

    //Operator(/)
    const ComplexVariable operator/(const complex<double> &other) const;

    //Operator(^)
    const ComplexVariable operator^(const complex<double> &other) const;

    //Operator(==)
    const ComplexVariable operator==(const ComplexVariable &other) const;
    const ComplexVariable operator==(const complex<double> &other) const;
    friend const ComplexVariable operator==(const complex<double> &d, const ComplexVariable &r);
};

 double solve( const RealVariable &x);
 complex<double> solve(const ComplexVariable &bi);

} // namespace solver