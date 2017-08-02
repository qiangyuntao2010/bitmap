/*************************************************************************
	> File Name: bitmap.c
	> Author: 
	> Mail: 
	> Created Time: Wed 02 Aug 2017 01:42:19 PM KST
 ************************************************************************/

#include <stdio.h>   
#include <stdlib.h>   
#include <string.h>   
//#include "bitmap.h"   
  
unsigned char *g_bitmap = NULL;  
int g_size = 0;  
int g_base = 0;  
  
int bitmap_init(int size, int start)  
{  
    g_bitmap = (char *)malloc((size/8+1)*sizeof(char));  
    if(g_bitmap == NULL)  
        return 0;  
    g_base = start;  
    g_size = size/8+1;  
    memset(g_bitmap, 0x0, g_size);  
    return 1;  
}  
  
int bitmap_set(int index)  
{  
    int quo = (index-g_base)/8 ;  
    int remainder = (index-g_base)%8;  
    unsigned char x = (0x1<<remainder);  
    if( quo > g_size)  
        return 0;  
    g_bitmap[quo] |= x;  
    return 1;   
}  
  
int bitmap_get(int i)  
{  
    int quo = (i)/8 ;  
    int remainder = (i)%8;  
    unsigned char x = (0x1<<remainder);  
    unsigned char res;  
    if( quo > g_size)  
        return -1;  
    res = g_bitmap[quo] & x;  
    return res > 0 ? 1 : 0;   
}  
  
int bitmap_data(int index)  
{  
    return (index + g_base);  
}  
  
int bitmap_free()  
{  
    free(g_bitmap);  
}  
   
//测试程序bitmap_test.c：  
  
//#include <stdio.h>   
//#include "bitmap.h"   
  
int main()  
{  
    int a[] = {5,8,7,6,3,1,10,78,56,34,23,12,43,54,65,76,87,98,89,100};  
    int i;  
    bitmap_init(100, 0);  
    for(i=0; i<20; i++)  
        bitmap_set(a[i]);  
    for(i=0; i<100; i++)  
    {  
        if(bitmap_get(i) > 0 )  
            printf("%d \n", bitmap_data(i));  
    }  
    printf("/n");  
    bitmap_free();  
    return 0;  
} 
