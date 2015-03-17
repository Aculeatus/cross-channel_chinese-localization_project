#include "stdafx.h"

/*
//����������
struct fileInfoNode
{
 struct _finddata64i32_t fileInfo;  //�����ļ���Ϣ�Ľṹ��
 string fileName;
 struct fileInfoNode* left;
};
//���ļ���Ϣ���ӵ�����head��
int saveToLink(struct fileInfoNode*& head,   //�����ͷ���,���ò���
 const string& fileName,   //IN:�ļ���(����·��)
 const struct _finddata64i32_t& fileInfo) //IN:�ļ���Ϣ�ṹ��,���ò���
{
 //����һ�����
  fileInfoNode* p;
  p=new fileInfoNode;
  p->fileInfo=fileInfo;  //�Ѵ�����ļ���Ϣ���ƽ����
  p->fileName=fileName;
  p->left=head;
  head=p;
  return 0;
}
//��ʾ�������ҵ����ļ�����Ϣ
void displayLink(struct fileInfoNode* head)//IN:ͷ��㣬ֵ���ݲ���
{
 while(head!=NULL)
 {
  cout<<"fileName: "<<head->fileName<<endl;
  cout<<"fileSize: "<<dec<<head->fileInfo.size<<"�ֽ�"<<endl;
  cout<<"fileAttrib: "<<"0x"<<hex<<head->fileInfo.attrib<<endl;
  cout<<"-------------------------------------------------------------------------------------------"<<endl;
  head=head->left;
 }
}
//���ļ���Ϣ�洢���ļ� fileName  ��
void saveLinkToFile(struct fileInfoNode* head,string saveFileName,int counter)
{
 ofstream fout;
 //���ļ�
 fout.open(saveFileName.c_str());
 if((fout.is_open())==false)
 {
  cout<<"�洢�ļ���ʧ�ܣ�"<<endl;
  exit(-1);
 }
 fout<<"the file number is: "<<counter<<endl;
 fout<<"-------------------------------------------------------------------------------------------------------"<<endl;
 while(head!=NULL)
 {
  fout<<"fileName: "<<head->fileName<<endl;
  fout<<"fileSize: "<<dec<<head->fileInfo.size<<"�ֽ�"<<endl;
  fout<<"fileAttrib: "<<"0x"<<hex<<head->fileInfo.attrib<<endl;
  fout<<"-------------------------------------------------------------------------------------------------------"<<endl;
  head=head->left;
 }
 //�ر��ļ�
 fout.close();
}
//
int searchAllFile(string filePath,//IN:�ļ����ڵ�·��,�磺f:example
 int layer,//��Σ�ֻ�в��Ϊ0ʱ��������������ļ���Ϣ����ʾ�ʹ洢
   string fileInfoOut)   //IN:�洢���ļ���
{
 struct _finddata64i32_t fileInfo;//�����ļ���Ϣ�Ľṹ��
 static fileInfoNode* head=NULL; //fileInfoNode�����ͷ���,��̬�洢
 static int counter=0;  //��¼�ļ���Ŀ
 long handle;//���
 int done;//����nextfile�Ƿ�ɹ�
 string fileName=filePath+"\\*.*"; //Ҫ�������ļ���
 //���ҵ�һ���ļ������ؾ��
 handle=_findfirst64i32(fileName.c_str(),&fileInfo);
 if(handle==-1)
 {
  cout<<"��Ŀ¼Ϊ��!"<<endl;
  //cin.get();
   return -1;
 }
 do
 {
 // cout<<"���ҳɹ�"<<endl;
 // cin.get();
 // cout<<fileInfo.name<<endl;
  //������ļ���".",����".."��������ж���һ���ļ�
  if((strcmp(fileInfo.name,".")==0)|(strcmp(fileInfo.name,"..")==0))
  {
   //cout<<"������"<<endl;
   //cin.get();
   continue;
  }
  //������ļ��У��������һ���ļ�������
  if((fileInfo.attrib&_A_SUBDIR)==_A_SUBDIR)
  {
 //  cout<<"���ļ���"<<endl;
 //  cin.get();
   string filePathSub=filePath+"\\"+fileInfo.name;
   //�ݹ����
   searchAllFile(filePathSub,++layer,fileInfoOut);
   layer--;
  }
  //���Ѽ�������Ϣ���ӵ��ļ�
  else
  {
//   cout<<"���ļ����洢��Ϣ!"<<endl;
//   cin.get();
   counter++;
   string fileNameTure=filePath+"\\"+fileInfo.name;
   saveToLink(head,fileNameTure,fileInfo);   //�洢��������
  }
 }while(!(done=_findnext64i32(handle,&fileInfo)));
 _findclose(handle);
 //layer==ʱ���������Ĵ洢
 if(layer==0)
 {
  //��ʾ�����е�����
   displayLink(head);
  //�洢�����е�����
   saveLinkToFile(head,fileInfoOut,counter);
 }
 return 0;
}*/

