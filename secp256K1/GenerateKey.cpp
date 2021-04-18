//
//  PubPrivKey.cpp
//  secp256K1
//
//  Created by Henri Aycard on 18/04/2021.
//  Copyright © 2021 Aycard. All rights reserved.
//

#include <iostream>
#include <string>
#include <pybind11/pybind11.h>
#include "uECC.h"

char version[]="1.0";

char const* getVersion() {
    return version;
}

class GenerateKey
{
public:
    /**
     @brief Déclaration du construteur sans paramètres
     */
    GenerateKey(){}
    ~GenerateKey() {}

    /**
     @brief Initialise la clé public et privée
     @params Les arguments sont des chaines de caracteres python représentant des nombres
     de 256bits codées en hexadécimal
     */
    void initialize(std::string &number) {
        
        int success;
        const struct uECC_Curve_t * curves;
        curves = uECC_secp256k1();
        
        memset(publicKey, number, sizeof(number));
        memset(public_computed, 0, sizeof(public_computed));

        
        if (!uECC_make_key(publicKey, privateKey, curves)) {
            printf("uECC_make_key() failed\n");
            continue;
        }

        if (!uECC_compute_public_key(privateKey, public_computedKey, curves)) {
            printf("uECC_compute_public_key() failed\n");
        }
        
        memset(privateKey, 0, sizeof(private));
        success = uECC_compute_public_key(private, public_computed, curves[c]);
        if (success) {
            printf("uECC_compute_public_key() should have failed\n");
        }
    }
    
    /**
     @return retourne la valeur d'initialisation
     */
    const std::string &getPublicKey() const { return publicKey; }
    /**
     @return retourne la clé privée
     */
    const std::string &getPrivateKey() const { return privateKey; }

private:
    std::uint8_t publicKey[256];
    std::uint8_t public_computed[256];
    std::uint8_t privateKey[256];
};

namespace py = pybind11;

PYBIND11_MODULE(GenerateKey, m)
{
    m.doc() = "GenerateKey 1.0";
    m.def("getVersion", &getVersion, "a function returning the version");
    py::class_<GenerateKey>(m, "GenerateKey")
        .def(py::init())
        .def("initialize", &GenerateKey::initialize)
        .def("get_private_key", &GenerateKey::getPrivateKey)
        .def("get_public_key", &GenerateKey::getPublicKey);
}

