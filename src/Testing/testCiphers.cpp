#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Cipher.hpp"
#include "CipherMode.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

bool testCipher( const Cipher& cipher, const CipherMode mode, const std::string& inputText, const std::string& outputText)
{
  if (cipher.applyCipher(inputText, mode) == outputText)
  {
    return true;
  }
  else
  {
    return false;
  }
}

TEST_CASE("Playfair Cipher encryption", "[playfair]") {
  PlayfairCipher cc{"hello"};
  REQUIRE( testCipher(cc, CipherMode::Encrypt, "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA"));
}

TEST_CASE("Playfair Cipher decryption", "[playfair]") {
  PlayfairCipher cc{"hello"};
  REQUIRE( testCipher(cc, CipherMode::Decrypt, "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA", "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ"));
}

TEST_CASE("Caesar Cipher encryption", "[caesar]") {
  CaesarCipher cc{10};
  REQUIRE( testCipher(cc, CipherMode::Encrypt, "HELLOWORLD", "ROVVYGYBVN"));
}

TEST_CASE("Caesar Cipher decryption", "[caesar]") {
  CaesarCipher cc{10};
  REQUIRE( testCipher(cc, CipherMode::Decrypt, "ROVVYGYBVN", "HELLOWORLD"));
}

TEST_CASE("Vigenere Cipher encryption", "[vigenere]") {
  VigenereCipher cc{"key"};
  REQUIRE( testCipher(cc, CipherMode::Encrypt, "HELLOWORLD", "RIJVSUYVJN"));
}

TEST_CASE("Vigenere Cipher decryption", "[vigenere]") {
  VigenereCipher cc{"key"};
  REQUIRE( testCipher(cc, CipherMode::Decrypt, "RIJVSUYVJN", "HELLOWORLD"));
}