//void traversal_dir( char *prefix, char *path);

void CreateFolder( string Name );
void getFileList( string Name, string SaveTo );
void getFileListAndSize( string Name, string SaveTo );

#ifdef CROSSCHANNEL
CrossChannelCrack CC( "Cross Channel Translation Project" );
#endif
#ifdef OTOMEGA
CrossChannelCrack CC( "OtoMega Translation Project" );
#endif

int main( )
{
	CC.RunUI( );

	system( "PAUSE" );
	return 0;
}

void getFileList( string Name, string SaveTo )
{
	if( Name.length( ) > 80 ) {
		cout << "FolderName length cannot be larger than 80!" << endl;
	}
	else {
		char tempName[ 81 ];
		for( unsigned int i = 0; i < Name.length( ); i ++ ) {
			if( Name[ i ] == '\\' || Name[ i ] == '/' || Name[ i ] == ':' || Name[ i ] == '?' ||
					Name[ i ] == '\"' || Name[ i ] == '<' || Name[ i ] == '?' || Name[ i ] == '|' ) {
				cout << "Districted character found!" << endl;
				return;
			}
			tempName[ i ] = Name[ i ];
		}
		tempName[ Name.length( ) ] = '\0';
		if( _access( tempName, 6 ) == -1 ) {
			cout << "Not exsiting folder." << endl;
			return;
		}
		else {
			//traversal_dir( "", tempName );
			
		}
	}
	return;
}

/*void traversal_dir( char *prefix, char *path)
{

	char filename[ 512 ], pathname[ 81 ];
	size_t pathlen = 0;

	char szFind[ MAX_PATH ];
	WIN32_FIND_DATA FindFileData;
	strcpy(szFind,path);
	strcat(szFind,"/*.*");
	HANDLE hFind = ::FindFirstFile( szFind, &FindFileData );
	if( INVALID_HANDLE_VALUE == hFind )
	{
		return;
	}

	while(TRUE)
	{
		if (FindFileData.cFileName[0] != '.') 
		{
			sprintf(filename, "%s/%s", path,FindFileData.cFileName);
			sprintf(pathname, "%s%s", prefix, FindFileData.cFileName);

			//����Ŀ¼�ݹ����
			if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				strcat(pathname, "/");
				traversal_dir(pathname, filename);
			}
			else
			{
				FILE *f = NULL;
				char *buf = NULL;
				if((f=fopen(filename,"r"))==NULL) {
					printf("Error!\n");
					return;
				}
				size_t nFileSize = ftell(f);
				buf = new char[nFileSize+1];
				fread(buf, nFileSize+1, 1,f);
				printf("%s\n", buf);
				delete [ ] buf;
				fclose(f);
			}
		}

		if(!FindNextFile(hFind,&FindFileData)) break;
	}

	FindClose(hFind);
	return;
}
*/