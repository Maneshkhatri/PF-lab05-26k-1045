#include <stdio.h>

int main()
{
    int product, customer, orderNumber;
    int distance;
    float orderAmount;
    float discountRate, discountAmount, finalAmount;
    float deliveryCharges, priorityCharges, totalAmount;
    int remainder;

    printf("E-COMMERCE ORDER PROCESSING SYSTEM\n");

    printf("\nSelect Product Category:\n");
    printf("1. Electronics\n");
    printf("2. Clothing\n");
    printf("3. Books\n");
    printf("4. Household\n");
    printf("Enter choice: ");
    scanf("%d", &product);

    printf("\nSelect Customer Category:\n");
    printf("1. Regular\n");
    printf("2. Premium\n");
    printf("3. Corporate\n");
    printf("Enter choice: ");
    scanf("%d", &customer);

    printf("\nEnter Order Amount: ");
    scanf("%f", &orderAmount);

    printf("Enter Delivery Distance (km): ");
    scanf("%d", &distance);

    printf("Enter Order Number: ");
    scanf("%d", &orderNumber);

    /*
       Main switch for product
       Nested switch for customer
    */

    switch(product)
    {
        case 1:
            switch(customer)
            {
                case 1:
                    discountRate = 5;
                    break;

                case 2:
                    discountRate = 10;
                    break;

                case 3:
                    discountRate = 15;
                    break;

                default:
                    printf("Invalid customer category.\n");
                    return 0;
            }
            break;

        case 2:
            switch(customer)
            {
                case 1:
                    discountRate = 10;
                    break;

                case 2:
                    discountRate = 15;
                    break;

                case 3:
                    discountRate = 20;
                    break;

                default:
                    printf("Invalid customer category.\n");
                    return 0;
            }
            break;

        case 3:
            switch(customer)
            {
                case 1:
                    discountRate = 8;
                    break;

                case 2:
                    discountRate = 12;
                    break;

                case 3:
                    discountRate = 18;
                    break;

                default:
                    printf("Invalid customer category.\n");
                    return 0;
            }
            break;

        case 4:
            switch(customer)
            {
                case 1:
                    discountRate = 7;
                    break;

                case 2:
                    discountRate = 14;
                    break;

                case 3:
                    discountRate = 20;
                    break;

                default:
                    printf("Invalid customer category.\n");
                    return 0;
            }
            break;

        default:
            printf("Invalid product category.\n");
            return 0;
    }

    discountAmount = orderAmount * discountRate / 100;
    finalAmount = orderAmount - discountAmount;

    /*
       Free shipping if final amount >= 5000
       OR customer is Premium/Corporate
    */

    if(finalAmount >= 5000 || customer == 2 || customer == 3)
    {
        deliveryCharges = 0;
    }
    else
    {
        if(distance <= 10)
            deliveryCharges = 200;
        else if(distance <= 20)
            deliveryCharges = 400;
        else
            deliveryCharges = 600;
    }

    /*
       Priority delivery:
       Premium or Corporate AND order amount >= 10000
    */

    if((customer == 2 || customer == 3) && orderAmount >= 10000)
    {
        priorityCharges = 500;
    }
    else
    {
        priorityCharges = 0;
    }

    /*
       Processing group using modulus
    */

    remainder = orderNumber % 4;

    totalAmount = finalAmount + deliveryCharges + priorityCharges;

    printf("\n\n--- FINAL ORDER REPORT ---\n");

    printf("Product Category: ");

    switch(product)
    {
        case 1:
            printf("Electronics\n");
            break;

        case 2:
            printf("Clothing\n");
            break;

        case 3:
            printf("Books\n");
            break;

        case 4:
            printf("Household\n");
            break;
    }

    printf("Customer Category: ");

    switch(customer)
    {
        case 1:
            printf("Regular\n");
            break;

        case 2:
            printf("Premium\n");
            break;

        case 3:
            printf("Corporate\n");
            break;
    }

    printf("Original Order Amount: Rs. %.2f\n", orderAmount);
    printf("Discount Percentage: %.0f%%\n", discountRate);
    printf("Discount Amount: Rs. %.2f\n", discountAmount);
    printf("Final Payable Amount: Rs. %.2f\n", finalAmount);
    printf("Delivery Distance: %d km\n", distance);

    printf("Shipping Status: %s\n",
           (deliveryCharges == 0) ? "FREE SHIPPING" : "CHARGED");

    printf("Delivery Charges: Rs. %.2f\n", deliveryCharges);

    printf("Priority Delivery: %s\n",
           (priorityCharges == 500) ? "YES" : "NO");

    printf("Priority Charges: Rs. %.2f\n", priorityCharges);

    if(remainder == 0)
        printf("Processing Group: Group A\n");
    else if(remainder == 1)
        printf("Processing Group: Group B\n");
    else if(remainder == 2)
        printf("Processing Group: Group C\n");
    else
        printf("Processing Group: Group D\n");

    printf("Total Amount Payable: Rs. %.2f\n", totalAmount);

    return 0;
}