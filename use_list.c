#include<stdio.h>
#include<stdlib.h>

typedef struct Datas{
    int num;
    Datas *next;
}Datas;

Datas* init_Datas(){
    Datas *head = (Datas*)malloc(sizeof(Datas));
    head->next = NULL;
    return head;
}

Datas* creat_data(Datas *head, int data){
    Datas *r, *newdata;
    r = head;
    newdata = (Datas*)malloc(sizeof(Datas));
    newdata->num = data;
    newdata->next = NULL;
    r->next = newdata;

    return newdata;
}

Datas* find_num(Datas* head, int a){
    Datas* cur = head;
    while(cur){
        if(cur->num == a){ return cur; }
        cur = cur->next;
    }
    return NULL;
}

void insert_data(Datas* p, int data){
    Datas *cur = (Datas*)malloc(sizeof(Datas));
    cur->num = data;
    cur->next = p->next;
    p->next = cur;
}

void delete_data(Datas *head, Datas *p){
    Datas *cur = head;
    while(cur){
        if(cur->next == p){ break; }
        cur = cur->next;
    }
    Datas *new_data = p->next;
    cur->next = new_data;
    free(p);
}

void free_Datas(Datas *head){
    Datas *p = head->next;
    Datas *q = p;
    while(p){
        p = p->next;
        free(q);
        q = p;
    }
    //free(head);
    head->next = NULL;
}

int main(){

    Datas *d1 = init_Datas();
    int num = 0;
    d1->num = num; 
    num++;
    Datas* d2 = creat_data(d1, num);
    num++;
    Datas* d3 = creat_data(d2, num);
    num++;
    Datas* d4 = creat_data(d3, num);

    Datas* cur = d1;

    insert_data(d3, 5);
    delete_data(d1, d2);
    free_Datas(d1);


    // while(cur){
    //     printf("%d\n", cur->num);
    //     cur = cur->next;
    // }

    printf("%d", d1->num);

    return 0;
}