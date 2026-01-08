#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// hala geliştirilen bir koddur
struct informationofPatients{ // Hasta struct

int age;
float weight;
float height;
char name[50];
char phone[20];
char IDnumber[30];
char surName[50];
char gender[10];

};

struct informationofDoctors{ // doctors struct

int id;
char name[50];
char branch[50];
char phone[20];


};

void patientRegister(struct informationofPatients*,int);

void currentDoctors(void);

void searchPatients(struct informationofPatients*,int);

void saveToFile(struct informationofPatients *, int);
    

int main(){
int choice,n;
struct informationofPatients *patients = NULL;

while(1){

puts("____Welcome to hospital____");
puts("Choose process which you want");
puts("1-to register a patient or patients");
puts("2-to make an appointment and choose doctor");
puts("3-to search a patient");
puts("4-to EXIT");

printf("\nEnter your choice:");
scanf("%d",&choice);
printf("\n");

if(choice == 4)break;

switch(choice){

case 1:printf("Enter how many patients you will register:");
scanf("%d",&n);
patients = (struct informationofPatients*) malloc(n * sizeof(struct informationofPatients));

if(patients == NULL){
printf("Memory allocation failed\n");
return 1;
}

patientRegister(patients,n);
saveToFile(patients,n);

break;

case 2:currentDoctors();break;

case 3:searchPatients(patients,n);break;

default:printf("Invalid choice\n");

   } 
}
if(patients != NULL) {
        free(patients);
    }

    return 0;
}
void patientRegister(struct informationofPatients *patients,int n){ // Hasta bilgilerini alır ve ekrana yazdırır
for(int i=0;i<n;i++){

printf("\nEnter informations of patient %d:\n", i+1);
    printf("Patient gender(Male/Female):");
    scanf("%s",patients[i].gender);

if (strcmp(patients[i].gender, "Male") != 0 &&
    strcmp(patients[i].gender, "Female") != 0) {
    printf("ERROR: Only Male or Female allowed!\n");
    i--;
    continue;
}

    printf("Patient name: ");
    scanf("%s", patients[i].name);  
    printf("Patient surname:");
    scanf("%s",patients[i].surName);         
    printf("Patient age: ");
    scanf("%d", &patients[i].age);
    printf("Patient weight: ");
    scanf("%f", &patients[i].weight);
    printf("Patient height: ");
    scanf("%f", &patients[i].height);
    printf("Phone number without space bar: ");
    scanf("%s", patients[i].phone);
    printf("Patient ID number: ");
    scanf("%s", patients[i].IDnumber);
    printf("\nPatient registered successfully!\n\n");

}

}
void currentDoctors(void){

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

    printf("\nChoose a branch:\n");
    printf("1 - Cardiology\n");
    printf("2 - Orthopedics\n");
    printf("3 - Neurology\n");
    printf("4 - Internal Medicine\n");
    printf("5 - Dermatology\n");
    printf("6 - Pediatrics\n");
    printf("7 - Ophthalmology\n");
    printf("8 - ENT\n");
    printf("9 - Psychiatry\n");
    printf("10 - Urology\n");
    printf("11 - Pulmonology\n");
    printf("12 - Physical Therapy\n");
    printf("13 - Infectious Diseases\n");
    printf("14 - Endocrinology\n");
    printf("15 - Gastroenterology\n");
    printf("16 - Neurosurgery\n");
    printf("17 - Cardiovascular Surgery\n");
    printf("18 - Plastic Surgery\n");
    printf("19 - OB/GYN\n");
    printf("Enter your choice: ");
    scanf("%d", &branchChoice);

    char selectedBranch[50];

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
            printf("Invalid choice!\n");
            return;
    }

    printf("\nAvailable doctors in %s:\n", selectedBranch);
    int count = 0;

    for(int i = 0; i < doctorCount; i++){
        if(strcmp(doctors[i].branch, selectedBranch) == 0){
            count++;
            printf("%d. %s (ID: %d) - Phone: %s\n",
                   count, doctors[i].name,
                   doctors[i].id, doctors[i].phone);
        }
    }

    if(count == 0){
        printf("No doctors available.\n");
        return;
    }

    printf("\nSelect doctor number (1-%d): ", count);
    scanf("%d", &doctorChoice);

    if(doctorChoice >= 1 && doctorChoice <= count)
        printf("\nAppointment booked successfully!\n");
    else
        printf("\nInvalid doctor selection!\n");
}
void searchPatients(struct informationofPatients* patients,int n){

if(patients == NULL || n == 0) {
        printf("No patients registered yet!\n\n");
        return;
    }

char searchID[30];    
printf("Enter a patient ID:\n");
scanf("%s",searchID);

int found=0;

for(int i=0;i<n;i++){
if(strcmp(patients[i].IDnumber,searchID)==0){
printf("You found your patient...\n");
printf("__Information about your found patient__\n");
    printf("name: %s\n",patients[i].name);
    printf("surname:%s\n",patients[i].surName);         
    printf("age: %d\n",patients[i].age);
    printf("weight: %.2f\n",patients[i].weight);
    printf("height: %.2f\n",patients[i].height);
    printf("Phone number: %s\n",patients[i].phone);
    printf("ID number: %s\n",patients[i].IDnumber);
printf("\n");
found=1;
break;

}
}

if(!found)
     printf("Patient not found!\n");

}

void saveToFile(struct informationofPatients *patients, int n){

 FILE *fptr = fopen("C:\\Users\\LENOVO\\OneDrive\\Belgeler\\Data\\patients.txt", "w");  // append mode
    
    if(fptr == NULL) {
        printf("File error!\n");
        return;
    }

    for(int i=0;i<n;i++){
    fprintf(fptr,"%s,%s,%d,%.2f,%.2f,%s,%s",
            patients[i].name,
            patients[i].surName,
            patients[i].age,
            patients[i].weight,
            patients[i].height,
            patients[i].phone,
            patients[i].IDnumber);  
    }
printf("The process completed successfully\n\n");
    fclose(fptr);
}
   
