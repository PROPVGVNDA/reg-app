#include "../include/User.h"

User::User(const std::string& t_Username, const std::string& t_Password)
	: m_Username(t_Username), m_Password(t_Password)
{
}

const std::string& User::GetUsername() const
{
	return m_Username;
}

const std::string& User::GetPassword() const
{
	return m_Password;
}

std::ofstream& operator<<(std::ofstream& stream, const User& user)
{
	stream << user.GetUsername() << " " << user.m_Password << '\n';
	return stream;
}
