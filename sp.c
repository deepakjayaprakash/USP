#include<shadow.h>
#include<stddef.h>
#include<string.h>
#include<stdio.h>

int main(int argc,char* argv[]){
        struct spwd *p;
        char *u=argv[1];
        int i;
        p=getspnam(u);
        if(p==NULL)
                printf("\nINVALID USER\n");
        else{
                printf("User:%s\n",p->sp_namp);
                printf("Pass:%s\n",p->sp_pwdp);
                printf("Last change:%d\n",p->sp_lstchg);
                printf("Days until change allowed:%d\n",p->sp_min);
                printf("Days before change req:%d\n",p->sp_max);
                printf("Days warning for expiration:%d\n",p->sp_warn);
                printf("Days before account inactive:%d\n",p->sp_inact);
		printf("Days since epoch when account expires:%d\n",p->sp_expire);
		printf("Reserved:%d\n",p->sp_flag);
        }
}



