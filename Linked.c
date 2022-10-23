#include <stdio.h>
#include <stdlib.h>

// linklist
// 1.init
// 2.add
// 3.del
// 4.search
// 5.modify

const int maxSize = 100;
int listTop = -1;

//init
int* initList(){
    int *list = (int *)malloc(sizeof(int) * maxSize);
    return list;
}

//add
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

int main(){
    int *list = initList();
    addValInList(list,50);
    printf("now list[%d] = %d\n",listTop,list[listTop]);
    addValInList(list,70);
    addValInList(list,20);
    printf("now list[%d] = %d\n",listTop,list[listTop]);
    delValInList(list,50);
    printf("now list[%d] = %d\n",listTop,list[listTop]);
    return 0;
}