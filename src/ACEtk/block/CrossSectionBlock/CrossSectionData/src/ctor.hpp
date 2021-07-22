CrossSectionData() = default;

CrossSectionData( const CrossSectionData& ) = default;
CrossSectionData( CrossSectionData&& ) = default;

/**
 *  @brief Constructor
 *
 *  @param[in] index     the energy index
 *  @param[in] values    the cross section values
 */
CrossSectionData( std::size_t index, std::vector< double >&& values ) :
  Base( "SIG::XS", generateXSS( index, std::move( values ) ) ) {}

/**
 *  @brief Constructor
 *
 *  @param[in] begin    the begin iterator of the cross section data
 *  @param[in] end      the end iterator of the cross section data
 */
 CrossSectionData( Iterator begin, Iterator end ) :
   Base( "SIG::XS", begin, end ) {}

CrossSectionData& operator=( const CrossSectionData& ) = default;
CrossSectionData& operator=( CrossSectionData&& ) = default;
