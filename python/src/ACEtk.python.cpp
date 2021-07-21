// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// other includes
#include "views.hpp"

// namespace aliases
namespace python = pybind11;

// declarations - generic ACE table
void wrapData( python::module&, python::module& );
void wrapTable( python::module&, python::module& );

// declarations - ACE table blocks
namespace block {

  void wrapPrincipalCrossSectionBlock( python::module&, python::module& );
}

/**
 *  @brief ACEtk python bindings
 *
 *  The name given here (ACEtk) must be the same as the name
 *  set on the PROPERTIES OUTPUT_NAME in the CMakeLists.txt file.
 */
PYBIND11_MODULE( ACEtk, module ) {

  // create the views submodule
  python::module viewmodule = module.def_submodule(

    "sequence",
    "sequence - ACE sequences (internal use only)"
  );

  // wrap some basic recurring views
  // none of these are supposed to be created directly by the user
  wrapBasicRandomAccessAnyViewOf< double >(
      viewmodule,
      "any_view< double, random_access >" );
  wrapBasicRandomAccessAnyViewOf< int >(
      viewmodule,
      "any_view< int, random_access >" );

  // wrap generic ACE table components
  wrapData( module, viewmodule );
  wrapTable( module, viewmodule );

  // wrap ACE table blocks
  block::wrapPrincipalCrossSectionBlock( module, viewmodule );
}
