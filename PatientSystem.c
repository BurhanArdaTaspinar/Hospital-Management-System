#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// --- STRUCTURE DEFINITIONS ---

// Structure to hold patient details
struct informationofPatients {
    int age;
    float weight;
    float height;
    char name[50];
    char phone[20];
    char IDnumber[30];
    char surName[50];
    char gender[10];
};

// Structure to hold doctor details
struct informationofDoctors {
    int id;
    char name[50];
    char branch[50];
    char phone[20];
};

// --- FUNCTION PROTOTYPES ---
void patientRegister(struct informationofPatients*, int);
void currentDoctors(void);
void searchPatients(struct informationofPatients*, int);
void saveToFile(struct informationofPatients*, int);

// --- MAIN FUNCTION ---
int main() {
    int choice, n;
    struct informationofPatients *patients = NULL; // Pointer for dynamic array

    while (1) {
        // Main Menu Display
        puts("____Welcome to the Hospital Management System____");
        puts("Please select an operation:");
        puts("1 - Register new patient(s)");
        puts("2 - Make an appointment (View Doctors)");
        puts("3 - Search for a patient");
        puts("4 - EXIT");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        if (choice == 4) break; // Exit condition

        switch (choice) {
            case 1:
                printf("Enter the number of patients to register: ");
                scanf("%d", &n);
                
                // Dynamic memory allocation for patients
                patients = (struct informationofPatients*) malloc(n * sizeof(struct informationofPatients));

                if (patients == NULL) {
                    printf("Memory allocation failed!\n");
                    return 1;
                }

                patientRegister(patients, n); // Get inputs
                saveToFile(patients, n);      // Save to .txt file
                break;

            case 2:
                currentDoctors(); // Show doctor list
                break;

            case 3:
                searchPatients(patients, n); // Search in current memory
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    // Free allocated memory before exiting
    if (patients != NULL) {
        free(patients);
    }

    return 0;
}

// --- FUNCTION IMPLEMENTATIONS ---

// Function to take patient information from the user
void patientRegister(struct informationofPatients *patients, int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Enter details for Patient %d ---\n", i + 1);

        // Gender Input with Validation
        printf("Gender (Male/Female): ");
        scanf("%s", patients[i].gender);

        if (strcmp(patients[i].gender, "Male") != 0 && strcmp(patients[i].gender, "Female") != 0) {
            printf("ERROR: Invalid input! Only 'Male' or 'Female' allowed.\n");
            i--; // Decrement index to retry this iteration
            continue;
        }

        printf("Name: ");
        scanf("%s", patients[i].name);
        printf("Surname: ");
        scanf("%s", patients[i].surName);
        printf("Age: ");
        scanf("%d", &patients[i].age);
        printf("Weight (kg): ");
        scanf("%f", &patients[i].weight);
        printf("Height (cm): ");
        scanf("%f", &patients[i].height);
        printf("Phone number (no spaces): ");
        scanf("%s", patients[i].phone);
        printf("ID Number: ");
        scanf("%s", patients[i].IDnumber);
        
        printf("\nPatient registered successfully!\n\n");
    }
}

// Function to display doctors based on branch selection
void currentDoctors(void) {
    // Database of doctors
    struct informationofDoctors doctors[] = {
        {101, "Dr. Ahmet Yilmaz", "Cardiology", "05321234567"},
        {102, "Dr. Ayse Demir", "Cardiology", "05321234568"},
        {103, "Dr. Mehmet Kaya", "Orthopedics", "05321234569"},
        {104, "Dr. Zeynep Ozturk", "Orthopedics", "05321234570"},
        {105, "Dr. Can Arslan", "Neurology", "05321234571"},
        {106, "Dr. Elif Celik", "Neurology", "05321234572"},
        {107, "Dr. Ali Sahin", "Internal Medicine", "05321234573"},
        {108, "Dr. Seda Aydin", "Dermatology", "05321234574"},
        {109, "Dr. Murat Polat", "Pediatrics", "05321234575"},
        {110, "Dr. Ece Karaca", "Ophthalmology", "05321234576"},
        {111, "Dr. Hakan Yildiz", "ENT", "05321234577"},
        {112, "Dr. Derya Gun", "Psychiatry", "05321234578"},
        {113, "Dr. Burak Korkmaz", "Urology", "05321234579"},
        {114, "Dr. Selin Aksoy", "Pulmonology", "05321234580"},
        {115, "Dr. Onur Tas", "Physical Therapy", "05321234581"},
        {116, "Dr. Nazli Er", "Infectious Diseases", "05321234582"},
        {117, "Dr. Cem Polat", "Endocrinology", "05321234583"},
        {118, "Dr. Leyla Cinar", "Gastroenterology", "05321234584"},
        {119, "Dr. Tolga Demir", "Neurosurgery", "05321234585"},
        {120, "Dr. Yasemin Kurt", "Cardiovascular Surgery", "05321234586"},
        {121, "Dr. Emre Sahin", "Plastic Surgery", "05321234587"},
        {122, "Dr. Aylin Koc", "OB/GYN", "05321234588"}
    };

    int doctorCount = sizeof(doctors) / sizeof(doctors[0]);
    int branchChoice, doctorChoice;

    // Branch Selection Menu
    printf("\n--- Select a Medical Branch ---\n");
    printf("1 - Cardiology\n2 - Orthopedics\n3 - Neurology\n4 - Internal Medicine\n");
    printf("5 - Dermatology\n6 - Pediatrics\n7 - Ophthalmology\n8 - ENT\n");
    printf("9 - Psychiatry\n10 - Urology\n11 - Pulmonology\n12 - Physical Therapy\n");
    printf("13 - Infectious Diseases\n14 - Endocrinology\n15 - Gastroenterology\n");
    printf("16 - Neurosurgery\n17 - Cardiovascular Surgery\n18 - Plastic Surgery\n19 - OB/GYN\n");
    
    printf("Enter your choice: ");
    scanf("%d", &branchChoice);

    char selectedBranch[50];

    // Branch Mapping
    switch(branchChoice){
        case 1: strcpy(selectedBranch,"Cardiology"); break;
        case 2: strcpy(selectedBranch,"Orthopedics"); break;
        case 3: strcpy(selectedBranch,"Neurology"); break;
        case 4: strcpy(selectedBranch,"Internal Medicine"); break;
        case 5: strcpy(selectedBranch,"Dermatology"); break;
        case 6: strcpy(selectedBranch,"Pediatrics"); break;
        case 7: strcpy(selectedBranch,"Ophthalmology"); break;
        case 8: strcpy(selectedBranch,"ENT"); break;
        case 9: strcpy(selectedBranch,"Psychiatry"); break;
        case 10: strcpy(selectedBranch,"Urology"); break;
        case 11: strcpy(selectedBranch,"Pulmonology"); break;
        case 12: strcpy(selectedBranch,"Physical Therapy"); break;
        case 13: strcpy(selectedBranch,"Infectious Diseases"); break;
        case 14: strcpy(selectedBranch,"Endocrinology"); break;
        case 15: strcpy(selectedBranch,"Gastroenterology"); break;
        case 16: strcpy(selectedBranch,"Neurosurgery"); break;
        case 17: strcpy(selectedBranch,"Cardiovascular Surgery"); break;
        case 18: strcpy(selectedBranch,"Plastic Surgery"); break;
        case 19: strcpy(selectedBranch,"OB/GYN"); break;
        default:
            printf("Invalid branch selection!\n");
            return;
    }

    printf("\nAvailable doctors in %s:\n", selectedBranch);
    int count = 0;

    // Display doctors matching the selected branch
    for(int i = 0; i < doctorCount; i++){
        if(strcmp(doctors[i].branch, selectedBranch) == 0){
            count++;
            printf("%d. %s (ID: %d) - Phone: %s\n",
                   count, doctors[i].name,
                   doctors[i].id, doctors[i].phone);
        }
    }

    if(count == 0){
        printf("No doctors available in this branch.\n");
        return;
    }

    // Appointment Booking Logic
    printf("\nSelect the doctor number (1-%d) to book: ", count);
    scanf("%d", &doctorChoice);

    if(doctorChoice >= 1 && doctorChoice <= count)
        printf("\nAppointment booked successfully!\n");
    else
        printf("\nInvalid doctor selection!\n");
}

// Function to search for a patient by ID
void searchPatients(struct informationofPatients* patients, int n) {
    if(patients == NULL || n == 0) {
        printf("No registered patients found in memory!\n\n");
        return;
    }

    char searchID[30];    
    printf("Enter the Patient ID to search: ");
    scanf("%s", searchID);

    int found = 0;

    for(int i = 0; i < n; i++) {
        if(strcmp(patients[i].IDnumber, searchID) == 0) {
            printf("\n--- Patient Record Found ---\n");
            printf("Name: %s\n", patients[i].name);
            printf("Surname: %s\n", patients[i].surName);         
            printf("Age: %d\n", patients[i].age);
            printf("Weight: %.2f\n", patients[i].weight);
            printf("Height: %.2f\n", patients[i].height);
            printf("Phone: %s\n", patients[i].phone);
            printf("ID: %s\n", patients[i].IDnumber);
            printf("\n");
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Patient with ID '%s' not found!\n", searchID);
}

// Function to save patient data to a text file
void saveToFile(struct informationofPatients *patients, int n) {
    // UPDATED: Using relative path "patients.txt" so it works on any computer
    FILE *fptr = fopen("patients.txt", "w"); // "w" mode overwrites. Use "a" to append.
    
    if(fptr == NULL) {
        printf("Error: Could not create or open file!\n");
        return;
    }

    for(int i = 0; i < n; i++) {
        fprintf(fptr, "%s,%s,%d,%.2f,%.2f,%s,%s\n",
                patients[i].name,
                patients[i].surName,
                patients[i].age,
                patients[i].weight,
                patients[i].height,
                patients[i].phone,
                patients[i].IDnumber);  
    }
    
    printf("Data saved to 'patients.txt' successfully.\n\n");
    fclose(fptr);
}
}
   

