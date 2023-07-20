#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Patient
{
public:
    Patient(const string &name, int age, const string &gender, const string &phone, const string &diseases)
        : name(name), age(age), gender(gender), phone(phone), diseases(diseases) {}

    void displayDetails() const
    {
        cout << "Patient Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Gender: " << gender << "\n";
        cout << "Phone: " << phone << "\n";
        cout << "Diseases: " << diseases << "\n";
    }

    const string &getName() const
    {
        return name;
    }

private:
    string name;
    int age;
    string gender;
    string phone;
    string diseases;
};

class HospitalManagementSystem
{
public:
    void addPatient(const string &name, int age, const string &gender, const string &phone, const string &diseases)
    {
        patients.push_back(Patient(name, age, gender, phone, diseases));
        cout << "Patient '" << name << "' added successfully!\n";
    }

    void displayPatients() const
    {
        if (patients.empty())
        {
            cout << "No patients found.\n";
        }
        else
        {
            for (const auto &patient : patients)
            {
                cout << "\n";
                patient.displayDetails();
            }
        }
    }

    void deletePatient(const string &name)
    {
        for (auto it = patients.begin(); it != patients.end(); ++it)
        {
            if (it->getName() == name)
            {
                patients.erase(it);
                cout << "Patient '" << name << "' deleted successfully!\n";
                return;
            }
        }
        cout << "Patient '" << name << "' not found.\n";
    }

private:
    vector<Patient> patients;
};

int main()
{
    HospitalManagementSystem hospital;

    int choice;
    string name, gender, phone, diseases;
    int age;

    do
    {
        cout << "\n===== Hospital Management System =====\n";
        cout << "1. Add Patient\n";
        cout << "2. View Patients\n";
        cout << "3. Delete Patient\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            cout << "Enter Patient Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Gender: ";
            cin >> gender;
            cout << "Enter Phone: ";
            cin.ignore();
            getline(cin, phone);
            cout << "Enter Diseases (comma-separated): ";
            cin.ignore();
            getline(cin, diseases);
            hospital.addPatient(name, age, gender, phone, diseases);
            break;
        case 2:
            system("cls");
            hospital.displayPatients();
            break;
        case 3:
            system("cls");
            cout << "Enter Patient Name to delete: ";
            cin.ignore();
            getline(cin, name);
            hospital.deletePatient(name);
            break;
        case 4:
            system("cls");
            cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            system("cls");
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
