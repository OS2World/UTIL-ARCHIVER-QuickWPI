void del_file( const char *_scriptname )
{

  unsigned short rc;


  if( fstream( _scriptname, ios::in ) )
  {

    // delete that file
    char *del_command = new char[30];
    strcpy( del_command , "del "      );
    strcat( del_command , _scriptname );
    strcat( del_command , " >NUL"     );
    rc = system( del_command          );
    delete[] del_command;

    if( rc != 0 )
    {

      cout << "Funny, i could not delete the " << _scriptname << endl;
      cout << "Something has gone wrong. Better check the archive!\n";

    }

  }

  else
  {

    cout << "Funny, i could not delete the " << _scriptname << endl;
    cout << "The file is not there!\n";

  }

}
