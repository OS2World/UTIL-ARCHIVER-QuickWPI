void adf_move( const unsigned short option )
{

  unsigned short rc;

  if( option == 1 )
  {

    rc = system( "move quickwpi.qwp .. >NUL" );

  }

  else
  {

    rc = system( "move ..\\quickwpi.qwp . >NUL" );

  }

}

