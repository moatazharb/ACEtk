#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ACEtk/block/PrincipalCrossSectionBlock.hpp"

// other includes

// convenience typedefs
using namespace njoy::ACEtk;
using PrincipalCrossSectionBlock = block::PrincipalCrossSectionBlock;

std::vector< double > chunk();
void verifyChunk( const PrincipalCrossSectionBlock& );

SCENARIO( "PrincipalCrossSectionBlock" ) {

  GIVEN( "valid data for a PrincipalCrossSectionBlock instance" ) {

    std::vector< double > xss = chunk();

    WHEN( "the data is given explicitly" ) {

      std::vector< double > energies = {

        1.00000000000E-11, 2.00000000000E-11, 5.00000000000E-11, 1.00000000000E-10,
        2.00000000000E-10, 5.00000000000E-10, 1.00000000000E-09, 2.00000000000E-09,
        5.00000000000E-09, 1.00000000000E-08, 2.00000000000E-08, 2.53000000000E-08,
        5.00000000000E-08, 1.00000000000E-07, 2.00000000000E-07, 5.00000000000E-07,
        1.00000000000E-06, 2.00000000000E-06, 5.00000000000E-06, 1.00000000000E-05,
        2.00000000000E-05, 5.00000000000E-05, 1.00000000000E-04, 2.00000000000E-04,
        5.00000000000E-04, 1.00000000000E-03, 2.00000000000E-03, 4.00000000000E-03,
        5.00000000000E-03, 6.00000000000E-03, 8.00000000000E-03, 1.00000000000E-02,
        1.50000000000E-02, 2.00000000000E-02, 4.00000000000E-02, 5.00000000000E-02,
        6.00000000000E-02, 8.00000000000E-02, 1.00000000000E-01, 1.50000000000E-01,
        2.00000000000E-01, 3.00000000000E-01, 4.00000000000E-01, 5.00000000000E-01,
        6.00000000000E-01, 7.00000000000E-01, 8.00000000000E-01, 9.00000000000E-01,
        1.00000000000E+00, 1.20000000000E+00, 1.40000000000E+00, 1.60000000000E+00,
        1.80000000000E+00, 2.00000000000E+00, 2.20000000000E+00, 2.40000000000E+00,
        2.60000000000E+00, 2.80000000000E+00, 3.00000000000E+00, 3.20000000000E+00,
        3.40000000000E+00, 3.60000000000E+00, 3.80000000000E+00, 4.00000000000E+00,
        4.20000000000E+00, 4.40000000000E+00, 4.60000000000E+00, 4.80000000000E+00,
        5.00000000000E+00, 5.50000000000E+00, 6.00000000000E+00, 6.50000000000E+00,
        7.00000000000E+00, 7.50000000000E+00, 8.00000000000E+00, 8.50000000000E+00,
        9.00000000000E+00, 9.50000000000E+00, 1.00000000000E+01, 1.05000000000E+01,
        1.10000000000E+01, 1.15000000000E+01, 1.20000000000E+01, 1.25000000000E+01,
        1.30000000000E+01, 1.35000000000E+01, 1.40000000000E+01, 1.45000000000E+01,
        1.50000000000E+01, 1.55000000000E+01, 1.60000000000E+01, 1.65000000000E+01,
        1.70000000000E+01, 1.75000000000E+01, 1.80000000000E+01, 1.85000000000E+01,
        1.90000000000E+01, 1.95000000000E+01, 2.00000000000E+01
      };
      std::vector< double > total = {

                                                                 1.17771501000E+03,
        8.32878160000E+02, 5.26963255000E+02, 3.72860705000E+02, 2.63993524000E+02,
        1.67610483000E+02, 1.19277715000E+02, 8.54096130000E+01, 5.60122893000E+01,
        4.18877751000E+01, 3.26778146000E+01, 3.04231461000E+01, 2.57923581000E+01,
        2.31941021000E+01, 2.18532558000E+01, 2.10313719000E+01, 2.07491966000E+01,
        2.06037794000E+01, 2.05115346000E+01, 2.04777658000E+01, 2.04585030000E+01,
        2.04422859000E+01, 2.04307615000E+01, 2.04144624000E+01, 2.03721297000E+01,
        2.03046009000E+01, 2.01723458000E+01, 1.99144127000E+01, 1.97892313000E+01,
        1.96641245000E+01, 1.94210094000E+01, 1.91847439000E+01, 1.86220408000E+01,
        1.80961984000E+01, 1.62960783000E+01, 1.55815917000E+01, 1.48677251000E+01,
        1.37062041000E+01, 1.27427238000E+01, 1.09238445000E+01, 9.64358528000E+00,
        7.95229561000E+00, 6.87663428000E+00, 6.12560229000E+00, 5.56699890000E+00,
        5.13210634000E+00, 4.78165124000E+00, 4.49154240000E+00, 4.24618070000E+00,
        3.85053146000E+00, 3.54181422000E+00, 3.29137287000E+00, 3.08224139000E+00,
        2.90369677000E+00, 2.74859202000E+00, 2.61196516000E+00, 2.49024321000E+00,
        2.38078120000E+00, 2.28156513000E+00, 2.19103601000E+00, 2.10795886000E+00,
        2.03134269000E+00, 1.96037450000E+00, 1.89438931000E+00, 1.83282710000E+00,
        1.77521589000E+00, 1.72115668000E+00, 1.67030247000E+00, 1.62235727000E+00,
        1.51359377000E+00, 1.41819631000E+00, 1.33374287000E+00, 1.25840048000E+00,
        1.19073011000E+00, 1.12959677000E+00, 1.07408446000E+00, 1.02344716000E+00,
        9.77066588000E-01, 9.34429025000E-01, 8.95099875000E-01, 8.58710735000E-01,
        8.24946302000E-01, 7.93535076000E-01, 7.64241754000E-01, 7.36861535000E-01,
        7.11214819000E-01, 6.87143905000E-01, 6.64509492000E-01, 6.43187979000E-01,
        6.23069267000E-01, 6.04055154000E-01, 5.86057740000E-01, 5.68997726000E-01,
        5.52804011000E-01, 5.37412095000E-01, 5.22763779000E-01, 5.08805961000E-01,
        4.95490443000E-01, 4.82773424000E-01
      };
      std::vector< double > disappearance = {

                                              1.71740100000E+01, 1.21438600000E+01,
        7.68045500000E+00, 5.43090500000E+00, 3.84022400000E+00, 2.42878300000E+00,
        1.71741500000E+00, 1.21440300000E+00, 7.68079300000E-01, 5.43155100000E-01,
        3.84154600000E-01, 3.41606100000E-01, 2.43218100000E-01, 1.72502100000E-01,
        1.23265800000E-01, 7.76319400000E-02, 5.42665800000E-02, 3.83593600000E-02,
        2.41345500000E-02, 1.69157900000E-02, 1.19330400000E-02, 7.52588100000E-03,
        5.30147700000E-03, 3.74241900000E-03, 2.35974500000E-03, 1.66085400000E-03,
        1.16578800000E-03, 8.12732500000E-04, 7.21302100000E-04, 6.54483800000E-04,
        5.59372400000E-04, 4.93876600000E-04, 3.90771200000E-04, 3.28387200000E-04,
        2.08326100000E-04, 1.81663500000E-04, 1.55085200000E-04, 1.24126000000E-04,
        1.03786200000E-04, 7.45175200000E-05, 5.92842800000E-05, 4.46076700000E-05,
        3.82766600000E-05, 3.52914400000E-05, 3.38996200000E-05, 3.33423900000E-05,
        3.32443400000E-05, 3.34022300000E-05, 3.36990500000E-05, 3.44554600000E-05,
        3.52169900000E-05, 3.58729500000E-05, 3.63894900000E-05, 3.67662300000E-05,
        3.70168600000E-05, 3.71598700000E-05, 3.72143000000E-05, 3.71976900000E-05,
        3.71253600000E-05, 3.70102000000E-05, 3.68628700000E-05, 3.66920200000E-05,
        3.65045600000E-05, 3.63059900000E-05, 3.61006300000E-05, 3.58918300000E-05,
        3.56821800000E-05, 3.54736400000E-05, 3.52677000000E-05, 3.47705000000E-05,
        3.43050800000E-05, 3.38741800000E-05, 3.34769900000E-05, 3.31108400000E-05,
        3.27723300000E-05, 3.24578800000E-05, 3.21640000000E-05, 3.18874900000E-05,
        3.16254500000E-05, 3.13753100000E-05, 3.11348500000E-05, 3.09021400000E-05,
        3.06755200000E-05, 3.04536000000E-05, 3.02351800000E-05, 3.00192800000E-05,
        2.98050700000E-05, 2.95919000000E-05, 2.93792000000E-05, 2.91665600000E-05,
        2.89536300000E-05, 2.87401800000E-05, 2.85260300000E-05, 2.83110700000E-05,
        2.80952300000E-05, 2.78785100000E-05, 2.76609500000E-05, 2.74425900000E-05,
        2.72235400000E-05
      };
      std::vector< double > elastic = {

                           1.16054100000E+03, 8.20734300000E+02, 5.19282800000E+02,
        3.67429800000E+02, 2.60153300000E+02, 1.65181700000E+02, 1.17560300000E+02,
        8.41952100000E+01, 5.52442100000E+01, 4.13446200000E+01, 3.22936600000E+01,
        3.00815400000E+01, 2.55491400000E+01, 2.30216000000E+01, 2.17299900000E+01,
        2.09537400000E+01, 2.06949300000E+01, 2.05654200000E+01, 2.04874000000E+01,
        2.04608500000E+01, 2.04465700000E+01, 2.04347600000E+01, 2.04254600000E+01,
        2.04107200000E+01, 2.03697700000E+01, 2.03029400000E+01, 2.01711800000E+01,
        1.99136000000E+01, 1.97885100000E+01, 1.96634700000E+01, 1.94204500000E+01,
        1.91842500000E+01, 1.86216500000E+01, 1.80958700000E+01, 1.62958700000E+01,
        1.55814100000E+01, 1.48675700000E+01, 1.37060800000E+01, 1.27426200000E+01,
        1.09237700000E+01, 9.64352600000E+00, 7.95225100000E+00, 6.87659600000E+00,
        6.12556700000E+00, 5.56696500000E+00, 5.13207300000E+00, 4.78161800000E+00,
        4.49150900000E+00, 4.24614700000E+00, 3.85049700000E+00, 3.54177900000E+00,
        3.29133700000E+00, 3.08220500000E+00, 2.90366000000E+00, 2.74855500000E+00,
        2.61192800000E+00, 2.49020600000E+00, 2.38074400000E+00, 2.28152800000E+00,
        2.19099900000E+00, 2.10792200000E+00, 2.03130600000E+00, 1.96033800000E+00,
        1.89435300000E+00, 1.83279100000E+00, 1.77518000000E+00, 1.72112100000E+00,
        1.67026700000E+00, 1.62232200000E+00, 1.51355900000E+00, 1.41816200000E+00,
        1.33370900000E+00, 1.25836700000E+00, 1.19069700000E+00, 1.12956400000E+00,
        1.07405200000E+00, 1.02341500000E+00, 9.77034700000E-01, 9.34397400000E-01,
        8.95068500000E-01, 8.58679600000E-01, 8.24915400000E-01, 7.93504400000E-01,
        7.64211300000E-01, 7.36831300000E-01, 7.11184800000E-01, 6.87114100000E-01,
        6.64479900000E-01, 6.43158600000E-01, 6.23040100000E-01, 6.04026200000E-01,
        5.86029000000E-01, 5.68969200000E-01, 5.52775700000E-01, 5.37384000000E-01,
        5.22735900000E-01, 5.08778300000E-01, 4.95463000000E-01, 4.82746200000E-01
      };
      std::vector< double > heating = {

        1.91876400000E-05, 1.91851600000E-05, 1.91777300000E-05, 1.91653500000E-05,
        1.91406000000E-05, 1.90670400000E-05, 1.89460000000E-05, 1.87098000000E-05,
        1.80456600000E-05, 1.70668700000E-05, 1.54783100000E-05, 1.47871100000E-05,
        1.24328000000E-05, 9.83603500000E-06, 7.52192300000E-06, 5.10694200000E-06,
        3.94128900000E-06, 3.44970900000E-06, 4.04821500000E-06, 6.08692400000E-06,
        1.07674800000E-05, 2.54844200000E-05, 5.03414400000E-05, 1.00241200000E-04,
        2.50152600000E-04, 5.00108300000E-04, 1.00007900000E-03, 2.00006600000E-03,
        2.50006700000E-03, 3.00007200000E-03, 4.00008800000E-03, 5.00011200000E-03,
        7.50020400000E-03, 1.00003300000E-02, 2.00012200000E-02, 2.50018600000E-02,
        3.00026400000E-02, 4.00045600000E-02, 5.00069200000E-02, 7.50145900000E-02,
        1.00024400000E-01, 1.50049400000E-01, 2.00080000000E-01, 2.50115500000E-01,
        3.00155600000E-01, 3.50200500000E-01, 4.00250200000E-01, 4.50305400000E-01,
        5.00366600000E-01, 6.00508500000E-01, 7.00681000000E-01, 8.00888300000E-01,
        9.01134500000E-01, 1.00142400000E+00, 1.10175900000E+00, 1.20214500000E+00,
        1.30258200000E+00, 1.40307400000E+00, 1.50362400000E+00, 1.60423100000E+00,
        1.70489800000E+00, 1.80562500000E+00, 1.90641400000E+00, 2.00726500000E+00,
        2.10817800000E+00, 2.20915400000E+00, 2.31019100000E+00, 2.41129100000E+00,
        2.51245200000E+00, 2.76561900000E+00, 3.01915100000E+00, 3.27303000000E+00,
        3.52723200000E+00, 3.78173100000E+00, 4.03650100000E+00, 4.29150900000E+00,
        4.54672500000E+00, 4.80211900000E+00, 5.05765800000E+00, 5.31330900000E+00,
        5.56904300000E+00, 5.82482900000E+00, 6.08063700000E+00, 6.33644100000E+00,
        6.59221500000E+00, 6.84793700000E+00, 7.10358200000E+00, 7.35913200000E+00,
        7.61457000000E+00, 7.86988300000E+00, 8.12505600000E+00, 8.38008000000E+00,
        8.63495000000E+00, 8.88966100000E+00, 9.14420800000E+00, 9.39859700000E+00,
        9.65282700000E+00, 9.90690800000E+00, 1.01608500000E+01
      };

      PrincipalCrossSectionBlock chunk( std::move( energies ),
                                        std::move( total ),
                                        std::move( disappearance ),
                                        std::move( elastic ),
                                        std::move( heating ) );

      THEN( "a PrincipalCrossSectionBlock can be constructed and members can "
            "be tested" ) {

        verifyChunk( chunk );
      } // THEN
    } // WHEN

    WHEN( "the data is defined by iterators" ) {

      PrincipalCrossSectionBlock chunk( xss.begin(), xss.end(), 99 );

      THEN( "a PrincipalCrossSectionBlock can be constructed and members can "
            "be tested" ) {

        verifyChunk( chunk );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

std::vector< double > chunk() {

  return {

    1.00000000000E-11, 2.00000000000E-11, 5.00000000000E-11, 1.00000000000E-10,
    2.00000000000E-10, 5.00000000000E-10, 1.00000000000E-09, 2.00000000000E-09,
    5.00000000000E-09, 1.00000000000E-08, 2.00000000000E-08, 2.53000000000E-08,
    5.00000000000E-08, 1.00000000000E-07, 2.00000000000E-07, 5.00000000000E-07,
    1.00000000000E-06, 2.00000000000E-06, 5.00000000000E-06, 1.00000000000E-05,
    2.00000000000E-05, 5.00000000000E-05, 1.00000000000E-04, 2.00000000000E-04,
    5.00000000000E-04, 1.00000000000E-03, 2.00000000000E-03, 4.00000000000E-03,
    5.00000000000E-03, 6.00000000000E-03, 8.00000000000E-03, 1.00000000000E-02,
    1.50000000000E-02, 2.00000000000E-02, 4.00000000000E-02, 5.00000000000E-02,
    6.00000000000E-02, 8.00000000000E-02, 1.00000000000E-01, 1.50000000000E-01,
    2.00000000000E-01, 3.00000000000E-01, 4.00000000000E-01, 5.00000000000E-01,
    6.00000000000E-01, 7.00000000000E-01, 8.00000000000E-01, 9.00000000000E-01,
    1.00000000000E+00, 1.20000000000E+00, 1.40000000000E+00, 1.60000000000E+00,
    1.80000000000E+00, 2.00000000000E+00, 2.20000000000E+00, 2.40000000000E+00,
    2.60000000000E+00, 2.80000000000E+00, 3.00000000000E+00, 3.20000000000E+00,
    3.40000000000E+00, 3.60000000000E+00, 3.80000000000E+00, 4.00000000000E+00,
    4.20000000000E+00, 4.40000000000E+00, 4.60000000000E+00, 4.80000000000E+00,
    5.00000000000E+00, 5.50000000000E+00, 6.00000000000E+00, 6.50000000000E+00,
    7.00000000000E+00, 7.50000000000E+00, 8.00000000000E+00, 8.50000000000E+00,
    9.00000000000E+00, 9.50000000000E+00, 1.00000000000E+01, 1.05000000000E+01,
    1.10000000000E+01, 1.15000000000E+01, 1.20000000000E+01, 1.25000000000E+01,
    1.30000000000E+01, 1.35000000000E+01, 1.40000000000E+01, 1.45000000000E+01,
    1.50000000000E+01, 1.55000000000E+01, 1.60000000000E+01, 1.65000000000E+01,
    1.70000000000E+01, 1.75000000000E+01, 1.80000000000E+01, 1.85000000000E+01,
    1.90000000000E+01, 1.95000000000E+01, 2.00000000000E+01, 1.17771501000E+03,
    8.32878160000E+02, 5.26963255000E+02, 3.72860705000E+02, 2.63993524000E+02,
    1.67610483000E+02, 1.19277715000E+02, 8.54096130000E+01, 5.60122893000E+01,
    4.18877751000E+01, 3.26778146000E+01, 3.04231461000E+01, 2.57923581000E+01,
    2.31941021000E+01, 2.18532558000E+01, 2.10313719000E+01, 2.07491966000E+01,
    2.06037794000E+01, 2.05115346000E+01, 2.04777658000E+01, 2.04585030000E+01,
    2.04422859000E+01, 2.04307615000E+01, 2.04144624000E+01, 2.03721297000E+01,
    2.03046009000E+01, 2.01723458000E+01, 1.99144127000E+01, 1.97892313000E+01,
    1.96641245000E+01, 1.94210094000E+01, 1.91847439000E+01, 1.86220408000E+01,
    1.80961984000E+01, 1.62960783000E+01, 1.55815917000E+01, 1.48677251000E+01,
    1.37062041000E+01, 1.27427238000E+01, 1.09238445000E+01, 9.64358528000E+00,
    7.95229561000E+00, 6.87663428000E+00, 6.12560229000E+00, 5.56699890000E+00,
    5.13210634000E+00, 4.78165124000E+00, 4.49154240000E+00, 4.24618070000E+00,
    3.85053146000E+00, 3.54181422000E+00, 3.29137287000E+00, 3.08224139000E+00,
    2.90369677000E+00, 2.74859202000E+00, 2.61196516000E+00, 2.49024321000E+00,
    2.38078120000E+00, 2.28156513000E+00, 2.19103601000E+00, 2.10795886000E+00,
    2.03134269000E+00, 1.96037450000E+00, 1.89438931000E+00, 1.83282710000E+00,
    1.77521589000E+00, 1.72115668000E+00, 1.67030247000E+00, 1.62235727000E+00,
    1.51359377000E+00, 1.41819631000E+00, 1.33374287000E+00, 1.25840048000E+00,
    1.19073011000E+00, 1.12959677000E+00, 1.07408446000E+00, 1.02344716000E+00,
    9.77066588000E-01, 9.34429025000E-01, 8.95099875000E-01, 8.58710735000E-01,
    8.24946302000E-01, 7.93535076000E-01, 7.64241754000E-01, 7.36861535000E-01,
    7.11214819000E-01, 6.87143905000E-01, 6.64509492000E-01, 6.43187979000E-01,
    6.23069267000E-01, 6.04055154000E-01, 5.86057740000E-01, 5.68997726000E-01,
    5.52804011000E-01, 5.37412095000E-01, 5.22763779000E-01, 5.08805961000E-01,
    4.95490443000E-01, 4.82773424000E-01, 1.71740100000E+01, 1.21438600000E+01,
    7.68045500000E+00, 5.43090500000E+00, 3.84022400000E+00, 2.42878300000E+00,
    1.71741500000E+00, 1.21440300000E+00, 7.68079300000E-01, 5.43155100000E-01,
    3.84154600000E-01, 3.41606100000E-01, 2.43218100000E-01, 1.72502100000E-01,
    1.23265800000E-01, 7.76319400000E-02, 5.42665800000E-02, 3.83593600000E-02,
    2.41345500000E-02, 1.69157900000E-02, 1.19330400000E-02, 7.52588100000E-03,
    5.30147700000E-03, 3.74241900000E-03, 2.35974500000E-03, 1.66085400000E-03,
    1.16578800000E-03, 8.12732500000E-04, 7.21302100000E-04, 6.54483800000E-04,
    5.59372400000E-04, 4.93876600000E-04, 3.90771200000E-04, 3.28387200000E-04,
    2.08326100000E-04, 1.81663500000E-04, 1.55085200000E-04, 1.24126000000E-04,
    1.03786200000E-04, 7.45175200000E-05, 5.92842800000E-05, 4.46076700000E-05,
    3.82766600000E-05, 3.52914400000E-05, 3.38996200000E-05, 3.33423900000E-05,
    3.32443400000E-05, 3.34022300000E-05, 3.36990500000E-05, 3.44554600000E-05,
    3.52169900000E-05, 3.58729500000E-05, 3.63894900000E-05, 3.67662300000E-05,
    3.70168600000E-05, 3.71598700000E-05, 3.72143000000E-05, 3.71976900000E-05,
    3.71253600000E-05, 3.70102000000E-05, 3.68628700000E-05, 3.66920200000E-05,
    3.65045600000E-05, 3.63059900000E-05, 3.61006300000E-05, 3.58918300000E-05,
    3.56821800000E-05, 3.54736400000E-05, 3.52677000000E-05, 3.47705000000E-05,
    3.43050800000E-05, 3.38741800000E-05, 3.34769900000E-05, 3.31108400000E-05,
    3.27723300000E-05, 3.24578800000E-05, 3.21640000000E-05, 3.18874900000E-05,
    3.16254500000E-05, 3.13753100000E-05, 3.11348500000E-05, 3.09021400000E-05,
    3.06755200000E-05, 3.04536000000E-05, 3.02351800000E-05, 3.00192800000E-05,
    2.98050700000E-05, 2.95919000000E-05, 2.93792000000E-05, 2.91665600000E-05,
    2.89536300000E-05, 2.87401800000E-05, 2.85260300000E-05, 2.83110700000E-05,
    2.80952300000E-05, 2.78785100000E-05, 2.76609500000E-05, 2.74425900000E-05,
    2.72235400000E-05, 1.16054100000E+03, 8.20734300000E+02, 5.19282800000E+02,
    3.67429800000E+02, 2.60153300000E+02, 1.65181700000E+02, 1.17560300000E+02,
    8.41952100000E+01, 5.52442100000E+01, 4.13446200000E+01, 3.22936600000E+01,
    3.00815400000E+01, 2.55491400000E+01, 2.30216000000E+01, 2.17299900000E+01,
    2.09537400000E+01, 2.06949300000E+01, 2.05654200000E+01, 2.04874000000E+01,
    2.04608500000E+01, 2.04465700000E+01, 2.04347600000E+01, 2.04254600000E+01,
    2.04107200000E+01, 2.03697700000E+01, 2.03029400000E+01, 2.01711800000E+01,
    1.99136000000E+01, 1.97885100000E+01, 1.96634700000E+01, 1.94204500000E+01,
    1.91842500000E+01, 1.86216500000E+01, 1.80958700000E+01, 1.62958700000E+01,
    1.55814100000E+01, 1.48675700000E+01, 1.37060800000E+01, 1.27426200000E+01,
    1.09237700000E+01, 9.64352600000E+00, 7.95225100000E+00, 6.87659600000E+00,
    6.12556700000E+00, 5.56696500000E+00, 5.13207300000E+00, 4.78161800000E+00,
    4.49150900000E+00, 4.24614700000E+00, 3.85049700000E+00, 3.54177900000E+00,
    3.29133700000E+00, 3.08220500000E+00, 2.90366000000E+00, 2.74855500000E+00,
    2.61192800000E+00, 2.49020600000E+00, 2.38074400000E+00, 2.28152800000E+00,
    2.19099900000E+00, 2.10792200000E+00, 2.03130600000E+00, 1.96033800000E+00,
    1.89435300000E+00, 1.83279100000E+00, 1.77518000000E+00, 1.72112100000E+00,
    1.67026700000E+00, 1.62232200000E+00, 1.51355900000E+00, 1.41816200000E+00,
    1.33370900000E+00, 1.25836700000E+00, 1.19069700000E+00, 1.12956400000E+00,
    1.07405200000E+00, 1.02341500000E+00, 9.77034700000E-01, 9.34397400000E-01,
    8.95068500000E-01, 8.58679600000E-01, 8.24915400000E-01, 7.93504400000E-01,
    7.64211300000E-01, 7.36831300000E-01, 7.11184800000E-01, 6.87114100000E-01,
    6.64479900000E-01, 6.43158600000E-01, 6.23040100000E-01, 6.04026200000E-01,
    5.86029000000E-01, 5.68969200000E-01, 5.52775700000E-01, 5.37384000000E-01,
    5.22735900000E-01, 5.08778300000E-01, 4.95463000000E-01, 4.82746200000E-01,
    1.91876400000E-05, 1.91851600000E-05, 1.91777300000E-05, 1.91653500000E-05,
    1.91406000000E-05, 1.90670400000E-05, 1.89460000000E-05, 1.87098000000E-05,
    1.80456600000E-05, 1.70668700000E-05, 1.54783100000E-05, 1.47871100000E-05,
    1.24328000000E-05, 9.83603500000E-06, 7.52192300000E-06, 5.10694200000E-06,
    3.94128900000E-06, 3.44970900000E-06, 4.04821500000E-06, 6.08692400000E-06,
    1.07674800000E-05, 2.54844200000E-05, 5.03414400000E-05, 1.00241200000E-04,
    2.50152600000E-04, 5.00108300000E-04, 1.00007900000E-03, 2.00006600000E-03,
    2.50006700000E-03, 3.00007200000E-03, 4.00008800000E-03, 5.00011200000E-03,
    7.50020400000E-03, 1.00003300000E-02, 2.00012200000E-02, 2.50018600000E-02,
    3.00026400000E-02, 4.00045600000E-02, 5.00069200000E-02, 7.50145900000E-02,
    1.00024400000E-01, 1.50049400000E-01, 2.00080000000E-01, 2.50115500000E-01,
    3.00155600000E-01, 3.50200500000E-01, 4.00250200000E-01, 4.50305400000E-01,
    5.00366600000E-01, 6.00508500000E-01, 7.00681000000E-01, 8.00888300000E-01,
    9.01134500000E-01, 1.00142400000E+00, 1.10175900000E+00, 1.20214500000E+00,
    1.30258200000E+00, 1.40307400000E+00, 1.50362400000E+00, 1.60423100000E+00,
    1.70489800000E+00, 1.80562500000E+00, 1.90641400000E+00, 2.00726500000E+00,
    2.10817800000E+00, 2.20915400000E+00, 2.31019100000E+00, 2.41129100000E+00,
    2.51245200000E+00, 2.76561900000E+00, 3.01915100000E+00, 3.27303000000E+00,
    3.52723200000E+00, 3.78173100000E+00, 4.03650100000E+00, 4.29150900000E+00,
    4.54672500000E+00, 4.80211900000E+00, 5.05765800000E+00, 5.31330900000E+00,
    5.56904300000E+00, 5.82482900000E+00, 6.08063700000E+00, 6.33644100000E+00,
    6.59221500000E+00, 6.84793700000E+00, 7.10358200000E+00, 7.35913200000E+00,
    7.61457000000E+00, 7.86988300000E+00, 8.12505600000E+00, 8.38008000000E+00,
    8.63495000000E+00, 8.88966100000E+00, 9.14420800000E+00, 9.39859700000E+00,
    9.65282700000E+00, 9.90690800000E+00, 1.01608500000E+01
  };
}

void verifyChunk( const PrincipalCrossSectionBlock& chunk ) {

  CHECK( false == chunk.empty() );
  CHECK( 495 == chunk.length() );
  CHECK( "ESZ" == chunk.name() );

  CHECK( 99 == chunk.NES() );
  CHECK( 99 == chunk.numberEnergyPoints() );
  CHECK( 99 == chunk.energies().size() );
  CHECK( 99 == chunk.total().size() );
  CHECK( 99 == chunk.disappearance().size() );
  CHECK( 99 == chunk.elastic().size() );
  CHECK( 99 == chunk.heating().size() );

  CHECK( 1.00000000000E-11 == Approx( chunk.energies().front() ) );
  CHECK( 2.00000000000E+01 == Approx( chunk.energies().back() ) );
  CHECK( 1.17771501000E+03 == Approx( chunk.total().front() ) );
  CHECK( 4.82773424000E-01 == Approx( chunk.total().back() ) );
  CHECK( 1.71740100000E+01 == Approx( chunk.disappearance().front() ) );
  CHECK( 2.72235400000E-05 == Approx( chunk.disappearance().back() ) );
  CHECK( 1.16054100000E+03 == Approx( chunk.elastic().front() ) );
  CHECK( 4.82746200000E-01 == Approx( chunk.elastic().back() ) );
  CHECK( 1.91876400000E-05 == Approx( chunk.heating().front() ) );
  CHECK( 1.01608500000E+01 == Approx( chunk.heating().back() ) );
}
