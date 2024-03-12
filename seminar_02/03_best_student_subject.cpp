#include <stdio.h>

int main()
{
    int grades[3][3] = {
        {8, 10, 8},
        {7, 8, 9},
        {7, 10, 8}};

    // Find the best student
    int best_student = 0;
    double best_avg = 0.0;
    for (int i = 0; i < 3; i++)
    {
        double avg = 0.0;
        for (int j = 0; j < 3; j++)
        {
            avg += grades[i][j];
        }
        avg /= 3;
        if (avg > best_avg)
        {
            best_student = i;
            best_avg = avg;
        }
    }
    printf("Best student: %d: average: %.2f\n", best_student, best_avg);

    // Find the subject with the highest average
    int best_subject = 0;
    best_avg = 0.0;
    for (int j = 0; j < 3; j++)
    {
        double avg = 0.0;
        for (int i = 0; i < 3; i++)
        {
            avg += grades[i][j];
        }
        avg /= 3;
        if (avg > best_avg)
        {
            best_subject = j;
            best_avg = avg;
        }
    }

    printf("Subject with the highest average: %d: average: %.2f\n", best_subject, best_avg);

    printf("\nEnter any number to exit: ");
    scanf("%d");
    return 0;
}