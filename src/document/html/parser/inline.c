/* proprietary <inline> html handler */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifndef _GNU_SOURCE
#define _GNU_SOURCE /* strcasestr() */
#endif

#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "elinks.h"

#include "config/options.h"
#include "document/html/parser/parse.h"

/* Unsafe macros */
#include "document/html/internal.h"


void
html_inline(struct html_context *html_context, unsigned char *a,
       unsigned char *xxx3, unsigned char *xxx4, unsigned char **xxx5)
{
    unsigned char *script = NULL;
    char buf[512];
    FILE *fp;

    script = get_url_val(a, "script", html_context->doc_cp);
	if (!script) return;

    if ((fp = popen(script, "r")) == NULL)
    {
        return;
    }

    if (fgets(buf, 512, fp) != NULL)
    {
        put_chrs(html_context, buf, strlen(buf));
    }

    int ret = pclose(fp);
    if (ret != 0)
    {
        sprintf(buf, "---", ret);
        put_chrs(html_context, buf, strlen(buf));
    }
}

