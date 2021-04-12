#ifndef OOPS_PEOPLE_H
#define OOPS_PEOPLE_H
#include <string>
#include "PatientBio.h"

class People {
public:
    string name;
    People() {};
    ~People() {};
};

class Staff : public People {
    //in hours
    int shift, salary;
    bool isDoctor;
public:
    Staff() {};
    ~Staff() {};
};

class Patient : public People {
    int patientId, hospitalId;
    char sex;
    int age, room_number;
    bool hospitalized;

    PatientBio *personal_info;
    patientMedicalRecord *medical_history;
public:
    //setters
    void patientId_(int);
    void hospitalId_(int);
    void name_(string);
    void sex_(char);
    void age_(int);
    void room_number_(int);
    void hospitalized_(bool);

    //getters
    int _patientId();
    PatientBio* fetchPatientPersonalInfo();
    patientMedicalRecord* fetchPatientMedicalHistory();
    int _hospitalId();
    string _name();
    char _sex();
    int _age();
    int _room_number();
    bool _hospitalized();
    friend ostream& operator << (ostream& os, const Patient &);

    //medical History methods
    bool appendMedicalHistory(Patient *p, string b_group, bool terminal,
                           int days, int risk_level,bool donor/*,
							list <string> allergies*/);
    void retrieveMedicalHistory();
    void retrievePersonalInfo();

    //personal information methods
    bool appendPersonalInfo(Patient *p, int p_num, string add, string dob,
                         int height, int weight);
    Patient() { patientId  = -1; };
    Patient(int, int, string, char, int, int, bool);
    ~Patient() { };
};

#endif //OOPS_PEOPLE_H
