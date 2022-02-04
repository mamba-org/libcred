#ifndef SRC_KEYTAR_H_
#define SRC_KEYTAR_H_

#include <string>
#include <vector>

namespace libcred
{

    typedef std::pair<std::string, std::string> Credentials;

    enum LIBCRED_RESULT
    {
        SUCCESS,
        FAIL_ERROR,
        FAIL_NONFATAL
    };

#ifdef _WIN32
#ifdef LIBCRED_STATIC_LIB
#define LIBCRED_PUBLIC_API
#else
#ifdef LIBCRED_EXPORTS
#define LIBCRED_PUBLIC_API __declspec(dllexport)
#else
#define LIBCRED_PUBLIC_API __declspec(dllimport)
#endif
#endif
#else
#define LIBCRED_PUBLIC_API
#endif

    LIBCRED_PUBLIC_API LIBCRED_RESULT set_password(const std::string& service,
                                                   const std::string& account,
                                                   const std::string& password,
                                                   std::string* error);

    LIBCRED_PUBLIC_API LIBCRED_RESULT get_password(const std::string& service,
                                                   const std::string& account,
                                                   std::string* password,
                                                   std::string* error);

    LIBCRED_PUBLIC_API LIBCRED_RESULT delete_password(const std::string& service,
                                                      const std::string& account,
                                                      std::string* error);

    LIBCRED_PUBLIC_API LIBCRED_RESULT find_password(const std::string& service,
                                                    std::string* password,
                                                    std::string* error);

    LIBCRED_PUBLIC_API LIBCRED_RESULT find_credentials(const std::string& service,
                                                       std::vector<Credentials>*,
                                                       std::string* error);

}  // namespace keytar

#endif  // SRC_KEYTAR_H_
