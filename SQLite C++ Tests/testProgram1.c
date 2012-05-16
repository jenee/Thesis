#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>

/*
   referenced chapter 6 of "The Definitive Guide to SQLite", Grant Allen and Mike Owens
   referenced website: http://www.linuxjournal.com/content/accessing-sqlite-c
http://milky.manishsinha.net/2009/03/30/sqlite-with-c/
*/

int callback( void *data, int ncols, char **values, char **headers );

int main(int argc, char* argv[]) {
   sqlite3  *conn;
   sqlite3_stmt   *res;
   int error = 0;
   int rec_count = 0;
   const char *data = "Callback function called: ";
   char *zErr;
   
   char* orthoQueryWord;
   char* sql;


   if( argc < 2 ) {
      fprintf(stderr,"USAGE: ./testProgram1 <databaseName> <orthoToLookup> \n");
      fprintf(stderr,"  |___EXAMPLE: ./testProgram1 ../SQLlite\\ browser\\ tests/phoneticDict hello\n");
      exit(-1);
   }

   error = sqlite3_open( argv[1], &conn);
   if ( error ) {
      fprintf(stderr,"Cannot open database %s: %s",argv[1], sqlite3_errmsg(conn)); 
      fprintf(stderr,"USAGE: ./testProgram1 <databaseName> <orthoToLookup> \n");
      fprintf(stderr,"  |___EXAMPLE: ./testProgram1 ../SQLlite\\ browser\\ tests/phoneticDict hello\n");
      exit(0);
   } else {
      fprintf(stdout,"Sucessful connection to database %s",argv[1]); 
      if( argc > 2) {
         orthoQueryWord = argv[2];
      } else {
         sprintf(orthoQueryWord, "%s", "hello");
      }
   }
   
   sprintf( sql, "select * from phoneticDictTable");
   //sprintf( sql, "select * from phoneticDictTable where ortho = \"%s\"", orthoQueryWord);
   //sql = "select * from phoneticDictTable where ortho = \"hello\"";
   //sql = "select SAMPA from phoneticDictTable where ortho = \"hello\"";
  
   error = sqlite3_exec( conn, sql, callback, data, &zErr); 

   sqlite3_close( conn );
	return 0;
}

//Simple callback from pg 158 of "The Definitive Guide to SQLite", Grant Allen and Mike Owens
int callback( void *data, int ncols, char **values, char **headers ) {
   int i;
   
   fprintf( stderr, "%s: ", (const char*) data );

   for( i = 0; i < ncols; i++ ) {
      fprintf( stderr, "%s=%s", headers[i], values[i] );
   }
   
   fprintf( stderr, "\n");
   return 0; //if return nonzero, will cause sqlite3_exec to abort
   
}
