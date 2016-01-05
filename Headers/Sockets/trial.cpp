//include nessesary boost items

#include "trial.h"

using namespace std;

//global variables
string reply;
//end global variables

/*int main(){
  crashObj.offloadCrash();
  return 0;
}*/

ClientCrash::ClientCrash()
{
  //construct shit here
}

ClientCrash::~ClientCrash()
{
  //destruct shit here
}

void ClientCrash::offloadCrash()
{
  try
  {
    ClientSocket client_socket("173.73.153.159", 41300); //Homestuck. This is what the reference
    try
    {
      client_socket << "crash now";
      client_socket >> reply;
    }
    catch (SocketException&){}
      std::cout << "We received this response from the server:\n\"" << reply << "\"\n";;
  }
  catch (SocketException& e)
  {
    std::cout << "Exception was caught here: " << e.description() << endl;
  }
}
