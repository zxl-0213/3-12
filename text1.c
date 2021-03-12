typedef struct {
    int* a;
    int n;
    int front;
    int rear;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* cp=(MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    cp->a=(int*)malloc(sizeof(int)*(k+1));
    cp->n=k+1;
    cp->front=0;
    cp->rear=0;
    return cp;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj))
    {
        return false;
    }
    obj->a[obj->rear]=value;
    obj->rear++;
    if(obj->rear==obj->n)
    {
        obj->rear=0;
    }
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
    {
        return false;
    }
    obj->front++;
    if(obj->front==obj->n)
    {
        obj->front=0;
    }
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    return obj->a[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
    {
        return -1;
    }
    

    if(obj->rear==0)
    {
        int prev=obj->rear-1;
        prev=obj->n-1;
        return obj->a[prev];
    }
    return obj->a[obj->rear-1];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    
    return obj->rear==obj->front;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    int next=obj->rear+1;
    next%=obj->n;
   
    return obj->front==next;
   
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/