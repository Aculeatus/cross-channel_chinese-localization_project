// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once
#pragma pack( 1 )

#include "targetver.h"
#include "resource.h"

#define DLLIMPORT __declspec (dllexport)
//#define DEBUG
#define SETALLLOG

#ifdef DEBUG
#define _CRT_SECURE_NO_WARNINGS
#endif

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
#include <windows.h>
#include <CommCtrl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "E:\\libs\\OpenCV-2.1.0\\include\\opencv\\cxcore.h"
#include "E:\\libs\\OpenCV-2.1.0\\include\\opencv\\highgui.h"
#pragma comment( lib, "C:\\dev\\libs\\OpenCV2.1\\lib\\cv210.lib" )
#pragma comment( lib, "C:\\dev\\libs\\OpenCV2.1\\lib\\cxcore210.lib" )
#pragma comment( lib, "C:\\dev\\libs\\OpenCV2.1\\lib\\highgui210.lib" )

// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
DLLIMPORT void HelloWorld( char * );
DLLIMPORT LONG HegCloseKey( HKEY );
DLLIMPORT LONG HegCreateKeyExA( HKEY, LPCSTR, DWORD, LPSTR, DWORD, REGSAM, LPSECURITY_ATTRIBUTES, PHKEY, LPDWORD );
DLLIMPORT LONG HegOpenKeyExA( HKEY, LPCSTR, DWORD, REGSAM, PHKEY );
DLLIMPORT LONG HegQueryValueExA( HKEY, LPCSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD lpcbData );
DLLIMPORT LONG HegSetValueExA( HKEY, LPCSTR, DWORD, DWORD, CONST BYTE *, DWORD cbData );

/* ������Ҫ�������ݽṹ��˳���� */
#define TableSize 52
const static char KeyTable[ TableSize ][ 20 ] = {
	"Adapter",
	"DisplayMode_Window",
	"Size_Full.Width",
	"Size_Full.Height",
	"Size_Window.Width",
	"Size_Window.Height",
	"FullScreen",
	"BackBuffer.Width",
	"BackBuffer.Height",
	"KeepAspectRatio",
	"VSync",
	"UnDivideTexture",
	"DisableDialog",
	"UseCV",
	"JoyPad",

	"InstallType",
	"InstallDir",
	"InstallSrc",
	"FontName",
	"SpecialFontName",
	"AutoMsg",
	"AutoSkip",
	"CursorHide",
	"CursorTime", // OTOMEGA
	"D3D.DisableTnL",
	"D3D.Tex16",
	"DeactivePlay",
	"Dialog",
	"DisableCursor",
	"DisablePan",
	"DisableQuick",
	"DisplayMode",
	"EffectSkip",
	"FontEdge",
	"LogAlpha", // OTOMEGA
	"MsgAlpha",
	"MsgPos",
	"MsgSpeed",
	"Mute",
	"RButtonMode",
	"SelAuto",
	"SelSkip",
	"SimpleWindow",
	"SkipIcon",
	"SkipType",
	"SysVoice",
	"TextColor", // OTOMEGA
	"UseDefaultFont",
	"UseFilt",
	"VoiceSkip",
	"Volume",
	"WndPos"
};

/* ֱ�Ӱ����ж������Ź�������д���Ƕ����� ( Need to be decryped ) */
typedef struct {
	DWORD Adapter,
		DisplayMode_Window,
		Size_Full_Width, Size_Full_Height,
		Size_Window_Width, Size_Window_Height,
		FullScreen,
		BackBuffer_Width, BackBuffer_Height,
		KeepAspectRatio,
		VSync,
		UnDivideTexture,
		DisableDialog,
		UseCV,
		JoyPad;
	char InstallType[ 4 ],
		InstallDir[ 260 ], InstallSrc[ 260 ],
		FontName[ 1024 ], SpecialFontName[ 1024 ],
		AutoMsg[ 4 ], AutoSkip[ 4 ],
		CursorHide[ 4 ],
		CursorTime[ 4 ], // OTOMEGA
		D3D_DisableTnL[ 4 ], D3D_Tex16[ 4 ],
		DeactivePlay[ 4 ],
		Dialog[ 4 ],
		DisableCursor[ 4 ],
		DisablePan[ 4 ],
		DisableQuick[ 4 ],
		DisplayMode[ 4 ],
		EffectSkip[ 4 ],
		FontEdge[ 4 ],
		LogAlpha[ 4 ], // OTOMEGA
		MsgAlpha[ 4 ],
		MsgPos[ 8 ],
		MsgSpeed[ 4 ],
		Mute[ 84 ],
		RButtonMode[ 4 ],
		SelAuto[ 4 ], SelSkip[ 4 ],
		SimpleWindow[ 4 ],
		SkipIcon[ 4 ], SkipType[ 4 ],
		SysVoice[ 4 ],
		TextColor[ 4 ], // OTOMEGA
		UseDefaultFont[ 4 ],
		UseFilt[ 4 ],
		VoiceSkip[ 4 ],
		Volume[ 84 ],
		WndPos[ 8 ];
} RegCC;

// Global vars
static FILE *FakeReg;
static RegCC Reg;
const static char ForSafe[ 1024 ] = { 0 };
static int DllErrorStatus;
static int i;

#ifdef DEBUG
static DWORD LoopCount;
static FILE *LogFile;
#endif

// Dialog Size
#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 250
