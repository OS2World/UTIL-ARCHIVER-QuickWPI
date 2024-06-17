// writes out the section of the code that generates the container
char *write_container( unsigned short pg_id )
{

  char buffer[1000];
  char dummy[35];

  strcpy( buffer , "<PAGE INDEX=\""                                 );
  strcat( buffer ,  _itoa( pg_id , dummy , 10 )                     );
  strcat( buffer ,  "\" TYPE=\"CONTAINER\">\n<NEXTBUTTON TARGET=\"" );
  strcat( buffer ,  _itoa( pg_id+1 , dummy , 10 )                   );
  strcat( buffer , "\">~Next</NEXTBUTTON>\n<TEXT>\n"                );
  strcat( buffer ,"You can remove the package by deselecting it, "  );
  strcat( buffer ,"else just press \"Next\" to go on</TEXT>\n"      );
  strcat( buffer ,"</PAGE>\n"                                       );

  return buffer;

}

// writes out the last confirmation dialog.
char *write_confirmation( unsigned short pg_id )
{

  char buffer[1000];
  char dummy[35];

  strcpy( buffer , "<PAGE INDEX=\""                                             );
  strcat( buffer ,  _itoa( pg_id , dummy , 10 )                                 );
  strcat( buffer ,"\" TYPE=\"TEXT\">\n"                                         );
  strcat( buffer ,"<NEXTBUTTON TARGET=\"0\">I~nstall</NEXTBUTTON>\n<TEXT>\n"    );
  strcat( buffer ,"Press \"Install\" to begin installing this archive.</TEXT>\n");
  strcat( buffer ,"</PAGE>\n"                                                   );


  return buffer;

}

void usage()
{

  cout << "\n\nPlease provide the EXE-filename without extension.\n\n";
  cout << "  Example: qwpi NewView\n\n";
  cout << "When the parameter \"-i\" is specified, some more information\n";
  cout << "to the package can be entered.\n\n  Example: qwpi NewView -i\n\n";
  exit(1);

}
