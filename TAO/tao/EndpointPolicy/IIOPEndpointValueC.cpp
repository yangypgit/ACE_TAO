// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// be/be_codegen.cpp:283


#include "tao/EndpointPolicy/IIOPEndpointValueC.h"
#include "tao/CDR.h"
#include "tao/Basic_Arguments.h"
#include "tao/UB_String_Arguments.h"
#include "ace/OS_NS_string.h"

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:70
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// Arg traits specializations.
namespace TAO
{
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:60

// Traits specializations for EndpointPolicy::IIOPEndpointValue.

EndpointPolicy::IIOPEndpointValue_ptr
TAO::Objref_Traits<EndpointPolicy::IIOPEndpointValue>::duplicate (
    EndpointPolicy::IIOPEndpointValue_ptr p
  )
{
  return EndpointPolicy::IIOPEndpointValue::_duplicate (p);
}

void
TAO::Objref_Traits<EndpointPolicy::IIOPEndpointValue>::release (
    EndpointPolicy::IIOPEndpointValue_ptr p
  )
{
  CORBA::release (p);
}

EndpointPolicy::IIOPEndpointValue_ptr
TAO::Objref_Traits<EndpointPolicy::IIOPEndpointValue>::nil (void)
{
  return EndpointPolicy::IIOPEndpointValue::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<EndpointPolicy::IIOPEndpointValue>::marshal (
    const EndpointPolicy::IIOPEndpointValue_ptr p,
    TAO_OutputCDR & cdr
  )
{
  return ::CORBA::Object::marshal (p, cdr);
}

EndpointPolicy::IIOPEndpointValue::IIOPEndpointValue (void)
{}

EndpointPolicy::IIOPEndpointValue::~IIOPEndpointValue (void)
{}

EndpointPolicy::IIOPEndpointValue_ptr
EndpointPolicy::IIOPEndpointValue::_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return IIOPEndpointValue::_duplicate (
      dynamic_cast<IIOPEndpointValue_ptr> (_tao_objref)
    );
}

EndpointPolicy::IIOPEndpointValue_ptr
EndpointPolicy::IIOPEndpointValue::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  return IIOPEndpointValue::_duplicate (
      dynamic_cast<IIOPEndpointValue_ptr> (_tao_objref)
    );
}

EndpointPolicy::IIOPEndpointValue_ptr
EndpointPolicy::IIOPEndpointValue::_duplicate (IIOPEndpointValue_ptr obj)
{
  if (! CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }

  return obj;
}

void
EndpointPolicy::IIOPEndpointValue::_tao_release (IIOPEndpointValue_ptr obj)
{
  CORBA::release (obj);
}

::CORBA::Boolean
EndpointPolicy::IIOPEndpointValue::_is_a (
    const char *value
    ACE_ENV_ARG_DECL_NOT_USED
  )
{
  if (
      !ACE_OS::strcmp (
          value,
          "IDL:EndpointPolicy/EndpointValueBase:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:EndpointPolicy/IIOPEndpointValue:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/LocalObject:1.0"
        ) ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return false;
    }
}

const char* EndpointPolicy::IIOPEndpointValue::_interface_repository_id (void) const
{
  return "IDL:EndpointPolicy/IIOPEndpointValue:1.0";
}

::CORBA::Boolean
EndpointPolicy::IIOPEndpointValue::marshal (TAO_OutputCDR &)
{
  return false;
}
