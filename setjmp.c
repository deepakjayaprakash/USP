#include<stdio.h>
#include<stdlib.h>
#include <setjmp.h>
#define TOK_ADD 5
jmp_buf jmpbuffer;
int i,flag=0;
void cmd_add();
int main(void)
{


printf("In Main\n");
i=setjmp(jmpbuffer);

//if (i!=0)
printf("i = %d\n",i);
cmd_add();
exit(0);
}

void cmd_add(void)
{
if(flag==0)
{
flag=1;
longjmp(jmpbuffer, 5);

/* rest of processing for this command */
}
}
