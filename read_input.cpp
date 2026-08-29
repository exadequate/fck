int read_coef(double* var);

int read_coef(double* var)
{
    int ret_val = 0;
    ret_val = scanf("%lg", var);
    if (ret_val == 0)
    {
        return 0;
    }
    return 1;
}
