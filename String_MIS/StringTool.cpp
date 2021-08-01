#include "StringTool.h"
#include "Global.h"
#include <stdio.h>

void ShowString()
{
    char* startPoint = g_szBuffer;
    while (startPoint < g_pointPresent)
    {
        if (*startPoint == CHARNULL)
        {
            printf("%c", SHOWNULL);
        }
        if (*startPoint == '\0')
        {
            printf("%c", SPACE);
        }
        else
        {
            printf("%c", *startPoint);
        }
        startPoint++;
    }
    printf("\n");
}

void ShowMemory(char* address)
{

    if (address == g_szBuffer && *address == '\0')
    {
        printf("%c", 'F');
        address++;
    }
    while (address < g_pointPresent)
    {
        if (*address == '\0' && *(address - 1) == '\0')
        {
            printf("%c", 'F');
        }
        else
        {
            printf("%c", 'U');
        }
        address++;
    }
    printf("\n");
}

void CleanMemoryFragment()
{
    char* startPoint = g_szBuffer;
    char* tempPoint = g_szBuffer;
    char* restartPoint = g_szBuffer;
    while (startPoint < g_pointPresent)
    {
        if (*startPoint == '\0' && *(startPoint + 1) == '\0')
        {
            if (startPoint != g_szBuffer)
            {
                startPoint++;
            }
            tempPoint = startPoint;
            restartPoint = startPoint;
            while (*tempPoint == '\0' && tempPoint < g_pointPresent)
            {
                tempPoint++;
            }
            while (tempPoint < g_pointPresent)
            {
                *startPoint = *tempPoint;
                *tempPoint = '\0';
                startPoint++;
                tempPoint++;
            }
            g_pointPresent = startPoint;
            startPoint = restartPoint;
        }
        startPoint++;
    }
}

int CountChar(char ch)
{
    int nCount = 0;
    char* startPoint = g_szBuffer;
    while (startPoint < g_pointPresent)
    {
        if (*startPoint == ch)
        {
            nCount++;
        }
        startPoint++;
    }
    return nCount;
}

int CountAllChar()
{
    int nCount = 0;
    char* startPoint = g_szBuffer;
    while (startPoint < g_pointPresent)
    {
        if (*startPoint != '\0')
        {
            nCount++;
        }
        startPoint++;
    }
    return nCount;
}

int CountEachChar(int arrCountChar[])
{
    char* startPoint = g_szBuffer;
    while (startPoint < g_pointPresent)
    {
        if (*startPoint == CHARNULL)
        {
            arrCountChar[128]++;
        }
        else if (*startPoint != '\0')
        {
            arrCountChar[*startPoint]++;
        }
        startPoint++;
    }
    return 1;
}
