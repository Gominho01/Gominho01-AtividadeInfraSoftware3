# AtividadeInfraSoftware4

## Proposito do código

>O código vai pedir para você digitar a quantidade de threads e quantums, depois ele vai entrar em um for que vai depender da quantidade threads, então ele vai receber o tempo que a thread vai chegar, e quanto tempo ele vai demorar pra terminar o processo. Depois disso ele vai printar a média do tempo ativo, a média do tempo de resposta e a média do tempo de espera

## Funções mínimas do makefile

> Tem 3 funções essenciais pedidas nessa tarefa, o make que compila o código e gera o binário, o make run pra compilar o código e o make clear para apagar o binário gerado.

## Funções no código e declaração da struct

```c 
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
```
Essa é a declaração da Struct e suas funções, queue para adicionar algo na fila e isempty para ver se tem algo dentro dela
## Inicio do main
```c
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
```
Declaração das variaveis do main + scanf

  
## Lógica
```c
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
```
Nessa parte tem toda a lógica do código + o print final

