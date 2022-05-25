

#include "Server.hpp"
#include "User.hpp"
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

User::User(int sd, std::string ip) : socket_descriptor(sd), registered(0), name("Guest"), nickname("Guest"), ip(ip)
{
	nickname.append(to_str(sd));
	debug(US, presentation(), NOCR);
	debug(US, "CONNECTED");
}

User::User( const User & src )
{
    (void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

User::~User()
{
	debug(US, presentation(), NOCR);
	debug(US, "CLOSED");
	std::cout << "NEED TO LEAVE ALL CHANS" << std::endl;
	joined_chans.clear();
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

User &				User::operator=( User const & rhs )
{

    (void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, User const & i )
{
    (void)i;
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	User::presentation( void )
{
	std::string to_ret(nickname);
	to_ret = to_ret + "[" + ip + ":" + to_str(socket_descriptor) + "] - ";
	return (to_ret);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


void        User::setName(std::string newName)
{
    this->name = trim(newName); 
}

void        User::setNickName(std::string newNickName)
{
    this->nickname = trim(newNickName); 
}

void        User::setSocket(int sd)
{
    this->socket_descriptor = sd;
}

void        User::joinChan(Channel *chan)
{
    this->joined_chans.push_back(chan);
}

void        User::leaveChan(Channel *chan)
{
    for (std::vector<Channel *>::iterator it = joined_chans.begin(); it != joined_chans.end(); it++)
    {
        if (*it == chan)
        {
            this->joined_chans.erase(it);
            chan->remove_user(this);
        }
    }
}

std::string const & User::getName()
{
    return (this->name);
}

std::vector<Channel *> const & User::getJoinedChannels()
{
    return (this->joined_chans);
}

/* ************************************************************************** */
