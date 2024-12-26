#include<stdio.h>
#include<stdlib.h>
#define M 1000
int s[M],t=-1,q[M],f=0,r=0,c=0,h[M],hs=0;

void psh(int v,int m){
    if(t==m-1){
        printf("-1\n");
        exit(0);
    }
    s[++t]=v;
}

int pp(){
    if(t==-1){
        printf("-1\n");
        exit(0);
    }
    return s[t--];
}

void ps(){
    for(int i=0;i<=t;i++)
        printf("%d ",s[i]);
    printf("\n");
}

void enq(int v,int m){
    if(c==m-1){
        printf("-1\n");
        exit(0);
    }
    q[r]=v;
    r=(r+1)%m;
    c++;
}

int deq(int m){
    if(c==0){
        printf("-1\n");
        exit(0);
    }
    int v=q[f];
    f=(f+1)%m;
    c--;
    return v;
}

void pq(int m){
    if(c==0){
        printf("\n");
        return;
    }
    int i=f;
    for(int j=0;j<c;j++){
        printf("%d ",q[i]);
        i=(i+1)%m;
    }
    printf("\n");
}

void swp(int*a,int*b){
    int t=*a;
    *a=*b;
    *b=t;
}

void hf(int i){
    int sm=i,l=2*i+1,r=2*i+2;
    if(l<hs&&h[l]<h[sm])
        sm=l;
    if(r<hs&&h[r]<h[sm])
        sm=r;
    if(sm!=i){
        swp(&h[i],&h[sm]);
        hf(sm);
    }
}

void bh(int v[],int n,int m){
    if(n>m){
        printf("-1\n");
        exit(0);
    }
    hs=n;
    for(int i=0;i<n;i++)
        h[i]=v[i];
    for(int i=n/2-1;i>=0;i--)
        hf(i);
}

void ph(){
    for(int i=0;i<hs;i++)
        printf("%d ",h[i]);
    printf("\n");
}

int em(){
    if(hs==0){
        printf("-1\n");
        exit(0);
    }
    int r=h[0];
    h[0]=h[--hs];
    hf(0);
    return r;
}

void dk(int i,int nv){
    if(i<0||i>=hs||h[i]<nv)
        return;
    h[i]=nv;
    while(i!=0&&h[(i-1)/2]>h[i]){
        swp(&h[i],&h[(i-1)/2]);
        i=(i-1)/2;
    }
}

int main(){
    int o,m;
    scanf("%d%d",&o,&m);
    if(o==0){
        int a,b;
        while(scanf("%d",&a)!=EOF){
            if(a==0){
                ps();
            }else if(a==1){
                scanf("%d",&b);
                psh(b,m);
            }else if(a==2){
                printf("%d\n",pp());
            }else if(a==3){
                break;
            }
        }
    }else if(o==1){
        int a,b;
        while(scanf("%d",&a)!=EOF){
            if(a==0){
                pq(m);
            }else if(a==1){
                scanf("%d",&b);
                enq(b,m);
            }else if(a==2){
                printf("%d\n",deq(m));
            }else if(a==3){
                break;
            }
        }
    }else if(o==2){
        int a1,a2,a3;
        while(scanf("%d",&a1)!=EOF){
            if(a1==0){
                ph();
            }else if(a1==1){
                scanf("%d",&a2);
                int v[M];
                for(int i=0;i<a2;i++)
                    scanf("%d",&v[i]);
                bh(v,a2,m);
            }else if(a1==2){
                scanf("%d%d",&a2,&a3);
                dk(a2-1,a3);
            }else if(a1==3){
                printf("%d\n",em());
            }else if(a1==4){
                break;
            }
        }
    }
    return 0;
}
