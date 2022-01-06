#ifndef NJOY_ACETK_BLOCK_DELAYEDNEUTRONPRECURSORBLOCK
#define NJOY_ACETK_BLOCK_DELAYEDNEUTRONPRECURSORBLOCK

// system includes

// other includes
#include "ACEtk/block/DelayedNeutronPrecursorData.hpp"
#include "ACEtk/block/details/Base.hpp"

namespace njoy {
namespace ACEtk {
namespace block {

/**
 *  @class
 *  @brief The continuous energy BDD block with the delayed neutron precursor
 *         data
 *
 *  The number of precursor groups is stored in NXS(8).
 */
class DelayedNeutronPrecursorBlock : protected details::Base {

  /* fields */
  unsigned int npcr_;
  std::vector< DelayedNeutronPrecursorData > data_;

  /* auxiliary functions */
  #include "ACEtk/block/DelayedNeutronPrecursorBlock/src/generateXSS.hpp"
  #include "ACEtk/block/DelayedNeutronPrecursorBlock/src/generateBlocks.hpp"
  #include "ACEtk/block/DelayedNeutronPrecursorBlock/src/verifyGroupIndex.hpp"

public:

  /* constructor */
  #include "ACEtk/block/DelayedNeutronPrecursorBlock/src/ctor.hpp"

  /* methods */

  /**
   *  @brief Return the number of delayed neutron precursor groups
   */
  unsigned int NPCR() const { return this->npcr_; }

  /**
   *  @brief Return the number of delayed neutron precursor groups
   */
  unsigned int numberPrecursorGroups() const {

    return this->NPCR();
  }

  /**
   *  @brief Return the precursor data
   */
  const std::vector< DelayedNeutronPrecursorData >& data() const {

    return this->data_;
  }

  /**
   *  @brief Return the precursor group data for a precursor group index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  const DelayedNeutronPrecursorData& precursorGroup( std::size_t index ) const {

    #ifndef NDEBUG
    this->verifyGroupIndex( index );
    #endif
    return this->data_[ index - 1 ];
  }

  using Base::empty;
  using Base::name;
  using Base::length;
  using Base::XSS;
  using Base::begin;
  using Base::end;
};

using BDD = DelayedNeutronPrecursorBlock;

} // block namespace
} // ACEtk namespace
} // njoy namespace

#endif
