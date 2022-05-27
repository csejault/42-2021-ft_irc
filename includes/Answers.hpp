#ifndef ANSWERS_HPP
# define ANSWERS_HPP 

/*
**	@file  answers.hpp
**	@brief manage anwers 
*/


#include "Server.hpp"
#include "User.hpp"
#include "Commands.hpp"
#include "Debug.hpp"



#include "numeric_rpl.hpp"


/*
**  Define messages 
*/

#define NONE		""
#define MSG_001		":Welcome to the Internet Relay Network of Clement and Claire " + user->nickname + "!" + user->name + "@" + "localhost"
#define MSG_002		":Your host is localhost, version 1.0   8-)"
#define MSG_003		":This server was created not so long time ago."
#define MSG_004		":You are very welcome. Enjoy !"
#define MSG_324 	":" + arg1 + "<mode> <mode_params>" 	/* RPL_CHANNELMODEIS */
#define MSG_331		 arg1 + " :No topic is set."
#define MSG_332		 arg1 + " :" + arg2 	/* RPL_TOPIC */
#define MSG_341		 ":" + arg1 + " " + user->nickname
#define MSG_353		 "= " + arg1 + " :" + printNames(s.chans[arg1])  // il faut le serveur ou le chan a minima                    //CHANGER EN FO Status" 
#define MSG_366		 	arg1 + " :End of NAMES list"  
#define ERR_403		  arg1 + " :No such channel" 							/* ERR_NOSUCHCHANNEL */

#define ERR_404		   arg1 + " :Cannot send to channel"  		/* ERR_CANNOTSENDTOCHAN */ 

#define ERR_441		  arg1 + " " + arg2 + ": They aren't on that channel" /*ERR_USERNOTINCHANNEL */
#define ERR_443		  arg1 + " " + arg2 + " :User already on channel"

