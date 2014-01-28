
#include"adm.h"

void print_adm_head()
{
	printf("\t\t***************************************\n");
	printf("\t\t***************************************\n");
	printf("\t\t***********学生管理系统欢迎*************\n");
	printf("\t\t***************************************\n");
	printf("\t\t***************************************\n");
}


void print_adm_main()
{
	int flag=0;
	while(1)
	{
		system("clear");
		print_adm_head();
		
		printf("\n\n\t请选择你要的操作\n");
		printf("\t\t\t1.show infomation \n");
		printf("\t\t\t2.change password\n");
		printf("\t\t\t3.manage teacher\n");
		printf("\t\t\t4.manage student\n");
		printf("\t\t\t5.return \n");
		printf("\t\t\t6.quit \n");
		printf("\n\t\t");
   
		scanf("%d",&flag);
   
		switch(flag)
		{
			case 1:
				show_adm_info();
				break;
			case 2:
				change_adm_password();
				break;
			case 3:
				print_teacher_main();
				break;
			case 4:  
				print_stu_main();
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

void change_adm_password()
{
	Adm adm;
	system("clear");
	print_adm_head();
	char ch;
	
	read_adm_info(&adm);
	printf("\n\n\t\tinput your new password\n");
	printf("\n\t\t\t");
	
	scanf("%s",adm.password);
	getchar();
	
	printf("do you want save it?n/y ");
	ch=getchar();
	if(ch=='y')
	{
		scanf("%c",&ch);
		getchar();
		save_adm_info(&adm);
		printf("\t\t\tsave succuess ");
	}
	scanf("%c",&ch);
}

void read_adm_info(Adm *adm)
{
	FILE *fp;
	if((fp=fopen("./data/adm","r"))==NULL)
    {
		printf("open file false!\n");
		return ;
    }
	fread(adm,sizeof(struct adm_node),1,fp);
	fclose(fp);
}
void save_adm_info(Adm *adm)
{
	FILE *fp;
  //open file 
	if((fp=fopen("./data/adm","w"))==NULL)
	{
		printf("open file is false!\n");
		return ;
	}
  //write student data to stu_list


	if((fwrite(adm,sizeof(struct adm_node),1,fp))!=1)
	{
		printf("write error!\n");
	}
	fclose(fp);
}

void show_adm_info()
{
	Adm adm;
	system("clear");
	print_adm_head();
	char ch;
	
	read_adm_info(&adm);
	
	printf("\n\n\t\tnumber     name    password\n");
	printf("\t\t%-12s%-10s%-12s\n",adm.name,adm.number,adm.password);
	getchar();
	scanf("%c",&ch);
}
/*int main()
{
	print_adm_main();
}*/

