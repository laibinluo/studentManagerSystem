


#include"manager_stu.h"


/*主菜单上的头部分*/
void print_stu_head()
{
      printf("\t\t***************************************\n");
      printf("\t\t***************************************\n");
      printf("\t\t***********学生管理系统欢迎*************\n");
      printf("\t\t***************************************\n");
      printf("\t\t***************************************\n");
}
//char *str="//2222//student//src//data//stu";
char  *str="./data/stu";  
void print_stu_main()
{
   int flag=0;
   while(1)
   {
      system("clear");
	  print_stu_head();
      printf("\n\n\t\t\t请选择你要的操作\n");
      printf("\t\t1.creat student infomation \n");
      printf("\t\t2.add student infomation\n");
      printf("\t\t3.delete\n");
      printf("\t\t4.select\n");
      printf("\t\t5.change student infomation\n");
      printf("\t\t6.show student infomation\n");
      printf("\t\t7.return \n");
      printf("\t\t8.quit\n");
      printf("\n\t\t");
   
      scanf("%d",&flag);
   
      switch(flag)
      {
        case 1:
                creat_stu_info();
                break;
        case 2:
                 add_stu_info();
                 break;
        case 3:
                 delete_stu_info();
                 break;
        case 4:  
                 select_stu_info();
                 break;
        case 5:  
                 change_stu_info();
                 break;
        case 6:  
                 show_stu_sort_main();
                 break;
        case 7:  
                 break;          
        case 8: 
                 exit(0);
                 break;
        default:
                 printf("你选择的操作不存在，请从新选择\n");
                 break;
       }  
       if(flag==7)
          return ;
    }
}

void show_stu_sort_main()
{
      system("clear");
      int flag=-1;
      while(1)
      {
		  print_stu_head();
         printf("\n\n\t\t\t请选择你要的操作\n");
         printf("\t\t0.show  student infomation \n");
         printf("\t\t1.show  c_langage sort \n");
         printf("\t\t2.show math  sort\n");
         printf("\t\t3.show chinese  sort\n");
         printf("\t\t4.show repute  sort\n");
         printf("\t\t5.return \n");
         printf("\t\t6.quit\n");
         printf("\n\t\t");
         scanf("%d",&flag);
     
         switch(flag)
         {
           case 0:
                  print_stu_info();
                  break;
           case 1:
                print_stu_clanguage_info();
                break;
           case 2:
                print_stu_math_info();
                break;
           case 3:
                print_stu_chinese_info();
                break;
           case 4:  
                print_stu_repute_info();
                break;
           case 5:  
                
                break;
           case 6: 
                 exit(0);
                 break;
           default:
                 printf("你选择的操作不存在，请从新选择\n");
                 break;
        }  
       if(flag==5)
          return ;
    }


}