#define ERR_461		  arg1 + " :Not enough parameters" 					 	/* ERR_NEEDMOREPARAMS */
#define ERR_462		  ":Unauthorized command (already registered)"  
#define ERR_463		  ":Your host isn't among the privileged"  												/* ERR_NOPERMFORHOST */
#define ERR_464		  ":Password incorrect" 																/* ERR_PASSWDMISMATCH */ 
#define ERR_465		  ":You are banned from this server"
#define ERR_466		  "" //ERR_YOUWILLBEBANNED  , no msg 
#define ERR_467		  arg1 + " :Channel key already set"					/* ERR_KEYSET */ 
#define ERR_471		  arg1 + " :Cannot join channel (+l)" 					/* ERR_CHANNELISFULL */
#define ERR_472		  arg1 + " :is unknown mode char to me for "  + arg2		/* ERR_UNKNOWNMODE */ 
#define ERR_473		  arg1 + " :Cannot join channel (+i) (You must be invited)" 					/* ERR_INVITEONLYCHAN */ 
#define ERR_474		  arg1 + " :Cannot join channel (+b)"  					/* ERR_BANNEDFROMCHAN */    
#define ERR_475		  arg1 + " :Cannot join channel (+k)" 					/* ERR_BADCHANNELKEY */
#define ERR_476		  arg1 + " :Bad Channel Mask" 							/* ERR_BADCHANMASK */
#define ERR_477		  arg1 + " :Channel doesn't support modes" 				/* ERR_NOCHANMODES */
#define ERR_478		  arg1 + " :Channel list is full" 				       /* ERR_BANLISTFULL */
#define ERR_482		  arg1 + " :You're not channel operator"				/* ERR_CHANOPRIVSNEEDED */


 #define MSG_001        ":Welcome to the Internet Relay Network <nick>!<user>@<host> The first message sent after client registration. The text used varies widely" /* RPL_WELCOME */
 #define MSG_002        ":Your host is <servername>, running version <version> Part of the post-registration greeting. Text varies widely" /* RPL_YOURHOST */
 #define MSG_003        ":This server was created <date> Part of the post-registration greeting. Text varies widely" /* RPL_CREATED */
 #define MSG_004        "<server_name> <version> <user_modes> <chan_modes> Part of the post-registration greeting" /* RPL_MYINFO */
 #define MSG_004        "<server_name> <version> <user_modes> <chan_modes> <channel_modes_with_params> <user_modes_with_params> <server_modes> <server_modes_with_params> Same as RFC2812 however with additional fields to avoid additional 005 burden." /* RPL_MYINFO */
 #define MSG_005        ":Try server <server_name>, port <port_number> Sent by the server to a user to suggest an alternative server, sometimes used when the connection is refused because the server is already full. Also known as RPL_SLINE (AustHex), and RPL_REDIR Also see #010." /* RPL_BOUNCE */
 #define MSG_200        "Link <version>[.<debug_level>] <destination> <next_server> [V<protocol_version> <link_uptime_in_seconds> <backstream_sendq> <upstream_sendq>] See RFC" /* RPL_TRACELINK */
 #define MSG_201        "Try. <class> <server> See RFC" /* RPL_TRACECONNECTING */
 #define MSG_202        "H.S. <class> <server> See RFC" /* RPL_TRACEHANDSHAKE */
 #define MSG_203        "???? <class> [<connection_address>] See RFC" /* RPL_TRACEUNKNOWN */
 #define MSG_204        "Oper <class> <nick> See RFC" /* RPL_TRACEOPERATOR */
 #define MSG_205        "User <class> <nick> See RFC" /* RPL_TRACEUSER */
 #define MSG_206        "Serv <class> <int>S <int>C <server> <nick!user|*!*>@<host|server> [V<protocol_version>] See RFC" /* RPL_TRACESERVER */
 #define MSG_207        "Service <class> <name> <type> <active_type> See RFC" /* RPL_TRACESERVICE */
 #define MSG_208        "<newtype> 0 <client_name> See RFC" /* RPL_TRACENEWTYPE */
 #define MSG_209        "Class <class> <count> See RFC" /* RPL_TRACECLASS */
 #define MSG_210        "" /* RPL_TRACERECONNECT */
 #define MSG_211        "<linkname> <sendq> <sent_msgs> <sent_bytes> <recvd_msgs> <rcvd_bytes> <time_open> Reply to STATS (See RFC)" /* RPL_STATSLINKINFO */
 #define MSG_212        "<command> <count> [<byte_count> <remote_count>] Reply to STATS (See RFC)" /* RPL_STATSCOMMANDS */
 #define MSG_213        "C <host> * <name> <port> <class> Reply to STATS (See RFC)" /* RPL_STATSCLINE */
 #define MSG_214        "N <host> * <name> <port> <class> Reply to STATS (See RFC), Also known as RPL_STATSOLDNLINE (ircu, Unreal)" /* RPL_STATSNLINE */
 #define MSG_215        "I <host> * <host> <port> <class> Reply to STATS (See RFC)" /* RPL_STATSILINE */
 #define MSG_216        "K <host> * <username> <port> <class> Reply to STATS (See RFC)" /* RPL_STATSKLINE */
 #define MSG_217        "" /* RPL_STATSQLINE */
 #define MSG_218        "Y <class> <ping_freq> <connect_freq> <max_sendq> Reply to STATS (See RFC)" /* RPL_STATSYLINE */
 #define MSG_219        "<query> :<info> End of RPL_STATS* list." /* RPL_ENDOFSTATS */
 #define MSG_221        "<user_modes> [<user_mode_params>] Information about a user's own modes. Some daemons have extended the mode command and certain modes take parameters (like channel modes)." /* RPL_UMODEIS */
 #define MSG_231        "" /* RPL_SERVICEINFO */
 #define MSG_232        "" /* RPL_ENDOFSERVICES */
 #define MSG_233        "" /* RPL_SERVICE */
 #define MSG_234        "<name> <server> <mask> <type> <hopcount> <info> A service entry in the service list" /* RPL_SERVLIST */
 #define MSG_235        "<mask> <type> :<info> Termination of an RPL_SERVLIST list" /* RPL_SERVLISTEND */
 #define MSG_240        "" /* RPL_STATSVLINE */
 #define MSG_241        "L <hostmask> * <servername> <maxdepth> Reply to STATS (See RFC)" /* RPL_STATSLLINE */
 #define MSG_242        ":Server Up <days> days <hours>:<minutes>:<seconds> Reply to STATS (See RFC)" /* RPL_STATSUPTIME */
 #define MSG_243        "O <hostmask> * <nick> [:<info>] Reply to STATS (See RFC); The info field is an extension found in some IRC daemons, which returns info such as an e-mail address or the name/job of an operator" /* RPL_STATSOLINE */
 #define MSG_244        "H <hostmask> * <servername> Reply to STATS (See RFC)" /* RPL_STATSHLINE */
 #define MSG_246        "" /* RPL_STATSPING */
 #define MSG_247        "" /* RPL_STATSBLINE */
 #define MSG_249        "to RFC1459?" /* RPL_STATSULINE */
 #define MSG_250        "" /* RPL_STATSDLINE */
 #define MSG_251        ":There are <int> users and <int> invisible on <int> servers Reply to LUSERS command, other versions exist (eg. RFC2812); Text may vary." /* RPL_LUSERCLIENT */
 #define MSG_252        "<int> :<info> Reply to LUSERS command - Number of IRC operators online" /* RPL_LUSEROP */
 #define MSG_253        "<int> :<info> Reply to LUSERS command - Number of unknown/unregistered connections" /* RPL_LUSERUNKNOWN */
 #define MSG_254        "<int> :<info> Reply to LUSERS command - Number of channels formed" /* RPL_LUSERCHANNELS */
 #define MSG_255        ":I have <int> clients and <int> servers Reply to LUSERS command - Information about local connections; Text may vary." /* RPL_LUSERME */
 #define MSG_256        "<server> :<info> Start of an RPL_ADMIN* reply. In practise, the server parameter is often never given, and instead the info field contains the text 'Administrative info about <server>'. Newer daemons seem to follow the RFC and output the server's hostname in the 'server' parameter, but also output the server name in the text as per traditional daemons." /* RPL_ADMINME */
 #define MSG_257        ":<admin_location> Reply to ADMIN command (Location, first line)" /* RPL_ADMINLOC1 */
 #define MSG_258        ":<admin_location> Reply to ADMIN command (Location, second line)" /* RPL_ADMINLOC2 */
 #define MSG_259        ":<email_address> Reply to ADMIN command (E-mail address of administrator)" /* RPL_ADMINEMAIL */
 #define MSG_261        "File <logfile> <debug_level> See RFC" /* RPL_TRACELOG */
 #define MSG_262        "to RFC1459?" /* RPL_TRACEPING */
 #define MSG_262        "<server_name> <version>[.<debug_level>] :<info> Used to terminate a list of RPL_TRACE* replies" /* RPL_TRACEEND */
 #define MSG_263        "<command> :<info> When a server drops a command without processing it, it MUST use this reply. Also known as RPL_LOAD_THROTTLED and RPL_LOAD2HI, I'm presuming they do the same thing." /* RPL_TRYAGAIN */
 #define MSG_300        "Dummy reply, supposedly only used for debugging/testing new features, however has appeared in production daemons." /* RPL_NONE */
 #define MSG_301        "<nick> :<message> Used in reply to a command directed at a user who is marked as away" /* RPL_AWAY */
 #define MSG_302        ":*1<reply> *( ' ' <reply> ) Reply used by USERHOST (see RFC)" /* RPL_USERHOST */
 #define MSG_303        ":*1<nick> *( ' ' <nick> ) Reply to the ISON command (see RFC)" /* RPL_ISON */
 #define MSG_305        ":<info> Reply from AWAY when no longer marked as away" /* RPL_UNAWAY */
 #define MSG_306        ":<info> Reply from AWAY when marked away" /* RPL_NOWAWAY */
 #define MSG_311        "<nick> <user> <host> * :<real_name> Reply to WHOIS - Information about the user" /* RPL_WHOISUSER */
 #define MSG_312        "<nick> <server> :<server_info> Reply to WHOIS - What server they're on" /* RPL_WHOISSERVER */
 #define MSG_313        "<nick> :<privileges> Reply to WHOIS - User has IRC Operator privileges" /* RPL_WHOISOPERATOR */
 #define MSG_314        "<nick> <user> <host> * :<real_name> Reply to WHOWAS - Information about the user" /* RPL_WHOWASUSER */
 #define MSG_315        "<name> :<info> Used to terminate a list of RPL_WHOREPLY replies" /* RPL_ENDOFWHO */
 #define MSG_316        "" /* RPL_WHOISCHANOP */
 #define MSG_317        "<nick> <seconds> :seconds idle Reply to WHOIS - Idle information" /* RPL_WHOISIDLE */
 #define MSG_318        "<nick> :<info> Reply to WHOIS - End of list" /* RPL_ENDOFWHOIS */
 #define MSG_319        "<nick> :*( ( '@' / '+' ) <channel> ' ' ) Reply to WHOIS - Channel list for user (See RFC)" /* RPL_WHOISCHANNELS */
 #define MSG_321        "Channels :Users Name Channel list - Header" /* RPL_LISTSTART */
 #define MSG_322        "<channel> <#_visible> :<topic> Channel list - A channel" /* RPL_LIST */
 #define MSG_323        ":<info> Channel list - End of list" /* RPL_LISTEND */
 #define MSG_324        "<channel> <mode> <mode_params>" /* RPL_CHANNELMODEIS */
 #define MSG_325        "<channel> <nickname>" /* RPL_UNIQOPIS */
 #define MSG_331        "<channel> :<info> Response to TOPIC when no topic is set" /* RPL_NOTOPIC */
 #define MSG_332        "<channel> :<topic> Response to TOPIC with the set topic" /* RPL_TOPIC */
 #define MSG_341        "<nick> <channel> Returned by the server to indicate that the attempted INVITE message was successful and is being passed onto the end client. Note that RFC1459 documents the parameters in the reverse order. The format given here is the format used on production servers, and should be considered the standard reply above that given by RFC1459." /* RPL_INVITING */
 #define MSG_342        "<user> :<info> Returned by a server answering a SUMMON message to indicate that it is summoning that user" /* RPL_SUMMONING */
 #define MSG_346        "<channel> <invitemask> An invite mask for the invite mask list" /* RPL_INVITELIST */
 #define MSG_347        "<channel> :<info> Termination of an RPL_INVITELIST list" /* RPL_ENDOFINVITELIST */
 #define MSG_348        "<channel> <exceptionmask> An exception mask for the exception mask list. Also known as RPL_EXLIST (Unreal, Ultimate)" /* RPL_EXCEPTLIST */
 #define MSG_349        "<channel> :<info> Termination of an RPL_EXCEPTLIST list. Also known as RPL_ENDOFEXLIST (Unreal, Ultimate)" /* RPL_ENDOFEXCEPTLIST */
 #define MSG_351        "<version>[.<debuglevel>] <server> :<comments> Reply by the server showing its version details, however this format is not often adhered to" /* RPL_VERSION */
 #define MSG_352        "<channel> <user> <host> <server> <nick> <H|G>[*][@|+] :<hopcount> <real_name> Reply to vanilla WHO (See RFC). This format can be very different if the 'WHOX' version of the command is used (see ircu)." /* RPL_WHOREPLY */
 #define MSG_353        "( '=' / '*' / '@' ) <channel> ' ' : [ '@' / '+' ] <nick> *( ' ' [ '@' / '+' ] <nick> ) Reply to NAMES (See RFC)" /* RPL_NAMREPLY */
 #define MSG_354        "Reply to WHO, however it is a 'special' reply because it is returned using a non-standard (non-RFC1459) format. The format is dictated by the command given by the user, and can vary widely. When this is used, the WHO command was invoked in its 'extended' form, as announced by the 'WHOX' ISUPPORT tag." /* RPL_WHOSPCRPL */
 #define MSG_361        "" /* RPL_KILLDONE */
 #define MSG_362        "" /* RPL_CLOSING */
 #define MSG_363        "" /* RPL_CLOSEEND */
 #define MSG_364        "<mask> <server> :<hopcount> <server_info> Reply to the LINKS command" /* RPL_LINKS */
 #define MSG_365        "<mask> :<info> Termination of an RPL_LINKS list" /* RPL_ENDOFLINKS */
 #define MSG_366        "<channel> :<info> Termination of an RPL_NAMREPLY list" /* RPL_ENDOFNAMES */
 #define MSG_367        "<channel> <banid> [<time_left> :<reason>] A ban-list item (See RFC); <time left> and <reason> are additions used by KineIRCd" /* RPL_BANLIST */
 #define MSG_368        "<channel> :<info> Termination of an RPL_BANLIST list" /* RPL_ENDOFBANLIST */
 #define MSG_369        "<nick> :<info> Reply to WHOWAS - End of list" /* RPL_ENDOFWHOWAS */
 #define MSG_371        ":<string> Reply to INFO" /* RPL_INFO */
 #define MSG_372        ":- <string> Reply to MOTD" /* RPL_MOTD */
 #define MSG_373        "" /* RPL_INFOSTART */
 #define MSG_374        ":<info> Termination of an RPL_INFO list" /* RPL_ENDOFINFO */
 #define MSG_375        ":- <server> Message of the day - Start of an RPL_MOTD list" /* RPL_MOTDSTART */
 #define MSG_376        ":<info> Termination of an RPL_MOTD list" /* RPL_ENDOFMOTD */
 #define MSG_381        ":<info> Successful reply from OPER" /* RPL_YOUREOPER */
 #define MSG_382        "<config_file> :<info> Successful reply from REHASH" /* RPL_REHASHING */
 #define MSG_383        ":You are service <service_name> Sent upon successful registration of a service" /* RPL_YOURESERVICE */
 #define MSG_384        "" /* RPL_MYPORTIS */
 #define MSG_391        "<server> :<time string> Response to the TIME command. The string format may vary greatly. Also see #679." /* RPL_TIME */
 #define MSG_392        ":UserID Terminal Host Start of an RPL_USERS list" /* RPL_USERSSTART */
 #define MSG_393        ":<username> <ttyline> <hostname> Response to the USERS command (See RFC)" /* RPL_USERS */
 #define MSG_394        ":<info> Termination of an RPL_USERS list" /* RPL_ENDOFUSERS */
 #define MSG_395        ":<info> Reply to USERS when nobody is logged in" /* RPL_NOUSERS */
 #define MSG_401        "<nick> :<reason> Used to indicate the nickname parameter supplied to a command is currently unused" /* ERR_NOSUCHNICK */
 #define MSG_402        "<server> :<reason> Used to indicate the server name given currently doesn't exist" /* ERR_NOSUCHSERVER */
 #define MSG_403        "<channel> :<reason> Used to indicate the given channel name is invalid, or does not exist" /* ERR_NOSUCHCHANNEL */
 #define MSG_404        "<channel> :<reason> Sent to a user who does not have the rights to send a message to a channel" /* ERR_CANNOTSENDTOCHAN */
 #define MSG_405        "<channel> :<reason> Sent to a user when they have joined the maximum number of allowed channels and they tried to join another channel" /* ERR_TOOMANYCHANNELS */
 #define MSG_406        "<nick> :<reason> Returned by WHOWAS to indicate there was no history information for a given nickname" /* ERR_WASNOSUCHNICK */
 #define MSG_407        "<target> :<reason> The given target(s) for a command are ambiguous in that they relate to too many targets" /* ERR_TOOMANYTARGETS */
 #define MSG_408        "<service_name> :<reason> Returned to a client which is attempting to send an SQUERY (or other message) to a service which does not exist" /* ERR_NOSUCHSERVICE */
 #define MSG_409        ":<reason> PING or PONG message missing the originator parameter which is required since these commands must work without valid prefixes" /* ERR_NOORIGIN */
 #define MSG_411        ":<reason> Returned when no recipient is given with a command" /* ERR_NORECIPIENT */
 #define MSG_412        ":<reason> Returned when NOTICE/PRIVMSG is used with no message given" /* ERR_NOTEXTTOSEND */
 #define MSG_413        "<mask> :<reason> Used when a message is being sent to a mask without being limited to a top-level domain (i.e. * instead of *.au)" /* ERR_NOTOPLEVEL */
 #define MSG_414        "<mask> :<reason> Used when a message is being sent to a mask with a wild-card for a top level domain (i.e. *.*)" /* ERR_WILDTOPLEVEL */
 #define MSG_415        "<mask> :<reason> Used when a message is being sent to a mask with an invalid syntax" /* ERR_BADMASK */
 #define MSG_421        "<command> :<reason> Returned when the given command is unknown to the server (or hidden because of lack of access rights)" /* ERR_UNKNOWNCOMMAND */
 #define MSG_422        ":<reason> Sent when there is no MOTD to send the client" /* ERR_NOMOTD */
 #define MSG_423        "<server> :<reason> Returned by a server in response to an ADMIN request when no information is available. RFC1459 mentions this in the list of numerics. While it's not listed as a valid reply in section 4.3.7 ('Admin command'), it's confirmed to exist in the real world." /* ERR_NOADMININFO */
 #define MSG_424        ":<reason> Generic error message used to report a failed file operation during the processing of a command" /* ERR_FILEERROR */
 #define MSG_431        ":<reason> Returned when a nickname parameter expected for a command isn't found" /* ERR_NONICKNAMEGIVEN */
 #define MSG_432        "<nick> :<reason> Returned after receiving a NICK message which contains a nickname which is considered invalid, such as it's reserved ('anonymous') or contains characters considered invalid for nicknames. This numeric is misspelt, but remains with this name for historical reasons :)" /* ERR_ERRONEUSNICKNAME */
 #define MSG_433        "<nick> :<reason> Returned by the NICK command when the given nickname is already in use" /* ERR_NICKNAMEINUSE */
 #define MSG_436        "<nick> :<reason> Returned by a server to a client when it detects a nickname collision" /* ERR_NICKCOLLISION */
 #define MSG_437        "<nick/channel/service> :<reason> Return when the target is unable to be reached temporarily, eg. a delay mechanism in play, or a service being offline" /* ERR_UNAVAILRESOURCE */
 #define MSG_441        "<nick> <channel> :<reason> Returned by the server to indicate that the target user of the command is not on the given channel" /* ERR_USERNOTINCHANNEL */
 #define MSG_442        "<channel> :<reason> Returned by the server whenever a client tries to perform a channel effecting command for which the client is not a member" /* ERR_NOTONCHANNEL */
 #define MSG_443        "<nick> <channel> [:<reason>] Returned when a client tries to invite a user to a channel they're already on" /* ERR_USERONCHANNEL */
 #define MSG_444        "<user> :<reason> Returned by the SUMMON command if a given user was not logged in and could not be summoned" /* ERR_NOLOGIN */
 #define MSG_445        ":<reason> Returned by SUMMON when it has been disabled or not implemented" /* ERR_SUMMONDISABLED */
 #define MSG_446        ":<reason> Returned by USERS when it has been disabled or not implemented" /* ERR_USERSDISABLED */
 #define MSG_451        ":<reason> Returned by the server to indicate that the client must be registered before the server will allow it to be parsed in detail" /* ERR_NOTREGISTERED */
 #define MSG_461        "<command> :<reason> Returned by the server by any command which requires more parameters than the number of parameters given" /* ERR_NEEDMOREPARAMS */
 #define MSG_462        ":<reason> Returned by the server to any link which attempts to register again" /* ERR_ALREADYREGISTERED */
 #define MSG_463        ":<reason> Returned to a client which attempts to register with a server which has been configured to refuse connections from the client's host" /* ERR_NOPERMFORHOST */
 #define MSG_464        ":<reason> Returned by the PASS command to indicate the given password was required and was either not given or was incorrect" /* ERR_PASSWDMISMATCH */
 #define MSG_465        ":<reason> Returned to a client after an attempt to register on a server configured to ban connections from that client" /* ERR_YOUREBANNEDCREEP */
 #define MSG_466        "Sent by a server to a user to inform that access to the server will soon be denied" /* ERR_YOUWILLBEBANNED */
 #define MSG_467        "<channel> :<reason> Returned when the channel key for a channel has already been set" /* ERR_KEYSET */
 #define MSG_471        "<channel> :<reason> Returned when attempting to join a channel which is set +l and is already full" /* ERR_CHANNELISFULL */
 #define MSG_472        "<char> :<reason> Returned when a given mode is unknown" /* ERR_UNKNOWNMODE */
 #define MSG_473        "<channel> :<reason> Returned when attempting to join a channel which is invite only without an invitation" /* ERR_INVITEONLYCHAN */
 #define MSG_474        "<channel> :<reason> Returned when attempting to join a channel a user is banned from" /* ERR_BANNEDFROMCHAN */
 #define MSG_475        "<channel> :<reason> Returned when attempting to join a key-locked channel either without a key or with the wrong key" /* ERR_BADCHANNELKEY */
 #define MSG_476        "<channel> :<reason> The given channel mask was invalid" /* ERR_BADCHANMASK */
 #define MSG_477        "<channel> :<reason> Returned when attempting to set a mode on a channel which does not support channel modes, or channel mode changes. Also known as ERR_MODELESS" /* ERR_NOCHANMODES */
 #define MSG_478        "<channel> <char> :<reason> Returned when a channel access list (i.e. ban list etc) is full and cannot be added to" /* ERR_BANLISTFULL */
 #define MSG_481        ":<reason> Returned by any command requiring special privileges (eg. IRC operator) to indicate the operation was unsuccessful" /* ERR_NOPRIVILEGES */
 #define MSG_482        "<channel> :<reason> Returned by any command requiring special channel privileges (eg. channel operator) to indicate the operation was unsuccessful" /* ERR_CHANOPRIVSNEEDED */
 #define MSG_483        ":<reason> Returned by KILL to anyone who tries to kill a server" /* ERR_CANTKILLSERVER */
 #define MSG_484        ":<reason> Sent by the server to a user upon connection to indicate the restricted nature of the connection (i.e. usermode +r)" /* ERR_RESTRICTED */
 #define MSG_485        ":<reason> Any mode requiring 'channel creator' privileges returns this error if the client is attempting to use it while not a channel creator on the given channel" /* ERR_UNIQOPRIVSNEEDED */
 #define MSG_491        ":<reason> Returned by OPER to a client who cannot become an IRC operator because the server has been configured to disallow the client's host" /* ERR_NOOPERHOST */
 #define MSG_492        "" /* ERR_NOSERVICEHOST */
 #define MSG_501        ":<reason> Returned by the server to indicate that a MODE message was sent with a nickname parameter and that the mode flag sent was not recognised" /* ERR_UMODEUNKNOWNFLAG */
 #define MSG_502        ":<reason> Error sent to any user trying to view or change the user mode for a user other than themselves" /* ERR_USERSDONTMATCH */

