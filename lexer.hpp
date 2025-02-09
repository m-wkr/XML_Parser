#pragma once

#include <deque>
#include "token.hpp"


std::deque<token> tokenizer(std::string &&rawString);

void printQueueItems(std::deque<token> &queue);