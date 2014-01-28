#include "check.h"
/*
* 接受用户的字符，并判断字符的长度
* 正确则返回1，否则返回0
*/


int get_password(char *line,int maxlenght)
{
	char *p=line;
	unsigned  int count=0;

	while(1)
	{
		set_keypress();	
		echo_off();	
		*p=getchar();	
		putchar('*');
	//printf("Test: getchar=%c\n", ch);
		echo_on();	
		
		count++;
          
		if(count>=maxlenght)
		{
			printf("输入的太长，长度1～%d\n",maxlenght-2);
			while(getchar()!='\n')
			{
			}
			memset(line,0,maxlenght-1);
			return 0;
		}
		if(*p=='\n')
		{
			*p='\0';
			break;
		}
		else
		{
			p++;
		}
	}
	return 1;	
}



int get_char(char *line,unsigned int maxlenght)
{
   char *p=line;
   unsigned  int count=0;

   while(1)
   {
      *p=getchar();
      count++;
          
      if(count>=maxlenght)
      {
          printf("输入的太长，长度1～%d\n",maxlenght-2);
          while(getchar()!='\n')
          {
          }
          memset(line,0,maxlenght-1);
          return 0;
      }
      if(*p=='\n')
      {
            *p='\0';
             break;
       }
      else
      {
           p++;
      }
   }
   return 1;
}
/*char *itoa(int value)
{
   char *str;
   int a=value;

   str=(char*)malloc(20*sizeof(char));
   if(str==NULL)
   { 
     return 0;
    }
   sprintf(str,"%d",a);
   return str;
}*/


int is_number(char *line)
{
   char *p=line;
   
   while(*p!='\0')
   {
       if(*p>'9'||*p<'0')
       {
         printf("请输入整数\n");
         return 0;
       }
       p++;
    }   
   return 1;
}

/*int main()
{
   char name[10];
   int num;
   while(get_char(name,10)==0);
   
   printf("%s",name);
   /*printf("*********\n");
   
   scanf("%d",&num);
   sprintf(name,"%d",num);
   printf("%s\n",name);
   while(is_number(name)==0);
   printf("********\n"); */
   
   //return 0;
//}





