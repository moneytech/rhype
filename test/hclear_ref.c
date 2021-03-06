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
 *
 * $Id$
 *
 */

#include <test.h>


struct partition_info pinfo[2] = {{
	.large_page_size1 = LARGE_PAGE_SIZE64K,
	.large_page_size2 = LARGE_PAGE_SIZE16M
},};


uval
test_os(uval argc __attribute__ ((unused)),
	uval argv[] __attribute__ ((unused)))
{
	uval pte_high, pte_low;
	uval flags = 0;
	uval pteg_index = 0, pte_index;
	uval ret2[2];
	uval retcode;
	struct pte lpte;

        pte_high = 0x000000000803;
        pte_low  = 0x000000040002;

        retcode = hcall_enter(ret2, flags, pteg_index, pte_high, pte_low);
	if (retcode) {
		hputs("H_ENTER: FAILURE\n");
		return retcode;
        }
	pte_index = ret2[0];

	retcode = hcall_clear_ref(ret2, flags, pte_index);
	if (retcode) {
		hputs("H_CLEAR_REF: FAILURE\n");
		return retcode;
        }

        retcode = hcall_read(ret2, flags, pte_index);
	if (retcode) {
		hputs("H_READ: FAILURE\n");
		return retcode;
        }

	lpte.words.rpnWord = ret2[1];
	lpte.words.vsidWord = ret2[0];

	/* Test for 'r' bit */
	if (lpte.bits.r) {
		hputs ("H_CLEAR_REF: FAILURE\n");
		return -1;
	}

	hputs("H_CLEAR_REF: SUCCESS\n");
	return 0;
}

