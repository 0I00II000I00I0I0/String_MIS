#include "StringUI.h"
#include "Global.h"
#include <stdio.h>
#include <string.h>
#include "StringTool.h"

int StringLength(char* string)
{
    /*int nLength = strlen(string);
    if (0 == nLength)
    {
      nLength = 1;
    }*/
    return strlen(string) == 0 ? 1 : strlen(string);
}

void StringUI()
{
    printf("------------------------静态存储下字符串管理系统（String_MIS）-------------------------\n");
    printf("\n");
    printf("\t---请选择对应操作 静态存储内存大小1MB 字符串长度限定127字节---\n");
    printf("\n");
    printf("\t1---添加字符串\t\t");
    printf("\t6---查询字符统计结果\n");
    printf("\t2---按内容查询字符串\t");
    printf("\t7---查询存储资源分布\n");
    printf("\t3---按地址查询字符串\t");
    printf("\t8---存储空间碎片管理\n");
    printf("\t4---按内容删除字符串\t");
    printf("\t9---修改字符串\n");
    printf("\t5---按地址删除字符串\t");
    printf("\t10--模糊查询\n");
    printf("\t11--主界面\t\t");
    printf("\t0---退出\n\n");
}

void AddView(int result, char* string)
{
    int nLength = StringLength(string);
    switch (result)
    {
    case 0:
        printf("添加失败：内存空间不足，请清理空间\n");
        break;
    case 1:
        printf("添加成功：字符串%s 长度%d 地址%d\n",
            string, nLength, g_pointPresent - 1 - nLength - g_szBuffer);
        break;
    }
}

void SelectView(int result, char* string)
{
    int nLength = StringLength(string);
    switch (result)
    {
    case 0:
        printf("查询失败：未找到字符串\n");
        break;
    case 1:
        printf("查询成功：字符串%s 长度%d 地址%d\n",
            string, nLength, g_pointSelect - g_szBuffer);
        break;
    }
}

void DeleteView(int result, char* string)
{
    int nLength = StringLength(string);
    switch (result)
    {
    case 0:
        printf("删除失败：未找到字符串\n");
        break;
    case 1:
        printf("删除成功：字符串%s 长度%d 地址%d\n",
            string, nLength, g_pointSelect - g_szBuffer);
        break;
    }
}

void UpdateView(int result, char* oldstring, char* newstring)
{
    int nLength = StringLength(newstring);
    switch (result)
    {
    case 0:
        printf("修改失败：未找到字符串\n");
        break;
    case 1:
        printf("修改成功：字符串%s 长度%d 地址%d\n",
            newstring, nLength, g_pointSelect - g_szBuffer);
        break;
    }
}

void DimSelectView(int result, char* arrString[])
{
    switch (result)
    {
    case 0:
        printf("查询失败：未找到字符串\n");
        break;
    case 1:
        printf("查询成功：\n");
        int i = 0;
        while (arrString[i] != NULL)
        {
            printf("%d---字符串%s 长度%d 地址%d\n",
                i + 1, arrString[i], strlen(arrString[i]), arrString[i] - g_szBuffer);
            i++;
        }
        break;
    }
}

void ShowStringView()
{
    printf("------------------------------------存储内容----------------------------------------\n");
    ShowString();
    printf("------------------------------------------------------------------------------------\n");
}

void ShowMemoryView(char* address)
{
    printf("------------------------------------内存情况----------------------------------------\n");
    ShowString();
    ShowMemory(address);
    printf("------------------------------------------------------------------------------------\n");
}

void MemoryFragmentView()
{
    printf("------------------------------------碎片整理----------------------------------------\n");
    ShowString();
    ShowMemory(g_szBuffer);
    printf("------------------------------------------------------------------------------------\n");
}

void CountCharView(char ch)
{
    int countresult = CountChar(ch);
    int allChar = CountAllChar();
    float n = ((float)countresult / (float)allChar) * 100;
    printf("统计结果：\n");
    printf("字符%c 出现次数%d 出现比例%.2f%%\n", ch, countresult, n);
}

void CountEachCharView()
{
    int i = 0;
    int eachChar[129] = { 0 };
    int result = CountEachChar(eachChar);
    int allChar = CountAllChar();
    printf("统计结果：\n");
    if (eachChar[128] != 0)
    {
        printf("字符%c 出现次数%d 出现比例%.2f%%\n", '\1', eachChar[128], ((double)eachChar[128] / (double)allChar) * 100);
    }
    while (i < 128)
    {
        if (eachChar[i] != 0)
        {
            printf("字符%c 出现次数%d 出现比例%.2f%%\n", i, eachChar[i], ((double)eachChar[i] / (double)allChar) * 100);
        }
        i++;
    }
}

