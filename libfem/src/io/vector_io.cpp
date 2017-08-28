#include "libfem/io/vector_io.h"
#include "libfem/exception.h"

using namespace libfem;

dVector io::read_vector(std::istream& in)
{
	dVector v;
	io::read_vector(in, v);
	return v;
}

void io::read_vector(std::istream& in, dVector& v)
{
	uint32_t size{ 0 };
	THROW_IF(!(in >> size), LibfemException(errors::INVALID_VECTOR_INPUT));

	v.resize(size);

	for (uint32_t i = 0; i < size; ++i)
	{
		THROW_IF(!(in >> v[i]), LibfemException(errors::INVALID_VECTOR_INPUT));
	}
}
