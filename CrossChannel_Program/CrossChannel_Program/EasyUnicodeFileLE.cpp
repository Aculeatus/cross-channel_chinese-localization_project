#include "StdAfx.h"
#include "EasyUnicodeFileLE.h"

/* * * < ERROR EXPLANATION LIST > * * */
/*
  ERROR_EUFLE001 - Not support open in-out file. ( When ios::in & ios::out appear together. )
  ERROR_EUFLE002 - Not support open in-trunc file. ( When ios::in & ios::trunc appear together. )
  ERROR_EUFLE003 - Not support open not in/out file. ( When ios::in & ios::out appear neither. )
  ERROR_EUFLE004 - Cannot open file. ( When trying to open a file, but fail to open it. )
  ERROR_EUFLE005 - Not a Little-Endian Unicode file. ( When opening a nor Little-Endian Unicode file in open mode. )
  ERROR_EUFLE006 - Not a Little-Endian Unicode file. ( When opening a nor Little-Endian Unicode file in write append mode. )
  ERROR_EUFLE007 - Cannot close file. ( When trying to close a file, but fail to close it. )
  ERROR_EUFLE008 - Unknown error. ( When reading a WideChar from a file, but run into the "catch". )
  ERROR_EUFLE009 - Unknown error. ( When reading a WCharLine from a file, but run into the "catch". )
  ERROR_EUFLE010 - Unknown error. ( When setting pointer in ios::cur mode. )
  ERROR_EUFLE011 - Unknown error. ( When setting pointer in ios::end mode. )
  ERROR_EUFLE012 - Unsupport referring file mode. ( When setting pointer not in ios::beg/cur/end mode. )
*/

/* * * < WARNING EXPLANATION LIST > * * */
/*
  WARNING_EUFLE001 - Target opening file is open, and will be closed. ( When target opening file is open. )
*/

EasyUnicodeFileLE::EasyUnicodeFileLE( )
{
	return;
}
EasyUnicodeFileLE::EasyUnicodeFileLE( string FileName, ios_base::open_mode OpenMode )
{
	open( FileName, OpenMode );//ִ�д��ļ���һϵ�в���
	return;
}

EasyUnicodeFileLE::~EasyUnicodeFileLE( void )
{
	return;
}

bool EasyUnicodeFileLE::Initialization( ios_base::open_mode OpenMode ) const
{
	/*��ʼ������*/
	if( ( ios_base::in | OpenMode ) == OpenMode && ( ios_base::out | OpenMode ) == OpenMode ) {
		cout <<  "ERROR_EUFLE001 - Not support open in-out file." << endl;
		system( "PAUSE" );
		return false;
	}
	else if( ( ios_base::in | OpenMode ) == OpenMode && ( ios_base::trunc | OpenMode ) == OpenMode ) {//������������
		cout << "ERROR_EUFLE002 - Not support open in-trunc file." << endl;
		system( "PAUSE" );
		return false;
	}
	else if( ( ios_base::in | OpenMode ) != OpenMode && ( ios_base::out | OpenMode ) != OpenMode ) {
		cout << "ERROR_EUFLE003 - Not support open not in/out file." << endl;
		system( "PAUSE" );
		return false;
	}
	else return true;
}

void EasyUnicodeFileLE::open( string FileName, ios_base::open_mode OpenMode )
{
	/*�ȹر�����*/
	if( F.is_open( ) ) {
		cout << "WARNING_EUFLE001 - Target opening file is open, and will be closed." << endl;
		cout << "                   ( File Name: " << FileName << " )" << endl;
		close( );
	}

	/*��ʼ������*/
	if( !Initialization( OpenMode ) ) return;

	/*�ж϶�orдģʽ*/
	JudgeReadOrWrite( OpenMode );

	/*ִ�д򿪲���*/
	char Name[ 1000 ];
	Tools.StringToChars( FileName, Name );
	F.open( Name, OpenMode | ios_base::in | ios_base::binary ); //�ڲ�Ҫ���ж�ȡ����
	if( !F.is_open( ) ) {
		cout << "ERROR_EUFLE004 - Cannot open file." << endl;
		cout << "                 ( File Name: " << Name << " )" << endl;
		system( "PAUSE" );
		return;
	}

	/*ͷ����Ǵ���*/
	char Head[ 3 ] = "\xFF\xFE";
	if( IsReadMode ) {//����ģʽ
		if( DEBUG_FLAG ) cout << "File of in-mode." << endl;
		F.read( Head, 2 );
		if( strcmp( Head, "\xFF\xFE" ) ) {
			cout << "ERROR_EUFLE005 - Not a Little-Endian Unicode file." << endl;
			cout << "                 File Name: " << Name << endl;
			cout << "                 Encode:    " << testFileHeader( ) << endl;
			system( "PAUSE" );
			return;
		}
	}
	else {
		if( DEBUG_FLAG ) cout << "File of out-mode." << endl;
		if( ( ios_base::trunc | OpenMode ) == OpenMode ) F.write( Head, 2 );//��д���ģʽ
		else { //���Ǹ�дģʽ��Ҫ����֤FFFE
			F.seekg( 0, ios_base::beg );
			F.read( Head, 2 );
			if( strcmp( Head, "\xFF\xFE" ) ) {
				cout << "ERROR_EUFLE006 - Not a Little-Endian Unicode file." << endl;
			cout << "                 ( File Name: " << Name << " )" << endl;
				system( "PAUSE" );
				return;
			}
			SetPointer( 0, ios_base::end );
		}
	}

	return;
}

