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
    exec_on_terminal(ses->tab->term, uri->data, "", TERM_EXEC_FG);
}