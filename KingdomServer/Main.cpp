

#include <iostream>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
//#include "Network/Messages.hpp"
#include "Utils/Log.hpp"
//#include "Network/AuthServer.hpp"
//#include "Network/Opcodes.hpp"
#include "Utils/MysqlConnectionPool.hpp"


using boost::asio::ip::tcp;

int main(int argc, char* argv[])
{
	try
	{
		sLog.Initialize("server.log", LOG_LVL_DEBUG);

		sLog.outString("Starting Warleague Server");


		sLog.outString("The Server has been Started!!");
		sLog.outString("-------------------------------------------");
		sLog.outString("----------Server Run Successful!!----------");
		sLog.outString("-------------------------------------------");


		MysqlConnectionPool::getInstance().initializePool("server", "n6q48D5746G6s3r", "tcp://warleague.fr:3306", "select 0 from dual;");

		boost::asio::io_service io_service;
		tcp::endpoint endpoint(tcp::v4(), 8080);


	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}
	return 0;
}