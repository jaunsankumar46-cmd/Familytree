#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Person
{
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
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
void link_parents(Person *child, Person *father, Person *mother)
{
    child->father = father;
    child->mother = mother;
}
void read_person_info(const char *role, char *namept, int *agept)
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
void print_family_relationships(const Person *me)
{
printf("\n=============\n FAMILY TREE \n=============\n");
printf("me : %s, Age : %d\n",me->name,me->age);
printf("Father : %s, Age : %d\n",me->father->name,me->father->age);
printf("mother : %s, Age : %d\n",me->mother->name,me->mother->age);
printf("Paternal grandfather : %s, Age : %d\n", me->father->father->name,me->father->father->age);
printf("Paternal grandmother : %s, Age : %d\n",me->father->mother->name,me->father->mother->age);
printf("Maternal grandfather : %s, Age : %d\n", me->mother->father->name,me->mother->father->age);
printf("Maternal grandmother : %s, Age : %d\n",me->mother->mother->name,me->mother->mother->age);
}
void free_family_tree(Person *people[], int count)
{
    for (int i =0; i < count; i++)
    {
        free(people[i]);
        people[i] = NULL;
    }
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
        read_person_info(roles[i],name,&age);
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
link_parents(people[0],people[1],people[2]);
link_parents(people[1],people[3],people[4]);
link_parents(people[2],people[5],people[6]);

print_family_relationships(people[0]);
free_family_tree(people, 7);
return 0;

}