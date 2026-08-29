int equal0(double var);

const double EPS = 1e-12;

int equal0(double var)
{
   return fabs(var) <= EPS;
}
