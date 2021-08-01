#include <stdio.h>
#include <string.h>
#include "Global.h"
#include "StringUI.h"
#include "StringTool.h"
#include "StringController.h"

//获取输入的字符串
int GetString(char* string)
{
    rewind(stdin);
    fgets(string, 128 + 1, stdin);
    while (strlen(string) == 128)
    {
        printf("字符串超出限定长度,请重新输入:");
        rewind(stdin);
        fgets(string, 128 + 1, stdin);
    }
    if (string[strlen(string) - 1] == LINEFEED)
    {
        string[strlen(string) - 1] = '\0';
    }
    return strlen(string);
}

int main()
{
    int nRet = 0;//输入的结果
    int nOption = 0;//功能选择结果
    int nAddress = 0;//输入的地址
    char string[128] = { 0 };//输入的字符串
    char newString[128] = { 0 };//修改的字符串
    int nLength = 0;//字符串长度
    bool bResult = true;//操作字符串结果
    char* selectAdress = NULL;//查询地址

    StringUI();
    do
    {
        printf("选择操作---");
        memset(string, 0, 128);
        memset(newString, 0, 128);
        rewind(stdin);
        nRet = scanf("%d", &nOption);
        while (nOption < 0 || nOption>11 || 0 == nRet)
        {
            printf("选择错误，请重新选择：");
            rewind(stdin);
            nRet = scanf("%d", &nOption);
        }

        switch (nOption)
        {
        case 1: //添加字符串
            printf("添加字符串：");
            nLength = GetString(string);
            if (nLength == 0)
            {
                bResult = AddNull();
            }
            else
            {
                bResult = AddString(string);
            }
            AddView(bResult, string);
            ShowStringView();
            break;

        case 2: //按内容查询字符串
            printf("按内容查询字符串：");
            nLength = GetString(string);
            if (nLength == 0)
            {
                bResult = SelectNull();
            }
            else
            {
                bResult = SelectString(string);
            }
            SelectView(bResult, string);
            ShowStringView();
            break;

        case 3: //按地址查找字符串
            printf("按地址（0~1048575）查找字符串：");
            rewind(stdin);
            scanf("%d", &nAddress);
            selectAdress = g_szBuffer + nAddress;
            bResult = SelectByAddress(selectAdress, string);
            SelectView(bResult, string);
            ShowStringView();
            break;

        case 4: //按内容删除字符串
            printf("按内容删除字符串：");
            nLength = GetString(string);
            if (nLength == 0)
            {
                bResult = DeleteNull();
            }
            else
            {
                bResult = DeleteString(string);
            }
            DeleteView(bResult, string);
            ShowStringView();
            break;

        case 5://按地址删除字符串
            printf("按地址（0~1048575）删除字符串：");
            rewind(stdin);
            scanf("%d", &nAddress);
            selectAdress = (g_szBuffer + nAddress);
            bResult = DeleteByAddress(selectAdress, string);
            DeleteView(bResult, string);
            ShowStringView();
            break;

        case 6: //查询字符统计结果
            CountEachCharView();
            ShowStringView();
            break;

        case 7: //查询存储资源分布
            printf("按地址（0~1048575）查询存储资源分布：");
            rewind(stdin);
            scanf("%d", &nAddress);
            selectAdress = g_szBuffer + nAddress;
            ShowMemoryView(selectAdress);
            break;

        case 8: //存储空间碎片管理
            CleanMemoryFragment();
            MemoryFragmentView();
            break;

        case 9: //修改字符串
            printf("修改字符串：");
            nLength = GetString(string);
            printf("修改为：");
            nLength = GetString(newString);
            if (strlen(string) == 0)
            {
                bResult = UpdateNull(newString);
            }
            else
            {
                bResult = UpdateString(string, newString);
            }
            UpdateView(bResult, string, newString);
            ShowStringView();
            break;

        case 10: //模糊查询
            printf("模糊查询字符串：");
            nLength = GetString(string);
            if (nLength == 0)
            {
                bResult = SelectNull();
                SelectView(bResult, string);
            }
            else
            {
                char* arrString[100] = { };
                bResult = DimSelect(string, arrString);
                DimSelectView(bResult, arrString);
            }
            ShowStringView();
            break;

        case 11://主界面
            StringUI();
            break;

        case 0: //退出
            printf("已退出\n");
            break;
        }
    } while (nOption);

    return 0;
}
