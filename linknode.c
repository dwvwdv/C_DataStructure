#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct n
{
    int val;
    struct n *next;
} Node;

Node *initList();
bool destroyList(Node *head);

int main()
{
    Node *head = initList();
    destroyList(head);
}

Node *initList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    return head;
}

bool destroyList(Node *head)
{
    if (!head)
        return true;
    Node *temp,*temp1;
    temp = head->next;
    temp1 = temp->next;
    while(temp){
        free(temp);
        temp = temp1;
        temp1 = temp->next;
    }
    // while (head)
    // {
    //     Node *np = head;
    //     if(np && head){
    //         printf("都有東西");
    //     }
    //     free(np);
    //     head = head->next;
    //     np = head;
    // }
    return true;
}
