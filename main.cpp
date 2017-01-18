/*
  OFT PHP extension
  @ Team:     OpenFaceTracker
  @ Version:  1.0
*/

#include <phpcpp.h>
#include <iostream>
/* We are using oftlib3 */
#include <oft3/core.h>
#include <oft3/color.h>

/*
* TEST function
*/
void oftInfo(){
  ft::FtUtils * oft3 = new ft::FtUtils;
  const char * oftversion = "test";

  oftversion = oft3->version();

  /* show info */
  Php::out << "OpenFaceTracker For PHP developers" << std::endl;
  Php::out << "Using OFTLIB version " << oftversion << std::endl;
  Php::out << "LgplV3" << std::endl;

  delete oft3;
}

/**
 *  tell the compiler that the get_module is a pure C function
 */
extern "C" {

    /**
     *  Function that is called by PHP right after the PHP process
     *  has started, and that returns an address of an internal PHP
     *  strucure with all the details and features of your extension
     *
     *  @return void*   a pointer to an address that is understood by PHP
     */
    PHPCPP_EXPORT void *get_module()
    {
        // static(!) Php::Extension object that should stay in memory
        // for the entire duration of the process (that's why it's static)
        static Php::Extension extension("php_oft", "1.0");

        /* All functions */
        extension.add<oftInfo>("oftInfo");

        // return the extension
        return extension;
    }
}
