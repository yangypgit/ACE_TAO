// $Id$

/* -*- C++ -*- */

// ******  Code generated by the The ACE ORB (TAO) IDL Compiler *******
// TAO ORB and the TAO IDL Compiler have been developed by Washington
// University Computer Science's Distributed Object Computing Group.
//
// Information on TAO is available at
//                 http://www.cs.wustl.edu/~schmidt/TAO.html

#include "tao/PolicyC.h"
#include "tao/Stub.h"
#include "tao/Servant_Base.h"
#include "tao/POA_CORBA.h"

#if !defined (__ACE_INLINE__)
#include "PolicyC.i"
#endif /* !defined INLINE */

ACE_RCSID(tao, PolicyC, "$Id$")

CORBA_Policy_ptr CORBA_Policy::_duplicate (CORBA_Policy_ptr obj)
{
  if (!CORBA::is_nil (obj))
    obj->_incr_refcnt ();

  return obj;
} // end of _duplicate

CORBA_Policy_ptr CORBA_Policy::_narrow (
    CORBA::Object_ptr obj,
    CORBA::Environment &env
  )
{
  if (CORBA::is_nil (obj))
    return CORBA_Policy::_nil ();
  if (!obj->_is_a ("IDL:CORBA/Policy:1.0", env))
    return CORBA_Policy::_nil ();
  STUB_Object *stub = obj->_stubobj ();
  stub->_incr_refcnt ();
  if (!obj->_is_collocated ()
         || !obj->_servant()
         || obj->_servant()->_downcast ("IDL:CORBA/Policy:1.0") == 0
      )
  {
    CORBA_Policy_ptr new_obj = new CORBA_Policy(stub);
    return new_obj;
  } // end of if
  void* servant = obj->_servant ()->_downcast ("IDL:CORBA/Policy:1.0");
  return new POA_CORBA::_tao_collocated_Policy(
      ACE_reinterpret_cast(POA_CORBA::Policy_ptr, servant),
      stub
    );
}

CORBA_Policy_ptr CORBA_Policy::_nil (void)
{
  return (CORBA_Policy_ptr)NULL;
} // end of _nil

CORBA::PolicyType CORBA_Policy::policy_type (
    CORBA::Environment &_tao_environment
   )
{
  static const TAO_Param_Data _get_CORBA_Policy_policy_type_paramdata [] =
  {
    {CORBA::_tc_PolicyType, PARAM_RETURN, 0}
  }; // CORBA_Policy_policy_type_paramdata

  static const TAO_Call_Data _get_CORBA_Policy_policy_type_calldata =
  {"_get_policy_type", 1, 1, _get_CORBA_Policy_policy_type_paramdata, 0, 0};

  CORBA::PolicyType _tao_retval = 0;
  STUB_Object *istub = this->_stubobj ();
  if (istub)
  {
    void* _tao_arguments[1];
    void** _tao_current_arg = _tao_arguments;
    *_tao_current_arg = &_tao_retval; _tao_current_arg++;
    istub->do_static_call (
      _tao_environment,
      &_get_CORBA_Policy_policy_type_calldata,
      _tao_arguments
    );
  } // end of if (istub)
  return _tao_retval;
}

CORBA_Policy_ptr CORBA_Policy::copy (
    CORBA::Environment &_tao_environment
   )
{
  static const TAO_Param_Data CORBA_Policy_copy_paramdata [] =
  {
    {CORBA::_tc_Policy, PARAM_RETURN, 0}
  }; // CORBA_Policy_copy_paramdata

  static const TAO_Call_Data CORBA_Policy_copy_calldata =
  {"copy", 1, 1, CORBA_Policy_copy_paramdata, 0, 0};

  CORBA_Policy_ptr _tao_retval = CORBA_Policy::_nil ();
  STUB_Object *istub = this->_stubobj ();
  if (istub)
  {
    CORBA::Object_ptr _tao_base_retval = CORBA::Object::_nil ();
    void* _tao_arguments[1];
    void** _tao_current_arg = _tao_arguments;
    *_tao_current_arg = &_tao_base_retval; _tao_current_arg++;
    istub->do_static_call (
      _tao_environment,
      &CORBA_Policy_copy_calldata,
      _tao_arguments
    );
    _tao_retval = CORBA_Policy::_narrow (_tao_base_retval, _tao_environment);
    CORBA::release (_tao_base_retval);
  } // end of if (istub)
  return _tao_retval;
}

void CORBA_Policy::destroy (
    CORBA::Environment &_tao_environment
   )
{
  static const TAO_Param_Data CORBA_Policy_destroy_paramdata [] =
  {
    {CORBA::_tc_void, PARAM_RETURN, 0}
  }; // CORBA_Policy_destroy_paramdata

  static const TAO_Call_Data CORBA_Policy_destroy_calldata =
  {"destroy", 1, 1, CORBA_Policy_destroy_paramdata, 0, 0};

  STUB_Object *istub = this->_stubobj ();
  if (istub)
  {
    void* _tao_arguments[1];
    void** _tao_current_arg = _tao_arguments;
    *_tao_current_arg = 0; _tao_current_arg++;
    istub->do_static_call (
      _tao_environment,
      &CORBA_Policy_destroy_calldata,
      _tao_arguments
    );
  } // end of if (istub)
  return;
}

CORBA::Boolean CORBA_Policy::_is_a (const CORBA::Char *value, CORBA::Environment &env)
{
  if (
    (!ACE_OS::strcmp ((char *)value, "IDL:CORBA/Policy:1.0")) ||
    (!ACE_OS::strcmp ((char *)value, CORBA::_tc_Object->id (env))))
  return 1; // success using local knowledge
  else
    return this->CORBA_Object::_is_a (value, env); // remote call
}

const char* CORBA_Policy::_interface_repository_id (void) const
{
  return "IDL:CORBA/Policy:1.0";
}

#if !defined (_CORBA_POLICYLIST_CS_)
#define _CORBA_POLICYLIST_CS_

// *************************************************************
// CORBA_PolicyList
// *************************************************************

CORBA_PolicyList::CORBA_PolicyList (void)
{}
CORBA_PolicyList::CORBA_PolicyList (CORBA::ULong max) // uses max size
  : TAO_Unbounded_Object_Sequence<CORBA_Policy> (max)
{}
CORBA_PolicyList::CORBA_PolicyList (CORBA::ULong max, CORBA::ULong length, CORBA_Policy_ptr *buffer, CORBA::Boolean release)
  : TAO_Unbounded_Object_Sequence<CORBA_Policy> (max, length, buffer, release)
{}
CORBA_PolicyList::CORBA_PolicyList (const CORBA::PolicyList &seq) // copy ctor
  : TAO_Unbounded_Object_Sequence<CORBA_Policy> (seq)
{}
CORBA_PolicyList::~CORBA_PolicyList (void) // dtor
{}


#endif /* end #if !defined */
