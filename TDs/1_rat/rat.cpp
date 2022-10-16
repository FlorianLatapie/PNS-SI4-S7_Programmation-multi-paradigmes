// surcharger les opérateurs >> et << pour la classe rat
#include <iostream>
#include <algorithm>
#include <numeric>
class Rat
{
    int num;
    int den;

public:
    Rat(int n1 = 0, int d1 = 1)
    {
        if (d1 == 0)
        {
           throw std::invalid_argument("denominator cannot be zero");
        }
        num = n1;
        den = d1;
        simplify();
    }

    void simplify()
    {
        int gcd = std::gcd(num, den);

        num = num / gcd;
        den = den / gcd;
    }

    friend std::ostream &operator<<(std::ostream &os, Rat rat);

    friend std::istream &operator>>(std::istream &is, Rat &rat);

    Rat operator+(const Rat &r);
    Rat operator-(const Rat &r);
    Rat operator++(int i);
    Rat operator--(int i);
    Rat operator*(const Rat &r);
    Rat operator/(const Rat &r);

    Rat opposite();
    Rat inverse();

    bool operator==(const Rat &r);
    bool operator!=(const Rat &r);
    bool operator<(const Rat &r);
    bool operator>(const Rat &r);
    bool operator<=(const Rat &r);
    bool operator>=(const Rat &r);
};

std::ostream &operator<<(std::ostream &os, Rat rat)
{
    return os << rat.num << "/" << rat.den;
}

std::istream &operator>>(std::istream &is, Rat &rat)
{
    is >> rat.num >> rat.den;
    rat.simplify();
    return is;
}

Rat Rat::operator+(const Rat &r)
{
    Rat result;
    result.num = num * r.den + den * r.num;
    result.den = den * r.den;
    result.simplify();
    return result;
}

Rat Rat::operator-(const Rat &r)
{
    Rat result;
    result.num = num * r.den - den * r.num;
    result.den = den * r.den;
    result.simplify();
    return result;
}

Rat Rat::operator++(int i)
{
    num += den;
    simplify();
    return *this;
}

Rat Rat::operator--(int i)
{
    num -= den;
    simplify();
    return *this;
}

Rat Rat::operator*(const Rat &r)
{
    Rat result;
    result.num = num * r.num;
    result.den = den * r.den;
    result.simplify();
    return result;
}

Rat Rat::operator/(const Rat &r)
{
    Rat result;
    result.num = num * r.den;
    result.den = den * r.num;
    result.simplify();
    return result;
}

Rat Rat::opposite()
{
    Rat result;
    result.num = -num;
    result.den = den;
    result.simplify();
    return result;
}

Rat Rat::inverse()
{
    Rat result;
    result.num = den;
    result.den = num;
    result.simplify();
    return result;
}

bool Rat::operator==(const Rat &r)
{
    return num == r.num && den == r.den;
}

bool Rat::operator!=(const Rat &r)
{
    return num != r.num || den != r.den;
}

bool Rat::operator<(const Rat &r)
{
    return num * r.den < den * r.num;
}

bool Rat::operator>(const Rat &r)
{
    return num * r.den > den * r.num;
}

bool Rat::operator<=(const Rat &r)
{
    return num * r.den <= den * r.num;
}

bool Rat::operator>=(const Rat &r)
{
    return num * r.den >= den * r.num;
}

int main()
{
    Rat r1;
    std::cout << "r1 = " << r1 << std::endl;

    Rat r2 = Rat(10);
    std::cout << "r2 = " << r2 << std::endl;

    Rat r3 = Rat(10, 20);
    std::cout << "r3 = " << r3 << std::endl;

    Rat r4;
    std::cin >> r4;
    std::cout << "r4 = " << r4 << std::endl;

    Rat r5 = Rat(1, 2);
    Rat r6 = Rat(1, 3);
    Rat r7 = r5 + r6;
    std::cout << "r7 (1/2 + 1/3) = " << r7 << std::endl;

    Rat r8 = r5 - r6;
    std::cout << "r8 (1/2 - 1/3) = " << r8 << std::endl;

    Rat r9 = Rat(2, 3) * Rat(3, 4);
    std::cout << "r9 (2/3 * 3/4) = " << r9 << std::endl;

    Rat r10 = Rat(2, 3) / Rat(3, 4);
    std::cout << "r10 (2/3 / 3/4) = " << r10 << std::endl;

    Rat r11 = Rat(1, 1);
    r11++;
    std::cout << "r11 = " << r11 << std::endl;

    Rat r12 = Rat(1, 1);
    r12--;
    std::cout << "r12 = " << r12 << std::endl;

    Rat r13 = Rat(1, 2);
    std::cout << "r13 = " << r13 << std::endl;
    std::cout << "r13.opposite() = " << r13.opposite() << std::endl;

    Rat r14 = Rat(1, 2);
    std::cout << "r14 = " << r14 << std::endl;
    std::cout << "r14.inverse() = " << r14.inverse() << std::endl;

    Rat r15 = Rat(1, 2);
    Rat r16 = Rat(1, 2);
    std::cout << "r15==r16 = " << (r15 == r16) << std::endl;
    std::cout << "r15!=r16 = " << (r15 != r16) << std::endl;

    Rat r17 = Rat(1, 2);
    Rat r18 = Rat(1, 3);
    std::cout << "r17<r18 = " << (r17 < r18) << std::endl;
    std::cout << "r17>r18 = " << (r17 > r18) << std::endl;

    Rat r19 = Rat(1, 2);
    Rat r20 = Rat(1, 3);
    std::cout << "r19<=r20 = " << (r19 <= r20) << std::endl;
    std::cout << "r19>=r20 = " << (r19 >= r20) << std::endl;

    Rat r21 = Rat(0,0);
    std::cout << "r21 = " << r21 << std::endl;

    return 0;
}