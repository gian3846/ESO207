#include<stdio.h>
#include<limits.h>
#define M 100

int md(int d[],int p[],int n){
    int m=INT_MAX,mi=-1;
    for(int i=0;i<n;i++){
        if(!p[i]&&d[i]<m){
            m=d[i];
            mi=i;
        }
    }
    return mi;
}

void swp(int*x,int*y){
    int t=*x;
    *x=*y;
    *y=t;
}

void srt(int nds[],int d[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(d[j]>d[j+1]){
                swp(&d[j],&d[j+1]);
                swp(&nds[j],&nds[j+1]);
            }
        }
    }
}

void dijk(int g[M][M],int n,int src){
    int d[M],p[M],nds[M];
    for(int i=0;i<n;i++){
        d[i]=INT_MAX;
        p[i]=0;
        nds[i]=i;
    }
    d[src]=0;
    for(int cnt=0;cnt<n-1;cnt++){
        int u=md(d,p,n);
        if(u==-1)break;
        p[u]=1;
        for(int v=0;v<n;v++){
            if(!p[v]&&g[u][v]&&d[u]!=INT_MAX&&d[u]+g[u][v]<d[v]){
                d[v]=d[u]+g[u][v];
            }
        }
    }
    srt(nds,d,n);
    for(int i=0;i<n;i++){
        printf("%d %d ",nds[i],d[i]);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int g[M][M];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            g[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        int j,w;
        while(scanf("%d",&j)&&j!=-1){
            scanf("%d",&w);
            g[i][j]=w;
        }
    }
    int src;
    scanf("%d",&src);
    dijk(g,n,src);
    return 0;
}
