typedef struct QueueNode
{
    int data;
    struct QueueNode* next;
}QueueNode;
typedef struct Queue
{
    struct QueueNode* front;
    struct QueueNode* back;
}Queue;

//初始化
void QueueInit(Queue* q)
{
    q->front=NULL;
    q->back=NULL;

}

//队尾进数据
void QueuePush(Queue* q,int x)
{
    QueueNode* newnode=(QueueNode*)malloc(sizeof(QueueNode));
    newnode->data=x;
    newnode->next=NULL;
    if(q->front==NULL)
    {
        q->front=q->back=newnode;
    }
   else
   {
        q->back->next=newnode;
        q->back=newnode;
   } 
}

//队头出数据
void QueuePop(Queue* q)
{
    QueueNode* cur=q->front->next;
    free(q->front);
    q->front=cur;
}

//获取队列头部元素
int QueueFront(Queue* q)
{
    
    return q->front->data;
}

//获取队尾元素
int QueueBack(Queue* q)
{
    return q->back->data;
}

//获取队列中有效元素个数
int QueueSize(Queue* q)
{
    int count=0;
    QueueNode* cur=q->front;
    while(cur)
    {
        cur=cur->next;
        count++;
    }
    return count;
}

//判断是否为空
int QueueEmpty(Queue* q)
{
    return q->front==NULL?1:0;
}

//销毁队列
void QueueDestroy(Queue* q)
{
    QueueNode* cur=q->front;
    while(cur)
    {
        QueueNode* next=q->front->next;
        free(cur);
        cur=next;
    }
    q->front=q->back=NULL;
}
typedef struct {
    Queue q1;
    Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack* st=(MyStack*)malloc(sizeof(MyStack));
    QueueInit(&st->q1);
    QueueInit(&st->q2);
    return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if(!QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q1,x);
    }
    else
    {
        QueuePush(&obj->q2,x);
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    Queue* pempty=&obj->q1;
    Queue* pnoempty=&obj->q2;
    if(!QueueEmpty(&obj->q1))
    {
        pempty=&obj->q2;
        pnoempty=&obj->q1;
    }
    while(QueueSize(pnoempty)>1)
    {
        QueuePush(pempty,QueueFront(pnoempty));
        QueuePop(pnoempty);
    }
    int top=QueueFront(pnoempty);
    QueuePop(pnoempty);
    return top;

}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    if(!QueueEmpty(&obj->q1))
    {
        return QueueBack(&obj->q1);
    }
    else
    {
        return QueueBack(&obj->q2);
    }
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
   return QueueEmpty(&obj->q1)&&QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/