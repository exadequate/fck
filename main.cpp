#include <stdio.h>
#include <math.h>
#include "EPS.cpp"
#include "read_input.cpp"
#include "printf.cpp"
#include "solve_square.cpp"
#include "unit_test.cpp"

int main()
{
    Unit_Test();
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    int nRoots = 0;
    #define USER_INPUT(var1) user_input(#var1); if (!read_coeffs(&var1)) {wrong_inp(); return 0;}
    USER_INPUT(a)
    USER_INPUT(b)
    USER_INPUT(c)
    int var = SolveSq(a, b, c, &x1, &x2, &nRoots);
    switch (var)
    {
    case Two_Roots:
        printf("first root: %lg\n", x1);
        printf("second root: %lg\n", x2);
        break;
    case Only_Root:
        printf("only root: %lg\n", x1);
        break;
    case No_Roots:
        printf("no roots\n");
        break;
    case Any_Roots:
        printf("any roots\n");
        break;
    default:
        printf("error: unexpected number of roots");
        break;
    }
    return 0;
}
