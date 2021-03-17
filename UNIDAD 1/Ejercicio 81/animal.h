#ifndef ANIMAL_H_
     #define ANIMAL_H_

     // Forward declaration
     struct animal_t;

     // Memory allocator
     struct animal_t* animal_new();

     // Constructor
     void animal_ctor(struct animal_t*);

     // Destructor
     void animal_dtor(struct animal_t*);

     // Behavior functions
     void animal_get_name(struct animal_t*, char*);
     void animal_sound(struct animal_t*);


     #endif