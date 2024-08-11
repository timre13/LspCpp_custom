#pragma once

#include "LibLsp/JsonRpc/RequestInMessage.h"
#include "LibLsp/JsonRpc/lsResponseMessage.h"

#include "LibLsp/lsp/lsWorkspaceEdit.h"
#include "LibLsp/lsp/lsTextDocumentPositionParams.h"

/**
 */
struct WorkDoneProgressCreateParams{
        /**
        * The token to be used to report progress.
        */
        std::pair<optional<int>, optional<std::string>> token;

        MAKE_SWAP_METHOD(WorkDoneProgressCreateParams, token)

};
MAKE_REFLECT_STRUCT(WorkDoneProgressCreateParams, token)

using empty_t = optional<std::nullptr_t>;

DEFINE_REQUEST_RESPONSE_TYPE(window_workDoneProgressCreate,
        WorkDoneProgressCreateParams, empty_t, "window/workDoneProgress/create");

