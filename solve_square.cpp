enum num_of_roots
{
    Two_Roots,
    Only_Root,
    No_Roots,
    Any_Roots
};
enum num_of_roots trivial_equation(double C, int* nRoots);
enum num_of_roots linear_roots(double B, double C, double* X1, int* nRoots);
enum num_of_roots SolveSq(double A, double B, double C, double* X1, double* X2, int* nRoots);

enum num_of_roots trivial_equation(double C, int* nRoots)
{
    if (equal0(C))
    {
        *nRoots = 3;
        return Any_Roots;
    }
    else
    {
        *nRoots = 0;
        return No_Roots;
    }
}
enum num_of_roots linear_roots(double B, double C, double* X1, int* nRoots)
{

    if (equal0(B))
    {
        return trivial_equation(C, nRoots);
    }
    else
    {
        *X1 = -C / B;
        *nRoots = 1;
        return Only_Root;
    }
}
enum num_of_roots SolveSq(double A, double B, double C, double* X1, double* X2, int* nRoots)
{
    if (equal0(A))
    {
        return linear_roots(B, C, X1, nRoots);
    }
    double D = B * B - 4 * A * C;
    if (equal0(D))
    {
        *X1 = -B / 2 / A;
        *nRoots = 1;
        return Only_Root;
    }
    else if (D < 0)
    {
        nRoots = 0;
        return No_Roots;
    }
    *X1 = (-B + sqrt(D)) / 2 / A;
    *X2 = (-B - sqrt(D)) / 2 / A;
    *nRoots = 2;
    return Two_Roots;
}
