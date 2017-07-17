#include "libfem/io/vector_io.h"

using namespace libfem;

dVector io::read_vector(std::istream& in)
{
	dVector v;

	if(!io::read_vector(in, v))
	{
		throw std::runtime_error("Wrong vector format");
	}

	return v;
}

bool io::read_vector(std::istream& in, dVector& v)
{
	size_t size = 0;

	if (!(in >> size))
	{
		return false;
	}

	v.resize(size);

	for (size_t i = 0; i < size; i++)
	{
		if (!(in >> v[i]))
		{
			return false;
		}
	}

	return true;
}
