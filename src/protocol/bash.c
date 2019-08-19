#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "elinks.h"
#include "protocol/bash.h"
#include "protocol/protocol.h"
#include "protocol/uri.h"
#include "util/string.h"
#include "session/session.h"
#include "terminal/terminal.h"

void
bash_protocol_handler(struct session *ses, struct uri *uri)
{
    struct string command;

    if (!init_string(&command))
        return;

    add_uri_to_string(&command, uri, URI_DATA);
    decode_uri_string(&command);
    exec_on_terminal(ses->tab->term, command.source, "", TERM_EXEC_FG);
    done_string(&command);
}