// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"
#define RELEASE_DELETE
//#define LOG_ON // turn on log

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�:
#include <windows.h>
#include <shlobj.h>
#include <shellapi.h>

#define _CRT_SECURE_NO_WARNINGS

// C ����ʱͷ�ļ�
#include <cstdlib>
#include <algorithm>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <string>
#include <sstream>
#include "textFinder.h"
#include "Resource.h"

#ifdef LOG_ON
#include <fstream>
#endif

using namespace std;


// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