/*
**      Numeric Replies : 
**      Functions pointed in server_replies returning content of define messages 
*/

inline std::string		RPL_001 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)arg1; (void)arg2; (void)arg3; return (MSG_001); }
inline std::string		RPL_002 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (MSG_002); }
inline std::string		RPL_003 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (MSG_003); }
inline std::string		RPL_004 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (MSG_004); }
inline std::string		RPL_324 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (MSG_324); }   //RPL INVITING 
inline std::string		RPL_331 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (MSG_331); }   //RPL INVITING 
inline std::string		RPL_332 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (MSG_332); }   //RPL INVITING 
inline std::string		RPL_341 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (MSG_341); }   //RPL INVITING 
inline std::string		RPL_353 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (MSG_353); }   /* RPL_NAMREPLY */
inline std::string		RPL_366 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (MSG_366); }   /* RPL_ENDNAME  */ 
inline std::string		RPL_403 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (ERR_403); }   /* RPL_ENDNAME  */ 
inline std::string		RPL_404 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (ERR_404); }   /* RPL_ENDNAME  */ 
inline std::string		RPL_442 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (ERR_442); }   /* RPL_ENDNAME  */ 
inline std::string		RPL_443 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (ERR_443); }   /* RPL_ENDNAME  */ 
inline std::string		RPL_461 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (ERR_461); }   /* RPL_ENDNAME  */ 
inline std::string		RPL_462 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (ERR_462); }   /* RPL_ENDNAME  */ 
inline std::string		RPL_463 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (ERR_463); }   /* RPL_ENDNAME  */ 
inline std::string		RPL_464 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (ERR_464); }   /* RPL_ENDNAME  */ 
inline std::string		RPL_465 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (ERR_465); }   /* RPL_ENDNAME  */ 
inline std::string		RPL_466 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (ERR_466); }   /* RPL_ENDNAME  */ 
inline std::string		RPL_467 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (ERR_467); }   /* RPL_ENDNAME  */ 
inline std::string		RPL_471 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (ERR_471); }   /* RPL_ENDNAME  */ 
inline std::string		RPL_472 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (ERR_472); }   /* RPL_ENDNAME  */ 
inline std::string		RPL_473 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (ERR_473); }   /* RPL_ENDNAME  */ 
inline std::string		RPL_474 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (ERR_474); }   /* RPL_ENDNAME  */ 
inline std::string		RPL_475 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (ERR_475); }   /* RPL_ENDNAME  */ 
inline std::string		RPL_476 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (ERR_476); }   /* RPL_ENDNAME  */ 
inline std::string		RPL_477 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (ERR_477); }   /* RPL_ENDNAME  */ 
inline std::string		RPL_478 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (ERR_478); }   /* RPL_ENDNAME  */ 
inline std::string		RPL_482 (Server &s, User *user, std::string arg1, std::string arg2, std::string arg3) { (void)s; (void)user; (void)arg1; (void)arg2; (void)arg3; return (ERR_482); }   /* RPL_ENDNAME  */ 





