#include <iostream>
#include <winbgim.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <MMsystem.h>
#include <windows.h>

using namespace std;
int culoare,acastigat,reset=0,joc_nou=1;
int matrice_de_adiacenta[17][17];
FILE *fp;
void  fundal()
{
    setfillstyle(1,10);
    bar(0,0,400,400);
}
void salveaza_joc(int tip_nivel,int tip_joc,int jucator)
{
    int i,j,k=4;
    fp=fopen("matrice.txt","w+");
    char buff[256];
    buff[0]=tip_nivel+'0';
    buff[1]=tip_joc+'0';
    buff[2]=jucator+'0';
    buff[3]=culoare+'0';
    for(i=1;i<=tip_nivel;i++)
        for(j=1;j<=tip_nivel;j++)
    {
        buff[k]=matrice_de_adiacenta[i][j]+'0';
        k++;
    }
    buff[k]=NULL;
    fprintf(fp,"%s",buff);
    fclose(fp);
}
void setari()
{
    fundal();
    setbkcolor(10);
    settextstyle(0,0,5);
    outtextxy(100,0,"IMPAS");
    settextstyle(0,0,2);
    outtextxy(145,140,"MUZICA");
    outtextxy(175,170,"ON");rectangle(165, 165,215,185);
    outtextxy(170,200,"OFF");rectangle(160, 195,220,215);
    outtextxy(300,350,"INAPOI");
    rectangle(295,350,385,365);

}
void meniu1l()
{
    fundal();
    settextstyle(0,0,5);
    setbkcolor(10);
    outtextxy(100,0,"IMPAS");
    settextstyle(0,0,2);
    setbkcolor(10);
   outtextxy(145,100,"JOC NOU");rectangle(140,95,248,120);
    setbkcolor(10);
    outtextxy(110,135,"CONTINUA JOC");rectangle(105,130,283,155);
    setbkcolor(10);
    outtextxy(150,170,"SETARI");rectangle(145,165,240,190);
    outtextxy(300,350,"IESIRE");
    rectangle(295,350,385,365);


}

