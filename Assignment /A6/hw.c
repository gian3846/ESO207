#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#define MAX 100
int op(int a,int b,int o){
switch(o){
case-1:return a-b;
case-2:return a+b;
case-3:return a*b;
case-4:return a/b;
case-5:return pow(a,b);
default:return 0;
}
}
int pre(int o){
if(o==-5)return 3;
if(o==-3||o==-4)return 2;
if(o==-1||o==-2)return 1;
return 0;
}
int ra(int o){
return o==-5;
}
int ev(int ex[],int n){
int v[MAX],p[MAX],vt=-1,pt=-1;
for(int i=0;i<n;i++){
if(ex[i]>=0){
v[++vt]=ex[i];
}
else if(ex[i]==-6){
p[++pt]=-6;
}
else if(ex[i]==-7){
while(p[pt]!=-6){
int b=v[vt--];
int a=v[vt--];
int o=p[pt--];
v[++vt]=op(a,b,o);
}
pt--;
}
else{
while(pt!=-1&&p[pt]!=-6&&(pre(p[pt])>pre(ex[i])||(pre(p[pt])==pre(ex[i])&&!ra(ex[i])))){
int b=v[vt--];
int a=v[vt--];
int o=p[pt--];
v[++vt]=op(a,b,o);
}
p[++pt]=ex[i];
}
}
while(pt!=-1){
int b=v[vt--];
int a=v[vt--];
int o=p[pt--];
v[++vt]=op(a,b,o);
}
return v[vt];
}
int mcm(int a[],int n){
int**dp=(int**)malloc(n*sizeof(int*));
for(int i=0;i<n;i++){
dp[i]=(int*)malloc(n*sizeof(int));
for(int j=0;j<n;j++)dp[i][j]=0;
}
for(int l=2;l<n;l++){
for(int i=1;i<n-l+1;i++){
int j=i+l-1;
dp[i][j]=INT_MAX;
for(int k=i;k<j;k++){
int c=dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j];
if(c<dp[i][j])dp[i][j]=c;
}
}
}
int r=dp[1][n-1];
for(int i=0;i<n;i++)free(dp[i]);
free(dp);
return r;
}
int main(){
int o;
if(scanf("%d",&o)!=1)return 1;
if(o==0){
int n;
if(scanf("%d",&n)!=1||n<=0)return 1;
int ex[n];
for(int i=0;i<n;i++){
if(scanf("%d",&ex[i])!=1)return 1;
}
printf("%d",ev(ex,n));
}
else if(o==1){
int n;
if(scanf("%d",&n)!=1||n<=1)return 1;
int a[n];
for(int i=0;i<n;i++){
if(scanf("%d",&a[i])!=1)return 1;
}
printf("%d",mcm(a,n));
}
return 0;
}
