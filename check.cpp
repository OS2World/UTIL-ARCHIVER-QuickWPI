#ifndef _NO_
#define NO 0
#endif

#ifndef _YES_
#define YES 1
#endif


unsigned int chk_exe( const char *chk_filename )
{
  if( fstream( chk_filename, ios::in ) )
  {
    return YES;
  }
  else
  {
    return NO;
  }

}
