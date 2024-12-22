#include "VigenereCipher.hpp"
#include "Alphabet.hpp"

#include <iostream>
#include <string>
#include <algorithm>

VigenereCipher::VigenereCipher(const std::string& key)
{
    // Set the given key
    setKey(key);
}

void VigenereCipher::setKey(const std::string& key)
{   
    // Store the key
    key_ = key;

    // Make sure the key is uppercase
    std::transform(std::begin(key_), std::end(key_), std::begin(key_),
                   ::toupper);

    // Remove non-alphabet characters
    key_.erase(std::remove_if(std::begin(key_), std::end(key_),
                              [](char c) { return !std::isalpha(c); }),
               std::end(key_));
    
    // Check if the key is empty and
    // replace with default if so
    if (key_.empty()) {
        key_ = "KEY";
    }

    // loop over the key
    for (char letter : key_) {
        // Find the letter position in the
        // alphabet
        std::size_t position = Alphabet::alphabet.find(letter);
        // Create a CaesarCipher using
        // this position as a key
        CaesarCipher caesarCipher{position};

        // Insert a std::pair of the
        // letter and CaesarCipher into the lookup
        charLookup_.insert(std::make_pair(letter, caesarCipher));
    }
}

std::string VigenereCipher::applyCipher(const std::string& inputText,
                                        const CipherMode cipherMode) const
{   
    // Create the output string
    std::string outputText {""};
    
    for (size_t i = 0; i < inputText.size(); i++) {
        
        // Find the corresponding letter in the key
        char keyLetter = key_[i % key_.size()];
        
        // Find the Caesar cipher from the lookup
        CaesarCipher caesarCipher = charLookup_.at(keyLetter);
        
        // Run the (de)encryption
        outputText += caesarCipher.applyCipher(std::string(1, inputText[i]), cipherMode);
    }

    return outputText;
}