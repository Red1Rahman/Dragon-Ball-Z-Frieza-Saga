#include <cstdio>
struct f
{
    char name[10];
    int point;
};
main
{
    FILE *f1;char s[10];int a;
    f1=fopen("C:\\Users\\Redoan\\Desktop\\GAme\\test3.cpp","r");
    fscanf(f1,"%s %d",&s,&d);
    printf("%s %d",s,d);
    return 0;
}
