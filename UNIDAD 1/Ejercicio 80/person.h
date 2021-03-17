#ifndef PERSON_H_
#define PERSON_H_

struct person_t;

struct person_t* person_new();

void person_ctor(struct person_t*,
const char*,
const char*,
unsigned int );

void person_dtor(struct person_t*);

void person_get_first_name(struct person_t*, char*);
void person_get_last_name(struct person_t*, char*);
unsigned int person_get_birth_year(struct person_t*);

#endif