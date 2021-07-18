#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<cstdlib>
using namespace std;
ifstream f("mapa.txt");
char a[14][14],v[100],v1[100],v2[100],v3[100],v4[100];
int p1,p2,p3,p4,n;

void citire(){
    int i,j;
    f>>n;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            f>>a[i][j];
    }
}
void afisare(){
    int i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(a[i][j]=='0')
                cout<<' '<<" ";
            else if(a[i][j]=='o')
            {
                a[i][j]=char(p1);
                cout<<" "<<a[i][j];
            }
            else if(a[i][j]=='l')
            {
                a[i][j]=char(p2);
                cout<<" "<<a[i][j];
            }

            else if(a[i][j]=='u')
            {
                a[i][j]=char(p3);
                cout<<" "<<a[i][j];
            }
            else if(a[i][j]=='t')
            {
                a[i][j]=char(p4);
                cout<<" "<<a[i][j];
            }
            else
                cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void alegere_player(){
    cout<<"pentru: "<<char(003)<<" introduceti 3"<<endl;
    cout<<"pentru: "<<char(004)<<" introduceti 4"<<endl;
    cout<<"pentru: "<<char(005)<<" introduceti 5"<<endl;
    cout<<"pentru: "<<char(006)<<" introduceti 6"<<endl;
    cout<<endl<<"Player 1:";
    cin>>p1;
    if(p1>=3 && p1<=6)
    {}
    else
    {
        cout<<"Trebuia sa introduceti doar 3,4,5,6, incercati iarasi:";
        cin>>p1;
    }
    cout<<"Player 1:"<<char(p1)<<endl;
    cout<<endl<<"Player 2:";
    cin>>p2;
    if(p2>=3 && p2<=6 && p2!=p1)
    {}
    else
    {
        cout<<"Trebuia sa introduceti doar 3,4,5,6,sau caracterul a fost luat deja, incercati iarasi:";
        cin>>p2;
        while(p2<=3 || p2>=6 || p2==p1)
            cin>>p2;
    }
    cout<<"Player 2:"<<char(p2)<<endl;
    cout<<endl<<"Player 3:";
    cin>>p3;
    if(p3>=3 && p3<=6 && p3!=p1 && p3!=p2)
    {}
    else
    {
        cout<<"Trebuia sa introduceti doar 3,4,5,6,sau caracterul a fost luat deja, incercati iarasi:";
        cin>>p3;
        while(p3<=3 || p3>=6 || p3==p1 || p3==p2)
            cin>>p3;
    }
    cout<<"Player 3:"<<char(p3)<<endl;
    cout<<endl<<"Player 4:";
    cin>>p4;
    if(p4>=3 && p4<=6 && p4!=p1 && p4!=p2 && p4!=p3)
    {}
    else
    {
        cout<<"Trebuia sa introduceti doar 3,4,5,6,sau caracterul a fost luat deja, incercati iarasi:";
        cin>>p4;
        while(p4<=3 || p4>=6 || p4==p1 || p4==p2 || p4==p3)
            cin>>p4;
    }
    cout<<"Player 4:"<<char(p4)<<endl;
}
void r1(char v[100], char v1[100]){
    int i=1;
    while(v[i]==v1[i]&&i<=40)
        i++;
    if(i==41)
        return;
    if(v[i]!=v1[i] && v[i]=='x'){
        v[i]=v1[i];
    return;
    }
    if(v[i]!=v1[i]){
        if(v[i]==char(p2)){
            v[i]=v1[i];
            if(a[3][10]!=char(p2))
                {
                    a[3][10]=char(p2);
                    return;
                }
            else if(a[4][10]!=char(p2))
                {
                    a[4][10]=char(p2);
                    return;
                }
            else if(a[4][11]!=char(p2))
                {
                    a[4][11]=char(p2);
                    return;
                }
            else if(a[3][11]!=char(p2))
                {
                    a[3][11]=char(p2);
                    return;
                }
        }
        if(v[i]==char(p3)){
            v[i]=v1[i];
            if(a[10][10]!=char(p3))
                {
                    a[10][10]=char(p3);
                    return;
                }
            else if(a[10][11]!=char(p3))
                {
                    a[10][11]=char(p3);
                    return;
                }
            else if(a[11][10]!=char(p3))
                {
                    a[11][10]=char(p3);
                    return;
                }
            else if(a[11][11]!=char(p3))
               {
                   a[11][11]=char(p3);
                   return;
                }
        }
        if(v[i]==char(p4)){
            v[i]=v1[i];
            if(a[10][3]!=char(p4))
                {
                    a[10][3]=char(p4);
                    return;
                }
            else if(a[10][4]!=char(p4))
                {
                    a[10][4]=char(p4);
                    return;
                }
            else if(a[11][3]!=char(p4))
                {
                    a[11][3]=char(p4);
                    return;
                }
            else if(a[11][4]!=char(p4))
                {
                    a[11][4]=char(p4);
                    return;
                }
        }
    }
}
void r2(char v[100], char v2[100]){
    int i=1;
    while(v[i+10]==v2[i]&&i<=40)
        i++;
    if(i==41)
        return;
    if(v[i+10]!=v2[i] && v[i+10]=='x'){
        v[i+10]=v2[i];
        return;
    }
    if(v[i+10]!=v2[i]){
        if(v[i+10]==char(p1)){
            v[i+10]=v2[i];
            if(a[3][3]!=char(p1))
                {
                    a[3][3]=char(p1);
                    return;
                }
            else if(a[3][4]!=char(p1))
                {
                    a[3][4]=char(p1);
                    return;}
            else if(a[4][3]!=char(p1))
                {a[4][3]=char(p1);return;}
            else if(a[4][4]!=char(p1))
                {a[4][4]=char(p1);return;}
        }
        if(v[i+10]==char(p3)){
            v[i+10]=v2[i];
            if(a[10][10]!=char(p3))
                {a[10][10]=char(p3);return;}
            else if(a[10][11]!=char(p3))
                {a[10][11]=char(p3);return;}
            else if(a[11][10]!=char(p3))
                {a[11][10]=char(p3);return;}
            else if(a[11][11]!=char(p3))
                {a[11][11]=char(p3);return;}
        }
        if(v[i+10]==char(p4)){
            v[i+10]=v2[i];
            if(a[10][3]!=char(p4))
                {a[10][3]=char(p4);return;}
            else if(a[10][4]!=char(p4))
                {a[10][4]=char(p4);return;}
            else if(a[11][3]!=char(p4))
                {a[11][3]=char(p4);return;}
            else if(a[11][4]!=char(p4))
                {a[11][4]=char(p4);return;}
        }
    }
}
void r3(char v[100], char v3[100]){
    int i=1;
    while(v[i+20]==v3[i]&&i<=40)
        i++;
    if(i==41)
        return;
    if(v[i+20]!=v3[i] && v[i+20]=='x'){
        v[i+20]=v3[i];
        return;
    }
    if(v[i+20]!=v3[i]){
        if(v[i+20]==char(p2)){
            v[i+20]=v3[i];
            if(a[3][10]!=char(p2))
                {a[3][10]=char(p2);return;}
            else if(a[4][10]!=char(p2))
                {a[4][10]=char(p2);return;}
            else if(a[4][11]!=char(p2))
                {a[4][11]=char(p2);return;}
            else if(a[3][11]!=char(p2))
                {a[3][11]=char(p2);return;}
        }
        if(v[i+20]==char(p1)){
            v[i+20]=v3[i];
            if(a[3][3]!=char(p1))
                {a[3][3]=char(p1);return;}
            else if(a[3][4]!=char(p1))
                {a[3][4]=char(p1);return;}
            else if(a[4][3]!=char(p1))
                {a[4][3]=char(p1);return;}
            else if(a[4][4]!=char(p1))
                {a[4][4]=char(p1);return;}
        }
        if(v[i+20]==char(p4)){
            v[i+20]=v3[i];
            if(a[10][3]!=char(p4))
                {a[10][3]=char(p4);return;}
            else if(a[10][4]!=char(p4))
                {a[10][4]=char(p4);return;}
            else if(a[11][3]!=char(p4))
                {a[11][3]=char(p4);return;}
            else if(a[11][4]!=char(p4))
                {a[11][4]=char(p4);return;}
        }
    }

}
void r4(char v[100], char v4[100]){
    int i=1;
    while(v[i+30]==v4[i]&&i<=40)
        i++;
    if(i==41)
        return;
    if(v[i+30]!=v4[i] && v[i+30]=='x'){
        v[i+30]=v4[i];
        return;
    }
    if(v[i+30]!=v4[i]){
        if(v[i+30]==char(p2)){
            v[i+30]=v4[i];
            if(a[3][10]!=char(p2))
                {a[3][10]=char(p2);return;}
            else if(a[4][10]!=char(p2))
                {a[4][10]=char(p2);return;}
            else if(a[4][11]!=char(p2))
                {a[4][11]=char(p2);return;}
            else if(a[3][11]!=char(p2))
                {a[3][11]=char(p2);return;}
        }
        if(v[i+30]==char(p3)){
            v[i+30]=v4[i];
            if(a[10][10]!=char(p3))
                {a[10][10]=char(p3);return;}
            else if(a[10][11]!=char(p3))
                {a[10][11]=char(p3);return;}
            else if(a[11][10]!=char(p3))
                {a[11][10]=char(p3);return;}
            else if(a[11][11]!=char(p3))
                {a[11][11]=char(p3);return;}
        }
        if(v[i+30]==char(p1)){
            v[i+30]=v4[i];
            if(a[3][3]!=char(p1))
                {a[3][3]=char(p1);return;}
            else if(a[3][4]!=char(p1))
                {a[3][4]=char(p1);return;}
            else if(a[4][3]!=char(p1))
                {a[4][3]=char(p1);return;}
            else if(a[4][4]!=char(p1))
                {a[4][4]=char(p1);return;}
        }
    }


}
void rprincipal(char a[14][14], char v[100]){
    a[6][2]=v[1];
    a[6][3]=v[2];
    a[6][4]=v[3];
    a[6][5]=v[4];
    a[6][6]=v[5];
    a[5][6]=v[6];
    a[4][6]=v[7];
    a[3][6]=v[8];
    a[2][6]=v[9];
    a[2][7]=v[10];
    a[2][8]=v[11];
    a[3][8]=v[12];
    a[4][8]=v[13];
    a[5][8]=v[14];
    a[6][8]=v[15];
    a[6][9]=v[16];
    a[6][10]=v[17];
    a[6][11]=v[18];
    a[6][12]=v[19];
    a[7][12]=v[20];
    a[8][12]=v[21];
    a[8][11]=v[22];
    a[8][10]=v[23];
    a[8][9]=v[24];
    a[8][8]=v[25];
    a[9][8]=v[26];
    a[10][8]=v[27];
    a[11][8]=v[28];
    a[12][8]=v[29];
    a[12][7]=v[30];
    a[12][6]=v[31];
    a[11][6]=v[32];
    a[10][6]=v[33];
    a[9][6]=v[34];
    a[8][6]=v[35];
    a[8][5]=v[36];
    a[8][4]=v[37];
    a[8][3]=v[38];
    a[8][2]=v[39];
    a[7][2]=v[40];
    //continuare alti playeri
    if(a[6][2]=='x')
    a[6][2]=v[41];
    if(a[6][3]=='x')
    a[6][3]=v[42];
    if(a[6][4]=='x')
    a[6][4]=v[43];
    if(a[6][5]=='x')
    a[6][5]=v[44];
    if(a[6][6]=='x')
    a[6][6]=v[45];
    if(a[5][6]=='x')
    a[5][6]=v[46];
    if(a[4][6]=='x')
    a[4][6]=v[47];
    if(a[3][6]=='x')
    a[3][6]=v[48];
    if(a[2][6]=='x')
    a[2][6]=v[49];
    if(a[2][7]=='x')
    a[2][7]=v[50];
    if(a[2][8]=='x')
    a[2][8]=v[51];
    if(a[3][8]=='x')
    a[3][8]=v[52];
    if(a[4][8]=='x')
    a[4][8]=v[53];
    if(a[5][8]=='x')
    a[5][8]=v[54];
    if(a[6][8]=='x')
    a[6][8]=v[55];
    if(a[6][9]=='x')
    a[6][9]=v[56];
    if(a[6][10]=='x')
    a[6][10]=v[57];
    if(a[6][11]=='x')
    a[6][11]=v[58];
    if(a[6][12]=='x')
    a[6][12]=v[59];
    if(a[7][12]=='x')
    a[7][12]=v[60];
    if(a[8][12]=='x')
    a[8][12]=v[61];
    if(a[8][11]=='x')
    a[8][11]=v[62];
    if(a[8][10]=='x')
    a[8][10]=v[63];
    if(a[8][9]=='x')
    a[8][9]=v[64];
    if(a[8][8]=='x')
    a[8][8]=v[65];
    if(a[9][8]=='x')
    a[9][8]=v[66];
    if(a[10][8]=='x')
    a[10][8]=v[67];
    if(a[11][8]=='x')
    a[11][8]=v[68];
    if(a[12][8]=='x')
    a[12][8]=v[69];
    //case
    a[12][7]=v[70];
    a[7][3]=v[71];
    a[7][4]=v[72];
    a[7][5]=v[73];
    a[7][6]=v[74];
    a[3][7]=v[75];
    a[4][7]=v[76];
    a[5][7]=v[77];
    a[6][7]=v[78];
    a[7][11]=v[79];
    a[7][10]=v[80];
    a[7][9]=v[81];
    a[7][8]=v[82];
    a[11][7]=v[83];
    a[10][7]=v[84];
    a[9][7]=v[85];
    a[8][7]=v[86];

}
int zar(){
    srand(time(0));
    return (rand() % 6 + 1);
    //return 1+(rand()%6);
}
void player1(int nr, bool &plecat1_1, bool &plecat1_2, bool &plecat1_3, bool &plecat1_4){
    int alegere,i;
    cout<<"Nr cazut la zar:"<<nr<<endl;
    if(nr==6)
    {
        if(a[3][3]==char(p1) || a[4][3]==char(p1) || a[4][4]==char(p1) || a[3][4]==char(p1))
        {
            cout<<"Daca doriti sa scoateti din casa un pion introduceti 1:"<<endl;
            cout<<"Daca doriti sa mutati un pion care este pe tabla de joc introduceti 2:"<<endl;
            cout<<"Optiunea aleasa:";
            cin>>alegere;
            if(alegere==1 && (a[3][3]==char(p1) || a[4][3]==char(p1) || a[4][4]==char(p1) || a[3][4]==char(p1)))
            {
                if(a[3][3]==char(p1))
                {
                    plecat1_1=false;
                }
                if(a[4][3]==char(p1))
                {
                    plecat1_2=false;
                }
                if(a[4][4]==char(p1))
                {
                    plecat1_3=false;
                }
                if(a[3][4]==char(p1))
                {
                    plecat1_4=false;
                }
                if(a[3][3]==char(p1) && plecat1_1==false)
                {
                    a[3][3]='0';
                    v1[1]=char(p1);
                    r1(v,v1);
                    rprincipal(a,v);
                    plecat1_1=true;
                    plecat1_2=true;
                    plecat1_3=true;
                    plecat1_4=true;
                    afisare();
                }
                if(a[4][3]==char(p1) && plecat1_2==false)
                {
                    a[4][3]='0';
                    v1[1]=char(p1);
                    r1(v,v1);
                    rprincipal(a,v);
                    plecat1_1=true;
                    plecat1_2=true;
                    plecat1_3=true;
                    plecat1_4=true;
                    afisare();
                }
                if(a[4][4]==char(p1) && plecat1_3==false)
                {
                    a[4][4]='0';
                    v1[1]=char(p1);
                    r1(v,v1);
                    rprincipal(a,v);
                    plecat1_1=true;
                    plecat1_2=true;
                    plecat1_3=true;
                    plecat1_4=true;
                    afisare();
                }
                if(a[3][4]==char(p1) && plecat1_4==false)
                {
                    a[3][4]='0';
                    v1[1]=char(p1);
                    r1(v,v1);
                    rprincipal(a,v);
                    plecat1_1=true;
                    plecat1_2=true;
                    plecat1_3=true;
                    plecat1_4=true;
                    afisare();
                }
            }
            if(alegere==2)
            {
                for(i=1; i<=44; i++)
                    if(v1[i]==char(p1))
                    {
                        v[i+nr]=v[i];
                        v[i]='x';
                        r1(v,v1);
                        rprincipal(a,v);
                        afisare();
                        break;
                    }
                    else
                    {
                        cout<<"Nu aveti piese pe tabla! Se scoate automat"<<endl;
                        if(a[3][3]==char(p1))
                        {
                            plecat1_1=false;
                        }
                        if(a[4][3]==char(p1))
                        {
                            plecat1_2=false;
                        }
                        if(a[4][4]==char(p1))
                        {
                            plecat1_3=false;
                        }
                        if(a[3][4]==char(p1))
                        {
                            plecat1_4=false;
                        }
                        if(a[3][3]==char(p1) && plecat1_1==false)
                        {
                            a[3][3]='0';
                            v1[1]=char(p1);
                            r1(v,v1);
                            rprincipal(a,v);
                            plecat1_1=true;
                            plecat1_2=true;
                            plecat1_3=true;
                            plecat1_4=true;
                            afisare();
                        }
                        if(a[4][3]==char(p1) && plecat1_2==false)
                        {
                            a[4][3]='0';
                            v1[1]=char(p1);
                            r1(v,v1);
                            rprincipal(a,v);
                            plecat1_1=true;
                            plecat1_2=true;
                            plecat1_3=true;
                            plecat1_4=true;
                            afisare();
                        }
                        if(a[4][4]==char(p1) && plecat1_3==false)
                        {
                            a[4][4]='0';
                            v1[1]=char(p1);
                            r1(v,v1);
                            rprincipal(a,v);
                            plecat1_1=true;
                            plecat1_2=true;
                            plecat1_3=true;
                            plecat1_4=true;
                            afisare();
                        }
                        if(a[3][4]==char(p1) && plecat1_4==false)
                        {
                            a[3][4]='0';
                            v1[1]=char(p1);
                            r1(v,v1);
                            rprincipal(a,v);
                            plecat1_1=true;
                            plecat1_2=true;
                            plecat1_3=true;
                            plecat1_4=true;
                            afisare();
                        }
                    }
            }
        }
    }
    else
    {
        if(a[3][3]==char(p1) && a[4][3]==char(p1) && a[4][4]==char(p1) && a[3][4]==char(p1))
            cout<<"next player"<<endl;
        else
            for(i=1; i<=44; i++)
            {
                if(v1[i]==char(p1))
                {
                    v1[i+nr]=v1[i];
                    v1[i]='x';
                    r1(v,v1);
                    rprincipal(a,v);
                    afisare();
                    break;
                }
            }

    }
}
void player2(int nr, bool &plecat2_1, bool &plecat2_2, bool &plecat2_3, bool &plecat2_4){
    int alegere,i;
    cout<<"Nr cazut la zar:"<<nr<<endl;
    if(nr==6)
    {
        if(a[3][10]==char(p2) || a[4][10]==char(p2) || a[4][11]==char(p2) || a[3][11]==char(p2))
        {
            cout<<"Daca doriti sa scoateti din casa un pion introduceti 1:"<<endl;
            cout<<"Daca doriti sa mutati un pion care este pe tabla de joc introduceti 2:"<<endl;
            cout<<"Optiunea aleasa:";
            cin>>alegere;
            if(alegere==1 && (a[3][10]==char(p2) || a[4][10]==char(p2) || a[4][11]==char(p2) || a[3][11]==char(p2)))
            {
                if(a[3][10]==char(p2))
                {
                    plecat2_1=false;
                }
                if(a[4][10]==char(p2))
                {
                    plecat2_2=false;
                }
                if(a[4][11]==char(p2))
                {
                    plecat2_3=false;
                }
                if(a[3][11]==char(p2))
                {
                    plecat2_4=false;
                }
                if(a[3][10]==char(p2) && plecat2_1==false)
                {
                    a[3][10]='0';
                    v2[1]=char(p2);
                    r2(v,v2);
                    rprincipal(a,v);
                    plecat2_1=true;
                    plecat2_2=true;
                    plecat2_3=true;
                    plecat2_4=true;
                    afisare();
                }
                if(a[4][10]==char(p2) && plecat2_2==false)
                {
                    a[4][10]='0';
                    v2[1]=char(p2);
                    r2(v,v2);
                    rprincipal(a,v);
                    plecat2_1=true;
                    plecat2_2=true;
                    plecat2_3=true;
                    plecat2_4=true;
                    afisare();
                }
                if(a[4][11]==char(p2) && plecat2_3==false)
                {
                    a[4][11]='0';
                    v2[1]=char(p2);
                    r2(v,v2);
                    rprincipal(a,v);
                    plecat2_1=true;
                    plecat2_2=true;
                    plecat2_3=true;
                    plecat2_4=true;
                    afisare();
                }
                if(a[3][11]==char(p2) && plecat2_4==false)
                {
                    a[3][11]='0';
                    v2[1]=char(p2);
                    r2(v,v2);
                    rprincipal(a,v);
                    plecat2_1=true;
                    plecat2_2=true;
                    plecat2_3=true;
                    plecat2_4=true;
                    afisare();
                }
            }
            if(alegere==2)
            {
                for(i=1; i<=44; i++)
                    if(v2[i]==char(p2))
                    {
                        v2[i+nr]=v2[i];
                        v2[i]='x';
                        r2(v,v2);
                        rprincipal(a,v);
                        afisare();
                        break;
                    }
                    else
                    {
                        cout<<"Nu aveti piese pe tabla! Se scoate automat"<<endl;
                        if(a[3][10]==char(p2) && plecat2_1==false)
                        {
                            a[3][10]='0';
                            v2[1]=char(p2);
                            r2(v,v2);
                            rprincipal(a,v);
                            plecat2_1=true;
                            plecat2_2=true;
                            plecat2_3=true;
                            plecat2_4=true;
                            afisare();
                        }
                        if(a[4][10]==char(p2) && plecat2_2==false)
                        {
                            a[4][10]='0';
                            v2[1]=char(p2);
                            r2(v,v2);
                            rprincipal(a,v);
                            plecat2_1=true;
                            plecat2_2=true;
                            plecat2_3=true;
                            plecat2_4=true;
                            afisare();
                        }
                        if(a[4][11]==char(p2) && plecat2_3==false)
                        {
                            a[4][11]='0';
                            v2[11]=char(p2);
                            r2(v,v2);
                            rprincipal(a,v);
                            plecat2_1=true;
                            plecat2_2=true;
                            plecat2_3=true;
                            plecat2_4=true;
                            afisare();
                        }
                        if(a[3][11]==char(p2) && plecat2_4==false)
                        {
                            a[3][11]='0';
                            v2[1]=char(p2);
                            r2(v,v2);
                            rprincipal(a,v);
                            plecat2_1=true;
                            plecat2_2=true;
                            plecat2_3=true;
                            plecat2_4=true;
                            afisare();
                        }
                        if(a[3][10]==char(p2))
                        {
                            plecat2_1=false;
                        }
                        if(a[4][10]==char(p2))
                        {
                            plecat2_2=false;
                        }
                        if(a[4][11]==char(p2))
                        {
                            plecat2_3=false;
                        }
                        if(a[3][11]==char(p2))
                        {
                            plecat2_4=false;
                        }
                    }
            }
        }
    }
    else
    {
        if(a[3][10]==char(p2) && a[4][10]==char(p2) && a[4][11]==char(p2) && a[3][11]==char(p2))
            cout<<"next player"<<endl;
        else
        {
            for(i=1; i<=44; i++)
            {
                if(v2[i]==char(p2))
                {
                    v2[i+nr]=v2[i];
                    v2[i]='x';
                    r2(v,v2);
                    rprincipal(a,v);
                    afisare();
                    break;
                }
            }
        }

    }
}
void player3(int nr, bool &plecat3_1, bool &plecat3_2, bool &plecat3_3, bool &plecat3_4){
    int alegere,i;
    cout<<"Nr cazut la zar:"<<nr<<endl;
    if(nr==6)
    {
        if(a[10][10]==char(p3) || a[11][10]==char(p3) || a[11][11]==char(p3) || a[10][11]==char(p3))
        {
            cout<<"Daca doriti sa scoateti din casa un pion introduceti 1:"<<endl;
            cout<<"Daca doriti sa mutati un pion care este pe tabla de joc introduceti 2:"<<endl;
            cout<<"Optiunea aleasa:";
            cin>>alegere;
            if(alegere==1 && (a[10][10]==char(p3) || a[11][10]==char(p3) || a[11][11]==char(p3) || a[10][11]==char(p3)))
            {
                if(a[10][10]==char(p3) && plecat3_1==false)
                {
                    a[10][10]='0';
                    v3[1]=char(p3);
                    r3(v,v3);
                    rprincipal(a,v);
                    plecat3_1=true;
                    plecat3_2=true;
                    plecat3_3=true;
                    plecat3_4=true;
                    afisare();
                }
                if(a[11][10]==char(p3) && plecat3_2==false)
                {
                    a[11][10]='0';
                    v3[1]=char(p3);
                    r3(v,v3);
                    rprincipal(a,v);
                    plecat3_1=true;
                    plecat3_2=true;
                    plecat3_3=true;
                    plecat3_4=true;
                    afisare();
                }
                if(a[11][11]==char(p3) && plecat3_3==false)
                {
                    a[11][11]='0';
                    v3[1]=char(p3);
                    r3(v,v3);
                    rprincipal(a,v);
                    plecat3_1=true;
                    plecat3_2=true;
                    plecat3_3=true;
                    plecat3_4=true;
                    afisare();
                }
                if(a[10][11]==char(p3) && plecat3_4==false)
                {
                    a[10][11]='0';
                    v3[1]=char(p3);
                    r3(v,v3);
                    rprincipal(a,v);
                    plecat3_1=true;
                    plecat3_2=true;
                    plecat3_3=true;
                    plecat3_4=true;
                    afisare();
                }
                if(a[10][10]==char(p3))
                {
                    plecat3_1=false;
                }
                if(a[11][10]==char(p3))
                {
                    plecat3_2=false;
                }
                if(a[11][11]==char(p3))
                {
                    plecat3_3=false;
                }
                if(a[10][11]==char(p3))
                {
                    plecat3_4=false;
                }
            }
            if(alegere==2)
            {
                for(i=1; i<=44; i++)
                    if(v3[i]==char(p3))
                    {
                        v3[i+nr]=v3[i];
                        v3[i]='x';
                        r3(v,v3);
                        rprincipal(a,v);
                        afisare();
                        break;
                    }
                    else
                    {
                        cout<<"Nu aveti piese pe tabla! Se scoate automat"<<endl;
                        if(a[10][10]==char(p3) && plecat3_1==false)
                        {
                            a[10][10]='0';
                            v3[1]=char(p3);
                            r3(v,v3);
                            rprincipal(a,v);
                            plecat3_1=true;
                            plecat3_2=true;
                            plecat3_3=true;
                            plecat3_4=true;
                            afisare();
                        }
                        if(a[11][10]==char(p3) && plecat3_2==false)
                        {
                            a[11][10]='0';
                            v[1]=char(p3);
                            r3(v,v3);
                            rprincipal(a,v);
                            plecat3_1=true;
                            plecat3_2=true;
                            plecat3_3=true;
                            plecat3_4=true;
                            afisare();
                        }
                        if(a[11][11]==char(p3) && plecat3_3==false)
                        {
                            a[11][11]='0';
                            v3[1]=char(p3);
                            r3(v,v3);
                            rprincipal(a,v);
                            plecat3_1=true;
                            plecat3_2=true;
                            plecat3_3=true;
                            plecat3_4=true;
                            afisare();
                        }
                        if(a[10][11]==char(p3) && plecat3_4==false)
                        {
                            a[10][11]='0';
                            v3[1]=char(p3);
                            r3(v,v3);
                            rprincipal(a,v);
                            plecat3_1=true;
                            plecat3_2=true;
                            plecat3_3=true;
                            plecat3_4=true;
                            afisare();
                        }
                        if(a[10][10]==char(p3))
                        {
                            plecat3_1=false;
                        }
                        if(a[11][10]==char(p3))
                        {
                            plecat3_2=false;
                        }
                        if(a[11][11]==char(p3))
                        {
                            plecat3_3=false;
                        }
                        if(a[10][11]==char(p3))
                        {
                            plecat3_4=false;
                        }
                    }
            }
        }
    }
    else
    {
        if(a[10][10]==char(p3) && a[11][10]==char(p3) && a[11][11]==char(p3) && a[10][11]==char(p3))
            cout<<"next player"<<endl;
        else
        {
            for(i=1; i<=44; i++)
            {
                if(v3[i]==char(p3))
                {
                    v3[i+nr]=v3[i];
                    v3[i]='x';
                    r3(v,v3);
                    rprincipal(a,v);
                    afisare();
                    break;
                }
            }
        }

    }
}
void player4(int nr, bool &plecat4_1, bool &plecat4_2, bool &plecat4_3, bool &plecat4_4){
    int alegere,i;
    cout<<"Nr cazut la zar:"<<nr<<endl;
    if(nr==6)
    {
        if(a[10][3]==char(p4) || a[11][3]==char(p4) || a[10][4]==char(p4) || a[11][4]==char(p4))
        {
            cout<<"Daca doriti sa scoateti din casa un pion introduceti 1:"<<endl;
            cout<<"Daca doriti sa mutati un pion care este pe tabla de joc introduceti 2:"<<endl;
            cout<<"Optiunea aleasa:";
            cin>>alegere;
            if(alegere==1 && (a[10][3]==char(p4) || a[11][3]==char(p4) || a[10][4]==char(p4) || a[11][4]==char(p4)))
            {
                if(a[10][3]==char(p4) && plecat4_1==false)
                {
                    a[10][3]='0';
                    v4[1]=char(p4);
                    r4(v,v4);
                    rprincipal(a,v);
                    plecat4_1=true;
                    plecat4_2=true;
                    plecat4_3=true;
                    plecat4_4=true;
                    afisare();
                }
                if(a[11][3]==char(p4) && plecat4_2==false)
                {
                    a[11][3]='0';
                    v4[1]=char(p4);
                    r4(v,v4);
                    rprincipal(a,v);
                    plecat4_1=true;
                    plecat4_2=true;
                    plecat4_3=true;
                    plecat4_4=true;
                    afisare();
                }
                if(a[10][4]==char(p4) && plecat4_3==false)
                {
                    a[10][4]='0';
                    v4[1]=char(p4);
                    r4(v,v4);
                    rprincipal(a,v);
                    plecat4_1=true;
                    plecat4_2=true;
                    plecat4_3=true;
                    plecat4_4=true;
                    afisare();
                }
                if(a[11][4]==char(p4) && plecat4_4==false)
                {
                    a[11][4]='0';
                    v4[1]=char(p4);
                    r4(v,v4);
                    rprincipal(a,v);
                    plecat4_1=true;
                    plecat4_2=true;
                    plecat4_3=true;
                    plecat4_4=true;
                    afisare();
                }
                if(a[10][3]==char(p4))
                {
                    plecat4_1=false;
                }
                if(a[11][4]==char(p4))
                {
                    plecat4_2=false;
                }
                if(a[10][4]==char(p4))
                {
                    plecat4_3=false;
                }
                if(a[11][4]==char(p4))
                {
                    plecat4_4=false;
                }
            }
            if(alegere==2)
            {
                for(i=11; i<=44; i++)
                    if(v4[i]==char(p4))
                    {
                        v4[i+nr]=v4[i];
                        v4[i]='x';
                        r4(v,v4);
                        rprincipal(a,v);
                        afisare();
                        break;
                    }
                    else
                    {
                        cout<<"Nu aveti piese pe tabla! Se scoate automat"<<endl;
                        if(a[10][3]==char(p4) && plecat4_1==false)
                        {
                            a[10][3]='0';
                            v4[1]=char(p4);
                            r4(v,v4);
                            rprincipal(a,v);
                            plecat4_1=true;
                            plecat4_2=true;
                            plecat4_3=true;
                            plecat4_4=true;
                            afisare();
                        }
                        if(a[11][3]==char(p4) && plecat4_2==false)
                        {
                            a[11][3]='0';
                            v4[1]=char(p4);
                            r4(v,v4);
                            rprincipal(a,v);
                            plecat4_1=true;
                            plecat4_2=true;
                            plecat4_3=true;
                            plecat4_4=true;
                            afisare();
                        }
                        if(a[10][4]==char(p4) && plecat4_3==false)
                        {
                            a[10][4]='0';
                            v4[1]=char(p4);
                            r4(v,v4);
                            rprincipal(a,v);
                            plecat4_1=true;
                            plecat4_2=true;
                            plecat4_3=true;
                            plecat4_4=true;
                            afisare();
                        }
                        if(a[11][4]==char(p4) && plecat4_4==false)
                        {
                            a[11][4]='0';
                            v4[1]=char(p4);
                            r4(v,v4);
                            rprincipal(a,v);
                            plecat4_1=true;
                            plecat4_2=true;
                            plecat4_3=true;
                            plecat4_4=true;
                            afisare();
                        }
                        if(a[10][3]==char(p4))
                        {
                            plecat4_1=false;
                        }
                        if(a[11][3]==char(p4))
                        {
                            plecat4_2=false;
                        }
                        if(a[10][4]==char(p4))
                        {
                            plecat4_3=false;
                        }
                        if(a[11][4]==char(p4))
                        {
                            plecat4_4=false;
                        }
                    }
            }
        }
    }
    else
    {
        if(a[10][10]==char(p4) && a[11][10]==char(p4) && a[11][11]==char(p4) && a[10][11]==char(p4))
            cout<<"next player"<<endl;
        else
        {
            for(i=1; i<=44; i++)
            {
                if(v4[i]==char(p4))
                {
                    v4[i+nr]=v4[i];
                    v4[i]='x';
                    r4(v,v4);
                    rprincipal(a,v);
                    afisare();
                    break;
                }
            }
        }

    }
}
int main(){
    int n,r, alegere_jucator,nr,i,psd,j,k,zar3x6=0;
    bool mutat=false, ocupat=false;

    bool plecat1_1=false, plecat1_2=false, plecat1_3=false, plecat1_4=false;
    bool plecat2_1=false, plecat2_2=false, plecat2_3=false, plecat2_4=false;
    bool plecat3_1=false, plecat3_2=false, plecat3_3=false, plecat3_4=false;
    bool plecat4_1=false, plecat4_2=false, plecat4_3=false, plecat4_4=false;

    alegere_player();
    cout<<endl<<endl;
    citire();
    afisare();
    cout<<endl<<endl;
    for(i=1;i<=70;i++)
        v[i]='x';
    for(i=71;i<=86;i++)
        v[i]='c';
    for(i=1; i<=40; i++)
    {
        v1[i]='x';
        v2[i]='x';
        v3[i]='x';
        v4[i]='x';
    }
    for(i=41; i<=44; i++)
    {
        v1[i]='c';
        v2[i]='c';
        v3[i]='c';
        v4[i]='c';
    }
    while(true)
    {
        cout<<"--PLAYER1--"<<endl;
        nr=zar();

        if(v[71]!='c' && v[72]!='c' && v[73]!='c' && v[74]!='c')
            break;
        else
            player1(nr,plecat1_1,plecat1_2,plecat1_3,plecat1_4);
        system("pause");

        cout<<endl<<"vector mare ";
        for(i=1;i<=70;i++)
        cout<<v[i]<<" ";
        cout<<endl<<"Vector mic1 ";
        for(i=1;i<=44;i++)
        cout<<v1[i]<<" ";

        cout<<"--PLAYER2--"<<endl;
        nr=zar();

        if(v[75]!='c' && v[76]!='c' && v[77]!='c' && v[78]!='c')
            break;
        else
            player2(nr,plecat2_1,plecat2_2,plecat2_3,plecat2_4);
        system("pause");
        cout<<endl<<"vector mare ";
        for(i=1;i<=70;i++)
        cout<<v[i]<<" ";
        cout<<endl<<"Vector mic2 ";
        for(i=1;i<=44;i++)
        cout<<v2[i]<<" ";
        cout<<"--PLAYER3--"<<endl;
        nr=zar();

        if(v[79]!='c' && v[80]!='c' && v[81]!='c' && v[82]!='c')
            break;
        else
            cout<<endl<<"vector mare";
        for(i=1;i<=70;i++)
        cout<<v[i]<<" ";
        cout<<endl<<"Vector mic4";
        for(i=1;i<=44;i++)
        cout<<v4[i]<<" ";
            player3(nr,plecat3_1,plecat3_2,plecat3_3,plecat3_4);
        system("pause");

        cout<<endl<<"vector mare ";
        for(i=1;i<=70;i++)
        cout<<v[i]<<" ";
        cout<<endl<<"Vector mic3 ";
        for(i=1;i<=44;i++)
        cout<<v3[i]<<" ";

        cout<<"--PLAYER4--"<<endl;
        nr=zar();

        if(v[83]!='c' && v[84]!='c' && v[85]!='c' && v[86]!='c')
            break;
        else
            player4(nr,plecat4_1,plecat4_2,plecat4_3,plecat4_4);
        system("pause");
        cout<<endl<<"vector mare ";
        for(i=1;i<=70;i++)
        cout<<v[i]<<" ";
        cout<<endl<<"Vector mic4 ";
        for(i=1;i<=44;i++)
        cout<<v4[i]<<" ";
    }
    return 0;
}

