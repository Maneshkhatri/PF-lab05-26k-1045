#include <stdio.h>

int main()
{
    int department;
    int theory, practical, attendance;
    int minTheory, minPractical, minAttendance;
    int remainder;
    int passed, distinction;

    printf("UNIVERSITY EXAMINATION RESULT SYSTEM\n");

    printf("\nSelect Department:\n");
    printf("1. Computer Science\n");
    printf("2. Electrical Engineering\n");
    printf("3. Business Administration\n");
    printf("4. Mathematics\n");
    printf("Enter choice: ");
    scanf("%d", &department);

    printf("\nEnter Theory Marks: ");
    scanf("%d", &theory);

    printf("Enter Practical Marks: ");
    scanf("%d", &practical);

    printf("Enter Attendance Percentage: ");
    scanf("%d", &attendance);

    switch(department)
    {
        case 1:
            minTheory = 50;
            minPractical = 40;
            minAttendance = 75;
            break;

        case 2:
            minTheory = 55;
            minPractical = 45;
            minAttendance = 75;
            break;

        case 3:
            minTheory = 50;
            minPractical = 35;
            minAttendance = 80;
            break;

        case 4:
            minTheory = 60;
            minPractical = 40;
            minAttendance = 75;
            break;

        default:
            printf("Invalid department.\n");
            return 0;
    }

    passed = (theory >= minTheory &&
              practical >= minPractical &&
              attendance >= minAttendance);

    distinction = (theory >= 85 &&
                   practical >= 80 &&
                   attendance >= 90);

    remainder = theory % 3;

    printf("\n\n--- FINAL REPORT ---\n");

    printf("Department: ");

    switch(department)
    {
        case 1:
            printf("Computer Science\n");
            break;

        case 2:
            printf("Electrical Engineering\n");
            break;

        case 3:
            printf("Business Administration\n");
            break;

        case 4:
            printf("Mathematics\n");
            break;
    }

    printf("Theory Marks: %d\n", theory);
    printf("Practical Marks: %d\n", practical);
    printf("Attendance: %d%%\n", attendance);

    printf("\nPassing Requirements:\n");
    printf("Theory: %d\n", minTheory);
    printf("Practical: %d\n", minPractical);
    printf("Attendance: %d%%\n", minAttendance);

    printf("\nDistinction: %s\n",
           distinction ? "Eligible" : "Not Eligible");

    if(remainder == 0)
        printf("Seat Category: A\n");
    else if(remainder == 1)
        printf("Seat Category: B\n");
    else
        printf("Seat Category: C\n");

    printf("Final Result: %s\n",
           passed ? "PASSED" : "FAILED");

    return 0;
}