#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "User.h"
#include <vector>

// Writes to file, reads from file, redirects to InputHandler operation
class Controller
{
public:
	// Redirects to InputHandler to create new user
	// Writes new user information provided by InputHandler into file
	// Appends new user to vector of existing users
	static void RegisterNewUser(std::vector<User>& existing_users);

	// Redirects to InputHandler to log user in
	// Returns a pair of user and bool returned from InputHandler, SEE: InputHandler
	static std::pair<User, bool> LogInUser(const std::vector<User>& existing_users);

	// Reads from file and returns vector of existing users read from file
	static std::vector<User> LoadExistingUsers();

	// Changes existing user's password, updates information in file
	static void ChangePassword(const User& user, std::vector<User>& existing_users);
private:
	static const char kFilename[];
};

#endif