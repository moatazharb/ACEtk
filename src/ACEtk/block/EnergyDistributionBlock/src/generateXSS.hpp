static std::vector< double >
generateXSS( std::vector< DistributionData >&& distributions ) {

  std::size_t size = distributions.size();
  std::vector< double > xss( size );
  std::size_t index = 0;
  for ( auto&& distribution : distributions ) {

    // set the locator
    std::size_t offset = xss.size() - size + 1;
    xss[index] = offset;

    // multi-law data needs no dummy probabilities
    if ( std::holds_alternative< MultiDistributionData >( distribution ) ) {

      std::visit(

        utility::overload{

          [ &xss, offset ] ( const MultiDistributionData& value ) {

            // remake the internal xss array with the proper locators
            MultiDistributionData temp(
                std::move( value.probabilities() ),
                std::move( value.distributions() ),
                offset );
            xss.insert( xss.end(), temp.begin(), temp.end() );
          },
          [] ( const auto& ) { /* nothing to do here */ }
        },
        distribution
      );
    }
    else {

      // generate the xss array for this distribution
      std::size_t idat = 0;
      std::visit(

        utility::overload{

          [] ( const MultiDistributionData& ) { /* nothing to do here */ },         
          [ &xss, &idat, offset ] ( const auto& value ) {

            idat = offset + 3 + 1 + 5;
            xss.push_back( 0 );                                    // LNW
            xss.push_back( static_cast< short >( value.LAW() ) );  // LAW
            xss.push_back( idat );                                 // IDAT
            xss.push_back( 0 );                                    // NR
            xss.push_back( 2 );                                    // NE
            xss.push_back( value.minimumIncidentEnergy() );        // E[0]
            xss.push_back( value.maximumIncidentEnergy() );        // E[1]
            xss.push_back( 1. );                                   // P[0]
            xss.push_back( 1. );                                   // P[1]
          }
        },
        distribution
      );
      std::visit(

        utility::overload{

          [ &xss, idat ] ( const OutgoingEnergyDistributionData& value ) {

            // remake the internal xss array with the proper locators
            decltype(auto) boundaries = value.boundaries();
            decltype(auto) interpolants = value.interpolants();
            OutgoingEnergyDistributionData temp(
                { boundaries.begin(), boundaries.end() },
                { interpolants.begin(), interpolants.end() },
                std::move( value.distributions() ),
                idat );
            xss.insert( xss.end(), temp.begin(), temp.end() );
          },
          [ &xss, idat ] ( const KalbachMannDistributionData& value ) {

            // remake the internal xss array with the proper locators
            decltype(auto) boundaries = value.boundaries();
            decltype(auto) interpolants = value.interpolants();
            KalbachMannDistributionData temp(
                { boundaries.begin(), boundaries.end() },
                { interpolants.begin(), interpolants.end() },
                std::move( value.distributions() ),
                idat );
            xss.insert( xss.end(), temp.begin(), temp.end() );
          },
          [ &xss ] ( const auto& value ) {

            xss.insert( xss.end(), value.begin(), value.end() );
          }
        },
        distribution
      );
    }

    ++index;
  }

  return xss;
}