void print_stu_repute_info()
{
	char  ch;
	system("clear");
	print_stu_head();

	linkList phead=NULL;     
	linkList pre=NULL;
	linkList p=NULL;
	linkList q=NULL;
//read data from file
	read_link(&phead,str);
	
	p=phead->next;
	if(p!=NULL)
	{
		q=p->next;
	}
	p->next=NULL;
	/*sort math begin*/ 
	while(q!=NULL)
	{
		pre=phead;
		p=phead->next; //每次都从开头比较 
		//寻找比较的位置
		while(p!=NULL&&(q->data).score.repute>(p->data).score.repute)
		{
			pre=p;
			p=p->next;
		}
		p=q;
		q=q->next;
			
		p->next=pre->next;
		pre->next=p; 
	}
	/*sort math end*/
	print_link(phead);
	getchar();
	scanf("%c",&ch);
	free_link(&phead);


}
void print_stu_chinese_info()
{
	char  ch;
	system("clear");
	print_stu_head();

	linkList phead=NULL;     
	linkList pre=NULL;
	linkList p=NULL;
	linkList q=NULL;
//read data from file
	read_link(&phead,str);
	
	p=phead->next;
	if(p!=NULL)
	{
		q=p->next;
	}
	p->next=NULL;
	/*sort math begin*/ 
	while(q!=NULL)
	{
		pre=phead;
		p=phead->next; //每次都从开头比较 
		//寻找比较的位置
		while(p!=NULL&&(q->data).score.chinese>(p->data).score.chinese)
		{
			pre=p;
			p=p->next;
		}
		p=q;
		q=q->next;
			
		p->next=pre->next;
		pre->next=p; 
	}
	/*sort math end*/
	print_link(phead);
	getchar();
	scanf("%c",&ch);
	free_link(&phead);
}
void print_stu_clanguage_info()
{
	char  ch;
	system("clear");
	print_stu_head();

	linkList phead=NULL;     
	linkList pre=NULL;
	linkList p=NULL;
	linkList q=NULL;
//read data from file
	read_link(&phead,str);
	
	p=phead->next;
	if(p!=NULL)
	{
		q=p->next;
	}
	p->next=NULL;
	/*sort math begin*/ 
	while(q!=NULL)
	{
		pre=phead;
		p=phead->next; //每次都从开头比较 
		//寻找比较的位置
		while(p!=NULL&&(q->data).score.c_language>(p->data).score.c_language)
		{
			pre=p;
			p=p->next;
		}
		p=q;
		q=q->next;
			
		p->next=pre->next;
		pre->next=p; 
	}
	/*sort math end*/
	print_link(phead);
	getchar();
	scanf("%c",&ch);
	free_link(&phead);



}

void print_stu_math_info()
{
    char  ch;
    system("clear");
	print_stu_head();

    linkList phead=NULL;     
    linkList pre=NULL;
    linkList p=NULL;
    linkList q=NULL;
//read data from file
    read_link(&phead,str);
	
	p=phead->next;
	if(p!=NULL)
	{
		q=p->next;
	}
	p->next=NULL;
/*sort math begin*/ 
    while(q!=NULL)
    {
		pre=phead;
		p=phead->next; //每次都从开头比较 
		//寻找比较的位置
        while(p!=NULL&&(q->data).score.math>(p->data).score.math)
		{
            pre=p;
            p=p->next;
        }
		p=q;
		q=q->next;
			
		p->next=pre->next;
		pre->next=p; 
    }
/*sort math end*/
    print_link(phead);
    getchar();
    scanf("%c",&ch);
    free_link(&phead);

}


void change_stu_info()
{
    system("clear");
	print_stu_head();
    linkList  phead=NULL;
    linkList p=NULL;
    DataType   data;
    char  ch;
   

    printf("\ninput you want to change number:");
    //getchar();
    get_string(data.number,8);
    
	read_link(&phead,str);

    p=search_number_link(phead,data.number);
    if(p==NULL)
    {
       printf("donot have this number ");
       getchar();
       return ;
    }

    printf("\t\t\t姓名：");
    get_string(data.name,120);
    //scanf("%s",data.name);

    printf("\t\t\t密码：");
    get_string(data.password,30);
    //scanf("%s",data.password);

    printf("\t\t\t年龄：");
    scanf("%d",&(data.age));
    while(getchar()!='\n');

    printf("\t\t\t班级：");
    scanf("%d",&(data.classroom));
    while(getchar()!='\n');

    printf("\t\t\t数学成绩：");
    scanf("%d",&(data.score.math));
    while(getchar()!='\n');

    printf("\t\t\tC语言成绩：");
    scanf("%d",&(data.score.c_language));
    while(getchar()!='\n');

    printf("\t\t\t中文成绩：");
    scanf("%d",&(data.score.chinese));
    while(getchar()!='\n');

    printf("\t\t\t名次：");
    scanf("%d",&(data.score.repute));
    while(getchar()!='\n');

    p->data=data;
       //printf("\n\t\tadd success\n");
    printf("do you want to save this change?n/y ");
    ch=getchar();
    if(ch=='y')
    {   
           
        if(save_link(phead))
        {
            printf("add and save success!\n");
            getchar();          
       }          
    }
    scanf("%c",&ch);
	free_link(&phead);
}

