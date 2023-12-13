#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

struct person {
    char* name;
    char *adres;
    int age;
};

typedef struct person person;

person *a = (person*)malloc(sizeof(person));
int main() {
    (*a).name = "Igor";
    (*a).adres = "asd";
    (*a).age = 15;
    printf("%i", a->age);
}