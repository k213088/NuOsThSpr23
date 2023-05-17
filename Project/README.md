                                                       OS PROJECT
    CHAIN SMOKER PROBLEM USING SEMPHORE
                            (SYSTEM CALL)

GROUP MEMBER:-
21K-3068
21K-3088










INTRODUCTION:
The cigarette smoker’s problem is a concurrency problem in computer science, originally described in 1971 by Suhas Patil.
This problem contain 1 agent and 3 smokers or processes agent provide resources and smokers obtain resources according to their need.

OBJECTIVE:
Agent have infinite supply of all three ingredients tobacco, matches and paper and smokers have infinite supply of few of the resources.
The needed resources will be fetched from table allocated by agent but if two smoker need same resource deadlock occurs and to prevent deadlock we will use banker’s algorithm which will make a smoker enter and lock the resources and then it will make a cigarette and smoke it.

Objective is to avoid deadlock situation.
CODE SNIPPETS
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#include <sys/syscall.h>


sem_t tobacco, paper, matches, agent, pusher_t, pusher_p, pusher_m, lock;


int isTobacco=0, isPaper=0 , isMatches=0;


void* smokerT()
{
  while(1)
  {
    sem_wait(&tobacco);
    printf("Smoker with tobacoo has started making cigarette\n");
    sleep(1);
    printf("Smoker with tobacco is smoking  [return value] : %d \n",syscall(335));
    sem_post(&agent);
  }
}
void* smokerP()
{
  while(1)
  {
    sem_wait(&paper);
    printf("Smoker with paper has started making cigarette\n");
    sleep(1);
    printf("Smoker with paper is smoking [return value] : %d \n",syscall(335));
    sem_post(&agent);
  }
}
void* smokerM()
{
  while(1)
  {
    sem_wait(&matches);
    printf("Smoker with matches has started making cigarette\n");
    sleep(1);
    printf("Smoker with matches is smoking [return value] : %d \n",syscall(335));
    sem_post(&agent);
  }
}


void* agentT()
{
  while(1)
  {
    sem_wait(&agent);
    printf("\n\n---> Agent puts paper and matches on the table\n");
    sem_post(&pusher_p);
    sem_post(&pusher_m);
  }
}

void* agentP()
{
  while(1)
  {
    sem_wait(&agent);
    printf("\n\n---> Agent puts tobacco and matches on the table\n");
    sem_post(&pusher_t);
    sem_post(&pusher_m);

  }
}

void* agentM()
{
  while(1)
  {
    sem_wait(&agent);
    printf("\n\n---> Agent puts tobacco and paper on the table\n");
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
      isMatches=0;
      sem_post(&tobacco);
    }
    else if(isTobacco==1)
    {
      isTobacco=0;
      sem_post(&matches);
    }
    else
    isPaper=1;
    sem_post(&lock);
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
      isTobacco=0;
      sem_post(&paper);
    }
    else if(isPaper==1)
    {
      isPaper=0;
      sem_post(&tobacco);
    }
    else
    isMatches=1;
    sem_post(&lock);
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
      isMatches=0;
      sem_post(&paper);
    }
    else if(isPaper==1)
    {
      isPaper=0;
      sem_post(&matches);
    }
    else
    isTobacco=1;
    sem_post(&lock);
  }
}



int main()
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
  return 0;
}



CODE SUMMARY
The problem is as follows: There are three smokers sitting around a table, each with an infinite supply of one of the following items: tobacco, paper, or matches. There is also an agent who places two of these items on the table at a time, and the smokers need to acquire the missing third item in order to roll and smoke a cigarette. However, each smoker can only pick up their designated item, and no two smokers can pick up the same item at the same time.

The program uses pthreads and semaphores to synchronize the actions of the smokers and the agent. There are three smoker threads (one for each type of smoker) and three pusher threads (one for each possible combination of missing items), as well as three agent threads (one for each possible combination of items to place on the table). The program also uses a lock semaphore to ensure that the pusher threads don't interfere with each other.

The smoker threads wait on their designated item semaphore (e.g. tobacco for the smoker with tobacco) to become available, then print a message indicating that they are starting to make a cigarette, sleep for one second to simulate rolling the cigarette, and then print another message indicating that they are smoking. The syscall(332) function is used to print the return value of the gettid() system call, which gives the thread ID of the smoker thread.

The agent threads wait on the agent semaphore to become available (which is initially set to 1), then place two items on the table, and signal the appropriate pusher threads to inform them that the items are available. The pusher threads wait on their designated pusher semaphore (e.g. pusher_t for the pusher that handles the combination of missing tobacco and paper) to become available, then check which item is missing, update the appropriate flag variable (e.g. isMatches if matches are missing), and signal the corresponding smoker by posting on their designated item semaphore (e.g. tobacco if tobacco is missing).

The main function initializes all the semaphores and creates all the threads, then waits for 10 seconds before exiting, allowing the threads to run and synchronize their actions.










KERNEL LEVEL PROCEDURE SNAPSHOTS
  
 
 
 
 
![os1](https://github.com/k213088/NuOsThSpr23/assets/127028606/6f6f3c9b-af55-485a-83c7-ce661362ca00)
![os2](https://github.com/k213088/NuOsThSpr23/assets/127028606/9f576b7d-8208-465b-a958-cbb765707d63)
![os3](https://github.com/k213088/NuOsThSpr23/assets/127028606/6688942d-abf1-470d-969e-ea8b83b056f8)
![os4](https://github.com/k213088/NuOsThSpr23/assets/127028606/aebe6a14-fff0-49f1-b775-9afe97c7f28d)
![os5](https://github.com/k213088/NuOsThSpr23/assets/127028606/253d2b28-d0f2-4a55-9e5c-8c7d81d5ef02)
 
 
 
 


SYSTEM CALL CODE
 ![os6](https://github.com/k213088/NuOsThSpr23/assets/127028606/5e2f9758-da49-499f-a254-2752f1621430)


RESULT:
![os 7](https://github.com/k213088/NuOsThSpr23/assets/127028606/b2c28e1c-287f-465f-8dcd-25692e8adabc)


![os8](https://github.com/k213088/NuOsThSpr23/assets/127028606/6a95e563-10bd-4e0a-bff1-69a6b1ee0d02)

![os9](https://github.com/k213088/NuOsThSpr23/assets/127028606/8700eba2-afee-4f3c-b6b7-84edb605ec1d)


 

 
 


                        JAZAKALLAH KHAIR 
