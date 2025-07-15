#ifndef ADMIN_H
#define ADMIN_H

// External array containing the time slots (e.g., "2PM to 2:30PM", etc.)
extern char* slots[5];

/**
 * @brief Adds a new patient to the system after validating ID uniqueness.
 * 
 * @param ids Array of stored patient IDs.
 * @param names 2D array storing names of patients.
 * @param ages Array of patient ages.
 * @param gender 2D array storing gender of each patient.
 * @param patientCount Pointer to the number of currently stored patients (will be incremented).
 */
void addPatient(int ids[],char names[][50],int ages[100],char gender[][30],int *patientCount);

/**
 * @brief Edits the information of a patient after searching by ID.
 * 
 * @param ids Array of patient IDs.
 * @param names 2D array storing names of patients.
 * @param ages Array of patient ages.
 * @param gender 2D array storing gender of each patient.
 * @param patientCount Total number of stored patients.
 */
void editRecord(int ids[],char names[][50],int ages[100],char gender[][30],int patientCount);

/**
 * @brief Allows admin to reserve a slot for a patient.
 * 
 * @param ids Array of patient IDs.
 * @param patientCount Total number of patients.
 * @param reservations Array representing reserved (1) or available (0) status for each slot.
 * @param patientSlots Array where each element stores which slot was booked by which patient (index = patient index).
 */
void reservation(int ids[],int patientCount,int reservations[],int patientSlots[]);

/**
 * @brief Cancels a previously reserved slot for a patient.
 * 
 * @param ids Array of patient IDs.
 * @param patientCount Total number of patients.
 * @param reservations Array representing reserved (1) or available (0) status for each slot.
 * @param patientSlots Array where each element stores which slot was booked by which patient.
 */
void cancel(int ids[],int patientCount,int reservations[],int patientSlots[]);

#endif // ADMIN_H
