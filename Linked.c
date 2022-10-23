#include <stdio.h>
#include <stdlib.h>

// linklist
// 1.init
// 2.add
// 3.del
// 4.search
// 5.modify


int* initList();
void addValInList(int *list,int val);
void delValInList(int *list,int val);
int searchValInList(int *list,int val);
void modValInList(int *list,int val,int newVal);

const int maxSize = 100;
int listTop = -1;

// init
int* initList(){
    int *list = (int *)malloc(sizeof(int) * maxSize);
    return list;
}

// add
void addValInList(int *list,int val){
    if(!list || listTop == maxSize)
        return;
    list[++listTop] = val;
}

//del
void delValInList(int *list,int val){
    if(!list || listTop == -1)
        return;
    for(int i = 0;i <= listTop;++i){
        if(list[i] == val){
            for(int j = i;j < listTop;++j){
                list[j] = list[j+1];
            }
            --listTop;
            break;
        }
    }
}

// search
int searchValInList(int *list,int val){
    if(!list || listTop == -1)
        return -1;
    for(int i=0;i<=listTop;++i){
        if(list[i] == val){
            return i;
        }
    }
    return -1;
}

// modify
void modValInList(int *list,int val,int newVal){
    if(!list || listTop == -1)
        return;
    int index = searchValInList(list,val);
    list[index] = newVal;
}


int main(){
    int *list = initList();
    addValInList(list,50);
    printf("now list[%d] = %d\n",listTop,list[listTop]);
    addValInList(list,70);
    addValInList(list,20);
    printf("now list[%d] = %d\n",listTop,list[listTop]);
    delValInList(list,50);
    printf("now list[%d] = %d\n",listTop,list[listTop]);
    modValInList(list,20,82);
    printf("now list[%d] = %d\n",listTop,list[listTop]);
    return 0;
}