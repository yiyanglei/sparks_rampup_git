/*
 * @Author: junbin_liu
 * @brief: addbinary implement
 * @Date: 2021-04-27 10:16:31 
 * @Last Modified time: 2021-04-27 10:16:31 
 */

/*
每周一题
    两个二进制字符串（ 字符串非空且只包含数字 1 和 0），返回它们的和（用二进制表示）。
示例 1:
    输入: a = "11", b = "1"
    输出: "100"
示例 2:
    输入: a = "1010", b = "1011"
    输出: "10101"
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAX
#define MAX(a, b) ((a) >(b) ? (a) : (b))
#endif

// COMMENT(Lei Lv) 养成注释的好习惯
//addbinary implement
char * addBinary(const char * a, const char * b)
{
    int a_len = strlen(a);
    int b_len = strlen(b);
    int ret_len = MAX(a_len, b_len) + 2;

    // COMMENT(Lei Lv): result并不恒为非空，访问空指针造成的后果可以自行科普
    char * ret = malloc(sizeof(char) * ret_len);
    if (NULL != ret)
    {
        ret[ret_len - 1] = '\0';

        int c = 0;
        int k = ret_len - 2;

        for (int i = a_len - 1, j = b_len - 1; ((i >= 0) || (j >= 0)); i--, j--, k--)
        {
            int a_bit = (i >=0 ? a[i] - '0': 0);
            int b_bit = (j>=0 ? b[j] - '0' : 0);
            int bit_sum = a_bit + b_bit + c;

            ret[k] = '0'+ bit_sum % 2;
            c = bit_sum / 2;
        }

        // COMMENT(Lei Lv): 1.目前实现的是一个函数，相加的结果不一定有进位; 2.malloc返回出来的内存并未被初始化
        if (c != 0)
        {
            ret[k] = '1';
        }
        else
        {
            ret[k] = '0';    
        }
    }

    return ret;
}


void main(void)
{
    char * a = "11";
    char * b = "1";

    char * ret = addBinary(a, b);
    if(NULL != ret)
    {
        printf("0b%s + 0b%s = 0b%s\n", a, b, ret);
        free(ret);
    }

    return;
}