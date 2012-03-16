#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>

/*
   referenced website: http://www.linuxjournal.com/content/accessing-sqlite-c
http://milky.manishsinha.net/2009/03/30/sqlite-with-c/
*/
int main(int argc, char* argv[]) {
   sqlite3  *conn;
   sqlite3_stmt   *res;
   int error = 0;
   int rec_count = 0;
   const char *errMSG;
   const char *tail;

   error = sqlite3_open( argv[1], &conn);
   if ( error ) {
      fprintf(stderr,"Cannot open database %s",argv[1]); 
      exit(0);
   }
   


	return 0;
}
