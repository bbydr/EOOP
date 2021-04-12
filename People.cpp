#include <string.h>
#include <string>
#include "PatientBio.h"
#include <iostream>
#include <list>
#include "People.h"

using namespace std;

Patient::Patient(int id, int h_id, string name, char sex, int age, int rno, bool hosp) {
    patientId = id;
    name = name;
    sex = sex;
    hospitalId = h_id;
    age = age;
    room_number = rno;
    hospitalized = hosp;
}

bool Patient::appendMedicalHistory(Patient *obj, string b_group, bool terminal,int days, int risk_level, bool donor){
    patientMedicalRecord *temp = new patientMedicalRecord;
    temp -> blood_group_(b_group);
    temp -> terminal_illness_(terminal);
    temp -> days_hospitalized_(days);
    temp -> risk_level_(risk_level);
    temp -> donor_(donor);
    obj -> medical_history = temp;
    return true;
}

bool Patient::appendPersonalInfo(Patient *p, int p_num, string add, string dob, int height, int weight){

    PatientBio *temp = new patientMedicalRecord;
    temp -> tel_number_(p_num);
    temp -> address_(add);
    temp -> dob_(dob);
    temp -> height_(height);
    temp -> weight_(weight);
    p -> personal_info=temp;
    return true;
}

void Patient::retrieveMedicalHistory() {
    cout << "Blood Group: " << (*medical_history)._blood_group() << endl;
    cout << "Terminal Illness: " << medical_history->_terminal_illness() << endl;
    cout << "Days at Hospital: " << medical_history->_days_hospitalized() << endl;
    cout << "Risk Level: " << medical_history->_risk_level() << endl;
    cout << "Donor: " << medical_history->_donor() << endl;
};

void Patient::retrievePersonalInfo(){
    cout<< "Height: " << personal_info->_height() << endl;
    cout<< "Weight: " << personal_info->_weight() << endl;
    cout<< "Date of Birth: " << personal_info->_dob()<<endl;
    cout<< "Address: " << personal_info->_address() << endl;
    cout<< "Phone No.: " <<personal_info->_tel_number() << endl;
};

//setters
void Patient::patientId_(int id) {
    patientId = id;
};
void Patient::hospitalId_(int id) {
    hospitalId = id;
};
void Patient::name_(string nam) {
    name = nam;
};
void Patient::sex_(char s) {
    sex = s;
};
void Patient::age_(int a) {
    age = a;
};
void Patient::room_number_(int rno) {
    room_number = rno;
};
void Patient::hospitalized_(bool val) {
    hospitalized = val;
};

//getters
int Patient::_patientId() {
    return patientId;
};
PatientBio* Patient::fetchPatientPersonalInfo()  {
    return personal_info;
};
patientMedicalRecord* Patient::fetchPatientMedicalHistory() {
    return medical_history;
};
int Patient::_hospitalId() {
    return hospitalId;
};
string Patient::_name() {
    return name;
};
char Patient::_sex() {
    return sex;
};
int Patient::_age() {
    return age;
};
int Patient::_room_number() {
    return room_number;
};
bool Patient::_hospitalized() {
    return hospitalized;
};