#include <string>
#include <iostream>

// libcred includes
#include <libcred.hpp>

int
main()
{
    // Test values
    const std::string service("libcred-test-service");
    const std::string account("libcred@example.org");
    const std::string password("$uP3RseCr1t!");
    const std::string new_password("Ub3R$3CrE7!?!");
    std::string err;
    // Add a password
    if (libcred::set_password(service, account, password, &err) != libcred::SUCCESS)
    {
        std::cerr << "error: unable to add password " << err << std::endl;
        return 1;
    }
    std::cout << "Set password successfully." << std::endl;

    // Get a password
    std::string retrieved;
    if (libcred::get_password(service, account, &retrieved, &err) != libcred::SUCCESS)
    {
        std::cerr << "error: unable to get password " << err << std::endl;
        return 1;
    }
    std::cout << "Got password successfully." << std::endl;

    // Find a password
    std::string found;
    if (libcred::find_password(service, &found, &err) != libcred::SUCCESS)
    {
        std::cerr << "error: unable to find password " << err << std::endl;
        return 1;
    }
    std::cout << "Found password successfully." << std::endl;

    // Delete a password
    if (libcred::delete_password(service, account, &err) != libcred::SUCCESS)
    {
        std::cerr << "error: unable to delete password " << err << std::endl;
        return 1;
    }
    std::cout << "Deleted password successfully." << std::endl;

    // All done
    return 0;
}
