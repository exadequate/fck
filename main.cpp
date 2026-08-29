#include <stdio.h>
#include <math.h>
#include "read_input.cpp"
#include "solve_square.cpp"
#include "unit_test.cpp"

int main()
{
    unit_test();
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    #define USER_INPUT(var) printf("print value of %s\n", #var); if (!read_coef(&var)) {printf("wrong input\n"); return 0;}
    USER_INPUT(a)
    USER_INPUT(b)
    USER_INPUT(c)
    enum num_of_roots nRoots = solve_square(a, b, c, &x1, &x2);
    switch (nRoots)
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
