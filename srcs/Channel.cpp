/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 09:59:07 by ldes-cou          #+#    #+#             */
/*   Updated: 2022/05/18 12:07:31 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Channel::Channel() : _owner(0)
{
	
}


Channel::Channel(std::string name, User *creator):  _name(name), _topic("")
{
	_owner = creator;
	out ("Creator :" << _owner->nickname)
	out ("Creator :" << creator->nickname)

	_users.insert(std::pair<std::string *, User *>(&_owner->nickname, _owner));
	out ("List of users :")
	for (std::map<std::string *, User *>::iterator it = _users.begin(); it != _users.end(); it++)
		out ("USERS : " << *it->first);
	_operators.push_back(_owner);
	std::cout << "a new chan " << *this << " has been created" << std::endl;
}

Channel::Channel( const Channel & src ): _name(src._name), _owner(src._owner)
{
	(void)src;
	//if ( this != &src )
	//{
		//this->_value = src.getValue();
	//}
	//return (*this);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Channel::~Channel()
{

}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Channel &				Channel::operator=( Channel const & rhs )
{
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Channel& i )
{
	o << i.getName() << std::endl;
	return o;
}



/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string& 				Channel::getName() //const 
{
	return _name;
	
}
std::map<std::string *, User *>& 	Channel::getUsers() //const 
{
	start;
	for (std::map<std::string *, User *>::iterator it = _users.begin(); it != _users.end(); it++)
		out ("USERS : " << *it->first);
	return _users;
}

/*
**	Prints the chan _users map (std::map<std::string *, User *>).  
*/
void	Channel::printUsers() //const 
{
	start;
	for (std::map<std::string *, User *>::iterator it = _users.begin(); it != _users.end(); it++)
		out ("USERS : " << *it->first); //show the nick name 
}

/*
** --------------------------------- OTHERS ----------------------------------
*/
// void Channel::ban(User kicked)
// {
// 	_banned.push_back(kicked);
// 	std::vector<User>::iterator kick;
// 	kick = std::find(_users.begin(), _users.end(), kicked);
// 	if (kick != _users.end())
// 		_users.erase(kick);
// 	else
// 		std::cout << "this users doesn't exist" << std::endl;
// }

bool Channel::isTopicSet()
{
	if (_topic != "")
		return true;
	return false;
}

bool Channel::isInChan(User *u)
{
	if (_users.count(&u->nickname) == 1)
		return true;
	return false;
}



//add a new_user, what happends if the name already exists ?
void Channel::add_user(User *new_user)
{
	start;
	_users.insert(std::pair<std::string *, User *>(&new_user->nickname, new_user));
	std::cout << "Added users" << std::endl;
}

void Channel::remove_user(User *new_user)
{
	start;
	if (isInChan(new_user))
	{
		_users.erase(&new_user->nickname);
		std::cout << "Deleted users" << std::endl;
	}
	else
		out("Unfound user : cannot remove from " << this->_name);
}

// void Channel::add_operator(User admin)
// {
// 	std::vector<User>::iterator add;
// 	add = std::find(_operators.begin(), _operators.end(), admin);
// 	if (add != _operators.end())
// 		_operators.push_back(admin);
// 	else
// 		std::cout << "this operator already exist" << std::endl;	
// }

// void	Channel::me()
// {
// 	// std::vector<User>::iterator it;
// 	// for (it = _users.begin(); it < _users.end(); it++)
// 	// 	std::cout << *it << std::endl;
// }

void	Channel::set_topic(std::string topic)
{
	this->_topic = topic;
}
// //Channel::invite 
// //Channel::names ==> list connected users 

// /* ************************************************************************** */