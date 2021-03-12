 #ifndef DUCK_H_
     #define DUCK_H_

     // Forward declaration
     struct duck_t;

     // Memory allocator
     struct duck_t* duck_new();

     // Constructor
     void duck_ctor(struct duck_t*);

     // Destructor
     void duck_dtor(struct duck_t*);

     // All behavior functions are inherited from the animal class.


     #endif