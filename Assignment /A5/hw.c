#include <stdio.h>
#include <stdlib.h>

typedef struct{int u,v,w;}E;

int find(int *p,int i){
    if(p[i]!=i)p[i]=find(p,p[i]);
    return p[i];
}

void unionSets(int *p,int *r,int x,int y){
    int xr=find(p,x);
    int yr=find(p,y);
    if(xr!=yr){
        if(r[xr]<r[yr])p[xr]=yr;
        else if(r[xr]>r[yr])p[yr]=xr;
        else{
            p[yr]=xr;
            r[xr]++;
        }
    }
}

int cmp(const void *a,const void *b){
    return((E*)a)->w-((E*)b)->w;
}

int main(){
    int f;
    scanf("%d",&f);
    if(f==0){
        int n,q;
        scanf("%d%d",&n,&q);
        int *p=malloc((n+1)*sizeof(int));
        int *r=calloc(n+1,sizeof(int));
        for(int i=1;i<=n;i++)p[i]=i;
        for(int i=0;i<q;i++){
            int q,u,v;
            scanf("%d%d%d",&q,&u,&v);
            if(q==0)unionSets(p,r,u,v);
            else printf("%d ",find(p,u)==find(p,v)?1:0);
        }
        free(p);
        free(r);
    }else{
        int n;
        scanf("%d",&n);
        E *e=malloc(n*n*sizeof(E));
        int ec=0;
        for(int i=0;i<n;i++){
            int v,w;
            while(1){
                scanf("%d",&v);
                if(v==-1)break;
                scanf("%d",&w);
                e[ec].u=i+1;
                e[ec].v=v;
                e[ec].w=w;
                ec++;
            }
        }
        qsort(e,ec,sizeof(E),cmp);
        int *p=malloc((n+1)*sizeof(int));
        int *r=calloc(n+1,sizeof(int));
        for(int i=1;i<=n;i++)p[i]=i;
        int mw=0;
        for(int i=0;i<ec;i++){
            int u=e[i].u;
            int v=e[i].v;
            if(find(p,u)!=find(p,v)){
                unionSets(p,r,u,v);
                mw+=e[i].w;
            }
        }
        printf("%d ",mw);
        free(e);
        free(p);
        free(r);
    }
    return 0;
}