/*
**  Server_relay
**  @brief non numeric replies. Just relay in course command to 
**  @tparam T : others users, specified in user_list (corresponding to server_users or just a specific
**  channel users) 
**  OR
**  @tparam <> : total specialization for User *
**  Their shape is : :<nick>!<user>@<host> <cmd> [<param>] :<msg>
*/
template <typename T> 
inline std::string server_relay(const User *u, std::vector<std::string> cmd, T user_list) 
{
	std::string txt;
	txt.append(":");
	txt.append(u->nickname);
	txt.append("!");
	txt.append(u->name); //username
	txt.append("@localhost ");
	for (std::vector<std::string>::iterator it = cmd.begin(); it != cmd.end() && *it != "\n"; it++)
		txt.append(*it + " "); // on met touts les commandes dans le prefixe 
	txt = trim(txt);
	 txt.append("\r\n");
	out(FG2("Server Reply to be sent: (server relay)"));
	out (txt)
	for (typename T::iterator ite = user_list.begin(); ite != user_list.end(); ite++)
	   send(ite->second->socket_descriptor, txt.c_str(), txt.length(), 0); // send to all 
	return ((txt));
}

template <> // specialisation si un seul envoi a effectuer
inline std::string server_relay(const User *u, std::vector<std::string> cmd, User *receiver) 
{
	std::string txt;
	txt.append(":");
	txt.append(u->nickname);
	txt.append("!");
	txt.append(u->name); //username
	txt.append("@localhost ");
	for (std::vector<std::string>::iterator it = cmd.begin(); it != cmd.end() && *it != "\n"; it++)
		txt.append(*it + " "); // on met touts les commandes dans le prefixe 
	txt = trim(txt);
	 txt.append("\r\n");
	out(FG2("Server Reply to be sent: (server relay)"));
	out (txt)
	send(receiver->socket_descriptor, txt.c_str(), txt.length(), 0);
	return ((txt));
}

