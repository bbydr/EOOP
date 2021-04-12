#include <iostream>
#include <string>
#include <list>
#include <stdlib.h>
#include <string.h>
#include "PatientBio.h"
#include "Hospital.h"
#include "People.h"

using namespace std;


Patient &findPatient(list <Patient*> patients, int id) {
    list<Patient*>::iterator iter;
    for(iter = patients.begin(); iter != patients.end(); iter++) {
        if((*iter) -> _patientId() == id) {
            return **iter;
        }
    }
}
/*
int main(int argc, char const *argv[]) {
    Hospital x;
    // patientID, hospitalId, name, sex, age, room_num, hospitalized
    x.appendPatient(1, 1, "Aaron Finch", 'M', 19, 709, false);
    x.appendPatient(4, 1, "Maise Williams", 'F', 21, 523, true);
    x.appendPatient(6, 2, "Shaun Marsh", 'M', 62, 754, true);
    x.appendPatient(5, 2, "Sophie Turner", 'F', 12, 41, true);
    x.retrievePatients();
    return 0;
}
*/
