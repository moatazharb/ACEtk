#ifndef NJOY_ACETK_BLOCK_CROSSSECTIONBLOCK
#define NJOY_ACETK_BLOCK_CROSSSECTIONBLOCK

// system includes

// other includes
#include "ACEtk/block/details/BaseCrossSectionBlock.hpp"
#include "ACEtk/block/CrossSectionData.hpp"

namespace njoy {
namespace ACEtk {
namespace block {

/**
 *  @class
 *  @brief The continuous energy LSIG and SIG block with the cross section data
 *
 *  The CrossSectionBlock class contains NXS(4) sets of cross section values,
 *  one for each reaction number on the MTR block. The order of these cross
 *  section data sets is the same as the order of the reaction numbers in the
 *  MTR block.
 */
class CrossSectionBlock :
    protected details::BaseCrossSectionBlock< CrossSectionBlock,
                                              CrossSectionData > {

  friend class details::BaseCrossSectionBlock< CrossSectionBlock,
                                               CrossSectionData >;

  /* fields */

  /* auxiliary functions */

public:

  /* constructor */
  #include "ACEtk/block/CrossSectionBlock/src/ctor.hpp"

  /* methods */

  /**
   *  @brief Return the number of available reactions (excluding elastic)
   */
  unsigned int NTR() const { return BaseCrossSectionBlock::NTR(); }

  /**
   *  @brief Return the number of available reactions (excluding elastic)
   */
  unsigned int numberReactions() const {

    return BaseCrossSectionBlock::numberReactions();
  }

  /**
   *  @brief Return the relative cross section locator for a reaction index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  std::size_t LSIG( std::size_t index ) const {

    return BaseCrossSectionBlock::LSIG( index );
  }

  /**
   *  @brief Return the relative cross section locator for a reaction index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  std::size_t crossSectionLocator( std::size_t index ) const {

    return BaseCrossSectionBlock::crossSectionLocator( index );
  }

  /**
   *  @brief Return the cross section data for a reaction index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  const CrossSectionData& crossSectionData( std::size_t index ) const {

    return BaseCrossSectionBlock::crossSectionData( index );
  }

  /**
   *  @brief Return the energy index for a reaction index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  std::size_t energyIndex( std::size_t index ) const {

    // sig : one-based index to the start of the SIG block
    // sig + locator - 1 : one-based index to the energy index
    std::size_t sig = std::distance( this->begin(), this->sig() ) + 1;
    return XSS( sig + this->LSIG( index ) - 1 );
  }

  /**
   *  @brief Return the number of cross section values for a reaction index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  std::size_t numberValues( std::size_t index ) const {

    // sig : one-based index to the start of the SIG block
    // sig + locator - 1 + 1 : one-based index to the number of values
    auto sig = std::distance( this->begin(), this->sig() ) + 1;
    return XSS( sig + this->LSIG( index ) );
  }

  /**
   *  @brief Return the cross section values for a reaction index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  auto crossSections( std::size_t index ) const {

    // sig : one-based index to the start of the SIG block
    // sig + locator - 1 + 2 : one-based index to the first cross section value
    auto locator = this->LSIG( index );
    auto sig = std::distance( this->begin(), this->sig() ) + 1;
    return XSS( sig + locator + 1,
                static_cast< std::size_t >( XSS( sig + locator ) ) );
  }

  using BaseCrossSectionBlock::empty;
  using BaseCrossSectionBlock::name;
  using BaseCrossSectionBlock::length;
  using BaseCrossSectionBlock::XSS;
  using BaseCrossSectionBlock::begin;
  using BaseCrossSectionBlock::end;
};

using SIG = CrossSectionBlock;

} // block namespace
} // ACEtk namespace
} // njoy namespace

#endif
