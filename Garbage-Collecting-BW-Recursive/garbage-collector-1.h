#include "memory.h"

class CollectorV1 {
    public:
        void collectGarbage();
        CollectorV1(Memory& memory);

        void markNodesWhite();
        void markRootsBlack();
        void markChildrenBlack(int index);
        void markingPhase();
        void collectingPahse();
        void collectGarbageNodes();
    private:
        int oldBlackCount, blackCount;
        Memory& memory;
        
};