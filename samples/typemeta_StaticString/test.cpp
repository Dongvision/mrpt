/* +------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)            |
   |                          http://www.mrpt.org/                          |
   |                                                                        |
   | Copyright (c) 2005-2017, Individual contributors, see AUTHORS file     |
   | See: http://www.mrpt.org/Authors - All rights reserved.                |
   | Released under BSD License. See details in http://www.mrpt.org/License |
   +------------------------------------------------------------------------+ */

#include <mrpt/typemeta/static_string.h>
#include <mrpt/typemeta/num_to_string.h>
#include <iostream>

void Test_StaticString()
{
	using namespace std;
	using namespace mrpt::typemeta;

	constexpr string_literal<3> s = "foo";
	cout << "string_literal<3>=" << s << endl;

	constexpr auto a = literal("foo");
	constexpr auto b = literal("bar");
	// In GCC7 this can be "constexpr", but it fails in MSVC 2017 (!)
	auto ab = a+b;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "a+b=" << ab << endl;

	static_assert(ab.size() == 6, "***");
	cout << "(a+b).size()=" << ab.size() << endl;
	cout << "(a+b)[0]=" << ab[0] << endl;
	cout << "(a+b)[5]=" << ab[5] << endl;

	constexpr auto n42 = num_to_string<42>::value;
	constexpr auto n9999 = num_to_string<9999>::value;
	cout << "42 as string=" << n42 << endl;
	cout << "9999 as string=" << n9999 << endl;
}

int main(int argc, char** argv)
{
	try
	{
		Test_StaticString();
		return 0;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		return -1;
	}
}
