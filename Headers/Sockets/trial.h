/* This is the client version of the program
 * This program is meant to connect with the server and send it the "crash program"
 * This will artificially increase the power of the client device, because the work is being offloaded via internet to a more powerful device
 * This program deserves a 7.8/10 #toomuchwater
 */

#ifndef TRAIL_H
#define TRAIL_H

#include <string>
#include <iostream>
/*#include <sys/socket.h>
#include <netinet/in.h> <-- these are included in the files below*/
#include "ClientSocket.h"
#include "SocketException.h"

//include the nessesary files from Boost and cppnetlib

using namespace std;

class ClientCrash
{
  public:
    ClientCrash();
    ~ClientCrash();

    void offloadCrash(); //starts the offload process

} crashObj;

#endif
