#include<pwd.h>
#include<stddef.h>
#include<string.h>
#include<stdio.h>

int main(int argc,char* argv[]){
        struct passwd *p;
        char *u=argv[1];
        int i;
	int n=10;
        p=getpwnam(u);
        if(p==NULL)
                printf("\nINVALID USER\n");
        else{
                printf("User:%s\n",p->pw_name);
                printf("Pass:%s\n",p->pw_passwd);
                printf("UID:%d\n",p->pw_uid);
                printf("GID:%d\n",p->pw_gid);
                printf("Info:%s\n",p->pw_gecos);
                printf("Home:%s\n",p->pw_dir);
                printf("Shell:%s\n\n",p->pw_shell);
        }
        for(i=0;i<n;i++){
                p=getpwent();
                printf("User:%s\n",p->pw_name);
                printf("Pass:%s\n",p->pw_passwd);
                printf("UID:%d\n",p->pw_uid);
                printf("GID:%d\n",p->pw_gid);
                printf("Info:%s\n",p->pw_gecos);
                printf("Home:%s\n",p->pw_dir);
                printf("Shell:%s\n\n",p->pw_shell);

        }
}

