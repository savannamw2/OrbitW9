
//
//  Fragment.cpp
//  Obrit
//
//  Created by Isabel Kamphaus on 3/27/25.
//

#include "fragment.h"
#include "uiDraw.h"

void Fragment::draw(ogstream& gout)
{
   gout.drawFragment(pos, angle.getRadians());
}
