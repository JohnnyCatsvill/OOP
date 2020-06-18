#include "CHttpUrl.h"

using namespace std;

bool IsLetter(char ch)
{
	return ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z';
}

bool IsDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

string ToLower(const string& str)
{
	string out = "";
	for (char ch : str)
	{
		out += tolower(ch);
	}
	return out;
}

unsigned short GetPortFromProtocol(Protocol protocol)
{
	if (protocol == HTTP)
	{
		return 80;
	}
	else if (protocol == HTTPS)
	{
		return 443;
	}
	else
	{
		return 0;
	}
}

string GetProtocolString(Protocol protocol)
{
	switch (protocol)
	{
	case HTTPS:
		return "https";
	default:
		return "http";
	}
}

string ParseDomain(const std::string& str)
{
	enum DomainState
	{
		DomainStart,
		DomainFirstLetters,
		DomainPoint,
		DomainEnd
	};

	DomainState state = DomainStart;

	if (str.empty())
	{
		throw CUrlParsingError("Domain empty");
	}
	for (char ch : str)
	{
		if (state == DomainStart)
		{
			if (!IsLetter(ch) && !IsDigit(ch))
			{
				throw CUrlParsingError("Domain starts with invalid characters. Valid characters are: A-Z a-z 0-9");
			}
			else
			{
				state = DomainFirstLetters;
			}
		}
		else if (state == DomainFirstLetters)
		{
			if (!IsLetter(ch) && !IsDigit(ch) && ch != '.' && ch != '-')
			{
				throw CUrlParsingError("Domain has invalid characters. Valid characters are: A-Z a-z 0-9 . -");
			}
			else if (ch == '.')
			{
				state = DomainPoint;
			}
		}
		else if (state == DomainPoint)
		{
			if (!IsLetter(ch) && !IsDigit(ch))
			{
				throw CUrlParsingError("Domain has invalid sequence of characters. Double nor letter and digits are not allowed");
			}
			else
			{
				state = DomainEnd;
			}
		}
		
	}
	if (state != DomainEnd)
	{
		throw CUrlParsingError("Entered domain consist of only one top-level, it must have at least 2 levels");
	}
	return str;
}

string ParseDocument(const std::string& str)
{
	for (char ch : str)
	{
		if (!IsLetter(ch) && !IsDigit(ch) && ch != '.' && ch != '/' && ch != '-' && ch != '_' && ch != '~' && ch != '%')
		{
			throw CUrlParsingError("Document contains invalid characters. Valid characters are: A-Z a-z 0-9 . / - _ ~ %");
		}
	}
	return str;
}

Protocol ParseProtocol(const std::string& str)
{
	if (ToLower(str) == "http")
	{
		return HTTP;
	}
	else if (ToLower(str) == "https")
	{
		return HTTPS;
	}
	else
	{
		throw CUrlParsingError("Invalid Protocol. Only HTTP & HTTPS allowed");
	}
}

string DocumentPutSlashIfItNotStartWith(const std::string& str)
{
	string out = "";
	if (str.empty() || str[0] != '/')
	{
		out = "/";
	}
	out += str;
	return out;
}

unsigned short ParsePort(int port)
{
	if (port > 65535 || port < 1)
	{
		throw CUrlParsingError("Invalid Port. Must be between 1 and 65535");
	}
	else
	{
		return port;
	}
}

CHttpUrl::CHttpUrl(std::string const& url)
{
	enum UrlStates
	{
		Scheme,
		SchemeEnd,
		SchemeSlashes,
		Host,
		Port,
		Path
	};

	UrlStates state = Scheme;

	string urlSequence = "";
	string urlWhole = "";

	std::string::const_iterator lastIt = url.end();
	if (!url.empty())
	{
		lastIt--;
	}
	else
	{
		throw CUrlParsingError("Entered url is empty");
	}

	for (std::string::const_iterator it = url.begin(); it != url.end() ; it++)
	{
		if (it == lastIt)
		{
			urlSequence += *it;
		}

		if (state == Scheme && (*it == ':' || it == lastIt))
		{
			m_protocol = ParseProtocol(urlSequence);
			state = SchemeEnd;
			urlWhole += urlSequence + ":";
			urlSequence = "";
		}
		else if (state == SchemeEnd)
		{
			state = (*it == '/') ? SchemeSlashes : Path;
			urlSequence += *it;
		}
		else if (state == SchemeSlashes)
		{
			urlSequence += *it;
			if (*it == '/' || it == lastIt)
			{
				state = Host;
				urlWhole += urlSequence;
				urlSequence = "";
			}
			else
			{
				state = Path;
			}

		}
		else if (state == Host && (*it == '/' || it == lastIt))
		{
			m_domain = ParseDomain(urlSequence);
			state = Path;
			urlWhole += urlSequence;
			urlSequence = "";
		}
		else if (state == Host && *it == ':')
		{
			m_domain = ParseDomain(urlSequence);
			state = Port;
			urlWhole += urlSequence;
			urlSequence = "";
		}
		else if (state == Port && (*it == '/' || it == lastIt))
		{
			m_port = ParsePort(stoi(urlSequence));
			state = Path;
			if (!(m_protocol == HTTPS && m_port == GetPortFromProtocol(HTTPS) || m_protocol == HTTP && m_port == GetPortFromProtocol(HTTP)))
			{
				urlWhole += ":" + urlSequence;
			}
			urlSequence = "";
		}
		else if (state == Path && it == lastIt)
		{
			m_document = ParseDocument(DocumentPutSlashIfItNotStartWith(urlSequence));
			urlWhole += DocumentPutSlashIfItNotStartWith(urlSequence);
		}
		else
		{
			urlSequence += *it;
		}
	}
	if (state < Path)
	{
		throw CUrlParsingError("Sourse of page must be provided");
	}
	m_url = urlWhole;
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol)
{
	m_document = ParseDocument(DocumentPutSlashIfItNotStartWith(document));
	m_protocol = protocol;
	if (domain.empty())
	{
		m_url = GetProtocolString(protocol) + ":" + m_document;
	}
	else
	{
		m_domain = ParseDomain(domain);
		m_url = GetProtocolString(protocol) + "://" + m_domain + m_document;
	}
}

CHttpUrl::CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port)
{
	m_document = ParseDocument(DocumentPutSlashIfItNotStartWith(document));
	m_protocol = protocol;
	m_port = (port == 0) ? GetPortFromProtocol(protocol) : port;

	if (domain.empty())
	{
		m_url = GetProtocolString(protocol) + ":" + m_document;
	}
	else if (port == 0 || m_protocol == HTTPS && m_port == GetPortFromProtocol(HTTPS) || m_protocol == HTTP && m_port == GetPortFromProtocol(HTTP))
	{
		m_domain = ParseDomain(domain);
		m_url = GetProtocolString(protocol) + "://" + m_domain + m_document;
	}
	else
	{
		m_domain = ParseDomain(domain);
		m_url = GetProtocolString(protocol) + "://" + m_domain + ":" + to_string(m_port) + m_document;
	}
}

std::string CHttpUrl::GetURL() const
{
	return m_url;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}
