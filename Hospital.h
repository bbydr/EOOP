#ifndef OOPS_HOSPITAL_H
#define OOPS_HOSPITAL_H

#include "People.h"
#include <string>
#include <string.h>

using namespace std;

class Hospital {
    int hospitalId;
    int patient_count, staff_count;
    string name;
    int key;
    std::list <Hospital*> hospitals;
    std::list <Patient*> patients;
    std::list <Staff*> staff;

public:
    //setters
    void hospitalId_(int);
    void staff_count_(int);
    void patient_count_(int);
    void name_(string);
    void key_(int);

    //getters
    int _hospitalID();
    int _staff_count();
    int _patient_count();
    string _name();
    int _key();

    bool addHospital ( int id, int staff_count,
                        int patient_count, string name);
    bool isEmpty();
    Hospital& hospitalExists(int id);
    bool updateInformation( int id, int staff_count, int patient_count, string name);
    bool updateHospital( int, int, string);
    void deleteHospital(int id);
    //bool deletePatient(int patient_id);
    Patient& patientExists(int id);
    list <Patient*> getList();
    list <Hospital*> getHospitalList();

    void retrievePatients();
    void showPatientPersonalInfo(int patient_id, int key);
    void showPatientMedicalHistory(int patient_id, int key);
    bool addToFile(list <Patient*>, string);


    bool ifPatientsExists(int);
    bool ifHospitalExists(int);

    //Patient Methods
    bool appendPatient( int patient_id, int hospital_id, string name,
                        char sex, int age, int room_num, bool hospitalized);
    bool deletePatient(int patient_id);

    bool patientUpdateInfo( int patient_id, int hospital_id, string name, char sex,
                            int age, int room_num, bool hospitalized);

    //overloaded operators
    Hospital &operator=(const Hospital &);
    Hospital operator+(const Hospital &);
    friend ostream& operator << (ostream& os, const Hospital &);

    //default, overloaded and copy constructors
    Hospital(const Hospital &);
    Hospital(int, string);
    Hospital() { };
    ~Hospital() {};
};

#endif //OOPS_HOSPITAL_H
