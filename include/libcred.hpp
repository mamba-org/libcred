#ifndef SRC_KEYTAR_H_
#define SRC_KEYTAR_H_

#include <string>
#include <vector>

namespace libcred {

typedef std::pair<std::string, std::string> Credentials;

enum LIBCRED_RESULT {
  SUCCESS,
  FAIL_ERROR,
  FAIL_NONFATAL
};

LIBCRED_RESULT SetPassword(const std::string& service,
                             const std::string& account,
                             const std::string& password,
                             std::string* error);

LIBCRED_RESULT GetPassword(const std::string& service,
                             const std::string& account,
                             std::string* password,
                             std::string* error);

LIBCRED_RESULT DeletePassword(const std::string& service,
                                const std::string& account,
                                std::string* error);

LIBCRED_RESULT FindPassword(const std::string& service,
                              std::string* password,
                              std::string* error);

LIBCRED_RESULT FindCredentials(const std::string& service,
                                 std::vector<Credentials>*,
                                 std::string* error);

}  // namespace keytar

#endif  // SRC_KEYTAR_H_
