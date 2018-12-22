#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "graphics.h"
#include "helper.h"

using namespace std;

int hs1,hs2,hs3;
long long i=1;
int a[10]= {0,0,1,0,1,0,0,1,1,0};
char s[][20]= {"2.gif", "3.gif", "0.gif", "1.gif", "4.gif", "5.gif", "6.gif", "7.gif", "8.gif", "9.gif", "10.gif","tbackground.jpg", "background.jpg", "troll.gif", "troll2.gif", "end.jpg", "blast.gif","11.gif","12.gif","13.gif","14.gif","15.gif","16.gif","17.gif","18.gif","19.gif","20.gif","21.gif","22.gif","23.gif"}, ch, p[10], l[10];
int x = 150, y = 410, j, k=0, flag, u = 900,v = 415, point = 0, lives=3, t=1, key,r1=0,n=0,h=0,b=0;

int main()
{
    while(1)
    {
        initwindow(1000, 600, "GAME");
        readimagefile(s[11], 0,0, 1000, 600);
        outtextxy(425, 400, "PRESS ANY KEY TO START");
        getch();
        while(key=menu())
        {
            if(key==1)
            {
                b=0,i = 1, lives = 3, point = k = 0;
                while(i++)
                {
                    j = 0;
                    background1(point, lives, s[12]);
                    readimagefile(s[13+t], u-k,v+h,u+68-k,v+h+60);
                    readimagefile(s[i%4], x, y, x+94, y+70);
                    if(collision(x,y,u,v+h,j,k+30)) lives--, k = 0,b=b+1, t=random(),h=up(a,b);
                    if(lives == 0) i = 0;
                    if(k == 870) k = 0, b=b+1,t=random() ,h=up(a,b);
                    k+=30;
                    delay(10);
                    if(kbhit())
                    {
                        ch=getch();
                        j = 0, flag = 0;
                        if(ch == KEY_UP)
                        {
                            while(j >= 0)
                            {
                                background1(point, lives, s[12]);
                                readimagefile(s[13+t], u-k,v+h,u+68-k,v+h+60);
                                if(flag == 0) readimagefile(s[4], x+10, y-20-j, x+70, y+70-j), j += 25;
                                else readimagefile(s[5], x+10, y-20-j, x+70, y+70-j), j -= 25;
                                if(collision(x,y-20,u,v+h,j,k)) lives--, k = 0,b=b+1, t=random() ,h=up(a,b);
                                if(lives == 0)
                                {
                                    i = 0;
                                    break;
                                }
                                if(k == 870) k = 0,b=b+1, t=random(),h=up(a,b);
                                k+=30;
                                delay(10);
                                if(j>150) flag = 1;
                            }
                        }
                        else if(ch == ' ')
                        {
                            while(j++<=4)
                            {
                                background1(point, lives, s[12]);
                                readimagefile(s[13+t], u-k,v+h,u+68-k,v+h+60);
                                readimagefile(s[5+j], x, y-35, x+172, y+70);
                                if(collision(x,y,u-10,v+h,j,k)) lives--, k = 0,b=b+1, j=650, t=random(),h=up(a,b);
                                if(lives == 0)
                                {
                                    i = 0;
                                    break;
                                }
                                k += 30;
                                delay(10);
                            }
                            while(j < 650)
                            {
                                background1(point, lives, s[12]);
                                readimagefile(s[i++%4], x, y, x+94, y+70);
                                readimagefile(s[13+t], u-k,v+h,u+68-k,v+h+60);
                                readimagefile(s[16], x+100+j, y, x+170+j, y+30);
                                if(collision(x,y,u-10,v+h,j,k)) lives--, k = 0,b=b+1, j=650, t=random(),h=up(a,b);
                                if(enemyhit(x,y,u,v+h,j,k,t))
                                {
                                    if(t==0) point++;
                                    else lives--;
                                    k = 0,b=b+1, j = 650, t=random(),h=up(a,b);
                                }
                                j += 40, k+= 30;
                                if(lives == 0)
                                {
                                    i = 0;
                                    break;
                                }
                                if(k == 870) k = 0,b=b+1, t=random(),h=up(a,b);
                            }
                        }
                        if(ch==KEY_DOWN)
                        {
                            for(n=0; n<13; n++,i++)
                            {
                                if(i%13==0 || i%13==12)
                                {
                                    background1(point, lives, s[12]);
                                    readimagefile(s[17+(i%13)],x, y, x+94, y+70);
                                    readimagefile(s[13+t], u-k,v+h,u+68-k,v+60+h);
                                    if(rcollision(x,y,u,v,j,k+30,h)) lives--,k=0,b=b+1,t=random(),h=up(a,b);
                                    if(lives == 0)
                                    {
                                        i = 0;
                                        break;
                                    }
                                    if(k == 870) k = 0,b=b+1,t=random(),h=up(a,b);
                                    k+=30;
                                    delay(10);
                                }
                                else
                                {

                                    background1(point, lives, s[12]);
                                    readimagefile(s[17+(i%13)],x+5, y, x+94, y+70);
                                    readimagefile(s[13+t], u-k,v+h,u+68-k,v+60+h);
                                    if(rcollision(x+5,y,u,v,j,k+30,h)) lives--,k=0,t=random(),h=up(a,b);
                                    if(lives == 0)
                                    {
                                        i = 0;
                                        break;
                                    }
                                    if(k == 870) k = 0,b=b+1,t=random(),h=up(a,b);
                                    k+=30;
                                    delay(10);
                                }
                            }
                        }
                    }
                }
                readimagefile(s[15], 0,0,1000,600);
                getch();
                scrcheck(point,hs1,hs2,hs3);
            }
            else if(key==2)
            {
                leaderboard();
            }
            else if(key==0)
            {
                break;
            }
        }
        return 0;
    }

    return 0;
}
