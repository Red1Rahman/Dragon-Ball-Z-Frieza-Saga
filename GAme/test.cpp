#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "graphics.h"
int hs1,hs2,hs3;
void scrcheck(int point)
{
    readimagefile("i1.jpg",0,0,1000,600);
    char name[10]={'\0'};char points[50],ch;
    int f=0,bi=0;
    FILE *n1,*n2,*n3,*h1,*h2,*h3;
    h1=fopen("C:\\Users\\Redoan\\Desktop\\GAme\\HS\\h1.txt","r");
    fscanf(h1,"%d",&hs1);
    fclose(h1);
    h2=fopen("C:\\Users\\Redoan\\Desktop\\GAme\\HS\\h2.txt","r");
    fscanf(h2,"%d",&hs2);
    fclose(h2);
    h3=fopen("C:\\Users\\Redoan\\Desktop\\GAme\\HS\\h3.txt","r");
    fscanf(h3,"%d",&hs3);
    fclose(h3);
    setbkcolor(BLACK);
    setcolor(WHITE);
    settextstyle(BOLD_FONT,HORIZ_DIR,1);
    outtextxy(350,200,"YOUR NAME: ");
    while(f<10)
    {
        if(kbhit)
        {
            ch=getch();
            /*if (ch=KEY_DOWN)
            {
                break;
            }
            if(name[f]=='-')
            {
                name[f]='\0';
                name[f-1]='\0';
                f=f-1;
            }*/
            name[f]=ch;f=f+1;
            readimagefile("i1.jpg",0,0,1000,600);
            outtextxy(350,200,"YOUR NAME: ");
            outtextxy(470,200,name);
        }
    }
    sprintf(points,"%d",point);
    outtextxy(350,300,"YOUR SCORE: ");
    outtextxy(470,300,points);
    getch();
    if(point>hs3)
    {
        if(point>hs2)
        {
            if(point>hs1)
            {
                n1=fopen("C:\\Users\\Redoan\\Desktop\\GAme\\HS\\n1.txt","w");
                fputs(name,n1);
                fclose(n1);
                h1=fopen("C:\\Users\\Redoan\\Desktop\\GAme\\HS\\h1.txt","w");
                fprintf(h1,"%d",point);
                fclose(h1);
                return;
            }
            else
            {
                n2=fopen("C:\\Users\\Redoan\\Desktop\\GAme\\HS\\n2.txt","w");
                fputs(name,n2);
                fclose(n2);
                h2=fopen("C:\\Users\\Redoan\\Desktop\\GAme\\HS\\h2.txt","w");
                fprintf(h2,"%d",point);
                fclose(h2);
                return;
            }
        }
        else
            {
                n3=fopen("C:\\Users\\Redoan\\Desktop\\GAme\\HS\\n3.txt","w");
                fputs(name,n3);
                fclose(n3);
                h3=fopen("C:\\Users\\Redoan\\Desktop\\GAme\\HS\\h3.txt","w");
                fprintf(h3,"%d",point);
                fclose(h3);
                return;
            }
            getch();
    }

    return;
}
main()
{
    initwindow(1000,600,"test");
    readimagefile("i1.jpg",0,0,1000,600);
    int point;
    scanf("%d",&point);
    scrcheck(point);
}
