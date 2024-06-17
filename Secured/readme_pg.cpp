

char *readme_pg( unsigned short pg_id, const char *pg_file )
{

  cout << "- Found " << pg_file << ", including it on page " << pg_id << ".\n";

  char buffer[1000];
  char temp[35];


  // create the complete XML stream
  strcpy( buffer , "<PAGE INDEX=\"" );
  strcat( buffer , _itoa( pg_id, temp, 10 ) );
  strcat( buffer , "\" TYPE=\"README\">\n<NEXTBUTTON TARGET=\"" );
  strcat( buffer , _itoa( pg_id + 1, temp , 10 ) );
  strcat( buffer , "\">~Next</NEXTBUTTON>\n<README EXTRACTFROMPCK=\"1\">" );
  strcat( buffer , pg_file );
  strcat( buffer , "</README>\n<TEXT>\nSelect \"Next\" to continue.\n" );
  strcat( buffer , "Select \"Cancel\" to abort installation.</TEXT>\n</PAGE>\n" );

  return buffer;

}


char *readme_def_pg( unsigned short pg_id )
{

  char buffer[1000];
  char temp[35];

  // create the complete XML stream
  strcpy( buffer , "<PAGE INDEX=\"" );
  strcat( buffer , _itoa( pg_id, temp , 10 ) );
  strcat( buffer , "\" TYPE=\"TEXT\">\n<NEXTBUTTON TARGET=\"" );
  strcat( buffer , _itoa( pg_id + 1, temp, 10 ) );
  strcat( buffer , "\">~Next</NEXTBUTTON>\n<TEXT>\nImportant information\n\n" );
  strcat( buffer , "This package is generated automatically by QWPI\n\n" );
  strcat( buffer , "Since the file \"README\" has not been found\n" );
  strcat( buffer , "during archive creation, you are strongly encouraged\n" );
  strcat( buffer , "to look into the installation directory to find\n" );
  strcat( buffer , "information about the product you are about to install.\n\n" );
  strcat( buffer , "Select \"Next\" to continue\n" ) ;
  strcat( buffer , "Select \"Cancel\" to abort installation</TEXT>\n</PAGE>\n" );

  return buffer;

}


char *readme_init_pg( unsigned short pg_id, const char *pck_base )
{

  char buffer[1000];
  char temp[35];

  // create the complete XML stream
  strcpy( buffer , "<PAGE INDEX=\"" );
  strcat( buffer , _itoa( pg_id, temp, 10 ) );
  strcat( buffer , "\" TYPE=\"TEXT\">\n<NEXTBUTTON TARGET=\"" );
  strcat( buffer , _itoa( pg_id + 1, temp, 10 ) );
  strcat( buffer , "\">~Next</NEXTBUTTON>\n<TEXT>\nWelcome!\n\n" );
  strcat( buffer , "This package installs " );
  strcat( buffer , pck_base );
  strcat( buffer , " on your system\n\nSelect \"Next\" to continue\n" );
  strcat( buffer , "Select \"Cancel\" to abort installation</TEXT>\n</PAGE>\n" );

  return buffer;

}


/*
       if( fstream(  , ios::in ) )
       {
         page_id++;
         next_id++;
         cout << "- Found README.TXT, including it." << endl;
         script << "<PAGE INDEX=\"" << page_id << "\" TYPE=\"README\">\n";
         script << "<NEXTBUTTON TARGET=\"" << next_id <<"\">~Next</NEXTBUTTON>\n";
         script << "<README EXTRACTFROMPCK=\"1\">README.TXT</README>\n";
         script << "<TEXT>\n";
         script << "Select \"Next\" to continue.\n";
         script << "Select \"Cancel\" to abort installation.</TEXT>\n";
         script << "</PAGE>\n";
       }

       if( fstream( "FILE_ID.DIZ" , ios::in ) )
       {
         page_id++;
         next_id++;
         cout << "- Found FILE_ID.DIZ, including it" << endl;
         script << "<PAGE INDEX=\"" << page_id << "\" TYPE=\"README\">\n";
         script << "<NEXTBUTTON TARGET=\"" << next_id <<"\">~Next</NEXTBUTTON>\n";
         script << "<README EXTRACTFROMPCK=\"1\">FILE_ID.DIZ</README>\n";
         script << "<TEXT>\n";
         script << "Select \"Next\" to continue.\n";
         script << "Select \"Cancel\" to abort installation.</TEXT>\n";
         script << "</PAGE>\n";
       }
*/

