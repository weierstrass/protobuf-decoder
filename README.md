# protobuf-decoder

https://weierstrass.github.io/protobuf-decoder/

## Overview
Are you working with protocol buffer and wants to know what is actually inside the serialized binary data, then you might find this tool handy.

![protobuf-decoder example.](protobuf_decoder_example.png)

Pre-compiled binaries can be found here https://github.com/weierstrass/protobuf-decoder/releases/latest

## Working with the source code
This project uses the cmake suit to manage building and testing.

### Build
`$ cmake . && make`

### Running unit tests
`$ cmake . && make && ctest`

### Usage
`$ ./src/protobuf-decoder`

## Supported conversion algorithms
The supported algorithms to encode the binary data are today:
* hex
* base64

### Need support for another algorithm?
If you know how to implement your algorithm in C++ then you are almost there. The project is open source and design to make it as easy as possible for a third party to add new algorithms.

Basically this is what you have to do

1. Create a new class in src/conversion/algorithm.
2. Extend the protobuf_decoder::algorithm::BaseAlgorithm class.
3. Register the algorithm using the REGISTER_ALGORITHM macro.
4. Make sure you have added test cases for your algorithm
5. Do a pull request and would be more than happy to review it.

An example for the hex algorithm.
```
// HexAlgorithm.hpp
...
class HexAlgorithm : public BaseAlgorithm<HexAlgorithm> // 2. Extend base Algorithm.
{
public:
  virtual ~HexAlgorithm() {}

  virtual std::string encode(const std::string& iString);

  virtual std::string decode(const std::string& iString);
};
  ...
```

```
// HexAlgorithm.cpp
...
REGISTER_ALGORITHM(HexAlgorithm, "HEX"); // 3. Register new algorithm.
...
std::string HexAlgorithm::encode(const std::string& iString)
{
  // Encoding implementation.
}

std::string HexAlgorithm::decode(const std::string& iString)
{
  // Decoding implementation.
}
...
```
This is really everythin that is needed, if you follow these steps your algorithm should automatically apear in the GUI without any need to modify existing code. How does it work?

If you do not have the necessary knowledge in C++, you can also let me know what you need and I will try to do it when I find a spare moment.



