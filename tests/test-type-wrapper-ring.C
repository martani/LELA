/* tests/test-type-wrapper-ring.C
 * Copyright 2002 William J. Turner
 *
 * Written by William J. Turner <wjturner@math.ncsu.edu>
 *
 * ------------------------------------
 * 
 * This file is part of LELA, licensed under the GNU General Public
 * License version 3. See COPYING for more information.
 */

#include "lela/lela-config.h"

#include <iostream>
#include <fstream>
#include <vector>

#include "lela/ring/type-wrapper.h"

#include "test-common.h"
#include "test-ring.h"
#include "test-blas-level1.h"

using namespace LELA;

int main (int argc, char **argv)
{
	static int iterations = 1 ;

	static Argument args[] = {
		{ 'i', "-i I", "Perform each test for I iterations.", TYPE_INT,     &iterations },
		{ '\0' }
	};

	parseArguments (argc, argv, args);

	commentator.start ("Type-wrapper-ring test suite", "TypeWrapperRing");
	bool pass = true;

	TypeWrapperRing<integer> F;

	// Make sure some more detailed messages get printed
	commentator.getMessageClass (INTERNAL_DESCRIPTION).setMaxDepth (6);
	commentator.getMessageClass (INTERNAL_DESCRIPTION).setMaxDetailLevel (Commentator::LEVEL_UNIMPORTANT);

	if (!runRingTests (F, "TypeWrapperRing<integer>", iterations, false, false)) pass = false;

	commentator.stop (MSG_STATUS (pass));

	return pass ? 0 : -1;
}

// Local Variables:
// mode: C++
// tab-width: 8
// indent-tabs-mode: t
// c-basic-offset: 8
// End:

// vim:sts=8:sw=8:ts=8:noet:sr:cino=>s,f0,{0,g0,(0,\:0,t0,+0,=s:syntax=cpp.doxygen:foldmethod=syntax
