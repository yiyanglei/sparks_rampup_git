/*
输入：一个字符串为数学混合运算表达式，里面可能含有多重小括号，如
    1+2*3-4/2
    10+((8+2)*3-(4+5))
    9*(1+(23-9/(1+1+1)))-4
输出：表达式的括号用法是否规范和配对，是则返回1，否则返回0
    如 1+)(2+3)，1+(2/3-4))

注意: 
    1.只检查括号的规范，不需要检查数字和运算符号
    2.有条件的可以用cmake/makefile来编译

示例：
    1+2*3-4/2    返回1
    9*(1+(23-9/(1+1+1)))-4  返回1
    1+(2/3-4))  返回0
    1（2-3） 返回1(只检查括号，不检查其他有效性)
*/


#include "stdio.h"
#include "stdlib.h"
#include "./include/typedef.h"
#include "./include/stack.h"




int validate_expression(const char * exp) {
    int len = strlen(exp);
	Stack_t* p_stk = stack_new(len);
	for (int i = 0; i < len + 1; i++) {
		if ('(' == exp[i]) {
			stack_push(p_stk, '(');
		}
		else if (')' == exp[i]) {
			char C;
			char* c = &C;
			stack_top(p_stk, c);
			if ('(' != C) {
				stack_delete(p_stk);
				return 0;
			}

			stack_pop(p_stk, c);
		}
	}
	if (stack_is_empty(p_stk)) {
		stack_delete(p_stk);
		return 1;
	}
	stack_delete(p_stk);
	return 0;
}

int main(void)
{
    char exp[]="1+(2*4-3))";
    
    if(validate_expression(exp) != 0)
    {
        printf("expression %s is valid\n", exp);
    }
    else
    {
        printf("expression %s is invalid\n", exp);
    }

    return 0;
}
