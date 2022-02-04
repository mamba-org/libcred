// Standard includes
#include <cassert>
#include <iostream>
#include <string>

// libcred includes
#include <libcred.hpp>

// Required MinUnit definitions
int tests_run = 0;

// Make sure get_password doesn't succeed for a non-existent service/account
void
test_non_existent_get()
{
    std::string password;
    std::string errStr;
    if (libcred::get_password(
            "libcred-bad-password", "libcred-test-bad-account", &password, &errStr)
        == libcred::FAIL_ERROR)
    {
        std::cout << "Expected non fatal fail for getting nonexistent password" << std::endl;
        exit(1);
    };
}

// Make sure find_password doesn't succeed for a non-existent service
void
test_non_existent_find()
{
    std::string password, errStr;
    if (libcred::find_password("libcred-test-bad-service", &password, &errStr)
        == libcred::FAIL_ERROR)
    {
        std::cout << "Expected non fatal fail for nonexistent find password" << std::endl;
        exit(1);
    }
}


#define TEST_ASSERT(msg, test)                                                                     \
    if (!(test))                                                                                   \
    {                                                                                              \
        std::cout << msg << ": " << errStr << std::endl;                                           \
        exit(1);                                                                                   \
    }


// Make sure the standard add/get/find/delete
void
test_password_lifecycle()
{
    // Set up testing constants
    const std::string service("libcred-test-service");
    const std::string account("libcred@example.org");
    const std::string password("$uP3RseCr1t!");
    const std::string alternate_password("Ub3R$3CrE7!?!");

    // Create buffer for retrieval
    std::string password_retrieved;
    std::string errStr;
    // Try to add a password
    TEST_ASSERT("error: set_password didnt succeed",
                libcred::set_password(service, account, password, &errStr) == libcred::SUCCESS);

    // // Try to get the password
    TEST_ASSERT("error: unable to get password",
                libcred::get_password(service, account, &password_retrieved, &errStr)
                    == libcred::SUCCESS);

    TEST_ASSERT("error: retrieved password doesn't match password stored",
                password_retrieved == password);

    // Try to find the password
    TEST_ASSERT("error: unable to find password",
                libcred::find_password(service, &password_retrieved, &errStr) == libcred::SUCCESS);
    TEST_ASSERT("error: found password doesn't match password stored",
                password_retrieved == password);

    // Try to replace the password
    TEST_ASSERT("error: unable to replace password",
                libcred::set_password(service, account, alternate_password, &errStr)
                    == libcred::SUCCESS);
    TEST_ASSERT("error: unable to get replaced password",
                libcred::get_password(service, account, &password_retrieved, &errStr)
                    == libcred::SUCCESS);
    TEST_ASSERT("error: retrieved password doesn't match new password",
                password_retrieved == alternate_password);

    // Try to delete the password
    TEST_ASSERT("error: unable to delete password",
                libcred::delete_password(service, account, &errStr) == libcred::SUCCESS);
}

// Test registry
void
all_tests()
{
    test_non_existent_get();
    test_non_existent_find();
    test_password_lifecycle();
}

// Main entry point
int
main(int argc, char** argv)
{
    // Run tests
    all_tests();
}
