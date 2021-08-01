#pragma once

//添加空字符
bool AddNull();
//添加字符串
bool AddString(char* string);

//查询空字符
bool SelectNull();
//根据内容查询字符串
bool SelectString(char* string);
//根据地址查询字符串
bool SelectByAddress(char* address, char string[]);
//模糊查询
bool DimSelect(char* string, char* arrString[]);

//删除空字符
bool DeleteNull();
//根据内容删除字符串
bool DeleteString(char* string);
//根据地址删除字符串
bool DeleteByAddress(char* address, char string[]);

//修改空字符
bool UpdateNull(char* newString);
//修改字符串
bool UpdateString(char* oldString, char* newString);

