#ifndef PROG3_FUNCS
#define PROG3_FUNCS

void   parseArgs(int, char *[], char **, char **, char **, char **, char **, char **, char **);     /* in: argc, argv; out: ifile, ofile, kfile */
int ftpDownload(char *, char *, char*, char *, char *); 
size_t ftpWrite(void *, size_t, size_t , void* );
//static int     ftpDownload(char *, char *, char *, char *);
//static size_t  ftpWrite(void *, size_t, size_t, void *);
void  *Malloc(size_t);                                          /* in: bytes to allocated; return: void ptr to allocated memory */
FILE  *Fopen(const char *, const char *);                       /* in: path/file, mode; return: file ptr */
void   readKey(unsigned char *, size_t, FILE *);                         /* in: buffer ptr, key length, key file ptr */
void   encryptDecrypt(unsigned char *, unsigned char *, size_t, FILE *, FILE *);  /* in: buffer ptr, key ptr, buffer size, input file ptr, output file ptr */
size_t Fread(void *, size_t, size_t, FILE *);                   /* in: buffer ptr, buffer size, num buffers, input file ptr; return: bytes read */
size_t Fwrite(const void *, size_t, size_t, FILE *);            /* in: buffer ptr, buffer size, num buffers, output file ptr; return: bytes written */
void   Fclose(FILE *);                                          /* in: file ptr */
void   bail(int, const char *);                                 /* in: rc to exit with, ptr to message to print */
void   help();

void extractValues(FILE *, long *, long *, char*);
int solveEquation(long , long , char*);
int ftpUpload(FILE *, char*, char* , char* , char *, char *);
size_t ftpRead(void * , size_t , size_t , void *);
#endif