void Scrie_meniu_principal()
{
    fundal();
    settextstyle(0,0,5);
    setbkcolor(10);
    outtextxy(100,0,"IMPAS");
    settextstyle(0,0,2);
    setbkcolor(10);
    outtextxy(75,100,"ALEGE MODUL DE JOC");
    setbkcolor(10);
    outtextxy(80,175,"PLAYER VS PLAYER");
    rectangle(75,175,310,190);
    setbkcolor(10);
    outtextxy(100,200,"PLAYER VS PC");
    rectangle(95,200,270,215);
    setbkcolor(10);
    outtextxy(300,350,"IESIRE");
    rectangle(295,350,385,365);
}
void reguli_joc()
{

    initwindow(400,400);
    fundal();
    settextstyle(0,0,5);
    setbkcolor(10);
    outtextxy(100,0,"IMPAS");
    settextstyle(0,0,2);
    setbkcolor(10);
    outtextxy(94,80,"REGULILE JOCULUI");
    setbkcolor(10);
    outtextxy(35,135,"Regulile jocului sunt:");
    setbkcolor(10);
    outtextxy(15,155,"alege  bila si clickeaza ");
    setbkcolor(10);
    outtextxy(15,175,"in locul in care doresti ");
    setbkcolor(10);
    outtextxy(15,195,"sa o muti. Computerul va ");
    setbkcolor(10);
    outtextxy(15,215,"face acelasi lucru,dar el");
    setbkcolor(10);
    outtextxy(15,235,"muta bilele spre dreapta, ");
    setbkcolor(10);
    outtextxy(15,255,"iar tu muti bilele în sus.");
    setbkcolor(10);
    outtextxy(35,275,"Jucatorul care nu mai ");
    setbkcolor(10);
    outtextxy(15,295,"poate muta intra in impas ");
    setbkcolor(10);
    outtextxy(15,315,"si pierde. ");
    setbkcolor(10);
    rectangle(290,360,380,395);
    outtextxy(297,367,"ENTER");
    setbkcolor(10);
    rectangle(20,360,110,395);
    outtextxy(25,367,"INAPOI");

}
void Scrie_meniu_alegere_tabla()
{
    initwindow(400,400);
    fundal();
    setbkcolor(10);
    settextstyle(0,0,5);
    outtextxy(100,0,"IMPAS");
    settextstyle(0,0,2);
    outtextxy(65,100,"ALEGE TIPUL DE TABLA");
    outtextxy(47,120,"(numar <=15 si >=4)");
    setfillstyle(1,10);
    bar(170,140,230,200);

    rectangle(120,200,150,230);
    outtextxy(127,207,"1");
    rectangle(170,200,200,230);
    outtextxy(177,207,"2");
    rectangle(220,200,250,230);
    outtextxy(227,207,"3");
    rectangle(120,250,150,280);
    outtextxy(127,257,"4");
    rectangle(170,250,200,280);
    outtextxy(177,257,"5");
    rectangle(220,250,250,280);
    outtextxy(227,257,"6");
    rectangle(120,300,150,330);
    outtextxy(127,307,"7");
    rectangle(170,300,200,330);
    outtextxy(177,307,"8");
    rectangle(220,300,250,330);
    outtextxy(227,307,"9");
    rectangle(170,350,200,380);
    outtextxy(177,357,"0");
    rectangle(290,360,380,395);
    outtextxy(297,367,"ENTER");
    rectangle(20,360,110,395);
    outtextxy(25,367,"INAPOI");
    settextstyle(0,0,1);
    rectangle(220,350,250,380);
    outtextxy(225,367,"DEL");

}
void alege_culoare_tabla()
{
    initwindow(400,400);
    fundal();
    setbkcolor(10);
    settextstyle(0,0,5);
    outtextxy(100,0,"IMPAS");
    rectangle(120,200,150,230);
    settextstyle(0,0,2);
    outtextxy(60,100,"ALEGE CULOAREA TABLEI");
    outtextxy(70,120,"(numar >=1 si <=9)");
    setfillstyle(1,1);
    setbkcolor(1);
    bar(120,200,150,230);
    outtextxy(127,207,"1");
    setbkcolor(2);
    setfillstyle(1,2);
    bar(170,200,200,230);
    outtextxy(177,207,"2");
    setbkcolor(3);
    setfillstyle(1,3);
    bar(220,200,250,230);
    outtextxy(227,207,"3");
    setbkcolor(4);
    setfillstyle(1,4);
    bar(120,250,150,280);
    outtextxy(127,257,"4");
    setbkcolor(5);
    setfillstyle(1,5);
    bar(170,250,200,280);
    outtextxy(177,257,"5");
    setbkcolor(6);
    setfillstyle(1,6);
    bar(220,250,250,280);
    outtextxy(227,257,"6");
    setbkcolor(7);
    setfillstyle(1,7);
    bar(120,300,150,330);
    outtextxy(127,307,"7");
    setbkcolor(8);
    setfillstyle(1,8);
    bar(170,300,200,330);
    outtextxy(177,307,"8");
    setbkcolor(9);
    setfillstyle(1,9);
    bar(220,300,250,330);
    outtextxy(227,307,"9");
    setbkcolor(10);
    setfillstyle(1,BLACK);
    rectangle(290,360,380,395);
    outtextxy(297,367,"ENTER");
    rectangle(20,360,110,395);
    outtextxy(25,367,"INAPOI");
    settextstyle(0,0,1);
    rectangle(220,350,250,380);
    outtextxy(225,367,"DEL");
}
void castigator1()
{
    fundal();
    settextstyle(0,0,5);
    outtextxy(100,0,"IMPAS");
    //rectangle(120,200,150,230);
    settextstyle(0,0,2);
    outtextxy(30,100,"CASTIGATORUL JOCULUI ESTE ");
    settextstyle(0,0,4);
outtextxy(60,150,"PLAYER 1");


}
void castigator2()
{
    fundal();
    settextstyle(0,0,5);
    outtextxy(100,0,"IMPAS");
    //rectangle(120,200,150,230);
    settextstyle(0,0,2);
    outtextxy(30,100,"CASTIGATORUL JOCULUI ESTE ");
    settextstyle(0,0,5);
outtextxy(60,150,"PLAYER 2");


}
void castigator_calculator()
{
    fundal();
    settextstyle(0,0,5);
    outtextxy(100,0,"IMPAS");
    //rectangle(120,200,150,230);
    settextstyle(0,0,2);
    outtextxy(30,100,"CASTIGATORUL JOCULUI ESTE ");
    settextstyle(0,0,3);
outtextxy(60,150,"CALCULATORUL");

}

