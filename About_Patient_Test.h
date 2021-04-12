#ifndef OOPS_ABOUT_PATIENT_TEST_H
#define OOPS_ABOUT_PATIENT_TEST_H

#include <iostream>
#include "About_Patient_Test.h"
#include "People.h"
#include <cassert>

class About_Patient_Test {
public:
    Patient *pat = new Patient(1, 1, "test", 'x', 25, 65, true);
    void appendedMedicalRecord();
    void appendedPersonalInfo();
    void staffCreated();
    void patientSuccessfullyAppended();
    About_Patient_Test() {};
    ~About_Patient_Test() {};
};


#endif //OOPS_ABOUT_PATIENT_TEST_H
