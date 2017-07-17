#ifndef _LIBFEM_TYPE_DEFINITIONS_H_
#define _LIBFEM_TYPE_DEFINITIONS_H_

#include <vector>
#include <complex>

namespace libfem
{
	using dComplex = std::complex<double>;

	using dVector = std::vector<double>;
	using iVector = std::vector<int>;
	using zVector = std::vector<dComplex>;
}

#endif
