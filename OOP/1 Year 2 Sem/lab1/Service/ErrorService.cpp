#include "ErrorService.h"

#include <string>

using namespace std;

const string InputException::Messages::InvalidInput = "Invalid input. Try again.";

const string NotFoundException::Messages::noItem = "This item does not exist.";
const string NotFoundException::Messages::noID = "This ID does not exist.";

const string StateException::Messages::EmptyList = "The shape list is empty.";

const string ValidationException::Messages::InvalidName = "This name cannot be applied.";
const string ValidationException::Messages::InvalidRadius = "Radius must be greater than zero.";
const string ValidationException::Messages::InvalidShape = "This shape cannot exist.";
const string ValidationException::Messages::InvalidThreshold = "Perimeter threshold must be greater than zero.";