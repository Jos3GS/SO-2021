 #include "queue.h"
 #include <stdlib.h>

 static void init(queue_t* this, int size) {
     this->front = 0;
     this->rear = 0;
     this->arr = (double*)malloc(size * sizeof(double));
 }

 queue_t* create(int size){
     queue_t* q = malloc(sizeof(queue_t));
     init(q,size);
     return(q);
 }

 void destroy(queue_t* this){
     free(this->arr);
     free(this);
 }

 int size(queue_t* this){
     return this->rear - this->front;
 }

 void enqueue(queue_t* this, double item) {
     this->arr[this->rear] = item;
     this->rear++;
 }

 double dequeue(queue_t* this) {
     double item = this->arr[this->front];
     this->front++;
     return item;
 }