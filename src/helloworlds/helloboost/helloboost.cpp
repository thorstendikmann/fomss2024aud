#include <iostream>

#include <boost/version.hpp>
void boostVersion()
{

	std::cout << "Using boost "
			  << BOOST_VERSION / 100000 << "."	   // major
			  << BOOST_VERSION / 100 % 1000 << "." // minor
			  << BOOST_VERSION % 100			   // patch
			  << std::endl;
}

#include <boost/array.hpp>
void boostArray()
{
	boost::array<int, 4> arr = {{1, 2, 3, 4}};
	std::cout << "Hello boost: " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << std::endl;
}

#include <boost/log/trivial.hpp>
void boostLog()
{
	BOOST_LOG_TRIVIAL(trace) << "This is a trace severity message";
	BOOST_LOG_TRIVIAL(debug) << "This is a debug severity message";
	BOOST_LOG_TRIVIAL(info) << "This is an informational severity message";
	BOOST_LOG_TRIVIAL(warning) << "This is a warning severity message";
	BOOST_LOG_TRIVIAL(error) << "This is an error severity message";
	BOOST_LOG_TRIVIAL(fatal) << "and this is a fatal severity message";
}

int main()
{
	boostVersion();
	boostArray();
	boostLog();
	return 0;
}