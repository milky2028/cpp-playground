#include <iostream>
#include <string>

class test_clipboard {
protected:
    virtual std::string set_file() {
        return "circles";
    }

public:
    std::string file = "";

    void setup_iteration() {
        file = set_file();
    }
};

class test_clipboard_extended : public test_clipboard {
   using base = test_clipboard;

   void setup_iteration() {
      file = "teapcup";
      base::setup_iteration();
   }
};
 
int main() {
   test_clipboard_extended test;
   std::cout << "Test file name is...\n";
   std::cout << test.file << std::endl;
}