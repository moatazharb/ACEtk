// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "ACEtk/block/KalbachMannDistributionData.hpp"
#include "views.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace block {

void wrapKalbachMannDistributionData( python::module& module,
                                         python::module& ) {

  // type aliases
  using Block = njoy::ACEtk::block::KalbachMannDistributionData;
  using Distribution = njoy::ACEtk::block::TabulatedKalbachMannDistribution;

  // wrap views created by this block

  // create the block
  python::class_< Block > block(

    module,
    "KalbachMannDistributionData",
    "Convenience interface for outgoing energy distribution data from the\n"
    "DLW block for a single reaction using Kalbach-Mann systematics"
  );

  // wrap the block
  block
  .def(

    python::init< std::vector< Distribution >&&, std::size_t >(),
    python::arg( "distributions" ), python::arg( "locb" ) = 1,
    "Initialise the block\n\n"
    "Arguments:\n"
    "    self             the block\n"
    "    distributions    the distributions for each incident energy\n"
    "    locb             the starting xss index with respect to the DLW block\n"
    "                     (default = 1, the relative locators get recalculated)"
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

    "NE",
    &Block::NE,
    "The number of incident energy values"
  )
  .def_property_readonly(

    "number_incident_energies",
    &Block::numberIncidentEnergies,
    "The number of incident energy values"
  )
  .def_property_readonly(

    "incident_energies",
    [] ( const Block& self ) -> DoubleRange
       { return self.incidentEnergies(); },
    "The incident energy values"
  )
  .def(

    "incident_energy",
    &Block::incidentEnergy,
    python::arg( "index" ),
    "Return the incident energy for a given index\n\n"
    "When the index is out of range an out of range exception is thrown\n"
    "(debug mode only).\n\n"
    "    self     the block\n"
    "    index    the index (one-based)"
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
  .def(

    "LOCC",
    &Block::LOCC,
    python::arg( "index" ),
    "Return the the distribution locator for an incident energy index\n\n"
    "This locator is the value as stored in the XSS array. It is relative to\n"
    "the beginning of the DLW block.\n\n"
    "When the index is out of range an out of range exception is thrown\n"
    "(debug mode only).\n\n"
    "    self     the block\n"
    "    index    the index (one-based)"
  )
  .def(

    "distribution_locator",
    &Block::distributionLocator,
    python::arg( "index" ),
    "Return the the distribution locator for an incident energy index\n\n"
    "This locator is the value as stored in the XSS array. It is relative to\n"
    "the beginning of the DLW block.\n\n"
    "When the index is out of range an out of range exception is thrown\n"
    "(debug mode only).\n\n"
    "    self     the block\n"
    "    index    the index (one-based)"
  )
  .def(

    "relative_distribution_locator",
    &Block::relativeDistributionLocator,
    python::arg( "index" ),
    "Return the relative distribution locator for an incident energy index\n\n"
    "This is the locator relative to the beginning of the current angular\n"
    "distribution block in the DLW block. It is always positive.\n\n"
    "When the index is out of range an out of range exception is thrown\n"
    "(debug mode only).\n\n"
    "    self     the block\n"
    "    index    the index (one-based)"
  )
  .def(

    "distribution",
    &Block::distribution,
    python::arg( "index" ),
    "Return the distribution data for an incident energy index\n\n"
    "When the index is out of range an out of range exception is thrown\n"
    "(debug mode only).\n\n"
    "    self     the block\n"
    "    index    the index (one-based)"
  );

  // add standard block definitions
  addStandardBlockDefinitions< Block >( block );
}

} // block namespace
