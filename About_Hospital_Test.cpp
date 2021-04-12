#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include "People.h"
#include "Hospital.h"
#include "About_Hospital_Test.h"

using namespace std;


void hospitalTest::afterHospitalAddIsNotEmpty() {
    cout << "New Hospital Created\n";
    assert( hosp -> getHospitalList().empty() == false );
    cout << "Hospital List No Longer Empty: Passed\n\n";
}

void hospitalTest:: afterPatientAddIsNotEmpty() {
    cout << "Patient added\n";
    hosp -> appendPatient(1,1,"Test",'X',25,420,false);
    assert ( hosp -> isEmpty() == false);
    cout << "Patient List No Longer Empty: Passed\n\n";
}

//int id, int staffCount, int p_count, string name
void hospitalTest::hospitalDoesntExistAfterDeleting(){
    hosp -> addHospital ( 2, 44 , 12 , "Test Hospital");
    cout << "Hospital added, name: " << hosp -> getHospitalList().back() -> _name() <<endl;

    hosp -> deleteHospital(2);
    cout << "Hospital deleted\n";
    assert (hosp -> ifHospitalExists(2) == false);
    cout << "Hospital doesn't exist anymore\n\n";
}

void hospitalTest::patientDoesntExistAfterDeleting() {
    hosp -> deletePatient(1);
    assert( hosp -> ifPatientsExists(1) == false);
    cout << "Patient deleted successfully\n\n";
}

void hospitalTest::operatorAssignedCorrectly() {
    cout << "New Hospital created\n";
    Hospital *test;
    test = hosp;
    assert(test->_hospitalID() == hosp->_hospitalID());
    cout << "Hospital successfully Assigned:Passed\n\n";
}

void hospitalTest::exportedPatientList() {
    cout << "Exported patient info to 'test.txt.'\n";
    assert(hosp->addToFile(hosp->getList(), "test.txt"));
    cout << "File successfully created and exported:  Passed\n";
}

void hospitalTest::updatedHospitalInfo() {
    assert(hosp->updateHospital(1, 23, "tested"));
    cout << "Hospital updated successfully:           Passed\n\n";
}

void hospitalTest::updatedPatientInfo() {
    hosp -> appendPatient(1, 1, "Test", 'X', 19, 709, false);
    hosp -> patientUpdateInfo(1, 1, "Test", 'X', 23, 352, true);
    assert(hosp ->patientExists(1)._age() == 23);
    cout << "Patient updated successfully:            Passed\n\n";
}

void hospitalTest::patientDeleted() {
    assert(hosp -> deletePatient(1));
    cout << "Patient removed successfully:            Passed\n";
}



