/*
 * Program.cpp
 *
 *  Created on: Jan 7, 2016
 *      Author: bazebadger
 */

#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iterator>

#include "../Headers/Mist.h"
#include "../Headers/Task.h"

using boost::asio::ip::tcp;

std::string message;

void callTask()
{

}

//client model
int main(int argc, char* argv[])
{
	  try
	  {
	    if (argc != 2)
	    {
	      std::cerr << "Usage: client <host>" << std::endl;
	      return 1;
	    }

	    printf("Passed argc != 2 \n");

	    boost::asio::io_service io_service;

	    tcp::resolver resolver(io_service);
	    tcp::resolver::query query(argv[1], "daytime");
	    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

	    tcp::socket socket(io_service);
	    boost::asio::connect(socket, endpoint_iterator);

	    for (;;)
	    {
	      boost::array<char, 64> buf;
	      boost::system::error_code error;

	      size_t len = socket.read_some(boost::asio::buffer(buf), error);

	      if (error == boost::asio::error::eof)
	        break; // Connection closed cleanly by peer.
	      else if (error)
	        throw boost::system::system_error(error); // Some other error.

	      std::cout.write(buf.data(), len);
	      std::copy(buf.begin(), buf.begin()+63, std::back_inserter(message));

	  	bool messageRecieved = false;

	  	while(!messageRecieved)
	  	{
	  		if(message == "PRIME_OPERATION")
	  		{
	  			Task* task = new Task("Client task", Mist::PRIME_OPERATION);
	  		}
	  	}

	    }
	  }
	  catch (std::exception& e)
	  {
	    std::cerr << e.what() << std::endl;
	  }

	  return 0;
}

//server model
/*int main2()
{
	  try
	  {
	    boost::asio::io_service io_service;

	    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 13));

	    for (;;)
	    {
	      tcp::socket socket(io_service);
	      acceptor.accept(socket);

	      std::string instruction = "PRIME_OPERATOR";

	      boost::system::error_code ignored_error;
	      boost::asio::write(socket, boost::asio::buffer(instruction), ignored_error);
	    }
	  }
	  catch (std::exception& e)
	  {
	    std::cerr << e.what() << std::endl;
	  }

	  return 0;
}
*/
