#pragma once

#include "LibLsp/JsonRpc/NotificationInMessage.h"
#include "LibLsp/lsp/lsDocumentUri.h"

// Clangd extension: indicates the current state of the file in clangd,
// sent from server via the `textDocument/clangd.fileStatus` notification.
namespace ClangdFileStatus {
    struct Params {
        // The text document's URI.
        lsDocumentUri uri;

        // The human-readable string presents the current state of the file, can be
        // shown in the UI (e.g. status bar).
        std::string state;

        MAKE_SWAP_METHOD(Params, uri, state);
    };
};
MAKE_REFLECT_STRUCT(ClangdFileStatus::Params, uri, state);

DEFINE_NOTIFICATION_TYPE(Notify_ClangdFileStatus, ClangdFileStatus::Params, "textDocument/clangd.fileStatus");
