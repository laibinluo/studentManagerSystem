

#include"manage_teacher.h"

char  *str_teacher="./data/teacher";

/*UI head*/
void print_teacher_head()
{
	printf("\t\t***************************************\n");
	printf("\t\t***************************************\n");
	printf("\t\t***********学生管理系统欢迎*************\n");
	printf("\t\t***************************************\n");
	printf("\t\t***************************************\n");
}
//char *str="//2222//student//src//data//stu";

void print_teacher_main()
{
	int flag=0;
	while(1)
	{
		system("clear");
		print_teacher_head();
		printf("\n\n\t\t\t请选择你要的操作\n");
		printf("\t\t1.creat teacher infomation \n");
		printf("\t\t2.add teacher infomation\n");
		printf("\t\t3.delete teacher infomation\n");
		printf("\t\t4.change teacher infomation\n");
		printf("\t\t5.show teacher infomation\n");
		printf("\t\t6.return \n");
		printf("\t\t7.quit\n");
		printf("\n\t\t");
   
		scanf("%d",&flag);
   
		switch(flag)
		{
			case 1:
				creat_teacher_info();
				break;
			case 2:
				add_teacher_info();
				break;
			case 3:
				delete_teacher_info();
				break;
			case 4:  
				change_teacher_info();
				break;
			case 5:  
				show_teacher_info();
				break;
			case 6:  
				break;
			case 7: 
				exit(0);
				break;
			default:
				printf("你选择的操作不存在，请从新选择\n");
				break;
		}  
		if(flag==6)
			return ;
	}
}

int add_teacher_link(TlinkList plist,const TDataType *value)
{
	TLNode *p=NULL;
	TLNode *phead=plist;
       
	p=(TlinkList)malloc(sizeof(TLNode));
    
	if(p==NULL)
	{
		printf("merroy false\n");
		return 0;
	}
	p->data=*value;
   
	while(phead->next!=NULL)
	{
		if(strncmp((phead->data).number,value->number,8)==0)
		{
			printf("number same\n");
			free(p);
			return 0;
		}
		phead=phead->next;
	}
	if(strncmp((phead->data).number,value->number,8)==0)
	{
		printf("number same\n");
		free(p);
		return 0;
	}

	p->next=phead->next;
	phead->next=p;

	return 1;
}


TlinkList search_teacher_number_link(TlinkList plist,char* number)
{

	TlinkList phead=NULL;
	phead=plist->next;
   
	while(phead!=NULL)
	{
		if(strncmp((phead->data).number,number,8)==0)
		{
			break;  
		}
		phead=phead->next;
	}
	return phead;
}

