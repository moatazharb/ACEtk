EnergyDependentWattSpectrum() = default;

EnergyDependentWattSpectrum( const EnergyDependentWattSpectrum& base ) :
  Base( base ) {

  this->generateBlocks();
}

EnergyDependentWattSpectrum( EnergyDependentWattSpectrum&& base ) :
  Base( std::move( base ) ) {

  this->generateBlocks();
}

/**
 *  @brief Constructor
 *
 *  @param[in] a         the data for the a parameter
 *  @param[in] b         the data for the b parameter
 *  @param[in] energy    the restriction energy
 */
EnergyDependentWattSpectrum(
    ParameterData a,
    ParameterData b,
    double energy ) :
  Base( "DLW::EnergyDependentWattSpectrum",
        generateXSS( std::move( a ), std::move( b ), energy ) ) {

  this->generateBlocks();
}

/**
 *  @brief Constructor
 *
 *  @param[in] name     the name of the block
 *  @param[in] type     the energy distribution type
 *  @param[in] begin    the begin iterator of the block in the XSS array
 *  @param[in] end      the end iterator of the block in the XSS array
 */
EnergyDependentWattSpectrum( Iterator begin, Iterator end ) :
  Base( "DLW::EnergyDependentWattSpectrum", begin, end ) {

  std::size_t nra = static_cast< std::size_t >( this->XSS( 1 ) );
  std::size_t nea = static_cast< std::size_t >( this->XSS( 1 + 2 * nra + 1 ) );
  std::size_t size = 2 + 2 * nra + 2 * nea;
  std::size_t nrb = static_cast< std::size_t >( this->XSS( size + 1 ) );
  std::size_t neb = static_cast< std::size_t >( this->XSS( size + 1 + 2 * nrb + 1 ) );
  verifySize( this->begin(), this->end(), nra, nea, nrb, neb );
  this->generateBlocks();
}

EnergyDependentWattSpectrum& operator=( const EnergyDependentWattSpectrum& base ) {

  new (this) EnergyDependentWattSpectrum( base );
  return *this;
}

EnergyDependentWattSpectrum& operator=( EnergyDependentWattSpectrum&& base ) {

  new (this) EnergyDependentWattSpectrum( std::move( base ) );
  return *this;
}
