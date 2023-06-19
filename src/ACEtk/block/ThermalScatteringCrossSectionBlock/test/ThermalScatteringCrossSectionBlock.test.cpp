#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ACEtk/block/ThermalScatteringCrossSectionBlock.hpp"

// other includes

// convenience typedefs
using namespace njoy::ACEtk;
using ThermalScatteringCrossSectionBlock = block::ThermalScatteringCrossSectionBlock;

std::vector< double > chunk();
void verifyChunk( const ThermalScatteringCrossSectionBlock& );

SCENARIO( "ThermalScatteringCrossSectionBlock" ) {

  GIVEN( "valid data for a ThermalScatteringCrossSectionBlock instance" ) {

    std::vector< double > xss = chunk();

    WHEN( "the data is given explicitly" ) {

      std::vector< double > energies = { 10., 20., 30., 40. };
      std::vector< double > xs = { 1., 2., 3., 4. };

      ThermalScatteringCrossSectionBlock chunk( std::move( energies ),
                                                  std::move( xs ) );

      THEN( "a ThermalScatteringCrossSectionBlock can be constructed and "
            "members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "the XSS array is correct" ) {

        auto xss_chunk = chunk.XSS();
        for ( unsigned int i = 0; i < chunk.length(); ++i ) {

          CHECK( xss[i] == Approx( xss_chunk[i] ) );
        }
      } // THEN
    } // WHEN

    WHEN( "the data is defined by iterators" ) {

      ThermalScatteringCrossSectionBlock chunk( xss.begin(), xss.end() );

      THEN( "a ThermalScatteringCrossSectionBlock can be constructed and "
            "members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "the XSS array is correct" ) {

        auto xss_chunk = chunk.XSS();
        for ( unsigned int i = 0; i < chunk.length(); ++i ) {

          CHECK( xss[i] == Approx( xss_chunk[i] ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

std::vector< double > chunk() {

  return {

                     4,  1.00000000000E+01,  2.00000000000E+01,  3.00000000000E+01,
     4.00000000000E+01,  1.00000000000E+00,  2.00000000000E+00,  3.00000000000E+00,
     4.00000000000E+00
  };
}

void verifyChunk( const ThermalScatteringCrossSectionBlock& chunk ) {

  CHECK( false == chunk.empty() );
  CHECK( 9 == chunk.length() );
  CHECK( "ThermalScatteringCrossSectionBlock" == chunk.name() );

  CHECK( 4 == chunk.NE() );
  CHECK( 4 == chunk.numberIncidentEnergies() );

  CHECK( 4 == chunk.energies().size() );
  CHECK( 10. == Approx( chunk.energies().front() ) );
  CHECK( 40. == Approx( chunk.energies().back() ) );

  CHECK( 4 == chunk.crossSections().size() );
  CHECK( 1. == Approx( chunk.crossSections().front() ) );
  CHECK( 4. == Approx( chunk.crossSections().back() ) );
}
