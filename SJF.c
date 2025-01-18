#include<stdio.h>
#include<stdlib.h>
struct process{
  int pid;
  int burst_time;
  int waiting_time;
  int completion_time;
}*aswp,*swap;
void printtable(struct process * a[],int nb_process){
    printf("PROCESS\tARRIVAL TIME\tBURST TIME\tCOMPLETION TIME\t\tTURN AROUND\tWAITING TIME\n");
for(int i=0;i<nb_process;i++)
  printf("P%d \t\t0 \t\t%d\t\t %d\t\t%d\t\t %d\n",a[i]->pid,a[i]->burst_time,a[i]->completion_time,a[i]->completion_time,a[i]->waiting_time);
}
void average(struct process * a[],int nb_process){
  float b=0,c=0;
  float average_tt,average_wt;
  for(int i=0;i<nb_process;i++){
     b = b + a[i]->completion_time;
     c= c + a[i]->waiting_time;
  }
  average_tt = b / nb_process;
  average_wt = c / nb_process;
printf("the average of turnaround time is :%.2f\n",average_tt);
printf("the average of waiting time is :%.2f\n",average_wt);
 }
void ganttchart(struct process *a[],int nb_process,int *c,int *w){
     for(int i=0;i<nb_process;i++)
     printf("P%d\t",a[i]->pid);
     printf("\n");
      for(int i=0;i<nb_process;i++){
           *c+=a[i]->burst_time;
           a[i]->completion_time=*c;
             printf("%d\t",*c);
      }
      printf("\n");
 for(int i=0;i<nb_process;i++){
  a[i]->waiting_time= a[i]->completion_time - a[i]->burst_time;
    *w+=a[i]->waiting_time;
  }
}
void allocprocess(struct process * a[],int nb_process){
    for(int i=0;i<nb_process;i++){
      a[i]=(struct process *)malloc(sizeof(struct process));
       if(a[i]==NULL)
         printf("ALLOCATION FAILED!");
    }
}
void fillprocessinfo(struct process *a[],int nb_process){
  for(int i=0;i<nb_process;i++){
    a[i]->pid=i+1;
        printf("enter the burst time of P%d:",a[i]->pid);
   scanf("%d",&a[i]->burst_time);
  }
}
void comparasion(struct process *a[],int nb_process){
    swap=(struct process *)malloc(sizeof(struct process));
  for(int i=0;i<nb_process;i++){
    for(int j=i+1;j<nb_process;j++){
      if(a[i]->burst_time > a[j]->burst_time){
         *swap=*a[i];
         *a[i]=*a[j];
         *a[j]=*swap;
       }
     }
  }
  free(swap);
}
 int main(){
  int c=0,w=0,n=0,nb_process=0;
  struct process *a[10],*swap=NULL;
  printf("SJF SCHEDULING\n");
  // get the number of process 
  printf("Enter the process nb of process:");
  scanf("%d",&nb_process);
  // alloc the processes needed 
    allocprocess(a,nb_process);
  // fill the informations about processes
    fillprocessinfo(a,nb_process);
  // comparasion of processes according to burst time 
    comparasion(a,nb_process);
  //initialize the members
   for(int i=0;i<nb_process;i++){
     a[i]->waiting_time=0;
     a[i]->completion_time=0;
  }
  //ganttchart
  ganttchart(a,nb_process,&c,&w);
// the table 
       printtable(a,nb_process);
 // the average of waiting time and waiting time 
  average(a,nb_process);
  // freeing the allocated structure 
for(int i=0;i<nb_process;i++)
  free(a[i]);
  return 0;
}

 
 
