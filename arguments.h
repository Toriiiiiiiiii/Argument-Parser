#pragma once

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#define ARG_REQUIRED 0b00000001
#define ARG_OPTIONAL 0b00000010
#define ARG_POSITIONAL 0b00000100
#define ARG_IMPLIED 0b00001000

typedef struct {
  uint8_t argumentType;
  std::string flag;
  std::string name;

  bool used;
} ArgumentTemplate;

typedef struct {
  std::string name;
  std::string value;
} Argument;

class ArgumentParser {
private:
  char **argv;
  int argc;

public:
  std::vector<std::string> argumentString;
  std::vector<ArgumentTemplate> usage;

  ArgumentParser(int argc, char **argv, std::vector<ArgumentTemplate> usage);
  ~ArgumentParser();

  bool parseArguments(std::vector<Argument> &args);

  bool argumentExists(std::vector<Argument> args, std::string name);
  Argument getArgByName(std::vector<Argument> args, std::string name);
};
