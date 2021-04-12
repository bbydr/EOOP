#include "People.h"
#include <list>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Hospital.h"

using namespace std;

Hospital:: Hospital (int id, string name){
    this -> hospitalId = id;
    this -> name = name;
    this -> hospitals.push_back(this);
}

bool Hospital::addHospital(int id, int staff_count, int patient_count, string name) {
    Hospital *hosp = new Hospital;

    hosp -> hospitalId    = id;
    hosp -> staff_count   = staff_count;
    hosp -> patient_count = patient_count;
    hosp -> name          = name;
    this -> hospitals.push_back(hosp);

    return true;
}

bool Hospital::updateInformation(int id, int staff_count, int patient_count, string name) {
    for (list<Hospital*>:: iterator iter = hospitals.begin(); iter!= hospitals.end(); iter++){
        if  ((*iter)-> hospitalId ==id){
            (*iter) -> staff_count   = staff_count;
            (*iter) -> patient_count = patient_count;
            (*iter) -> name          = name;
            return true;
        }
    }
    return true;
}

bool Hospital::updateHospital(int staff_count, int patient_count, string name) {
    this -> staff_count   = staff_count;
    this -> patient_count = patient_count;
    this -> name          = name;

    return true;

}

bool Hospital::patientUpdateInfo(int patient_id, int hospital_id, string name, char sex, int age, int room_num,
                                 bool hospitalized) {
    for (list<Patient*>::iterator iter = patients.begin(); iter != patients.end();iter++){
        if ((*iter) -> _patientId()== patient_id){
            (*iter) -> hospitalId_(hospital_id);
            (*iter) -> sex_(sex);
            (*iter) -> age_(age);
            (*iter) -> room_number_(room_num);
            (*iter) -> hospitalized_(hospitalized);
            (*iter) -> name_(name);
            return true;
        }
    }
    return false;
}

void Hospital::retrievePatients() {
    for(list<Patient*>::iterator iter = patients.begin(); iter != patients.end(); iter++){
        cout << "Patient ID: " << (*iter) -> _patientId() << endl;
        cout << "Name: " << (*iter) -> _name() << endl;
        cout << "Sex: " << (*iter) -> _sex()<< endl;
        cout << "Room Number: " << (*iter) -> _room_number()<< endl;
        cout << "Age: " << (*iter) -> _age()<< endl << endl;
    }
}

void Hospital::showPatientPersonalInfo(int patient_id, int key){
    for(list<Patient*>::iterator iter = patients.begin(); iter!= patients.end(); iter++){
        if((*iter)-> _patientId() == patient_id && this -> key == key){
            (*iter)->retrievePersonalInfo();
        }
    }
}

void Hospital::showPatientMedicalHistory(int patient_id, int key) {
    for (list<Patient *>::iterator iter = patients.begin(); iter != patients.end(); iter++) {
        if ((*iter)->_patientId() == patient_id && this->key == key)
            (*iter)->retrieveMedicalHistory();
    }
}

Patient& Hospital::patientExists(int id){
    for(list<Patient*>::iterator iter=patients.begin();iter!=patients.end();iter++){
        if((*iter)->_patientId() == id){
            Patient *P;
            P=(Patient*)(*iter);
            return *P;
        }
    }
    Patient *temp = new Patient();
    return *temp;
    cerr << "No Such Patient Exists" << endl;
}

Hospital& Hospital::hospitalExists(int id){
    for(list<Hospital*>::iterator iter=hospitals.begin();iter!=hospitals.end();iter++){
        if((*iter)->_hospitalID()==id){
            Hospital *P;
            P=(Hospital*)(*iter);
            return *P;
        }
    }
    Hospital *temp = new Hospital(-1, "null");
    return *temp;
    cerr << "No Such Hospital Exists" << endl;
}

bool Hospital::ifHospitalExists(int id) {
    if(hospitalExists(id)._hospitalID() == -1)
        return false;
    return true;
}

bool Hospital::ifPatientsExists(int id) {
    if(patientExists(id)._patientId() == -1)
        return false;
    return true;
}

