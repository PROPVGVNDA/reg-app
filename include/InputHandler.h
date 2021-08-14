#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <string>
#include <vector>
#include <User.h>

// Handles user's input to create new users and change existing
class InputHandler
{
public:
	// Gets input from User
	// Creates and returns new user with given input
	// Vector of existing users is required to check if username is taken
	static User GetNewUser(const std::vector<User>& existing_users);

	// Creates and reutrns new user with given username, and password provided from input
	static User GetUserWithNewPassword(const std::string& username);

	// Returns a pair of user and true, if user exists
	// Returns a pair of empty User and false otherwise
	static std::pair<User, bool> GetExistingUser(const std::vector<User>& existing_users);
private:
	// Deletes forbidden characters from given string
	static void pValidateUsername(std::string& username);

	// Iterates over vector of existing users and returns false if given username is taken
	// Returns true otherwise
	static bool pIsUsernameUnique(const std::vector<User>& existing_users, const std::string& username);
};

#endif