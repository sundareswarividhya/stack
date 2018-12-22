
#include "stack.h"

void help(void);

main()
{
	stack_t *sd;
	int nmax;
	int choice;
	int num;

	printf("Enter the max items to push:\t");
	scanf("%d", &nmax);
	if ((nmax <= MIN_ITEMS) || (nmax >= MAX_ITEMS)) {
		fprintf(stderr, "nmax should be in range of %d...%d\n", MIN_ITEMS, MAX_ITEMS);
		exit(1);
	}

	sd = open_stack(nmax, sizeof num);
	if (sd == NULL) {
		fprintf(stderr, "Failed to open stack\n");
		exit(1);
	}

	while (1) {
		printf("\n\n Enter 1 to push, 2 for pop, 3 for exit,");
		printf("Enter your choice: \t");
		scanf("%d", &choice);
		switch (choice) {
		case PUSH_OP:
			if (is_stack_full(sd)) {
				fprintf(stderr, "stack is full\n");
			} else {
				printf("Enter the number to push:\t");
				scanf("%d", &num);
				push(sd, &num);
			}
			break;
		case POP_OP:
			if (is_stack_empty(sd)) {
				fprintf(stderr, "stack is empty\n");
			} else {
				pop(sd, &num);
				printf("Popped num is : %d\n", num);
			}
			break;
		case EXIT_OP:
			printf("Bye\n");
			exit(1);
		default:
			help();
			break;
		}
	}
}

void help (void)
{
		printf("\n\n Enter 1 to push, 2 for pop, 3 for exit\n");
}	

	
