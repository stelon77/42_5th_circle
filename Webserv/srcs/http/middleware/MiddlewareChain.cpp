#include "MiddlewareChain.hpp"

MiddlewareChain::MiddlewareChain(const std::list<IMiddleware*> &middlewares, Config &config, ClientSocket &client, Request &request, Response &response)
	: m_middlewares(middlewares),
	  m_client(&client),
	  m_request(&request),
	  m_response(&response),
	  m_config(&config)
{
}

MiddlewareChain::~MiddlewareChain(void)
{
}

void MiddlewareChain::operator()()
{
	if (m_middlewares.empty()) {
		return;
	}

	IMiddleware &middleware = *(m_middlewares.front());

	m_middlewares.pop_front();

	middleware.handle(*m_client, *m_config, *m_request, *m_response, *this);
}
