#ifndef CROSSCHANNELCRACK_H
#define CROSSCHANNELCRACK_H

#pragma pack( 1 )
#define ARC_VERSION 1
//#define ARC_VERSION 2
#define SECTION_SIZE 10

#if ARC_VERSION >= 2
#define FILENAME_LENGTH 13
#else
#define FILENAME_LENGTH 9
#endif

/**********************************************************************
CrossChannelCrack��Ĺ���

�ر����ܣ�
1.UI�����û���������
2.��ȡ���ܣ��ļ�������������
3.��װ���ܣ��ļ��У���������
4.ͳ����Ϸ������ɶȣ�Ҳ��ͳ�ƴ浵��

���߹��ܣ��Ժ������װ���ࣩ��
01.�����ļ���
02.��ȡ�ļ����е��ļ��б�
03.��ȡ�ļ����е��ļ��б������ļ����ֽ���
04.����ת�������ض����뵽Unicode
05.����ת������Unicode���ض����룬ע��������ʾ�ַ������ַ����ڡ�
06.����ת�������ض����뵽Unicode-bigEndian
07.����ת������Unicode-bigEndian���ض����룬ע��������ʾ�ַ������ַ����ڡ�
08.����ת�������ض����뵽UTF-8
09.����ת������UTF-8���ض����룬ע��������ʾ�ַ������ַ����ڡ�
10.����ת�������ض����뵽UTF-16
11.����ת������UTF-16���ض����룬ע��������ʾ�ַ������ַ����ڡ�
12.
**********************************************************************/

class CrossChannelCrack
{
public:
	CrossChannelCrack( string PName );
	~CrossChannelCrack( void );

	/*������Ǳر�����*/
	void RunUI( );
	void __1_Unpack( string FileName, string OutputFolder ); //�ϰ�Ľ��
	void __1_Unpack2( string FileName, string OutputFolder ); //���̰�Ľ��
	void __2_Pack( string pFileName, string SourceFolder ); //ͨ��gFile��ȡ������ͣ������Ӧ�����Դ�ļ��п�����ע���ļ�
	void __3_Decrypt( string InputFolder );
	void __4_Decrypt( string OriginalUnpackFolder, string PureScriptFolder );
	void __7_CalculateSaves( string GameFolder );//������Ϸ������ɶ�
	void __8_CCSProcess( string InputFolder, string OutputFolder ); // ����CCS����һ�����裬����-У��-��ɫ-����
	void __9_CCSInit( string InputFolder, string OutputFolder, string ReferFolder );
	void __10_GetAllChapterTitle(string InputFolder, string OutputFile);
	void __11_SetAllChapterTitle(string InputFile, string OutputFolder);
	void __12_PackText(string InputFolder, string OutputFile);

	/*������ǹ��߹���*/
	void _01_CreateFolder( string Name );
	void _02_getFileList( string FolderName, string SaveTo ); /* ��֧�������ļ������ļ��� */
	void _03_getFileListAndSize( string FolderName, string SaveTo ); /* ��֧�������ļ������ļ��� */
	void _04_ConvertToUnicode( UINT LocalOption, string gFileName, string SaveTo );
	void _05_UnicodeConvertTo( UINT LocalOption, string gFileName, string SaveTo );

protected:
	wstring StringToWstring( UINT LocalOption, string str );
	string WstringToString( UINT LocalOption, wstring wstr );
	unsigned __int64 LittleEndianCharsToValue( char LEValue[ 9 ] );
	unsigned __int64 LittleEndianCharsToValue_s( UINT Length, char LEValue[ 9 ] );
	string ValueToLittleEndianChars( unsigned __int64 Value );

private:
	NASCToolBox TB;
	static const bool DebugMode = true;
	string ProjectName;

	void getFolderList( string FolderName, string SaveTo ); /* ��֧�������ļ������ļ��� */
	void Test( );

	unsigned char WSC_DecryptHelper( unsigned char s );
	unsigned char WSC_EncryptHelper( unsigned char s );

	unsigned long unwipf( unsigned char *buff,      // �����ļ����ĵ�array
						  unsigned long  len,       // �����ļ�����
						  unsigned char *out_buff,  // ����ļ����ĵ�array
						  unsigned long  out_len ); // ����ļ�����

	void wipf_fake( unsigned char *buff,       // �����ļ����ĵ�array
					unsigned long  len,        // ���ĵĳ���
					unsigned char **out_buff,  // ����ļ�������array
					unsigned long *out_len );  // ����ļ�����

	/* Structures */
	struct ARCHDR {
		unsigned long section_count; // ������
	}; // �鵵ͷ��

	struct ARCSECTHDR {
		char          type[ 4 ];   // "PNG", "MOS", "OGG"
		unsigned long entry_count; // �ļ���
		unsigned long toc_offset;  // ��ʼ����ƫ�Ƶ�ַ
	}; // �鵵����ϸ��

	struct ARCENTRY {
		char          filename[ FILENAME_LENGTH ];
		unsigned long length; // �ļ�����
		unsigned long offset; // �ļ���ʼ��ƫ�Ƶ�ַ
	}; // �ļ�ϸ��

	struct WIPFHDR {
		unsigned char  signature[ 4 ]; // "WIPF";
		unsigned short entry_count;    // �ļ���
		unsigned short depth;          // λ���
	}; // WIPF�ļ�ͷ��

	struct WIPFENTRY {
		unsigned long  width;    // ���
		unsigned long  height;   // �߶�
		unsigned long  offset_x; // x������ʾλ��
		unsigned long  offset_y; // y������ʾλ��
		unsigned long  unknown1; // layer?
		unsigned long  length;   // �ļ�����
	}; // WIPF�ں��ļ�ϸ��

};

#endif
