#include <iostream>
#include "lexer.hpp"


enum states {
  NULL_START, //covers spaces before first tag
  S_DELIM,
  E_DELIM
};


void printQueueItems(std::deque<token> &queue) {
  while (!queue.empty()) {
    token tempValue = queue.front();
    queue.pop_front();
    std::cout << tempValue.getTokenName() << ' ' << tempValue.getTokenType()  << " " << tempValue.getText() << '\n';
  }
}


std::deque<token> tokenizer(std::string &&rawString) {
  std::deque<token> tokenQueue;

  states currentState = NULL_START;
  std::string tempString = "";

  try {

    for (int i = 0; i < rawString.length(); i++) {
        switch (rawString[i]) {

          case '<':
            if (currentState == S_DELIM) {
                //raise error
                throw ("Error: < delimiter already utilised\n");
            } else {

              if (tempString.length() > 0) {
                token tempToken = tokenQueue.back();

                //Ensure text is assigned only to open tokens
                if (tempToken.getTokenType() == S_TAG) {

                  tokenQueue.pop_back();
                  tempToken.setAssociatedText(tempString);
                  tokenQueue.push_back(tempToken);

                } else {
                  //Raise Error
                  throw ("Error: Text cannot be assigned to closed or void tags, make sure that text is only assigned after an open tag\n");
                }

                tempString = "";

              }

              currentState = S_DELIM;
            }
            break;

          case '>':
            if (currentState == S_DELIM) {
              currentState = E_DELIM;
              tokenQueue.push_back(token(tempString));
              tempString = "";
            } else {
              //raise error
              throw ("Error: Closed tag should have a corresponding open tag to match\n");
            }
            break;

          // skip empty spaces
          case ' ':
            break;

          default:
            if (currentState == NULL_START) {
                //raise error
                throw ("Error: Text cannot appear at the start without being enclosed in tags\n");
            } else {
                tempString += rawString[i];
            }
            break;
        }
    }

    if (tempString.length() != 0 || currentState == S_DELIM) {
      throw ("Error: Text cannot appear outside of enclosed tags\n");
    }
  }

  catch (const char* errorMsg) { std::cout << errorMsg << '\n';}

  return tokenQueue;

}