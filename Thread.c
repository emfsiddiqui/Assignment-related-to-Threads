#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int arr[1000];
int resultarr[10];
pthread_t thread[10];
int rarrindex=0;
int vstart=0;
int sum=0;

void * add(void * arg);

int main()
{
	int i;

	for(i=0; i<1000; i++)
	{
		arr[i]=i;
	}
	
	
    for(i=0; i<10; i++)
    {
        pthread_create(&thread[i],NULL,add,NULL);

        //vstart += 100;
		//rarrindex += 1;
    }
	
	
	for(i=0; i<10; i++)
		pthread_join(thread[i],NULL);

    //int sum=0;

    //for(i=0; i<10; i++)
      //  sum=sum+resultarr[i];

    printf("%d",sum);
	
	
	return 0;
}

void * add(void * arg)
{
	
	//resultarr[rarrindex] = 0;
	
	printf("%d ",rarrindex);

    for(int i=vstart; i<vstart+100; i++)
	{
		sum += arr[i];
	}
	
	vstart += 100;

    return NULL;
}