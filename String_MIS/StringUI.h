#pragma once

int StringLength(char* string);

//功能选择界面
void StringUI();
//添加结果显示
void AddView(int result, char* string);
//查询结果显示
void SelectView(int result, char* string);
//删除结果显示
void DeleteView(int result, char* string);
//修改字符串结果显示
void UpdateView(int result, char* oldstring, char* newstring);
//模糊查询显示
void DimSelectView(int result, char* arrString[]);

//存储内容显示
void ShowStringView();
//存储情况显示
void ShowMemoryView(char* address);
//碎片管理显示
void MemoryFragmentView();
//统计单个字符结果显示
void CountCharView(char ch);
//统计每个字符结果显示
void CountEachCharView();

