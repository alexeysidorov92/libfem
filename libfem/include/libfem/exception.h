#ifndef _LIBFEM_EXCEPTION_H_
#define _LIBFEM_EXCEPTION_H_

#include <exception>

namespace libfem
{
	struct ErrorInfo
	{
		int code{ 0 };
		const char* message{ nullptr };
	};

	class LibfemException : public std::exception
	{
	private:
		ErrorInfo error_;

	public:
		LibfemException(const ErrorInfo& error)
			: error_(error)
		{}

		virtual const char* what() const override
		{
			return error_.message;
		}
	};

#define DECLARE_ERROR_INFO(name, code, message) libfem::ErrorInfo name{ code, message }
#define THROW_IF(condition, exception) if(condition) throw exception

	namespace errors
	{
		DECLARE_ERROR_INFO(INVALID_VECTOR_INPUT, 1, "invalid vector input");
	}
}

#endif