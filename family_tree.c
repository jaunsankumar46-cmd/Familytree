
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Person {
    char name[50];
    int age;
    struct Person *father;
    struct Person *mother;
} Person;
Person *create_person(const char *name, int age);
void read_person_info(const char *role, char *name_out, int *age_out);
Person *create_person(const char *name, int age)
{
    Person *person = malloc(sizeof(Person));
    if (person == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(person->name, name, sizeof(person->name) - 1);
    person->name[sizeof(person->name) - 1] = '\0';
    person->age = age;
    person->father = NULL;
    person->mother = NULL;
    return person;
}
void person_info(const char *role, char *name_out, int *age_out)
{
    printf("\nEnter name for %s: ", role);
    if (fgets(name_out, 50, stdin) == NULL) {
        printf("Input error.\n");
        exit(EXIT_FAILURE);
    }
    name_out[strcspn(name_out, "\n")] = '\0';
    printf("Enter age for %s: ", role);
    while (scanf("%d", age_out) != 1 || *age_out < 0) {
        printf("Invalid age. Enter a non-negative integer: ");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
        }
    }
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}
int main(void)
{
    char name[7][50];
    int age[7];
    const char *roles[7] = {
        "Yourself",
        "Mother",
        "Father",
        "Paternal Grandfather",
        "Paternal Grandmother",
        "Maternal Grandfather",
        "Maternal Grandmother",
    };
    Person *people[7];
    for (int i = 0; i < 7; i++)
     {
        person_info(roles[i], name[i], &age[i]);
        people[i] = create_person(name[i], age[i]);
    }
    printf("\n=== FAMILY MEMBERS ENTERED ===\n");
    for (int i = 0; i < 7; i++) {
        printf("%s: %s, Age: %d\n",
               roles[i], people[i]->name, people[i]->age);
    }
    for (int i = 0; i < 7; i++) {
        free(people[i]);
    }
    return 0;
}
