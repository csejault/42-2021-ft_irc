#include "Server.hpp"
#include "Answers.hpp"

/*
**    Command: NICK
**    Parameters: <nickname>
** 
**    NICK command is used to give user a nickname or change the existing
**    one.
** 
**    Numeric Replies:
** 
**            ERR_NONICKNAMEGIVEN             ERR_ERRONEUSNICKNAME
**            ERR_NICKNAMEINUSE               ERR_NICKCOLLISION
**            ERR_UNAVAILRESOURCE             ERR_RESTRICTED
** 
**    Examples:
** 
**    NICK Wiz                ; Introducing new nick "Wiz" if session is
**                            still unregistered, or user changing his
**                            nickname to "Wiz"
** 
**    :WiZ!jto@tolsun.oulu.fi NICK Kilroy
**                            ; Server telling that WiZ changed his
**                            nickname to Kilroy.
*/

void Commands::nick(Server &s, User *u, std::vector<std::string> cmd)
{
	start;
	out (u->nickname);
	if (u->registered[User::NICK] == false)
	{
		out (BOLD("Setting nickname to ") << *(cmd.begin() + 1));
		u->registered[User::NICK] = true;
	}	
	else if (u->registered[User::NICK] == true)
	{
		out (BOLD("Changing nick name from ") << u->nickname << " to " << *(cmd.begin() + 1));
		server_relay(u, cmd, s.server_users);
	}
	if (u->HasCompletedRegistration() == true && u->registered[User::WELCOMED] == false)
	{
		s.numeric_reply(u, "001", u);
		s.numeric_reply(u, "002", u);
		s.numeric_reply(u, "003", u);
		s.numeric_reply(u, "004", u);
		u->registered[User::WELCOMED] = true;
		out("Answer sent to " << u->socket_descriptor);
	}
	u->setNickName(*(cmd.begin() + 1));
}