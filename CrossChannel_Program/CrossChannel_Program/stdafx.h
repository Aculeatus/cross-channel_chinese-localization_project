// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include <direct.h>
#include <io.h>
#include <iostream>
#include <fstream>
#include <string>
#include <Strsafe.h>

#define IOREVISION
/** < WillPlus Project List >
 *  CROSSCHANNEL
 *  OTOMEGA
 *  IO_REVISION_II
 **/

using namespace std;

#include "EasyUnicodeFileLE.h"
#include "ToolBox.h"
#include "crc32.h"
#include "textFinder.h"

// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
#include "libbmp-0.1.3\bmpfile.h"
#pragma comment( lib, "..\\libs\\libbmp-0.1.3.gcc.lib" )
#include "CxImage600\xfile.h"
#include "CxImage600\ximage.h"
#include "CxImage600\ximath.h"
#pragma comment( lib, "..\\libs\\cximage600.vc6.lib" )

#include "lzss_enc.h"
#include "CrossChannelCrack.h"
