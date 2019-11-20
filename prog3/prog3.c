#define BLOCKSIZE 16

#include <stdio.h>       /* for fprintf, sprintf */
#include <stdlib.h>      /* for exit */
#include <errno.h>       /* error handling */
#include <string.h>      /* for ? */
#include "prog3_funcs.h"
#include <curl/curl.h>

int main(int argc, char *argv[]) {
  char *ifile = NULL;               /* to point to input file name */
  FILE *fip = NULL;                 /* to point to opened input file */
  char *ofile = NULL;               /* to point to output file name */
  FILE *fop = NULL;                 /* to point to opened output file */
  char *kfile = NULL;               /* to point to key file name */
  FILE *fkp = NULL;                 /* to point to opened key file */
  
  char* serverName = NULL;
  char* dirName = NULL;
  char* userID = NULL;
  char* pw = NULL;
  
  unsigned char block[BLOCKSIZE];   /* to hold bytes read from input file */
  unsigned char key[BLOCKSIZE];     /* to hold key for encryption/decryption read from key file */

  parseArgs(argc, argv, &ifile, &ofile, &kfile, &serverName, &dirName, &userID, &pw);    /* parse arguments and return pointers to filenames */

  //fip = Fopen(ifile, "r");
  //fop = Fopen(ofile, "w");
  //fkp = Fopen(kfile, "r");
  
  FILE *fEncryptedFile = Fopen("downloadedFile", "r"); //this is downloadedFile
  FILE *fDecryptedFile = Fopen("DecryptedFile", "w"); //this can be anything - maybe output?
  FILE *fDecryptedAnswer = Fopen("DecryptedAnswer", "w");
  FILE *fEncryptedAnswer = Fopen("EncryptedAnswer", "w");
  fkp = Fopen(kfile, "r");

  //ftpDownload - directory and input file as pathname 
  char str[256];
  int rc =0;

  rc = ftpDownload(userID, pw, serverName, dirName);
  
  if (rc) {                                                  /* bail if transfer was unsuccessful */
    sprintf(str, "Unable to download %s from %s (curl rc = %d (%s))", dirName, serverName, rc, curl_easy_strerror(rc));
    bail(15, str);
  }                                                   

//decrypt - use key for decryption

readKey(key, BLOCKSIZE, fkp);                     /* read the key for encryption/decryption */
encryptDecrypt(block, key, BLOCKSIZE, fEncryptedFile, fDecryptedFile);

//solve equaiton, write into file
//should prob pass in a file pointer and use getline +sscanf or fscanf
 readByWhiteSpace(fDecryptedFile);
  
//encrypt - use key for encryption
  
//ftpUpload - use directory and output file as pathname
  
  
//encryptDecrypt(block, key, BLOCKSIZE, fip, fop);  /* encrypt/decrypt the input file and write to output file */

Fclose(fip);
Fclose(fop);
Fclose(fkp);

return 0;
}

