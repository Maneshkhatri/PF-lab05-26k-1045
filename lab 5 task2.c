#include <stdio.h>

int main()
{
    int department;
    int age, heartRate, temperature;
    int consciousness, severity;
    int departmentPriority = 0;
    int critical;
    int tempAlert;
    int senior;
    int remainder;
    char caseCategory;

    printf("Enter Emergency Department:\n");
    printf("1. General Emergency\n");
    printf("2. Cardiology\n");
    printf("3. Neurology\n");
    printf("4. Trauma\n");
    scanf("%d", &department);

    printf("Enter Patient Age: ");
    scanf("%d", &age);

    printf("Enter Heart Rate: ");
    scanf("%d", &heartRate);

    printf("Enter Body Temperature: ");
    scanf("%d", &temperature);

    printf("Is Patient Conscious? (1 Yes, 0 No): ");
    scanf("%d", &consciousness);

    printf("Enter Severity Level (1-High, 0-Low): ");
    scanf("%d", &severity);

    switch (department)
    {
    case 1:
        printf("\nDepartment: General Emergency\n");

        switch (severity)
        {
        case 1:
            departmentPriority = 1;
            break;

        case 0:
            departmentPriority = 0;
            break;

        default:
            printf("Invalid Severity\n");
        }
        break;

    case 2:
        printf("\nDepartment: Cardiology\n");

        switch (heartRate > 120 || heartRate < 50)
        {
        case 1:
            departmentPriority = 1;
            break;

        case 0:
            departmentPriority = 0;
            break;
        }
        break;

    case 3:
        printf("\nDepartment: Neurology\n");

        switch (consciousness)
        {
        case 0:
            departmentPriority = 1;
            break;

        case 1:
            departmentPriority = 0;
            break;
        }
        break;

    case 4:
        printf("\nDepartment: Trauma\n");

        switch (severity)
        {
        case 1:
            departmentPriority = 1;
            break;

        case 0:
            departmentPriority = 0;
            break;
        }
        break;

    default:
        printf("Invalid Department");
        return 0;
    }

    critical = ((heartRate < 50 || heartRate > 120) && consciousness == 0);

    tempAlert = (temperature < 36 || temperature > 38);

    senior = (age >= 65);

    remainder = (age + heartRate) % 4;

    caseCategory = (remainder == 0) ? 'A' : (remainder == 1) ? 'B'
                                        : (remainder == 2)   ? 'C'
                                                             : 'D';

    printf("\n----- Patient Details -----\n");

    printf("Age: %d\n", age);
    printf("Heart Rate: %d\n", heartRate);
    printf("Temperature: %d\n", temperature);

    if (critical)
    {
        printf("Critical Condition: Yes\n");
        printf("Final Decision: Immediate Medical Attention\n");
    }
    else if (departmentPriority || senior || tempAlert)
    {
        printf("Critical Condition: No\n");
        printf("Final Decision: Priority Assessment Required\n");
    }
    else
    {
        printf("Critical Condition: No\n");
        printf("Final Decision: Routine Medical Assessment\n");
    }

    printf("Senior Priority: ");

    if (senior)
        printf("Yes\n");
    else
        printf("No\n");

    printf("Temperature Alert: ");

    if (tempAlert)
        printf("Yes\n");
    else
        printf("No\n");

    printf("Department Priority: ");

    if (departmentPriority)
        printf("Yes\n");
    else
        printf("No\n");

    printf("Case Category: %c\n", caseCategory);

    return 0;
}