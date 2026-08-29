int equal0(double var);

int equal0(double var)
{
   const double EPS = 1e-12;
   return fabs(var) <= EPS;
}
