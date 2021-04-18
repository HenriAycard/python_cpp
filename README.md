# python_cpp
Exemple d'utilisation d'un composant en python
Utilise pybind11
apres git clone, faire:
```
cd python_cpp
git submodule init
git submodule update
```

Pour compiler

```
cd hello
make
```

Pour utiliser
```
python3
>>> import hello_component
>>> hello_component.greet()
'hello, world'
>>> hello_component.getVersion()
'1.0'
>>> 
```

# secp256K1
Exemple d'utilisation en utilisant la courbe secp256k1
Utilise pybind11
apres git clone, faire:
```
cd python_cpp
git submodule init
git submodule update
```

Pour compiler

```
cd secp256K1
make
```

Pour utiliser
```
python3
>>> from GenerateKey import GenerateKey
>>> key = GenerateKey()
>>> key.initialize("4b8e29b9b0dddd58a709edba7d6df6c07ebdaf5653e325114bc5318c238f87f0")
>>> key.getPrivateKey()
'4b8e29b9b0dddd58a709edba7d6df6c07ebdaf5653e325114bc5318c238f87f0'
>>> key.getPublicKey()
```