void add_stu_info()
{

    system("clear");
	print_stu_head();
    linkList  phead=NULL;
    DataType   data;
    char  ch;
   

    printf("\n\t\t\t学号：");
    //getchar();
    get_string(data.number,8);

    printf("\t\t\t姓名：");
    get_string(data.name,120);
    //scanf("%s",data.name);

    printf("\t\t\t密码：");
    get_string(data.password,30);
    //scanf("%s",data.password);

    printf("\t\t\t年龄：");
    scanf("%d",&(data.age));
    while(getchar()!='\n');

    printf("\t\t\t班级：");
    scanf("%d",&(data.classroom));
    while(getchar()!='\n');

    printf("\t\t\t数学成绩：");
    scanf("%d",&(data.score.math));
    while(getchar()!='\n');

    printf("\t\t\tC语言成绩：");
    scanf("%d",&(data.score.c_language));
    while(getchar()!='\n');

    printf("\t\t\t中文成绩：");
    scanf("%d",&(data.score.chinese));
    while(getchar()!='\n');

    printf("\t\t\t名次：");
    scanf("%d",&(data.score.repute));
    while(getchar()!='\n');

    read_link(&phead,str);

    if(add_link(phead,&data))
    {
       //printf("\n\t\tadd success\n");
      printf("do you want to save the new data?n/y ");
      ch=getchar();
      if(ch=='y')
      {   
           
           if(save_link(phead))
           {
                printf("add and save success!\n");
                getchar();
           }
       }    
       
    }
    else
    {
       printf("\n\t\tadd false\n");
       printf("number isnot same");
     }
    scanf("%c",&ch);
    free_link(&phead);

}


void select_stu_info()
{
    system("clear");
	print_stu_head();
    linkList  pstu=NULL;
    linkList  phead=NULL;
    char name[20];
    char ch;

    printf("please input you want to name:\n");
    printf("\t\t\t");
    get_string(name,20);
    
//read data from file
    read_link(&phead,str);

    pstu=search_name_link(phead,name);
    if(pstu==NULL)
    {
        printf("don't have this name");
        getchar();
        return ;
     }
    printf("\t学号    姓名      数学    C语言   语文   名次\n");
    printf("\t%-8s%-10s%-8d%-8d%-8d%-8d",
           (pstu->data).number,(pstu->data).name,(pstu->data).score.math,
           (pstu->data).score.c_language,(pstu->data).score.chinese,
           (pstu->data).score.repute);
   
   scanf("%c",&ch);
   free_link(&phead);

}

void creat_stu_info()
{
      char ch;
      linkList  phead=NULL;
      system("clear");
	  print_stu_head();
      creat_link(&phead);
     
      printf("do you want to save the new data?n/y ");
      ch=getchar();
      if(ch=='y')
      {   
           
           if(save_link(phead))
           {
                printf("save success!\n");
                getchar();
           }
       }    
     scanf("%c",&ch);
     free_link(&phead);
}
  
void  print_stu_info()
{
     char  ch;
     system("clear");
	 print_stu_head();
     linkList  phead=NULL;
//read data from file
     read_link(&phead,str);

     //printf("phead=%x,*phead=%d\n",phead,*phead);

     print_link(phead);
     getchar();
     scanf("%c",&ch);
     free_link(&phead);
}

void delete_stu_info()
{
    system("clear");
	print_stu_head();
    linkList  pstu=NULL;
    linkList  phead=NULL;
    char number[6];
    char ch;

    printf("please input you want to number:\n");
    printf("\t\t\t");
    get_string(number,6);
    
//read data from file
    read_link(&phead,str);

    if(delete_link(phead,number)==0)
    {
        printf("don't have this number\n");
        return ;
     }
 
           
     printf("delete success\n");
     printf("do you want to save it?y/n ");
     
     ch=getchar();
     if(ch=='y')
      {   
           
           if(save_link(phead))
           {
                printf("save success!\n");
                getchar();
           }
       }    
     scanf("%c",&ch);
     free_link(&phead);
}


