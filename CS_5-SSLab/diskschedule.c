#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main(){
  int choice,n,start,seek_time,range,temp,index=0,count=0;
  printf("DISK SCHEDULING \n");
  printf("--------------------\n");
  printf("Enter the range : ");
  scanf("%d",&range);
  printf("Enter the number of disk requests : ",range);
  scanf("%d",&n);
  printf("Enter the head position (< %d): ",range);
  scanf("%d",&start);
  if(start>range)
      exit(0);
  printf("Enter the requests : ");
  int disk_req[n],order[n],a[n];
  disk_req[0]=start;
  a[0]=start;
  for(int i=1;i<=n;i++){
      scanf("%d",&disk_req[i]);
      a[i]=disk_req[i];
  }
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n-i-1;j++){
           if(a[j]>a[j+1]){
             temp=a[j];
             a[j]=a[j+1];
             a[j+1]=temp;
            }    
    }
  }
  for(int i=0;i<=n;i++){
      printf("%d \t",a[i]);
  }
  while(1){
    seek_time=0;
    printf("Enter your choice \n1.FCFS\t2.SCAN\t3.C-SCAN\n");
    scanf("%d",&choice);
    switch(choice){
      case 1:{  printf("No\tDisk Req\n");
                order[0]=1;
                printf("%d\t%d\n",order[0],disk_req[0]);
                for(int i=1;i<=n;i++){
                    order[i]=i+1;
                    printf("%d\t%d\n",order[i],disk_req[i]);
                    seek_time+=abs(disk_req[i]-disk_req[i-1]);
              }
              printf("Seek Time : %d ms \n",seek_time);
              break;
      }
      case 2:{
                printf("No\tDisk Req\n");
                for(int i=0;i<=n;i++){
                     if(a[i]==start){
                          index=i;                    
                      }                
                }
                for(int i=index-1;i>=0;i--){
                    printf("%d\t%d\n",count,a[i]);
                    seek_time+=abs(a[i+1]-a[i]);
                    //printf("Seek time :%d\n",seek_time);
                    count++; 
                    if(i==0){
                      printf("%d\t%d\n",count,0);
                      seek_time+=a[0];
                      count++;
                    }
                }
                for(int i=index+1;i<n;i++){
                    if(i==(index+1)){
                       seek_time+=a[i];
                      //  printf("Seek time :%d\n",seek_time);                                
                    }
                    printf("%d\t%d\n",count,a[i]);
                    seek_time+=abs(a[i+1]-a[i]);
                    count++;
                    //printf("Seek time :%d\n",seek_time);  
                    if(i==(n-1))     
                          printf("%d\t%d\n",count,a[n]);   
                }
                printf("Seek Time : %d ms\n",seek_time);
              break;
      }
      case 3:{  count=0;
                printf("No\tDisk Req\n");
                for(int i=0;i<=n;i++){
                     if(a[i]==start){
                          index=i;                    
                      }                
                }
                for(int i=index-1;i>=0;i--){
                    printf("%d\t%d\n",count,a[i]);
                    seek_time+=abs(a[i+1]-a[i]);
                    //printf("Seek time :%d\n",seek_time);
                    count++;
                    if(i==0){
                        printf("%d\t%d\n",++count,0);
                        seek_time+=(a[0]+range); 
                        printf("%d\t%d\n",++count,range-1);       
                        count++;           
                    }
                }
                for(int i=(n-1);i>index-1;i--){
                    printf("%d\t%d\n",count,a[i]);
                    seek_time+=abs(a[i+1]-a[i]);
                    count++;
                }
                printf("Seek Time : %d ms \n",seek_time);
              break;
      }
      default:exit(0);break;
    }
  }
}
