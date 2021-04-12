#ifndef OOPS_ABOUT_HOSPITAL_TEST_H
#define OOPS_ABOUT_HOSPITAL_TEST_H
#include "Hospital.h"

class hospitalTest{
public:
    Hospital *hosp = new Hospital (1, "My New Hospital");
    void afterHospitalAddIsNotEmpty();
    void afterPatientAddIsNotEmpty();
    void hospitalDoesntExistAfterDeleting();
    void patientDoesntExistAfterDeleting();
    void operatorAssignedCorrectly();
    void exportedPatientList();
    void updatedHospitalInfo();
    void updatedPatientInfo();
    void patientDeleted();
    hospitalTest() {};
    ~hospitalTest() {};
};

#endif //OOPS_ABOUT_HOSPITAL_TEST_H
