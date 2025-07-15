#include <stdio.h>
#include <string.h>
#include "user.h"
#include "admin.h"

 
void viewRecord(int ids[], char names[][50], int ages[], char genders[][30], int patientCount) {
    int id, found = 0, i;

    printf("Enter patient ID: ");
    scanf("%d", &id);

    for (i = 0; i < patientCount; i++) {
        if (ids[i] == id) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("\nPatient Record:\n");
        printf("ID: %d\n", ids[i]);
        printf("Name: %s\n", names[i]);
        printf("Age: %d\n", ages[i]);
        printf("Gender: %s\n", genders[i]);
    } else {
        printf("Patient not found.\n");
    }
}
 
 void viewReservations(int ids[], int patientSlots[], int patientCount, char* slots[])
 {
	int found = 0;
    printf("\nToday Reservations: \n");

    for (int i = 0; i < patientCount; i++) {
        if (patientSlots[i] != -1) 
		{		// there is reservations
			printf("Slot %d (%s), Patient ID: %d\n", patientSlots[i]+1, slots[patientSlots[i]], ids[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("No reservations yet.\n");
    }
 }