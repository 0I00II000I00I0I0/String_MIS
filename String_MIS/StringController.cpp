#include "StringController.h"
#include "Global.h"
#include <string.h>

bool AddNull()
{
    if ((g_pointPresent + 1 + 1) > (g_szBuffer + g_nBufferSize))
    {
        return false;
    }
    *g_pointPresent++ = CHARNULL;
    *g_pointPresent++ = '\0';
    return true;
}

bool AddString(char* string)
{
    int nLen = strlen(string);
    if ((g_pointPresent + nLen + 1) > (g_szBuffer + g_nBufferSize))
    {
        return false;
    }
    while (*string != '\0')
    {
        *g_pointPresent++ = *string++;
    }
    *g_pointPresent++ = '\0';
    return true;
}

bool SelectNull()
{
    char* startPoint = g_szBuffer;
    while (startPoint < g_pointPresent)
    {
        if (*startPoint == CHARNULL)
        {
            g_pointSelect = startPoint;
            return true;
        }
        startPoint++;
    }
    return false;
}

bool SelectString(char* string)
{
    char* selectStr = string;
    char* startPoint = g_szBuffer;
    char* tempPoint = g_szBuffer;
    while (startPoint < g_pointPresent)
    {
        while (*startPoint != *selectStr && startPoint < g_pointPresent)
        {
            startPoint++;
        }
        if (*(startPoint - 1) == '\0')
        {
            tempPoint = startPoint;
            while (*tempPoint == *selectStr && tempPoint < g_pointPresent)
            {
                if (*tempPoint == '\0' && *selectStr == '\0')
                {
                    g_pointSelect = startPoint;
                    return true;
                }
                tempPoint++;
                selectStr++;
            }
        }
        startPoint++;
        selectStr = string;
    }
    return false;
}

bool SelectByAddress(char* address, char string[])
{
    if ((*address == '\0') && (*(address - 1) == '\0'))
    {
        return false;
    }
    int i = 0;
    while (*(address - 1) != '\0')
    {
        address--;
    }
    g_pointSelect = address;
    while (*address != '\0')
    {
        string[i] = *address;
        address++;
        i++;
    }
    string[i] = '\0';
    return true;
}

bool DimSelect(char* string, char* arrString[])
{
    int i = 0;
    char strBuf[128] = { 0 };
    char* selectStr = string;
    char* startPoint = g_szBuffer;
    char* tempPoint = g_szBuffer;
    while (startPoint < g_pointPresent)
    {
        while (*startPoint != *selectStr && startPoint < g_pointPresent)
        {
            startPoint++;
        }
        tempPoint = startPoint;
        while (*tempPoint == *selectStr && *selectStr != '\0' && tempPoint < g_pointPresent)
        {
            tempPoint++;
            selectStr++;
        }
        if (*selectStr == '\0')
        {
            SelectByAddress(tempPoint, strBuf);
            arrString[i] = g_pointSelect;
            startPoint = g_pointSelect + strlen(g_pointSelect);
            i++;
        }
        startPoint++;
        selectStr = string;
    }
    if (arrString[0] == NULL)
    {
        return false;
    }
    return true;
}

bool DeleteNull()
{
    if (SelectNull())
    {
        *(g_pointSelect) = '\0';
        return true;
    }
    return false;
}

bool DeleteString(char* string)
{
    if (SelectString(string))
    {
        char* tempPoint = g_pointSelect;
        while (*tempPoint != '\0')
        {
            *tempPoint = '\0';
            tempPoint++;
        }
        return true;
    }
    return false;
}

bool DeleteByAddress(char* address, char string[])
{
    if (SelectByAddress(address, string))
    {
        int i = 0;
        char* pDeleteAddress = g_pointSelect;
        while (*g_pointSelect != '\0')
        {
            string[i] = *g_pointSelect;
            g_pointSelect++;
            i++;
        }
        string[i] = '\0';
        while (*pDeleteAddress != '\0')
        {
            *pDeleteAddress = '\0';
            pDeleteAddress++;
        }
        return true;
    }
    return false;
}

bool UpdateNull(char* newString)
{
    if (SelectNull())
    {
        if (strlen(newString) == 1)
        {
            *g_pointSelect = *newString;
        }
        else
        {
            AddString(newString);
            *g_pointSelect = '\0';
        }
        return true;
    }
    return false;
}

bool UpdateString(char* oldString, char* newString)
{
    if (SelectString(oldString))
    {
        char* tempPoint = g_pointSelect;
        if (strlen(newString) == 0)
        {
            *tempPoint++ = CHARNULL;
            while (*tempPoint != '\0')
            {
                *tempPoint++ = '\0';
            }
            return true;
        }
        char* startPoint = g_pointSelect;
        while (*tempPoint != '\0')
        {
            tempPoint++;
        }
        while (*tempPoint == '\0')
        {
            tempPoint++;
        }
        if (strlen(newString) < tempPoint - startPoint)
        {
            while (*newString != '\0')
            {
                *startPoint++ = *newString++;
            }
            while (startPoint < tempPoint)
            {
                *startPoint++ = '\0';
            }
            return true;
        }
        if (AddString(newString))
        {
            DeleteString(oldString);
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}


