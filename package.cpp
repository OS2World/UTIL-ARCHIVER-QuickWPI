char *package( unsigned short pck_index,
               unsigned short pck_mode,
               const char *pck_basename,
               const char *pck_filename,
               unsigned short pck_object ) {


  char *buffer       = new char[1000];
  char *temp         = new char[35]  ;
  char *author       = new char[40]  ;
  char *version      = new char[5]   ;
  char *minor        = new char[5]   ;
  char *major        = new char[5]   ;
  char *pck_title    = new char[30]  ;
  char *pck_instpath = new char[255] ;

  unsigned short _version;
  unsigned short _major  ;
  unsigned short _minor  ;

  strcpy( pck_title, pck_basename );


  if( fstream( "quickwpi.qwp", ios::in ) )
  {
    fstream info( "quickwpi.qwp", ios::in );
    info.getline( author , 39 );
    info.getline( pck_title , 29 );
    info >> version;
    info >> major;
    info >> minor;
    info >> pck_instpath;
    info.close();
    pck_mode = 3;
    cout << "\n\t\t: Found archive definition file, using it.     :";
  }


  switch( pck_mode )
  {


    case 2 : // interactive mode

      cout <<   "\n\t- Author........: ";
      cin.getline( author , 39 );

      if( pck_object == 1 )
      {
        cout << "\t- Object Title....: ";
        cin.getline( pck_title , 29 );
      }

      cout <<   "\t- Default Path....: ";
      cin >> pck_instpath;

      cout << "\n\tPlease provide the version of the program. You will be asked";
      cout << "\n\tfor the version, major and minor revision number separately\n\n";

      cout << "\t- Version.........: ";
      cin  >> version;
      _version = atoi( version );

      cout << "\t- Major revision..: ";
      cin  >> major;
      _major = atoi( major );

      cout << "\t- Minor revision..: ";
      cin  >> minor;
      _minor = atoi( minor );

      break;

    case 3 :

      break;

    default :

      // this is the default
      strcpy( author  , "Author is unknown" );
      strcpy( pck_title , pck_basename      );
      strcpy( version , "1"                 );
      strcpy( major   , "0"                 );
      strcpy( minor   , "0"                 );
      strcpy( pck_instpath , "\\TOOLS\\"    );
      strcpy( pck_instpath , pck_title      );

  }




  // creating the output string
  strcpy( buffer , "<PCK INDEX=\"1\"\n      PACKAGEID=\"" );
  strcat( buffer ,  author                                );
  strcat( buffer , "\\"                                   );
  strcat( buffer , pck_basename                           );
  strcat( buffer , "\\"                                   );
  strcat( buffer , pck_basename                           );
  strcat( buffer , "\\"                                   );
  strcat( buffer , version                                );
  strcat( buffer ,  "\\"                                  );
  strcat( buffer , major                                  );
  strcat( buffer ,  "\\"                                  );
  strcat( buffer , minor                                  );
  strcat( buffer , "\"\n      TARGET=\"?:"                );
  strcat( buffer , pck_instpath                           );
  strcat( buffer ,  "\"\n      SELECT\n      TITLE=\""    );
  strcat( buffer , pck_title                              );
  strcat( buffer , "\"\n"                                 );


  // eventually create an object on the desktop
  if( pck_object == 1 )
  {
    cout << "\n\t\t: Found executable file, creating object       :" << endl;
    strcat( buffer , "      CREATEOBJECT=\"WPProgram|" );
    strcat( buffer , pck_title );
    strcat( buffer , "|<WP_DESKTOP>|EXENAME=$(1)\\" );
    strcat( buffer , pck_filename );
    strcat( buffer , ";OBJECTID=<" );
    strcat( buffer , pck_basename );
    strcat( buffer , ">;\"\n" );
    }
  else
  {
    cout << "\n\t\t: Missing .exe-file, no object will be created :" << endl;
    }

  strcat( buffer , "      >This package installs " );
  strcat( buffer , pck_basename );
  strcat( buffer , "</PCK>\n" );



  return buffer;

  delete[] buffer       ;
  delete[] temp         ;
  delete[] author       ;
  delete[] version      ;
  delete[] minor        ;
  delete[] major        ;
  delete[] pck_title    ;
  delete[] pck_instpath ;

}

