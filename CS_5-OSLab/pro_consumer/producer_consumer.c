#include<stdio.h>
void main()
{
	int buffer[10], bufsize, in, out, produce, consume, choice=0;
	in = 0;
	out = 0;
	bufsize = 5;
	while(choice !=3)
	{
		printf(" \n 1.Producer \t 2.Consumer \t 3. Exit");
		printf("\nEnter your choice:");
		scanf("%d", &choice);
		switch(choice) 
		{
			case 1: if((in+1)%bufsize==out)
					printf("\n Buffer is Full");
				else
				{
					printf("\nEnter the value: ");
					scanf("%d", &produce);
					buffer[in] = produce;
					in = (in+1)%bufsize;
				}
				break;
			case 2: if(in == out)
					printf("\n  Buffer is Empty");
				else
				{
					consume = buffer[out];
					printf("\nThe consumed value is %d", consume);
					out = (out+1)%bufsize;
				}
				break;
		}
	} 
}
