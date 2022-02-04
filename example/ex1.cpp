#include <iostream>
#include "libcred.hpp"


using namespace libcred;
int
main()
{
    std::string err;
    int res = libcred::SetPassword("myservice", "myaccount", "thisistopsecret", &err);

    switch (res)
    {
        case LIBCRED_RESULT::SUCCESS:
            std::cout << "Successfully set password for myservice/myaccount!" << std::endl;
            return 0;
        case LIBCRED_RESULT::FAIL_NONFATAL:
            std::cout << "Non-fatal error " << err << std::endl;
            return 0;
        case LIBCRED_RESULT::FAIL_ERROR:
            std::cout << "Fatal error " << err << std::endl;
            return 1;
    }
}
