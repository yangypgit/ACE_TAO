// This version uses the Implementation Repository.

#include "Test_i.h"

#include "tao/IORTable/IORTable.h"
#include "tao/PortableServer/Root_POA.h"
#include "tao/ImR_Client/ImR_Client.h"

#include "ace/Get_Opt.h"
#include "ace/streams.h"
#include "ace/OS_NS_unistd.h"

PortableServer::POA_ptr
createPOA(PortableServer::POA_ptr root_poa, const char* poa_name)
{
  PortableServer::LifespanPolicy_var life =
    root_poa->create_lifespan_policy(PortableServer::PERSISTENT);

  PortableServer::IdAssignmentPolicy_var assign =
    root_poa->create_id_assignment_policy(PortableServer::USER_ID);

  CORBA::PolicyList pols;
  pols.length(2);
  pols[0] = PortableServer::LifespanPolicy::_duplicate(life.in());
  pols[1] = PortableServer::IdAssignmentPolicy::_duplicate(assign.in());

  PortableServer::POAManager_var mgr = root_poa->the_POAManager();
  PortableServer::POA_var poa =
    root_poa->create_POA(poa_name, mgr.in(), pols);

  life->destroy();
  assign->destroy();

  return poa._retn();
}

int
ACE_TMAIN (int argc, ACE_TCHAR *argv[])
{
  try {
    CORBA::ORB_var orb = CORBA::ORB_init(argc, argv);

    int init_delay_secs = 0;
    int num_requests_expected = 0;

    ACE_Get_Opt get_opts (argc, argv, ACE_TEXT ("d:n:?"));
    int c;

    while ((c = get_opts ()) != -1)
      switch (c)
        {
        case 'd':
          init_delay_secs = ACE_OS::atoi (get_opts.opt_arg ());
          break;
        case 'n':
          num_requests_expected = ACE_OS::atoi (get_opts.opt_arg ());
          break;
        case '?':
          ACE_DEBUG ((LM_DEBUG,
                      "Server: usage: %s "
                      "-d <seconds to delay before initializing POA> ",
                      "-n <number of expected requests> \n",
                      argv[0]));
          return 1;
          break;
        }

    ACE_DEBUG ((LM_DEBUG,
                "(%P|%t) Server: delaying in initialization for <%d> seconds\n",
                init_delay_secs));
    ACE_OS::sleep (init_delay_secs);
    ACE_DEBUG ((LM_DEBUG,
                "(%P|%t) Server: done with delay\n"));

    CORBA::Object_var obj = orb->resolve_initial_references("RootPOA");
    PortableServer::POA_var root_poa = PortableServer::POA::_narrow(obj.in());

    PortableServer::POAManager_var mgr = root_poa->the_POAManager();

    ACE_CString poa_name("TestObject");

    PortableServer::POA_var test_poa = createPOA(root_poa.in(),
                                                 poa_name.c_str ());

    PortableServer::Servant_var<Test_i> test_servant =
      new Test_i(orb.in(), num_requests_expected);

    PortableServer::ObjectId_var object_id =
      PortableServer::string_to_ObjectId("test_object");

    // Activate the servant with the test POA,
    // obtain its object reference, and get a
    // stringified IOR.
    test_poa->activate_object_with_id(object_id.in(), test_servant.in());

    // Create binding between "TestService" and
    // the test object reference in the IOR Table.
    // Use a TAO extension to get the non imrified poa
    // to avoid forwarding requests back to the ImR.
    TAO_Root_POA* tpoa = dynamic_cast<TAO_Root_POA*>(test_poa.in());
    if (!tpoa)
      {
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("(%P|%t) Server: Could not cast POA to root POA")
                    ));
        return -1;
      }

    obj = tpoa->id_to_reference_i(object_id.in(), false);
    CORBA::String_var test_ior = orb->object_to_string(obj.in());
    obj = orb->resolve_initial_references("IORTable");
    IORTable::Table_var table = IORTable::Table::_narrow(obj.in());
    table->bind(poa_name.c_str (), test_ior.in());

    // This server is now ready to run.
    // This version does not create an IOR
    // file as demonstrated in the
    // Developer's Guide.  It assumes that
    // users create IORs for the client using
    // the tao_imr utility.
    //
    // Stop discarding requests.
    mgr->activate();

    ACE_DEBUG ((LM_DEBUG,
      "(%P|%t) Server: started <%C>\n",
      poa_name.c_str()));

    {
      ACE_CString status_file = poa_name + ACE_CString(".status");
      ofstream out(status_file.c_str ());
      out << "started" << endl;
    }

    orb->run();

    root_poa->destroy(1,1);
    orb->destroy();

    ACE_DEBUG ((LM_DEBUG,
      "(%P|%t) Server: ended <%C>\n",
      poa_name.c_str()));
  }
  catch(const CORBA::Exception& ex) {
    ex._tao_print_exception ("Server main()");
    return 1;
  }

  bool const expected_requests_made = Test_i::expected_requests_made ();
  if (!expected_requests_made)
    {
      ACE_ERROR ((LM_ERROR,
                  "(%P|%t) Server: ERROR: Expected number of requests were not made\n"));
    }

  int const status = expected_requests_made ? 0 : -1;

  return status;
}
