// 递归求解全排列问题

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

#define ARRAY_LEN 5

//打印数组a
void print_array(char a[])
{
    for (int i = 0; i < ARRAY_LEN; i++)
        printf("%c",a[i]);
    printf("\n");
    
    
}

//用于打印缩进
void print_tab(int n)
{
    string str="";
    for (int i = 0; i < n; i++)
        str+="\t";
    cout<<str;
}

// 求字符数组a[0:n-1]中所有字符从下标k到n-1的全排列
void range(char a[],int k,int n)
{

    print_tab(k);
    printf("当前调用的是range（a，%d，%d）:\n",k,n);
    if(k==n)
    {
        print_tab(k);
        printf("目标输出-----------------");
        print_array(a);
    }
    else
    {
        for (int i=k; i<n; i++)
        {
            //打印信息
            print_tab(k);
            printf("a[%d]与a[%d]交换，交换前数组a为：",k,i);
            print_array(a);
            
            //交换
            char temp=a[i];
            a[i]=a[k];
            a[k]=temp;
			
			//打印信息
            print_tab(k);
            printf("交换后数组a为：");
            print_array(a);
			
			//递归调用
            range(a,k+1,n);
            
            //复原
            temp=a[i];
            a[i]=a[k];
            a[k]=temp;
			
			//打印信息
            print_tab(k);
            printf("复原后数组a为：");
            print_array(a);
        }
    }
    //打印信息
    print_tab(k);
    printf("range（a，%d，%d）:调用结束\n",k,n);
}

int main()
{
    char a[ARRAY_LEN]= {""};
    //初始化字符数组a[n]为字母表顺序的大写字母
    for(int i=0; i<ARRAY_LEN; i++) a[i]= 65+i;

    //主函数调用
    range(a,0,ARRAY_LEN);

    return 0;
}
