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
void print_family_relationships(const Person *yourself)
{
    printf("\n=== FAMILY TREE RELATIONSHIPS ===\n\n");
    printf("1. YOURSELF:\n");
    printf("   - Name: %s | Age: %d\n\n",
           yourself->name, yourself->age);
    printf("2. PARENTS:\n");
    printf("   - Father: %s | Age: %d\n",
           yourself->father->name, yourself->father->age);
    printf("   - Mother: %s | Age: %d\n\n",
           yourself->mother->name, yourself->mother->age);
    printf("3. PATERNAL GRANDPARENTS (via Father's Pointers):\n");
    printf("   - Grandfather: %s | Age: %d\n",
           yourself->father->father->name,
           yourself->father->father->age);
    printf("   - Grandmother: %s | Age: %d\n\n",
           yourself->father->mother->name,
           yourself->father->mother->age);
    printf("4. MATERNAL GRANDPARENTS (via Mother's Pointers):\n");
    printf("   - Grandfather: %s | Age: %d\n",
           yourself->mother->father->name,
           yourself->mother->father->age);
    printf("   - Grandmother: %s | Age: %d\n",
           yourself->mother->mother->name,
           yourself->mother->mother->age);
}
void free_family_tree(Person *people[], int count)
{
    for (int i =0; i < count; i++)
    {
        free(people[i]);
        people[i] = NULL;
    }
}
void print_tree_visual(const Person *root, int level)
{
    (void)level;
    if (root == NULL)
    {
        return;
    }
    printf("%s (Age: %d)\n", root->name, root->age);
    if (root->father != NULL)
    {
        printf("|\n");
        printf("|___ Father: %s (Age: %d)\n",
               root->father->name, root->father->age);
        printf("|    |_______ Grandfather: %s (Age: %d)\n",
               root->father->father->name,
               root->father->father->age);
        printf("|    |\n");
        printf("|    |_______ Grandmother: %s (Age: %d)\n",
               root->father->mother->name,
               root->father->mother->age);
    }
    if (root->mother != NULL)
    {
        printf("|\n");
        printf("|___ Mother: %s (Age: %d)\n",
               root->mother->name, root->mother->age);
        printf("     |_______ Grandfather: %s (Age: %d)\n",
               root->mother->father->name,
               root->mother->father->age);
        printf("     |\n");

        printf("     |_______ Grandmother: %s (Age: %d)\n",
               root->mother->mother->name,
               root->mother->mother->age);
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
printf("\n=== VISUAL FAMILY TREE ===\n\n");
print_tree_visual(people[0], 0);
free_family_tree(people, 7);
return 0;

}