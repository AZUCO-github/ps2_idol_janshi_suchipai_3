///////////////////////////////////////////////////////////////////////////////
//	PS2	スーチパイIII converter
//		071017
//			by	AZUCO
///////////////////////////////////////////////////////////////////////////////
#include	<windows.h>
#include	<stdio.h>

extern	void	decode_tlz	(char *,unsigned long,unsigned char *);

int	main(int argc,char *argv[])
{
	unsigned char	*buff=NULL;

	HANDLE			hndl;
	HANDLE			hscl;

	unsigned long	file_size;

	unsigned long	tul;
	unsigned long	tul3;
	unsigned long	fnargc=0;

	char			drive[MAX_PATH];
	char			dir[MAX_PATH];
	char			fname[MAX_PATH];
	char			ext[MAX_PATH];

	printf("PS2 スーチーパイIII Converter\n");
	printf("\t\tProg. By AZUCO\n\n");

	if(argc==1){
		printf("milk <option ...> <file ...>\n");
		printf("<type>\t<option>\n");
		exit(0);
	}

///////	option	///////////////////////////////////////////////////////////////
	for(tul=1;tul<argc;tul++){
		if(argv[tul][0]=='/'){
			if(	argv[tul][1]=='a' &&
				argv[tul][2]=='f'	)
				NULL;
		}else{
			if(fnargc==0)	fnargc=tul;
		}
	}

//strcpy(argv[fnargc],"E:\\src\\afs\\src\\ADX\scl\\bb_02.scl");

	hndl=CreateFile(argv[fnargc],
					GENERIC_READ,0,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
	if(hndl==(HANDLE)-1){
		printf("\tError\tsource file not found\n");
		exit(-1);	}

	file_size=GetFileSize(hndl,NULL);

	_splitpath(argv[fnargc],drive,dir,fname,ext);

	if(	strcmp(_strlwr(ext),".tlz")==0){
		buff=new unsigned char[file_size];
		ReadFile(hndl,buff,file_size,&tul,NULL);
		decode_tlz(fname,file_size,buff);
		goto esc;	}

esc:
	CloseHandle(hndl);
	if(buff!=NULL){	delete[]	buff;	buff=NULL;	}
}
