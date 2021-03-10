#include <stdio.h>
 #include "queue.h"

 int main(int argc, char** argv) {

     queue_t* q = create(10);
     enqueue(q, 6.5);
     enqueue(q, 1.3);
     enqueue(q, 2.4);
     printf("%f\n", dequeue(q));
     printf("%f\n", dequeue(q));
     printf("%f\n", dequeue(q));
     destroy(q);
     return 0;
 }