//========== e NFA to NFA ===============================

#include<stdio.h>

typedef struct Node{
	int transition[5];
	}Node;
	
Node node[10];	

// e_closure() find and store e-closures to e_arr
int e_arr[10];

// intermediate e-closure calculated are stored in e_sub_arr
int e_sub_arr[10];

// contains the alphabets a,b,c......
char alphabets[10];
	

// map characters to an index value a-1, b-2 .....
int map(char a){

	if( a =='e' )
		return 0;	
	int i;
	i=a-96;
	return i;
}


// find e-closure of node e and store the result(indexes) in res[]
int e_closure(int e, int res[]){
	int count=0, i;
	res[count++] = e; // e closure contain itself
	while(node[e].transition[ map('e') ] !=-1 ){// check if there is an e transition
			i = node[e].transition[ map('e') ]; // return index of next node
			res[count++] = i;
			e = i;// set new node as current node 
	}
	return count;
}

int get_transition(int e,char a){
	if(node[e].transition[ map(a) ] !=-1 ){// check if there is the req transition
			int i = node[e].transition[ map(a) ]; // return index of next node
			return i;
	}
	return -1;
}

void perform(int n,int alpha){
	int i,c,j,r[50],b,p,k,w,copy[50],q;
	for(i=0;i<n;i++){
		c=e_closure(i,e_arr);// finding e-closure
		
		// finding transition for each alphabet
		for(k=0;k<alpha;k++){	
			int cnt=0;
			for(j=0;j<c;j++){
				int flag;
				flag=get_transition(e_arr[j],alphabets[k]);
				if(flag!=-1){// return -1 if no transition
					r[cnt++]=flag;// cnt count no of items
					
				}
			} // finding transition of it for each alphabet
			int count=0;// count no of states after taking 2nd e-closure
			for( w=0;w<cnt;w++){
				b = e_closure(r[w],e_sub_arr);
				for(q=0;q<b;q++){
					copy[count++] = e_sub_arr[q];		
				}
			}
			
			printf("\nState-> %d for alphabet %c >> { ",i,alphabets[k]);
			int print;
			for(p=0;p<count;p++){
				print=1;
				for(int r=p-1;r>0;r--){
					if(copy[p] == copy[r])
						print=0;
				}
				if( print==1)		
					printf(" %d",copy[p]);
			}
			printf(" } ");
		}
	
	}
}

	
int main(){
	/*variables in main()
	 * 	INTEGERS
	 * n - no of nodes
	 * t - no of transitions
	 * a - no of alphabets 
	 *  -1 # indicates No transition for that input alphabet
	 * */
	int n,t,a,state1,state2,i,j;
	char alpha;

	printf("\nEnter the no of states: ");
	scanf("%d",&n);
	printf("\nEnter the no of alphabets: ");
	scanf("%d",&a);
	for(i=0;i<a;i++)
		scanf(" %c",&alphabets[i]);
		
	for(i=0;i<n;i++){
		for(j=0;j<a+1;j++)// for initializing with no transition, a+1 for including epsilon
			node[i].transition[j] = -1;
			
	}
	printf("\nEnter the no of transitions: ");
	scanf("%d", &t);
	printf("nEnter the state table:>>\nSTATE ALPHABET STATE");
	for(i=0;i<t;i++){
		scanf("%d	%c	%d",&state1,&alpha,&state2);
		node[state1].transition[ map(alpha) ] = state2;
	}
	perform(n,a);

}