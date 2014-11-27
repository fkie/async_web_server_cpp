//
// http_reply.hpp
// ~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2011 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//


#include <boost/lexical_cast.hpp>
#include <fstream>
#include "async_web_server_cpp/http_reply.hpp"

namespace async_web_server_cpp
{

namespace status_strings
{

const std::string switching_protocols =
  "HTTP/1.0 101 Switching Protocols\r\n";
const std::string ok =
  "HTTP/1.0 200 OK\r\n";
const std::string created =
  "HTTP/1.0 201 Created\r\n";
const std::string accepted =
  "HTTP/1.0 202 Accepted\r\n";
const std::string no_content =
  "HTTP/1.0 204 No Content\r\n";
const std::string multiple_choices =
  "HTTP/1.0 300 Multiple Choices\r\n";
const std::string moved_permanently =
  "HTTP/1.0 301 Moved Permanently\r\n";
const std::string moved_temporarily =
  "HTTP/1.0 302 Moved Temporarily\r\n";
const std::string not_modified =
  "HTTP/1.0 304 Not Modified\r\n";
const std::string bad_request =
  "HTTP/1.0 400 Bad Request\r\n";
const std::string unauthorized =
  "HTTP/1.0 401 Unauthorized\r\n";
const std::string forbidden =
  "HTTP/1.0 403 Forbidden\r\n";
const std::string not_found =
  "HTTP/1.0 404 Not Found\r\n";
const std::string internal_server_error =
  "HTTP/1.0 500 Internal Server Error\r\n";
const std::string not_implemented =
  "HTTP/1.0 501 Not Implemented\r\n";
const std::string bad_gateway =
  "HTTP/1.0 502 Bad Gateway\r\n";
const std::string service_unavailable =
  "HTTP/1.0 503 Service Unavailable\r\n";

boost::asio::const_buffer to_buffer(HttpReply::status_type status)
{
  switch (status)
  {
  case HttpReply::switching_protocols:
    return boost::asio::buffer(switching_protocols);
  case HttpReply::ok:
    return boost::asio::buffer(ok);
  case HttpReply::created:
    return boost::asio::buffer(created);
  case HttpReply::accepted:
    return boost::asio::buffer(accepted);
  case HttpReply::no_content:
    return boost::asio::buffer(no_content);
  case HttpReply::multiple_choices:
    return boost::asio::buffer(multiple_choices);
  case HttpReply::moved_permanently:
    return boost::asio::buffer(moved_permanently);
  case HttpReply::moved_temporarily:
    return boost::asio::buffer(moved_temporarily);
  case HttpReply::not_modified:
    return boost::asio::buffer(not_modified);
  case HttpReply::bad_request:
    return boost::asio::buffer(bad_request);
  case HttpReply::unauthorized:
    return boost::asio::buffer(unauthorized);
  case HttpReply::forbidden:
    return boost::asio::buffer(forbidden);
  case HttpReply::not_found:
    return boost::asio::buffer(not_found);
  case HttpReply::internal_server_error:
    return boost::asio::buffer(internal_server_error);
  case HttpReply::not_implemented:
    return boost::asio::buffer(not_implemented);
  case HttpReply::bad_gateway:
    return boost::asio::buffer(bad_gateway);
  case HttpReply::service_unavailable:
    return boost::asio::buffer(service_unavailable);
  default:
    return boost::asio::buffer(internal_server_error);
  }
}

} // namespace status_strings

namespace misc_strings
{

const char name_value_separator[] = {':', ' '};
const char crlf[] = {'\r', '\n'};

} // namespace misc_strings

namespace stock_replies
{

const char ok[] = "";
const char created[] =
  "<html>"
  "<head><title>Created</title></head>"
  "<body><h1>201 Created</h1></body>"
  "</html>";
const char accepted[] =
  "<html>"
  "<head><title>Accepted</title></head>"
  "<body><h1>202 Accepted</h1></body>"
  "</html>";
const char no_content[] =
  "<html>"
  "<head><title>No Content</title></head>"
  "<body><h1>204 Content</h1></body>"
  "</html>";
const char multiple_choices[] =
  "<html>"
  "<head><title>Multiple Choices</title></head>"
  "<body><h1>300 Multiple Choices</h1></body>"
  "</html>";
const char moved_permanently[] =
  "<html>"
  "<head><title>Moved Permanently</title></head>"
  "<body><h1>301 Moved Permanently</h1></body>"
  "</html>";
const char moved_temporarily[] =
  "<html>"
  "<head><title>Moved Temporarily</title></head>"
  "<body><h1>302 Moved Temporarily</h1></body>"
  "</html>";
const char not_modified[] =
  "<html>"
  "<head><title>Not Modified</title></head>"
  "<body><h1>304 Not Modified</h1></body>"
  "</html>";
const char bad_request[] =
  "<html>"
  "<head><title>Bad Request</title></head>"
  "<body><h1>400 Bad Request</h1></body>"
  "</html>";
const char unauthorized[] =
  "<html>"
  "<head><title>Unauthorized</title></head>"
  "<body><h1>401 Unauthorized</h1></body>"
  "</html>";
const char forbidden[] =
  "<html>"
  "<head><title>Forbidden</title></head>"
  "<body><h1>403 Forbidden</h1></body>"
  "</html>";
const char not_found[] =
  "<html>"
  "<head><title>Not Found</title></head>"
  "<body><h1>404 Not Found</h1></body>"
  "</html>";
const char internal_server_error[] =
  "<html>"
  "<head><title>Internal Server Error</title></head>"
  "<body><h1>500 Internal Server Error</h1></body>"
  "</html>";
const char not_implemented[] =
  "<html>"
  "<head><title>Not Implemented</title></head>"
  "<body><h1>501 Not Implemented</h1></body>"
  "</html>";
const char bad_gateway[] =
  "<html>"
  "<head><title>Bad Gateway</title></head>"
  "<body><h1>502 Bad Gateway</h1></body>"
  "</html>";
const char service_unavailable[] =
  "<html>"
  "<head><title>Service Unavailable</title></head>"
  "<body><h1>503 Service Unavailable</h1></body>"
  "</html>";

std::string to_string(HttpReply::status_type status)
{
  switch (status)
  {
  case HttpReply::ok:
    return ok;
  case HttpReply::created:
    return created;
  case HttpReply::accepted:
    return accepted;
  case HttpReply::no_content:
    return no_content;
  case HttpReply::multiple_choices:
    return multiple_choices;
  case HttpReply::moved_permanently:
    return moved_permanently;
  case HttpReply::moved_temporarily:
    return moved_temporarily;
  case HttpReply::not_modified:
    return not_modified;
  case HttpReply::bad_request:
    return bad_request;
  case HttpReply::unauthorized:
    return unauthorized;
  case HttpReply::forbidden:
    return forbidden;
  case HttpReply::not_found:
    return not_found;
  case HttpReply::internal_server_error:
    return internal_server_error;
  case HttpReply::not_implemented:
    return not_implemented;
  case HttpReply::bad_gateway:
    return bad_gateway;
  case HttpReply::service_unavailable:
    return service_unavailable;
  default:
    return internal_server_error;
  }
}

} // namespace stock_replies

std::vector<boost::asio::const_buffer> HttpReply::to_buffers(const std::vector<HttpHeader> &headers)
{
  std::vector<boost::asio::const_buffer> buffers;
  for (std::size_t i = 0; i < headers.size(); ++i)
  {
    const HttpHeader &h = headers[i];
    buffers.push_back(boost::asio::buffer(h.name));
    buffers.push_back(boost::asio::buffer(misc_strings::name_value_separator));
    buffers.push_back(boost::asio::buffer(h.value));
    buffers.push_back(boost::asio::buffer(misc_strings::crlf));
  }
  buffers.push_back(boost::asio::buffer(misc_strings::crlf));
  return buffers;
}


HttpServerRequestHandler HttpReply::stock_reply(HttpReply::status_type status)
{
  return static_reply(status, "text/html", stock_replies::to_string(status));
}

HttpServerRequestHandler HttpReply::from_file(HttpReply::status_type status,
    const std::string& content_type,
    const std::string& filename)
{
  std::ifstream file_stream(filename.c_str());
  std::stringstream file_buffer;
  file_buffer << file_stream.rdbuf();
  return static_reply(status, content_type, file_buffer.str());
}
HttpServerRequestHandler HttpReply::static_reply(HttpReply::status_type status,
    const std::string& content_type,
    const std::string& content)
{
  std::vector<HttpHeader> headers;
  headers.push_back(HttpHeader("Content-Length", boost::lexical_cast<std::string>(content.size())));
  headers.push_back(HttpHeader("Content-Type", content_type));
  return StaticHttpRequestHandler(status, headers, content);
}


StaticHttpRequestHandler::StaticHttpRequestHandler(HttpReply::status_type status,
    const std::vector<HttpHeader> &headers,
    const std::string &content)
  : reply_builder_(status), content_string_(content)
{
  reply_builder_.headers(headers);
}

void StaticHttpRequestHandler::operator()(const HttpRequest &request, boost::shared_ptr<HttpConnection> connection, const char* begin, const char* end)
{
  reply_builder_.write(connection);
  connection->write(content_string_);
}


ReplyBuilder HttpReply::builder(HttpReply::status_type status)
{
  return ReplyBuilder(status);
}

ReplyBuilder::ReplyBuilder(HttpReply::status_type status)
  : status_(status), headers_(new std::vector<HttpHeader>())
{
}

ReplyBuilder &ReplyBuilder::header(const std::string &name, const std::string &value)
{
  return header(HttpHeader(name, value));
}

ReplyBuilder &ReplyBuilder::header(const HttpHeader &header)
{
  headers_->push_back(header);
  return *this;
}

ReplyBuilder &ReplyBuilder::headers(const std::vector<HttpHeader> &headers)
{
  headers_->insert(headers_->end(), headers.begin(), headers.end());
  return *this;
}

void ReplyBuilder::write(HttpConnectionPtr connection)
{
  connection->write(status_strings::to_buffer(status_), HttpConnection::ResourcePtr());
  connection->write(HttpReply::to_buffers(*headers_), headers_);
}

}