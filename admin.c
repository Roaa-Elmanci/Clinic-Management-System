#include <stdio.h>
#include <string.h>
#include "admin.h"

char* slots[5] = {
    "2PM to 2:30PM",
    "2:30PM to 3PM",
    "3PM to 3:30PM",
    "3:30PM to 4PM",
    "4PM to 4:30PM"
};

void addPatient(int ids[],char names[][50],int ages[100],char gender[][30],int *patientCount)
{
	int id;
	int isuniq = 0;
	int i=0;
	// check if ID exists 
	while(!isuniq)
	{
		printf("Enter patient ID: ");
		scanf("%d",&id);
		isuniq = 1;
		for(i=0;i<*patientCount;i++)
		{	
			if(ids[i]==id)
			{
				printf("ID already exists \n");
				isuniq = 0;
			}
			break;
		}
	}

	//save ID
	ids[*patientCount]=id;
	
	printf("Enter patient name: ");
	scanf(" %[^\n]",names[*patientCount]);
		
	printf("Enter patient age: ");
	scanf("%d",&ages[*patientCount]);
		
	printf("Enter patient gender: ");
	scanf(" %[^\n]",gender[*patientCount]);
	
	(*patientCount)++;
    printf("\nPatient added successfully.\n");
}

void editRecord(int ids[],char names[][50],int ages[100],char gender[][30],int patientCount)
{
	int found = 1;
	int id;
	
	printf("\nEnter patient ID: ");
	scanf("%d",&id);
	found = 1;
	for(int i=0;i<(patientCount);i++)
	{
		if(ids[i]==id)
		{
			printf("Enter new patient name: ");
			scanf("%s",names[i]);
				
			printf("Enter new patient age: ");
			scanf("%d",&ages[i]);
				
			printf("Enter new patient gender: ");
			scanf(" %[^\n]",gender[i]);
			
			printf("Record updated successfully.\n");
			return;		// go back where called don't continue looping
		}
	}
	printf("\nPatient not found incorrect ID \n");
}

void reservation(int ids[],int patientCount,int reservations[],int patientSlots[])
{
	// show available slots
	int available = 0;
	int chosenSlot;
	
	for(int i=0;i<5;i++)
	{
		if(reservations[i]==0)
		{
			printf("The available slots are %d. %s \n",(i+1),slots[i]);
			available = 1;
		}
	}
	if (!available) {
        printf("No available slots.\n");
        return;
    }
		
	// enter available id
	int id,index = -1;
	
	printf("\nEnter patient ID: ");
	scanf("%d",&id);
	
	for(int i=0;i<(patientCount);i++)
	{
		if(ids[i]==id)
		{
			index = i;
			break;
		}
	}
	if(index==-1)
	{
		printf("Patient not found incorrect ID \n");
		return;
	}
	
	// choose slot

	printf("Please choose a slot number (1-5): ");
	scanf("%d",&chosenSlot);
	
	if((chosenSlot<1) || (chosenSlot>5))
	{
		printf("Wrong slot number");
		return;
	}
	
	if(reservations[chosenSlot - 1] == 1)
	{
		printf("Already reserved");
		return;
	}
	
	reservations[chosenSlot-1] = 1;
	patientSlots[index] = chosenSlot - 1;

	printf("Slot is reserved successfully \n")	;	
	
}

void cancel(int ids[],int patientCount,int reservations[],int patientSlots[])
{
	
	// enter available id
	int id,i,index = -1;
	
	printf("Enter patient ID: ");
	scanf("%d",&id);
	
	for(int i=0;i<(patientCount);i++)
	{
		if(ids[i]==id)
		{
			index = i;
			break;
		}
	}
	if(index == -1)
	{
		printf("Patient not found incorrect ID \n");
		return;
	}	
	
	// cancel reservation then the slot back available
	if(patientSlots[index] == -1)
	{
		printf("\nThe petient has no reservations\n");
	}	
	
	// canceling
	reservations[patientSlots[index]] = 0;
	patientSlots[index] = -1;

	
	printf("\nReservation cancelled successfully \n");
}
	
 