#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>

#define SIZE 128

typedef struct msgbuf
{
	long mtype ;
	char mtext[SIZE];
};

int main()
{
	int msgid ;
	FILE *fp;
	key_t key;
char contents[100];
	struct msgbuf buffer;

	key = 1234;

	msgid = msgget(key,0777);

	msgrcv(msgid,&buffer,SIZE,1,0);
	printf("%s\n",buffer.mtext);
	fp = fopen(buffer.mtext,"r");
	fgets(contents,100,fp);



	printf("%s\n",contents);
}
