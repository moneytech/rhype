/*
 * Copyright (C) 2005 Jimi Xenidis <jimix@watson.ibm.com>, IBM Corporation
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 $Id$
 *
 * Hypervisor call implementation for interrupt support hcalls.
 *
 */

#include <config.h>
#include <xirr.h>
#include <h_proto.h>
#include <xir.h>
#include <llan.h>
#include <hv_regs.h>
#include <debug.h>

sval
h_eoi(struct cpu_thread *thread, uval val)
{

	uval class = xirr_class(val);
	struct cpu_thread *thr = xir_get_thread(val);

	if (xirr_classes[class].eoi_fn) {
		return xirr_classes[class].eoi_fn(thread, val);
	}

	if (!thr || thr->cpu->os != thread->cpu->os) {
		return H_Permission;
	}

	xir_eoi(thread, val);

	return H_Success;
}
