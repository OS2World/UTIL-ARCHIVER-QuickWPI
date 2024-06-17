void wic_exec( const char *_arc, const char *_base, const char *_script )
{

  int rc;
  char *cmdline = new char[50];



  // creating the commandline for wic.exe
  strcpy( cmdline , "wic "   );
  strcat( cmdline , "-a "    );
  strcat( cmdline , _arc     );
  strcat( cmdline , " 1 "    );
  strcat( cmdline , _base    );
  strcat( cmdline , " -r *"  );
  strcat( cmdline , " -s "   );
  strcat( cmdline , _script  );
  strcat( cmdline , " >NUL"  );

  cout << "\n\t\tRunning WIC.EXE" << endl;

  rc = system( cmdline );

  delete[] cmdline;

  switch( rc )
  {

  case 0 :

    cout << "\n\t\tTask completed successfully." << endl;
    break;

  case 2 :

    cout << "\nA command line parameter was not provided or incorrect.";
    cout << "\nCancelling this step. Please verify the parameters: \n\n";
    cout << "  The command was: " << cmdline << endl;

    break;

  case 65535 :

    cout << "\n** WIC failed, there are open files in this directory **\n" << endl;
    break;


  cout << "\n** An unknown error occurred. rc = " << rc << " **\n";
  break;

  }

}
