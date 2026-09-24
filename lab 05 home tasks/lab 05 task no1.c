#include <stdio.h>

int main()
{
    int status = 0;
    int operation, device, mask;
    int mode;

    printf("SMART HOME SECURITY CONTROLLER\n");

    printf("\nEnter operation:\n");
    printf("1. Activate Device\n");
    printf("2. Deactivate Device\n");
    printf("3. Check Status\n");
    printf("4. Toggle Device\n");
    printf("Enter choice: ");
    scanf("%d", &operation);

    switch(operation)
    {
        case 1:
            printf("\nSelect Device:\n");
            printf("1. Main Door Lock\n");
            printf("2. Alarm System\n");
            printf("3. CCTV Camera\n");
            printf("4. Motion Sensor\n");
            printf("Enter device: ");
            scanf("%d", &device);

            switch(device)
            {
                case 1:
                    mask = 1 << 0;
                    status = status | mask;
                    printf("Main Door Lock activated.\n");
                    break;

                case 2:
                    mask = 1 << 1;
                    status = status | mask;
                    printf("Alarm System activated.\n");
                    break;

                case 3:
                    mask = 1 << 2;
                    status = status | mask;
                    printf("CCTV Camera activated.\n");
                    break;

                case 4:
                    mask = 1 << 3;
                    status = status | mask;
                    printf("Motion Sensor activated.\n");
                    break;

                default:
                    printf("Invalid device.\n");
            }
            break;

        case 2:
            printf("\nSelect Device:\n");
            printf("1. Main Door Lock\n");
            printf("2. Alarm System\n");
            printf("3. CCTV Camera\n");
            printf("4. Motion Sensor\n");
            printf("Enter device: ");
            scanf("%d", &device);

            switch(device)
            {
                case 1:
                    mask = 1 << 0;
                    status = status & ~mask;
                    printf("Main Door Lock deactivated.\n");
                    break;

                case 2:
                    mask = 1 << 1;
                    status = status & ~mask;
                    printf("Alarm System deactivated.\n");
                    break;

                case 3:
                    mask = 1 << 2;
                    status = status & ~mask;
                    printf("CCTV Camera deactivated.\n");
                    break;

                case 4:
                    mask = 1 << 3;
                    status = status & ~mask;
                    printf("Motion Sensor deactivated.\n");
                    break;

                default:
                    printf("Invalid device.\n");
            }
            break;

        case 3:
            printf("\nSelect Device:\n");
            printf("1. Main Door Lock\n");
            printf("2. Alarm System\n");
            printf("3. CCTV Camera\n");
            printf("4. Motion Sensor\n");
            printf("Enter device: ");
            scanf("%d", &device);

            switch(device)
            {
                case 1:
                    mask = 1 << 0;
                    printf("Main Door Lock is %s.\n",
                           (status & mask) ? "ACTIVE" : "INACTIVE");
                    break;

                case 2:
                    mask = 1 << 1;
                    printf("Alarm System is %s.\n",
                           (status & mask) ? "ACTIVE" : "INACTIVE");
                    break;

                case 3:
                    mask = 1 << 2;
                    printf("CCTV Camera is %s.\n",
                           (status & mask) ? "ACTIVE" : "INACTIVE");
                    break;

                case 4:
                    mask = 1 << 3;
                    printf("Motion Sensor is %s.\n",
                           (status & mask) ? "ACTIVE" : "INACTIVE");
                    break;

                default:
                    printf("Invalid device.\n");
            }
            break;

        case 4:
            printf("\nSelect Device:\n");
            printf("1. Main Door Lock\n");
            printf("2. Alarm System\n");
            printf("3. CCTV Camera\n");
            printf("4. Motion Sensor\n");
            printf("Enter device: ");
            scanf("%d", &device);

            switch(device)
            {
                case 1:
                    mask = 1 << 0;
                    status = status ^ mask;
                    break;

                case 2:
                    mask = 1 << 1;
                    status = status ^ mask;
                    break;

                case 3:
                    mask = 1 << 2;
                    status = status ^ mask;
                    break;

                case 4:
                    mask = 1 << 3;
                    status = status ^ mask;
                    break;

                default:
                    printf("Invalid device.\n");
            }

            printf("Device toggled.\n");
            break;

        default:
            printf("Invalid operation.\n");
    }

    printf("\nEnter Security Mode:\n");
    printf("1. Home Mode\n");
    printf("2. Away Mode\n");
    printf("3. Night Mode\n");
    printf("4. No Mode\n");
    printf("Enter choice: ");
    scanf("%d", &mode);

    switch(mode)
    {
        case 1:
            status = status | (1 << 0);
            status = status | (1 << 2);
            printf("Home Mode selected.\n");
            break;

        case 2:
            status = status | (1 << 0);
            status = status | (1 << 1);
            status = status | (1 << 2);
            status = status | (1 << 3);
            printf("Away Mode selected.\n");
            break;

        case 3:
            status = status | (1 << 0);
            status = status | (1 << 1);
            status = status | (1 << 3);
            printf("Night Mode selected.\n");
            break;

        case 4:
            printf("No security mode selected.\n");
            break;

        default:
            printf("Invalid mode.\n");
    }

    printf("\n--- DEVICE STATUS ---\n");

    printf("Main Door Lock : %s\n",
           (status & 1) ? "ACTIVE" : "INACTIVE");

    printf("Alarm System   : %s\n",
           (status & 2) ? "ACTIVE" : "INACTIVE");

    printf("CCTV Camera    : %s\n",
           (status & 4) ? "ACTIVE" : "INACTIVE");

    printf("Motion Sensor  : %s\n",
           (status & 8) ? "ACTIVE" : "INACTIVE");

    printf("\nBinary Status: %d%d%d%d\n",
           (status & 8) ? 1 : 0,
           (status & 4) ? 1 : 0,
           (status & 2) ? 1 : 0,
           (status & 1) ? 1 : 0);

    if ((status & 1) && (status & 2) &&
        (status & 4) && (status & 8))
    {
        printf("Security System: FULLY ARMED\n");
    }
    else
    {
        printf("Security System: NOT FULLY ARMED\n");
    }

    return 0;
}