#include "token.h"

Token::Token(std::string input) {
  this->input = input;
  this->current = 0;
  this->tokenize();
}

std::string Token::getToken() {
  return this->tokens[this->current];
}

std::string Token::getNextToken() {
  this->current += 1;
  this->getToken();
}

int Token::total() {
  return this->tokens.size();
}

void Token::tokenize(){
  size_t start = this->input.find_first_not_of(DELIMITER), end=start;
  while (start != std::string::npos) {
    end = this->input.find(DELIMITER, start);
    this->tokens.push_back(this->input.substr(start, end-start));
    start = this->input.find_first_not_of(DELIMITER, end);
  }

  this->current = 0;
}