int Calcul_tabla(int x,int y,int &suma)
{
    if(x>=120&&x<=150&&y>=200&&y<=230)
    {
        suma=suma*10+1;
    }
    if(x>=170&&x<=200&&y>=200&&y<=230)
    {
        suma=suma*10+2;
    }
    if(x>=220&&x<=250&&y>=200&&y<=230)
    {
        suma=suma*10+3;
    }
    if(x>=120&&x<=150&&y>=250&&y<=280)
    {
        suma=suma*10+4;
    }
    if(x>=170&&x<=200&&y>=250&&y<=280)
    {
        suma=suma*10+5;
    }
    if(x>=220&&x<=250&&y>=250&&y<=280)
    {
        suma=suma*10+6;
    }
    if(x>=120&&x<=150&&y>=300&&y<=330)
    {
        suma=suma*10+7;
    }
    if(x>=170&&x<=200&&y>=300&&y<=330)
    {
        suma=suma*10+8;
    }
    if(x>=220&&x<=250&&y>=300&&y<=330)
    {
        suma=suma*10+9;
    }
    if(x>=170&&x<=200&&y>=350&&y<=380)
        suma=suma*10;

    if(x>=220&&x<=250&&y>=350&&y<=395)
    {
        suma=suma/10;
    }
    if(suma>15)
        suma=suma/10;
}

void meniu(int &tip_joc,int &tip_tabla)
{
    int selectat=0,a=1;
    int x,y;
    int suma=0;

    while (a==1)
    {

        if(a==1)
        {
            x=-1;
            y=-1;
            closegraph();
            initwindow(400,400);
            meniu1l();
            selectat=0;
            while(selectat==0)
            {
                if(ismouseclick(WM_LBUTTONDOWN))
                {

                    clearmouseclick(WM_LBUTTONDOWN);
                    x=mousex();
                    y=mousey();
                }
                if(x>=140&&x<=248&&y>=95&&y<=120)
                {Beep(500,500);
                    selectat=1;
                    a=5;
                }
                if(x>=105&&x<=283&&y>=130&&y<=155)
                {Beep(500,500);
                    selectat=1;
                    a=6;
                }
                if(x>=145&&x<=240&&y>=165&&y<=190)//setari
                {Beep(500,500);

                    selectat=1;
                    a=7;
                }
                 if(x>=295&&x<=385&&y>=350&&y<=365)//iesire
                {Beep(500,500);
                    tip_joc=0;
                    selectat=1;
                    exit(1);
                }


            }

        }
        if(a==5)
        {
            x=-1;
            y=-1;
            closegraph();
            initwindow(400,400);
            Scrie_meniu_principal();
            selectat=0;
            while(selectat==0)
            {
                if(ismouseclick(WM_LBUTTONDOWN))
                {

                    clearmouseclick(WM_LBUTTONDOWN);
                    x=mousex();
                    y=mousey();
                }
                if(x>=75&&x<=310&&y>=175&&y<=190)
                {Beep(500,500);
                    tip_joc=1;
                    selectat=1;
                    a=2;
                }
                if(x>=95&&x<=270&&y>=200&&y<=215)
                {Beep(500,500);
                    tip_joc=2;
                    selectat=1;
                    a=2;
                }
                if(x>=295&&x<=385&&y>=350&&y<=365)
                {Beep(500,500);
                    selectat=1;
                    a=1;

                }


            }

        }
        if(a==6)
        {
            x=-1;y=-1;
            joc_nou=0;
            a=0;
            closegraph();
        }

        if(a==7)
        {
            x=-1;y=-1;
            closegraph();
            initwindow(400,400);
            setari();
            selectat=0;
            while(selectat==0)
            {
                if(ismouseclick(WM_LBUTTONDOWN))
                {

                    clearmouseclick(WM_LBUTTONDOWN);
                    x=mousex();
                    y=mousey();
                }
                if(x>=160&&x<=220&&y>=195&&y<=215)
                {Beep(500,500);
                    waveOutSetVolume(NULL, 0);

                }
                if(x>=165&&x<=215&&y>=165&&y<=185)
                {Beep(500,500);
                    waveOutSetVolume(NULL, 0xFFFF);

                }
               if(x>=295&&x<=385&&y>=350&&y<=365)
                {Beep(500,500);
                    selectat=1;
                    a=1;

                }

            }

        }

        if(a==2)
        {

            x=-1;
            y=-1;
            closegraph();
            selectat=0;
            Scrie_meniu_alegere_tabla();
            suma=0;
            settextstyle(0,0,2);
            char c[2];
            while(selectat==0)
            {
                if(ismouseclick(WM_LBUTTONDOWN))
                {
                    clearmouseclick(WM_LBUTTONDOWN);
                    x=mousex();
                    y=mousey();
                }
                Calcul_tabla(x,y,suma);
                if(suma>=0)
                {
                    c[0]=suma/10+'0';
                    c[1]=suma%10+'0';
                    outtextxy(180,147,c);

                }
                if(suma>=4)
                    if(x>=290&&x<=380&&y>=360&&y<=395)
                    {Beep(500,500);
                        a=3;
                        selectat=1;
                        tip_tabla=suma;
                        closegraph();

                    }
                if(x>=20&&x<=110&&y>=360&&y<=395)
                {Beep(500,500);
                    a=1;
                    selectat=1;
                    tip_joc=-1;
                    closegraph();
                }
                x=-1;
                x=-1;

            }
            if(a==3)
            {
                x=-1;
                y=-1;
                closegraph();
                selectat=0;
                alege_culoare_tabla();
                int p=0;
                settextstyle(0,0,2);
                char d[2];
                while(selectat==0)
                {
                    if(ismouseclick(WM_LBUTTONDOWN))
                    {
                        clearmouseclick(WM_LBUTTONDOWN);
                        x=mousex();
                        y=mousey();
                    }
                    Calcul_tabla(x,y,p);
                    if(p>=0)
                    {
                        d[0]=p/10+'0';
                        d[1]=p%10+'0';
                        outtextxy(180,147,d);

                    }

                    if(x>=290&&x<=380&&y>=360&&y<=395)
                    {Beep(500,500);
                        a=4;
                        selectat=1;
                        closegraph();

                    }
                    if(x>=20&&x<=110&&y>=360&&y<=395)
                    {Beep(500,500);
                        a=1;
                        selectat=1;
                        closegraph();
                    }
                    x=-1;
                    x=-1;


                }
                culoare=p;
            }
            if(a==4)
            {
                reguli_joc();
                selectat=0;
                while(selectat==0)
                {
                    if(ismouseclick(WM_LBUTTONDOWN))
                    {
                        clearmouseclick(WM_LBUTTONDOWN);
                        x=mousex();
                        y=mousey();
                    }

                    if(x>=290&&x<=380&&y>=360&&y<=395)
                    {Beep(500,500);
                        a=4;
                        selectat=1;
                        tip_tabla=suma;
                        closegraph();
                    }
                    if(x>=20&&x<=110&&y>=360&&y<=395)
                    {Beep(500,500);
                        a=1;
                        selectat=1;
                        tip_joc=-1;
                        closegraph();
                    }
                    x=-1;
                    x=-1;


                }
            }


        }

    }
}

