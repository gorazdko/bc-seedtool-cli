//
//  random.hpp
//
//  Copyright © 2020 by Blockchain Commons, LLC
//  Licensed under the "BSD-2-Clause Plus Patent License"
//

#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "utils.hpp"

typedef void (*random_generator)(uint8_t*, size_t, void*);

// Generates a buffer of random bytes using the OS's cryptographically strong random number generator.
void crypto_random(uint8_t* buf, size_t n, void* ctx);

// Seeds the cryptographically strong deterministic random number generator with the SHA256 digest of the string.
void seed_deterministic_string(const std::string &string);

// Generates a buffer of random bytes using the cryptographically strong deterministic random number generator.
void deterministic_random(uint8_t* buf, size_t n, void* ctx);

ByteVector deterministic_random(const ByteVector &entropy, size_t n);

ByteVector sha256_deterministic_random(const ByteVector &entropy, size_t n);
ByteVector sha256_deterministic_random(const std::string &string, size_t n);
