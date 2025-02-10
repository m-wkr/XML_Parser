#include <deque>
#include "lexer.hpp"
#include "parser.hpp"
#include <iostream>
#include <fstream>


std::string extractFileLines(std::string &&fileName) {
  std::string stringHolder;
  std::string tempString;

  std::ifstream targetFile(fileName);

  if (!targetFile) {
    throw ("Error: Input file doesn't exist.\n");
  }

  while (std::getline (targetFile, tempString)) {
    stringHolder += tempString;
  }

  return stringHolder;
}




// <></> is deemed illegal to reduce complexity for now
int main(int argc, char** argv) {

  if (argc != 2) {
    std::cout << "Program Terminated. Ensure that you supply only one argument with the executable.\n";
  } else {
    try {
    std::string rawString = extractFileLines(argv[1]);

    std::deque<token> tokenQueue = tokenizer(rawString);
    std::shared_ptr<node> AST = formAST(tokenQueue);
    }
    catch (const char* errorMsg) {std::cout << errorMsg;}
  }

  return 0;
}