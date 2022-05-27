
#include "Server.hpp"
#include "Answers.hpp"

/*
**    Command: MODE (channel)
**    Parameters: <channel> *( ( "-" / "+" ) *<modes> *<modeparams> )
**
**    The MODE command is provided so that users may query and change the
**    characteristics of a channel.  For more details on available modes
**    and their uses, see "Internet Relay Chat: Channel Management" [IRC-
**    CHAN].  Note that there is a maximum limit of three (3) changes per
**    command for modes that take a parameter.
**
**    Numeric Replies:
**
**            ERR_NEEDMOREPARAMS              ERR_KEYSET
**            ERR_NOCHANMODES  ok               ERR_CHANOPRIVSNEEDED ok
**            ERR_USERNOTINCHANNEL            ERR_UNKNOWNMODE
**            RPL_CHANNELMODEIS
**            RPL_BANLIST                     RPL_ENDOFBANLIST
**            RPL_EXCEPTLIST (mask etc)       RPL_ENDOFEXCEPTLIST
**            RPL_INVITELIST                  RPL_ENDOFINVITELIST
**            RPL_UNIQOPIS
*/
// MODE #TRUC -/+[options] [mode params]

/*
**    The various modes available for channels are as follows:
**
**         O - give "channel creator" status;               // VECTOR LIST
**         o - give/take channel operator privilege;        // VECTOR LIST
**         v - give/take the voice privilege;               // VECTOR LIST
**
**         a - toggle the anonymous channel flag;
**         i - toggle the invite-only channel flag;
**         m - toggle the moderated channel;
**         n - toggle the no messages to channel from clients on the
**             outside;
**         q - toggle the quiet channel flag;
**         p - toggle the private channel flag;
**         s - toggle the secret channel flag;
**         r - toggle the server reop channel flag;
**         t - toggle the topic settable by channel operator only flag;
**
**         k - set/remove the channel key (password);
**         l - set/remove the user limit to channel;
**
**         b - set/remove ban mask to keep users out;
**         e - set/remove an exception mask to override a ban mask;
**         I - set/remove an invitation mask to automatically override
**             the invite-only flag;
*/

void Commands::mode(Server &s, User *u, std::vector<std::string> cmd)
{
	std::string target = *(cmd.begin() + 1);
	if (target[0] == '+') // ne supportent pas les chans modes
		return (s.numeric_reply(u, ERR_NOCHANMODES, target, NONE, NONE));
	if (target[0] == '#') // ou & ....
	{
		std::string empty = " lol";
		std::string chan_name = cmd.size() > 1 ? *(cmd.begin() + 1) : ""; // #truc
		std::string modes = cmd.size() > 2 ? *(cmd.begin() + 2) : "";	  // +=....
		std::vector<std::string> mode_params;
		(cmd.size() > 3) ? (mode_params.insert(mode_params.begin(), cmd.begin() + 3, cmd.end())) : (mode_params.push_back("")); // tout le reste n fait
		// si modes c un +, faut un troisieme cmd ssi K par ex
		if (!s.chanExists(chan_name))
		{
			out("Chan does not exist") // une erreur surement
				return;
		}
		else
		{
			Channel *chan = s.chans[chan_name];

			// if (modes[0]) ni un - ou +, trouver quoi retrouner
			bool value = modes[0] == '+' ? true : false;
			for (size_t i = 1; i < modes.length(); i++)
			{
				/* A voir. Mode query pour limit par ex (flag l doit etre possible 4.2.9 rfc 2811) */ 
				/* hypothese : si pas de valeur on voit genre MODE e, a tester */ 
				if (!chan->isOperator(u)) // Only privileged (eg op and creator) can change modes
					s.numeric_reply(u, ERR_CHANOPRIVSNEEDED, chan->_name, NONE, NONE);
				std::string res = chan->setMode(u, modes[i], value, mode_params);
				if (res.length() != 0)
					s.numeric_reply(u, res, chan->_name, NONE, NONE);
				else
				{
					s.numeric_reply(u, RPL_CHANNELMODEIS, chan->_name, modes, vecToString(mode_params)); //
					server_relay(u, cmd, chan->getUsers());
				}
			}
			chan->displayModes();
		}
	}
	else // mode des gens ? 
	{
	}
}
