#include <iostream>
#include <limits>
#include <cmath>
#include "Fixed.hpp"

void print_header(const char* s) {
    std::cout << "\n=== " << s << " ===\n";
}

int main() {
    print_header("CONSTRUCTORS");
    Fixed a;                          // default
    Fixed b(10);                      // from int
    Fixed c(42.42f);                  // from float
    Fixed d(b);                       // copy ctor
    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
    std::cout << "c: " << c << "\n";
    std::cout << "d: " << d << "\n";

    print_header("ASSIGNMENT / COPY");
    Fixed e;
    e = c;
    std::cout << "e (assigned from c): " << e << "\n";

    print_header("TO_INT / TO_FLOAT");
    std::cout << "b.toInt(): " << b.toInt() << " expected 10\n";
    std::cout << "c.toInt(): " << c.toInt() << " expected 42\n";
    std::cout << "c.toFloat(): " << c.toFloat() << " approx 42.4219\n";

    print_header("COMPARISONS");
    std::cout << std::boolalpha;
    std::cout << "b > c: " << (b > c) << "\n";
    std::cout << "b < c: " << (b < c) << "\n";
    std::cout << "b >= d: " << (b >= d) << "\n";
    std::cout << "b == d: " << (b == d) << "\n";
    std::cout << "c != d: " << (c != d) << "\n";

    print_header("ARITHMETIC BASIC");
    Fixed x(5.05f);
    Fixed y(2);
    std::cout << "x = " << x << ", y = " << y << "\n";
    std::cout << "x + y = " << (x + y) << "\n";
    std::cout << "x - y = " << (x - y) << "\n";
    std::cout << "x * y = " << (x * y) << "\n";
    std::cout << "x / y = " << (x / y) << "\n";

    print_header("INCREMENT / DECREMENT");
    Fixed inc;
    std::cout << "inc = " << inc << "\n";
    std::cout << "++inc = " << ++inc << "\n";
    std::cout << "inc++ = " << inc++ << "\n";
    std::cout << "inc after = " << inc << "\n";
    std::cout << "--inc = " << --inc << "\n";
    std::cout << "inc-- = " << inc-- << "\n";
    std::cout << "inc final = " << inc << "\n";

    print_header("MIN / MAX");
    std::cout << "min(x,y) = " << Fixed::min(x, y) << "\n";
    std::cout << "max(x,y) = " << Fixed::max(x, y) << "\n";

    print_header("OVERFLOW / EDGE CASES");

    // 1) Large ints: building from large int may overflow internally (value << fracBits)
    long big_int = std::numeric_limits<int>::max() >> 4; // somewhat large but avoid immediate shift overflow
    Fixed bigA(static_cast<int>(big_int));
    std::cout << "bigA from int " << big_int << " => " << bigA << " (raw: " << bigA.getRawBits() << ")\n";

    // 2) Construct from very large float (could overflow)
    float huge = 1e8f; // large float
    Fixed bigF(huge);
    std::cout << "bigF from float " << huge << " => " << bigF << " (raw: " << bigF.getRawBits() << ")\n";

    // 3) Multiply large values to try to overflow 32-bit raw if not using 64-bit intermediate
    Fixed f1(10000); // 10000 << fracBits -> large raw
    Fixed f2(10000);
    // expected: if multiplication uses 64-bit intermediate, no undefined behaviour; else overflow
    Fixed prod = f1 * f2;
    std::cout << "prod f1*f2 = " << prod << " (raw: " << prod.getRawBits() << ")\n";

    // 4) Division by a small fixed; check precision
    Fixed divres = f1 / Fixed(3);
    std::cout << "f1 / 3 = " << divres << "\n";

    // 5) Check copy ctor doesn't print twice (sanity check)
    Fixed copied = f1;
    std::cout << "copied = " << copied << "\n";

    // 6) Check self-assignment safe
    f1 = f1;
    std::cout << "f1 after self-assign = " << f1 << "\n";

    print_header("RANDOMIZED SIMPLE CHECK (float vs fixed approx)");

    // random-ish checks: compare fixed arithmetic with double arithmetic (tolerance)
    double a_d = 1234.75;
    double b_d = 12.125;
    Fixed A(static_cast<float>(a_d));
    Fixed B(static_cast<float>(b_d));
    Fixed R = A * B;
    double expected = a_d * b_d;
    double approx = R.toFloat();
    std::cout << "A * B (fixed) = " << approx << " expected(double) = " << expected
              << " diff = " << fabs(approx - expected) << "\n";

    return 0;
}
