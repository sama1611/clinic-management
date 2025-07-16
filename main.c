#include <stdio.h>
#include <stdlib.h>
#include "clinic.h"


int main() {
    int mode;
    while (1) {
        printf("\n================================\n");
        printf("🏥 Clinic Management System\n");
        printf("================================\n");
        printf("1. Admin Mode\n");
        printf("2. User Mode\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &mode);

        switch (mode) {
            case 1: admin_mode(); break;
            case 2: user_mode(); break;
            case 3: 
                printf(" Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf(" Invalid choice. Please try again.\n");
        }
    }
}
