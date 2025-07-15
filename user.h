#ifndef USER_H
#define USER_H

/**
 * @brief Displays the record of a specific patient by their ID.
 * 
 * @param ids Array of patient IDs.
 * @param names 2D array storing patient names.
 * @param ages Array of patient ages.
 * @param genders 2D array storing patient genders.
 * @param patientCount Total number of patients stored.
 */
void viewRecord(int ids[], char names[][50], int ages[], char genders[][30], int patientCount);

/**
 * @brief Displays all reservations for today.
 * 
 * Loops through the patients and prints the reservation slots they have reserved.
 * If a patient has no reservation (value = -1), they will be skipped.
 * 
 * @param ids Array of patient IDs.
 * @param patientSlots Array that holds the reserved slot number for each patient.
 *        If patientSlots[i] == -1, that patient has no reservation.
 * @param patientCount Total number of registered patients.
 * @param slots Array of strings representing available slot descriptions (e.g., "2PM to 2:30PM").
 */
void viewReservations(int ids[], int patientSlots[], int patientCount, char* slots[]);

#endif	//	USER_H
