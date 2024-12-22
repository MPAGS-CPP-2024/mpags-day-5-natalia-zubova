#ifndef MPAGSCIPHER_VIGENERECIPHER_HPP
#define MPAGSCIPHER_VIGENERECIPHER_HPP

#include "CipherMode.hpp"
#include "CaesarCipher.hpp"

#include <cstddef>
#include <string>
#include <map>

class VigenereCipher {
  public:
    /**
     * \brief Create a new VigenereCipher with the given key
     *
     * \param key the key to use in the cipher
     */
    explicit VigenereCipher(const std::string& key);

    /**
     * \brief Set the key to be used for the encryption/decryption
     *
     * \param key the key to use in the cipher
     */
    void setKey(const std::string& key);

    /**
     * \brief Apply the cipher to the provided text
     *
     * \param inputText the text to encrypt or decrypt
     * \param cipherMode whether to encrypt or decrypt the input text
     * \return the result of applying the cipher to the input text
     */
    std::string applyCipher(const std::string& inputText,
                            const CipherMode cipherMode) const;

  private:
    /// The cipher key
    std::string key_{""};

    /// Lookup table
    std::map<char,CaesarCipher> charLookup_;
};

#endif