#include <iostream>
#include <string>
#include <list>
#include <stdlib.h>
#include <string.h>
#include "Hospital.h"
#include "PatientBio.h"
#include "People.h"
#include "About_Hospital_Test.h"
#include "About_Patient_Test.h"

using namespace std;

int main(int argc, char const *argv[]) {

    int choice = 0;
    cout << "ENTER YOUR CHOICE FROM THE FOLLOWING" << endl;
    cout << "1. Main simulation." << endl;
    cout << "2. Hospital Test."  << endl;
    cout << "3. Patient Test."   << endl;
    cin >> choice;

    cout << "You have chosen: " << choice << endl;
    if (choice >= 4 || choice <= 0 ) {
        cout << "Choice doesn't exist.";
        return 1;
    }

    switch (choice) {

        case 1:
        {
            cout << "Main simulation." << endl;
            Hospital x(1, "My hospital");
            Hospital y(2, "Big hospital");

            // p_id, hos_id, name, sex, age, room_num, hospitalized
           
	    x.appendPatient(1, 1, "Ayse Baydur", 'F', 50, 709, false);
            x.appendPatient(4, 1, "Beste Baydur", 'F', 21, 523, true);
            x.appendPatient(6, 2, "Bora Baydur", 'M', 10, 754, true);
            x.appendPatient(5, 2, "Sait Baydur", 'M', 53, 41, true);


            //OPERATOR OVERLOADING
            y = x;
            y.retrievePatients();

            //ACCESSING INDIVIDUAL PATIENTS
            Patient x1;
            x1=x.patientExists(6);
            // Patient *obj, string b_group, bool terminal, int days, int risk_level, bool donor
            x1.appendMedicalHistory(&x1, "O", false, 5, 2, false);

            // Patient *p, int p_num, string add, string dob, int height, int weight
            x1.appendPersonalInfo(&x1, 729382594, "Izmir", "2008/02/14", 150, 39);

            //Accessing individual properties of individual patients
            int i = x1.fetchPatientPersonalInfo()->_weight();
            cout << endl << endl << "Patient's weight: " << i << endl << endl;

            cout << "Patient's medical history\n";
            x1.retrieveMedicalHistory();
            cout << endl;
            cout << "Patient's Personal info\n";
            cout << "Name: " << x1._name() << endl;
            x1.retrievePersonalInfo();

            //Using FileIO
            x.addToFile(x.getList(), "Test.txt");

            break;
        }

        case 2:
        {
            cout << "Hospital Test." << endl;
            hospitalTest ht;
            ht.afterHospitalAddIsNotEmpty();
            ht.afterPatientAddIsNotEmpty();
            ht.hospitalDoesntExistAfterDeleting();
            ht.patientDoesntExistAfterDeleting();
            ht.operatorAssignedCorrectly();
            ht.exportedPatientList();
            ht.updatedHospitalInfo();
            ht.updatedPatientInfo();
            ht.patientDeleted();
            break;
        }

        case 3: {

            cout << "Patient Test." << endl;
            About_Patient_Test pt;
            pt.appendedMedicalRecord();
            pt.appendedPersonalInfo();
            pt.patientSuccessfullyAppended();
            break;
        }

    }

    return 0;
}