void init_matrice(int &tip_tabla,int &tip_joc,int &jucator)
{
    int i,j;
    if(joc_nou)
    {
        for(i=1; i<=tip_tabla; i++)
        for(j=1; j<=tip_tabla; j++)
            matrice_de_adiacenta[i][j]=0;
    for(i=0; i<=tip_tabla+1; i++)
    {
        matrice_de_adiacenta[0][i]=1;
        matrice_de_adiacenta[i][0]=1;
        matrice_de_adiacenta[tip_tabla+1][i]=1;
        matrice_de_adiacenta[i][tip_tabla+1]=1;
    }
    for(i=tip_tabla/2+tip_tabla%2+1;i<=tip_tabla;i++)
        for(j=1;j<=tip_tabla/2;j++)
        matrice_de_adiacenta[i][j]=1;
    }
    else
    {

        fp=fopen("matrice.txt","r");
        char buff[256];
        int k=4;
        fscanf(fp,"%s",buff);
    tip_tabla=buff[0]-'0';
    tip_joc=buff[1]-'0';
    jucator=buff[2]-'0';
    culoare=buff[3]-'0';
    for(i=1;i<=tip_tabla;i++)
    {
        for(j=1;j<=tip_tabla;j++)
    {

        matrice_de_adiacenta[i][j]=buff[k]-'0';
        k++;
    }
    }
    fclose(fp);
    for(i=0; i<=tip_tabla+1; i++)
    {
        matrice_de_adiacenta[0][i]=1;
        matrice_de_adiacenta[i][0]=1;
        matrice_de_adiacenta[tip_tabla+1][i]=1;
        matrice_de_adiacenta[i][tip_tabla+1]=1;
    }
    }


}
void init_tabla(int tip_tabla)
{
    //int n=800/tip_tabla*tip_tabla;// sa nu uiti sa schimbi pe 800
    int n=800,i,j;// sa nu uiti sa schimbi pe 800


        initwindow(n,n+100);
        setcolor(WHITE);
        setfillstyle(1,culoare);
        bar(0,0,n,n);
        for(int d=0; d<=n; d=d+n/tip_tabla)
        {

            line(d,0,d,n);
            line(0,d,n,d);
        }
        rectangle(0,0,n,n);

    settextstyle(0,0,2);
    setcolor(WHITE);
    rectangle( 680, 840,780,875);
    outtextxy(690,850,"IESIRE");
    rectangle(15,840,105,875);
    outtextxy(25,850,"RESET");
    n=400/tip_tabla;
    for(i=1;i<=tip_tabla;i++)
        for(j=1;j<=tip_tabla;j++)
    {
        setfillstyle(1,culoare);
                    bar(j*2*n-2*n,i*2*n-2*n,j*2*n,i*2*n);
                    rectangle(j*2*n-2*n,i*2*n-2*n,j*2*n,i*2*n);
    }
    n=2*n*tip_tabla;
    setfillstyle(1,BLACK);
    bar(1,n+1,801,801);
    bar(n+1,0,801,801);
  }

