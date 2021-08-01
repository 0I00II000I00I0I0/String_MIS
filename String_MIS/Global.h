#pragma once

//空格符
#define SPACE 32
//换行符
#define LINEFEED 10
//空白字符保存为-1
#define CHARNULL -1
//空白字符显示为1
#define SHOWNULL 1

#ifndef GLOBAL_H
#define GLOBAL_H
extern char g_szBuffer[1024 * 1024];
extern int g_nBufferSize;
extern char* g_pointSelect;
extern char* g_pointPresent;
#endif
