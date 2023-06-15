#ifndef CGISOCKET_HPP
# define CGISOCKET_HPP

class CgiSocket;

# include "ASocket.hpp"
# include "Buffer.hpp"
# include "Request.hpp"
# include "Response.hpp"
# include "FDList.hpp"
# include <sys/time.h>


class CgiSocket : public ASocket
{
	private :
		CgiSocket();

	protected:
		struct timespec _lastInterTime;

	public :
		CgiSocket(int fd);
		virtual ~CgiSocket();

		virtual int	getFd(void) const;
		virtual void read(Config *datas, FDList *listFD);
		virtual void write(Config *datas, FDList *listFD);
		virtual bool getTimeout();
		virtual void setTime();
};

#endif