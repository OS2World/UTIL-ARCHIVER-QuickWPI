#include <fstream.h>
#include <stdlib.h>
//#include <string.h>

#include "readme_pg.cpp"
#include "package.cpp"
#include "check.cpp"

#define N_TYPES 10
#define YES 1
#define NO 0

int main( int argc, char **argv )
{

   char filename[13];
   char scriptname[13];
   char archivename[13];
   char basename[9];
   unsigned short createObject;
   unsigned short page_id = 1;

   unsigned short i_temp, readme_found = NO;

   char readme_types[N_TYPES][13] = { "README" ,
                                      "LIESMICH",
                                      "README.TXT",
                                      "LIESMICH.TXT",
                                      "README.ENG",
                                      "README.GER",
                                      "FILE_ID.DIZ",
                                      "HISTORY",
                                      "CHANGES.TXT",
                                      "CHANGELOG" };


   if( argc == 2 )
   {

     cout << "\nQuick-WPI 0.11 (C) 2001 J”rg Skottke" << endl;

     strncpy( basename , argv[1] , 8 );
     cout << "Basename...: " << basename << endl;

     strcpy( filename , basename );
     strcat( filename , ".exe" );

     strcpy( scriptname , basename );
     strcat( scriptname , ".wis" );
     cout << "Scriptname.: " << scriptname << endl;

     strcpy( archivename , basename );
     strcat( archivename , ".wpi" );
     cout << "Archive....: " << archivename << endl;

     fstream script( scriptname , ios::out );

     // this creates the package
     script << "<WARPIN>\n";
       script << "<HEAD>\n";
       script << package( 1 , basename , filename , chk_exe( filename ) );
     script << "</HEAD>\n";

       // Script information

     script << "<BODY>\n";
       script << readme_init_pg( page_id, basename );

       for( i_temp >= 0 ; i_temp <= 9 ; i_temp++ )
       {
         if( fstream( readme_types[i_temp] , ios::in ) )
         {
           page_id++;
           readme_found = YES;
           script << readme_pg( page_id , readme_types[i_temp] );
         }
       }

       if( readme_found )
       {
         // DEFAULT PAGE
         page_id++;
         script << readme_def_pg( page_id );
       }

       page_id++;
       script << "<PAGE INDEX=\"" << page_id << "\" TYPE=\"CONTAINER\">\n";
       script << "<NEXTBUTTON TARGET=\"" << page_id+1 <<"\">~Next</NEXTBUTTON>\n";
       script << "<TEXT>\n";
       script << "You can remove the package by deselecting it, else just press \"Next\" to go on</TEXT>\n";
       script << "</PAGE>\n";

       page_id++;
       script << "<PAGE INDEX=\"" << page_id << "\" TYPE=\"TEXT\">\n";
       script << "<NEXTBUTTON TARGET=\"0\">I~nstall</NEXTBUTTON>\n";
       script << "<TEXT>\n";
       script << "Press \"Install\" to begin installing this archive.</TEXT>\n";
       script << "</PAGE>\n";

     script << "</BODY>\n";

       script << "</WARPIN>";

     script.close();


// this out!
     int rc;
     char cmdline[50];

     strcpy( cmdline , "wic " );
     strcat( cmdline , "-a " );
     strcat( cmdline , archivename );
     strcat( cmdline , " 1 " );
     strcat( cmdline , basename );
     strcat( cmdline , " -r *" );
     strcat( cmdline , " -s " );
     strcat( cmdline , scriptname );
     strcat( cmdline , " >NUL" );

     cout << "Running WIC.EXE" << endl;
     //cout << "Trying to run: " << cmdline << endl;

     rc = system( cmdline );

     if( rc == 0 )
     {
       cout << "\nTask completed successfully." << endl;
     }
     else if( rc == 65535 )
     {
       cout << "\nWIC failed: QWPI in current directory. RTFM!" << endl;
     }
     else
     {
       cout << "\nAn error occurred. rc = " << rc << endl;
     }

   }
   else
   {
     cout << "Please provide the EXE-filename without extension.\n\n";
     cout << " Example: qwpi NewView\n\n";
     return 1;
     exit(1);
   }



   return 0;

}
