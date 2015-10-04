/*	$OpenBSD: socket.h,v 1.1 2015/09/11 15:38:33 guenther Exp $	*/
/*
 * Copyright (c) 2015 Philip Guenther <guenther@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _LIBC_SYS_SOCKET_H_
#define	_LIBC_SYS_SOCKET_H_

#include_next <sys/socket.h>

PROTO_NORMAL(bind);
PROTO_DEPRECATED(getpeereid);
PROTO_NORMAL(getpeername);
PROTO_NORMAL(getrtable);
PROTO_NORMAL(getsockname);
PROTO_NORMAL(getsockopt);
PROTO_NORMAL(listen);
PROTO_NORMAL(setrtable);
PROTO_NORMAL(setsockopt);
PROTO_NORMAL(shutdown);
PROTO_DEPRECATED(sockatmark);
PROTO_NORMAL(socket);
PROTO_NORMAL(socketpair);

#endif /* !_LIBC_SYS_SOCKET_H_ */
