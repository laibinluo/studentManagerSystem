#include"teacher_main.h"

void print_head_teacher_person()
{
	printf("\t\t***************************************\n");
	printf("\t\t***************************************\n");
	printf("\t\t**********学生管理系统欢迎***********\n");
	printf("\t\t***************************************\n");
	printf("\t\t***************************************\n");
}

void  print_teacher_person_main(char number[10])
{
	int flag=0;
   
	while(1)
	{
		system("clear");
		print_head_teacher_person();
		printf("\n\n\t\t\t请选择你要的操作\n");
		printf("\t\t1.修改密码\n");
		printf("\t\t2.查看个人信息\n");
		printf("\t\t3.manage student\n");
		printf("\t\t4.return \n");
		printf("\t\t5.退出系统\n");
		printf("\n\t\t");
   
		scanf("%d",&flag);
   
		switch(flag)
		{
			case 1:
				set_teacher_person_password(number);
				break;
			case 2:
				print_teacher_person(number);
				break;
			case 3:
				print_stu_main();
				break;
			case 4:
				return ;
			case 5:
				exit(0);
			default:
				printf("你选择的操作不存在，请从新选择\n");
				break;
		}  
	}
}


/*修改密码*/
void set_teacher_person_password(char number[10])
{
	system("clear");
	print_head_teacher_person();
	TlinkList  phead=NULL;
	TlinkList p=NULL;
	char password[8];
	char  ch;
   
    //getchar();
	 
	read_teacher_link(&phead,"./data/teacher");
	p=search_teacher_number_link(phead,number);
	printf("\ninput your new password: ");
	get_string(password,8);
    
	strcpy((p->data).password,password);
	printf("你要保存你的更改吗？n/y"); 
	ch=getchar();
	if(ch='y')
	{
		save_teacher_info(phead);
		printf("保存更改成功");
	}   
	scanf("%c",&ch);
	free_teacher_link(&phead);
}


void  print_teacher_person(char number[10])
{
	
	system("clear");
	print_head_teacher_person();
	TlinkList  phead=NULL;
	TlinkList p=NULL;
	char  ch;
   
    //getchar();
    
	read_teacher_link(&phead,"./data/teacher");
	p=search_teacher_number_link(phead,number);
	
	printf("\n\t\t教师序号    姓名      密码    班级\n");
	printf("\t\t%-12s%-10s%-8s%-8d",
		   (p->data).number,(p->data).name,
		   (p->data).password,
		   (p->data).classroom);
	getchar();
	scanf("%c",&ch);
	free_teacher_link(&phead);
}


/*int main()
{
	char number[10];
	get_string(number,10);
	print_teacher_person_main(number);
}
*/

