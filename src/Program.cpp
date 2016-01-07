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

#include "../Headers/Mist.h"
#include "../Headers/Task.h"

using boost::asio::ip::tcp;

std::vector<std::string> dummyIP;
Mist* mist = new Mist(2, 16000, 2, dummyIP);

//client model
int main()
{
	Mist::TaskInstruction instruction;

	try
	{
	    boost::asio::io_service clio_service;

	    tcp::resolver resolver(clio_service);
	    tcp::resolver::query query("daytime");
	    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

	    tcp::socket socket(clio_service);
	    boost::asio::connect(socket, endpoint_iterator);

	    bool is_connected = false;

	    while(!is_connected)
	    {
	    	socket.read_some(instruction);
	    	switch(instruction)
	    	{
	    	case Mist::PRIME_OPERATION:
	    		//do stuff
	    		printf("Found PRIME_OPERATION at the connection");
	    		is_connected = true;
	    		break;
	    	//case Mist::[Some other type]
	    	default:
	    		printf("Found nothing at the connection \n");
	    		break;
	    	}
	    }

	    Task* task = new Task("Client Task", instruction);
	    task->start();

	}
	catch(std::exception& e)
	{

	}
}

//server model
int main2()
{
	try
	{
		boost::asio::io_service svio_service;

	    tcp::acceptor acceptor(svio_service, tcp::endpoint(tcp::v4(), 13));

	    while(true)
	    {
	        tcp::socket svsocket(svio_service);
	        acceptor.accept(svsocket);
	        boost::system::error_code ignored_error;
	        boost::asio::write(svsocket, mist->PRIME_OPERATION, ignored_error);
	    }
	}
	  catch (std::exception& e)
	  {
	    std::cerr << e.what() << std::endl;
	  }
}