/*
**  Numeric Replies 
**  @brief  numeric replies sent back to client after a request
**
**  Their shape is : :<host> <3digits> <nickname> : [...] (depends on the answer)
*/


inline std::string     Server::choose_msg(int code, User *u, std::string arg1, std::string arg2, std::string arg3)
{
	start;
	out ("anwer code " << code)
	if (cmds.server_replies.count(code) != 1)
	{
		out ("==> Unfound server_replies");
		return ("(no reply found)");
	}
	return (*(cmds.server_replies.find(code)->second))(*this, u, arg1, arg2, arg3); // second = la function
}


inline void            Server::numeric_reply(User *u, std::string code, std::string arg1, std::string arg2, std::string arg3) // rajouter autre chose pour le channel par ex ? //numeric reply 
{
	start;
	std::string txt;
	char *ptr;
	txt.append(":");
	txt.append("localhost "); // remplacer par le define
	txt.append(code);
	txt.append(" ");
	txt.append(u->nickname); // lui qui va servir commenickname
	txt.append(" ");
	txt.append(choose_msg(std::strtol(code.c_str(), &ptr, 10), u, arg1, arg2, arg3));
	txt.append("\r\n");
	
	out(FG2("Server Reply to be sent:") << code);
	out(txt.c_str());
	if (send(u->socket_descriptor, txt.c_str(), txt.length(), 0) < 0)
	{
		perror("SEND FAILED");
	}
}

#endif 