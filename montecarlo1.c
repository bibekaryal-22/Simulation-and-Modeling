//Activity 1
//a. Calculate the value of pi using monte carlo method.
//b.Calculate the error percntage.
//c.repeat the experiment for at least five different value of input iteraitons and tabulate value ,experiments output and error percentage of each.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SEED 35791246

int main()
{
    int iterations[5] = {100, 1000, 10000, 100000, 1000000};
    int i, j;
    int circle_point, square_point;
    double x, y, d, pi, error;
    double true_pi = 3.141592653589793;

    srand(SEED);

    printf("Iterations\tTrue PI\t\tEstimated PI\tError(%%)\n");
    printf("---------------------------------------------------------------\n");

    for(i = 0; i < 5; i++)
    {
        circle_point = 0;
        square_point = 0;

        for(j = 0; j < iterations[i]; j++)
        {
            x = (double)rand() / RAND_MAX;
            y = (double)rand() / RAND_MAX;

            d = x * x + y * y;

            if(d <= 1)
                circle_point++;

            square_point++;
        }

        pi = 4.0 * circle_point / square_point;

        error = fabs((true_pi - pi) / true_pi) * 100;

        printf("%d\t\t%lf\t%lf\t%lf%%\n",
               iterations[i], true_pi, pi, error);
    }

    return 0;
}