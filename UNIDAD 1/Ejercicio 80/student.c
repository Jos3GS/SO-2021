#include <stdlib.h>
     #include <stdio.h>
     #include <string.h>


     #include "person.h"
     #include "personPrivate.h"


     //Forward declaration
     typedef struct {

             person_t person;
             char* student_number;
             unsigned int passed_credits;
     } student_t;

     // Memory allocator
     student_t* student_new() {
             return (student_t*)malloc(sizeof(student_t));
     }

     // Constructor
     void student_ctor(student_t* student,
                                     const char* first_name,
                                     const char* last_name,
                                     unsigned int birth_year,
                                     const char* student_number,
                                     unsigned int passed_credits) {

            
             person_ctor((struct person_t*)student,
             first_name, last_name, birth_year);
             student->student_number = (char*)malloc(16 * sizeof(char));
             strcpy(student->student_number, student_number);
             student->passed_credits = passed_credits;
     }

     // Destructor
     void student_dtor(student_t* student) {
            
             free(student->student_number);

             person_dtor((struct person_t*)student);
     }


     void student_get_student_number(student_t* student,
                     char* buffer) {
                     strcpy(buffer, student->student_number);
     }

     unsigned int student_get_passed_credits(student_t* student) {
             return student->passed_credits;
     }