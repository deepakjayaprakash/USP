
/*
    compile using gcc 11b.c -lpthread

    ignore warnings
*/


#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_WRITERS 1
#define NUM_READERS 1

int item_written = 0;
int item_read = 0;

sem_t semaphore_item;

void writer(int count)
{
  sleep(1);
  printf("Locking Writer %d \n",count);
  
  item_written ++;
  sem_post(&semaphore_item); // unlock item so it can be read if it was locked when no new item was available  printf("Writing to new value %d\n",item_written);
  printf("Writer %d unlocking semaphore\n",count);}

void reader(int count)
{
  sleep(1);
    if(item_read == item_written)
  {
    printf("No new item available to be read . Locking resource until new entry is written !\n");
    sem_wait(&semaphore_item); // wait for new item to be written
  }
  item_read++;
  printf("Reader %d read value : %d \n",count,item_read);
}

void *begin_reader(void *arg)
{
  while(1)
  {
    reader((int) arg);
  }
}

void *begin_writer(void *arg)
{
  while(1)
  {
    writer((int) arg);
  }
}

int main()
{
  int i; //loop variable
  // initializing readers and writers
  pthread_t reader_th[NUM_READERS];
  pthread_t writer_th[NUM_WRITERS];

  sem_init(&semaphore_item,0,1);
  
  //creating readers and writers
  for(i=0;i<NUM_WRITERS;i++)
    pthread_create(&writer_th[i],NULL,begin_writer,(void *)i);

  for(i=0;i<NUM_READERS;i++)
    pthread_create(&reader_th[i],NULL,begin_reader,(void *)i);

  //join thread
  for(i=0;i<NUM_READERS;i++)
    pthread_join(reader_th[i],NULL);

  for(i=0;i<NUM_WRITERS;i++)
    pthread_join(writer_th[i],NULL);

  return 0;
}