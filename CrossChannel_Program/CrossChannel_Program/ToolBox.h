#ifndef TOOLBOX_H
#define TOOLBOX_H

class NASCToolBox
{
public:
	NASCToolBox( void );
	~NASCToolBox( void );

	/*�ַ����*/
	bool isPunctuation( wchar_t P ) const; // �ж��Ƿ�Ϊ������

	/*�ַ������*/
	void StringToChars( string temp, char *C ) const;
	void WstringToWchars( wstring temp, wchar_t *WC ) const;
	wstring StringToWstring( UINT LocalOption, string str ) const;
	string WstringToString( UINT LocalOption, wstring wstr ) const;
	string IntToString( long i ) const;
	int StringToInt( string str ) const;
	int StringToInt( wstring wstr ) const;
	int SubstringToInt( string str, int StartIndex, int EndIndex ) const;
	int SubstringToInt( wstring wstr, int StartIndex, int EndIndex ) const;

	/*ʱ��������*/
	int TimeToInt( string Time ) const;
	int TimeToInt( wstring Time ) const;
	string IntToTime( int Num ) const;
	wstring IntToTimeW( int Num ) const;

	/*�������*/
	string DecToHex( unsigned long i ) const;
	int Random( int range_min, int range_max ) const;

	/*�ļ����*/
	void CreateFolder( string Name ) const;

	/*ͼ�δ������*/
	struct Martrix {
		int Width, Height; // ����
		char **Graph; // ��ά��̬����
	};
	int getStringWidth( wchar_t* fontName, BYTE fontCharset, int OutLine, int fontHeight, int fontSpace, wchar_t *str );

	/*������ǻ���CairoGraphic�Ĺ��ߺ���*/

private:

};

#endif
