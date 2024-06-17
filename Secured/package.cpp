char *package( unsigned short pck_index,
               const char *pck_basename,
               const char *pck_filename,
               unsigned short pck_object ) {


  char buffer[1000];
  char temp[35];

  cout << "Creating tag for package " << pck_index << endl;
  strcpy( buffer , "<PCK INDEX=\"1\"\n      PACKAGEID=\"AUTHOR\\" );
  strcat( buffer , pck_basename );
  strcat( buffer , "\\" );
  strcat( buffer , pck_basename );
  strcat( buffer , "\\1\\0\\0\"\n      TARGET=\"?:\\Tools\\" );
  strcat( buffer , pck_basename );
  strcat( buffer ,  "\"      SELECT\n      TITLE=\"" );
  strcat( buffer , pck_basename );
  strcat( buffer , "\"\n" );

  if( pck_object == 1 )
  {
    cout << "- Found " << pck_filename << ", will create desktop object." << endl;
    strcat( buffer , "      CREATEOBJECT=\"WPProgram|" );
    strcat( buffer , pck_basename );
    strcat( buffer , "|<WP_DESKTOP>|EXENAME=$(1)\\" );
    strcat( buffer , pck_filename );
    strcat( buffer , ";OBJECTID=<" );
    strcat( buffer , pck_basename );
    strcat( buffer , ">;\"\n" );
    }
  else
  {
    cout << "- Missing .exe-file, no desktop object will be created." << endl;
    }

  strcat( buffer , "      >This package installs " );
  strcat( buffer , pck_basename );
  strcat( buffer , "</PCK>\n" );


  return buffer;

}

