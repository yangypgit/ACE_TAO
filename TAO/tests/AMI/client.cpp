// $Id$

#include "ace/Get_Opt.h"
#include "ace/Task.h"
#include "testC.h"

ACE_RCSID(MT_Client, client, "$Id$")

const char *ior = "file://test.ior";
int nthreads = 5;
int niterations = 5;

int
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "k:n:i:");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'k':
        ior = get_opts.optarg;
        break;
      case 'n':
        nthreads = ACE_OS::atoi (get_opts.optarg);
        break;
      case 'i':
        niterations = ACE_OS::atoi (get_opts.optarg);
        break;
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s "
                           "-k <ior> "
                           "-n <nthreads> "
                           "-i <niterations> "
                           "\n",
                           argv [0]),
                          -1);
      }
  // Indicates sucessful parsing of the command line
  return 0;
}

class Client : public ACE_Task_Base
{
  // = TITLE
  //   Run the client thread
  //
  // = DESCRIPTION
  //   Use the ACE_Task_Base class to run the client threads.
  //
public:
  Client (Simple_Server_ptr server, int niterations);
  // ctor

  virtual int svc (void);
  // The thread entry point.

private:
  Simple_Server_var server_;
  // The server.

  int niterations_;
  // The number of iterations on each client thread.
};

class Handler : public POA_AMI_Simple_Server_Handler
{
public:
  Handler (void) {};
 
  ~Handler (void) {};
};

int
main (int argc, char *argv[])
{
  ACE_TRY_NEW_ENV
    {
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc, argv, "", ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (parse_args (argc, argv) != 0)
        return 1;

      CORBA::Object_var object =
        orb->string_to_object (ior, ACE_TRY_ENV);
      ACE_TRY_CHECK;

      Simple_Server_var server =
        Simple_Server::_narrow (object.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (server.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Object reference <%s> is nil\n",
                             ior),
                            1);
        }

      // Activate POA to handle the call back.
      
      CORBA::Object_var poa_object =
        orb->resolve_initial_references("RootPOA");
      if (CORBA::is_nil (poa_object.in ()))
        ACE_ERROR_RETURN ((LM_ERROR,
                           " (%P|%t) Unable to initialize the POA.\n"),
                          1);
      
      PortableServer::POA_var root_poa =
        PortableServer::POA::_narrow (poa_object.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;

      PortableServer::POAManager_var poa_manager =
        root_poa->the_POAManager (ACE_TRY_ENV);
      ACE_TRY_CHECK;

      poa_manager->activate (ACE_TRY_ENV);
      ACE_TRY_CHECK;
      
      Client client (server.in (), niterations);
      if (client.activate (THR_NEW_LWP | THR_JOINABLE,
                           nthreads) != 0)
        ACE_ERROR_RETURN ((LM_ERROR,
                           "Cannot activate client threads\n"),
                          1);

      client.thr_mgr ()->wait ();

      ACE_DEBUG ((LM_DEBUG, "threads finished\n"));
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Catched exception:");
      return 1;
    }
  ACE_ENDTRY;

  return 0;
}

// ****************************************************************

Client::Client (Simple_Server_ptr server,
                int niterations)
  :  server_ (Simple_Server::_duplicate (server)),
     niterations_ (niterations)
{
}

int
Client::svc (void)
{
  ACE_TRY_NEW_ENV
    {
#if 0
      // If we are using a global ORB this is a nop, otherwise it
      // initializes the ORB resources for this thread.
      int argc = 0;
      char* argv[] = { "" };
      CORBA::ORB_var orb =
        CORBA::ORB_init (argc, argv, "", ACE_TRY_ENV);
      ACE_TRY_CHECK;
#endif

      Handler handler;
      AMI_Simple_Server_Handler_var the_handler =
        handler._this (ACE_TRY_ENV);
      ACE_TRY_CHECK;

      CORBA::Long number = 0;

      for (int i = 0; i < this->niterations_; ++i)
        {
          server_->sendc_get_number (the_handler.in (),
                                     ACE_TRY_ENV);
          ACE_TRY_CHECK;

          if (TAO_debug_level > 0 && i % 100 == 0)
            ACE_DEBUG ((LM_DEBUG, "(%P|%t) iteration = %d\n", i));
        }

      number = server_->get_number (ACE_TRY_ENV);
      
      ACE_DEBUG ((LM_DEBUG, "(%P | %t) get_number = %d\n", number));
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "MT_Client: exception raised");
    }
  ACE_ENDTRY;
  return 0;
}
