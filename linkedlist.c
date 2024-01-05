#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[],int n){
    int i;
    struct Node*t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void create2(int A[],int n){
    int i;
    struct Node*t,*last;
    second=(struct Node*)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;
    for(int i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct Node*p){
    printf("\n");
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

void rdisplay(struct Node*p){
    if(p!=NULL){
        printf("%d ", p->data);
        rdisplay(p->next);
    }
}

int count(struct Node*p){
    int l=0;
    while(p){
        l++;
        p=p->next;
    }
    return l;
}
int rcount(struct Node*p){
    if(p!=0){
        return rcount(p->next)+1;
    }
    else
        return 0;
}
int sum(struct Node*p){
    int s=0;
    while(p){
        s+=p->data;
        p=p->next;
    }
    return s;
}
int rsum(struct Node*p){
    if(p){
        return p->data + rsum(p->next);
    }
    else
        return 0;
}
int max(struct Node*p){
    int m=-32676;
    while(p){
        if(p->data>m)
            m=p->data;
        p=p->next;
    }
    return m;
}
struct Node* search(struct Node*p,int key){
    struct Node*q;
    while(p){
        if(key==p->data){
            q->next=p->next;
            p->next=first;
            first=p;
            return (p);
        }
        q=p;  
        p=p->next;
    }
    if(p==NULL)
        return NULL;
}
struct Node* rsearch(struct Node*p,int key){
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return(p);
    return rsearch(p->next,key);
} 
void insert(struct Node*p,int index,int x){
    struct Node*t;
    int i;
    if(index<0 || index>count(p))
        return;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0){
        t->next=first;
        first=t;
    }
    else{
        for(i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}
void sortedinsert(struct Node*p,int x){
    struct Node*t,*q=NULL;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
        first=t;
    else{
        while(p && p->data<x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=p;
            first=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}
int Delete(struct Node*p,int index){
    struct Node*q=NULL;
    int x=-1,i;
    if(index<1 || index>count(p))
        return -1;
    if(index==1){
        q=first;
        first=first->next;
        x=q->data;
        free (q);
        return x;
    }
    else{
        for(i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free (p);
    }
}
int issorted(struct Node*p){
    int x=-65536;
    while(p!=NULL){
        if(p->data<x)
            return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}
void removeduplicate(struct Node*p){
    struct Node*q=p->next;
    while(q!=NULL){
        if(q->data!=p->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            free (q);
            q=p->next;
        }
    }
}
void reverse1(struct Node*p){
    int *A;
    struct Node*q=p;
    A=(int *)malloc(sizeof(int)*count(p));
    int i=0;
    while(q!=NULL){
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL){
        q->data=A[i];
        q=q->next;
        i--;
    }
}
void reverse2(struct Node*p){
    struct Node*q=NULL,*r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
void reverse3(struct Node*q,struct Node*p){
    if(p){
        reverse3(p,p->next);
        p->next=q;
    }
    else
        first=q;
}
void concat(struct Node*p,struct Node*q){
    third=p;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
}
void merge(struct Node*p,struct Node*q){
    struct Node*last;
    if(p->data<q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p && q){
        if(p->data<q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)last->next=p;
    if(q)last->next=q;
}
int isLoop(struct Node*f){
    struct Node*p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);
    if(p==q)
        return 1;
    else
        return 0;
}
int main(){
   
    int A[]={10,20,30,40,50};
    create(A,5);
    display(first);
    return 0;
}