// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "ACEtk/continuous/GeneralEvaporationSpectrum.hpp"
#include "views.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace continuous {

void wrapGeneralEvaporationSpectrum( python::module& module, python::module& ) {

  // type aliases
  using Block = njoy::ACEtk::continuous::GeneralEvaporationSpectrum;

  // wrap views created by this block

  // create the block
  python::class_< Block > block(

    module,
    "GeneralEvaporationSpectrum",
    "A general evaporation spectrum\n\n"
    "The GeneralEvaporationSpectrum class contains the tabulated energy and\n"
    "temperature values as well as the bin date used to describe the\n"
    "general evaporation spectrum. It is used in the DLW block as ACE LAW 5."
  );

  // wrap the block
  block
  .def(

    python::init< std::vector< long >, std::vector< long >,
                  std::vector< double >, std::vector< double >,
                  std::vector< double > >(),
    python::arg( "boundaries" ), python::arg( "interpolants" ),
    python::arg( "energies" ), python::arg( "temperatures" ),
    python::arg( "bins" ),
    "Initialise the block\n\n"
    "Arguments:\n"
    "    self            the block\n"
    "    boundaries      the interpolation range boundaries\n"
    "    interpolants    the interpolation types for each range\n"
    "    energies        the energy values\n"
    "    temperatures    the temperature values\n"
    "    bins            the x bin values"
  )
  .def(

    python::init< std::vector< double >, std::vector< double >,
                  std::vector< double > >(),
    python::arg( "energies" ), python::arg( "temperatures" ),
    python::arg( "bins" ),
    "Initialise the block without interpolation data\n\n"
    "Arguments:\n"
    "    self            the block\n"
    "    energies        the energy values\n"
    "    temperatures    the temperature values\n"
    "    bins            the x bin values"
  )
  .def_property_readonly(

    "LAW",
    [] ( const Block& self ) { return self.LAW(); },
    "The distribution type"
  )
  .def_property_readonly(

    "type",
    [] ( const Block& self ) { return self.type(); },
    "The distribution type"
  )
  .def_property_readonly(

    "interpolation_data",
    &Block::interpolationData,
    "The interpolation data"
  )
  .def_property_readonly(

    "NB",
    &Block::NB,
    "The number of interpolation regions"
  )
  .def_property_readonly(

    "number_interpolation_regions",
    &Block::numberInterpolationRegions,
    "The number of interpolation regions"
  )
  .def_property_readonly(

    "NBT",
    [] ( const Block& self ) -> LongRange
       { return self.NBT(); },
    "The interpolation boundaries"
  )
  .def_property_readonly(

    "boundaries",
    [] ( const Block& self ) -> LongRange
       { return self.boundaries(); },
    "The interpolation boundaries"
  )
  .def_property_readonly(

    "INT",
    [] ( const Block& self ) -> LongRange
       { return self.INT(); },
    "The interpolation type for each range"
  )
  .def_property_readonly(

    "interpolants",
    [] ( const Block& self ) -> LongRange
       { return self.interpolants(); },
    "The interpolation type for each range"
  )
  .def_property_readonly(

    "NE",
    &Block::NE,
    "The number of incident energy values"
  )
  .def_property_readonly(

    "number_energy_points",
    &Block::numberEnergyPoints,
    "The number of incident energy values"
  )
  .def_property_readonly(

    "energies",
    [] ( const Block& self ) -> DoubleRange
       { return self.energies(); },
    "The incident energy values"
  )
  .def_property_readonly(

    "temperatures",
    [] ( const Block& self ) -> DoubleRange
       { return self.temperatures(); },
    "The temperature values"
  )
  .def_property_readonly(

    "minimum_incident_energy",
    &Block::minimumIncidentEnergy,
    "The minimum incident energy for the distribution"
  )
  .def_property_readonly(

    "maximum_incident_energy",
    &Block::maximumIncidentEnergy,
    "The maximum incident energy for the distribution"
  )
  .def_property_readonly(

    "NET",
    &Block::NET,
    "The number of x values"
  )
  .def_property_readonly(

    "number_bins",
    &Block::numberBins,
    "The number of x bins"
  )
  .def_property_readonly(

    "bins",
    [] ( const Block& self ) -> DoubleRange
       { return self.bins(); },
    "The equiprobable x bins"
  );

  // add standard block definitions
  addStandardBlockDefinitions< Block >( block );
}

} // continuous namespace
