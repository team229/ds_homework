#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} linknode, *link;

link Create(link head)
{
    head->next = NULL;
    return head;
}

link insert(link position, int data)
{
    link temp = malloc(sizeof(linknode));
    temp->data = data;
    temp->next = position->next;
    position->next = temp;
    return temp;
}

link delete(link pre){
    link node=pre->next;
    pre->next=node->next;
    free(node);
    return pre->next;
}

void Print(link head)
{
    link temp = head->next;
    while (temp)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int people, begin, interval,log=0;
    link loop = malloc(sizeof(linknode)), temp,start;
    Create(loop);
    temp = loop;

    scanf("%d%d%d", &people, &begin, &interval);
    //加里森编号为 1
    if(interval<2){
        printf("No!Jia Lisen can't avoid!");
        return 0;
    }
    for (int i = 0; i < people; i++){
        temp = insert(temp, i + 1);
        if(i+1==begin)
            start=temp;
    }
    //构成循环
    temp->next = loop->next;

    
    //进行筛选，直到剩下一个人
    while (start->next != start)
    {
        log=1;
        while((log+1)!=interval){
            start=start->next;
            log++;
        }
        start=delete(start);
        printf("%d\n",start->data);
        
    }

    if(start->data==1)
        printf("Yes!");
    else
        printf("No!Number %d can avoid!",start->data);
}