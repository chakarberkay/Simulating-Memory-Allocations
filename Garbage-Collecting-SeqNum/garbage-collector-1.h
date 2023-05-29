#include "memory.h"

class CollectorV1 {
    public:
        void collectGarbage();
        CollectorV1(Memory& memory);

        void countUsedNodes();
        //void markNodesWhite();
        void markRoots();
        void markNodes();
        void markingPhase();
        void collectingPahse();
        void collectGarbageNodes();
        void resetStates();
    private:
        bool resetInProg;
        int oldUsedCount, usedCount;
        Memory& memory;
        
};