#include <stdio.h>
#include <stdlib.h>
#include "clinic.h"

typedef struct p {
    char name[20];
    int age;
    char gender[10];
    int id;
    int slot;
    struct p *link;
} patient;

const char* slots[] = {
    "2pm to 2:30pm",
    "2:30pm to 3pm",
    "3pm to 3:30pm",
    "4pm to 4:30pm",
    "4:30pm to 5pm"
};

patient *head = NULL;
int reserved_slots[5] = {0};

patient *find_p(int id) {
    patient* temp = head;
    while (temp) {
        if (temp->id == id)
            return temp;
        temp = temp->link;
    }
    return NULL;
}

void add_p() {
    int id;
    printf("\n--- Add New Patient Record ---\n");
    printf("Enter patient's ID: ");
    scanf("%d", &id);
    if (find_p(id)) {
        printf(" Patient already exists.\n");
        return;
    }

    patient *new_p = malloc(sizeof(patient));
    new_p->id = id;
    new_p->slot = -1;
    printf("Enter patient's name: ");
    scanf("%s", new_p->name);
    printf("Enter patient's age: ");
    scanf("%d", &new_p->age);
    printf("Enter patient's gender: ");
    scanf("%s", new_p->gender);
    new_p->link = head;
    head = new_p;

    printf(" Patient added successfully.\n");
}

void edit_p() {
    int id;
    printf("\n--- Edit Patient Record ---\n");
    printf("Enter patient ID: ");
    scanf("%d", &id);
    patient *p = find_p(id);
    if (!p) {
        printf(" Incorrect ID.\n");
        return;
    }

    printf("Enter new name: ");
    scanf("%s", p->name);
    printf("Enter new age: ");
    scanf("%d", &p->age);
    printf("Enter new gender: ");
    scanf("%s", p->gender);
    printf("Record updated successfully.\n");
}

void reserve() {
    printf("\n--- Available Slots ---\n");
    for (int i = 0; i < 5; i++) {
        if (reserved_slots[i] == 0) {
            printf("%d. %s\n", i + 1, slots[i]);
        }
    }

    int id, slot;
    printf("\nEnter your patient ID: ");
    scanf("%d", &id);
    patient *p = find_p(id);
    if (!p) {
        printf("Incorrect ID.\n");
        return;
    }

    printf("Choose a slot number (1-5): ");
    scanf("%d", &slot);
    if (slot < 1 || slot > 5 || reserved_slots[slot - 1]) {
        printf(" Invalid or already reserved slot.\n");
        return;
    }

    p->slot = slot - 1;
    reserved_slots[slot - 1] = 1;
    printf(" Slot reserved successfully for %s.\n", slots[slot - 1]);
}

void del_res() {
    int id;
    printf("\n--- Cancel Reservation ---\n");
    printf("Enter patient ID: ");
    scanf("%d", &id);
    patient* p = find_p(id);
    if (!p) {
        printf("Incorrect ID.\n");
        return;
    }

    if (p->slot == -1) {
        printf("⚠️ No reservation found for this patient.\n");
        return;
    }

    reserved_slots[p->slot] = 0;
    p->slot = -1;
    printf(" Reservation has been cancelled.\n");
}

void view_patient() {
    int id;
    printf("\n--- View Patient Record ---\n");
    printf("Enter patient ID: ");
    scanf("%d", &id);
    patient* p = find_p(id);
    if (!p) {
        printf(" Incorrect ID.\n");
        return;
    }

    printf("\n Patient Information:\n");
    printf("Name   : %s\n", p->name);
    printf("Age    : %d\n", p->age);
    printf("Gender : %s\n", p->gender);
    if (p->slot != -1) {
        printf("Slot   : %s\n", slots[p->slot]);
    } else {
        printf("Slot   : No reservation.\n");
    }
}

void view_reservations() {
    printf("\n--- Today's Reservations ---\n");
    for (int i = 0; i < 5; i++) {
        int found = 0;
        patient* temp = head;
        while (temp) {
            if (temp->slot == i) {
                printf("%s -> ID: %d (%s)\n", slots[i], temp->id, temp->name);
                found = 1;
                break;
            }
            temp = temp->link;
        }
        if (!found)
            printf("%s -> Available\n", slots[i]);
    }
}

void admin_mode() {
    int pass;
    int trials = 0;

    printf("\n Admin Mode\n");
    printf("Please enter admin password: ");
    while (trials < 3) {
        scanf("%d", &pass);
        if (pass == 1234) {
            printf("\n Access granted!\n");
            printf("================================\n");
            printf("1. Add new patient record\n");
            printf("2. Edit patient record\n");
            printf("3. Reserve a slot with the doctor\n");
            printf("4. Cancel reservation\n");
            printf("Enter your choice: ");
            int c;
            scanf("%d", &c);
            printf("================================\n");
            switch (c) {
                case 1: add_p(); break;
                case 2: edit_p(); break;
                case 3: reserve(); break;
                case 4: del_res(); break;
                default: printf(" Invalid choice.\n");
            }
            return;
        } else {
            trials++;
            if (trials < 3)
                printf(" Wrong password, try again (%d trials left): ", 3 - trials);
        }
    }
    printf("🔒 Too many failed attempts. Returning to main menu.\n");
}

void user_mode() {
    int choice;
    printf("\n👤 User Mode\n");
    printf("================================\n");
    printf("1. View Patient Record\n");
    printf("2. View Today's Reservations\n");
    printf("3. Exit User Mode\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("================================\n");

    switch (choice) {
        case 1: view_patient(); break;
        case 2: view_reservations(); break;
        case 3: return;
        default: printf(" Invalid choice.\n");
    }
}

