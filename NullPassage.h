//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef ZOORK_NULLPASSAGE_H
#define ZOORK_NULLPASSAGE_H

#include "Passage.h"

class NullPassage : public Passage {
public:
    explicit NullPassage(Room*);

    void enter() override;  // ✅ Add this so it's properly overridden
};


#endif //ZOORK_NULLPASSAGE_H