void init_pioni(int tip_tabla)
{
    int n=400/tip_tabla,i,j;
setfillstyle(1,WHITE);
    for(int i=1; i<=tip_tabla; i++)
    {

        for(int j=1; j<=tip_tabla; j++)
        {
            if(matrice_de_adiacenta[i][j]==1)

            fillellipse(j*2*n-n,i*2*n-n,n/2,n/2);
        }
    }
}
void initializare_nivel(int &tip_tabla,int &tip_joc,int &jucator)
{
    init_matrice(tip_tabla,tip_joc,jucator);
    init_tabla(tip_tabla);

    init_pioni(tip_tabla);
    }
void afisare (int a)//p
{
    setfillstyle(1,BLACK);
    bar(340,850,550,950);
    settextstyle(0,0,2);
    if (a==1)
        outtextxy(340,850,"PLAYER 1");
    if(a==2)
    outtextxy(340,850,"PLAYER 2");

}
void afisare1(int a)
{
    setfillstyle(1,BLACK);
    bar(240,810,550,950);
    settextstyle(0,0,2);
    if (a==1)
        outtextxy(340,850," PLAYER 1  ");
        else
        outtextxy(305,850,"CALCULATORUL");
}
int conditie_salt1(int x_schimbat, int y_schimbat, int y_schimbabil)
{
    for(int i=y_schimbabil-1; i>=y_schimbat; i--)
        if(matrice_de_adiacenta[i][x_schimbat]==1)
            return 0;
    return 1;
}
int conditie_salt2(int y_schimbat, int x_schimbat, int x_schimbabil)
{
    for(int i=x_schimbabil+1; i<=x_schimbat; i++)
        if(matrice_de_adiacenta[y_schimbat][i]==1)
            return 0;
    return 1;
}
int exista_mutari_posibile(int jucator,int tip_tabla)
{
    int i,j;
    if(jucator==1)
    {
        for(i=1; i<=tip_tabla; i++)
            for(j=1; j<=tip_tabla; j++)
                if(matrice_de_adiacenta[i][j]==1 and matrice_de_adiacenta[i-1][j]==0)
                    return 1;
    }
    else
    {
        for(i=1; i<=tip_tabla; i++)
            for(j=1; j<=tip_tabla; j++)
                if(matrice_de_adiacenta[i][j]==1 and matrice_de_adiacenta[i][j+1]==0)
                    return 1;
    }
    return 0;
}
void PvP(int tip_tabla,int tip_joc,int jucator)
{

    int selectat=0,x_schimbabil=-1,x_schimbat=-1,y_schimbabil=-1,y_schimbat=-1;
    int n=400/tip_tabla;
    int Jocul_continua=1;
    int selectat1=0,a=1;
    int x,y;

    while(Jocul_continua)
    {
        selectat=0;
        if(!exista_mutari_posibile(jucator,tip_tabla))
        {
        Jocul_continua=0;
        closegraph();
         initwindow(400,400);
        if(acastigat==1)
        castigator1();
            else
        castigator2();
        while(selectat==0)
        {
            if(ismouseclick(WM_LBUTTONDOWN))
                    {
                        clearmouseclick(WM_LBUTTONDOWN);
                        selectat=1;
                    }
        }

        }
        else
        {
            if(jucator==1)
            {
                afisare(jucator);
                while(selectat!=2 and Jocul_continua)
                {
                    if(ismouseclick(WM_LBUTTONDOWN) and selectat==0)
                    {
                        clearmouseclick(WM_LBUTTONDOWN);
                        if(mousex()>=680&&mousex()<=780&&mousey()>=840&&mousey()<=875){Jocul_continua=0;salveaza_joc(tip_tabla,tip_joc,jucator);}
                        if(mousex()>=15&&mousex()<=105&&mousey()>=840&&mousey()<=875){Jocul_continua=0;reset=1;}
                        x_schimbabil=((mousex()+2*n)/n*n)/(2*n);
                        y_schimbabil=((mousey()+2*n)/n*n)/(2*n);
                        selectat=1;
                    }
                    if(!(matrice_de_adiacenta[y_schimbabil][x_schimbabil]==1 and matrice_de_adiacenta[y_schimbabil-1][x_schimbabil]==0) and selectat == 1)
                    {
                        selectat=0;
                    }
                    if(ismouseclick(WM_LBUTTONDOWN) and selectat==1)
                    {
                        clearmouseclick(WM_LBUTTONDOWN),x_schimbat=((mousex()/n*n+2*n))/(2*n),y_schimbat=(mousey()/n*n+2*n)/(2*n);
                        selectat=2;
                    }
                    if(!(matrice_de_adiacenta[y_schimbat][x_schimbat]==0 and x_schimbabil==x_schimbat and y_schimbabil>y_schimbat and conditie_salt1(x_schimbat,y_schimbat,y_schimbabil)) and selectat==2)
                    {
                        selectat=1;
                    }
                }
                if(selectat==2)
                {
                    matrice_de_adiacenta[y_schimbat][x_schimbat]=1;
                    matrice_de_adiacenta[y_schimbabil][x_schimbabil]=0;
                    setfillstyle(1,WHITE);
                    fillellipse(x_schimbat*2*n-n,y_schimbat*2*n-n,n/2,n/2);
                    setfillstyle(1,culoare);
                    bar(x_schimbabil*2*n-2*n,y_schimbabil*2*n-2*n,x_schimbabil*2*n,y_schimbabil*2*n);
                    rectangle(x_schimbabil*2*n-2*n,y_schimbabil*2*n-2*n,x_schimbabil*2*n,y_schimbabil*2*n);
                    jucator=2;
                }acastigat=1;
            }
            else
            {
                afisare(jucator);
                while(selectat!=2 and Jocul_continua)
                {
                    if(ismouseclick(WM_LBUTTONDOWN) and selectat==0)
                    {

                        clearmouseclick(WM_LBUTTONDOWN);
                        if(mousex()>=680&&mousex()<=780&&mousey()>=840&&mousey()<=875){Jocul_continua=0;salveaza_joc(tip_tabla,tip_joc,jucator);}
                        if(mousex()>=15&&mousex()<=105&&mousey()>=840&&mousey()<=875){Jocul_continua=0;reset=1;}
                        x_schimbabil=((mousex()+2*n)/n*n)/(2*n);
                        y_schimbabil=((mousey()+2*n)/n*n)/(2*n);
                        selectat=1;
                    }
                    if(!(matrice_de_adiacenta[y_schimbabil][x_schimbabil]==1 and matrice_de_adiacenta[y_schimbabil][x_schimbabil+1]==0 ) and selectat == 1)
                    {
                        selectat=0;
                    }
                    if(ismouseclick(WM_LBUTTONDOWN) and selectat==1)
                    {
                        clearmouseclick(WM_LBUTTONDOWN),x_schimbat=((mousex()/n*n+2*n))/(2*n),y_schimbat=(mousey()/n*n+2*n)/(2*n);
                        selectat=2;
                    }
                    if(!(matrice_de_adiacenta[y_schimbat][x_schimbat]==0 and y_schimbabil==y_schimbat and x_schimbabil<x_schimbat  and conditie_salt2(y_schimbat,x_schimbat,x_schimbabil) ) and selectat==2)
                    {
                        selectat=1;
                    }
                }
                if(selectat==2)
                {

                    matrice_de_adiacenta[y_schimbat][x_schimbat]=1;
                    matrice_de_adiacenta[y_schimbabil][x_schimbabil]=0;
                    setfillstyle(1,WHITE);
                    fillellipse(x_schimbat*2*n-n,y_schimbat*2*n-n,n/2,n/2);
                    setfillstyle(1,culoare);
                    bar(x_schimbabil*2*n-2*n,y_schimbabil*2*n-2*n,x_schimbabil*2*n,y_schimbabil*2*n);
                    rectangle(x_schimbabil*2*n-2*n,y_schimbabil*2*n-2*n,x_schimbabil*2*n,y_schimbabil*2*n);
                    jucator=1;
                }
                acastigat=2;
                }
        }

}

        if(Jocul_continua==0) closegraph();
        }



