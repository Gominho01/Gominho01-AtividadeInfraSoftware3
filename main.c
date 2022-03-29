#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct queue {
    int begin_t;
    int end_t;
    struct queue *next;
};
void queue(struct queue **head, struct queue **tail, int a, int b)
{
  	struct queue *novo = (struct queue *)malloc(sizeof(struct queue));
  	if (novo != NULL){
    		novo-> begin_t = a;
    		novo -> end_t = b;
    		novo->next = NULL;
    
    		if (isEmpty(*head)){
      			*head = novo;
      			*tail = novo;
    		}
        else{
      			(*tail)->next = novo;
      			*tail = novo;
    		}
  	}
}

int isEmpty(struct queue *head) 
{
	return head == NULL;
}

int main()
{
  struct queue *head = NULL;
	struct queue *tail = NULL;
  struct queue *aux = head;
  int i, x, process_n, total = 0, count = 0, quantum;
  int wait_t = 0, answer_t = 0, active_t = 0, begin_t = 0, end_t = 0;
  float wait_ave, answer_ave, active_ave;
  scanf("%d %d", &process_n, &quantum);
  
  for (int i = 0; i < process_n; i++) {
      scanf("%d %d", &begin_t, &end_t);
      queue(&head,&tail, begin_t, end_t);
  }
  x = process_n;
  
  for (total = 0, i = 0; x != 0;)  {
      if (aux -> end_t <= quantum && aux -> end_t > 0) {
          total = total + aux -> end_t;
          aux -> end_t = 0;
          count = 1;
      }
      else if (aux -> end_t > 0) {
          aux -> end_t = aux -> end_t - quantum;
          total = total + quantum;
      }
      if (aux -> end_t == 0 && count == 1) {
          wait_t += total - aux -> begin_t - aux -> begin_t;
          active_t += total;
          answer_t += total - aux -> begin_t;
          x--;
          count = 0;
      }
      if (aux -> next == NULL) { 
          aux = head;          
      }
      else if (head -> next -> begin_t <= total) {
          aux = aux -> next;
      }
      else {
          aux = head;
      }
  }
  
  wait_ave = wait_t * 1.0 / process_n;
  answer_ave = answer_t * 1.0 / process_n;
  active_ave = active_t * 1.0 / process_n;
  printf("\nRR %.1f %.1f %.1f", active_ave, answer_ave, wait_ave);

  return 0;
}
