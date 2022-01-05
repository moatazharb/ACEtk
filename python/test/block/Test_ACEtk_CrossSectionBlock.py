# standard imports
import unittest

# third party imports

# local imports
from ACEtk import CrossSectionBlock
from ACEtk import CrossSectionData

class Test_ACEtk_CrossSectionBlock( unittest.TestCase ) :
    """Unit test for the CrossSectionBlock class."""

    chunk = [                 1,               102,               203,                 1,
                             99, 1.71740100000E+01, 1.21438600000E+01, 7.68045500000E+00,
              5.43090500000E+00, 3.84022400000E+00, 2.42878300000E+00, 1.71741500000E+00,
              1.21440300000E+00, 7.68079300000E-01, 5.43155100000E-01, 3.84154600000E-01,
              3.41606100000E-01, 2.43218100000E-01, 1.72502100000E-01, 1.23265800000E-01,
              7.76319400000E-02, 5.42665800000E-02, 3.83593600000E-02, 2.41345500000E-02,
              1.69157900000E-02, 1.19330400000E-02, 7.52588100000E-03, 5.30147700000E-03,
              3.74241900000E-03, 2.35974500000E-03, 1.66085400000E-03, 1.16578800000E-03,
              8.12732500000E-04, 7.21302100000E-04, 6.54483800000E-04, 5.59372400000E-04,
              4.93876600000E-04, 3.90771200000E-04, 3.28387200000E-04, 2.08326100000E-04,
              1.81663500000E-04, 1.55085200000E-04, 1.24126000000E-04, 1.03786200000E-04,
              7.45175200000E-05, 5.92842800000E-05, 4.46076700000E-05, 3.82766600000E-05,
              3.52914400000E-05, 3.38996200000E-05, 3.33423900000E-05, 3.32443400000E-05,
              3.34022300000E-05, 3.36990500000E-05, 3.44554600000E-05, 3.52169900000E-05,
              3.58729500000E-05, 3.63894900000E-05, 3.67662300000E-05, 3.70168600000E-05,
              3.71598700000E-05, 3.72143000000E-05, 3.71976900000E-05, 3.71253600000E-05,
              3.70102000000E-05, 3.68628700000E-05, 3.66920200000E-05, 3.65045600000E-05,
              3.63059900000E-05, 3.61006300000E-05, 3.58918300000E-05, 3.56821800000E-05,
              3.54736400000E-05, 3.52677000000E-05, 3.47705000000E-05, 3.43050800000E-05,
              3.38741800000E-05, 3.34769900000E-05, 3.31108400000E-05, 3.27723300000E-05,
              3.24578800000E-05, 3.21640000000E-05, 3.18874900000E-05, 3.16254500000E-05,
              3.13753100000E-05, 3.11348500000E-05, 3.09021400000E-05, 3.06755200000E-05,
              3.04536000000E-05, 3.02351800000E-05, 3.00192800000E-05, 2.98050700000E-05,
              2.95919000000E-05, 2.93792000000E-05, 2.91665600000E-05, 2.89536300000E-05,
              2.87401800000E-05, 2.85260300000E-05, 2.83110700000E-05, 2.80952300000E-05,
              2.78785100000E-05, 2.76609500000E-05, 2.74425900000E-05, 2.72235400000E-05,
                              1,                99, 1.81740100000E+01, 1.21438600000E+01,
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
              2.72235400000E-05,                 1,                99, 9.02129200000E-03,
              6.37901700000E-03, 4.03444700000E-03, 2.85278600000E-03, 2.01722200000E-03,
              1.27580900000E-03, 9.02136700000E-04, 6.37910900000E-04, 4.03462800000E-04,
              2.85313200000E-04, 2.01792500000E-04, 1.79442400000E-04, 1.27760800000E-04,
              9.06151300000E-05, 6.47527500000E-05, 4.07834500000E-05, 2.85116500000E-05,
              2.01583100000E-05, 1.26911300000E-05, 8.90464100000E-06, 6.29502700000E-06,
              2.62139000000E-04, 6.08933100000E-04, 1.14370500000E-03, 2.32575300000E-03,
              3.61758400000E-03, 5.14149800000E-03, 6.66476200000E-03, 7.11019200000E-03,
              7.44789100000E-03, 7.91944200000E-03, 8.22581200000E-03, 8.62713300000E-03,
              8.77329100000E-03, 8.59246800000E-03, 8.38871000000E-03, 8.12703600000E-03,
              7.65201300000E-03, 7.21597900000E-03, 6.32249800000E-03, 5.65383500000E-03,
              4.73362300000E-03, 4.13055600000E-03, 3.70232700000E-03, 3.38023300000E-03,
              3.12741300000E-03, 2.92238200000E-03, 2.75177900000E-03, 2.60686600000E-03,
              2.37196900000E-03, 2.18761400000E-03, 2.03735400000E-03, 1.91138400000E-03,
              1.80347700000E-03, 1.70946300000E-03, 1.62643600000E-03, 1.55229800000E-03,
              1.48549100000E-03, 1.42482600000E-03, 1.36937900000E-03, 1.31842000000E-03,
              1.27135700000E-03, 1.22770800000E-03, 1.18707600000E-03, 1.14912500000E-03,
              1.11357300000E-03, 1.08018200000E-03, 1.04874100000E-03, 1.01907500000E-03,
              9.51686300000E-04, 8.92477300000E-04, 8.39981400000E-04, 7.93086200000E-04,
              7.50915800000E-04, 7.12777900000E-04, 6.78112800000E-04, 6.46463600000E-04,
              6.17451100000E-04, 5.90759700000E-04, 5.66122200000E-04, 5.43311400000E-04,
              5.22133100000E-04, 5.02419500000E-04, 4.84025100000E-04, 4.66823400000E-04,
              4.50703000000E-04, 4.35566200000E-04, 4.21326600000E-04, 4.07907500000E-04,
              3.95240400000E-04, 3.83264400000E-04, 3.71924700000E-04, 3.61171900000E-04,
              3.50961800000E-04, 3.41254200000E-04, 3.32012800000E-04, 3.23204500000E-04,
              3.14799100000E-04, 3.06769500000E-04 ]

    def test_component( self ) :

        def verify_chunk( self, chunk ) :

            # verify content
            self.assertEqual( False, chunk.empty )
            self.assertEqual( 306, chunk.length )
            self.assertEqual( "SIG", chunk.name )

            self.assertEqual( 3, chunk.NTR )
            self.assertEqual( 3, chunk.number_reactions )
            self.assertEqual( 3, len( chunk.data ) )

            self.assertEqual( 1, chunk.LSIG(1) )
            self.assertEqual( 102, chunk.LSIG(2) )
            self.assertEqual( 203, chunk.LSIG(3) )
            self.assertEqual( 1, chunk.cross_section_locator(1) )
            self.assertEqual( 102, chunk.cross_section_locator(2) )
            self.assertEqual( 203, chunk.cross_section_locator(3) )

            self.assertEqual( 1, chunk.energy_index(1) )
            self.assertEqual( 99, chunk.number_values(1) )
            array = chunk.cross_sections(1)
            self.assertEqual( 99, len( array ) )
            self.assertEqual( 17.17401, array[0] )
            self.assertEqual( 2.72235400000E-05, array[-1] )

            self.assertEqual( 1, chunk.energy_index(2) )
            self.assertEqual( 99, chunk.number_values(2) )
            array = chunk.cross_sections(2)
            self.assertEqual( 99, len( array ) )
            self.assertEqual( 18.17401, array[0] )
            self.assertEqual( 2.72235400000E-05, array[-1] )

            self.assertEqual( 1, chunk.energy_index(3) )
            self.assertEqual( 99, chunk.number_values(3) )
            array = chunk.cross_sections(3)
            self.assertEqual( 99, len( array ) )
            self.assertEqual( 9.02129200000E-03, array[0] )
            self.assertEqual( 3.06769500000E-04, array[-1] )

            xs = chunk.cross_section_data(1)
            self.assertEqual( 1, xs.energy_index )
            self.assertEqual( 99, xs.number_values )
            self.assertEqual( 99, len( xs.cross_sections ) )
            self.assertEqual( 17.17401, xs.cross_sections[0] )
            self.assertEqual( 2.72235400000E-05, xs.cross_sections[-1] )

            xs = chunk.cross_section_data(2)
            self.assertEqual( 1, xs.energy_index )
            self.assertEqual( 99, xs.number_values )
            self.assertEqual( 99, len( xs.cross_sections ) )
            self.assertEqual( 18.17401, xs.cross_sections[0] )
            self.assertEqual( 2.72235400000E-05, xs.cross_sections[-1] )

            xs = chunk.cross_section_data(3)
            self.assertEqual( 1, xs.energy_index )
            self.assertEqual( 99, xs.number_values )
            self.assertEqual( 99, len( xs.cross_sections ) )
            self.assertEqual( 9.02129200000E-03, xs.cross_sections[0] )
            self.assertEqual( 3.06769500000E-04, xs.cross_sections[-1] )

            xs = chunk.data[0]
            self.assertEqual( 1, xs.energy_index )
            self.assertEqual( 99, xs.number_values )
            self.assertEqual( 99, len( xs.cross_sections ) )
            self.assertEqual( 17.17401, xs.cross_sections[0] )
            self.assertEqual( 2.72235400000E-05, xs.cross_sections[-1] )

            xs = chunk.data[1]
            self.assertEqual( 1, xs.energy_index )
            self.assertEqual( 99, xs.number_values )
            self.assertEqual( 99, len( xs.cross_sections ) )
            self.assertEqual( 18.17401, xs.cross_sections[0] )
            self.assertEqual( 2.72235400000E-05, xs.cross_sections[-1] )

            xs = chunk.data[2]
            self.assertEqual( 1, xs.energy_index )
            self.assertEqual( 99, xs.number_values )
            self.assertEqual( 99, len( xs.cross_sections ) )
            self.assertEqual( 9.02129200000E-03, xs.cross_sections[0] )
            self.assertEqual( 3.06769500000E-04, xs.cross_sections[-1] )

            # verify the xss array
            xss = chunk.xss_array
            for index in range( chunk.length ) :

                self.assertAlmostEqual( self.chunk[index], xss[index] )

        # the data is given explicitly
        chunk = CrossSectionBlock(
                  xs = [ CrossSectionData(
                           1,
                           [ 1.71740100000E+01, 1.21438600000E+01, 7.68045500000E+00,
                             5.43090500000E+00, 3.84022400000E+00, 2.42878300000E+00, 1.71741500000E+00,
                             1.21440300000E+00, 7.68079300000E-01, 5.43155100000E-01, 3.84154600000E-01,
                             3.41606100000E-01, 2.43218100000E-01, 1.72502100000E-01, 1.23265800000E-01,
                             7.76319400000E-02, 5.42665800000E-02, 3.83593600000E-02, 2.41345500000E-02,
                             1.69157900000E-02, 1.19330400000E-02, 7.52588100000E-03, 5.30147700000E-03,
                             3.74241900000E-03, 2.35974500000E-03, 1.66085400000E-03, 1.16578800000E-03,
                             8.12732500000E-04, 7.21302100000E-04, 6.54483800000E-04, 5.59372400000E-04,
                             4.93876600000E-04, 3.90771200000E-04, 3.28387200000E-04, 2.08326100000E-04,
                             1.81663500000E-04, 1.55085200000E-04, 1.24126000000E-04, 1.03786200000E-04,
                             7.45175200000E-05, 5.92842800000E-05, 4.46076700000E-05, 3.82766600000E-05,
                             3.52914400000E-05, 3.38996200000E-05, 3.33423900000E-05, 3.32443400000E-05,
                             3.34022300000E-05, 3.36990500000E-05, 3.44554600000E-05, 3.52169900000E-05,
                             3.58729500000E-05, 3.63894900000E-05, 3.67662300000E-05, 3.70168600000E-05,
                             3.71598700000E-05, 3.72143000000E-05, 3.71976900000E-05, 3.71253600000E-05,
                             3.70102000000E-05, 3.68628700000E-05, 3.66920200000E-05, 3.65045600000E-05,
                             3.63059900000E-05, 3.61006300000E-05, 3.58918300000E-05, 3.56821800000E-05,
                             3.54736400000E-05, 3.52677000000E-05, 3.47705000000E-05, 3.43050800000E-05,
                             3.38741800000E-05, 3.34769900000E-05, 3.31108400000E-05, 3.27723300000E-05,
                             3.24578800000E-05, 3.21640000000E-05, 3.18874900000E-05, 3.16254500000E-05,
                             3.13753100000E-05, 3.11348500000E-05, 3.09021400000E-05, 3.06755200000E-05,
                             3.04536000000E-05, 3.02351800000E-05, 3.00192800000E-05, 2.98050700000E-05,
                             2.95919000000E-05, 2.93792000000E-05, 2.91665600000E-05, 2.89536300000E-05,
                             2.87401800000E-05, 2.85260300000E-05, 2.83110700000E-05, 2.80952300000E-05,
                             2.78785100000E-05, 2.76609500000E-05, 2.74425900000E-05, 2.72235400000E-05 ] ),
                         CrossSectionData(
                           1,
                           [ 1.81740100000E+01, 1.21438600000E+01,
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
                             2.72235400000E-05 ] ),
                         CrossSectionData(
                           1,
                           [ 9.02129200000E-03,
                             6.37901700000E-03, 4.03444700000E-03, 2.85278600000E-03, 2.01722200000E-03,
                             1.27580900000E-03, 9.02136700000E-04, 6.37910900000E-04, 4.03462800000E-04,
                             2.85313200000E-04, 2.01792500000E-04, 1.79442400000E-04, 1.27760800000E-04,
                             9.06151300000E-05, 6.47527500000E-05, 4.07834500000E-05, 2.85116500000E-05,
                             2.01583100000E-05, 1.26911300000E-05, 8.90464100000E-06, 6.29502700000E-06,
                             2.62139000000E-04, 6.08933100000E-04, 1.14370500000E-03, 2.32575300000E-03,
                             3.61758400000E-03, 5.14149800000E-03, 6.66476200000E-03, 7.11019200000E-03,
                             7.44789100000E-03, 7.91944200000E-03, 8.22581200000E-03, 8.62713300000E-03,
                             8.77329100000E-03, 8.59246800000E-03, 8.38871000000E-03, 8.12703600000E-03,
                             7.65201300000E-03, 7.21597900000E-03, 6.32249800000E-03, 5.65383500000E-03,
                             4.73362300000E-03, 4.13055600000E-03, 3.70232700000E-03, 3.38023300000E-03,
                             3.12741300000E-03, 2.92238200000E-03, 2.75177900000E-03, 2.60686600000E-03,
                             2.37196900000E-03, 2.18761400000E-03, 2.03735400000E-03, 1.91138400000E-03,
                             1.80347700000E-03, 1.70946300000E-03, 1.62643600000E-03, 1.55229800000E-03,
                             1.48549100000E-03, 1.42482600000E-03, 1.36937900000E-03, 1.31842000000E-03,
                             1.27135700000E-03, 1.22770800000E-03, 1.18707600000E-03, 1.14912500000E-03,
                             1.11357300000E-03, 1.08018200000E-03, 1.04874100000E-03, 1.01907500000E-03,
                             9.51686300000E-04, 8.92477300000E-04, 8.39981400000E-04, 7.93086200000E-04,
                             7.50915800000E-04, 7.12777900000E-04, 6.78112800000E-04, 6.46463600000E-04,
                             6.17451100000E-04, 5.90759700000E-04, 5.66122200000E-04, 5.43311400000E-04,
                             5.22133100000E-04, 5.02419500000E-04, 4.84025100000E-04, 4.66823400000E-04,
                             4.50703000000E-04, 4.35566200000E-04, 4.21326600000E-04, 4.07907500000E-04,
                             3.95240400000E-04, 3.83264400000E-04, 3.71924700000E-04, 3.61171900000E-04,
                             3.50961800000E-04, 3.41254200000E-04, 3.32012800000E-04, 3.23204500000E-04,
                             3.14799100000E-04, 3.06769500000E-04 ] ) ] )

        verify_chunk( self, chunk )

if __name__ == '__main__' :

    unittest.main()
