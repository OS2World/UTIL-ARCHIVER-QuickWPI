
// quite dirty - just checks if something is there and that's all ...
// i've got to figure out how this is really done.
unsigned short chk_arg( const char *arg )
{

  if( strcmp( arg , "-i" ) != 0 )
  {
     return 2;
  }


  if( strcmp( arg , "-I" ) != 0 )
  {
     return 2;
  }

  return 0;

}

