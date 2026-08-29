int equal0(double var);

int equal0(double var)
{
   const double EPS = 1e-12;
   return fabs(var) <= EPS;
}

enum num_of_roots
{
    No_Roots,
    Only_Root,
    Two_Roots,
    Any_Roots,
};
enum num_of_roots solve_trivial(double C);
enum num_of_roots solve_linear(double B, double C, double* X1);
enum num_of_roots solve_square(double A, double B, double C, double* X1, double* X2);

enum num_of_roots solve_trivial(double C)
{
    if (equal0(C))
    {
        return Any_Roots;
    }
    else
    {
        return No_Roots;
    }
}
enum num_of_roots solve_linear(double B, double C, double* X1)
{

    if (equal0(B))
    {
        return solve_trivial(C);
    }
    else
    {
        *X1 = -C / B;
        return Only_Root;
    }
}
enum num_of_roots solve_square(double A, double B, double C, double* X1, double* X2)
{
    if (equal0(A))
    {
        return solve_linear(B, C, X1);
    }
    double D = B * B - 4 * A * C;
    if (equal0(D))
    {
        *X1 = -B / 2 / A;
        return Only_Root;
    }
    else if (D < 0)
    {
        return No_Roots;
    }
    *X1 = (-B + sqrt(D)) / 2 / A;
    *X2 = (-B - sqrt(D)) / 2 / A;
    return Two_Roots;
}
