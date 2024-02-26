#include	<windows.h>
#include	<stdio.h>

extern	void	decode_tim2	(char *,unsigned long,unsigned char *);

		void	decode_tlz(char *,unsigned long,unsigned char *);

void	decode_tlz(char *name,unsigned long ssrc,unsigned char *src)
{	unsigned long	tul1;
	char			tim2name[MAX_PATH];

	for(tul1=0;*(unsigned long *)(src+(tul1)*4)<ssrc;tul1++){
		sprintf(tim2name,"%s_%02d",name,tul1);
		printf("%s.tim2\n",tim2name);
		decode_tim2(tim2name,ssrc,src+ *(unsigned long *)(src+tul1*4));
	}
}