void EasyUnicodeFileLE::close( )
{
	F.close( );
	if( DEBUG_FLAG ) cout << "File closed." << endl;
	if( F.is_open( ) ) {
		cout << "ERROR_EUFLE007 - Cannot close file." << endl;
		system( "PAUSE" );
		return;
	}
	return;
}


wchar_t EasyUnicodeFileLE::readWchar( )//��ȡһ�����ַ�
{
	if( !IsReadMode ) return L'';//���ģʽ���������
	if( IsEOF( ) ) return L'';//����Ѿ����ļ�β�ˣ��Ͳ�����

	wchar_t Temp2[ 2 ];
	wchar_t tempWC[ 2 ];
	try {
		F.read( (char *)tempWC, 2 );
		tempWC[ 1 ] = L'\0';

		if( tempWC[ 0 ] == L'\x000D' ) {
			F.read( (char *)Temp2, 2 );
			Temp2[ 1 ] = L'\0';
			if( Temp2[ 0 ] == L'\x000A' ) return L'\n';
			else {
				SetPointer( -1, ios_base::cur );
				return tempWC[ 0 ];
			}
		}
		else return tempWC[ 0 ];
	}
	catch( ... ) {
		cout << "ERROR_EUFLE008 - Unknown error." << endl;
		system( "PAUSE" );
		return L'';
	}
	return tempWC[ 0 ];
}

wstring EasyUnicodeFileLE::readLine( )//��ȡһ�п��ַ�
{
	if( !IsReadMode ) return L""; // ���ģʽ���������
	if( IsEOF( ) ) return L""; // ����Ѿ����ļ�β�ˣ��Ͳ�����

	wstring t;
	wchar_t Temp1/*, Temp2*/;
	try {
		Temp1 = readWchar( );
		if( Temp1 != L'\n' ) return Temp1 + readLine( );
		else return L"";
		/*if( Temp1 == L'\x000D' ) {
			Temp2 = readWchar( );
			if( Temp2 == L'\x000A' ) return L"";
			else if( Temp2 == L'\x000D' ) {
				SetPointer( -1, ios_base::cur );
				t += Temp1;
				return t + readLine( );
			}
			else {
				t += Temp1;
				t += Temp2;
				return t + readLine( );
			}
		}
		else {
			t += Temp1;
			return t + readLine( );
		}*/
	}
	catch( ... ) {
		cout << "ERROR_EUFLE009 - Unknown error." << endl;
		system( "PAUSE" );
		return L"";
	}
}

void EasyUnicodeFileLE::write( wstring WC )//д��ָ�����ַ���
{
	//��"\0D00\0A00"�����ж�
	int L = WC.length( );
	wchar_t temp[ 2 ];
	if( DEBUG_FLAG ) cout << "Run into write." << endl;
	for( int i = 0; i < L; i ++ ) {
		temp[ 0 ] = WC[ i ];
		temp[ 1 ] = L'\0';
		if( temp[ 0 ] == L'\n' ) {
			F.write( "\x0D\x00\x0A\x00", 4 );
			/*F.write( "\x0D\x0A\x00", 3 );//���Խ�������L"\x0A"�Ľ����\x0D0A
			F.seekg( -3, ios_base::cur );//����Ǹ�д
			F.write( "\x00", 1 );
			F.seekg( 2, ios_base::cur );//������ڴ򿪷�ʽ����û��binary*/
		}
		else F.write( (char *)temp, 2 );
	}
	return;
}

