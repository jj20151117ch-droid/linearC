#include <stdio.h>
#include <math.h>


#define EPSILON 1e-9

int main(void)
{

    double A[3][2] = {
        {2.0, 1.0},
        {2.0, -1.0},
        {1.0, -2.0}
    };

    double b[3] = { 3.0, 1.0, -1.0 };

    double determinant;
    double x1 = 0.0;
    double x2 = 0.0;
    int commonSolution = 1;

    determinant = A[0][0] * A[1][1] - A[0][1] * A[1][0];

    if (fabs(determinant) < EPSILON) {
        printf("\n세 방정식은 공통해를 가집니다.\n");
        printf("공통해: (x1, x2) = (%.0f, %.0f)\n", x1, x2);
        return 1;
    }

    x1 = (b[0] * A[1][1] - b[1] * A[0][1]) / determinant;
    x2 = (A[0][0] * b[1] - A[1][0] * b[0]) / determinant;

    printf("계산된 해\n");
    printf("x1 = %.6f\n", x1);
    printf("x2 = %.6f\n\n", x2);

    for (int i = 0; i < 3; i++) {
        double leftSide = A[i][0] * x1 + A[i][1] * x2;
        double error = leftSide - b[i];

        printf(
            "%d번 방정식: 좌변 = %.6f, 우변 = %.6f\n",
            i + 1,
            leftSide,
            b[i]
        );

        if (fabs(error) > EPSILON) {
            commonSolution = 0;
        }
    }

    if (commonSolution) {
        printf("\n세 방정식은 공통해를 가집니다.\n");
        printf("공통해: (x1, x2) = (%.0f, %.0f)\n", x1, x2);
    }
    else {
        printf("\n세 방정식을 만족하는 공통해를 가지지 않습니다.\n");
    }

    return 0;
}