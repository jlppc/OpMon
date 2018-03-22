/*
OpString.hpp
Author : Jlppc
File under license GNU GPL-3.0
http://opmon-game.ga
*/
#ifndef OPSTRING_PROTECTED
#define OPSTRING_PROTECTED
#include <SFML/System/String.hpp>
#include <iostream>
#include <vector>

namespace Utils {

    /**
   * Class defining an OpString. See the OpMon documentation (http://opmon.ga/pages/doc) for more details
   */
    class OpString {
      private:
        std::string key;
        std::vector<sf::String *> objects;
      bool created = false;
      public:
      OpString(std::string const& key, ...);
      OpString(std::string const& key, std::vector<sf::String*> obj = std::vector<sf::String*>());
      OpString();
      ~OpString();

        sf::String getObject(int const &index) {
            return *(objects[index]);
        }
        std::string getKey() {
            return key;
        }
        sf::String getString();
        static OpString voidStr;
    };

} // namespace Utils

#endif