bool Hospital::addToFile(list<Patient*> hh, string name){
    FILE *pFILEtxt;
    pFILEtxt = fopen(name.c_str(), "a");
    int j = 0;
    ofstream out;
    out.open(name.c_str(), ios::trunc);
    if (!out)
        return false;
    for(list<Patient*>::iterator iter = hh.begin(); iter != hh.end(); iter++,j++){
        string s,a,b,c;
        s=("Name: " + (*iter)->_name()) + "\n";
        out << s;

        int i = (*iter) -> _patientId();

        s = "Patient ID: ";
        out << s;
        out << i;
        out << "\n";

        s="Room Number:  ";
        i = (*iter) -> _room_number();
        out << s;
        out << i;
        out << "\n";


        s = "Age:  ";
        i = (*iter) -> _age();
        out << s;
        out << i;
        out << "\n\n\n";
        out<<"\nNext Patient\n\n\n\n\n";
    }

    out << "-=====END====-" ;
    fclose(pFILEtxt);
    return true;
}

list <Patient*> Hospital::getList() {
    return patients;
};

list <Hospital*> Hospital::getHospitalList() {
    return hospitals;
};

bool Hospital::appendPatient(int p_id, int hos_id, string name, char sex,int age, int room_num, bool hospitalized) {
    Patient *temp = new Patient;
    temp -> patientId_(p_id);
    temp -> hospitalId_(hos_id);
    temp -> name_(name);
    temp -> sex_(sex);
    temp -> age_(age);
    temp -> room_number_(room_num);
    temp -> hospitalized_(hospitalized);
    this -> patients.push_back(temp);
    return true;
}

bool Hospital::isEmpty() {
    return (this -> patients.empty());
}

bool Hospital::deletePatient(int patient_id){
    for(list<Patient*>::iterator iter=patients.begin();iter!=patients.end();iter++){
        if((*iter)->_patientId()==patient_id){
            patients.erase(iter++);
            return true;
        }
    }
    return false;
}

void Hospital::deleteHospital(int id){
    for(list<Hospital*>::iterator iter = hospitals.begin();iter!=hospitals.end();iter++){
        if((*iter)->_hospitalID() == id)
            hospitals.erase(iter++);
    }
}

Hospital& Hospital::operator=(const Hospital& h) {
    if(this==&h)
        return *this;
    hospitalId=h.hospitalId;
    staff_count=h.staff_count;
    patient_count=h.patient_count;
    name=h.name;
    key=h.key;
    hospitals=h.hospitals;
    patients=h.patients;
    staff=h.staff;
    return *this;
}

Hospital Hospital::operator+(const Hospital &h){

    Hospital result;
    list<Hospital*> hsptl;
    hsptl = h.hospitals;

    list<Patient*> p;
    p = h.patients;

    list<Staff*> s;
    s=h.staff;

    if(this->hospitalId == h.hospitalId){
        result.hospitalId = hospitalId + h.hospitalId;
        result.staff_count = staff_count+h.staff_count;
        result.patient_count = patient_count+h.patient_count;
        result.name = name;
        result.key = key+h.key;

        result.hospitals = hospitals;
        result.patients = patients;
        result.staff = staff;
        result.hospitals.merge(hsptl);
        result.patients.merge(p);
        result.staff.merge(s);
    }
    return result;
}

//setters
void Hospital::hospitalId_(int hid) {
    hospitalId = hid;
}

void Hospital::staff_count_(int sc) {
    staff_count = sc;
};

void Hospital::patient_count_(int pc) {
    patient_count = pc;
};

void Hospital::name_(string s) {
    name = s;
};

void Hospital::key_(int k) {
    key = k;
};

//getters

int Hospital::_hospitalID() {
    return hospitalId;
};

int Hospital::_staff_count() {
    return staff_count;
};

int Hospital::_patient_count() {
    return patient_count;
};

string Hospital::_name() {
    return name;
};

int Hospital::_key() {
    return key;
};