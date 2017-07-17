#ifndef _LIBFEM_IO_VECTOR_IO_H_
#define _LIBFEM_IO_VECTOR_IO_H_

#include "libfem/type_definitions.h"
#include <istream>

namespace libfem
{
	namespace io
	{
		dVector read_vector(std::istream& in);

		bool read_vector(std::istream& in, dVector& v);
	}
}

#endif
