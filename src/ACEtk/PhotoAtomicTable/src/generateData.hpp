Data generateData( std::vector< unsigned int > za, std::vector< double > awr,
                   block::ESZG&& eszg, block::JINC&& jinc,
                   block::JCOH&& jcoh, block::LHNM&& lhnm ) {

  std::array< int32_t, 16 > iz;
  std::array< double, 16 > aw;
  std::array< int64_t, 16 > nxs;
  std::array< int64_t, 32 > jxs;
  iz.fill( 0 );
  aw.fill( 0. );
  nxs.fill( 0 );
  jxs.fill( 0 );
  std::vector< double > xss;

  // assign za values
  for ( unsigned int i = 0; i < za.size(); ++i ) {

    iz[i] = za[i];
    aw[i] = awr[i];
  }

  // some size values
  unsigned int ne = eszg.NES();

  // verify some stuff:
  //  - same number of ZA and atomic mass values
  //  - ESZG and LHNM use the same numbeer of incident energy values
  if ( za.size() != awr.size() ) {

    Log::error( "Inconsistent number of ZA and atomic mass values" );
    Log::info( "Number of ZA values = {}", za.size() );
    Log::info( "Number of atomic mass values = {}", awr.size() );
    throw std::exception();
  }
  if ( ne != lhnm.NES() ) {

    Log::error( "Inconsistent NE between the different blocks" );
    Log::info( "ESZG NE value = {}", eszg.NES() );
    Log::info( "LHNM NE value = {}", lhnm.NES() );
    throw std::exception();
  }

  // generate the xss array and set the locators in the jxs array as we go
  jxs[0] = 1;
  xss.insert( xss.end(), eszg.begin(), eszg.end() );
  jxs[1] = xss.size() + 1;
  xss.insert( xss.end(), jinc.begin(), jinc.end() );
  jxs[2] = xss.size() + 1;
  xss.insert( xss.end(), jcoh.begin(), jcoh.end() );
  jxs[4] = xss.size() + 1;
  xss.insert( xss.end(), lhnm.begin(), lhnm.end() );

  // set the nxs values for the continuous energy table
  // NXS(1) = length
  // NXS(3) = NE
  nxs[0] = xss.size();
  nxs[2] = ne;

  return { std::move( iz ), std::move( aw ),
           std::move( nxs ), std::move( jxs ), std::move( xss ) };
}
