#include<stdio.h>
#include<stdlib.h>
struct process{
  int pid;
  int burst_time;
  int waiting_time;
  float average_tt;
  float average_wt;
  int completion_time;
};
main(){
  int c=0,w=0;
  float s=0;
  int n=0,nb_process=0;
  struct process *a[10],*swap;
  printf("SJF SCHEDULING\n");
  int i=0;
  printf("Enter the process nb of process:");
  scanf("%d",&nb_process);
  for(int i=0;i<nb_process;i++){
    a[i]=(struct process *)malloc(sizeof(struct process));
  }
  for(int i=0;i<nb_process;i++){
    a[i]->pid=i+1;
   printf("enter the burst time:");
   scanf("%d",&a[i]->burst_time);
  }

  // arrangment of processes according to burst time 
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
  // initilize all members
  for(int i=0;i<nb_process;i++){
     a[i]->waiting_time=0;
     a[i]->completion_time=0;
     a[i]->average_wt=0;
     a[i]->average_tt=0;
  }
  // ganttchart
  for(int i=0;i<nb_process;i++)
     printf("P%d\t",a[i]->pid);
     printf("\n");
      for(int i=0;i<nb_process;i++){
           c+=a[i]->burst_time;
           a[i]->completion_time=c;
             printf("%d\t",c);
      }
      printf("\n");
 for(int i=0;i<nb_process;i++){
  a[i]->waiting_time= a[i]->completion_time - a[i]->burst_time;
    w+=a[i]->waiting_time;
  }
// the table 
printf("PROCESS\tARRIVAL TIME\tBURST TIME\tCOMPLETION TIME\tTURN AROUND\tWAITING TIME\n");
for(int i=0;i<nb_process;i++)
  printf("P%d \t\t0 \t\t%d\t\t %d\t\t%d\t\t %d\n",a[i]->pid,a[i]->burst_time,a[i]->completion_time,a[i]->completion_time,a[i]->waiting_time);
for(int i=0;i<nb_process;i++){
   a[i]->average_tt=c/nb_process;
  a[i]->average_wt=w/nb_process;
printf("the average of turnaround time is :%.2f\n",a[i]->average_tt);
printf("the average of waiting time is :%.2f",a[i]->average_wt);
for(int i=0;i<nb_process;i++)
  free(a[i]);
}
}

 