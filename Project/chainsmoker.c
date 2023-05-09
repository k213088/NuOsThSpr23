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

void* pusherP()
{
  while(1)
  {
    sem_wait(&pusher_p);
    sem_wait(&lock);
    if(isMatches==1)
    {
      isMatches = 0;
      sem_post(&tabacco);
    }
    else if(isTobacco==1)
    {
      isTobacco = 0;
      sem_post(&matches);
    }
    else
    {
      isPaper = 1;
      sem_post(&lock);
    }
  }
}

void* pusherM()
{
  while(1)
  {
    sem_wait(&pusher_m);
    sem_wait(&lock);
    if(isTobacco==1)
    {
      isTobacco = 0;
      sem_post(&paper);
    }
    else if(isPaper==1)
    {
      isPaper = 0;
      sem_post(&tobacco);
    }
    else
    {
      isMatches = 1;
      sem_post(&lock);
    }
  }
}


void* pusherT()
{
  while(1)
  {
    sem_wait(&pusher_t);
    sem_wait(&lock);
    if(isMatches==1)
    {
      isMatches = 0;
      sem_post(&paper);
    }
    else if(isPaper==1)
    {
      isPaper = 0;
      sem_post(&matches);
    }
    else
    {
      isTobacco = 1;
      sem_post(&lock);
    }
  }
}

void main()
{
  sem_init(&tobacco,0,0);
  sem_init(&matches,0,0);
  sem_init(&lock,0,1);
  sem_init(&paper,0,0);
  sem_init(&pusher_t,0,0);
  sem_init(&pusher_m,0,0);
  sem_init(&pusher_p,0,0);
  sem_init(&agent,0,1);

  pthread_t tid[9];
  pthread_create(&tid[0],NULL,smokerT,NULL);
  pthread_create(&tid[1],NULL,smokerP,NULL);
  pthread_create(&tid[2],NULL,smokerM,NULL);
  pthread_create(&tid[3],NULL,pusherT,NULL);
  pthread_create(&tid[4],NULL,pusherP,NULL);
  pthread_create(&tid[5],NULL,pusherM,NULL);
  pthread_create(&tid[6],NULL,agentM,NULL);
  pthread_create(&tid[7],NULL,agentP,NULL);
  pthread_create(&tid[8],NULL,agentT,NULL);

  sleep(10);
}
