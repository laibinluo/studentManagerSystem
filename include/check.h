/*
*  filename      :check.h
*  autor         :luolaibin
*  creat data    :2012-03-22
*  histroy       :2012-03-22
*/



#ifndef  _CHECK_H_
#define  _CHECK_H_

#include<stdio.h>
#include<string.h>
#include"term.h"
/*define check operate*/

/*
* 接受用户的字符，并判断字符的长度
* 正确则返回1，否则返回0
*/
int  get_char(char *line,unsigned int maxlenght);

/*
*  判断用户输入的是否是整数，
*  是:q
则返回1，否则返回0
*/
int is_number(char *str);

char *itoa(int value);

int get_password(char *line,int maxlenght);

#endif




