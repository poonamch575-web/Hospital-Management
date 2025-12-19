#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// --------------------- Patient Class ---------------------
class Patient {
public:
    int id;
    string name, disease, phone;

    void input() {
        cout << "\nEnter Patient ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Patient Name: ";
        getline(cin, name);

        cout << "Enter Disease: ";
        getline(cin, disease);

        cout << "Enter Phone: ";
        getline(cin, phone);
    }

    void display() {
        cout << "\nID: " << id
             << "\nName: " << name
             << "\nDisease: " << disease
             << "\nPhone: " << phone << endl;
    }
};

// --------------------- Doctor Class ---------------------
class Doctor {
public:
    int id;
    string name, specialist;

    void input() {
        cout << "\nEnter Doctor ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Doctor Name: ";
        getline(cin, name);

        cout << "Enter Specialist: ";
        getline(cin, specialist);
    }

    void display() {
        cout << "\nID: " << id
             << "\nName: " << name
             << "\nSpecialist: " << specialist << endl;
    }
};

// --------------------- Appointment Class ---------------------
class Appointment {
public:
    int patientID, doctorID;
    string date;

    void input() {
        cout << "\nEnter Patient ID: ";
        cin >> patientID;

        cout << "Enter Doctor ID: ";
        cin >> doctorID;
        cin.ignore();

        cout << "Enter Appointment Date (DD/MM/YYYY): ";
        getline(cin, date);
    }

    void display() {
        cout << "\nPatient ID: " << patientID
             << "\nDoctor ID: " << doctorID
             << "\nDate: " << date << endl;
    }
};

// --------------------- File Functions ---------------------
template <typename T>
void saveToFile(string filename, T data) {
    ofstream fout(filename, ios::app | ios::binary);
    fout.write((char*)&data, sizeof(data));
    fout.close();
}

template <typename T>
void readFromFile(string filename) {
    ifstream fin(filename, ios::binary);
    T obj;
    while (fin.read((char*)&obj, sizeof(obj))) {
        obj.display();
    }
    fin.close();
}

// --------------------- Main Menu ---------------------
int main() {
    int choice;

    while (true) {
        cout << "\n\n========== Hospital Management System ==========";
        cout << "\n1. Add Patient";
        cout << "\n2. View Patients";
        cout << "\n3. Add Doctor";
        cout << "\n4. View Doctors";
        cout << "\n5. Book Appointment";
        cout << "\n6. View Appointments";
        cout << "\n7. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Patient p;
            p.input();
            saveToFile("patients.txt", p);
        }
        else if (choice == 2) {
            readFromFile<Patient>("patients.txt");
        }
        else if (choice == 3) {
            Doctor d;
            d.input();
            saveToFile("doctors.txt", d);
        }
        else if (choice == 4) {
            readFromFile<Doctor>("doctors.txt");
        }
        else if (choice == 5) {
            Appointment a;
            a.input();
            saveToFile("appointments.txt", a);
        }
        else if (choice == 6) {
            readFromFile<Appointment>("appointments.txt");
        }
        else if (choice == 7) {
            cout << "\nExiting... Stay healthy! 🌿\n";
            break;
        }
        else {
            cout << "\nInvalid choice!";
        }
    }

    return 0;
}
