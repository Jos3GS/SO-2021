#include <stdio.h>
     #include <stdlib.h>
     #include "person.h"
     #include "student.h"

     int main(int argc, char* argv[]) {
            
             struct student_t* student = student_new();
             student_ctor(student, "John", "Doe", 1987, "TA5667", 134);

             char buffer[32];

             
             struct person_t* person_ptr = (struct person_t*)student;
             person_get_first_name(person_ptr, buffer);
             printf("First name: %s\n", buffer);
             person_get_last_name(person_ptr, buffer);
             printf("Last name: %s\n", buffer);
             printf("Birth year: %d\n", person_get_birth_year(person_ptr));

            
             student_get_student_number(student, buffer);
             printf("Student number: %s\n", buffer);
             printf("Passed credits: %d\n",
             student_get_passed_credits(student));

           
             student_dtor(student);
             free(student);
             return 0;
     }