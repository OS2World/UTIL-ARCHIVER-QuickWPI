#include <fstream.h>
#include <stdlib.h>
//#include <string.h>


#include "readme_pg.cpp"      // creates readme-pages
#include "package.cpp"        // creates the package
#include "check.cpp"          // check for existing files
#include "wrt_cnt.cpp"        // write something
#include "wic_exec.cpp"       // runs wic.exe
#include "mk_filename.cpp"    // creates filename from <basename> and extension
#include "chk_arg.cpp"        // checks the arguments (extremely basic...)
#include "del_file.cpp"        // delete the temporary .wis file
#include "adf_move.cpp"

#define N_TYPES 21            // number of files to look for. config-file?
#define N_AUTOMATIC_TYPES 4   // number of files that are derived from <basename>
#define N_FILE  13            // length of accepted filename, keep it DOS


// defines the version number
#define VERSION 0
#define MAJOR   18
#define MINOR   2


// some binary decisions
#define YES 1
#define NO 0
#define UP 1
#define DOWN 0




int main( int argc, char **argv )
{

   char *filename        = new char[N_FILE]  ;
   char *scriptname      = new char[N_FILE]  ;
   char *archivename     = new char[N_FILE]  ;
   char *basename        = new char[9]       ;
   char *long_scriptname = new char[N_FILE+3];

   unsigned short createObject      ;
   unsigned short page_id      = 1  ;
   unsigned short mode         = 0  ;
   unsigned short rm_wis       = YES;
   unsigned short rc                ;

   unsigned short i_temp, readme_found = NO;

   char automatic_types[N_AUTOMATIC_TYPES][N_FILE];
   char readme_types[N_TYPES][N_FILE] = { "README"      ,
                                          "LIESMICH"    ,
                                          "LISEZ.MOI"   ,
                                          "README.1ST"  ,
                                          "READ.ME"     ,
                                          "README.DOC"  ,
                                          "README.TXT"  ,
                                          "README.OS2"  ,
                                          "LIESMICH.TXT",
                                          "README.ENG"  ,
                                          "README.GER"  ,
                                          "FILE_ID.DIZ" ,
                                          "HISTORY"     ,
                                          "CHANGES.TXT" ,
                                          "CHANGELOG"   ,
                                          "OPTIONS.TXT" ,
                                          "LICENSE.TXT" ,
                                          "LIZENZ.TXT"  ,
                                          "WHATSNEW.TXT",
                                          "REGISTER.TXT",
                                          "TECHNOTE.TXT",  };


   // if no parameter is given print a usage message
   if( argc == 1 )
   {
     usage();
/*
     // Implement VERSION.QWP instead and print usage if no parameters are given
     mode = 1
*/
   }




   // checks if the -i parameter has been specified
   if( argc == 3 )
   {

     // is just a dummy, will implement something funny later
     mode = chk_arg( argv[2] );

   }



   system( "cls" );


   // output the basic configuration information
   cout << "\n\t\t   Quick-WPI " << VERSION << ".";
   cout << MAJOR << "." << MINOR << " (C) 2001 J”rg Skottke\n\n";





   // Cut off everything beyond 8 chars. Yes, i know...
   strncpy( basename , argv[1] , 8 );
   cout << "\t\tBasename...: " << basename << endl;




   // find EXE, Script and archive filenames.
   mk_filename( filename    , basename , "exe" );  // builds the exe-name
   mk_filename( scriptname  , basename , "wis" );  // builds the wis-name
   mk_filename( archivename , basename , "wpi" );  // builds the wpi-name




   // creating the scriptname
   strcpy( long_scriptname , "..\\" );
   strcat( long_scriptname , scriptname );




   // some more files to look for that depend on the basename
   mk_filename( automatic_types[0] , basename , "txt" );
   mk_filename( automatic_types[1] , basename , "nfo" );
   mk_filename( automatic_types[2] , basename , "doc" );
   mk_filename( automatic_types[3] , basename , "os2" );




   // print the basic files to the screen
   cout << "\t\tExe-name...: " << filename    << endl;
   cout << "\t\tScriptname.: " << scriptname  << endl;
   cout << "\t\tArchive....: " << archivename << endl;



   cout << "\n\t\t------------------------------------------------";


   // delete the archive-file, if it exists
   if( chk_exe( archivename ) == YES )
   {

     cout << "\n\t\t: Found existing archive, deleting it!         :";

     del_file( archivename );

   }




   // open the output stream (the .wis-file is created at ..\)
   fstream script( long_scriptname , ios::out );





   // begin XML style tag for wpi
   script << "<WARPIN>\n";




   // this creates the package
   script << "<HEAD>\n";
   script << package( 1, mode, basename, filename, chk_exe( filename ) );
   // if there should be more packages, put them in here.
   // i'm afraid this will need a major redesign of the program to work
   script << "</HEAD>\n";




   // this creates the script
   script << "<BODY>\n";
   script << readme_init_pg( page_id, basename );



   cout << "\t\t------------------------------------------------\n";


   // running a loop to include all readme-type-files listed
   for( i_temp >= 0 ; i_temp <= (N_TYPES-1) ; i_temp++ )
   {
     if( fstream( readme_types[i_temp] , ios::in ) )
     {
       page_id++;
       readme_found = YES;
       script << readme_pg( page_id , readme_types[i_temp] );
     }
   }


   cout << "\t\t------------------------------------------------\n";



   // if no readme-type-file has been found, display a default
   if( readme_found == NO )
   {
     // DEFAULT PAGE
     page_id++;
     script << readme_def_pg( page_id );
   }




   // writes out the container
   page_id++;
   script << write_container( page_id );




   // writes out the confirmation dialog
   page_id++;
   script << write_confirmation( page_id );




   // writes out the closing tag
   script << "</BODY>\n</WARPIN>";
   script.close();




   // executes the wic.exe with required parameters
   adf_move( UP );
   wic_exec( archivename , basename, long_scriptname );
   adf_move( DOWN );




   // deletes the .wis-file
   del_file( long_scriptname );




   // cleanup the heap
   delete[] filename       ;
   delete[] scriptname     ;
   delete[] archivename    ;
   delete[] basename       ;
   delete[] long_scriptname;




   // hopefully. I have seen some access violations lately
   return 0;

}
