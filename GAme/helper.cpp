#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "graphics.h"
#include "winbgim.h"
#include "helper.h"
int up(int a[],int b)
{
    if(a[b%10]==0) return 0;
    else return -65;
}
void background1(int point, int lives, char s1[])
{
    char p[10], l[10];
    itoa(point, p, 10);
    itoa(lives, l, 10);
    readimagefile(s1, 0,0, 1000, 600);
    outtextxy(160,90, "Points:  ");
    outtextxy(212,90, p);
    outtextxy(750,90, "Lives: ");
    outtextxy(798,90, l);
}

bool collision(int x, int y, int u, int v, int j, int k)
{
    if(u-k-x-65 <= 0 && u-k+60-x-10 >= 0 && v-y-80+j <= 0)
    {
        outtextxy(x+45, y-j-80, " -1 ");
        delay(80);
        return true;
    }
    return false;
}
bool rcollision(int x, int y, int u, int v, int j, int k,int h)
{
    if(u-k-x-65 <= 0 && u-k+60-x-10 >= 0 && v+h-y+j >= 0)
    {
        outtextxy(x+45, y-j-80, " -1 ");
        delay(80);
        return true;
    }
    return false;
}
bool enemyhit(int x, int y, int u, int v, int j, int k, int t)
{
    if(u-k-x-170-j <= 0 && u+60-k-x-100-j >= 0)
    {
        if(t==1)
        {
            outtextxy(u-k+20,v-50," -1 ");
            delay(80);
        }
        else delay(50);
        return true;
    }
    return false;
}

int random()
{
    srand(time(NULL));
    return rand()%2;
}

int menu()
{
    int x, y;
    readimagefile("b2.jpg",0,0,1000,600);
    readimagefile("m1.gif",400,175,600,200);
    readimagefile("m2.gif",375,275,625,300);
    readimagefile("m3.gif",375,375,625,400);
    readimagefile("m4.gif",425,475,550,500);
    while(1)
    {
        while(!ismouseclick(WM_LBUTTONDOWN));
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if(x>=400 && x<=600 && y>=175 && y<=200)
        {
            readimagefile("b2.jpg",0,0,1000,600);
            readimagefile("m11.gif",400,175,600,200);
            readimagefile("m2.gif",375,275,625,300);
            readimagefile("m3.gif",375,375,625,400);
            readimagefile("m4.gif",425,475,550,500);
            delay(100);
            return 1;
        }
        else if(x>=375 && x<=625 && y>=275 && y<=300)
            {
            readimagefile("b2.jpg",0,0,1000,600);
        readimagefile("m1.gif",400,175,600,200);
        readimagefile("m22.gif",375,275,625,300);
        readimagefile("m3.gif",375,375,625,400);
        readimagefile("m4.gif",425,475,550,500);
        return 2;
            }
        /*else if(x>=375 && x<=625 && y>=375 && y<=400)
            {
            readimagefile("b2.jpg",0,0,1000,600);
        readimagefile("m1.gif",400,175,600,200);
        readimagefile("m2.gif",375,275,625,300);
        readimagefile("m33.gif",375,375,625,400);
        readimagefile("m4.gif",425,475,550,500);
        return 3;
        }*/
        else if(x>=425 && x<=550 && y>=475 && y<=500)
        {
            readimagefile("b2.jpg",0,0,1000,600);
            readimagefile("m1.gif",400,175,600,200);
            readimagefile("m2.gif",375,275,625,300);
            readimagefile("m3.gif",375,375,625,400);
            readimagefile("m44.gif",425,475,550,500);
            delay(100);
            return 0;
        }
    }
}
void scrcheck(int point,int hs1,int hs2,int hs3)
{
    readimagefile("i1.jpg",0,0,1000,600);
    char name[10]={'\0'};char points[50];
    int f=0;
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
            name[f]=getch();
            /*if (name[f]=KEY_DOWN)
            {
                break;
            }
            if(name[f]=='x')
            {
                name[f]='\0';
                name[f-1]='\0';
                f=f-1;
            }*/
            readimagefile("i1.jpg",0,0,1000,600);
            outtextxy(350,200,"YOUR NAME: ");
            outtextxy(460,200,name);
            f=f+1;
        }
    }
    sprintf(points,"%d",point);
    outtextxy(350,300,"YOUR SCORE: ");
    outtextxy(480,300,points);
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
void leaderboard()
{
    readimagefile("i3.jpg",0,0,1000,600);
    char name1[10],name2[10],name3[10],sc1[50],sc2[50],sc3[50];FILE *n1,*n2,*n3,*h1,*h2,*h3;int hs1,hs2,hs3;
    setbkcolor(BLACK);
    setcolor(YELLOW);
    settextstyle(BOLD_FONT ,HORIZ_DIR,4);
    outtextxy(350,100,"HIGH SCORES");
    n1=fopen("C:\\Users\\Redoan\\Desktop\\GAme\\HS\\n1.txt","r");
    fgets(name1,sizeof(name1),n1);
    outtextxy(300,200,name1);
    fclose(n1);
    h1=fopen("C:\\Users\\Redoan\\Desktop\\GAme\\HS\\h1.txt","r");
    fscanf(h1,"%d",&hs1);
    fclose(h1);
    sprintf(sc1,"%d",hs1);
    outtextxy(500,200,sc1);
    n2=fopen("C:\\Users\\Redoan\\Desktop\\GAme\\HS\\n2.txt","r");
    fgets(name2,sizeof(name2),n2);
    outtextxy(300,300,name2);
    fclose(n2);
    h2=fopen("C:\\Users\\Redoan\\Desktop\\GAme\\HS\\h2.txt","r");
    fscanf(h2,"%d",&hs2);
    fclose(h2);
    sprintf(sc2,"%d",hs2);
    outtextxy(500,300,sc2);
    n3=fopen("C:\\Users\\Redoan\\Desktop\\GAme\\HS\\n3.txt","r");
    fgets(name3,sizeof(name3),n3);
    outtextxy(300,400,name3);
    fclose(n3);
    h3=fopen("C:\\Users\\Redoan\\Desktop\\GAme\\HS\\h3.txt","r");
    fscanf(h3,"%d",&hs3);
    fclose(h3);
    sprintf(sc3,"%d",hs3);
    outtextxy(500,400,sc3);
    getch();
}
