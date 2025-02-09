#pragma once

#include <string>

enum tokenType {
  NIL,
  S_TAG,
  E_TAG,
  SE_TAG
};


class token {
  std::string tokenName;
  tokenType tagType;

  std::string tokenAssociatedText = "";

  public:
  token(std::string &nTokenName) {
    const int nameLength = nTokenName.length();
    //determine token type
    if (nameLength > 0) {

      if (nTokenName[0] == '/') {
        tagType = E_TAG;
        tokenName = nTokenName.substr(1);
      } else if (nTokenName[nameLength-1] == '/') {
        tagType = SE_TAG;
        tokenName = nTokenName.substr(0,nameLength-1);
      } else {
        tagType = S_TAG;
        tokenName = nTokenName;
      }

    } else {
      tagType = NIL;
      tokenName = nTokenName;
    }

  }

  token(std::string &&nTokenName) {
    const int nameLength = nTokenName.length();
    //determine token type
    if (nameLength > 0) {

      if (nTokenName[0] == '/') {
        tagType = E_TAG;
        tokenName = nTokenName.substr(1);
      } else if (nTokenName[nameLength-1] == '/') {
        tagType = SE_TAG;
        tokenName = nTokenName.substr(0,nameLength-1);
      } else {
        tagType = S_TAG;
        tokenName = nTokenName;
      }

    } else {
      tagType = NIL;
      tokenName = nTokenName;
    }

  }

  std::string getTokenName() {
    return tokenName;
  }

  tokenType getTokenType() {
    return tagType;
  }

  std::string getText() {
    return tokenAssociatedText;
  }

  void setAssociatedText(std::string &string) {
    tokenAssociatedText = string;
  }
};