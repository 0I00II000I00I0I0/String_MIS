#pragma once

//显示内存存储内容
void ShowString();
//显示内存存储情况
void ShowMemory(char* address);
//清理内存碎片空间
void CleanMemoryFragment();

//查询单个字符出现的次数
int CountChar(char ch);
//查询所有字符出现的次数
int CountAllChar();
//查询每个字符出现的次数
int CountEachChar(int arrCountChar[]);
