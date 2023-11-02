#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <limits>

using namespace std;

// Define a structure for patient information
struct patient {
    long long id;
    string firstname;
    string lastname;
    int age;
    char blood[5];
    char gender;
    patient* next;
};

// Define a class for a linked queue to manage patients in a department
class linkedqueue {
    patient *head, *last;
public:
    linkedqueue() {
        head = NULL;
        last = NULL;
    }

    // Function to input patient data
    patient input();

    // Function to insert a patient at the end of the queue
    void insertatend();

    // Function to insert a patient at the beginning of the queue
    void insertatbeg();

    // Function to get the patient at the front of the queue
    void getpatientout();

    // Function to display the list of patients in the department
    void listofpatients();

    // Function to search for a patient by ID
    int search(int);
    char departmentname[50];
};

// Function to search for a patient by ID
int linkedqueue::search(int name) {
    if (head == NULL) {
        return false;
    }else {
        int flag = 0;
        patient* p = new patient();
        p = head;

        // Traverse the linkedlist to find the patient with the specified ID
        while (p->next != NULL && p->id != name) {
            p->next;
        }
        if (p->id == name) {
            flag = 1;
            return true;
        }
        if (flag == 0) {
            return false;
        }
    }
}

// Function to read a number from input
int readnumber() {
    char b[20];
    cin.getline(b, sizeof(b));
    return atoi(b);
}

// Function to input patient data
patient linkedqueue::input() {
    int flag = 0;
    patient* p = new patient();
    cout << "\nEnter patient's data.\n";
    cout << "\n First name : ";
    getline(cin, p->firstname);
    cout << " Last name : ";
    getline(cin, p->lastname);

    // Validate blood group input
    again:
    cout << " Blood group : ";
    cin >> p->blood;
    if (strcmp(p->blood, "a+") == 0 ||
        strcmp(p->blood, "b+") == 0 ||
        strcmp(p->blood, "o+") == 0 ||
        strcmp(p->blood, "ab+") == 0 ||
        strcmp(p->blood, "a-") == 0 ||
        strcmp(p->blood, "b-") == 0 ||
        strcmp(p->blood, "o-") == 0 ||
        strcmp(p->blood, "ab-") == 0 ||
        strcmp(p->blood, "A+") == 0 ||
        strcmp(p->blood, "B+") == 0 ||
        strcmp(p->blood, "O+") == 0 ||
        strcmp(p->blood, "AB+") == 0 ||
        strcmp(p->blood, "A-") == 0 ||
        strcmp(p->blood, "B-") == 0 ||
        strcmp(p->blood, "O-") == 0 ||
        strcmp(p->blood, "AB-") == 0) {
        flag = 1;
    }
    if (flag == 0) {
        cout << "\n Invalid Blood group. Try again. \n";
        goto again;
    }

    // Validate gender input
    again_gender:
    cout << " Gender (M/F/N) : ";
    cin >> p->gender;
    p->gender = toupper(p->gender);  // Convert to uppercase for consistency
    if (p->gender != 'M' && p->gender != 'F' && p->gender != 'N') {
        cout << "\n Invalid gender. Please select M, F, or N. \n";
        goto again_gender;
    }

    cout << " Age : ";
    cin >> p->age;

    // Validate mobile number input
    again_phone:
    cout << " Mobile Number (10 digits): ";
    cin >> p->id;
    if (cin.fail() || p->id < 1000000000 || p->id > 9999999999) {
        cin.clear();  // Clear the fail state
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore any invalid input
        cout << "\n Invalid mobile number. Please enter a 10-digit numeric value. \n";
        goto again_phone;
    }

    // Check if the patient with the same ID already exists
    if (search(p->id)) {
        p->id = 0;
        cout << "\n Data Invalid. Process cancelled. \n";
    }
    return *p;
}

// Function to display patient information
void output(patient* p) {
    cout << "\n \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
    cout << "\n First name : " << p->firstname;
    cout << "\n Last name : " << p->lastname;
    cout << "\n Gender : " << p->gender;
    cout << "\n Age : " << p->age;
    cout << "\n Blood Group : " << p->blood;
    cout << "\n Mobile Number : " << p->id;
    cout << "\n \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
}

