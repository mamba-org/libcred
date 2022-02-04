# libcred - cross-platform credentials helper library

This C++ library is a fork of [`node-keytar`](https://github.com/atom/node-keytar) and tests are forked from [`keytar`](https://github.com/xenoscopic/keytar) to provide standalone C++ access to cross-platform credentials management.

The library can be used to get, add, replace, and delete passwords in system's keychain. On macOS the passwords are managed by the Keychain, on Linux they are managed by the Secret Service API/libsecret, and on Windows they are managed by Credential Vault.

### Usage example

```cpp
#include <string>
#include <iostream>

// libcred includes
#include <libcred.hpp>

int main() {
    // Test values
    const std::string service("libcred-test-service");
    const std::string account("libcred@example.org");
    const std::string password("$uP3RseCr1t!");
    const std::string new_password("Ub3R$3CrE7!?!");
    std::string err;
    // Add a password
    if (libcred::set_password(service, account, password, &err) != libcred::SUCCESS) {
        std::cerr << "error: unable to add password " << err << std::endl;
        return 1;
    }
    std::cout << "Set password successfully." << std::endl;

    // Get a password
    std::string retrieved;
    if (libcred::get_password(service, account, &retrieved, &err) != libcred::SUCCESS) {
        std::cerr << "error: unable to get password " << err  << std::endl;
        return 1;
    }
    std::cout << "Got password successfully." << std::endl;

    // Find a password
    std::string found;
    if (libcred::find_password(service, &found, &err) != libcred::SUCCESS) {
        std::cerr << "error: unable to find password " << err << std::endl;
        return 1;
    }
    std::cout << "Found password successfully." << std::endl;

    // Delete a password
    if (libcred::delete_password(service, account, &err) != libcred::SUCCESS) {
        std::cerr << "error: unable to delete password " << err << std::endl;
        return 1;
    }
    std::cout << "Deleted password successfully." << std::endl;

    // All done
    return 0;
}
```
