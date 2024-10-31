#include<stdio.h>
#define SharedStackMax 100
typedef char SharedStackType;
typedef struct SharedStack{
    SharedStackType data[SharedStackMax];
    size_t top1;
    size_t top2;
}SharedStack;

void SharedStackInit(SharedStack*stack)
{
    if(stack==NULL)
    {
        return;
    }
    stack->top1=0;
    stack->top2=SharedStackMax;
}
void SharedStackPush1(SharedStack*stack,SharedStackType value)
{
    if(stack==NULL)
    {
        return;
    }
    if(stack->top1==stack->top2)
    {
        return;
    }
    stack->data[stack->top1++]=value;
    return;
}
void SharedStackPush2(SharedStack*stack,SharedStackType value)
{
    if(stack==NULL)
    {
        return;
    }
    if(stack->top2==stack->top1)
    {
        return;
    }
    stack->data[--stack->top2]=value;
}
int  SharedStackTop1(SharedStack*stack,SharedStackType*value)
{
    if(stack==NULL||value==NULL)
    {
        return 0;
    }
    if(stack->top1==0)
    {
    // 返回0表示栈为空
    return 0;
    }

    // 从栈中弹出一个值
    *value = stack->data[stack->top1-1];
    // 成功弹出值后返回1
    return 1;

}
int SharedStackTop2(SharedStack*stack,SharedStackType*value)
{
    if(stack==NULL||value==NULL)
    {
        return 0;
    }
    if(stack->top2==SharedStackMax)
    {
        return 0;
    }
    *value=stack->data[stack->top2];
    return 1;
}
void SharedStackPop1(SharedStack*stack)
{
    if(stack==NULL)
    {
        return;
    }
    if(stack->top1==0)
    {
        return;
    }
    stack->top1--;
}
void SharedStackPop2(SharedStack*stack)
{
    if(stack==NULL)
    {
        return;
    }
    if(stack->top2==SharedStackMax)
    {
        return;
    }
    stack->top2++;
}