// Function to insert a patient at the beginning of the queue
void linkedqueue::insertatbeg() {
    patient* p = new patient();
    *p = input();
    if (p->id == 0)
        return;
    if (head == NULL) {
        head = p;
        last = p;
        p->next = NULL;
    }
    else {
        p->next = head;
        head = p;
    }
    system("cls");
    cout << "\n\tPatient added:";
    output(p);
}

// Function to insert a patient at the end of the queue
void linkedqueue::insertatend() {
    patient* p = new patient();
    *p = input();
    if (p->id == 0)
        return;
    if (head == NULL) {
        head = p;
        last = p;
        p->next = NULL;
    }
    else {
        p->next = NULL;
        last->next = p;
        last = p;
    }
    system("cls");
    cout << "\n \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n ----------PATIENT ADDED-----------";
    output(p);
}

// Function to get the patient at the front of the queue
void linkedqueue::getpatientout() {
    system("cls");
    if (head == NULL) {
        cout << "\n No Patient to operate";
    }
    else {
        patient* p = new patient();
        *p = *head;
        head = head->next;
        cout << "\n Patient to operate:";
        output(p);
    }
}

// Function to display the list of patients in the department
void linkedqueue::listofpatients() {
    if (head == NULL) {
        cout << "\n No patient";
    }
    system("cls");
    cout << "\n \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout << "\n |-- HOSPITAL MANAGEMENT SYSTEM --|";
    cout << "\n \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
    patient* p = new patient;
    p = head;
    while (p != NULL) {
        cout << "\n Patient data:\n";
        cout << "\n First Name : " << p->firstname;
        cout << "\n Last Name : " << p->lastname;
        cout << "\n Gender : " << p->gender;
        cout << "\n Age : " << p->age;
        cout << "\n Blood Group : " << p->blood;
        cout << "\n Mobile Number : " << p->id;
        cout << "\n\n \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
        p = p->next;
    }
    cout << "\n";
}

// Function to handle the department menu
void departmentmenu(linkedqueue* q) {
    int choice = 0, success;
    patient p;
    while (choice != 5) {
        system("cls");
        cout << "\n \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout << "\n |-- HOSPITAL MANAGEMENT SYSTEM --|";
        cout << "\n \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout << "\n\n " << q->departmentname;
        cout << "\n [1] Add normal patient\n";
        cout << " [2] Add critically ill patient\n";
        cout << " [3] Take patient to Doctor\n";
        cout << " [4] Display list\n";
        cout << " [5] Change department\n";
        cout << "\n Please enter your choice : ";
        choice = readnumber();
        cout << " \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        switch (choice) {
        case 1: q->insertatend(); //normal patient
            cout << "\n Press any key";
            getch();
            break;
        case 2: q->insertatbeg(); //critical patient
            cout << "\n Press any key";
            getch();
            break;
        case 3: q->getpatientout(); //patient to doctor
            cout << "\n Press any key";
            getch();
            break;
        case 4: system("cls");
            q->listofpatients(); //list of patients
            cout << "\n Press any key";
            getch();
            break;
        }
    }
}

int main() {
    int i, choice = 0;
    linkedqueue departments[4];
    while (choice != 5) {
        strcpy(departments[0].departmentname, "GENERAL CLINIC\n");
        strcpy(departments[1].departmentname, "HEART CLINIC\n");
        strcpy(departments[2].departmentname, "LUNG CLINIC\n");
        strcpy(departments[3].departmentname, "PLASTIC SURGERY\n");
        system("cls");
        cout << "\n \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
        cout << "\n |-- HOSPITAL MANAGEMENT SYSTEM --|";
        cout << "\n \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";
        cout << " Main Menu\n\n";
        for (i = 0; i < 4; i++) {
            cout << " " << (i + 1) << ": " << departments[i].departmentname;
        }
        cout << " 5: Exit";
        cout << "\n\n Please enter your choice : ";
        choice = readnumber();
        if (choice >= 1 && choice <= 4) {
            departmentmenu(&departments[choice - 1]);
        }
    }
    if (choice == 5)
        cout << "\n\t\tThank you! \n";
    exit(0);
}