/*change teacher infomation*/
void change_teacher_info()
{
	system("clear");
	print_teacher_head();
	TlinkList  phead=NULL;
	TlinkList p=NULL;
	TDataType   data;
	char  ch;
   

	printf("\ninput you want to change number:");
    //getchar();
	get_string(data.number,8);
    
	read_teacher_link(&phead,str_teacher);

	p=search_teacher_number_link(phead,data.number);
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

	printf("\t\t\t班级：");
	scanf("%d",&(data.classroom));
	while(getchar()!='\n');

	p->data=data;
       //printf("\n\t\tadd success\n");
	printf("do you want to save this change?n/y ");
	ch=getchar();
	if(ch=='y')
	{   
           
		if(save_teacher_info(phead))
		{
			printf("add and save success!\n");
			getchar();          
		}          
	}
	scanf("%c",&ch);
	free_teacher_link(&phead);
 
}
/*add teacher infomation*/
void add_teacher_info()
{
	system("clear");
	print_teacher_head();
	TlinkList  phead=NULL;
	TlinkList p=NULL;
	TDataType   data;
	char  ch;
	
	printf("\t\tplease input teacher information\n");
	printf("\n\t\t\t教师序号：");
    //getchar();
	get_string(data.number,8);
	printf("\t\t\t姓名：");
	get_string(data.name,120);
    //scanf("%s",data.name);

	printf("\t\t\t密码：");
	get_string(data.password,30);
    //scanf("%s",data.password);

	printf("\t\t\t班级：");
	scanf("%d",&(data.classroom));
	while(getchar()!='\n');
   
	read_teacher_link(&phead,str_teacher);

	if(add_teacher_link(phead,&data))
	{
       //printf("\n\t\tadd success\n");
		printf("do you want to save the new data?n/y ");
		ch=getchar();
		if(ch=='y')
		{   
           
			if(save_teacher_info(phead))
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
	free_teacher_link(&phead);

}

/*delete teacher infomation*/
void delete_teacher_info()
{
	
	system("clear");
	print_teacher_head();
	TlinkList  p=NULL;
	TlinkList  phead=NULL;
	TlinkList  pre=NULL;
	char number[6];
	char ch;

	printf("please input you want to number:\n");
	printf("\t\t\t");
	get_string(number,6);
    
//read data from file
	read_teacher_link(&phead,str_teacher);

	p=phead->next;
	pre=phead;   

	while(p!=NULL && (strncmp((p->data).number,number,6)!=0))
	{
		pre=p;
		p=p->next;
	}

	if(p==NULL)
	{
		printf("have not this teacher number\n");
		scanf("%c",&ch);
		return ;
	}
    
	pre->next=p->next;
	free(p);      
	printf("delete success!\n");
	printf("do you want to save it?y/n ");    
	
	ch=getchar();
	if(ch=='y')
	{        
		if(save_teacher_info(phead))
		{
			printf("save success!\n");
			getchar();
		}
	}    
	scanf("%c",&ch);
	free_teacher_link(&phead);
}

/*show teacher infomation*/
void show_teacher_info()
{
	char  ch;
	system("clear");
	print_teacher_head();
	TlinkList  phead=NULL;
//read data from file
	read_teacher_link(&phead,str_teacher);

	print_teacher_link(phead);
	getchar();
	scanf("%c",&ch);
	free_teacher_link(&phead);
	
}

void print_teacher_link(TlinkList plist)
{
	TlinkList pstu=NULL;
	pstu=plist->next;
  
	printf("\n\t\t教师序号    姓名      密码    班级\n");
	while(pstu!=NULL)
	{
		printf("\t\t%-12s%-10s%-8s%-8d",
			   (pstu->data).number,(pstu->data).name,
			   (pstu->data).password,
			   (pstu->data).classroom);
 
		pstu=pstu->next;
		printf("\n");
	}

	printf("\n");
} 


/*creat and initaion teacher infomation*/
void creat_teacher_info()
{  
	TlinkList  phead=NULL;
	TLNode *p=NULL;
	TDataType data;
	char ch;
  
	phead=(TlinkList)malloc(sizeof(TLNode));
	if(phead==NULL)
	{
		printf("memrroy false\n");
		return ;
	}

	(phead->data).number[0]='\0';
	(phead->data).name[0]='\0';
	(phead->data).password[0]='\0';	
	(phead->data).classroom=-1;
	phead->next=NULL;

	printf("\n\t\t以教师序号0结束: \n");

	printf("\t\t\t教师序号：");
	get_string(data.number,8);

	while(strncmp(data.number,"0",8)!=0)
	{
		p=(TlinkList)malloc(sizeof(TLNode));
		if(p==NULL)
		{
			return ;
		}

		printf("\t\t\t姓名：");
		get_string(data.name,120);
    //scanf("%s",data.name);

		printf("\t\t\t密码：");
		get_string(data.password,30);
    //scanf("%s",data.password);

		printf("\t\t\t班级：");
		scanf("%d",&(data.classroom));
		while(getchar()!='\n');

		p->data=data;
		p->next=phead->next;
		phead->next=p;
   
		printf("\n\t\t\t教师序号：");
    //getchar();
		get_string(data.number,8);
	}
	printf("\n");
	printf("do you want to save the new data?n/y ");
	ch=getchar();
	if(ch=='y')
	{   
           
		if(save_teacher_info(phead))
		{
			printf("save success!\n");
			getchar();
		}
	}    
	scanf("%c",&ch);
	free_teacher_link(&phead);
	
}

int read_teacher_link(TlinkList *phead,char *str)
{
	FILE *fp=NULL;
	TLNode *p=NULL;
    //DLNode *q=NULL;
	*phead=(TlinkList)malloc(sizeof(TLNode));
	if(*phead==NULL)
	{
		printf("memrroy false\n");
		return ;
	}
	((*phead)->data).number[0]='\0';
	((*phead)->data).name[0]='\0';
	((*phead)->data).password[0]='\0';	
	((*phead)->data).classroom=-1;
	(*phead)->next=NULL;
   
    //q=(*plist)->next;
	if((fp=fopen(str_teacher,"r"))==NULL) 
	{
		printf("open file is false!\n");
		return 0;
	}
   
	while(!feof(fp))
	{
		p=(TlinkList)malloc(sizeof(TLNode));
		if(p==NULL)
		{
			printf("memrroy false\n");
			return ;
		}

		if(fread(p,sizeof(TDataType),1,fp)!=1)
		{
           //printf("read error\n");
			free(p);
			return ;
		}
        //printf("p=%d,p->name=%s\n",p,(p->data).name);
		p->next=(*phead)->next;
		(*phead)->next=p;
	}
	fclose(fp);
	return 1;
}


/*save teacher infomation*/
int save_teacher_info(const TlinkList plist)
{
	FILE *fpw=NULL;
	TLNode *p=NULL;

	if((fpw=fopen(str_teacher,"w"))==NULL) 
	{
		printf("open file is false!\n");
		return 0;
	}

	p=plist->next;
	while(p!=NULL)
	{
		if(fwrite(&(p->data),sizeof(TDataType),1,fpw)!=1)
		{
         //printf("write error\n");
			return 0;
		}
		p=p->next;
	}

	fclose(fpw);
	return 1;
}  


void free_teacher_link(TlinkList *plist)
{
	TLNode *p=NULL;
	TLNode *q=NULL;
	p=*plist;

	while(p!=NULL)
	{
		q=p;
		p=p->next;
		free(q);
	}
}














