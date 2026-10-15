#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct person
{
    char name[50];
    int age;
    struct person *father;
    struct person *mother;
}Person;
Person *create_person(const char *name, int age)
{
    Person *person = malloc(sizeof(Person));
    if (person == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    snprintf(person->name,sizeof(person->name),"%s",name);
    person->age = age;
    person->father = NULL;
    person->mother = NULL;
    return person;
}
void personinfo(const char *role, char *namept, int *agept)
{
    printf("Enter name of %s: ", role);
    if (fgets(namept, 50, stdin) == NULL)
    {
        printf("Invalid name.\n");
        exit(EXIT_FAILURE);
    }
    namept[strcspn(namept, "\n")] = '\0';
    printf("Enter age of %s: ", role);
    if (scanf("%d", agept) != 1 || *agept < 0)
    {
        printf("Invalid age.\n");
        exit(EXIT_FAILURE);
    }
    getchar();
}
int main(void)
{
    Person *people[7] = {NULL};
    const char *roles[7] = {
        "Yourself",
        "Father",
        "Mother",
        "Paternal grandfather",
        "Paternal grandmother",
        "Maternal grandfather",
        "Maternal grandmother"
        
    };
    char name[50];
    int age;
    for(int i = 0; i<7;i++)
    {
        personinfo(roles[i],name,&age);
        people[i] = create_person(name, age);
        if (people[i] == NULL)
        {
            for ( int j = 0; j< i; j++)
            {
                free(people[j]);
            }
            return 1;
    }
}
printf("\n__________________________\n FAMILY MEMBERS \n________________________\n");
for (int i = 0; i < 7; i++)
{
    printf("%s: %s, Age: %d\n",roles[i],people[i]->name,people[i]->age);
}
for (int i = 0; i < 7;i++)
{
    free(people[i]);
    people[i] = NULL;
}
return 0;
}