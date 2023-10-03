# standard imports
import unittest

# third party imports

# local imports
from ACEtk.continuous import CrossSectionData

class Test_ACEtk_continuous_CrossSectionData( unittest.TestCase ) :
    """Unit test for the CrossSectionData class."""

    chunk = [                 1,
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
              2.78785100000E-05, 2.76609500000E-05, 2.74425900000E-05, 2.72235400000E-05 ]

    def test_component( self ) :

        def verify_chunk( self, chunk ) :

            # verify content
            self.assertEqual( False, chunk.empty )
            self.assertEqual( 101, chunk.length )
            self.assertEqual( "CrossSectionData", chunk.name )

            self.assertEqual( 1, chunk.energy_index )
            self.assertEqual( 99, chunk.number_values )

            self.assertEqual( 99, len( chunk.cross_sections ) )
            self.assertAlmostEqual( 17.17401, chunk.cross_sections[0] )
            self.assertAlmostEqual( 2.72235400000E-05, chunk.cross_sections[-1] )

            # verify the xss array
            xss = chunk.xss_array
            for index in range( chunk.length ) :

                self.assertAlmostEqual( self.chunk[index], xss[index] )

        # the data is given explicitly
        chunk = CrossSectionData(
                    index = 1,
                    values = [                    1.71740100000E+01, 1.21438600000E+01, 7.68045500000E+00,
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
                               2.78785100000E-05, 2.76609500000E-05, 2.74425900000E-05, 2.72235400000E-05 ] )

        verify_chunk( self, chunk )

if __name__ == '__main__' :

    unittest.main()
