 #ifndef _QUEUE_H
 #define _QUEUE_H

 typedef struct {
     int front;
     int rear;
     double* arr;
 } queue_t;

 queue_t* create(int size);
 void destroy(queue_t* this);
 int size(queue_t* this);
 void enqueue(queue_t* this, double item);
 double dequeue(queue_t* q);

 #endif