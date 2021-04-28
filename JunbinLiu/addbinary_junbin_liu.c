/*
 * @Author: junbin_liu
 * @brief: addbinary implement
 * @Date: 2021-04-27 10:16:31 
 * @Last Modified time: 2021-04-27 10:16:31 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max(a,b) (a>b ? a:b)
//addbinary implement
char * addBinary(char *a, char *b)
{
    int a_len =strlen(a);
    int b_len =strlen(b);
    int ret_len=max(a_len,b_len)+2;

    char *ret=malloc(sizeof(char)*ret_len);
    ret[ret_len-1]='\0';
    int c=0;
    int k=ret_len-2;
    for(int i=a_len-1,j=b_len-1;i>=0||j>=0;i--,j--,k--)
    {
        
        int a_bit=(i>=0?a[i]-'0':0);
        int b_bit=(j>=0?b[j]-'0':0);
        int bit_sum = a_bit + b_bit+c;

        ret[k]='0'+bit_sum%2;
        c=bit_sum/2;
    }
    if(c!=0)
       ret[k]='1';

    return ret;
}


void main(void)
{
    char *a ="11";
    char *b ="111";

    char *ret =addBinary(a,b);
    if(ret)
    {
        printf("0b%s + 0b%s = 0b%s\n", a, b, ret);
        free(ret);
    }

    return;
}