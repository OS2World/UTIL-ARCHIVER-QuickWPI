// just creates a filename and returns it
void mk_filename( char *_file,
                  const char *name,
                  const char *suffix )
{

  char *buffer = new char[13];

  strcpy( buffer , name );
  strcat( buffer , "." );
  strcat( buffer , suffix );

  strcpy( _file , buffer );

  delete[] buffer;

}
