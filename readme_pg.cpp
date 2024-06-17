

char *readme_pg( unsigned short pg_id, const char *pg_file )
{

  unsigned short i;

  cout << "\t\t: Found " << pg_file << ",";

  for( i = strlen( pg_file ) ; i < 14 ; i++ ) { cout << " "; }

  cout << "including it on page " << pg_id << ". :\n";

  char *buffer = new char[1000];
  char *temp   = new char[35];


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

  delete[] buffer;
  delete[] temp;

}


char *readme_def_pg( unsigned short pg_id )
{

  char *buffer = new char[1000];
  char *temp   = new char[35];


  // create the complete XML stream
  strcpy( buffer , "<PAGE INDEX=\"" );
  strcat( buffer , _itoa( pg_id, temp , 10 ) );
  strcat( buffer , "\" TYPE=\"TEXT\">\n<NEXTBUTTON TARGET=\"" );
  strcat( buffer , _itoa( pg_id + 1, temp, 10 ) );
  strcat( buffer , "\">~Next</NEXTBUTTON>\n<TEXT>\nImportant information\n\n" );
  strcat( buffer , "This package is generated automatically by \n" );
  strcat( buffer , "J”rg Skottke's Quick-WPI.\n\n" );
  strcat( buffer , "Since a \"README\"-type file has not been found\n" );
  strcat( buffer , "during archive creation, you are strongly encouraged\n" );
  strcat( buffer , "to look into the installation directory to find\n" );
  strcat( buffer , "information about the product you are about to install.\n\n" );
  strcat( buffer , "Select \"Next\" to continue\n" ) ;
  strcat( buffer , "Select \"Cancel\" to abort installation</TEXT>\n</PAGE>\n" );

  return buffer;

  delete[] buffer;
  delete[] temp;

}


char *readme_init_pg( unsigned short pg_id, const char *pck_base )
{

  char *buffer = new char[1000];
  char *temp   = new char[35];


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

  delete[] buffer;
  delete[] temp;

}

