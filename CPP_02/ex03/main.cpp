
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const p);

void testPoint(const char *label, Point const &A, Point const &B, Point const &C, Point const &P)
{
    std::cout << label << "  P(" 
              << P.getX().toFloat() << ", " 
              << P.getY().toFloat() << ")  → ";

    if (!(bsp(A, B, C, P))) 
    {
        std::cout << "Fora do triângulo\n";
        return;
    }
    std::cout << "Dentro do triângulo\n";
}

int main()
{
    // Triângulo ABC fixo
    Point A(0, 0);
    Point B(10, 0);
    Point C(4, 8);

    std::cout << "=== Testes BSP ===\n\n";
    std::cout << "Triângulo ABC:\n";
    std::cout << "A(0,0), B(10,0), C(4,8)\n\n";

    // ---- Testes dentro ----
    testPoint("Dentro 1:", A, B, C, Point(4, 3));
    testPoint("Dentro 2:", A, B, C, Point(5, 2));
    testPoint("Dentro 3:", A, B, C, Point(3, 4));

    // ---- Testes na borda ----
    std::cout << "\n-- Testes na borda (devem dar 'fora') --\n";
    testPoint("Borda 1:", A, B, C, Point(5, 0));  // em cima de AB
    testPoint("Borda 2:", A, B, C, Point(2, 4));  // em AC
    testPoint("Borda 3:", A, B, C, Point(7, 4));  // em BC
    testPoint("Vertice A:", A, B, C, Point(0, 0));
    testPoint("Vertice B:", A, B, C, Point(10, 0));
    testPoint("Vertice C:", A, B, C, Point(4, 8));

    // ---- Testes fora ----
    std::cout << "\n-- Testes fora --\n";
    testPoint("Fora 1:", A, B, C, Point(-1, 1));
    testPoint("Fora 2:", A, B, C, Point(12, 2));
    testPoint("Fora 3:", A, B, C, Point(4, 10));
    testPoint("Fora 4:", A, B, C, Point(7, -1));
    testPoint("Fora 5:", A, B, C, Point(20, 20));

    return 0;
}
