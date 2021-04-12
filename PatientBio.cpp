#include "PatientBio.h"
#include <iostream>
#include <string>

using namespace std;

//setters
void PatientBio::tel_number_(int phone_num){
    this -> tel_number = phone_num;
}

void PatientBio::address_(string addr) {
    this -> address = addr;
}

void PatientBio::dob_(string dob) {
    this -> dob = dob;
}

void PatientBio::height_(int height) {
    this -> height = height;
}

void PatientBio::weight_(int weight) {
    this -> weight = weight;
}

//getters
int PatientBio::_tel_number() {
    return tel_number;
}

int PatientBio::_height() {
    return height;
}

int PatientBio::_weight() {
    return weight;
}

string PatientBio::_address() {
    return address;
}

string PatientBio::_dob() {
    return dob;
}

//setters
void patientMedicalRecord::blood_group_(string bg) {
    blood_group = bg;
}
void patientMedicalRecord::terminal_illness_(bool ter) {
    terminal_illness = ter;
}
void patientMedicalRecord::days_hospitalized_(int days) {
    days_hospitalized = days;
}
void patientMedicalRecord::risk_level_(int rl) {
    risk_level = rl;
}
void patientMedicalRecord::donor_(bool d) {
    donor = d;
}

//getters
string patientMedicalRecord::_blood_group() {
    return blood_group;
}
bool patientMedicalRecord::_terminal_illness() {
    return terminal_illness;
}

int patientMedicalRecord::_days_hospitalized() {
    return days_hospitalized;
}

int patientMedicalRecord::_risk_level() {
    return risk_level;
}
bool patientMedicalRecord::_donor() {
    return donor;
}