#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Taxon{
    char name[50];
    int lifespan;
    struct Taxon *parent_group;
}Taxon;
Taxon*create(const char *name, int lifespan)
{
    struct create_tason() = malloc(sizeof(struct Taxon));
    parent_group=NULL;
}
void read_taxon_info(const char *label, char name_out, int *lifrspan_out)
{
    printf("enter name species:")
    scanf("%d",&Taxon->name);
}
void link_parents(Taxon *child, Taxon *parent)
{
    child->parent_group = parent;
}
void print_taxonomy(Taxon *species_lists[], int species_count)
{
    printf("");
}
int main()
{
    create_tason(const char *name, int lifespan);
    read_tason_info(const *label, char *name_out,int *lifespan_out);
    link_parents(Taxon *child, Taxon *parent);
}