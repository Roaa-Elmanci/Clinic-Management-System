#include <stdio.h>
#include "admin.h"
#include "user.h"

void main (void)
{
	int ids[100], ages[100], patientSlots[100];
    char names[100][50], genders[100][30];
    int patientCount = 0;

    int reservations[5] = {0}; 

	int mod,i=0;
	int defpass = 1234,pass;
	int op;
	int running =1;
	while(running)
	{
		printf("\nPlease choose (1) for Admin Mode, (2) for User Mode, (3) for Exit: ");
		scanf("%d",&mod);
				
		// admin login
		if(mod==1)
		{
			do
			{
				printf("Enter password: ");
				scanf("%d",&pass);
				i++;				
			}
			while((pass!=defpass) && (i<3));	
			
			int adminrunning = 1;
			while(adminrunning)
			{
				// choose operation
				printf("\n1.Add patient. - 2.Edit Record. - 3.Reservation with a doctor. - 4.Cancel reservation. - 5.Exit. -> ");
				scanf("%d",&op);
			
				switch(op)
				{
					case 1:
						addPatient(ids,names,ages,genders,&patientCount);
						break;
					case 2:
						editRecord(ids,names,ages,genders,patientCount);
						break;
					case 3:
						reservation(ids,patientCount,reservations,patientSlots);
						break;
					case 4:
						cancel(ids,patientCount,reservations,patientSlots);
						break;
					case 5:
						adminrunning = 0;
						break;
					default:
						printf("Invalid option \n");
				}
			}
		}
		else if(mod==2)
		{
			int adminrunning = 1;
			while(adminrunning)
			{
			// choose operation
				printf("\n1.View patient record. - 2.View today reservations. - 3.Exit. -> ");
				scanf("%d",&op);	
				
				switch(op)
				{
					case 1:
						viewRecord(ids,names,ages,genders,patientCount);
						break;
					case 2:
						viewReservations(ids,patientSlots,patientCount,slots);
						break;
					case 3:
						adminrunning = 0;
						break;
					default:
						printf("Invalid option \n");
				}
			}
		}
		else if(mod==3)
		{
			printf("Exiting program...\n");
			running = 0;
		}
		else
		{
			printf("Invalid choice");
		}
	}
}