#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ACEtk/fromFile.hpp"
#include "ACEtk/DosimetryTable.hpp"

// other includes

// convenience typedefs
using namespace njoy::ACEtk;
using CrossSectionData = dosimetry::CrossSectionData;
using MTR = block::MTR;
using SIGD = dosimetry::SIGD;
using Header = Table::Header;

void verifyChunk( const DosimetryTable& );

SCENARIO( "DosimetryTable" ){

  GIVEN( "valid data for a DosimetryTable" ) {

    auto table = fromFile( "13027.24y" );
    std::array< int32_t, 16 > iz = table.data().IZ();
    std::array< double, 16 > aw = table.data().AW();
    std::array< int64_t, 16 > nxs = table.data().NXS();
    std::array< int64_t, 32 > jxs = table.data().JXS();
    std::vector< double > xss = table.data().XSS();

    WHEN( "constructing a DosimetryTable from a table" ) {

      DosimetryTable chunk( std::move( table ) );

      THEN( "a DosimetryTable can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      }

      THEN( "the IZ array is correct" ) {

        decltype(auto) iz_chunk = chunk.data().IZ();
        CHECK( iz.size() == iz_chunk.size() );
        for ( unsigned int i = 0; i < iz_chunk.size(); ++i ) {

          CHECK( iz[i] == Approx( iz_chunk[i] ) );
        }
      } // THEN

      THEN( "the AW array is correct" ) {

        decltype(auto) aw_chunk = chunk.data().AW();
        CHECK( aw.size() == aw_chunk.size() );
        for ( unsigned int i = 0; i < aw_chunk.size(); ++i ) {

          CHECK( aw[i] == Approx( aw_chunk[i] ) );
        }
      } // THEN

      THEN( "the NXS array is correct" ) {

        decltype(auto) nxs_chunk = chunk.data().NXS();
        CHECK( nxs.size() == nxs_chunk.size() );
        for ( unsigned int i = 0; i < nxs_chunk.size(); ++i ) {

          CHECK( nxs[i] == Approx( nxs_chunk[i] ) );
        }
      } // THEN

      THEN( "the JXS array is correct" ) {

        decltype(auto) jxs_chunk = chunk.data().JXS();
        CHECK( jxs.size() == jxs_chunk.size() );
        for ( unsigned int i = 0; i < jxs_chunk.size(); ++i ) {

          CHECK( jxs[i] == Approx( jxs_chunk[i] ) );
        }
      } // THEN

      THEN( "the XSS array is correct" ) {

        decltype(auto) xss_chunk = chunk.data().XSS();
        CHECK( xss.size() == xss_chunk.size() );
        for ( unsigned int i = 0; i < xss_chunk.size(); ++i ) {

          CHECK( xss[i] == Approx( xss_chunk[i] ) );
        }
      } // THEN
    } // WHEN

    WHEN( "constructing a DosimetryTable from scratch" ) {

      unsigned int z = 13;
      unsigned int a = 27;
      Header header( "13027.24y", 26.75, 0., "", "", "" );
      MTR mtr( { 103, 107 } );
      SIGD sigd( { CrossSectionData(

                     { 1.896100000000E+00, 2.000000000000E+00,
                       2.050000000000E+00, 2.062500000000E+00, 2.075000000000E+00, 2.078125000000E+00,
                       2.081250000000E+00, 2.082421880000E+00, 2.083593750000E+00, 2.084106450000E+00,
                       2.084859470000E+00, 2.085565420000E+00, 2.086235000000E+00, 2.086876820000E+00,
                       2.087684200000E+00, 2.088453940000E+00, 2.089175570000E+00, 2.089852090000E+00,
                       2.090486340000E+00, 2.091080940000E+00, 2.091908110000E+00, 2.092650920000E+00,
                       2.093332490000E+00, 2.094139880000E+00, 2.094872400000E+00, 2.095513350000E+00,
                       2.096335900000E+00, 2.096793910000E+00, 2.097595440000E+00, 2.098422000000E+00,
                       2.098985570000E+00, 2.099661860000E+00, 2.100000000000E+00, 2.101165770000E+00,
                       2.102307320000E+00, 2.103797720000E+00, 2.105241540000E+00, 2.106640240000E+00,
                       2.107995230000E+00, 2.109307880000E+00, 2.110579510000E+00, 2.111811400000E+00,
                       2.113004790000E+00, 2.114160890000E+00, 2.115280870000E+00, 2.116365840000E+00,
                       2.117934100000E+00, 2.119421530000E+00, 2.120847310000E+00, 2.122199610000E+00,
                       2.123495860000E+00, 2.124725300000E+00, 2.125903780000E+00, 2.127409790000E+00,
                       2.128821680000E+00, 2.130145330000E+00, 2.131386240000E+00, 2.132549600000E+00,
                       2.134151500000E+00, 2.135621320000E+00, 2.136941240000E+00, 2.138152330000E+00,
                       2.139633290000E+00, 2.140929130000E+00, 2.142062990000E+00, 2.143489170000E+00,
                       2.144682820000E+00, 2.146012120000E+00, 2.147436360000E+00, 2.148718180000E+00,
                       2.150000000000E+00, 2.152319340000E+00, 2.154542540000E+00, 2.156651160000E+00,
                       2.158672390000E+00, 2.160589440000E+00, 2.162427040000E+00, 2.164738650000E+00,
                       2.166942490000E+00, 2.169008580000E+00, 2.170945550000E+00, 2.172761450000E+00,
                       2.174463860000E+00, 2.176832130000E+00, 2.178958870000E+00, 2.180910260000E+00,
                       2.183221910000E+00, 2.185319170000E+00, 2.187154280000E+00, 2.189509330000E+00,
                       2.190820660000E+00, 2.193115490000E+00, 2.195482040000E+00, 2.197095600000E+00,
                       2.199031870000E+00, 2.200000000000E+00, 2.202319340000E+00, 2.204542540000E+00,
                       2.205963090000E+00, 2.208715390000E+00, 2.211295680000E+00, 2.213714700000E+00,
                       2.215982530000E+00, 2.218108620000E+00, 2.220101840000E+00, 2.222846390000E+00,
                       2.225364670000E+00, 2.227626120000E+00, 2.229701110000E+00, 2.232238480000E+00,
                       2.234458670000E+00, 2.237307910000E+00, 2.238894420000E+00, 2.241670820000E+00,
                       2.244533970000E+00, 2.246486130000E+00, 2.248828710000E+00, 2.250000000000E+00,
                       2.253125000000E+00, 2.256054690000E+00, 2.258801270000E+00, 2.261376190000E+00,
                       2.264921740000E+00, 2.268174960000E+00, 2.271096400000E+00, 2.273776980000E+00,
                       2.277054850000E+00, 2.279923000000E+00, 2.283603780000E+00, 2.286549980000E+00,
                       2.289015810000E+00, 2.291761860000E+00, 2.294704050000E+00, 2.298234680000E+00,
                       2.300000000000E+00, 2.303125000000E+00, 2.307427980000E+00, 2.311376190000E+00,
                       2.314921740000E+00, 2.318174960000E+00, 2.322153090000E+00, 2.325633950000E+00,
                       2.330012230000E+00, 2.333676650000E+00, 2.337757490000E+00, 2.341965850000E+00,
                       2.344835190000E+00, 2.348278400000E+00, 2.350000000000E+00, 2.354589840000E+00,
                       2.358801270000E+00, 2.363790180000E+00, 2.368316410000E+00, 2.372276860000E+00,
                       2.377359430000E+00, 2.380189500000E+00, 2.385142130000E+00, 2.390249520000E+00,
                       2.393731830000E+00, 2.397910610000E+00, 2.400000000000E+00, 2.403125000000E+00,
                       2.408984380000E+00, 2.414111330000E+00, 2.418597410000E+00, 2.424240060000E+00,
                       2.428962720000E+00, 2.434222040000E+00, 2.439645710000E+00, 2.445562450000E+00,
                       2.450000000000E+00, 2.456250000000E+00, 2.461718750000E+00, 2.468597410000E+00,
                       2.474354550000E+00, 2.480765910000E+00, 2.487377630000E+00, 2.491885620000E+00,
                       2.497295210000E+00, 2.500000000000E+00, 2.506250000000E+00, 2.514111330000E+00,
                       2.520690920000E+00, 2.528018190000E+00, 2.535574440000E+00, 2.540726420000E+00,
                       2.546908810000E+00, 2.550000000000E+00, 2.558984380000E+00, 2.566503910000E+00,
                       2.574877930000E+00, 2.583513640000E+00, 2.589401630000E+00, 2.596467210000E+00,
                       2.600000000000E+00, 2.608984380000E+00, 2.616503910000E+00, 2.624877930000E+00,
                       2.633850100000E+00, 2.641925050000E+00, 2.650000000000E+00, 2.656250000000E+00,
                       2.667187500000E+00, 2.678466800000E+00, 2.686157230000E+00, 2.695385740000E+00,
                       2.700000000000E+00, 2.711718750000E+00, 2.721289060000E+00, 2.731542970000E+00,
                       2.740771480000E+00, 2.750000000000E+00, 2.762500000000E+00, 2.775390630000E+00,
                       2.784179690000E+00, 2.794726560000E+00, 2.817187500000E+00, 2.828906250000E+00,
                       2.842968750000E+00, 2.867187500000E+00, 2.878906250000E+00, 2.892968750000E+00,
                       2.917187500000E+00, 2.928906250000E+00, 2.942968750000E+00, 2.962500000000E+00,
                       2.981250000000E+00, 3.000000000000E+00, 3.010000000000E+00, 3.100000000000E+00,
                       3.200000000000E+00, 3.300000000000E+00, 3.330000000000E+00, 3.360000000000E+00,
                       3.370000000000E+00, 3.380000000000E+00, 3.400000000000E+00, 3.420000000000E+00,
                       3.450000000000E+00, 3.470000000000E+00, 3.490000000000E+00, 3.500000000000E+00,
                       3.520000000000E+00, 3.530000000000E+00, 3.580000000000E+00, 3.590000000000E+00,
                       3.600000000000E+00, 3.610000000000E+00, 3.620000000000E+00, 3.650000000000E+00,
                       3.660000000000E+00, 3.680000000000E+00, 3.700000000000E+00, 3.800000000000E+00,
                       3.880000000000E+00, 3.900000000000E+00, 3.990000000000E+00, 4.000000000000E+00,
                       4.100000000000E+00, 4.150000000000E+00, 4.200000000000E+00, 4.250000000000E+00,
                       4.300000000000E+00, 4.400000000000E+00, 4.500000000000E+00, 4.550000000000E+00,
                       4.600000000000E+00, 4.650000000000E+00, 4.700000000000E+00, 4.750000000000E+00,
                       4.800000000000E+00, 4.850000000000E+00, 4.900000000000E+00, 5.000000000000E+00,
                       5.100000000000E+00, 5.200000000000E+00, 5.400000000000E+00, 5.600000000000E+00,
                       6.000000000000E+00, 6.400000000000E+00, 6.800000000000E+00, 7.000000000000E+00,
                       7.400000000000E+00, 7.800000000000E+00, 8.200000000000E+00, 8.400000000000E+00,
                       8.600000000000E+00, 9.000000000000E+00, 9.200000000000E+00, 9.400000000000E+00,
                       9.600000000000E+00, 9.800000000000E+00, 1.000000000000E+01, 1.050000000000E+01,
                       1.100000000000E+01, 1.250000000000E+01, 1.300000000000E+01, 1.350000000000E+01,
                       1.450000000000E+01, 1.500000000000E+01, 1.600000000000E+01, 1.650000000000E+01,
                       1.750000000000E+01, 1.850000000000E+01, 1.950000000000E+01, 2.000000000000E+01 },
                     {                   0, 9.090000000000E-15, 2.180400000000E-12, 8.580800000000E-12,
                        3.376910000000E-11, 4.756270000000E-11, 6.699070000000E-11, 7.617190000000E-11,
                        8.661150000000E-11, 9.161770000000E-11, 9.949990000000E-11, 1.075040000000E-10,
                        1.156900000000E-10, 1.241220000000E-10, 1.356060000000E-10, 1.475420000000E-10,
                        1.596860000000E-10, 1.719760000000E-10, 1.843560000000E-10, 1.967710000000E-10,
                        2.154440000000E-10, 2.337170000000E-10, 2.518450000000E-10, 2.751470000000E-10,
                        2.981480000000E-10, 3.198450000000E-10, 3.500200000000E-10, 3.680390000000E-10,
                        4.018330000000E-10, 4.399370000000E-10, 4.679680000000E-10, 5.039720000000E-10,
                        5.230000000000E-10, 5.599160000000E-10, 5.985880000000E-10, 6.531270000000E-10,
                        7.106950000000E-10, 7.712990000000E-10, 8.349330000000E-10, 9.015810000000E-10,
                        9.712150000000E-10, 1.043800000000E-09, 1.119280000000E-09, 1.197610000000E-09,
                        1.278710000000E-09, 1.362510000000E-09, 1.493440000000E-09, 1.629230000000E-09,
                        1.770960000000E-09, 1.916770000000E-09, 2.067790000000E-09, 2.222000000000E-09,
                        2.380610000000E-09, 2.599890000000E-09, 2.823770000000E-09, 3.051130000000E-09,
                        3.280890000000E-09, 3.511970000000E-09, 3.857040000000E-09, 4.203390000000E-09,
                        4.540860000000E-09, 4.874280000000E-09, 5.315450000000E-09, 5.734110000000E-09,
                        6.127400000000E-09, 6.660600000000E-09, 7.142380000000E-09, 7.720030000000E-09,
                        8.390880000000E-09, 9.044340000000E-09, 9.748700000000E-09, 1.065310000000E-08,
                        1.159860000000E-08, 1.257290000000E-08, 1.358350000000E-08, 1.461700000000E-08,
                        1.568140000000E-08, 1.713110000000E-08, 1.863780000000E-08, 2.017050000000E-08,
                        2.172170000000E-08, 2.328410000000E-08, 2.485070000000E-08, 2.720700000000E-08,
                        2.951280000000E-08, 3.179990000000E-08, 3.473980000000E-08, 3.764150000000E-08,
                        4.037860000000E-08, 4.418490000000E-08, 4.645770000000E-08, 5.072000000000E-08,
                        5.552540000000E-08, 5.906040000000E-08, 6.360060000000E-08, 6.600000000000E-08,
                        7.111800000000E-08, 7.639610000000E-08, 7.997190000000E-08, 8.738320000000E-08,
                        9.495400000000E-08, 1.026460000000E-07, 1.104230000000E-07, 1.182470000000E-07,
                        1.260860000000E-07, 1.377370000000E-07, 1.493710000000E-07, 1.606550000000E-07,
                        1.717560000000E-07, 1.863790000000E-07, 2.001920000000E-07, 2.194280000000E-07,
                        2.309300000000E-07, 2.525270000000E-07, 2.769160000000E-07, 2.948820000000E-07,
                        3.179870000000E-07, 3.302100000000E-07, 3.569930000000E-07, 3.840710000000E-07,
                        4.113200000000E-07, 4.386190000000E-07, 4.791970000000E-07, 5.197250000000E-07,
                        5.590310000000E-07, 5.977080000000E-07, 6.486570000000E-07, 6.967870000000E-07,
                        7.638240000000E-07, 8.221000000000E-07, 8.742780000000E-07, 9.362930000000E-07,
                        1.007630000000E-06, 1.100440000000E-06, 1.150000000000E-06, 1.228790000000E-06,
                        1.346180000000E-06, 1.463740000000E-06, 1.578040000000E-06, 1.690740000000E-06,
                        1.839560000000E-06, 1.980470000000E-06, 2.173150000000E-06, 2.348750000000E-06,
                        2.561060000000E-06, 2.800110000000E-06, 2.975770000000E-06, 3.201180000000E-06,
                        3.320200000000E-06, 3.599350000000E-06, 3.876080000000E-06, 4.231560000000E-06,
                        4.582200000000E-06, 4.912770000000E-06, 5.372170000000E-06, 5.646340000000E-06,
                        6.160240000000E-06, 6.739240000000E-06, 7.164910000000E-06, 7.711350000000E-06,
                        8.000000000000E-06, 8.388640000000E-06, 9.168950000000E-06, 9.911040000000E-06,
                        1.060950000000E-05, 1.155830000000E-05, 1.241730000000E-05, 1.344930000000E-05,
                        1.460350000000E-05, 1.597580000000E-05, 1.708900000000E-05, 1.854010000000E-05,
                        1.991050000000E-05, 2.177890000000E-05, 2.347690000000E-05, 2.552400000000E-05,
                        2.782220000000E-05, 2.950670000000E-05, 3.166330000000E-05, 3.280000000000E-05,
                        3.524900000000E-05, 3.859060000000E-05, 4.162970000000E-05, 4.529670000000E-05,
                        4.941690000000E-05, 5.243900000000E-05, 5.631040000000E-05, 5.835200000000E-05,
                        6.391980000000E-05, 6.898610000000E-05, 7.510210000000E-05, 8.197760000000E-05,
                        8.702300000000E-05, 9.348900000000E-05, 9.690000000000E-05, 1.051410000000E-04,
                        1.125760000000E-04, 1.214750000000E-04, 1.317920000000E-04, 1.418240000000E-04,
                        1.526200000000E-04, 1.605610000000E-04, 1.754640000000E-04, 1.922840000000E-04,
                        2.046670000000E-04, 2.205830000000E-04, 2.290000000000E-04, 2.494710000000E-04,
                        2.675390000000E-04, 2.883520000000E-04, 3.084640000000E-04, 3.299800000000E-04,
                        3.583590000000E-04, 3.901840000000E-04, 4.134890000000E-04, 4.432990000000E-04,
                        5.092100000000E-04, 5.465570000000E-04, 5.950070000000E-04, 6.825630000000E-04,
                        7.281450000000E-04, 7.868790000000E-04, 8.924160000000E-04, 9.470000000000E-04,
                        1.016920000000E-03, 1.116940000000E-03, 1.218830000000E-03, 1.330000000000E-03,
                        1.390700000000E-03, 2.010000000000E-03, 2.460000000000E-03, 2.930000000000E-03,
                        3.178200000000E-03, 3.625400000000E-03, 3.860300000000E-03, 4.178000000000E-03,
                        5.100000000000E-03, 6.336000000000E-03, 8.900000000000E-03, 9.864000000000E-03,
                        1.015600000000E-02, 1.010000000000E-02, 9.780000000000E-03, 9.280000000000E-03,
                        5.340000000000E-03, 4.830000000000E-03, 4.600000000000E-03, 4.978000000000E-03,
                        5.652000000000E-03, 8.700000000000E-03, 9.062000000000E-03, 9.212000000000E-03,
                        9.100000000000E-03, 7.700000000000E-03, 7.076000000000E-03, 7.000000000000E-03,
                        6.942300000000E-03, 6.966700000000E-03, 7.500000000000E-03, 7.952100000000E-03,
                        8.600000000000E-03, 9.543700000000E-03, 1.070000000000E-02, 1.350000000000E-02,
                        1.700000000000E-02, 1.900000000000E-02, 2.155600000000E-02, 2.174200000000E-02,
                        2.000000000000E-02, 1.750000000000E-02, 1.650000000000E-02, 1.677500000000E-02,
                        1.800000000000E-02, 2.330000000000E-02, 2.634000000000E-02, 2.833600000000E-02,
                        3.316400000000E-02, 3.770400000000E-02, 4.640000000000E-02, 5.486400000000E-02,
                        6.367200000000E-02, 6.780000000000E-02, 7.520800000000E-02, 8.228000000000E-02,
                        8.897600000000E-02, 9.190400000000E-02, 9.414400000000E-02, 9.800000000000E-02,
                        1.004800000000E-01, 1.023200000000E-01, 1.034000000000E-01, 1.039000000000E-01,
                        1.040000000000E-01, 1.025200000000E-01, 1.000000000000E-01, 8.823700000000E-02,
                        8.500000000000E-02, 8.157400000000E-02, 7.397400000000E-02, 7.000000000000E-02,
                        6.270000000000E-02, 5.880700000000E-02, 5.168100000000E-02, 4.400000000000E-02,
                        3.638500000000E-02, 3.220000000000E-02 }
                   ),
                   CrossSectionData(
                     { 3.248700000000E+00, 3.600000000000E+00, 3.650000000000E+00, 3.675000000000E+00,
                       3.700000000000E+00, 3.750000000000E+00, 3.800000000000E+00, 3.825000000000E+00,
                       3.850000000000E+00, 3.875000000000E+00, 3.900000000000E+00, 3.925000000000E+00,
                       3.950000000000E+00, 3.975000000000E+00, 4.000000000000E+00, 4.025000000000E+00,
                       4.050000000000E+00, 4.075000000000E+00, 4.100000000000E+00, 4.125000000000E+00,
                       4.150000000000E+00, 4.162500000000E+00, 4.175000000000E+00, 4.178125000000E+00,
                       4.182421880000E+00, 4.185644530000E+00, 4.189233400000E+00, 4.191925050000E+00,
                       4.195962520000E+00, 4.200000000000E+00, 4.203125000000E+00, 4.207427980000E+00,
                       4.211376190000E+00, 4.214921740000E+00, 4.218174960000E+00, 4.222153090000E+00,
                       4.225633950000E+00, 4.228679710000E+00, 4.232588430000E+00, 4.236669270000E+00,
                       4.240001950000E+00, 4.243572680000E+00, 4.247857560000E+00, 4.254589840000E+00,
                       4.258801270000E+00, 4.262583180000E+00, 4.266053290000E+00, 4.270296630000E+00,
                       4.274009550000E+00, 4.278774470000E+00, 4.282588430000E+00, 4.285780550000E+00,
                       4.289335410000E+00, 4.293144190000E+00, 4.297714730000E+00, 4.304589840000E+00,
                       4.308801270000E+00, 4.313790180000E+00, 4.318316410000E+00, 4.322276860000E+00,
                       4.327359430000E+00, 4.330189500000E+00, 4.335142130000E+00, 4.340249520000E+00,
                       4.343731830000E+00, 4.347910610000E+00, 4.354589840000E+00, 4.358801270000E+00,
                       4.363951110000E+00, 4.368457220000E+00, 4.374125060000E+00, 4.378868800000E+00,
                       4.384151600000E+00, 4.389599490000E+00, 4.393313960000E+00, 4.397771320000E+00,
                       4.404589840000E+00, 4.408801270000E+00, 4.413951110000E+00, 4.418457220000E+00,
                       4.424240060000E+00, 4.427460060000E+00, 4.433095040000E+00, 4.438906120000E+00,
                       4.442868220000E+00, 4.447622740000E+00, 4.456054690000E+00, 4.461547850000E+00,
                       4.466354370000E+00, 4.472522740000E+00, 4.475957390000E+00, 4.481968050000E+00,
                       4.488166530000E+00, 4.492392770000E+00, 4.497464260000E+00, 4.506250000000E+00,
                       4.511718750000E+00, 4.516503910000E+00, 4.522522740000E+00, 4.527560230000E+00,
                       4.533170180000E+00, 4.539180830000E+00, 4.544590410000E+00, 4.556250000000E+00,
                       4.561718750000E+00, 4.568597410000E+00, 4.574354550000E+00, 4.580765910000E+00,
                       4.587377630000E+00, 4.594590410000E+00, 4.603125000000E+00, 4.608984380000E+00,
                       4.616503910000E+00, 4.620690920000E+00, 4.628018190000E+00, 4.635574440000E+00,
                       4.640726420000E+00, 4.646908810000E+00, 4.656250000000E+00, 4.664111330000E+00,
                       4.670690920000E+00, 4.678018190000E+00, 4.685574440000E+00, 4.690726420000E+00,
                       4.696908810000E+00, 4.706250000000E+00, 4.714111330000E+00, 4.720690920000E+00,
                       4.728018190000E+00, 4.733513640000E+00, 4.741756820000E+00, 4.750000000000E+00,
                       4.758984380000E+00, 4.766503910000E+00, 4.774877930000E+00, 4.783513640000E+00,
                       4.789401630000E+00, 4.796467210000E+00, 4.806250000000E+00, 4.814111330000E+00,
                       4.820690920000E+00, 4.828018190000E+00, 4.835868840000E+00, 4.842934420000E+00,
                       4.856250000000E+00, 4.861718750000E+00, 4.871289060000E+00, 4.881158450000E+00,
                       4.887887570000E+00, 4.895962520000E+00, 4.908984380000E+00, 4.916503910000E+00,
                       4.924877930000E+00, 4.933850100000E+00, 4.941925050000E+00, 4.956250000000E+00,
                       4.966503910000E+00, 4.974877930000E+00, 4.983850100000E+00, 4.991925050000E+00,
                       5.009179690000E+00, 5.017602540000E+00, 5.027902220000E+00, 5.036914440000E+00,
                       5.048480130000E+00, 5.054920110000E+00, 5.066190080000E+00, 5.077812240000E+00,
                       5.085736440000E+00, 5.095245480000E+00, 5.103125000000E+00, 5.112109380000E+00,
                       5.123095700000E+00, 5.132708740000E+00, 5.145045470000E+00, 5.151914790000E+00,
                       5.163936090000E+00, 5.176333060000E+00, 5.184785540000E+00, 5.194928510000E+00,
                       5.212500000000E+00, 5.223437500000E+00, 5.237194820000E+00, 5.248709110000E+00,
                       5.261531830000E+00, 5.274755260000E+00, 5.283771240000E+00, 5.294590410000E+00,
                       5.312500000000E+00, 5.323437500000E+00, 5.337194820000E+00, 5.348709110000E+00,
                       5.361531830000E+00, 5.375270460000E+00, 5.387635230000E+00, 5.412500000000E+00,
                       5.428222660000E+00, 5.441381840000E+00, 5.456036380000E+00, 5.471148870000E+00,
                       5.487635230000E+00, 5.517968750000E+00, 5.533007810000E+00, 5.549755860000E+00,
                       5.567027280000E+00, 5.578803250000E+00, 5.592934420000E+00, 5.617968750000E+00,
                       5.633007810000E+00, 5.649755860000E+00, 5.667027280000E+00, 5.685868840000E+00,
                       5.717968750000E+00, 5.733007810000E+00, 5.749755860000E+00, 5.767700200000E+00,
                       5.783850100000E+00, 5.817968750000E+00, 5.833007810000E+00, 5.849755860000E+00,
                       5.867700200000E+00, 5.889233400000E+00, 5.912500000000E+00, 5.934375000000E+00,
                       5.956933590000E+00, 5.972314450000E+00, 5.990771480000E+00, 6.000000000000E+00,
                       6.100000000000E+00, 6.200000000000E+00, 6.300000000000E+00, 6.400000000000E+00,
                       6.500000000000E+00, 6.700000000000E+00, 6.800000000000E+00, 6.900000000000E+00,
                       7.000000000000E+00, 7.200000000000E+00, 7.400000000000E+00, 7.600000000000E+00,
                       7.800000000000E+00, 8.000000000000E+00, 8.200000000000E+00, 8.400000000000E+00,
                       8.600000000000E+00, 8.800000000000E+00, 9.000000000000E+00, 9.200000000000E+00,
                       9.400000000000E+00, 9.600000000000E+00, 9.800000000000E+00, 1.000000000000E+01,
                       1.050000000000E+01, 1.100000000000E+01, 1.150000000000E+01, 1.200000000000E+01,
                       1.250000000000E+01, 1.300000000000E+01, 1.350000000000E+01, 1.400000000000E+01,
                       1.450000000000E+01, 1.500000000000E+01, 1.550000000000E+01, 1.600000000000E+01,
                       1.650000000000E+01, 1.700000000000E+01, 1.750000000000E+01, 1.800000000000E+01,
                       1.850000000000E+01, 1.900000000000E+01, 1.950000000000E+01, 2.000000000000E+01 },
                     {                  0, 3.160000000000E-22, 1.014000000000E-20, 5.743820000000E-20,
                       3.253600000000E-19, 1.044010000000E-17, 3.350000000000E-16, 1.092320000000E-15,
                       3.561700000000E-15, 1.013470000000E-14, 2.883800000000E-14, 7.160990000000E-14,
                       1.778200000000E-13, 3.853310000000E-13, 8.350000000000E-13, 1.751580000000E-12,
                       3.674300000000E-12, 7.228820000000E-12, 1.422200000000E-11, 2.624150000000E-11,
                       4.841900000000E-11, 6.369480000000E-11, 8.378990000000E-11, 8.973540000000E-11,
                       9.860530000000E-11, 1.058290000000E-10, 1.144970000000E-10, 1.214610000000E-10,
                       1.327100000000E-10, 1.450000000000E-10, 1.547240000000E-10, 1.691900000000E-10,
                       1.836500000000E-10, 1.976860000000E-10, 2.115060000000E-10, 2.297250000000E-10,
                       2.469500000000E-10, 2.630780000000E-10, 2.853280000000E-10, 3.105690000000E-10,
                       3.328290000000E-10, 3.584530000000E-10, 3.918200000000E-10, 4.476150000000E-10,
                       4.855390000000E-10, 5.223240000000E-10, 5.585240000000E-10, 6.062170000000E-10,
                       6.512770000000E-10, 7.140460000000E-10, 7.686200000000E-10, 8.174890000000E-10,
                       8.755770000000E-10, 9.424020000000E-10, 1.029360000000E-09, 1.167650000000E-09,
                       1.258810000000E-09, 1.376060000000E-09, 1.491850000000E-09, 1.601130000000E-09,
                       1.753190000000E-09, 1.844030000000E-09, 2.014480000000E-09, 2.206770000000E-09,
                       2.348290000000E-09, 2.530150000000E-09, 2.831490000000E-09, 3.033840000000E-09,
                       3.301030000000E-09, 3.554050000000E-09, 3.900030000000E-09, 4.215350000000E-09,
                       4.596600000000E-09, 5.025910000000E-09, 5.341400000000E-09, 5.746220000000E-09,
                       6.399200000000E-09, 6.830600000000E-09, 7.397850000000E-09, 7.932700000000E-09,
                       8.676140000000E-09, 9.119890000000E-09, 9.951770000000E-09, 1.088920000000E-08,
                       1.157850000000E-08, 1.246350000000E-08, 1.412310000000E-08, 1.529950000000E-08,
                       1.640900000000E-08, 1.795150000000E-08, 1.887240000000E-08, 2.059900000000E-08,
                       2.254530000000E-08, 2.397660000000E-08, 2.581480000000E-08, 2.916900000000E-08,
                       3.142750000000E-08, 3.354660000000E-08, 3.641610000000E-08, 3.900560000000E-08,
                       4.210670000000E-08, 4.570330000000E-08, 4.920220000000E-08, 5.734810000000E-08,
                       6.147580000000E-08, 6.709210000000E-08, 7.218520000000E-08, 7.831340000000E-08,
                       8.517850000000E-08, 9.335580000000E-08, 1.038560000000E-07, 1.114920000000E-07,
                       1.221200000000E-07, 1.284700000000E-07, 1.403890000000E-07, 1.538400000000E-07,
                       1.637420000000E-07, 1.764700000000E-07, 1.968240000000E-07, 2.154090000000E-07,
                       2.323050000000E-07, 2.526870000000E-07, 2.755790000000E-07, 2.923660000000E-07,
                       3.138650000000E-07, 3.480060000000E-07, 3.789770000000E-07, 4.070070000000E-07,
                       4.406700000000E-07, 4.677310000000E-07, 5.114700000000E-07, 5.593000000000E-07,
                       6.130480000000E-07, 6.619830000000E-07, 7.210890000000E-07, 7.875750000000E-07,
                       8.363880000000E-07, 8.989730000000E-07, 9.904520000000E-07, 1.069210000000E-06,
                       1.139920000000E-06, 1.224180000000E-06, 1.321380000000E-06, 1.415440000000E-06,
                       1.606680000000E-06, 1.690270000000E-06, 1.847150000000E-06, 2.024200000000E-06,
                       2.154550000000E-06, 2.322100000000E-06, 2.609420000000E-06, 2.788280000000E-06,
                       3.001920000000E-06, 3.249030000000E-06, 3.488770000000E-06, 3.947130000000E-06,
                       4.300380000000E-06, 4.612200000000E-06, 4.971430000000E-06, 5.318590000000E-06,
                       6.114670000000E-06, 6.532160000000E-06, 7.081610000000E-06, 7.600160000000E-06,
                       8.321640000000E-06, 8.752660000000E-06, 9.561350000000E-06, 1.047370000000E-05,
                       1.114510000000E-05, 1.200790000000E-05, 1.274600000000E-05, 1.359260000000E-05,
                       1.470480000000E-05, 1.575230000000E-05, 1.720660000000E-05, 1.807390000000E-05,
                       1.969810000000E-05, 2.152600000000E-05, 2.286870000000E-05, 2.459090000000E-05,
                       2.768630000000E-05, 2.975250000000E-05, 3.257180000000E-05, 3.513570000000E-05,
                       3.822920000000E-05, 4.170490000000E-05, 4.425420000000E-05, 4.751990000000E-05,
                       5.311220000000E-05, 5.674740000000E-05, 6.167510000000E-05, 6.612680000000E-05,
                       7.146360000000E-05, 7.766040000000E-05, 8.369570000000E-05, 9.674940000000E-05,
                       1.056670000000E-04, 1.137590000000E-04, 1.235020000000E-04, 1.344240000000E-04,
                       1.474440000000E-04, 1.734130000000E-04, 1.874320000000E-04, 2.043830000000E-04,
                       2.234700000000E-04, 2.374970000000E-04, 2.554950000000E-04, 2.887180000000E-04,
                       3.101930000000E-04, 3.359940000000E-04, 3.648500000000E-04, 3.991630000000E-04,
                       4.626290000000E-04, 4.947240000000E-04, 5.330940000000E-04, 5.775130000000E-04,
                       6.206460000000E-04, 7.186290000000E-04, 7.649000000000E-04, 8.199430000000E-04,
                       8.833210000000E-04, 9.658740000000E-04, 1.060300000000E-03, 1.154430000000E-03,
                       1.260270000000E-03, 1.337940000000E-03, 1.437480000000E-03, 1.490000000000E-03,
                       2.140000000000E-03, 2.990000000000E-03, 4.000000000000E-03, 5.140000000000E-03,
                       6.540000000000E-03, 9.870000000000E-03, 1.180000000000E-02, 1.370000000000E-02,
                       1.590000000000E-02, 2.010000000000E-02, 2.500000000000E-02, 3.000000000000E-02,
                       3.560000000000E-02, 4.130000000000E-02, 4.710000000000E-02, 5.330000000000E-02,
                       5.920000000000E-02, 6.490000000000E-02, 7.020000000000E-02, 7.510000000000E-02,
                       7.970000000000E-02, 8.380000000000E-02, 8.770000000000E-02, 9.120000000000E-02,
                       9.961200000000E-02, 1.075000000000E-01, 1.149300000000E-01, 1.212000000000E-01,
                       1.260400000000E-01, 1.288000000000E-01, 1.279400000000E-01, 1.247000000000E-01,
                       1.193600000000E-01, 1.129000000000E-01, 1.052100000000E-01, 9.700000000000E-02,
                       8.840600000000E-02, 7.940000000000E-02, 7.118700000000E-02, 6.370000000000E-02,
                       5.653700000000E-02, 4.980000000000E-02, 4.343700000000E-02, 3.800000000000E-02 }
                     ) } );

      DosimetryTable chunk( z, a, std::move( header ),
                            std::move( mtr ), std::move( sigd ) );

      THEN( "a DosimetryTable can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      }

      THEN( "the IZ array is correct" ) {

        decltype(auto) iz_chunk = chunk.data().IZ();
        CHECK( iz.size() == iz_chunk.size() );
        for ( unsigned int i = 0; i < iz_chunk.size(); ++i ) {

          CHECK( iz[i] == Approx( iz_chunk[i] ) );
        }
      } // THEN

      THEN( "the AW array is correct" ) {

        decltype(auto) aw_chunk = chunk.data().AW();
        CHECK( aw.size() == aw_chunk.size() );
        for ( unsigned int i = 0; i < aw_chunk.size(); ++i ) {

          CHECK( aw[i] == Approx( aw_chunk[i] ) );
        }
      } // THEN

      THEN( "the NXS array is correct" ) {

        decltype(auto) nxs_chunk = chunk.data().NXS();
        CHECK( nxs.size() == nxs_chunk.size() );
        for ( unsigned int i = 0; i < nxs_chunk.size(); ++i ) {

          CHECK( nxs[i] == Approx( nxs_chunk[i] ) );
        }
      } // THEN

      THEN( "the JXS array is correct" ) {

        decltype(auto) jxs_chunk = chunk.data().JXS();
        CHECK( jxs.size() == jxs_chunk.size() );
        for ( unsigned int i = 0; i < jxs_chunk.size(); ++i ) {

          CHECK( jxs[i] == Approx( jxs_chunk[i] ) );
        }
      } // THEN

      THEN( "the XSS array is correct" ) {

        decltype(auto) xss_chunk = chunk.data().XSS();
        CHECK( xss.size() == xss_chunk.size() );
        for ( unsigned int i = 0; i < xss_chunk.size(); ++i ) {

          CHECK( xss[i] == Approx( xss_chunk[i] ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

void verifyChunk( const DosimetryTable& chunk ) {

  CHECK( "13027.24y" == chunk.ZAID() );
  CHECK( 26.75 == Approx( chunk.AWR() ) );
  CHECK( 26.75 == Approx( chunk.atomicWeightRatio() ) );
  CHECK( 0. == Approx( chunk.TEMP() ) );
  CHECK( 0. == Approx( chunk.temperature() ) );

  CHECK( "" == chunk.date() );

  CHECK( 1164 == chunk.length() );
  CHECK( 13027 == chunk.ZA() );
  CHECK( 2 == chunk.NTR() );
  CHECK( 2 == chunk.numberReactions() );

  // MTR block
  CHECK( false == chunk.MTR().empty() );
  CHECK( 2 == chunk.MTR().MTs().size() );
  CHECK( 103 == chunk.MTR().MTs().front() );
  CHECK( 107 == chunk.MTR().MTs().back() );
  CHECK( 2 == chunk.MTR().reactionNumbers().size() );
  CHECK( 103 == chunk.MTR().reactionNumbers().front() );
  CHECK( 107 == chunk.MTR().reactionNumbers().back() );

  CHECK( 103 == chunk.MTR().MT( 1 ) );
  CHECK( 107 == chunk.MTR().MT( 2 ) );
  CHECK( 103 == chunk.MTR().reactionNumber( 1 ) );
  CHECK( 107 == chunk.MTR().reactionNumber( 2 ) );

  CHECK( true == chunk.MTR().hasReactionNumber( 103 ) );
  CHECK( true == chunk.MTR().hasReactionNumber( 107 ) );
  CHECK( 1 == chunk.MTR().index( 103 ) );
  CHECK( 2 == chunk.MTR().index( 107 ) );

  // SIGD block
  CHECK( false == chunk.SIGD().empty() );
  CHECK( 2 == chunk.SIGD().NTR() );

  CHECK( 1 == chunk.SIGD().LSIG( 1 ) );
  CHECK( 615 == chunk.SIGD().LSIG( 2 ) );
  CHECK( 1 == chunk.SIGD().crossSectionLocator( 1 ) );
  CHECK( 615 == chunk.SIGD().crossSectionLocator( 2 ) );

  auto xs1 = chunk.SIGD().crossSectionData( 1 );
  auto xs2 = chunk.SIGD().crossSectionData( 2 );
  CHECK( 306 == xs1.numberEnergyPoints() );
  CHECK( 272 == xs2.numberEnergyPoints() );
  CHECK( 1.8961 == Approx( xs1.energies().front() ) );
  CHECK( 20. == Approx( xs1.energies().back() ) );
  CHECK( 3.248700000000E+00 == Approx( xs2.energies().front() ) );
  CHECK( 20. == Approx( xs2.energies().back() ) );
  CHECK( 0. == Approx( xs1.crossSections().front() ) );
  CHECK( 0.0322 == Approx( xs1.crossSections().back() ) );
  CHECK( 0. == Approx( xs2.crossSections().front() ) );
  CHECK( 0.038 == Approx( xs2.crossSections().back() ) );
}
