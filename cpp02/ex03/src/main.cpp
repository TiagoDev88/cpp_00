#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const p);

static void testPoint(const char *label, Point const &A, Point const &B, Point const &C, Point const &P)
{
    std::cout << label << "  P("
              << P.getX().toFloat() << ", "
              << P.getY().toFloat() << ")  → ";

    if (!(bsp(A, B, C, P)))
    {
        std::cout << "Outside the triangle\n";
        return;
    }
    std::cout << "Inside the triangle\n";
}

int main()
{
    // Fixed Triangle ABC
    const Point A(0, 0);
    const Point B(10, 0);
    const Point C(4, 8);

    std::cout << "=== BSP Tests ===\n\n";
    std::cout << "Triangle ABC:\n";
    std::cout << "A(0,0), B(10,0), C(4,8)\n\n";

    // ---- Inside tests ----
    std::cout << "-- Inside tests --\n";
    testPoint("Inside 1:", A, B, C, Point(4, 3));
    testPoint("Inside 2:", A, B, C, Point(5, 2));
    testPoint("Inside 3:", A, B, C, Point(3, 4));
    testPoint("Inside 4:", A, B, C, Point(4, 1));
    testPoint("Inside 5:", A, B, C, Point(3, 2));
    testPoint("Inside 6:", A, B, C, Point(6, 3));
    testPoint("Inside 7:", A, B, C, Point(4, 4));
    testPoint("Inside 8:", A, B, C, Point(5, 3.5f));

    // ---- Edge tests ----
    std::cout << "\n-- Edge tests (should be 'outside') --\n";
    testPoint("Edge 1:", A, B, C, Point(5, 0));
    testPoint("Edge 2:", A, B, C, Point(2, 4));
    testPoint("Edge 3:", A, B, C, Point(7, 4));
    testPoint("Edge 4 (AB):", A, B, C, Point(2, 0));
    testPoint("Edge 5 (AC):", A, B, C, Point(3, 6));
    testPoint("Edge 6 (BC):", A, B, C, Point(5, 6.667f));
    testPoint("Edge-mid A→B:", A, B, C, Point(1, 0));
    testPoint("Edge-mid A→C:", A, B, C, Point(2, 4));
    testPoint("Edge-mid B→C:", A, B, C, Point(7, 4));
    testPoint("Vertice A:", A, B, C, Point(0, 0));
    testPoint("Vertice B:", A, B, C, Point(10, 0));
    testPoint("Vertice C:", A, B, C, Point(4, 8));

    // ---- Outside tests ----
    std::cout << "\n-- Outside tests --\n";
    testPoint("Outside 1:", A, B, C, Point(-1, 1));
    testPoint("Outside 2:", A, B, C, Point(12, 2));
    testPoint("Outside 3:", A, B, C, Point(4, 10));
    testPoint("Outside 4:", A, B, C, Point(7, -1));
    testPoint("Outside 5:", A, B, C, Point(20, 20));

    // ---- Far Outside tests ----
    std::cout << "\n-- Far Outside tests --\n";
    testPoint("Far Out 1:", A, B, C, Point(-10, -10));
    testPoint("Far Out 2:", A, B, C, Point(30, 30));
    testPoint("Far Out 3:", A, B, C, Point(10, 20));
    testPoint("Far Out 4:", A, B, C, Point(-5, 15));

    // ---- Near Edge (small offset) ----
    std::cout << "\n-- Near Edge (tiny offset) --\n";
    testPoint("Near AB 1:", A, B, C, Point(5, 0.000f)); // inside
    testPoint("Near AC 1:", A, B, C, Point(2, 4.000f)); // inside
    testPoint("Near BC 1:", A, B, C, Point(7, 4.005f)); //outside

    // ---- Precision tests ----
    std::cout << "\n-- Precision tests --\n";
    testPoint("Precision 1:", A, B, C, Point(4.0001f, 3.0001f)); // inside
    testPoint("Precision 2:", A, B, C, Point(3.9999f, 3.9999f)); // inside
    testPoint("Precision 3:", A, B, C, Point(4.0001f, 4.0001f)); // inside
    testPoint("Precision 4 (outside):", A, B, C, Point(6.0f, 5.334f));  // outside

    return 0;
}
