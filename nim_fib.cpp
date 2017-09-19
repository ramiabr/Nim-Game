#include <stdio.h>
using namespace std;

// Find Fib sequence from 0 to n 
int findLargestFib (int *F, int n) {	
	F[0] = 0;
	F[1] = 1;
	
	int a = 0;  int b = 1; int c = 0;
	
	for(int i=0; i <= n ; i++) {
		c = a + b ; 
		a    = b; 
		b    = c;		
	
		// Break if Fib numbers generated are > n
		if(c > n) {
			break;
		}
		F[c] = c;
	}
	
	int prev = 0;
	for(int i=0 ; i <= n; i++) {
		if(F[i] != 0)  prev = F[i]; 		
		if(F[i] == 0)  F[i] = prev;		
		//printf("%d = %d \n", i, F[i]);
	}
		
	return 0;
}


int findMaxMove(int p, int r, int *F) {	
	int n = p;
	int next = 0;
	int prev = 0;
	int tmp  = 0;
	int move = 0;
	
	while(n > 0) {
	        tmp = F[n];
		
		move = p-next;
		//printf("%d, %d \n", prev, move);
		
		if( (prev > 2*move || move == p) && move <= r) return move;			
		next += tmp;
		n = n - tmp;	
		prev = tmp;
		
		if(n == 0) break;
	}	
	return 0;
}


int main () {
	//int n = 105;
	int n;
	
	// Let F be an array which stores largest Fib number 
	// such that Fi < i  
	
	// Get Total number of Chips from User
 	printf("Enter Total no of Chips :");
 	scanf("%d", &n);
	int F[n];

	//n = 51;
	
	// Initialize F array to Zero 	
	for(int i=0; i <=n ; i++) {
		F[i] = 0;
	}
	
	// Find Fibonacci Sequence from 0 to n
	findLargestFib(F, n);

/* 	for(int i =1; i<= n; i++) {
		printf("\t%d",i);
	}
	printf("\n");
 /	
	// Calculate Winning move				
	for(int p=1; p<=n; p++) {				   	   
		//printf("%d", p);			        
		for(int r=1; r <= n; r++) {			

			int move = findMaxMove(p, r, F);								
			//if(r<=p)
			//	printf("\t%d",move);		
			
		}
		//printf("\n");
	}
	
	//printf("Result = %d \n", findMaxMove(55, 54, F));
*/
	
	// 
	int i = n;
	int prev_move = n-1;
	int pmove = 0;
	
 	// Nim Game
	while(i>0) {
		//int move_old = w[i][prev_move];
		int move = findMaxMove(i, prev_move, F);
		if(move == 0) move = 1;
		i = i - move;
		
		printf("[Algo] removes; %d, Remaining Chips: %d\n", move, i);
		
		if(i <=0) {
			printf("Algo Wins !!\n\n");
			break;
		}
		
		printf("[Player] move: ");
		scanf("%d", &pmove);	
		
		if(pmove > 2*move)  {
			pmove = 2*move;
			printf("max allowed=%d\n",2*move);
		}
		i = i- pmove;
		printf("[Play] removes: %d, Remaining Chips: %d\n", pmove, i);
		prev_move = 2 * pmove;
	
		if(i <=0) {
			printf("Player Wins !!\n\n");
			break;
		}
	}
 	
	
	
	return 0;
}
