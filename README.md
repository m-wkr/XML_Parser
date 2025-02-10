# Naive XML Parser ![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)

This project was initially inspired by [LowByteProduction's RegEx Engine](https://github.com/lowbyteproductions/Regular-Expression-Engine), which in turn lead to this naive approach
in building an XML lexer and parser to validate the format of a file containing strictly XML formatting.

## Syntactic Limitations

* Due to how the lexer skips whitespace, both tag names and enclosed text will lose any spacing utilised.
* The lexer only allows text if it immediately follows an opening tag, such as `<test>{textHere}...</test>`.
* Empty tags such as `<></>` are flagged by the parser as being illegal.
* Text may not appear before the first element, and after the last element.

### How do I build & run this project?

1. Clone this Repository: `git clone https://github.com/m-wkr/XML_Parser`
2. Navigate to its build directory: `cd XML_Parser/build`
3. Build the MakeFile and executable with: `cmake .. && make`
4. Move the file containing strictly XML content into the build directory.
5. Run: `./XML_Parser <YourFileName/FilePathHere>`
