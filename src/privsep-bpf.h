/* SPDX-License-Identifier: BSD-2-Clause */
/*
 * Priviledge Seperation for dhcpcd
 * Copyright (c) 2006-2019 Roy Marples <roy@marples.name>
 * All rights reserved

 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef PRIVSEP_BPF_H
#define PRIVSEP_BPF_H

ssize_t ps_bpf_cmd(struct dhcpcd_ctx *,
    struct ps_msghdr *, struct msghdr *);
ssize_t ps_bpf_dispatch(struct dhcpcd_ctx *,
    struct ps_msghdr *, struct msghdr *);

#ifdef ARP
ssize_t ps_bpf_openarp(const struct interface *);
ssize_t ps_bpf_addaddr(const struct interface *, const struct in_addr *);
ssize_t ps_bpf_deladdr(const struct interface *, const struct in_addr *);
ssize_t ps_bpf_closearp(const struct interface *);
ssize_t ps_bpf_sendarp(const struct interface *, const void *, size_t);
#endif

ssize_t ps_bpf_openbootp(const struct interface *);
ssize_t ps_bpf_closebootp(const struct interface *);
ssize_t ps_bpf_sendbootp(const struct interface *, const void *, size_t);
ssize_t ps_bpf_openbootpudp(const struct interface *);
ssize_t ps_bpf_closebootpudp(const struct interface *);
ssize_t ps_bpf_sendbootpudp(const struct interface *, const void *, size_t);
#endif
