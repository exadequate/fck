void unit_test();

void unit_test()
{
    double ArrA[10] =                 {    1,        1,         1,         0,         5,        0,         5,        0,        0,          2    };
    double ArrB[10] =                 {    5,        2,         2,         0,         0,        5,         4,        0,        5,          0    };
    double ArrC[10] =                 {    6,        3,         1,         0,         1,        3,         0,        9,        0,          0    };
    double ArrX1[10] =                {   -2,        0,        -1,         0,         0,      -0.6,        0,        0,       -0,         -0    };
    double ArrX2[10] =                {   -3,        0,         0,         0,         0,        0,       -0.8,       0,        0,          0    };
    enum num_of_roots ArrNroots[10] = {Two_Roots, No_Roots, Only_Root, Any_Roots, No_Roots, Only_Root, Two_Roots, No_Roots, Only_Root, Only_Root};
    int nFails = 0;
    for (int i = 0; i < 10; i++)
    {
        double X1ref = 0, X2ref = 0;
        enum num_of_roots nRoots = solve_square(ArrA[i], ArrB[i], ArrC[i], &X1ref, &X2ref);
        if (!equal0(ArrX1[i] - X1ref) || !equal0(ArrX2[i] - X2ref)  || ArrNroots[i] != nRoots)
        {
            printf("test %d failed\n", i);
            printf("x1 expected: %lg\tx1 actual: %lg\nx2 expected: %lg\tx2 actual: %lg\n", ArrX1[i], X1ref, ArrX2[i], X2ref);
            printf("nRoots expected: %d\tnRoots actual: %d  (3 means infinity)\n", ArrNroots[i], nRoots);
            nFails++;
        }
    }
    if (nFails == 0)
    {
        printf("test passed\n");
    }
}
