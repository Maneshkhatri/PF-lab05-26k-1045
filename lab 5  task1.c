#include <stdio.h>

int main()
{
    int category, destination;
    int age, baggage, allowance;
    int documents;
    int priority;
    int remainder;
    char verification;

    printf("Enter Passenger Category:\n");
    printf("1. Adult\n");
    printf("2. Student\n");
    printf("3. Senior Citizen\n");
    scanf("%d", &category);

    printf("Enter Destination Type:\n");
    printf("1. Domestic\n");
    printf("2. International\n");
    scanf("%d", &destination);

    printf("Enter Age: ");
    scanf("%d", &age);

    printf("Enter Baggage Weight: ");
    scanf("%d", &baggage);

    printf("Are documents valid? (1 for Yes, 0 for No): ");
    scanf("%d", &documents);

    switch (category)
    {
    case 1:
        printf("Passenger Category: Adult\n");

        switch (destination)
        {
        case 1:
            printf("Destination: Domestic\n");
            allowance = 20;
            break;

        case 2:
            printf("Destination: International\n");
            allowance = 30;
            break;

        default:
            printf("Invalid Destination");
            return 0;
        }
        break;

    case 2:
        printf("Passenger Category: Student\n");

        switch (destination)
        {
        case 1:
            printf("Destination: Domestic\n");
            allowance = 25;
            break;

        case 2:
            printf("Destination: International\n");
            allowance = 35;
            break;

        default:
            printf("Invalid Destination");
            return 0;
        }
        break;

    case 3:
        printf("Passenger Category: Senior Citizen\n");

        switch (destination)
        {
        case 1:
            printf("Destination: Domestic\n");
            allowance = 30;
            break;

        case 2:
            printf("Destination: International\n");
            allowance = 40;
            break;

        default:
            printf("Invalid Destination");
            return 0;
        }
        break;

    default:
        printf("Invalid Category");
        return 0;
    }

    printf("Allowed Baggage: %d kg\n", allowance);
    printf("Actual Baggage: %d kg\n", baggage);

    if (documents == 0)
    {
        printf("Final Decision: Denied Boarding\n");
    }
    else if (baggage <= allowance)
    {
        printf("Final Decision: Normal Boarding\n");
    }
    else
    {
        printf("Final Decision: Enhanced Baggage Screening\n");
    }

    remainder = age % 5;

    verification = (remainder == 0) ? 'A' : (remainder == 1) ? 'B'
                                        : (remainder == 2)   ? 'C'
                                        : (remainder == 3)   ? 'D'
                                                             : 'E';

    printf("Verification Category: %c\n", verification);

    priority = (category == 3 || (category == 2 && destination == 2));

    if (priority == 1)
        printf("Priority Assistance: Available\n");
    else
        printf("Priority Assistance: Not Available\n");

    return 0;
}
