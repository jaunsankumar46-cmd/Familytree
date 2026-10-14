#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct person {
char name[50];
int age;
struct person *father;
struct person *mother;
} Person;

Person *create_person(const char *name, int age)
{ 
Person *person = malloc(sizeof(Person));
if (person == NULL)
{
printf("memory allocation failed.\n");
return NULL ;
}
snprintf(person->name, sizeof (person->name),"%s",name);
person->age = age;
person->father=NULL;
person->mother=NULL;
return person;
}
