#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

#include "CipherMode.hpp"
#include <string>

class Cipher {
  public:
    Cipher() = default;
    Cipher(const Cipher& rhs) = default;
    Cipher(Cipher&& rhs) = default;
    Cipher& operator=(const Cipher& rhs) = default;
    Cipher& operator=(Cipher&& rhs) = default;
    virtual ~Cipher() = default;
    
    virtual std::string applyCipher( const std::string& input,
                                     const CipherMode mode ) const = 0;
};

#endif // MPAGSCIPHER_CIPHER_HPP