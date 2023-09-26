// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "ACEtk/block/PhotoatomicElectronElasticCrossSectionBlock.hpp"
#include "views.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace block {

void wrapPhotoatomicElectronElasticCrossSectionBlock( python::module& module, python::module& ) {

  // type aliases
  using Block = njoy::ACEtk::block::PhotoatomicElectronElasticCrossSectionBlock;

  // wrap views created by this block

  // create the block
  python::class_< Block > block(

    module,
    "PhotoatomicElectronElasticCrossSectionBlock",
    "The photoatomic SELAS block with the additional electron elastic cross section data\n\n"
    "This block is part of the eprdata14 format.\n\n"
    "The PhotoatomicElectronElasticCrossSectionBlock class contains 2 arrays\n"
    "of the same length:\n"
    "  - the transport elastic scattering cross section\n"
    "  - the total elastic scattering cross section\n\n"
    "The size NE of each (the total number of electron energy points) is stored in\n"
    "NXS(8)."
  );

  // wrap the block
  block
  .def(

    python::init< std::vector< double >, std::vector< double > >(),
    python::arg( "transport" ), python::arg( "total" ),
    "Initialise the block\n\n"
    "Arguments:\n"
    "    self         the block\n"
    "    transport    the transport elastic cross section values\n"
    "    total        the total elastic cross section values"
  )
  .def_property_readonly(

    "NE",
    &Block::NE,
    "The number of energy points"
  )
  .def_property_readonly(

    "number_energy_points",
    &Block::numberEnergyPoints,
    "The number of energy points"
  )
  .def_property_readonly(

    "transport",
    [] ( const Block& self ) -> DoubleRange
       { return self.transport(); },
    "The transport elastic cross section values"
  )
  .def_property_readonly(

    "total",
    [] ( const Block& self ) -> DoubleRange
       { return self.total(); },
    "The total elastic cross section values"
  );

  // add standard block definitions
  addStandardBlockDefinitions< Block >( block );
}

} // block namespace
