#ifndef EASYUNICODEFILELE_H
#define EASYUNICODEFILELE_H
#include "ToolBox.h"

//Little - Endian
class EasyUnicodeFileLE
{
public:
	EasyUnicodeFileLE( );
	EasyUnicodeFileLE( string FileName, ios_base::open_mode OpenMode );
	~EasyUnicodeFileLE( void );

	void open( string FileName, ios_base::open_mode OpenMode );
	void close( );

	wchar_t readWchar( ); //��ȡһ�����ַ�
	wstring readLine( ); //��ȡһ�п��ַ�
	void write( wstring WC ); //д��ָ�����ַ���
	void write( UINT LocalOption, string S ); //д��ָ��խת���ַ���
	void writeln( wstring WC ); // write line
	void writeln( UINT LocalOption, string S ); // write line
	void SetPointer( std::streamoff off, basic_istream< char, char_traits< char > >::pos_type PosType );
	bool IsOpen( ) const; // �ж��Ƿ�򿪣���true��δ��false
	bool IsEOF( ); //�ж��Ƿ�Ϊ�ļ�ĩβ
	string testFileHeader( );

private:
	static const bool DEBUG_FLAG = false;
	fstream F;
	NASCToolBox Tools;

	bool IsReadMode;
	bool Initialization( ios_base::open_mode OpenMode ) const; //��ʼ��
	void JudgeReadOrWrite( ios_base::open_mode OpenMode );

};

#endif
