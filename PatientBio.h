#ifndef OOPS_PATIENTBIO_H
#define OOPS_PATIENTBIO_H
#include <string>
#include <list>
using namespace std;

class PatientBio {
    string address;
    string dob;
    int height, weight;
    int tel_number;

public:

    void address_(string);
    void dob_(string);
    void height_(int);
    void weight_(int);
    void tel_number_(int);

    int _height();
    int _weight();
    string _address();
    string _dob();
    int _tel_number();

    PatientBio() {};
    ~PatientBio() {};
};

class patientMedicalRecord : public PatientBio {

    bool terminal_illness;
    int days_hospitalized;
    bool donor;
    string blood_group;
    int risk_level;
    list <string> allergies;

public:
    //setters
    void blood_group_(string);
    void terminal_illness_(bool);
    void days_hospitalized_(int);
    void risk_level_(int);
    void donor_(bool);

    //getters
    string _blood_group();
    bool _terminal_illness();
    int _days_hospitalized();
    int _risk_level();
    bool _donor();

    patientMedicalRecord() {};
    ~patientMedicalRecord() {};
};

#endif //OOPS_PATIENTBIO_H
