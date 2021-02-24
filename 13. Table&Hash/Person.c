#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

int GetSSN(Person* p){
    return p->ssn;
}

void ShowPersonInfo(Person* p){
    printf("SSN: %d\n", p->ssn);
    printf("Name: %s\n", p->name);
    printf("Address: %s\n\n", p->addr);
}

Person* MakePersonData(int ssn, char* name, char* addr){
    Person* newPerson = malloc(sizeof(Person));
    newPerson->ssn = ssn;
    strcpy(newPerson->name, name);
    strcpy(newPerson->addr, addr);

    return newPerson;
}