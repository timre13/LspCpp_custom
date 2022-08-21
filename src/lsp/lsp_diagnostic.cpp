#include "LibLsp/lsp/lsp_diagnostic.h"

bool lsDiagnostic::operator==(const lsDiagnostic& rhs) const {
  // Just check the important fields.
  return range == rhs.range && message == rhs.message;
}
bool lsDiagnostic::operator!=(const lsDiagnostic& rhs) const {
  return !(*this == rhs);
}

std::string lsResponseError::ToString()
{
	std::string codeStr;
	switch (code)
	{
	case lsErrorCodes::ParseError:
		codeStr = "ParseError";
		break;
	case lsErrorCodes::InvalidRequest:
		codeStr = "InvalidRequest";
		break;
	case lsErrorCodes::MethodNotFound:
		codeStr = "MethodNotFound";
		break;
	case lsErrorCodes::InvalidParams:
		codeStr = "InvalidParams";
		break;
	case lsErrorCodes::InternalError:
		codeStr = "InternalError";
		break;
	case lsErrorCodes::serverErrorStart:
		codeStr = "serverErrorStart";
		break;
	case lsErrorCodes::serverErrorEnd:
		codeStr = "serverErrorEnd";
		break;
	case lsErrorCodes::ServerNotInitialized:
		codeStr = "ServerNotInitialized";
		break;
	case lsErrorCodes::UnknownErrorCode:
		codeStr = "UnknownErrorCode";
		break;
		// Defined by the protocol.
	case lsErrorCodes::RequestCancelled:
		codeStr = "RequestCancelled";
		break;
	default:
		codeStr = "Unknown code (" + std::to_string(int(code)) + ')';
		break;
	}

	std::string out = codeStr + ": " + this->message;

	if(data.has_value())
		out += ", data: " + data.value().Data();
	return out;
}

void lsResponseError::Write(Writer& visitor) {
	auto& value = *this;
	int code2 = static_cast<int>(this->code);

	visitor.StartObject();
	REFLECT_MEMBER2("code", code2);
	REFLECT_MEMBER(message);
	visitor.EndObject();
}
