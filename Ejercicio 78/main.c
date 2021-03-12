#include <stdio.h>

typedef struct {
    char first_name[32];
    char last_name[32];
    unsigned int birth_year;
}person_t;

typedef struct {
    person_t person;
    char student_number[16];
    unsigned int passed_credits;
}studen_t;

int main(int argc,char* argv[]){
    studen_t s;
    studen_t* s_ptr = &s;
    person_t* p_ptr = (person_t*)&s;
    printf("Puntero de Student es: %p\n",(void*)s_ptr);
    printf("Puntero de Persona es: %p\n",(void*)p_ptr);
    return 0;
}