void cautam_coordonate(int &y_schimbabil,int &x_schimbabil,int &x_schimbat,int &y_schimbat,int tip_tabla)
{
    int i,j,avem_pion=0,avem_loc_bun=0,c=0;
    for(i=1; i<=tip_tabla and c==0; i++)
    {
        avem_pion=0;
        avem_loc_bun=0;
        for(j=1; j<=tip_tabla and c==0; j++)
        {
            if(matrice_de_adiacenta[i][j]==1 and avem_pion==0)
            {
                avem_pion=1;
                x_schimbabil=j;
                y_schimbabil=i;
            }
            if(matrice_de_adiacenta[i-1][j]==1 and matrice_de_adiacenta[i+1][j]==1 and matrice_de_adiacenta[i][j]==0 and j>x_schimbabil )
            {
                avem_loc_bun=1;
                x_schimbat=j;
                y_schimbat=i;
            }
            if(avem_loc_bun and avem_pion and conditie_salt2(y_schimbat,x_schimbat,x_schimbabil) and x_schimbabil<x_schimbat)
                c=1;

        }


    }
    if(c==0)
    {
        for(i=1; i<=tip_tabla and c==0; i++)
        {
            avem_pion=0;
            avem_loc_bun=0;
            for(j=1; j<=tip_tabla and c==0; j++)
            {
                if(matrice_de_adiacenta[i][j]==1)
                {
                    avem_pion=1;
                    x_schimbabil=j;
                    y_schimbabil=i;
                }
                if(matrice_de_adiacenta[i-1][j]==1 and matrice_de_adiacenta[i][j]==0 and j>x_schimbabil)
                {
                    avem_loc_bun=1;
                    x_schimbat=j;
                    y_schimbat=i;
                }
                if(avem_loc_bun and avem_pion and conditie_salt2(y_schimbat,x_schimbat,x_schimbabil) and x_schimbabil<x_schimbat)
                    c=1;

            }

        }

    }
    if(c==0)
    {
        for(i=1; i<=tip_tabla and c==0; i++)
        {
            avem_pion=0;
            avem_loc_bun=0;
            for(j=1; j<=tip_tabla and c==0; j++)
            {
                if(matrice_de_adiacenta[i][j]==1)
                {
                    avem_pion=1;
                    x_schimbabil=j;
                    y_schimbabil=i;
                }
                if(matrice_de_adiacenta[i+1][j]==1 and matrice_de_adiacenta[i][j]==0 and j>x_schimbabil)
                {
                    avem_loc_bun=1;
                    x_schimbat=j;
                    y_schimbat=i;
                }
                if(avem_loc_bun and avem_pion and conditie_salt2(y_schimbat,x_schimbat,x_schimbabil) and x_schimbabil<x_schimbat)
                    c=1;

            }

        }

    }
    if(c==0)
    {
        for(i=1; i<=tip_tabla and c==0; i++)
        {
            avem_pion=0;
            avem_loc_bun=0;
            for(j=1; j<=tip_tabla and c==0; j++)
            {
                if(matrice_de_adiacenta[i][j]==1 and matrice_de_adiacenta[i][j+1]==0)
                {
                    avem_pion=1;
                    avem_loc_bun=1;
                    x_schimbabil=j;
                    y_schimbabil=i;
                    x_schimbat=j+1;
                    y_schimbat=i;
                    c=1;
                }

            }
        }
    }


}
void PvC(int tip_tabla,int tip_joc,int jucator)
{
    int selectat=0,x_schimbabil=-1,x_schimbat=-1,y_schimbabil=-1,y_schimbat=-1;
    int n=400/tip_tabla;
    int Jocul_continua=1;
delay(500);
    while(Jocul_continua)
    {

        selectat=0;
        if(!exista_mutari_posibile(jucator,tip_tabla))
        {
            delay(500);
            closegraph();
            Jocul_continua=0;
            initwindow(400,400);
            if(acastigat==1)
                castigator1();
            else
                castigator_calculator();
            while(selectat==0)
            {
                if(ismouseclick(WM_LBUTTONDOWN))
                    {
                        clearmouseclick(WM_LBUTTONDOWN);
                        selectat=1;
                    }
            }
        }
        else
        {
            if(jucator==1)
            {
                afisare1(jucator);
                while(selectat!=2 and Jocul_continua)
                {
                    if(ismouseclick(WM_LBUTTONDOWN) and selectat==0)
                    {
                        clearmouseclick(WM_LBUTTONDOWN);
                        if(mousex()>=680&&mousex()<=780&&mousey()>=840&&mousey()<=875){Jocul_continua=0;salveaza_joc(tip_tabla,tip_joc,jucator);}
                        if(mousex()>=15&&mousex()<=105&&mousey()>=840&&mousey()<=875){Jocul_continua=0;reset=1;}
                        x_schimbabil=((mousex()+2*n)/n*n)/(2*n);
                        y_schimbabil=((mousey()+2*n)/n*n)/(2*n);
                        selectat=1;
                    }
                    if(!(matrice_de_adiacenta[y_schimbabil][x_schimbabil]==1 and matrice_de_adiacenta[y_schimbabil-1][x_schimbabil]==0) and selectat == 1)
                    {
                        selectat=0;
                    }
                    if(ismouseclick(WM_LBUTTONDOWN) and selectat==1)
                    {
                        clearmouseclick(WM_LBUTTONDOWN),x_schimbat=((mousex()/n*n+2*n))/(2*n),y_schimbat=(mousey()/n*n+2*n)/(2*n);
                        selectat=2;
                    }
                    if(!(matrice_de_adiacenta[y_schimbat][x_schimbat]==0 and x_schimbabil==x_schimbat and y_schimbabil>y_schimbat and conditie_salt1(x_schimbat,y_schimbat,y_schimbabil)) and selectat==2)
                    {
                        selectat=1;
                    }
                }
                if(selectat==2)
                {
                    matrice_de_adiacenta[y_schimbat][x_schimbat]=1;
                    matrice_de_adiacenta[y_schimbabil][x_schimbabil]=0;
                    setfillstyle(1,WHITE);
                    fillellipse(x_schimbat*2*n-n,y_schimbat*2*n-n,n/2,n/2);
                    setfillstyle(1,culoare);
                    bar(x_schimbabil*2*n-2*n,y_schimbabil*2*n-2*n,x_schimbabil*2*n,y_schimbabil*2*n);
                    rectangle(x_schimbabil*2*n-2*n,y_schimbabil*2*n-2*n,x_schimbabil*2*n,y_schimbabil*2*n);
                    jucator=2;
                } acastigat=1;

            }
            else
            {
                afisare1(jucator);
                delay(500);
                cautam_coordonate(y_schimbabil,x_schimbabil,x_schimbat,y_schimbat,tip_tabla);
                matrice_de_adiacenta[y_schimbat][x_schimbat]=1;
                matrice_de_adiacenta[y_schimbabil][x_schimbabil]=0;
                setfillstyle(1,WHITE);
                fillellipse(x_schimbat*2*n-n,y_schimbat*2*n-n,n/2,n/2);
                setfillstyle(1,culoare);
                bar(x_schimbabil*2*n-2*n,y_schimbabil*2*n-2*n,x_schimbabil*2*n,y_schimbabil*2*n);
                rectangle(x_schimbabil*2*n-2*n,y_schimbabil*2*n-2*n,x_schimbabil*2*n,y_schimbabil*2*n);
                jucator=1;
                acastigat=2;
            }
        }
    }

 if(Jocul_continua==0) closegraph();
}
void derulare_joc(int tip_joc,int tip_tabla,int jucator)
{
    joc_nou=1;reset=0;
    if(tip_joc==1)
    {

        PvP(tip_tabla, tip_joc,jucator);

    }
    else
    {
        PvC(tip_tabla,tip_joc,jucator);

    }


    }



int main()
{
    int tip_joc=-1,tip_tabla=-1,jocul_e_deschis=1,jucator;
    PlaySound(TEXT("Rosegold  - Entro Senestre.wav"),NULL,SND_LOOP | SND_ASYNC );
    while(jocul_e_deschis)
    {
        if(reset==0 and joc_nou)
        {

        meniu(tip_joc,tip_tabla);
        jucator=1;
        }
        initializare_nivel(tip_tabla,tip_joc,jucator);
        derulare_joc(tip_joc,tip_tabla,jucator);




    }
    getch();
    closegraph();
    return 0;
}
