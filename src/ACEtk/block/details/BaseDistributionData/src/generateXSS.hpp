static std::vector< double >
generateXSS( const std::string& name,
             std::vector< long >&& boundaries,
             std::vector< long >&& interpolants,
             std::vector< Distribution >&& distributions,
             std::size_t locb ) {

  // add the distribution data to the xss array
  std::size_t nr = boundaries.size();
  std::size_t ne = distributions.size();
  std::vector< double > xss( 1 + 2 * ne );
  xss[0] = ne;
  std::size_t index = 1;
  std::size_t offset = 1 + 2 * nr + locb;
  for ( const auto& distribution : distributions ) {

    // set the energy value
    xss[index] = distribution.incidentEnergy();

    // set the locator
    xss[index + ne] = xss.size() + offset;

    // insert the xss array
    xss.insert( xss.end(), distribution.begin(), distribution.end() );

    // on to the next distribution
    ++index;
  }

  // insert the interpolation data in the front
  InterpolationData interpolation( std::string( name ),
                                   std::move( boundaries ),
                                   std::move( interpolants ) );
  xss.insert( xss.begin(), interpolation.begin(), interpolation.end() );

  return xss;
}
