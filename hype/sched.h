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
 * Declarations for hypervisor hcall()-implementation functions.
 *
 */

#ifndef _SCHED_H
#define _SCHED_H

#include <config.h>
#include <types.h>

/* Constants */
/* Specifies current CPU */
#define THIS_CPU	0xffff

extern uval locked_set_sched_params(struct cpu *cpup, uval cpu,
				    slot_mask_t required, slot_mask_t desired);
#endif /* ! _SCHED_H */
