#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#include <sys/syscall.h>

sem_t tobacco, paper, matches, agent, pusher_t, pusher_p, pusher_m, lock;
int isTobacco=0, isPaper=0, isMatches=0;

void* smokerT()
{
  while(1)
  {
    sem_wait(&tobacco);
    printf("Smoker with tobacco has started making cigarette \n");
    sleep(1);
    printf("Smoker with tobacco is smoking [return value] : %d \n", syscall(322,0));
    sem_post(&agent);
  }
}

void* smokerP()
{
  while(1)
  {
    sem_wait(&paper);
    printf("Smoker with paper has started making cigarette \n");
    sleep(1);
    printf("Smoker with paper is smoking [return value] : %d \n", syscall(322,1));
    sem_post(&agent);
  }
}

void* smokerM()
{
  while(1)
  {
    sem_wait(&matches);
    printf("Smoker with matches has started making cigarette \n");
    sleep(1);
    printf("Smoker with matches is smoking [return value] : %d \n", syscall(322,2));
    sem_post(&agent);
  }
}

void* agentT()
{
  while(1)
  {
    sem_wait(&agent);
    printf("\n\n--> Agent puts paper and matches on the table \n");
    sem_post(&pusher_p);
    sem_post(&pusher_m);
  }
}


void* agentP()
{
  while(1)
  {
    sem_wait(&agent);
    printf("\n\n--> Agent puts tobacco and matches on the table \n");
    sem_post(&pusher_t);
    sem_post(&pusher_m);
  }
}


void* agentM()
{
  while(1)
  {
    sem_wait(&agent);
    printf("\n\n--> Agent puts tobacco and paper on the table \n");
    sem_post(&pusher_t);
    sem_post(&pusher_p);
  }
}

void main()
{
  
  
}
