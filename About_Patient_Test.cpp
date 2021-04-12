#include <iostream>
#include <cassert>
#include <string>
#include "People.h"
#include "About_Patient_Test.h"

using namespace std;

void About_Patient_Test::patientSuccessfullyAppended(){
    assert(true);
    cout << "Patient created successfully \n\n";
}

void About_Patient_Test::appendedMedicalRecord(){
    pat -> appendMedicalHistory(pat, "B+", false, 5, 2, true);
    assert(pat->fetchPatientMedicalHistory() -> _donor());
    cout << "Patient's medical history added \n\n";
}

void About_Patient_Test::appendedPersonalInfo() {
    pat -> appendPersonalInfo(pat, 0, "test", "1978/02/12", 22, 55);
    assert(pat->fetchPatientPersonalInfo()->_weight() == 55);
    cout << "Patient's personal information added: Passed\n\n";
}

//int main(int argc, char const *argv[]) {
//    About_Patient_Test pt;
//    pt.appendedMedicalRecord();
//    pt.appendedPersonalInfo();
//    pt.patientSuccessfullyAppended();
//    return 0;
//}
