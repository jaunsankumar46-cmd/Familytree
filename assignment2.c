#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Taxon{
    char name[50];
    int lifespan;
    struct Taxon *parent_group;
}Taxon;

