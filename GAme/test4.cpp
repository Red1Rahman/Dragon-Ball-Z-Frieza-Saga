#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "graphics.h"
struct f
{
    char name[10];
    int points;
};
main()
{
    initwindow(1000,600,"test4");
    readimagefile("i1.jpg",0,0,1000,600);
    char player[10]= {'\0'};
    char points1[50];
    int f=0;
    struct f en[3];
    FILE *f1;
    int i;
    /*for(i=0;i<3;i++)
    {
        en[i].name={'\0'};
    }*/
    f1=fopen("C:\\Users\\Redoan\\Desktop\\GAme\\HS\\f1.txt","r");
    for(i=0; i<3; i++)
    {
        fscanf(f1,"%s %d",&en[i].name,&en[i].points);
    }
    fclose(f1);
    int point;
    scanf("%d",&point);
    setbkcolor(BLACK);
    setcolor(WHITE);
    settextstyle(BOLD_FONT,HORIZ_DIR,1);
    outtextxy(350,200,"YOUR NAME: ");
    for(f=0; f<10; f++)
        if(kbhit)
        {
            player[f]=getch();
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
            readimagefile("i1.jpg",0,0,1000,600);
            outtextxy(350,200,"YOUR NAME: ");
            outtextxy(470,200,player);
        }

    sprintf(points1,"%d",point);
    outtextxy(350,300,"YOUR SCORE: ");
    outtextxy(470,300,points1);
    getch();
    for(i=0;i<3;i++)
    {
        printf("%s %d\n",en[i].name,en[i].points);
    }
    if(point>en[2].points)
    {
        if(point>en[1].points)
        {
            if(point>en[0].points)
            {
                f1=fopen("C:\\Users\\Redoan\\Desktop\\GAme\\HS\\f1.txt","w");
                strcpy(player,en[0].name);
                en[0].points=point;
                for(i=0; i<3; i++)
                {
                    fprintf(f1,"%s %d\n",en[i].name,en[i].points);
                }
                fclose(f1);
                return 0;
            }
            else
            {
                f1=fopen("C:\\Users\\Redoan\\Desktop\\GAme\\HS\\f1.txt","w");
                strcpy(player,en[1].name);
                en[1].points=point;
                for(i=0; i<3; i++)
                {
                    fprintf(f1,"%s %d\n",en[i].name,en[i].points);
                }
                fclose(f1);
                return 0;
            }
        }
        else
        {
            f1=fopen("C:\\Users\\Redoan\\Desktop\\GAme\\HS\\n1.txt","w");
            strcpy(player,en[2].name);
            en[2].points=point;
            for(i=0; i<3; i++)
            {
                fprintf(f1,"%s %d\n",en[i].name,en[i].points);
            }
            fclose(f1);
            return 0;
        }
        getch();
    }

    return 0;
}
