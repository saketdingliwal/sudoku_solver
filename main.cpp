#include <bits/stdc++.h>

using namespace std;

int a[10][10];
int prob[10][10][10]={0,0};
int p[81],q[81];
int dash=1;

void display()
{
for(int f=1;f<10;f++)
{
for(int g=1;g<10;g++)
{
cout <<a[f][g]<< " ";
}
cout <<endl;
}
}

void prob_update(int p,int q)
{
for(int i=1;i<10;i++)
{prob[p][q][i]=0;}
bool chk[10]={false,false};
for(int i=1;i<10;i++)
{
chk[a[p][i]]=true;
chk[a[i][q]]=true;
}
int r=p%3;
if(r==0){r=3;}
int t=q%3;
if(t==0){t=3;}
for(int i=1;i<=3;i++)
{
for(int j=1;j<=3;j++)
{
chk[a[p-r+i][q-t+j]]=true;
}
}
int j=1;
for(int i=1;i<10;i++)
{

if(chk[i]==false)
{
prob[p][q][j]=i;
j++;

//cout<<i<<" ";

}
}
//if(j==1)cout<<"show me";
}

bool chk(int x)
{
bool sol=true;int j;
for(j=x-1;j<dash;j++)
{
if(prob[p[j]][q[j]][1]==0){return false;}
}
if(j==dash){return true;}
}








int main()
{
for(int i=1;i<10;i++)
{for(int j=1;j<10;j++)
 {cin >> a[i][j];}
}
for(int i=1;i<10;i++)
{for(int j=1;j<10;j++)
 {if(a[i][j]==0){p[dash]=i;q[dash]=j;dash++;}}
}




int j=1;

do
{
do
{
for(int i=j;i<dash;i++)
{
prob_update(p[i],q[i]);
//cout <<endl;
}
if(chk(j+1)==false){break;}
a[p[j]][q[j]]=prob[p[j]][q[j]][1];
j++;
//cout << "updated"<<prob[p[4]][q[4]][2]<<endl;
}while(j<dash);
if(j==dash){display();return 0;}
j=j-1;
a[p[j]][q[j]]=0;
while(prob[p[j]][q[j]][2]==0)
{j--; //cout <<"dds"<<j<<prob[p[j]][q[j]][2];
a[p[j]][q[j]]=0;
}

for(int k=1;k<9;k++)
{prob[p[j]][q[j]][k]=prob[p[j]][q[j]][k+1];
}
a[p[j]][q[j]]=prob[p[j]][q[j]][1];
j++;
}while(1>0);










}
