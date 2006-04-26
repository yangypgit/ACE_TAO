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
// be/be_codegen.cpp:155

#ifndef _TAO_IDL_IIOPENDPOINTVALUEC_H_
#define _TAO_IDL_IIOPENDPOINTVALUEC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/EndpointPolicy/EndpointPolicy_Export.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "tao/Object.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Versioned_Namespace.h"

#include "tao/EndpointPolicy/EndpointPolicyC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_EndpointPolicy_Export

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:49

namespace EndpointPolicy
{

  // TAO_IDL - Generated from
  // be/be_interface.cpp:646

#if !defined (_ENDPOINTPOLICY_IIOPENDPOINTVALUE__VAR_OUT_CH_)
#define _ENDPOINTPOLICY_IIOPENDPOINTVALUE__VAR_OUT_CH_

  class IIOPEndpointValue;
  typedef IIOPEndpointValue *IIOPEndpointValue_ptr;

  typedef
    TAO_Objref_Var_T<
        IIOPEndpointValue
      >
    IIOPEndpointValue_var;

  typedef
    TAO_Objref_Out_T<
        IIOPEndpointValue
      >
    IIOPEndpointValue_out;

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:54

#if !defined (_ENDPOINTPOLICY_IIOPENDPOINTVALUE_CH_)
#define _ENDPOINTPOLICY_IIOPENDPOINTVALUE_CH_

  class TAO_EndpointPolicy_Export IIOPEndpointValue
    : public virtual ::EndpointPolicy::EndpointValueBase
  {
  public:
    typedef IIOPEndpointValue_ptr _ptr_type;
    typedef IIOPEndpointValue_var _var_type;

    // The static operations.
    static IIOPEndpointValue_ptr _duplicate (IIOPEndpointValue_ptr obj);

    static void _tao_release (IIOPEndpointValue_ptr obj);

    static IIOPEndpointValue_ptr _narrow (
        ::CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static IIOPEndpointValue_ptr _unchecked_narrow (
        ::CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    static IIOPEndpointValue_ptr _nil (void)
    {
      return static_cast<IIOPEndpointValue_ptr> (0);
    }



    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual char * host (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void host (
        const char * host
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual ::CORBA::UShort port (
        ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46

    virtual void port (
        ::CORBA::UShort port
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        ::CORBA::SystemException
      )) = 0;

    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:210

    virtual ::CORBA::Boolean _is_a (
        const char *type_id
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );

    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);

  protected:
    // Abstract or local interface only.
    IIOPEndpointValue (void);

    virtual ~IIOPEndpointValue (void);

  private:
    // Private and unimplemented for concrete interfaces.
    IIOPEndpointValue (const IIOPEndpointValue &);

    void operator= (const IIOPEndpointValue &);
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:78

} // module EndpointPolicy

// TAO_IDL - Generated from
// be/be_visitor_traits.cpp:62
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// Traits specializations.
namespace TAO
{

#if !defined (_ENDPOINTPOLICY_IIOPENDPOINTVALUE__TRAITS_)
#define _ENDPOINTPOLICY_IIOPENDPOINTVALUE__TRAITS_

  template<>
  struct TAO_EndpointPolicy_Export Objref_Traits< ::EndpointPolicy::IIOPEndpointValue>
  {
    static ::EndpointPolicy::IIOPEndpointValue_ptr duplicate (
        ::EndpointPolicy::IIOPEndpointValue_ptr
      );
    static void release (
        ::EndpointPolicy::IIOPEndpointValue_ptr
      );
    static ::EndpointPolicy::IIOPEndpointValue_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::EndpointPolicy::IIOPEndpointValue_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL

#include /**/ "ace/post.h"

#endif /* ifndef */
