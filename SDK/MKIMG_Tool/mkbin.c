#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define	VOID	void
#define ULONG   unsigned long
#define USHORT  unsigned short
#define UCHAR   unsigned char
#define LONG    long
#define	SHORT   short			
#define CHAR    char
#define BYTE	UCHAR
#define BOOL	SHORT

#define	TRUE	1
#define	FALSE	0			

CHAR tokensep[] = " \t,\r\n";

LONG GetFileSize (FILE *fp)
{
    LONG save_pos, filesize;
    
    save_pos = ftell(fp);
    fseek(fp, 0L, SEEK_END);
    filesize = ftell(fp);
    fseek(fp, save_pos, SEEK_SET);
    
    return (filesize);	
}	

int main (int argc, char *argv[])
{

    UCHAR INFFile[30], BINFile[30];
    ULONG ulSize;
    FILE *fp1, *fp2, *fp3;
    
    UCHAR string[81], name[20], StringToken[30];
    ULONG ulCurrent=0, ulStart, ulFileSize;
    CHAR  *stop_at;

    UCHAR ch;
    ULONG i;

    strcpy (INFFile, argv[1]);
    strcpy (BINFile, argv[2]);
    ulSize = (ULONG) strtoul(argv[3], &stop_at, 10) * 1024 * 1024;

    if ((fp1=fopen(INFFile,"rb"))==NULL) 
    {
       printf("Can't Open %s \n", INFFile);	 
       return 0;
    }
             
    if ((fp2=fopen(BINFile,"wb"))==NULL) 
    {
       printf("Can't Open %s \n", BINFile);	 
       return 0;
    }
                   
    while (fgets (string, 80, fp1) != NULL)
    {
        sscanf (string, "%[^=] = %s", name, StringToken);
        ulStart = (ULONG) strtoul(StringToken, &stop_at, 16);
        if ((fp3=fopen(name,"rb"))==NULL)
        {
           printf("Can't Open %s \n", name);	 
           return 0;
        }    

        ch = 0xFF;
        while (ulCurrent < ulStart)
        {
            putc (ch, fp2);
            ulCurrent++;                        
        }
        
        ulFileSize = GetFileSize(fp3);
        for (i=0;i<ulFileSize;i++)
        {
            ch = getc(fp3);
            putc (ch, fp2);
            ulCurrent++;            
        }                  
        
        fclose (fp3);
    }

    ch = 0xFF;
    while (ulCurrent < ulSize)
    {
        putc (ch, fp2);
        ulCurrent++;                        
    }
            
    fclose (fp1);
    fclose (fp2);
     
    return(0);   
}
