#ifndef NJOY_ACETK_BLOCK_PHOTOATOMICFLUORESCENCEDATABLOCK
#define NJOY_ACETK_BLOCK_PHOTOATOMICFLUORESCENCEDATABLOCK

// system includes

// other includes
#include "ACEtk/block/details/ArrayData.hpp"

namespace njoy {
namespace ACEtk {
namespace block {

/**
 *  @class
 *  @brief The photoatomic JFLO block with the fluorescence data
 *
 *  The PhotoatomicFluorescenceDataBlock class contains 4 arrays of the
 *  same length:
 *    - the fluoresence edge energies
 *    - the relative ejection probabilities
 *    - the yields
 *    - the fluorescent energies
 *
 *  The size of each (the total number of fluorescence edges) is stored in NXS(4).
 */
class PhotoatomicFluorescenceDataBlock : protected details::ArrayData {

  /* fields */

  /* auxiliary functions */

public:

  /* constructor */
  #include "ACEtk/block/PhotoatomicFluorescenceDataBlock/src/ctor.hpp"

  /**
   *  @brief Return the number of fluorescence edges
   */
  unsigned int NFLO() const { return this->N(); }

  /**
   *  @brief Return the number of fluorescence edges
   */
  unsigned int numberFluorescenceEdges() const { return this->NFLO(); }

  /**
   *  @brief Return the fluoresence edge energies
   */
  auto E() const { return this->array( 1 ); }

  /**
   *  @brief Return the fluoresence edge energies
   */
  auto fluorescenceEdgeEnergies() const { return this->E(); }

  /**
   *  @brief Return the relative ejection probabilities
   */
  auto PHI() const { return this->array( 2 ); }

  /**
   *  @brief Return the relative ejection probabilities
   */
  auto relativeEjectionProbabilities() const { return this->PHI(); }

  /**
   *  @brief Return the yields
   */
  auto Y() const { return this->array( 3 ); }

  /**
   *  @brief Return the yields
   */
  auto yields() const { return this->Y(); }

  /**
   *  @brief Return the fluorescent energies
   */
  auto F() const { return this->array( 4 ); }

  /**
   *  @brief Return the fluorescent energies
   */
  auto fluorescentEnergies() const { return this->F(); }

  using ArrayData::empty;
  using ArrayData::name;
  using ArrayData::length;
  using ArrayData::XSS;
  using ArrayData::begin;
  using ArrayData::end;
};

using JFLO = PhotoatomicFluorescenceDataBlock;

} // block namespace
} // ACEtk namespace
} // njoy namespace

#endif
