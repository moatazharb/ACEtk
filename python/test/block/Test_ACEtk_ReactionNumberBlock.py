# standard imports
import unittest

# third party imports

# local imports
from ACEtk import ReactionNumberBlock

class Test_ACEtk_ReactionNumberBlock( unittest.TestCase ) :
    """Unit test for the ReactionNumberBlock class."""

    def test_component( self ) :

        def verify_chunk( self, chunk ) :

            # verify content
            self.assertEqual( False, chunk.empty )
            self.assertEqual( 3, chunk.length )
            self.assertEqual( "MTR", chunk.name )

            self.assertEqual( 3, chunk.NTR )
            self.assertEqual( 3, chunk.number_reactions )

            self.assertEqual( 102, chunk.MT(1) )
            self.assertEqual( 204, chunk.MT(2) )
            self.assertEqual( 444, chunk.MT(3) )

            self.assertEqual( 3, len( chunk.MTs ) )
            self.assertEqual( 102, chunk.MTs[0] )
            self.assertEqual( 204, chunk.MTs[1] )
            self.assertEqual( 444, chunk.MTs[2] )

            self.assertEqual( True, chunk.has_MT(102) )
            self.assertEqual( True, chunk.has_MT(204) )
            self.assertEqual( True, chunk.has_MT(444) )
            self.assertEqual( False, chunk.has_MT(1) )

            self.assertEqual( 1, chunk.index(102) )
            self.assertEqual( 2, chunk.index(204) )
            self.assertEqual( 3, chunk.index(444) )

            with self.assertRaises( Exception ) :

                index = chunk.index(1)

        # the data is given explicitly
        chunk = ReactionNumberBlock( reactions = [ 102, 204, 444 ] )

        verify_chunk( self, chunk )

if __name__ == '__main__' :

    unittest.main()
