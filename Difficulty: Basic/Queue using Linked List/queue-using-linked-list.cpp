/* Linked list node */
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to push an element into the queue.
void MyQueue::push(int x) {
    QueueNode* temp = new QueueNode(x);
    if (rear == NULL) { // empty queue
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

// Function to pop front element from the queue.
int MyQueue::pop() {
    if (front == NULL) // empty queue
        return -1;

    int val = front->data;
    QueueNode* temp = front;
    front = front->next;

    if (front == NULL) // queue becomes empty
        rear = NULL;

    delete temp;
    return val;
}