void EasyUnicodeFileLE::write( UINT LocalOption, string S )
{
	write( Tools.StringToWstring( LocalOption, S ) );
}


void EasyUnicodeFileLE::writeln( wstring WC )
{
	write( WC + L"\n" );
}

void EasyUnicodeFileLE::writeln( UINT LocalOption, string S )
{
	write( Tools.StringToWstring( LocalOption, S + "\n" ) );
}

void EasyUnicodeFileLE::SetPointer( std::streamoff off, basic_istream< char, char_traits< char > >::pos_type PosType )
{
	/*
	����˵����
		off ����Ҫƫ�Ƶ�ֵ
		PosType ����������ʼλ��
	ö�����ͣ�
		enum seek_dir {beg, cur, end};
		ÿ��ö�ٳ����ĺ��壺
		ios::beg ���ļ�������ʼλ��
		ios::cur ���ļ����ĵ�ǰλ��
		ios::end ���ļ����Ľ���λ��
	*/

	//ע���ļ�ͷ
	if( IsEOF( ) ) F.clear( );

	if( (int)PosType == ios_base::beg && off >= 0 ) {
		F.seekg( 2 /*+ 2 * off*/, ios_base::beg );//FF FE
		for( int i = 0; i < off; i ++ ) readWchar( );
	}
	else if( (int)PosType == ios_base::cur ) {
		F.seekg( 0/*2 * off*/, ios_base::cur );
		if( off >= 0 ) for( int i = 0; i < off; i ++ ) readWchar( );
		else for( int i = 0; i < -off; i ++ ) {
			try {
				F.seekg( -4, ios_base::cur );
				if( readWchar( ) == L'\n' ) {
					F.seekg( -4, ios_base::cur );
					continue;
				}
			}
			catch( ... ) {
				cout << "ERROR_EUFLE010 - Unknown error." << endl;
				system( "PAUSE" );
			}
		}
	}
	else if( (int)PosType == ios_base::end && off <= 0 ) {
		F.seekg( 0/*2 * off*/, ios_base::end );
		for( int i = 0; i < -off; i ++ ) {
			try {
				F.seekg( -4, ios_base::cur );
			   	if( readWchar( ) == L'\n' ) {
					F.seekg( -4, ios_base::cur );
					continue;
				}
			}
			catch( ... ) {
				cout << "ERROR_EUFLE011 - Unknown error." << endl;
				system( "PAUSE" );
   			}
		}
	}
	else cout << "ERROR_EUFLE012 - Unsupport referring file mode." << endl;
	return;
}

bool EasyUnicodeFileLE::IsEOF( )//�ж��Ƿ�Ϊ�ļ�ĩβ
{
	char t[ 2 ];
	F.read( t, 1 );
	t[ 1 ] = '\0';//������Ԥ��һ�������ж�

	if( F.eof( ) ) return true;
	else {
		F.seekg( -1, ios_base::cur );
		return false;
	}
}

string EasyUnicodeFileLE::testFileHeader( )
{
	F.seekg( 0, ios::beg );
	char Header[ 4 ];

	F.read( Header, 3 );
	Header[ 3 ] = '\0';

	//cout << hex << (int)Header[ 0 ] << ' ' << (int)Header[ 1 ] << ' ' << (int)Header[ 2 ] << dec << endl;
	if( Header[ 0 ] == '\xEF' && Header[ 1 ] == '\xBB' && Header[ 2 ] == '\xBF' ) return "UTF-8";
	else if( Header[ 0 ] == '\xFF' && Header[ 1 ] == '\xFE' ) return "Unicode - Little Endian";
	else if( Header[ 0 ] == '\xFE' && Header[ 1 ] == '\xFF' ) return "Unicode - Big Endian";
	else return "ANSI";
}

void EasyUnicodeFileLE::JudgeReadOrWrite( ios_base::open_mode OpenMode )
{
	if( ( ios_base::in | OpenMode ) == OpenMode && ( ios_base::out | OpenMode ) != OpenMode ) IsReadMode = true;//����ģʽ
	else if( ( ios_base::out | OpenMode ) == OpenMode ) IsReadMode = false;//���ģʽ
	else {
		cout << "Error: EasyUnicodeFileLE006 - Neither in nor out file." << endl;
		system( "PAUSE" );
	}
	return;
}

bool EasyUnicodeFileLE::IsOpen( ) const
{
	return F.is_open( );
}
